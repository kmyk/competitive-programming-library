---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find_tree.hpp
    title: Union-Find Tree
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.aoj.test.cpp
    title: graph/kruskal.aoj.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "minimum spanning tree / \u6700\u5C0F\u5168\u57DF\u6728 (Kruskal's\
      \ method)"
    links: []
  bundledCode: "#line 2 \"data_structure/union_find_tree.hpp\"\n#include <vector>\n\
    \n/**\n * @brief Union-Find Tree\n * @docs data_structure/union_find_tree.md\n\
    \ * @note union-by-size + path-compression\n */\nstruct union_find_tree {\n  \
    \  std::vector<int> data;\n    union_find_tree() = default;\n    explicit union_find_tree(std::size_t\
    \ n) : data(n, -1) {}\n    bool is_root(int i) { return data[i] < 0; }\n    int\
    \ find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }\n\
    \    int tree_size(int i) { return - data[find_root(i)]; }\n    int unite_trees(int\
    \ i, int j) {\n        i = find_root(i); j = find_root(j);\n        if (i != j)\
    \ {\n            if (tree_size(i) < tree_size(j)) std::swap(i, j);\n         \
    \   data[i] += data[j];\n            data[j] = i;\n        }\n        return i;\n\
    \    }\n    bool is_same(int i, int j) { return find_root(i) == find_root(j);\
    \ }\n};\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) <\
    \ (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++\
    \ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define\
    \ REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 4 \"graph/kruskal.hpp\"\n#include <algorithm>\n\
    #include <numeric>\n#include <tuple>\n#line 8 \"graph/kruskal.hpp\"\n\n/**\n *\
    \ @brief minimum spanning tree / \u6700\u5C0F\u5168\u57DF\u6728 (Kruskal's method)\n\
    \ * @note $O(E \\log E)$\n * @note it becomes a forest if the given graph is not\
    \ connected\n * @return a list of indices of edges\n */\ntemplate <typename T>\n\
    std::vector<int> compute_minimum_spanning_tree(int n, std::vector<std::tuple<int,\
    \ int, T> > edges) {\n    std::vector<int> order(edges.size());\n    std::iota(ALL(order),\
    \ 0);\n    std::sort(ALL(order), [&](int i, int j) {\n        return std::make_pair(std::get<2>(edges[i]),\
    \ i) < std::make_pair(std::get<2>(edges[j]), j);\n    });\n    std::vector<int>\
    \ tree;\n    union_find_tree uft(n);\n    for (int i : order) {\n        int x\
    \ = std::get<0>(edges[i]);\n        int y = std::get<1>(edges[i]);\n        if\
    \ (not uft.is_same(x, y)) {\n            uft.unite_trees(x, y);\n            tree.push_back(i);\n\
    \        }\n    }\n    return tree;\n}\n"
  code: "#pragma once\n#include \"../data_structure/union_find_tree.hpp\"\n#include\
    \ \"../utils/macros.hpp\"\n#include <algorithm>\n#include <numeric>\n#include\
    \ <tuple>\n#include <vector>\n\n/**\n * @brief minimum spanning tree / \u6700\u5C0F\
    \u5168\u57DF\u6728 (Kruskal's method)\n * @note $O(E \\log E)$\n * @note it becomes\
    \ a forest if the given graph is not connected\n * @return a list of indices of\
    \ edges\n */\ntemplate <typename T>\nstd::vector<int> compute_minimum_spanning_tree(int\
    \ n, std::vector<std::tuple<int, int, T> > edges) {\n    std::vector<int> order(edges.size());\n\
    \    std::iota(ALL(order), 0);\n    std::sort(ALL(order), [&](int i, int j) {\n\
    \        return std::make_pair(std::get<2>(edges[i]), i) < std::make_pair(std::get<2>(edges[j]),\
    \ j);\n    });\n    std::vector<int> tree;\n    union_find_tree uft(n);\n    for\
    \ (int i : order) {\n        int x = std::get<0>(edges[i]);\n        int y = std::get<1>(edges[i]);\n\
    \        if (not uft.is_same(x, y)) {\n            uft.unite_trees(x, y);\n  \
    \          tree.push_back(i);\n        }\n    }\n    return tree;\n}\n"
  dependsOn:
  - data_structure/union_find_tree.hpp
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/kruskal.aoj.test.cpp
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: "minimum spanning tree / \u6700\u5C0F\u5168\u57DF\u6728 (Kruskal's method)"
---