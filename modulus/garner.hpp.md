---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':question:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':question:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Garner's algorithm
    links: []
  bundledCode: "#line 2 \"modulus/garner.hpp\"\n#include <cassert>\n#include <cstdint>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n#line 3 \"modulus/mint.hpp\"\
    \n#include <iostream>\n#line 4 \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 9 \"modulus/garner.hpp\"\n\n/**\n * @brief Garner's algorithm\n * @arg eqns\
    \ is equations like x = a_i (mod m_i)\n * @return the minimal solution of given\
    \ equations\n */\nint32_t garner_algorithm(std::vector<std::pair<int32_t, int32_t>\
    \ > eqns, int32_t MOD) {\n    eqns.emplace_back(0, MOD);\n    std::vector<int64_t>\
    \ k(eqns.size(), 1);\n    std::vector<int64_t> c(eqns.size(), 0);\n    REP (i,\
    \ eqns.size() - 1) {\n        int32_t a_i, m_i; std::tie(a_i, m_i) = eqns[i];\n\
    \n        int32_t x = (a_i - c[i]) * modinv(k[i], m_i) % m_i;\n        if (x <\
    \ 0) x += m_i;\n        assert (a_i == (k[i] * x + c[i]) % m_i);\n\n        REP3\
    \ (j, i + 1, eqns.size()) {\n            int32_t a_j, m_j; std::tie(a_j, m_j)\
    \ = eqns[j];\n            (c[j] += k[j] * x) %= m_j;\n            (k[j] *= m_i)\
    \ %= m_j;\n        }\n    }\n    return c.back();\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n#include \"modulus/mint.hpp\"\n#include\
    \ \"utils/macros.hpp\"\n\n/**\n * @brief Garner's algorithm\n * @arg eqns is equations\
    \ like x = a_i (mod m_i)\n * @return the minimal solution of given equations\n\
    \ */\nint32_t garner_algorithm(std::vector<std::pair<int32_t, int32_t> > eqns,\
    \ int32_t MOD) {\n    eqns.emplace_back(0, MOD);\n    std::vector<int64_t> k(eqns.size(),\
    \ 1);\n    std::vector<int64_t> c(eqns.size(), 0);\n    REP (i, eqns.size() -\
    \ 1) {\n        int32_t a_i, m_i; std::tie(a_i, m_i) = eqns[i];\n\n        int32_t\
    \ x = (a_i - c[i]) * modinv(k[i], m_i) % m_i;\n        if (x < 0) x += m_i;\n\
    \        assert (a_i == (k[i] * x + c[i]) % m_i);\n\n        REP3 (j, i + 1, eqns.size())\
    \ {\n            int32_t a_j, m_j; std::tie(a_j, m_j) = eqns[j];\n           \
    \ (c[j] += k[j] * x) %= m_j;\n            (k[j] *= m_i) %= m_j;\n        }\n \
    \   }\n    return c.back();\n}\n"
  dependsOn:
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  - utils/macros.hpp
  isVerificationFile: false
  path: modulus/garner.hpp
  requiredBy: []
  timestamp: '2020-07-16 00:35:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modulus/garner.hpp
layout: document
redirect_from:
- /library/modulus/garner.hpp
- /library/modulus/garner.hpp.html
title: Garner's algorithm
---
