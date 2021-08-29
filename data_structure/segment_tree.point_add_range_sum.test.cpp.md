---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
      \u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"data_structure/segment_tree.point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line\
    \ 2 \"data_structure/segment_tree.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i\
    \ = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) <\
    \ (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 6 \"data_structure/segment_tree.hpp\"\
    \n\n/**\n * @brief Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids,\
    \ \u5B8C\u5168\u4E8C\u5206\u6728)\n * @docs data_structure/segment_tree.md\n *\
    \ @tparam Monoid (commutativity is not required)\n */\ntemplate <class Monoid>\n\
    struct segment_tree {\n    typedef typename Monoid::value_type value_type;\n \
    \   Monoid mon;\n    int n;\n    std::vector<value_type> a;\n    segment_tree()\
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
    \ i and i < n);\n        return a[i + n - 1];\n    }\n\n    /**\n     * @note\
    \ O(min(n, (r - l) log n))\n     */\n    void range_set(int l, int r, value_type\
    \ b) {\n        assert (0 <= l and l <= r and r <= n);\n        range_set(0, 0,\
    \ n, l, r, b);\n    }\n    void range_set(int i, int il, int ir, int l, int r,\
    \ value_type b) {\n        if (l <= il and ir <= r and ir - il == 1) {  // 0-based\n\
    \            a[i] = b;\n        } else if (ir <= l or r <= il) {\n           \
    \ // nop\n        } else {\n            range_set(2 * i + 1, il, (il + ir) / 2,\
    \ l, r, b);\n            range_set(2 * i + 2, (il + ir) / 2, ir, l, r, b);\n \
    \           a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);\n        }\n    }\n\n\
    \    /**\n     * @brief a fast & semigroup-friendly version constructor\n    \
    \ * @note $O(n)$\n     */\n    template <class InputIterator>\n    segment_tree(InputIterator\
    \ first, InputIterator last, const Monoid & mon_ = Monoid()) : mon(mon_) {\n \
    \       int size = std::distance(first, last);\n        n = 1; while (n < size)\
    \ n *= 2;\n        a.resize(2 * n - 1, mon.unit());\n        std::copy(first,\
    \ last, a.begin() + (n - 1));\n        unsafe_rebuild();\n    }\n    /**\n   \
    \  * @brief update a leaf node without updating ancestors\n     * @note $O(1)$\n\
    \     */\n    void unsafe_point_set(int i, value_type b) {  // 0-based\n     \
    \   assert (0 <= i and i < n);\n        a[i + n - 1] = b;\n    }\n    /**\n  \
    \   * @brief re-build non-leaf nodes from leaf nodes\n     * @note $O(n)$\n  \
    \   */\n    void unsafe_rebuild() {\n        REP_R (i, n - 1) {\n            a[i]\
    \ = mon.mult(a[2 * i + 1], a[2 * i + 2]);\n        }\n    }\n};\n#line 2 \"monoids/plus.hpp\"\
    \n\ntemplate <class T>\nstruct plus_monoid {\n    typedef T value_type;\n    value_type\
    \ unit() const { return value_type(); }\n    value_type mult(value_type a, value_type\
    \ b) const { return a + b; }\n};\n#line 5 \"data_structure/segment_tree.point_add_range_sum.test.cpp\"\
    \n#include <cstdint>\n#include <cstdio>\n#include <tuple>\n#line 9 \"data_structure/segment_tree.point_add_range_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n\
    \    vector<int64_t> a(n);\n    REP (i, n) {\n        scanf(\"%lld\", &a[i]);\n\
    \    }\n    segment_tree<plus_monoid<int64_t> > segtree(ALL(a));\n    while (q\
    \ --) {\n        int t, x, y; scanf(\"%d%d%d\", &t, &x, &y);\n        if (t ==\
    \ 0) {\n            segtree.point_set(x, segtree.point_get(x) + y);\n        }\
    \ else if (t == 1) {\n            int64_t answer = segtree.range_get(x, y);\n\
    \            printf(\"%lld\\n\", answer);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../data_structure/segment_tree.hpp\"\n#include \"../monoids/plus.hpp\"\
    \n#include \"../utils/macros.hpp\"\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <tuple>\n#include <vector>\nusing namespace std;\n\nint main() {\n    int n,\
    \ q; scanf(\"%d%d\", &n, &q);\n    vector<int64_t> a(n);\n    REP (i, n) {\n \
    \       scanf(\"%lld\", &a[i]);\n    }\n    segment_tree<plus_monoid<int64_t>\
    \ > segtree(ALL(a));\n    while (q --) {\n        int t, x, y; scanf(\"%d%d%d\"\
    , &t, &x, &y);\n        if (t == 0) {\n            segtree.point_set(x, segtree.point_get(x)\
    \ + y);\n        } else if (t == 1) {\n            int64_t answer = segtree.range_get(x,\
    \ y);\n            printf(\"%lld\\n\", answer);\n        }\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - data_structure/segment_tree.hpp
  - utils/macros.hpp
  - monoids/plus.hpp
  isVerificationFile: true
  path: data_structure/segment_tree.point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/segment_tree.point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/data_structure/segment_tree.point_add_range_sum.test.cpp
- /verify/data_structure/segment_tree.point_add_range_sum.test.cpp.html
title: data_structure/segment_tree.point_add_range_sum.test.cpp
---
