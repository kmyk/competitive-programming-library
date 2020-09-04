---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Euler Tour (preorder)
  bundledCode: "#line 2 \"graph/euler_tour_preorder.hpp\"\n#include <functional>\n\
    #include <vector>\n\n/**\n * @brief Euler Tour (preorder)\n * @arg g must be a\
    \ rooted tree, directed or undirected\n */\nvoid do_euler_tour_preorder(std::vector<std::vector<int>\
    \ > const & g, int root, std::vector<int> & tour, std::vector<int> & left, std::vector<int>\
    \ & right) {\n    int n = g.size();\n    tour.clear();\n    left.assign(n, -1);\n\
    \    right.assign(n, -1);\n    std::function<void (int, int)> go = [&](int x,\
    \ int parent) {\n        left[x] = tour.size();\n        tour.push_back(x);\n\
    \        for (int y : g[x]) if (y != parent) {\n            go(y, x);\n      \
    \  }\n        right[x] = tour.size();\n    };\n    go(root, -1);\n}\n"
  code: "#pragma once\n#include <functional>\n#include <vector>\n\n/**\n * @brief\
    \ Euler Tour (preorder)\n * @arg g must be a rooted tree, directed or undirected\n\
    \ */\nvoid do_euler_tour_preorder(std::vector<std::vector<int> > const & g, int\
    \ root, std::vector<int> & tour, std::vector<int> & left, std::vector<int> & right)\
    \ {\n    int n = g.size();\n    tour.clear();\n    left.assign(n, -1);\n    right.assign(n,\
    \ -1);\n    std::function<void (int, int)> go = [&](int x, int parent) {\n   \
    \     left[x] = tour.size();\n        tour.push_back(x);\n        for (int y :\
    \ g[x]) if (y != parent) {\n            go(y, x);\n        }\n        right[x]\
    \ = tour.size();\n    };\n    go(root, -1);\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.hpp
    title: Euler Tour (subtree queries, with commutative monoids)
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
    title: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  isVerificationFile: false
  path: graph/euler_tour_preorder.hpp
  requiredBy:
  - data_structure/euler_tour_subtree_query.hpp
  timestamp: '2020-02-26 19:51:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
documentation_of: graph/euler_tour_preorder.hpp
layout: document
redirect_from:
- /library/graph/euler_tour_preorder.hpp
- /library/graph/euler_tour_preorder.hpp.html
title: Euler Tour (preorder)
---
