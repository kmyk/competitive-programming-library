---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  - icon: ':heavy_check_mark:'
    path: graph/euler_tour_preorder.hpp
    title: Euler Tour (preorder)
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
      \u4E8C\u5206\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
    title: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: data_structure/euler_tour_subtree_query.md
    document_title: Euler Tour (subtree queries, with commutative monoids)
    links: []
  bundledCode: "#line 2 \"data_structure/euler_tour_subtree_query.hpp\"\n#include\
    \ <cassert>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n)\
    \ for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i =\
    \ (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1;\
    \ (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >=\
    \ (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 2 \"graph/euler_tour_preorder.hpp\"\
    \n#include <functional>\n#line 4 \"graph/euler_tour_preorder.hpp\"\n\n/**\n *\
    \ @brief Euler Tour (preorder)\n * @arg g must be a rooted tree, directed or undirected\n\
    \ */\nvoid do_euler_tour_preorder(std::vector<std::vector<int> > const & g, int\
    \ root, std::vector<int> & tour, std::vector<int> & left, std::vector<int> & right)\
    \ {\n    int n = g.size();\n    tour.clear();\n    left.assign(n, -1);\n    right.assign(n,\
    \ -1);\n    std::function<void (int, int)> go = [&](int x, int parent) {\n   \
    \     left[x] = tour.size();\n        tour.push_back(x);\n        for (int y :\
    \ g[x]) if (y != parent) {\n            go(y, x);\n        }\n        right[x]\
    \ = tour.size();\n    };\n    go(root, -1);\n}\n#line 2 \"data_structure/segment_tree.hpp\"\
    \n#include <algorithm>\n#line 6 \"data_structure/segment_tree.hpp\"\n\n/**\n *\
    \ @brief Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
    \u4E8C\u5206\u6728)\n * @docs data_structure/segment_tree.md\n * @tparam Monoid\
    \ (commutativity is not required)\n */\ntemplate <class Monoid>\nstruct segment_tree\
    \ {\n    typedef typename Monoid::value_type value_type;\n    const Monoid mon;\n\
    \    int n;\n    std::vector<value_type> a;\n    segment_tree() = default;\n \
    \   segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {\n     \
    \   n = 1; while (n < n_) n *= 2;\n        a.resize(2 * n - 1, mon.unit());\n\
    \    }\n    void point_set(int i, value_type b) {  // 0-based\n        assert\
    \ (0 <= i and i < n);\n        a[i + n - 1] = b;\n        for (i = (i + n) / 2;\
    \ i > 0; i /= 2) {  // 1-based\n            a[i - 1] = mon.mult(a[2 * i - 1],\
    \ a[2 * i]);\n        }\n    }\n    value_type range_get(int l, int r) {  // 0-based,\
    \ [l, r)\n        assert (0 <= l and l <= r and r <= n);\n        value_type lacc\
    \ = mon.unit(), racc = mon.unit();\n        for (l += n, r += n; l < r; l /= 2,\
    \ r /= 2) {  // 1-based loop, 2x faster than recursion\n            if (l % 2\
    \ == 1) lacc = mon.mult(lacc, a[(l ++) - 1]);\n            if (r % 2 == 1) racc\
    \ = mon.mult(a[(-- r) - 1], racc);\n        }\n        return mon.mult(lacc, racc);\n\
    \    }\n\n    value_type point_get(int i) {  // 0-based\n        assert (0 <=\
    \ i and i < n);\n        return a[i + n - 1];\n    }\n\n    /**\n     * @brief\
    \ a fast & semigroup-friendly version constructor\n     * @note $O(n)$\n     */\n\
    \    template <class InputIterator>\n    segment_tree(InputIterator first, InputIterator\
    \ last, const Monoid & mon_ = Monoid()) : mon(mon_) {\n        int size = std::distance(first,\
    \ last);\n        n = 1; while (n < size) n *= 2;\n        a.resize(2 * n - 1,\
    \ mon.unit());\n        std::copy(first, last, a.begin() + (n - 1));\n       \
    \ unsafe_rebuild();\n    }\n    /**\n     * @brief update a leaf node without\
    \ updating ancestors\n     * @note $O(1)$\n     */\n    void unsafe_point_set(int\
    \ i, value_type b) {  // 0-based\n        assert (0 <= i and i < n);\n       \
    \ a[i + n - 1] = b;\n    }\n    /**\n     * @brief re-build non-leaf nodes from\
    \ leaf nodes\n     * @note $O(n)$\n     */\n    void unsafe_rebuild() {\n    \
    \    REP_R (i, n - 1) {\n            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);\n\
    \        }\n    }\n};\n#line 7 \"data_structure/euler_tour_subtree_query.hpp\"\
    \n\n/**\n * @brief Euler Tour (subtree queries, with commutative monoids)\n *\
    \ @docs data_structure/euler_tour_subtree_query.md\n */\ntemplate <class CommutativeMonoid>\n\
    class euler_tour_subtree_query {\n    typedef typename CommutativeMonoid::value_type\
    \ value_type;\n    segment_tree<CommutativeMonoid> data;\n    std::vector<int>\
    \ left, right;\n\npublic:\n    euler_tour_subtree_query(const std::vector<std::vector<int>\
    \ > & g, int root, const CommutativeMonoid & mon_ = CommutativeMonoid())\n   \
    \         : data(g.size(), mon_) {\n        std::vector<int> tour;\n        do_euler_tour_preorder(g,\
    \ root, tour, left, right);\n    }\n    template <class InputIterator>\n    euler_tour_subtree_query(const\
    \ std::vector<std::vector<int> > & g, int root, InputIterator first, InputIterator\
    \ last, const CommutativeMonoid & mon_ = CommutativeMonoid())\n            : data(std::distance(first,\
    \ last), mon_) {\n        assert ((int)g.size() == std::distance(first, last));\n\
    \        std::vector<int> tour;\n        do_euler_tour_preorder(g, root, tour,\
    \ left, right);\n        REP (x, g.size()) {\n            data.unsafe_point_set(left[x],\
    \ *(first ++));\n        }\n        data.unsafe_rebuild();\n    }\n\n    void\
    \ vertex_set(int x, value_type a) {\n        assert (0 <= x and x < (int)left.size());\n\
    \        return data.point_set(left[x], a);\n    }\n    value_type vertex_get(int\
    \ x) {\n        assert (0 <= x and x < (int)left.size());\n        return data.point_get(left[x]);\n\
    \    }\n    value_type subtree_get(int x) {\n        assert (0 <= x and x < (int)left.size());\n\
    \        return data.range_get(left[x], right[x]);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"utils/macros.hpp\"\
    \n#include \"graph/euler_tour_preorder.hpp\"\n#include \"data_structure/segment_tree.hpp\"\
    \n\n/**\n * @brief Euler Tour (subtree queries, with commutative monoids)\n *\
    \ @docs data_structure/euler_tour_subtree_query.md\n */\ntemplate <class CommutativeMonoid>\n\
    class euler_tour_subtree_query {\n    typedef typename CommutativeMonoid::value_type\
    \ value_type;\n    segment_tree<CommutativeMonoid> data;\n    std::vector<int>\
    \ left, right;\n\npublic:\n    euler_tour_subtree_query(const std::vector<std::vector<int>\
    \ > & g, int root, const CommutativeMonoid & mon_ = CommutativeMonoid())\n   \
    \         : data(g.size(), mon_) {\n        std::vector<int> tour;\n        do_euler_tour_preorder(g,\
    \ root, tour, left, right);\n    }\n    template <class InputIterator>\n    euler_tour_subtree_query(const\
    \ std::vector<std::vector<int> > & g, int root, InputIterator first, InputIterator\
    \ last, const CommutativeMonoid & mon_ = CommutativeMonoid())\n            : data(std::distance(first,\
    \ last), mon_) {\n        assert ((int)g.size() == std::distance(first, last));\n\
    \        std::vector<int> tour;\n        do_euler_tour_preorder(g, root, tour,\
    \ left, right);\n        REP (x, g.size()) {\n            data.unsafe_point_set(left[x],\
    \ *(first ++));\n        }\n        data.unsafe_rebuild();\n    }\n\n    void\
    \ vertex_set(int x, value_type a) {\n        assert (0 <= x and x < (int)left.size());\n\
    \        return data.point_set(left[x], a);\n    }\n    value_type vertex_get(int\
    \ x) {\n        assert (0 <= x and x < (int)left.size());\n        return data.point_get(left[x]);\n\
    \    }\n    value_type subtree_get(int x) {\n        assert (0 <= x and x < (int)left.size());\n\
    \        return data.range_get(left[x], right[x]);\n    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  - graph/euler_tour_preorder.hpp
  - data_structure/segment_tree.hpp
  isVerificationFile: false
  path: data_structure/euler_tour_subtree_query.hpp
  requiredBy: []
  timestamp: '2020-03-04 20:34:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
documentation_of: data_structure/euler_tour_subtree_query.hpp
layout: document
redirect_from:
- /library/data_structure/euler_tour_subtree_query.hpp
- /library/data_structure/euler_tour_subtree_query.hpp.html
title: Euler Tour (subtree queries, with commutative monoids)
---
## Operations

根付き木 $T$ であってそれぞれの頂点 $x$ に可換 monoid 重み $a_x \in M$ が乗ったものがあるとする。頂点数を $N$ として均し $O(\log N)$ で次が処理できる。

-   $\mathtt{vertex\unicode{95}set}(x, b)$: 頂点 $x$ の重みを $a_x \gets b$ と更新する。
-   $\mathtt{vertex\unicode{95}get}(x)$: 頂点 $x$ の重み $a_x$ を計算する。
-   $\mathtt{subtree\unicode{95}get}(x, y)$: 頂点 $x$ を根とする部分木に属する頂点の重みの総和 $$\sum _ {y ~\text{is a descendent of}~ x} a_y$$ を計算する。
