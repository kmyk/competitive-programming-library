---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/kruskal.hpp
    title: "minimum spanning tree / \u6700\u5C0F\u5168\u57DF\u6728 (Kruskal's method)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find_tree.aoj.test.cpp
    title: data_structure/union_find_tree.aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find_tree.yosupo.test.cpp
    title: data_structure/union_find_tree.yosupo.test.cpp
  - icon: ':x:'
    path: graph/kruskal.aoj.test.cpp
    title: graph/kruskal.aoj.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: data_structure/union_find_tree.md
    document_title: Union-Find Tree
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
    \ }\n};\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief Union-Find Tree\n * @docs\
    \ data_structure/union_find_tree.md\n * @note union-by-size + path-compression\n\
    \ */\nstruct union_find_tree {\n    std::vector<int> data;\n    union_find_tree()\
    \ = default;\n    explicit union_find_tree(std::size_t n) : data(n, -1) {}\n \
    \   bool is_root(int i) { return data[i] < 0; }\n    int find_root(int i) { return\
    \ is_root(i) ? i : (data[i] = find_root(data[i])); }\n    int tree_size(int i)\
    \ { return - data[find_root(i)]; }\n    int unite_trees(int i, int j) {\n    \
    \    i = find_root(i); j = find_root(j);\n        if (i != j) {\n            if\
    \ (tree_size(i) < tree_size(j)) std::swap(i, j);\n            data[i] += data[j];\n\
    \            data[j] = i;\n        }\n        return i;\n    }\n    bool is_same(int\
    \ i, int j) { return find_root(i) == find_root(j); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find_tree.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2020-02-28 14:33:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - graph/kruskal.aoj.test.cpp
  - data_structure/union_find_tree.yosupo.test.cpp
  - data_structure/union_find_tree.aoj.test.cpp
documentation_of: data_structure/union_find_tree.hpp
layout: document
redirect_from:
- /library/data_structure/union_find_tree.hpp
- /library/data_structure/union_find_tree.hpp.html
title: Union-Find Tree
---
## 概要

頂点数 $N$ で辺数 $0$ の無向グラフ $G = (V, E)$ に対し、次が $O(\alpha(N))$ amortized (ただし $\alpha$ は Ackermann 関数の逆関数) で処理可能。

-   $\mathtt{unite\unicode{95}trees}(u, v)$: 頂点 $u, v$ 間に辺を追加する。
    -   $u, v$ 間の辺は無向であることに注意
-   $\mathtt{find\unicode{95}root}(v)$: 頂点 $v$ の所属する連結成分の代表元を取得する。
-   $\mathtt{is\unicode{95}same}(u, v)$: 頂点 $u, v$ が同じ連結成分に所属するかを判定する。
-   $\mathtt{tree\unicode{95}size}(v)$: 頂点 $v$ の所属する連結成分の要素数を取得する。
