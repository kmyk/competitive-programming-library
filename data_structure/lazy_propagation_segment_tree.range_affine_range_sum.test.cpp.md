---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.hpp
    title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)"
  - icon: ':question:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':question:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':question:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/linear_function.hpp
    title: monoids/linear_function.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/linear_function_plus_count_action.hpp
    title: monoids/linear_function_plus_count_action.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus_count.hpp
    title: monoids/plus_count.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #line 2 \"data_structure/lazy_propagation_segment_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 7 \"data_structure/lazy_propagation_segment_tree.hpp\"\n\n/**\n * @brief Lazy\
    \ Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @docs data_structure/lazy_propagation_segment_tree.md\n\
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
    \    }\n};\n#line 2 \"monoids/plus_count.hpp\"\n#include <utility>\n\ntemplate\
    \ <class T>\nstruct plus_count_monoid {\n    typedef std::pair<T, int> value_type;\n\
    \    value_type unit() const {\n        return std::make_pair(T(), 0);\n    }\n\
    \    value_type mult(value_type a, value_type b) const {\n        return std::make_pair(a.first\
    \ + b.first, a.second + b.second);\n    }\n    static value_type make(T a) {\n\
    \        return std::make_pair(a, 1);\n    }\n};\n#line 3 \"monoids/linear_function.hpp\"\
    \n\ntemplate <class CommutativeRing>\nstruct linear_function_monoid {\n    typedef\
    \ std::pair<CommutativeRing, CommutativeRing> value_type;\n    linear_function_monoid()\
    \ = default;\n    value_type unit() const {\n        return std::make_pair(1,\
    \ 0);\n    }\n    value_type mult(value_type g, value_type f) const {\n      \
    \  CommutativeRing fst = g.first * f.first;\n        CommutativeRing snd = g.second\
    \ + g.first * f.second;\n        return std::make_pair(fst, snd);\n    }\n};\n\
    #line 4 \"monoids/linear_function_plus_count_action.hpp\"\n\n/**\n * @note lazy_propagation_segment_tree<plus_count_monoid<T>,\
    \ linear_function_monoid<T>, linear_function_plus_count_action<T> >\n */\ntemplate\
    \ <class T>\nstruct linear_function_plus_count_action {\n    typename plus_count_monoid<T>::value_type\
    \ operator () (typename linear_function_monoid<T>::value_type f, typename plus_count_monoid<T>::value_type\
    \ x) const {\n        return std::make_pair(f.first * x.first + f.second * x.second,\
    \ x.second);\n    }\n};\n#line 2 \"modulus/mint.hpp\"\n#include <cstdint>\n#include\
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
    #line 8 \"data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp\"\
    \n#include <cstdio>\n#line 11 \"data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp\"\
    \nusing namespace std;\n\nconstexpr int MOD = 998244353;\n\nint main() {\n   \
    \ int n, q; scanf(\"%d%d\", &n, &q);\n    vector<pair<mint<MOD>, int> > a(n);\n\
    \    REP (i, n) {\n        int a_i; scanf(\"%d\", &a_i);\n        a[i].first =\
    \ a_i;\n        a[i].second = 1;\n    }\n    lazy_propagation_segment_tree<plus_count_monoid<mint<MOD>\
    \ >, linear_function_monoid<mint<MOD> >, linear_function_plus_count_action<mint<MOD>\
    \ > > segtree(ALL(a));\n    while (q --) {\n        int t; scanf(\"%d\", &t);\n\
    \        if (t == 0) {\n            int l, r, b, c; scanf(\"%d%d%d%d\", &l, &r,\
    \ &b, &c);\n            pair<mint<MOD>, mint<MOD> > f(b, c);\n            segtree.range_apply(l,\
    \ r, f);\n        } else if (t == 1) {\n            int l, r; scanf(\"%d%d\",\
    \ &l, &r);\n            mint<MOD> answer = segtree.range_get(l, r).first;\n  \
    \          printf(\"%d\\n\", answer.value);\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"data_structure/lazy_propagation_segment_tree.hpp\"\n#include \"monoids/plus_count.hpp\"\
    \n#include \"monoids/linear_function.hpp\"\n#include \"monoids/linear_function_plus_count_action.hpp\"\
    \n#include \"modulus/mint.hpp\"\n#include \"utils/macros.hpp\"\n#include <cstdio>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\nconstexpr int MOD\
    \ = 998244353;\n\nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n    vector<pair<mint<MOD>,\
    \ int> > a(n);\n    REP (i, n) {\n        int a_i; scanf(\"%d\", &a_i);\n    \
    \    a[i].first = a_i;\n        a[i].second = 1;\n    }\n    lazy_propagation_segment_tree<plus_count_monoid<mint<MOD>\
    \ >, linear_function_monoid<mint<MOD> >, linear_function_plus_count_action<mint<MOD>\
    \ > > segtree(ALL(a));\n    while (q --) {\n        int t; scanf(\"%d\", &t);\n\
    \        if (t == 0) {\n            int l, r, b, c; scanf(\"%d%d%d%d\", &l, &r,\
    \ &b, &c);\n            pair<mint<MOD>, mint<MOD> > f(b, c);\n            segtree.range_apply(l,\
    \ r, f);\n        } else if (t == 1) {\n            int l, r; scanf(\"%d%d\",\
    \ &l, &r);\n            mint<MOD> answer = segtree.range_get(l, r).first;\n  \
    \          printf(\"%d\\n\", answer.value);\n        }\n    }\n    return 0;\n\
    }\n"
  dependsOn:
  - data_structure/lazy_propagation_segment_tree.hpp
  - utils/macros.hpp
  - monoids/plus_count.hpp
  - monoids/linear_function.hpp
  - monoids/linear_function_plus_count_action.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  isVerificationFile: true
  path: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 23:22:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
- /verify/data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp.html
title: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
---
