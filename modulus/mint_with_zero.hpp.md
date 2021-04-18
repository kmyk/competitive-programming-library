---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u96F6\u306E\u500B\u6570\u4ED8\u304D\u5270\u4F59\u6F14\u7B97\u306E\
      \u4E57\u6CD5\u7FA4 $\\mathbb{Z}/n\\mathbb{Z} \\times \\mathbb{Z}$"
    links: []
  bundledCode: "#line 2 \"modulus/mint_with_zero.hpp\"\n#include <cstdint>\n#include\
    \ <iostream>\n#line 2 \"modulus/modpow.hpp\"\n#include <cassert>\n#line 4 \"modulus/modpow.hpp\"\
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
    \    assert (y != -1);\n    return y;\n}\n#line 6 \"modulus/mint_with_zero.hpp\"\
    \n\n/**\n * @brief \u96F6\u306E\u500B\u6570\u4ED8\u304D\u5270\u4F59\u6F14\u7B97\
    \u306E\u4E57\u6CD5\u7FA4 $\\mathbb{Z}/n\\mathbb{Z} \\times \\mathbb{Z}$\n */\n\
    template <int32_t MOD>\nstruct zmint {\n    int32_t nonzero;\n    int32_t zero;\n\
    \    zmint() : nonzero() {}\n    zmint(int64_t nonzero_, int32_t zero_ = 0) :\
    \ nonzero(nonzero_), zero(zero_) { while (nonzero and nonzero % MOD == 0) { nonzero_\
    \ /= MOD; zero_ += 1; } if (nonzero_ < 0) nonzero_ = nonzero_ % MOD + MOD; }\n\
    \    zmint(int32_t nonzero_, int32_t zero_, std::nullptr_t) : nonzero(nonzero_),\
    \ zero(zero_) {}\n    explicit operator bool() const { return nonzero; }\n   \
    \ inline zmint<MOD> operator * (zmint<MOD> other) const { return zmint<MOD>(*this)\
    \ *= other; }\n    inline zmint<MOD> & operator *= (zmint<MOD> other) { nonzero\
    \ = static_cast<uint_fast64_t>(this->nonzero) * other.nonzero % MOD; zero += other.zero;\
    \ return *this; }\n    inline zmint<MOD> operator / (zmint<MOD> other) const {\
    \ return *this * other.inv(); }\n    inline zmint<MOD> & operator /= (zmint<MOD>\
    \ other) { return *this *= other.inv(); }\n    inline zmint<MOD> operator - ()\
    \ const { return zmint<MOD>(nonzero ? MOD - nonzero : 0, zero, nullptr); }\n \
    \   inline bool operator == (zmint<MOD> other) const { return nonzero == other.nonzero\
    \ and zero == other.zero; }\n    inline bool operator != (zmint<MOD> other) const\
    \ { return nonzero != other.nonzero or zero != other.zero; }\n    inline zmint<MOD>\
    \ pow(uint64_t k) const { return zmint<MOD>(modpow(nonzero, k, MOD), k * zero,\
    \ nullptr); }\n    inline zmint<MOD> inv() const { return zmint<MOD>(modinv(nonzero,\
    \ MOD), - zero, nullptr); }\n};\ntemplate <int32_t MOD> zmint<MOD> operator *\
    \ (int64_t nonzero, zmint<MOD> n) { return zmint<MOD>(nonzero) * n; }\ntemplate\
    \ <int32_t MOD> zmint<MOD> operator / (int64_t nonzero, zmint<MOD> n) { return\
    \ zmint<MOD>(nonzero) / n; }\n"
  code: "#pragma once\n#include <cstdint>\n#include <iostream>\n#include \"modulus/modpow.hpp\"\
    \n#include \"modulus/modinv.hpp\"\n\n/**\n * @brief \u96F6\u306E\u500B\u6570\u4ED8\
    \u304D\u5270\u4F59\u6F14\u7B97\u306E\u4E57\u6CD5\u7FA4 $\\mathbb{Z}/n\\mathbb{Z}\
    \ \\times \\mathbb{Z}$\n */\ntemplate <int32_t MOD>\nstruct zmint {\n    int32_t\
    \ nonzero;\n    int32_t zero;\n    zmint() : nonzero() {}\n    zmint(int64_t nonzero_,\
    \ int32_t zero_ = 0) : nonzero(nonzero_), zero(zero_) { while (nonzero and nonzero\
    \ % MOD == 0) { nonzero_ /= MOD; zero_ += 1; } if (nonzero_ < 0) nonzero_ = nonzero_\
    \ % MOD + MOD; }\n    zmint(int32_t nonzero_, int32_t zero_, std::nullptr_t) :\
    \ nonzero(nonzero_), zero(zero_) {}\n    explicit operator bool() const { return\
    \ nonzero; }\n    inline zmint<MOD> operator * (zmint<MOD> other) const { return\
    \ zmint<MOD>(*this) *= other; }\n    inline zmint<MOD> & operator *= (zmint<MOD>\
    \ other) { nonzero = static_cast<uint_fast64_t>(this->nonzero) * other.nonzero\
    \ % MOD; zero += other.zero; return *this; }\n    inline zmint<MOD> operator /\
    \ (zmint<MOD> other) const { return *this * other.inv(); }\n    inline zmint<MOD>\
    \ & operator /= (zmint<MOD> other) { return *this *= other.inv(); }\n    inline\
    \ zmint<MOD> operator - () const { return zmint<MOD>(nonzero ? MOD - nonzero :\
    \ 0, zero, nullptr); }\n    inline bool operator == (zmint<MOD> other) const {\
    \ return nonzero == other.nonzero and zero == other.zero; }\n    inline bool operator\
    \ != (zmint<MOD> other) const { return nonzero != other.nonzero or zero != other.zero;\
    \ }\n    inline zmint<MOD> pow(uint64_t k) const { return zmint<MOD>(modpow(nonzero,\
    \ k, MOD), k * zero, nullptr); }\n    inline zmint<MOD> inv() const { return zmint<MOD>(modinv(nonzero,\
    \ MOD), - zero, nullptr); }\n};\ntemplate <int32_t MOD> zmint<MOD> operator *\
    \ (int64_t nonzero, zmint<MOD> n) { return zmint<MOD>(nonzero) * n; }\ntemplate\
    \ <int32_t MOD> zmint<MOD> operator / (int64_t nonzero, zmint<MOD> n) { return\
    \ zmint<MOD>(nonzero) / n; }\n"
  dependsOn:
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  isVerificationFile: false
  path: modulus/mint_with_zero.hpp
  requiredBy: []
  timestamp: '2021-04-18 22:48:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modulus/mint_with_zero.hpp
layout: document
redirect_from:
- /library/modulus/mint_with_zero.hpp
- /library/modulus/mint_with_zero.hpp.html
title: "\u96F6\u306E\u500B\u6570\u4ED8\u304D\u5270\u4F59\u6F14\u7B97\u306E\u4E57\u6CD5\
  \u7FA4 $\\mathbb{Z}/n\\mathbb{Z} \\times \\mathbb{Z}$"
---
