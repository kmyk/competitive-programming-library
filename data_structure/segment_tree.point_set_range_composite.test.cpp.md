---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
      \u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':heavy_check_mark:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/dual.hpp
    title: monoids/dual.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/linear_function.hpp
    title: monoids/linear_function.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"data_structure/segment_tree.point_set_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 2 \"data_structure/segment_tree.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n)\
    \ for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i =\
    \ (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1;\
    \ (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >=\
    \ (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 6 \"data_structure/segment_tree.hpp\"\
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
    \ = mon.mult(a[2 * i + 1], a[2 * i + 2]);\n        }\n    }\n};\n#line 2 \"monoids/linear_function.hpp\"\
    \n#include <utility>\n\ntemplate <class CommutativeRing>\nstruct linear_function_monoid\
    \ {\n    typedef std::pair<CommutativeRing, CommutativeRing> value_type;\n   \
    \ linear_function_monoid() = default;\n    value_type unit() const {\n       \
    \ return std::make_pair(1, 0);\n    }\n    value_type mult(value_type g, value_type\
    \ f) const {\n        CommutativeRing fst = g.first * f.first;\n        CommutativeRing\
    \ snd = g.second + g.first * f.second;\n        return std::make_pair(fst, snd);\n\
    \    }\n};\n#line 2 \"monoids/dual.hpp\"\n\n/**\n * @see http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual\n\
    \ */\ntemplate <class Monoid>\nstruct dual_monoid {\n    typedef typename Monoid::value_type\
    \ value_type;\n    Monoid base;\n    value_type unit() const { return base.unit();\
    \ }\n    value_type mult(const value_type & a, const value_type & b) const { return\
    \ base.mult(b, a); }\n};\n#line 2 \"modulus/mint.hpp\"\n#include <cstdint>\n#include\
    \ <iostream>\n#line 4 \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t\
    \ x, uint64_t k, int32_t MOD) {\n    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n\
    \    uint_fast64_t y = 1;\n    for (; k; k >>= 1) {\n        if (k & 1) (y *=\
    \ x) %= MOD;\n        (x *= x) %= MOD;\n    }\n    assert (/* 0 <= y and */ y\
    \ < (uint_fast64_t)MOD);\n    return y;\n}\n#line 5 \"modulus/modinv.hpp\"\n\n\
    inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {\n    assert (0 <=\
    \ value and value < MOD);\n    if (value == 0) return -1;\n    int64_t a = value,\
    \ b = MOD;\n    int64_t x = 0, y = 1;\n    for (int64_t u = 1, v = 0; a; ) {\n\
    \        int64_t q = b / a;\n        x -= q * u; std::swap(x, u);\n        y -=\
    \ q * v; std::swap(y, v);\n        b -= q * a; std::swap(b, a);\n    }\n    if\
    \ (not (value * x + MOD * y == b and b == 1)) return -1;\n    if (x < 0) x +=\
    \ MOD;\n    assert (0 <= x and x < MOD);\n    return x;\n}\n\ninline int32_t modinv(int32_t\
    \ x, int32_t MOD) {\n    int32_t y = modinv_nocheck(x, MOD);\n    assert (y !=\
    \ -1);\n    return y;\n}\n#line 6 \"modulus/mint.hpp\"\n\n/**\n * @brief quotient\
    \ ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$\n */\ntemplate <int32_t\
    \ MOD>\nstruct mint {\n    int32_t value;\n    mint() : value() {}\n    mint(int64_t\
    \ value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD\
    \ : value_) {}\n    mint(int32_t value_, std::nullptr_t) : value(value_) {}\n\
    \    explicit operator bool() const { return value; }\n    inline mint<MOD> operator\
    \ + (mint<MOD> other) const { return mint<MOD>(*this) += other; }\n    inline\
    \ mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other;\
    \ }\n    inline mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this)\
    \ *= other; }\n    inline mint<MOD> & operator += (mint<MOD> other) { this->value\
    \ += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }\n\
    \    inline mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value;\
    \ if (this->value <    0) this->value += MOD; return *this; }\n    inline mint<MOD>\
    \ & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value *\
    \ other.value % MOD; return *this; }\n    inline mint<MOD> operator - () const\
    \ { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }\n    inline\
    \ bool operator == (mint<MOD> other) const { return value == other.value; }\n\
    \    inline bool operator != (mint<MOD> other) const { return value != other.value;\
    \ }\n    inline mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value,\
    \ k, MOD), nullptr); }\n    inline mint<MOD> inv() const { return mint<MOD>(modinv(value,\
    \ MOD), nullptr); }\n    inline mint<MOD> operator / (mint<MOD> other) const {\
    \ return *this * other.inv(); }\n    inline mint<MOD> & operator /= (mint<MOD>\
    \ other) { return *this *= other.inv(); }\n};\ntemplate <int32_t MOD> mint<MOD>\
    \ operator + (int64_t value, mint<MOD> n) { return mint<MOD>(value) + n; }\ntemplate\
    \ <int32_t MOD> mint<MOD> operator - (int64_t value, mint<MOD> n) { return mint<MOD>(value)\
    \ - n; }\ntemplate <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD>\
    \ n) { return mint<MOD>(value) * n; }\ntemplate <int32_t MOD> mint<MOD> operator\
    \ / (int64_t value, mint<MOD> n) { return mint<MOD>(value) / n; }\ntemplate <int32_t\
    \ MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t\
    \ value; in >> value; n = value; return in; }\ntemplate <int32_t MOD> std::ostream\
    \ & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }\n\
    #line 8 \"data_structure/segment_tree.point_set_range_composite.test.cpp\"\n#include\
    \ <tuple>\nusing namespace std;\n\nconstexpr int MOD = 998244353;\nint main()\
    \ {\n    int n, q; scanf(\"%d%d\", &n, &q);\n    segment_tree<dual_monoid<linear_function_monoid<mint<MOD>\
    \ > > > segtree(n);\n    REP (i, n) {\n        int a, b; scanf(\"%d%d\", &a, &b);\n\
    \        segtree.point_set(i, make_pair(a, b));\n    }\n    while (q --) {\n \
    \       int f, x, y, z; scanf(\"%d%d%d%d\", &f, &x, &y, &z);\n        if (f ==\
    \ 0) {\n            segtree.point_set(x, make_pair(y, z));\n        } else if\
    \ (f == 1) {\n            mint<MOD> a, b; tie(a, b) = segtree.range_get(x, y);\n\
    \            printf(\"%d\\n\", (a * z + b).value);\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"data_structure/segment_tree.hpp\"\n#include \"monoids/linear_function.hpp\"\
    \n#include \"monoids/dual.hpp\"\n#include \"modulus/mint.hpp\"\n#include \"utils/macros.hpp\"\
    \n#include <cstdint>\n#include <tuple>\nusing namespace std;\n\nconstexpr int\
    \ MOD = 998244353;\nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n   \
    \ segment_tree<dual_monoid<linear_function_monoid<mint<MOD> > > > segtree(n);\n\
    \    REP (i, n) {\n        int a, b; scanf(\"%d%d\", &a, &b);\n        segtree.point_set(i,\
    \ make_pair(a, b));\n    }\n    while (q --) {\n        int f, x, y, z; scanf(\"\
    %d%d%d%d\", &f, &x, &y, &z);\n        if (f == 0) {\n            segtree.point_set(x,\
    \ make_pair(y, z));\n        } else if (f == 1) {\n            mint<MOD> a, b;\
    \ tie(a, b) = segtree.range_get(x, y);\n            printf(\"%d\\n\", (a * z +\
    \ b).value);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/segment_tree.hpp
  - utils/macros.hpp
  - monoids/linear_function.hpp
  - monoids/dual.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  isVerificationFile: true
  path: data_structure/segment_tree.point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 23:22:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/segment_tree.point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/data_structure/segment_tree.point_set_range_composite.test.cpp
- /verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html
title: data_structure/segment_tree.point_set_range_composite.test.cpp
---
