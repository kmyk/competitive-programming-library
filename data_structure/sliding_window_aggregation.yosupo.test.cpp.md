---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sliding_window_aggregation.hpp
    title: "Sliding Window Aggregation / \u542B\u307E\u308C\u308B\u8981\u7D20\u306E\
      \u7DCF\u548C\u304C $O(1)$ \u3067\u53D6\u308C\u308B queue (\u53EF\u63DB\u3068\
      \u306F\u9650\u3089\u306A\u3044 monoid \u304C\u4E57\u308B)"
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
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"data_structure/sliding_window_aggregation.yosupo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#line 2 \"data_structure/sliding_window_aggregation.hpp\"\n#include <cassert>\n\
    #include <cstddef>\n#include <deque>\n#line 2 \"utils/macros.hpp\"\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 6 \"\
    data_structure/sliding_window_aggregation.hpp\"\n\n/**\n * @brief Sliding Window\
    \ Aggregation / \u542B\u307E\u308C\u308B\u8981\u7D20\u306E\u7DCF\u548C\u304C $O(1)$\
    \ \u3067\u53D6\u308C\u308B queue (\u53EF\u63DB\u3068\u306F\u9650\u3089\u306A\u3044\
    \ monoid \u304C\u4E57\u308B)\n */\ntemplate <class Monoid>\nstruct sliding_window_aggregation\
    \ {\n    typedef typename Monoid::value_type value_type;\n    Monoid mon;\n  \
    \  std::deque<value_type> data;\n    int front;\n    value_type back;\n    sliding_window_aggregation(const\
    \ Monoid & mon_ = Monoid()) : mon(mon_) {\n        front = 0;\n        back =\
    \ mon.unit();\n    }\n    /**\n     * @note O(1)\n     */\n    void push(value_type\
    \ x) {\n        data.push_back(x);\n        back = mon.mult(back, x);\n    }\n\
    \    /**\n     * @note amortized O(1)\n     */\n    void pop() {\n        assert\
    \ (not data.empty());\n        data.pop_front();\n        if (front) {\n     \
    \       -- front;\n        } else {\n            REP_R (i, (int)data.size() -\
    \ 1) {\n                data[i] = mon.mult(data[i], data[i + 1]);\n          \
    \  }\n            front = data.size();\n            back = mon.unit();\n     \
    \   }\n    }\n    /**\n     * @brief get sum of elements in the queue\n     *\
    \ @note O(1)\n     */\n    value_type accumulate() const {\n        return front\
    \ ? mon.mult(data.front(), back) : back;\n    }\n    bool empty() const {\n  \
    \      return data.empty();\n    }\n    std::size_t size() const {\n        return\
    \ data.size();\n    }\n};\n#line 2 \"monoids/linear_function.hpp\"\n#include <utility>\n\
    \ntemplate <class CommutativeRing>\nstruct linear_function_monoid {\n    typedef\
    \ std::pair<CommutativeRing, CommutativeRing> value_type;\n    linear_function_monoid()\
    \ = default;\n    value_type unit() const {\n        return std::make_pair(1,\
    \ 0);\n    }\n    value_type mult(value_type g, value_type f) const {\n      \
    \  CommutativeRing fst = g.first * f.first;\n        CommutativeRing snd = g.second\
    \ + g.first * f.second;\n        return std::make_pair(fst, snd);\n    }\n};\n\
    #line 2 \"monoids/dual.hpp\"\n\n/**\n * @see http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual\n\
    \ */\ntemplate <class Monoid>\nstruct dual_monoid {\n    typedef typename Monoid::value_type\
    \ value_type;\n    Monoid base;\n    value_type unit() const { return base.unit();\
    \ }\n    value_type mult(const value_type & a, const value_type & b) const { return\
    \ base.mult(b, a); }\n};\n#line 2 \"modulus/mint.hpp\"\n#include <cstdint>\n#include\
    \ <iostream>\n#line 4 \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t\
    \ x, uint64_t k, int32_t MOD) {\n    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n\
    \    uint_fast64_t y = 1;\n    for (; k; k >>= 1) {\n        if (k & 1) (y *=\
    \ x) %= MOD;\n        (x *= x) %= MOD;\n    }\n    assert (/* 0 <= y and */ y\
    \ < (uint_fast64_t)MOD);\n    return y;\n}\n#line 2 \"modulus/modinv.hpp\"\n#include\
    \ <algorithm>\n#line 5 \"modulus/modinv.hpp\"\n\ninline int32_t modinv_nocheck(int32_t\
    \ value, int32_t MOD) {\n    assert (0 <= value and value < MOD);\n    if (value\
    \ == 0) return -1;\n    int64_t a = value, b = MOD;\n    int64_t x = 0, y = 1;\n\
    \    for (int64_t u = 1, v = 0; a; ) {\n        int64_t q = b / a;\n        x\
    \ -= q * u; std::swap(x, u);\n        y -= q * v; std::swap(y, v);\n        b\
    \ -= q * a; std::swap(b, a);\n    }\n    if (not (value * x + MOD * y == b and\
    \ b == 1)) return -1;\n    if (x < 0) x += MOD;\n    assert (0 <= x and x < MOD);\n\
    \    return x;\n}\n\ninline int32_t modinv(int32_t x, int32_t MOD) {\n    int32_t\
    \ y = modinv_nocheck(x, MOD);\n    assert (y != -1);\n    return y;\n}\n#line\
    \ 6 \"modulus/mint.hpp\"\n\n/**\n * @brief quotient ring / \u5270\u4F59\u74B0\
    \ $\\mathbb{Z}/n\\mathbb{Z}$\n */\ntemplate <int32_t MOD>\nstruct mint {\n   \
    \ int32_t value;\n    mint() : value() {}\n    mint(int64_t value_) : value(value_\
    \ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}\n    mint(int32_t\
    \ value_, std::nullptr_t) : value(value_) {}\n    explicit operator bool() const\
    \ { return value; }\n    inline mint<MOD> operator + (mint<MOD> other) const {\
    \ return mint<MOD>(*this) += other; }\n    inline mint<MOD> operator - (mint<MOD>\
    \ other) const { return mint<MOD>(*this) -= other; }\n    inline mint<MOD> operator\
    \ * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }\n    inline\
    \ mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value\
    \ >= MOD) this->value -= MOD; return *this; }\n    inline mint<MOD> & operator\
    \ -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value\
    \ += MOD; return *this; }\n    inline mint<MOD> & operator *= (mint<MOD> other)\
    \ { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this;\
    \ }\n    inline mint<MOD> operator - () const { return mint<MOD>(this->value ?\
    \ MOD - this->value : 0, nullptr); }\n    inline bool operator == (mint<MOD> other)\
    \ const { return value == other.value; }\n    inline bool operator != (mint<MOD>\
    \ other) const { return value != other.value; }\n    inline mint<MOD> pow(uint64_t\
    \ k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }\n    inline mint<MOD>\
    \ inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }\n    inline mint<MOD>\
    \ operator / (mint<MOD> other) const { return *this * other.inv(); }\n    inline\
    \ mint<MOD> & operator /= (mint<MOD> other) { return *this *= other.inv(); }\n\
    };\ntemplate <int32_t MOD> mint<MOD> operator + (int64_t value, mint<MOD> n) {\
    \ return mint<MOD>(value) + n; }\ntemplate <int32_t MOD> mint<MOD> operator -\
    \ (int64_t value, mint<MOD> n) { return mint<MOD>(value) - n; }\ntemplate <int32_t\
    \ MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value)\
    \ * n; }\ntemplate <int32_t MOD> mint<MOD> operator / (int64_t value, mint<MOD>\
    \ n) { return mint<MOD>(value) / n; }\ntemplate <int32_t MOD> std::istream & operator\
    \ >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value;\
    \ return in; }\ntemplate <int32_t MOD> std::ostream & operator << (std::ostream\
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 6 \"data_structure/sliding_window_aggregation.yosupo.test.cpp\"\
    \n#include <cstdio>\n#include <tuple>\nusing namespace std;\n\nconstexpr int MOD\
    \ = 998244353;\nint main() {\n    int q; scanf(\"%d\", &q);\n    sliding_window_aggregation<dual_monoid<linear_function_monoid<mint<MOD>\
    \ > > > swag;\n    while (q --) {\n        int t; scanf(\"%d\", &t);\n       \
    \ if (t == 0) {\n            int a, b; scanf(\"%d%d\", &a, &b);\n            swag.push(make_pair(a,\
    \ b));\n        } else if (t == 1) {\n            swag.pop();\n        } else\
    \ if (t == 2) {\n            int x; scanf(\"%d\", &x);\n            mint<MOD>\
    \ a, b; tie(a, b) = swag.accumulate();\n            printf(\"%d\\n\", (a * x +\
    \ b).value);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include \"data_structure/sliding_window_aggregation.hpp\"\n#include \"monoids/linear_function.hpp\"\
    \n#include \"monoids/dual.hpp\"\n#include \"modulus/mint.hpp\"\n#include <cstdio>\n\
    #include <tuple>\nusing namespace std;\n\nconstexpr int MOD = 998244353;\nint\
    \ main() {\n    int q; scanf(\"%d\", &q);\n    sliding_window_aggregation<dual_monoid<linear_function_monoid<mint<MOD>\
    \ > > > swag;\n    while (q --) {\n        int t; scanf(\"%d\", &t);\n       \
    \ if (t == 0) {\n            int a, b; scanf(\"%d%d\", &a, &b);\n            swag.push(make_pair(a,\
    \ b));\n        } else if (t == 1) {\n            swag.pop();\n        } else\
    \ if (t == 2) {\n            int x; scanf(\"%d\", &x);\n            mint<MOD>\
    \ a, b; tie(a, b) = swag.accumulate();\n            printf(\"%d\\n\", (a * x +\
    \ b).value);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/sliding_window_aggregation.hpp
  - utils/macros.hpp
  - monoids/linear_function.hpp
  - monoids/dual.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  isVerificationFile: true
  path: data_structure/sliding_window_aggregation.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-07-16 00:35:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/sliding_window_aggregation.yosupo.test.cpp
layout: document
redirect_from:
- /verify/data_structure/sliding_window_aggregation.yosupo.test.cpp
- /verify/data_structure/sliding_window_aggregation.yosupo.test.cpp.html
title: data_structure/sliding_window_aggregation.yosupo.test.cpp
---
