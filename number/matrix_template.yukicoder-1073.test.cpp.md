---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number/matrix_template.hpp
    title: number/matrix_template.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':heavy_check_mark:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1073
    links:
    - https://yukicoder.me/problems/no/1073
  bundledCode: "#line 1 \"number/matrix_template.yukicoder-1073.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1073\"\n#line 2 \"number/matrix_template.hpp\"\
    \n#include <array>\n#include <cstdint>\n#line 2 \"utils/macros.hpp\"\n#define\
    \ REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for\
    \ (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n)\
    \ - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 5 \"\
    number/matrix_template.hpp\"\n\ntemplate <typename T, size_t H, size_t W>\nusing\
    \ matrix = std::array<std::array<T, W>, H>;\n\ntemplate <typename T, size_t A,\
    \ size_t B, size_t C>\nmatrix<T, A, C> operator * (matrix<T, A, B> const & a,\
    \ matrix<T, B, C> const & b) {\n    matrix<T, A, C> c = {};\n    REP (y, A) REP\
    \ (z, B) REP (x, C) c[y][x] += a[y][z] * b[z][x];\n    return c;\n}\ntemplate\
    \ <typename T, size_t H, size_t W>\nstd::array<T, H> operator * (matrix<T, H,\
    \ W> const & a, std::array<T, W> const & b) {\n    std::array<T, H> c = {};\n\
    \    REP (y, H) REP (z, W) c[y] += a[y][z] * b[z];\n    return c;\n}\n\ntemplate\
    \ <typename T, size_t H, size_t W>\nmatrix<T, H, W> operator + (matrix<T, H, W>\
    \ const & a, matrix<T, H, W> const & b) {\n    matrix<T, H, W> c;\n    REP (y,\
    \ H) REP (x, W) c[y][x] = a[y][x] + b[y][x];\n    return c;\n}\n\ntemplate <typename\
    \ T, size_t N>\nstd::array<T, N> operator + (std::array<T, N> const & a, std::array<T,\
    \ N> const & b) {\n    std::array<T, N> c;\n    REP (i, N) c[i] = a[i] + b[i];\n\
    \    return c;\n}\n\ntemplate <typename T, size_t H, size_t W>\nmatrix<T, H, W>\
    \ zero_matrix() {\n    return {};\n}\n\ntemplate <typename T, size_t N>\nmatrix<T,\
    \ N, N> unit_matrix() {\n    matrix<T, N, N> a = {};\n    REP (i, N) a[i][i] =\
    \ 1;\n    return a;\n}\n\ntemplate <typename T, size_t N>\nmatrix<T, N, N> powmat(matrix<T,\
    \ N, N> x, int64_t k) {\n    matrix<T, N, N> y = unit_matrix<T, N>();\n    for\
    \ (; k; k >>= 1) {\n        if (k & 1) y = y * x;\n        x = x * x;\n    }\n\
    \    return y;\n}\n#line 3 \"modulus/mint.hpp\"\n#include <iostream>\n#line 2\
    \ \"modulus/modpow.hpp\"\n#include <cassert>\n#line 4 \"modulus/modpow.hpp\"\n\
    \ninline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {\n    assert\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 5 \"number/matrix_template.yukicoder-1073.test.cpp\"\
    \nusing namespace std;\n\n\nconstexpr int MOD = 1000000007;\nmint<MOD> solve(int64_t\
    \ n) {\n    matrix<mint<MOD>, 6, 6> f = {{\n        {{ 0, 0, 0, 0, 0, mint<MOD>(6).inv()\
    \ }},\n        {{ 1, 0, 0, 0, 0, mint<MOD>(6).inv() }},\n        {{ 0, 1, 0, 0,\
    \ 0, mint<MOD>(6).inv() }},\n        {{ 0, 0, 1, 0, 0, mint<MOD>(6).inv() }},\n\
    \        {{ 0, 0, 0, 1, 0, mint<MOD>(6).inv() }},\n        {{ 0, 0, 0, 0, 1, mint<MOD>(6).inv()\
    \ }},\n    }};\n    array<mint<MOD>, 6> x = {{\n        0,\n        0,\n     \
    \   0,\n        0,\n        0,\n        1,\n    }};\n    return (powmat(f, n)\
    \ * x)[5];\n}\n\nint main() {\n    int64_t n; cin >> n;\n    auto ans = solve(n);\n\
    \    cout << ans << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1073\"\n#include \"number/matrix_template.hpp\"\
    \n#include \"modulus/mint.hpp\"\n#include <iostream>\nusing namespace std;\n\n\
    \nconstexpr int MOD = 1000000007;\nmint<MOD> solve(int64_t n) {\n    matrix<mint<MOD>,\
    \ 6, 6> f = {{\n        {{ 0, 0, 0, 0, 0, mint<MOD>(6).inv() }},\n        {{ 1,\
    \ 0, 0, 0, 0, mint<MOD>(6).inv() }},\n        {{ 0, 1, 0, 0, 0, mint<MOD>(6).inv()\
    \ }},\n        {{ 0, 0, 1, 0, 0, mint<MOD>(6).inv() }},\n        {{ 0, 0, 0, 1,\
    \ 0, mint<MOD>(6).inv() }},\n        {{ 0, 0, 0, 0, 1, mint<MOD>(6).inv() }},\n\
    \    }};\n    array<mint<MOD>, 6> x = {{\n        0,\n        0,\n        0,\n\
    \        0,\n        0,\n        1,\n    }};\n    return (powmat(f, n) * x)[5];\n\
    }\n\nint main() {\n    int64_t n; cin >> n;\n    auto ans = solve(n);\n    cout\
    \ << ans << endl;\n    return 0;\n}\n"
  dependsOn:
  - number/matrix_template.hpp
  - utils/macros.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  isVerificationFile: true
  path: number/matrix_template.yukicoder-1073.test.cpp
  requiredBy: []
  timestamp: '2020-07-16 00:35:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: number/matrix_template.yukicoder-1073.test.cpp
layout: document
redirect_from:
- /verify/number/matrix_template.yukicoder-1073.test.cpp
- /verify/number/matrix_template.yukicoder-1073.test.cpp.html
title: number/matrix_template.yukicoder-1073.test.cpp
---
