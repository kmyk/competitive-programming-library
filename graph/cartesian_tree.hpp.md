---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/cartesian_tree.yukicoder-1031.test.cpp
    title: graph/cartesian_tree.yukicoder-1031.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/cartesian_tree.yosupo.test.cpp
    title: graph/cartesian_tree.yosupo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Cartesian tree ($O(n)$)
    links: []
  bundledCode: "#line 2 \"graph/cartesian_tree.hpp\"\n#include <functional>\n#include\
    \ <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i)\
    \ < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n\
    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 5 \"graph/cartesian_tree.hpp\"\n\n\
    /**\n * @brief Cartesian tree ($O(n)$)\n * @note the smallest value is the root\n\
    \ * @note if a is not distinct, the way for tie-break is undefined\n * @return\
    \ the binary tree as the list of parents\n */\ntemplate <class T, class Comparator\
    \ = std::less<int> >\nstd::vector<int> construct_cartesian_tree(const std::vector<T>\
    \ & a, const Comparator & cmp = Comparator()) {\n    int n = a.size();\n    std::vector<int>\
    \ parent(n, -1);\n    REP3 (i, 1, n) {\n        int p = i - 1;  // parent of i\n\
    \        int l = -1;  // left child of i\n        while (p != -1 and cmp(a[i],\
    \ a[p])) {\n            int pp = parent[p];  // parent of parent of i\n      \
    \      if (l != -1) {\n                parent[l] = p;\n            }\n       \
    \     parent[p] = i;\n            l = p;\n            p = pp;\n        }\n   \
    \     parent[i] = p;\n    }\n    return parent;\n}\n"
  code: "#pragma once\n#include <functional>\n#include <vector>\n#include \"utils/macros.hpp\"\
    \n\n/**\n * @brief Cartesian tree ($O(n)$)\n * @note the smallest value is the\
    \ root\n * @note if a is not distinct, the way for tie-break is undefined\n *\
    \ @return the binary tree as the list of parents\n */\ntemplate <class T, class\
    \ Comparator = std::less<int> >\nstd::vector<int> construct_cartesian_tree(const\
    \ std::vector<T> & a, const Comparator & cmp = Comparator()) {\n    int n = a.size();\n\
    \    std::vector<int> parent(n, -1);\n    REP3 (i, 1, n) {\n        int p = i\
    \ - 1;  // parent of i\n        int l = -1;  // left child of i\n        while\
    \ (p != -1 and cmp(a[i], a[p])) {\n            int pp = parent[p];  // parent\
    \ of parent of i\n            if (l != -1) {\n                parent[l] = p;\n\
    \            }\n            parent[p] = i;\n            l = p;\n            p\
    \ = pp;\n        }\n        parent[i] = p;\n    }\n    return parent;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2020-07-16 00:31:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/cartesian_tree.yukicoder-1031.test.cpp
  - graph/cartesian_tree.yosupo.test.cpp
documentation_of: graph/cartesian_tree.hpp
layout: document
redirect_from:
- /library/graph/cartesian_tree.hpp
- /library/graph/cartesian_tree.hpp.html
title: Cartesian tree ($O(n)$)
---
