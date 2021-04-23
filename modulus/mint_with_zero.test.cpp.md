---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':heavy_check_mark:'
    path: modulus/mint_with_zero.hpp
    title: "$\\mathbb{Z}$ \u306E\u4E57\u9664\u7B97\u3092 $\\mathbb{Z}/n\\mathbb{Z}$\
      \ \u306E\u4E0A\u3067\u3084\u308B\u30C7\u30FC\u30BF\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
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
    PROBLEM: https://atcoder.jp/contests/arc117/tasks/arc117_c
    links:
    - https://atcoder.jp/contests/arc117/tasks/arc117_c
  bundledCode: "#line 1 \"modulus/mint_with_zero.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc117/tasks/arc117_c\"\
    \n#include <array>\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 2 \"modulus/mint.hpp\"\n#include <cstdint>\n#line 4 \"modulus/modpow.hpp\"\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 7 \"modulus/mint_with_zero.hpp\"\
    \n\n/**\n * @brief $\\mathbb{Z}$ \u306E\u4E57\u9664\u7B97\u3092 $\\mathbb{Z}/n\\\
    mathbb{Z}$ \u306E\u4E0A\u3067\u3084\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n * @sa\
    \ https://kimiyuki.net/blog/2021/04/23/modulo-with-zero/\n */\ntemplate <int32_t\
    \ MOD>\nstruct zmint {\n    int32_t nonzero;\n    int32_t zero;\n    zmint() :\
    \ nonzero(1) {}\n    zmint(int64_t nonzero_, int32_t zero_ = 0) : nonzero(nonzero_),\
    \ zero(zero_) { assert (nonzero != 0); while (nonzero % MOD == 0) { nonzero /=\
    \ MOD; zero += 1; } if (nonzero < 0) nonzero = nonzero % MOD + MOD; }\n    zmint(int32_t\
    \ nonzero_, int32_t zero_, std::nullptr_t) : nonzero(nonzero_), zero(zero_) {}\n\
    \    explicit operator bool() const { return nonzero; }\n    inline zmint<MOD>\
    \ operator * (zmint<MOD> other) const { return zmint<MOD>(*this) *= other; }\n\
    \    inline zmint<MOD> & operator *= (zmint<MOD> other) { nonzero = static_cast<uint_fast64_t>(this->nonzero)\
    \ * other.nonzero % MOD; zero += other.zero; return *this; }\n    inline zmint<MOD>\
    \ operator / (zmint<MOD> other) const { return *this * other.inv(); }\n    inline\
    \ zmint<MOD> & operator /= (zmint<MOD> other) { return *this *= other.inv(); }\n\
    \    inline zmint<MOD> operator - () const { return zmint<MOD>(nonzero ? MOD -\
    \ nonzero : 0, zero, nullptr); }\n    inline bool operator == (zmint<MOD> other)\
    \ const { return nonzero == other.nonzero and zero == other.zero; }\n    inline\
    \ bool operator != (zmint<MOD> other) const { return nonzero != other.nonzero\
    \ or zero != other.zero; }\n    inline zmint<MOD> pow(uint64_t k) const { return\
    \ zmint<MOD>(modpow(nonzero, k, MOD), k * zero, nullptr); }\n    inline zmint<MOD>\
    \ inv() const { return zmint<MOD>(modinv(nonzero, MOD), - zero, nullptr); }\n\
    \    inline mint<MOD> to_mint() const { assert (nonzero >= 0); return zero ? 0\
    \ : nonzero; }\n};\ntemplate <int32_t MOD> zmint<MOD> operator * (int64_t nonzero,\
    \ zmint<MOD> n) { return zmint<MOD>(nonzero) * n; }\ntemplate <int32_t MOD> zmint<MOD>\
    \ operator / (int64_t nonzero, zmint<MOD> n) { return zmint<MOD>(nonzero) / n;\
    \ }\n#line 9 \"modulus/mint_with_zero.test.cpp\"\nusing namespace std;\n\nint\
    \ solve(int n, const std::vector<int>& a) {\n    std::vector<zmint<3> > fact(n\
    \ + 1);\n    fact[0] = 1;\n    REP (i, n) {\n        fact[i + 1] = (i + 1) * fact[i];\n\
    \    }\n    auto choose = [&](int n, int r) {\n        return (fact[n] * fact[n\
    \ - r].inv() * fact[r].inv()).to_mint();\n    };\n\n    mint<3> b = 0;\n    REP\
    \ (i, n) {\n        b += choose(n - 1, i) * a[i];\n    }\n    if (n % 2 == 0)\
    \ {\n        b *= -1;\n    }\n    return b.value;\n}\n\nint main() {\n    int\
    \ n; std::cin >> n;\n    std::string s; std::cin >> s;\n    assert (s.length()\
    \ == n);\n    std::vector<int> a(n);\n    REP (i, n) {\n        a[i] = (s[i] ==\
    \ 'W' ? 0 : s[i] == 'R' ? 1 : s[i] == 'B' ? 2 : -1);\n        assert (a[i] !=\
    \ -1);\n    }\n    int ans = solve(n, a);\n    assert (0 <= ans and ans < 3);\n\
    \    std::array<char, 3> table = {{ 'W', 'R', 'B' }};\n    std::cout << table[ans]\
    \ << std::endl;\n    return 0;\n}\n\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc117/tasks/arc117_c\"\n#include\
    \ <array>\n#include <cassert>\n#include <iostream>\n#include <vector>\n#include\
    \ \"utils/macros.hpp\"\n#include \"modulus/mint.hpp\"\n#include \"modulus/mint_with_zero.hpp\"\
    \nusing namespace std;\n\nint solve(int n, const std::vector<int>& a) {\n    std::vector<zmint<3>\
    \ > fact(n + 1);\n    fact[0] = 1;\n    REP (i, n) {\n        fact[i + 1] = (i\
    \ + 1) * fact[i];\n    }\n    auto choose = [&](int n, int r) {\n        return\
    \ (fact[n] * fact[n - r].inv() * fact[r].inv()).to_mint();\n    };\n\n    mint<3>\
    \ b = 0;\n    REP (i, n) {\n        b += choose(n - 1, i) * a[i];\n    }\n   \
    \ if (n % 2 == 0) {\n        b *= -1;\n    }\n    return b.value;\n}\n\nint main()\
    \ {\n    int n; std::cin >> n;\n    std::string s; std::cin >> s;\n    assert\
    \ (s.length() == n);\n    std::vector<int> a(n);\n    REP (i, n) {\n        a[i]\
    \ = (s[i] == 'W' ? 0 : s[i] == 'R' ? 1 : s[i] == 'B' ? 2 : -1);\n        assert\
    \ (a[i] != -1);\n    }\n    int ans = solve(n, a);\n    assert (0 <= ans and ans\
    \ < 3);\n    std::array<char, 3> table = {{ 'W', 'R', 'B' }};\n    std::cout <<\
    \ table[ans] << std::endl;\n    return 0;\n}\n\n"
  dependsOn:
  - utils/macros.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  - modulus/mint_with_zero.hpp
  isVerificationFile: true
  path: modulus/mint_with_zero.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 11:00:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: modulus/mint_with_zero.test.cpp
layout: document
redirect_from:
- /verify/modulus/mint_with_zero.test.cpp
- /verify/modulus/mint_with_zero.test.cpp.html
title: modulus/mint_with_zero.test.cpp
---
