---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dual_segment_tree.hpp
    title: "Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids,\
      \ \u5B8C\u5168\u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: monoids/left.hpp
    title: monoids/left.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"data_structure/dual_segment_tree.range_update_query.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#line 2 \"data_structure/dual_segment_tree.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\n/**\n * @brief Dual Segment Tree / \u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728\
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
    \ * i + 2, (il + ir) / 2, ir, l, r, g);\n        }\n    }\n};\n#line 2 \"monoids/left.hpp\"\
    \n#include <utility>\n\ntemplate <class T>\nstruct left_monoid {\n    // typedef\
    \ std::optional<T> value_type;\n    typedef std::pair<bool, T> value_type;\n \
    \   value_type unit() const { return std::make_pair(false, T()); }\n    value_type\
    \ mult(value_type a, value_type b) const { return a.first ? a : b; }\n};\n#line\
    \ 4 \"data_structure/dual_segment_tree.range_update_query.test.cpp\"\n\n#include\
    \ <iostream>\nusing namespace std;\n\nint main() {\n    int n, q; cin >> n >>\
    \ q;\n    dual_segment_tree<left_monoid<uint32_t> > segtree(n);\n    segtree.range_apply(0,\
    \ n, make_pair(true, (1u << 31) - 1));\n    while (q --) {\n        int com; cin\
    \ >> com;\n        if (com == 0) {\n            int l, r; uint32_t x; cin >> l\
    \ >> r >> x;\n            ++ r;\n            segtree.range_apply(l, r, make_pair(true,\
    \ x));\n        } else if (com == 1) {\n            int i; cin >> i;\n       \
    \     cout << segtree.point_get(i).second << endl;\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include \"data_structure/dual_segment_tree.hpp\"\n#include \"monoids/left.hpp\"\
    \n\n#include <iostream>\nusing namespace std;\n\nint main() {\n    int n, q; cin\
    \ >> n >> q;\n    dual_segment_tree<left_monoid<uint32_t> > segtree(n);\n    segtree.range_apply(0,\
    \ n, make_pair(true, (1u << 31) - 1));\n    while (q --) {\n        int com; cin\
    \ >> com;\n        if (com == 0) {\n            int l, r; uint32_t x; cin >> l\
    \ >> r >> x;\n            ++ r;\n            segtree.range_apply(l, r, make_pair(true,\
    \ x));\n        } else if (com == 1) {\n            int i; cin >> i;\n       \
    \     cout << segtree.point_get(i).second << endl;\n        }\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - data_structure/dual_segment_tree.hpp
  - monoids/left.hpp
  isVerificationFile: true
  path: data_structure/dual_segment_tree.range_update_query.test.cpp
  requiredBy: []
  timestamp: '2020-03-04 20:34:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/dual_segment_tree.range_update_query.test.cpp
layout: document
redirect_from:
- /verify/data_structure/dual_segment_tree.range_update_query.test.cpp
- /verify/data_structure/dual_segment_tree.range_update_query.test.cpp.html
title: data_structure/dual_segment_tree.range_update_query.test.cpp
---
