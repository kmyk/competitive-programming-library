---
data:
  _extendedDependsOn:
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
    path: number/matrix.hpp
    title: number/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1073
    links:
    - https://yukicoder.me/problems/no/1073
  bundledCode: "#line 1 \"number/matrix.yukicoder-1073.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1073\"\n#line 2 \"number/matrix.hpp\"\n#include\
    \ <cstdint>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n)\
    \ for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i =\
    \ (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1;\
    \ (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >=\
    \ (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 5 \"number/matrix.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::vector<T> > operator * (const std::vector<std::vector<T>\
    \ >& a, const std::vector<std::vector<T> >& b) {\n    int n = a.size();\n    std::vector<std::vector<T>\
    \ > c(n, std::vector<T>(n));\n    REP (y, n) {\n        REP (z, n) {\n       \
    \     REP (x, n) {\n                c[y][x] += a[y][z] * b[z][x];\n          \
    \  }\n        }\n    }\n    return c;\n}\n\ntemplate <typename T>\nstd::vector<T>\
    \ operator * (const std::vector<std::vector<T> >& a, const std::vector<T>& b)\
    \ {\n    int n = a.size();\n    std::vector<T> c(n);\n    REP (y, n) {\n     \
    \   REP (z, n) {\n            c[y] += a[y][z] * b[z];\n        }\n    }\n    return\
    \ c;\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T> > unit_matrix(int\
    \ n) {\n    auto e = std::vector<std::vector<T> >(n, std::vector<T>(n));\n   \
    \ REP (i, n) {\n        e[i][i] = 1;\n    }\n    return e;\n}\n\ntemplate <typename\
    \ T>\nstd::vector<std::vector<T> > zero_matrix(int n) {\n    return std::vector<std::vector<T>\
    \ >(n, std::vector<T>(n));\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T>\
    \ > matpow(std::vector<std::vector<T> > x, int64_t y) {\n    int n = x.size();\n\
    \    auto z = unit_matrix<T>(n);\n    for (int64_t i = 1; i <= y; i <<= 1) {\n\
    \        if (y & i) {\n            z = z * x;\n        }\n        x = x * x;\n\
    \    }\n    return z;\n}\n#line 3 \"modulus/mint.hpp\"\n#include <iostream>\n\
    #line 2 \"modulus/modpow.hpp\"\n#include <cassert>\n#line 4 \"modulus/modpow.hpp\"\
    \n\ninline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {\n    assert\
    \ (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n    uint_fast64_t y = 1;\n    for\
    \ (; k; k >>= 1) {\n        if (k & 1) (y *= x) %= MOD;\n        (x *= x) %= MOD;\n\
    \    }\n    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);\n    return y;\n\
    }\n#line 2 \"modulus/modinv.hpp\"\n#include <algorithm>\n#line 5 \"modulus/modinv.hpp\"\
    \n\ninline int32_t modinv_nocheck(int32_t value, int32_t MOD) {\n    assert (0\
    \ <= value and value < MOD);\n    if (value == 0) return -1;\n    int64_t a =\
    \ value, b = MOD;\n    int64_t x = 0, y = 1;\n    for (int64_t u = 1, v = 0; a;\
    \ ) {\n        int64_t q = b / a;\n        x -= q * u; std::swap(x, u);\n    \
    \    y -= q * v; std::swap(y, v);\n        b -= q * a; std::swap(b, a);\n    }\n\
    \    if (not (value * x + MOD * y == b and b == 1)) return -1;\n    if (x < 0)\
    \ x += MOD;\n    assert (0 <= x and x < MOD);\n    return x;\n}\n\ninline int32_t\
    \ modinv(int32_t x, int32_t MOD) {\n    int32_t y = modinv_nocheck(x, MOD);\n\
    \    assert (y != -1);\n    return y;\n}\n#line 6 \"modulus/mint.hpp\"\n\n/**\n\
    \ * @brief quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$\n */\n\
    template <int32_t MOD>\nstruct mint {\n    int32_t value;\n    mint() : value()\
    \ {}\n    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_\
    \ >= MOD ? value_ % MOD : value_) {}\n    mint(int32_t value_, std::nullptr_t)\
    \ : value(value_) {}\n    explicit operator bool() const { return value; }\n \
    \   inline mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this)\
    \ += other; }\n    inline mint<MOD> operator - (mint<MOD> other) const { return\
    \ mint<MOD>(*this) -= other; }\n    inline mint<MOD> operator * (mint<MOD> other)\
    \ const { return mint<MOD>(*this) *= other; }\n    inline mint<MOD> & operator\
    \ += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value\
    \ -= MOD; return *this; }\n    inline mint<MOD> & operator -= (mint<MOD> other)\
    \ { this->value -= other.value; if (this->value <    0) this->value += MOD; return\
    \ *this; }\n    inline mint<MOD> & operator *= (mint<MOD> other) { this->value\
    \ = (uint_fast64_t)this->value * other.value % MOD; return *this; }\n    inline\
    \ mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value\
    \ : 0, nullptr); }\n    inline bool operator == (mint<MOD> other) const { return\
    \ value == other.value; }\n    inline bool operator != (mint<MOD> other) const\
    \ { return value != other.value; }\n    inline mint<MOD> pow(uint64_t k) const\
    \ { return mint<MOD>(modpow(value, k, MOD), nullptr); }\n    inline mint<MOD>\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 5 \"number/matrix.yukicoder-1073.test.cpp\"\
    \nusing namespace std;\n\n\nconstexpr int MOD = 1000000007;\nmint<MOD> solve(int64_t\
    \ n) {\n    vector<vector<mint<MOD> > > f = {\n        vector<mint<MOD> >{ 0,\
    \ 0, 0, 0, 0, mint<MOD>(6).inv() },\n        vector<mint<MOD> >{ 1, 0, 0, 0, 0,\
    \ mint<MOD>(6).inv() },\n        vector<mint<MOD> >{ 0, 1, 0, 0, 0, mint<MOD>(6).inv()\
    \ },\n        vector<mint<MOD> >{ 0, 0, 1, 0, 0, mint<MOD>(6).inv() },\n     \
    \   vector<mint<MOD> >{ 0, 0, 0, 1, 0, mint<MOD>(6).inv() },\n        vector<mint<MOD>\
    \ >{ 0, 0, 0, 0, 1, mint<MOD>(6).inv() },\n    };\n    vector<mint<MOD> > x =\
    \ {\n        0,\n        0,\n        0,\n        0,\n        0,\n        1,\n\
    \    };\n    return (matpow(f, n) * x)[5];\n}\n\nint main() {\n    int64_t n;\
    \ cin >> n;\n    auto ans = solve(n);\n    cout << ans << endl;\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1073\"\n#include \"../number/matrix.hpp\"\
    \n#include \"../modulus/mint.hpp\"\n#include <iostream>\nusing namespace std;\n\
    \n\nconstexpr int MOD = 1000000007;\nmint<MOD> solve(int64_t n) {\n    vector<vector<mint<MOD>\
    \ > > f = {\n        vector<mint<MOD> >{ 0, 0, 0, 0, 0, mint<MOD>(6).inv() },\n\
    \        vector<mint<MOD> >{ 1, 0, 0, 0, 0, mint<MOD>(6).inv() },\n        vector<mint<MOD>\
    \ >{ 0, 1, 0, 0, 0, mint<MOD>(6).inv() },\n        vector<mint<MOD> >{ 0, 0, 1,\
    \ 0, 0, mint<MOD>(6).inv() },\n        vector<mint<MOD> >{ 0, 0, 0, 1, 0, mint<MOD>(6).inv()\
    \ },\n        vector<mint<MOD> >{ 0, 0, 0, 0, 1, mint<MOD>(6).inv() },\n    };\n\
    \    vector<mint<MOD> > x = {\n        0,\n        0,\n        0,\n        0,\n\
    \        0,\n        1,\n    };\n    return (matpow(f, n) * x)[5];\n}\n\nint main()\
    \ {\n    int64_t n; cin >> n;\n    auto ans = solve(n);\n    cout << ans << endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - number/matrix.hpp
  - utils/macros.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  isVerificationFile: true
  path: number/matrix.yukicoder-1073.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: number/matrix.yukicoder-1073.test.cpp
layout: document
redirect_from:
- /verify/number/matrix.yukicoder-1073.test.cpp
- /verify/number/matrix.yukicoder-1073.test.cpp.html
title: number/matrix.yukicoder-1073.test.cpp
---
