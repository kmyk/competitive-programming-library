---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/subtree.hpp
    title: "subtree info / \u305D\u308C\u305E\u308C\u306E\u90E8\u5206\u6728\u306E\
      \ size \u3068\u304B height \u3068\u304B\u3092\u307E\u3068\u3081\u3066\u6C42\u3081\
      \u3066\u304A\u3044\u3066\u304F\u308C\u308B\u3084\u3064"
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: utils/dsu_on_tree.aoj.test.cpp
    title: utils/dsu_on_tree.aoj.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: DSU on tree (sack)
    links:
    - https://codeforces.com/blog/entry/44351
  bundledCode: "#line 2 \"utils/dsu_on_tree.hpp\"\n#include <functional>\n#include\
    \ <stack>\n#include <vector>\n#line 2 \"graph/subtree.hpp\"\n#include <algorithm>\n\
    #line 4 \"graph/subtree.hpp\"\n\nstruct subtree_info_t {\n    int parent;  //\
    \ in the entire tree\n    int depth;  // in the entire tree\n    int size;  //\
    \ of the subtree\n    int height;  // of the subtree\n};\n\n/**\n * @brief subtree\
    \ info / \u305D\u308C\u305E\u308C\u306E\u90E8\u5206\u6728\u306E size \u3068\u304B\
    \ height \u3068\u304B\u3092\u307E\u3068\u3081\u3066\u6C42\u3081\u3066\u304A\u3044\
    \u3066\u304F\u308C\u308B\u3084\u3064\n * @arg g must be a tree\n * @note O(n)\
    \ time\n * @note O(n) space on heap\n */\nstd::vector<subtree_info_t> prepare_subtree_info(std::vector<std::vector<int>\
    \ > const & g, int root) {\n    int n = g.size();\n    std::vector<subtree_info_t>\
    \ info(n, (subtree_info_t) { -1, -1, -1, -1 });\n    std::vector<int> topological(n);\n\
    \    topological[0] = root;\n    info[root].parent = root;\n    info[root].depth\
    \ = 0;\n    int r = 1;\n    for (int l = 0; l < r; ++ l) {\n        int i = topological[l];\n\
    \        for (int j : g[i]) if (j != info[i].parent) {\n            topological[r\
    \ ++] = j;\n            info[j].parent = i;\n            info[j].depth = info[i].depth\
    \ + 1;\n        }\n    }\n    while ((-- r) >= 0) {\n        int i = topological[r];\n\
    \        info[i].size = 1;\n        info[i].height = 0;\n        for (int j :\
    \ g[i]) if (j != info[i].parent) {\n            info[i].size += info[j].size;\n\
    \            info[i].height = std::max(info[i].height, info[j].height + 1);\n\
    \        }\n    }\n    info[root].parent = -1;\n    return info;\n}\n#line 2 \"\
    utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n\
    #define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i,\
    \ n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for\
    \ (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 7 \"utils/dsu_on_tree.hpp\"\n\n/**\n * @brief DSU on tree\
    \ (sack)\n * @arg g is a tree\n * @arg root\n * @arg add is a function object\
    \ which takes a index of a vertex\n * @arg sub is a function object which takes\
    \ a index of a vertex\n * @arg callback is a function object which takes a index\
    \ of a vertex\n * @note for each x, add(x) and sub(x) are called O(log n) times\n\
    \ * @note O(n log n) if add, sub, and callback are O(1)\n * @see https://codeforces.com/blog/entry/44351\n\
    \ * @note sub(x) can be implemented as reset(), because sub(x) is called until\
    \ it becomes empty after sub(x) is called once\n */\ntemplate <class Add, class\
    \ Sub, class Callback>\nvoid dsu_on_tree(const std::vector<std::vector<int> >\
    \ & g, int root, Add & add, Sub & sub, Callback & callback) {\n    auto info =\
    \ prepare_subtree_info(g, root);\n    auto subtree_apply = [&](int x, auto & f)\
    \ {\n        std::stack<int> stk;\n        stk.push(x);\n        while (not stk.empty())\
    \ {\n            int y = stk.top();\n            stk.pop();\n            f(y);\n\
    \            for (int z : g[y]) if (z != info[y].parent) {\n                stk.push(z);\n\
    \            }\n        }\n    };\n    std::function<void (int, bool)> go = [&](int\
    \ x, bool keep) {\n        // leaf\n        if (info[x].size == 1) {\n       \
    \     add(x);\n            callback(x);\n            if (not keep) {\n       \
    \         sub(x);\n            }\n            return;\n        }\n        // choose\
    \ the heavy child\n        int z = *max_element(ALL(g[x]), [&](int y1, int y2)\
    \ {\n            int size1 = (y1 == info[x].parent ? -1 : info[y1].size);\n  \
    \          int size2 = (y2 == info[x].parent ? -1 : info[y2].size);\n        \
    \    return size1 < size2;\n        });\n        // go light\n        for (int\
    \ y : g[x]) if (y != info[x].parent) {\n            if (y != z) {\n          \
    \      go(y, false);\n            }\n        }\n        // go heavy\n        go(z,\
    \ true);\n        for (int y : g[x]) if (y != info[x].parent) {\n            if\
    \ (y != z) {\n                subtree_apply(y, add);\n            }\n        }\n\
    \        add(x);\n        callback(x);\n        if (not keep) {\n            subtree_apply(x,\
    \ sub);\n        }\n    };\n    go(root, false);\n}\n"
  code: "#pragma once\n#include <functional>\n#include <stack>\n#include <vector>\n\
    #include \"../graph/subtree.hpp\"\n#include \"../utils/macros.hpp\"\n\n/**\n *\
    \ @brief DSU on tree (sack)\n * @arg g is a tree\n * @arg root\n * @arg add is\
    \ a function object which takes a index of a vertex\n * @arg sub is a function\
    \ object which takes a index of a vertex\n * @arg callback is a function object\
    \ which takes a index of a vertex\n * @note for each x, add(x) and sub(x) are\
    \ called O(log n) times\n * @note O(n log n) if add, sub, and callback are O(1)\n\
    \ * @see https://codeforces.com/blog/entry/44351\n * @note sub(x) can be implemented\
    \ as reset(), because sub(x) is called until it becomes empty after sub(x) is\
    \ called once\n */\ntemplate <class Add, class Sub, class Callback>\nvoid dsu_on_tree(const\
    \ std::vector<std::vector<int> > & g, int root, Add & add, Sub & sub, Callback\
    \ & callback) {\n    auto info = prepare_subtree_info(g, root);\n    auto subtree_apply\
    \ = [&](int x, auto & f) {\n        std::stack<int> stk;\n        stk.push(x);\n\
    \        while (not stk.empty()) {\n            int y = stk.top();\n         \
    \   stk.pop();\n            f(y);\n            for (int z : g[y]) if (z != info[y].parent)\
    \ {\n                stk.push(z);\n            }\n        }\n    };\n    std::function<void\
    \ (int, bool)> go = [&](int x, bool keep) {\n        // leaf\n        if (info[x].size\
    \ == 1) {\n            add(x);\n            callback(x);\n            if (not\
    \ keep) {\n                sub(x);\n            }\n            return;\n     \
    \   }\n        // choose the heavy child\n        int z = *max_element(ALL(g[x]),\
    \ [&](int y1, int y2) {\n            int size1 = (y1 == info[x].parent ? -1 :\
    \ info[y1].size);\n            int size2 = (y2 == info[x].parent ? -1 : info[y2].size);\n\
    \            return size1 < size2;\n        });\n        // go light\n       \
    \ for (int y : g[x]) if (y != info[x].parent) {\n            if (y != z) {\n \
    \               go(y, false);\n            }\n        }\n        // go heavy\n\
    \        go(z, true);\n        for (int y : g[x]) if (y != info[x].parent) {\n\
    \            if (y != z) {\n                subtree_apply(y, add);\n         \
    \   }\n        }\n        add(x);\n        callback(x);\n        if (not keep)\
    \ {\n            subtree_apply(x, sub);\n        }\n    };\n    go(root, false);\n\
    }\n"
  dependsOn:
  - graph/subtree.hpp
  - utils/macros.hpp
  isVerificationFile: false
  path: utils/dsu_on_tree.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - utils/dsu_on_tree.aoj.test.cpp
documentation_of: utils/dsu_on_tree.hpp
layout: document
redirect_from:
- /library/utils/dsu_on_tree.hpp
- /library/utils/dsu_on_tree.hpp.html
title: DSU on tree (sack)
---
