---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
    title: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: utils/mo_algorithm.yuki1270.test.cpp
    title: utils/mo_algorithm.yuki1270.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: data_structure/lazy_propagation_segment_tree.md
    document_title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)"
    links: []
  bundledCode: "#line 2 \"data_structure/lazy_propagation_segment_tree.hpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <type_traits>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 7 \"data_structure/lazy_propagation_segment_tree.hpp\"\n\n\
    /**\n * @brief Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @docs data_structure/lazy_propagation_segment_tree.md\n\
    \ * @tparam MonoidX is a monoid\n * @tparam MonoidF is a monoid\n * @tparam Action\
    \ is a function phi : F * X -> X where the partial applied phi(f, -) : X -> X\
    \ is a homomorphism on X\n */\ntemplate <class MonoidX, class MonoidF, class Action>\n\
    struct lazy_propagation_segment_tree {\n    static_assert (std::is_invocable_r<typename\
    \ MonoidX::value_type, Action, typename MonoidF::value_type, typename MonoidX::value_type>::value,\
    \ \"\");\n    typedef typename MonoidX::value_type value_type;\n    typedef typename\
    \ MonoidF::value_type operator_type;\n    MonoidX mon_x;\n    MonoidF mon_f;\n\
    \    Action act;\n    int n;\n    std::vector<value_type> a;\n    std::vector<operator_type>\
    \ f;\n\n    lazy_propagation_segment_tree() = default;\n    lazy_propagation_segment_tree(int\
    \ n_, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_ = MonoidF(),\
    \ const Action & act_ = Action())\n            : mon_x(mon_x_), mon_f(mon_f_),\
    \ act(act_) {\n        n = 1; while (n < n_) n *= 2;\n        a.resize(2 * n -\
    \ 1, mon_x.unit());\n        f.resize(n - 1, mon_f.unit());\n    }\n    template\
    \ <class InputIterator>\n    lazy_propagation_segment_tree(InputIterator first,\
    \ InputIterator last, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_\
    \ = MonoidF(), const Action & act_ = Action())\n            : mon_x(mon_x_), mon_f(mon_f_),\
    \ act(act_) {\n        int size = std::distance(first, last);\n        n = 1;\
    \ while (n < size) n *= 2;\n        a.resize(2 * n - 1, mon_x.unit());\n     \
    \   f.resize(n - 1, mon_f.unit());\n        std::copy(first, last, a.begin() +\
    \ (n - 1));\n        REP_R (i, n - 1) {\n            a[i] = mon_x.mult(a[2 * i\
    \ + 1], a[2 * i + 2]);\n        }\n    }\n\n    void point_set(int i, value_type\
    \ b) {\n        range_set(i, i + 1, b);\n    }\n    /**\n     * @note O(min(n,\
    \ (r - l) log n))\n     */\n    void range_set(int l, int r, value_type b) {\n\
    \        assert (0 <= l and l <= r and r <= n);\n        range_set(0, 0, n, l,\
    \ r, b);\n    }\n    void range_set(int i, int il, int ir, int l, int r, value_type\
    \ b) {\n        if (l <= il and ir <= r and ir - il == 1) {  // 0-based\n    \
    \        a[i] = b;\n        } else if (ir <= l or r <= il) {\n            // nop\n\
    \        } else {\n            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n,\
    \ f[i]);\n            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);\n\
    \            f[i] = mon_f.unit();\n            range_set(2 * i + 1, il, (il +\
    \ ir) / 2, l, r, b);\n            range_set(2 * i + 2, (il + ir) / 2, ir, l, r,\
    \ b);\n            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);\n        }\n\
    \    }\n\n    void point_apply(int i, operator_type g) {\n        range_apply(i,\
    \ i + 1, g);\n    }\n    void range_apply(int l, int r, operator_type g) {\n \
    \       assert (0 <= l and l <= r and r <= n);\n        range_apply(0, 0, n, l,\
    \ r, g);\n    }\n    void range_apply(int i, int il, int ir, int l, int r, operator_type\
    \ g) {\n        if (l <= il and ir <= r) { // 0-based\n            a[i] = act(g,\
    \ a[i]);\n            if (i < f.size()) f[i] = mon_f.mult(g, f[i]);\n        }\
    \ else if (ir <= l or r <= il) {\n            // nop\n        } else {\n     \
    \       range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);\n            range_apply(2\
    \ * i + 2, (il + ir) / 2, ir, 0, n, f[i]);\n            f[i] = mon_f.unit(); \
    \ // unnecessary if the oprator monoid is commutative\n            range_apply(2\
    \ * i + 1, il, (il + ir) / 2, l, r, g);\n            range_apply(2 * i + 2, (il\
    \ + ir) / 2, ir, l, r, g);\n            a[i] = mon_x.mult(a[2 * i + 1], a[2 *\
    \ i + 2]);\n        }\n    }\n\n    value_type point_get(int i) {\n        return\
    \ range_get(i, i + 1);\n    }\n    value_type range_get(int l, int r) {\n    \
    \    assert (0 <= l and l <= r and r <= n);\n        if (l == 0 and r == n) return\
    \ a[0];\n        value_type lacc = mon_x.unit(), racc = mon_x.unit();\n      \
    \  for (int l1 = (l += n), r1 = (r += n) - 1; l1 > 1; l /= 2, r /= 2, l1 /= 2,\
    \ r1 /= 2) {  // 1-based loop, 2x faster than recursion\n            if (l < r)\
    \ {\n                if (l % 2 == 1) lacc = mon_x.mult(lacc, a[(l ++) - 1]);\n\
    \                if (r % 2 == 1) racc = mon_x.mult(a[(-- r) - 1], racc);\n   \
    \         }\n            lacc = act(f[l1 / 2 - 1], lacc);\n            racc =\
    \ act(f[r1 / 2 - 1], racc);\n        }\n        return mon_x.mult(lacc, racc);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <type_traits>\n\
    #include <vector>\n#include \"utils/macros.hpp\"\n\n/**\n * @brief Lazy Propagation\
    \ Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \ (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @docs data_structure/lazy_propagation_segment_tree.md\n\
    \ * @tparam MonoidX is a monoid\n * @tparam MonoidF is a monoid\n * @tparam Action\
    \ is a function phi : F * X -> X where the partial applied phi(f, -) : X -> X\
    \ is a homomorphism on X\n */\ntemplate <class MonoidX, class MonoidF, class Action>\n\
    struct lazy_propagation_segment_tree {\n    static_assert (std::is_invocable_r<typename\
    \ MonoidX::value_type, Action, typename MonoidF::value_type, typename MonoidX::value_type>::value,\
    \ \"\");\n    typedef typename MonoidX::value_type value_type;\n    typedef typename\
    \ MonoidF::value_type operator_type;\n    MonoidX mon_x;\n    MonoidF mon_f;\n\
    \    Action act;\n    int n;\n    std::vector<value_type> a;\n    std::vector<operator_type>\
    \ f;\n\n    lazy_propagation_segment_tree() = default;\n    lazy_propagation_segment_tree(int\
    \ n_, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_ = MonoidF(),\
    \ const Action & act_ = Action())\n            : mon_x(mon_x_), mon_f(mon_f_),\
    \ act(act_) {\n        n = 1; while (n < n_) n *= 2;\n        a.resize(2 * n -\
    \ 1, mon_x.unit());\n        f.resize(n - 1, mon_f.unit());\n    }\n    template\
    \ <class InputIterator>\n    lazy_propagation_segment_tree(InputIterator first,\
    \ InputIterator last, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_\
    \ = MonoidF(), const Action & act_ = Action())\n            : mon_x(mon_x_), mon_f(mon_f_),\
    \ act(act_) {\n        int size = std::distance(first, last);\n        n = 1;\
    \ while (n < size) n *= 2;\n        a.resize(2 * n - 1, mon_x.unit());\n     \
    \   f.resize(n - 1, mon_f.unit());\n        std::copy(first, last, a.begin() +\
    \ (n - 1));\n        REP_R (i, n - 1) {\n            a[i] = mon_x.mult(a[2 * i\
    \ + 1], a[2 * i + 2]);\n        }\n    }\n\n    void point_set(int i, value_type\
    \ b) {\n        range_set(i, i + 1, b);\n    }\n    /**\n     * @note O(min(n,\
    \ (r - l) log n))\n     */\n    void range_set(int l, int r, value_type b) {\n\
    \        assert (0 <= l and l <= r and r <= n);\n        range_set(0, 0, n, l,\
    \ r, b);\n    }\n    void range_set(int i, int il, int ir, int l, int r, value_type\
    \ b) {\n        if (l <= il and ir <= r and ir - il == 1) {  // 0-based\n    \
    \        a[i] = b;\n        } else if (ir <= l or r <= il) {\n            // nop\n\
    \        } else {\n            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n,\
    \ f[i]);\n            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);\n\
    \            f[i] = mon_f.unit();\n            range_set(2 * i + 1, il, (il +\
    \ ir) / 2, l, r, b);\n            range_set(2 * i + 2, (il + ir) / 2, ir, l, r,\
    \ b);\n            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);\n        }\n\
    \    }\n\n    void point_apply(int i, operator_type g) {\n        range_apply(i,\
    \ i + 1, g);\n    }\n    void range_apply(int l, int r, operator_type g) {\n \
    \       assert (0 <= l and l <= r and r <= n);\n        range_apply(0, 0, n, l,\
    \ r, g);\n    }\n    void range_apply(int i, int il, int ir, int l, int r, operator_type\
    \ g) {\n        if (l <= il and ir <= r) { // 0-based\n            a[i] = act(g,\
    \ a[i]);\n            if (i < f.size()) f[i] = mon_f.mult(g, f[i]);\n        }\
    \ else if (ir <= l or r <= il) {\n            // nop\n        } else {\n     \
    \       range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);\n            range_apply(2\
    \ * i + 2, (il + ir) / 2, ir, 0, n, f[i]);\n            f[i] = mon_f.unit(); \
    \ // unnecessary if the oprator monoid is commutative\n            range_apply(2\
    \ * i + 1, il, (il + ir) / 2, l, r, g);\n            range_apply(2 * i + 2, (il\
    \ + ir) / 2, ir, l, r, g);\n            a[i] = mon_x.mult(a[2 * i + 1], a[2 *\
    \ i + 2]);\n        }\n    }\n\n    value_type point_get(int i) {\n        return\
    \ range_get(i, i + 1);\n    }\n    value_type range_get(int l, int r) {\n    \
    \    assert (0 <= l and l <= r and r <= n);\n        if (l == 0 and r == n) return\
    \ a[0];\n        value_type lacc = mon_x.unit(), racc = mon_x.unit();\n      \
    \  for (int l1 = (l += n), r1 = (r += n) - 1; l1 > 1; l /= 2, r /= 2, l1 /= 2,\
    \ r1 /= 2) {  // 1-based loop, 2x faster than recursion\n            if (l < r)\
    \ {\n                if (l % 2 == 1) lacc = mon_x.mult(lacc, a[(l ++) - 1]);\n\
    \                if (r % 2 == 1) racc = mon_x.mult(a[(-- r) - 1], racc);\n   \
    \         }\n            lacc = act(f[l1 / 2 - 1], lacc);\n            racc =\
    \ act(f[r1 / 2 - 1], racc);\n        }\n        return mon_x.mult(lacc, racc);\n\
    \    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: data_structure/lazy_propagation_segment_tree.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:22:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - utils/mo_algorithm.yuki1270.test.cpp
  - data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
  - data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
