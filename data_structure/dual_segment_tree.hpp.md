---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: data_structure/dual_segment_tree.md
    document_title: "Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)"
  bundledCode: "#line 2 \"data_structure/dual_segment_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n/**\n * @brief Dual Segment Tree / \u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728\
    )\n * @docs data_structure/dual_segment_tree.md\n * @tparam Monoid (commutativity\
    \ is not required)\n */\ntemplate <class Monoid>\nstruct dual_segment_tree {\n\
    \    typedef typename Monoid::value_type value_type;\n    const Monoid mon;\n\
    \    int n;\n    std::vector<value_type> f;\n    dual_segment_tree() = default;\n\
    \    dual_segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {\n\
    \        n = 1; while (n < n_) n *= 2;\n        f.resize(2 * n - 1, mon.unit());\n\
    \    }\n    value_type point_get(int i) {  // 0-based\n        assert (0 <= i\
    \ and i < n);\n        value_type acc = mon.unit();\n        for (i += n; i >\
    \ 0; i /= 2) {  // 1-based\n            acc = mon.mult(f[i - 1], acc);\n     \
    \   }\n        return acc;\n    }\n    void range_apply(int l, int r, value_type\
    \ g) {  // 0-based, [l, r)\n        assert (0 <= l and l <= r and r <= n);\n \
    \       range_apply(0, 0, n, l, r, g);\n    }\n    void range_apply(int i, int\
    \ il, int ir, int l, int r, value_type g) {\n        if (l <= il and ir <= r)\
    \ {  // 0-based\n            f[i] = mon.mult(g, f[i]);\n        } else if (ir\
    \ <= l or r <= il) {\n            // nop\n        } else {\n            range_apply(2\
    \ * i + 1, il, (il + ir) / 2, 0, n, f[i]);\n            range_apply(2 * i + 2,\
    \ (il + ir) / 2, ir, 0, n, f[i]);\n            f[i] = mon.unit();\n          \
    \  range_apply(2 * i + 1, il, (il + ir) / 2, l, r, g);\n            range_apply(2\
    \ * i + 2, (il + ir) / 2, ir, l, r, g);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n/**\n * @brief Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @docs data_structure/dual_segment_tree.md\n\
    \ * @tparam Monoid (commutativity is not required)\n */\ntemplate <class Monoid>\n\
    struct dual_segment_tree {\n    typedef typename Monoid::value_type value_type;\n\
    \    const Monoid mon;\n    int n;\n    std::vector<value_type> f;\n    dual_segment_tree()\
    \ = default;\n    dual_segment_tree(int n_, const Monoid & mon_ = Monoid()) :\
    \ mon(mon_) {\n        n = 1; while (n < n_) n *= 2;\n        f.resize(2 * n -\
    \ 1, mon.unit());\n    }\n    value_type point_get(int i) {  // 0-based\n    \
    \    assert (0 <= i and i < n);\n        value_type acc = mon.unit();\n      \
    \  for (i += n; i > 0; i /= 2) {  // 1-based\n            acc = mon.mult(f[i -\
    \ 1], acc);\n        }\n        return acc;\n    }\n    void range_apply(int l,\
    \ int r, value_type g) {  // 0-based, [l, r)\n        assert (0 <= l and l <=\
    \ r and r <= n);\n        range_apply(0, 0, n, l, r, g);\n    }\n    void range_apply(int\
    \ i, int il, int ir, int l, int r, value_type g) {\n        if (l <= il and ir\
    \ <= r) {  // 0-based\n            f[i] = mon.mult(g, f[i]);\n        } else if\
    \ (ir <= l or r <= il) {\n            // nop\n        } else {\n            range_apply(2\
    \ * i + 1, il, (il + ir) / 2, 0, n, f[i]);\n            range_apply(2 * i + 2,\
    \ (il + ir) / 2, ir, 0, n, f[i]);\n            f[i] = mon.unit();\n          \
    \  range_apply(2 * i + 1, il, (il + ir) / 2, l, r, g);\n            range_apply(2\
    \ * i + 2, (il + ir) / 2, ir, l, r, g);\n        }\n    }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/dual_segment_tree.range_update_query.test.cpp
    title: data_structure/dual_segment_tree.range_update_query.test.cpp
  isVerificationFile: false
  path: data_structure/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2020-03-04 20:34:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - data_structure/dual_segment_tree.range_update_query.test.cpp
documentation_of: data_structure/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/dual_segment_tree.hpp
- /library/data_structure/dual_segment_tree.hpp.html
title: "Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids,\
  \ \u5B8C\u5168\u4E8C\u5206\u6728)"
---
## 概要

monoid $F = (F, \circ, \mathrm{id})$ の要素の列 $f = (f_0, f_1, \dots, f _ {n - 1}) \in F^n$ に対し、次が $O(\log N)$ で処理可能:

-   $\mathtt{range\unicode{95}set}(l, r, g)$: それぞれの $i \in [l, r)$ に対し $f_i \gets g \circ f_i$ と更新する。
-   $\mathtt{point\unicode{95}get}(i)$: 値 $f_i$ を計算する。
