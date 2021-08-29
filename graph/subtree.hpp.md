---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: utils/dsu_on_tree.hpp
    title: DSU on tree (sack)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: utils/dsu_on_tree.aoj.test.cpp
    title: utils/dsu_on_tree.aoj.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "subtree info / \u305D\u308C\u305E\u308C\u306E\u90E8\u5206\u6728\
      \u306E size \u3068\u304B height \u3068\u304B\u3092\u307E\u3068\u3081\u3066\u6C42\
      \u3081\u3066\u304A\u3044\u3066\u304F\u308C\u308B\u3084\u3064"
    links: []
  bundledCode: "#line 2 \"graph/subtree.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \nstruct subtree_info_t {\n    int parent;  // in the entire tree\n    int depth;\
    \  // in the entire tree\n    int size;  // of the subtree\n    int height;  //\
    \ of the subtree\n};\n\n/**\n * @brief subtree info / \u305D\u308C\u305E\u308C\
    \u306E\u90E8\u5206\u6728\u306E size \u3068\u304B height \u3068\u304B\u3092\u307E\
    \u3068\u3081\u3066\u6C42\u3081\u3066\u304A\u3044\u3066\u304F\u308C\u308B\u3084\
    \u3064\n * @arg g must be a tree\n * @note O(n) time\n * @note O(n) space on heap\n\
    \ */\nstd::vector<subtree_info_t> prepare_subtree_info(std::vector<std::vector<int>\
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
    \        }\n    }\n    info[root].parent = -1;\n    return info;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nstruct subtree_info_t\
    \ {\n    int parent;  // in the entire tree\n    int depth;  // in the entire\
    \ tree\n    int size;  // of the subtree\n    int height;  // of the subtree\n\
    };\n\n/**\n * @brief subtree info / \u305D\u308C\u305E\u308C\u306E\u90E8\u5206\
    \u6728\u306E size \u3068\u304B height \u3068\u304B\u3092\u307E\u3068\u3081\u3066\
    \u6C42\u3081\u3066\u304A\u3044\u3066\u304F\u308C\u308B\u3084\u3064\n * @arg g\
    \ must be a tree\n * @note O(n) time\n * @note O(n) space on heap\n */\nstd::vector<subtree_info_t>\
    \ prepare_subtree_info(std::vector<std::vector<int> > const & g, int root) {\n\
    \    int n = g.size();\n    std::vector<subtree_info_t> info(n, (subtree_info_t)\
    \ { -1, -1, -1, -1 });\n    std::vector<int> topological(n);\n    topological[0]\
    \ = root;\n    info[root].parent = root;\n    info[root].depth = 0;\n    int r\
    \ = 1;\n    for (int l = 0; l < r; ++ l) {\n        int i = topological[l];\n\
    \        for (int j : g[i]) if (j != info[i].parent) {\n            topological[r\
    \ ++] = j;\n            info[j].parent = i;\n            info[j].depth = info[i].depth\
    \ + 1;\n        }\n    }\n    while ((-- r) >= 0) {\n        int i = topological[r];\n\
    \        info[i].size = 1;\n        info[i].height = 0;\n        for (int j :\
    \ g[i]) if (j != info[i].parent) {\n            info[i].size += info[j].size;\n\
    \            info[i].height = std::max(info[i].height, info[j].height + 1);\n\
    \        }\n    }\n    info[root].parent = -1;\n    return info;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/subtree.hpp
  requiredBy:
  - utils/dsu_on_tree.hpp
  timestamp: '2019-12-15 04:15:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - utils/dsu_on_tree.aoj.test.cpp
documentation_of: graph/subtree.hpp
layout: document
redirect_from:
- /library/graph/subtree.hpp
- /library/graph/subtree.hpp.html
title: "subtree info / \u305D\u308C\u305E\u308C\u306E\u90E8\u5206\u6728\u306E size\
  \ \u3068\u304B height \u3068\u304B\u3092\u307E\u3068\u3081\u3066\u6C42\u3081\u3066\
  \u304A\u3044\u3066\u304F\u308C\u308B\u3084\u3064"
---