documentation_of: data_structure/lazy_propagation_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/lazy_propagation_segment_tree.hpp
- /library/data_structure/lazy_propagation_segment_tree.hpp.html
title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
  \u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)"
---
## 概要

次があるとする:

-   monoid $M = (M, \cdot, 1)$
-   monoid $F = (F, \circ, \mathrm{id})$
-   monoid $F$ の半群 $M$ に対する作用 $\star$。つまり関数 $\star : F \times M \to M$ であって、次を満たすもの
    -   $\forall a \in M.~ \mathrm{id} \star a = a$
    -   $\forall f, g \in F.~ \forall a \in M.~ (f \circ g) \star a = f \star (g \star a)$
    -   $\forall f \in F.~ \forall a, b \in M.~ f \star (a \cdot b) = (f \star a) \cdot (f \star b)$

このとき monoid $M$ の要素の列 $a = (a_0, a_1, \dots, a _ {n - 1}) \in M^n$ に対し、次が $O(\log N)$ で処理可能:

-   $\mathtt{range\unicode{95}apply}(l, r, g)$: それぞれの $i \in [l, r)$ に対し $a_i \gets g \star a_i$ と更新する。
-   $\mathtt{range\unicode{95}get}(l, r)$: 積 $a_l \cdot a _ {l + 1} \cdot \dots \cdot a _ {r - 1}$ を計算する。

他にも:

-   $\mathtt{point\unicode{95}get}(i)$: 値 $a_i$ を計算する。
-   $\mathtt{point\unicode{95}set}(i, b)$: $a_i \gets b$ と更新する。
-   $\mathtt{range\unicode{95}set}(l, r, b)$: それぞれの $i \in [l, r)$ に対し $a_i \gets b$ と更新する。
