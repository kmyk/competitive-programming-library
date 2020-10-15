---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.hpp
    title: Euler Tour (subtree queries, with commutative monoids)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
    title: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.point_add_range_sum.test.cpp
    title: data_structure/segment_tree.point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.point_set_range_composite.test.cpp
    title: data_structure/segment_tree.point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.range_sum_query.test.cpp
    title: data_structure/segment_tree.range_sum_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: old/rollback-square-decomposition.yukicoder-1031.test.cpp
    title: old/rollback-square-decomposition.yukicoder-1031.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: data_structure/segment_tree.md
    document_title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids,\
      \ \u5B8C\u5168\u4E8C\u5206\u6728)"
    links: []
  bundledCode: "#line 2 \"data_structure/segment_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 6 \"\
    data_structure/segment_tree.hpp\"\n\n/**\n * @brief Segment Tree / \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @docs data_structure/segment_tree.md\n\
    \ * @tparam Monoid (commutativity is not required)\n */\ntemplate <class Monoid>\n\
    struct segment_tree {\n    typedef typename Monoid::value_type value_type;\n \
    \   const Monoid mon;\n    int n;\n    std::vector<value_type> a;\n    segment_tree()\
    \ = default;\n    segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_)\
    \ {\n        n = 1; while (n < n_) n *= 2;\n        a.resize(2 * n - 1, mon.unit());\n\
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
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include \"utils/macros.hpp\"\n\n/**\n * @brief Segment Tree / \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @docs data_structure/segment_tree.md\n\
    \ * @tparam Monoid (commutativity is not required)\n */\ntemplate <class Monoid>\n\
    struct segment_tree {\n    typedef typename Monoid::value_type value_type;\n \
    \   const Monoid mon;\n    int n;\n    std::vector<value_type> a;\n    segment_tree()\
    \ = default;\n    segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_)\
    \ {\n        n = 1; while (n < n_) n *= 2;\n        a.resize(2 * n - 1, mon.unit());\n\
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
    \        }\n    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy:
  - data_structure/euler_tour_subtree_query.hpp
  timestamp: '2020-03-04 20:34:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - old/rollback-square-decomposition.yukicoder-1031.test.cpp
  - data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  - data_structure/segment_tree.point_set_range_composite.test.cpp
  - data_structure/segment_tree.range_sum_query.test.cpp
  - data_structure/segment_tree.point_add_range_sum.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.hpp
- /library/data_structure/segment_tree.hpp.html
title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
  \u4E8C\u5206\u6728)"
---
## 概要

monoid $M = (M, \cdot, 1)$ の要素の列 $a = (a_0, a_1, \dots, a _ {n - 1}) \in M^n$ に対し、次が $O(\log N)$ で処理可能:

-   $\mathtt{point\unicode{95}set}(i, b)$: $a_i \gets b$ と更新する。
-   $\mathtt{range\unicode{95}get}(l, r)$: 積 $a_l \cdot a _ {l + 1} \cdot \dots \cdot a _ {r - 1}$ を計算する。
