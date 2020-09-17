---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: modulus/modsqrt.yosupo.test.cpp
    title: modulus/modsqrt.yosupo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: find the sqrt $b$ of $a$ modulo $p$
    links: []
  bundledCode: "#line 2 \"modulus/modsqrt.hpp\"\n#include <cassert>\n#include <cstdint>\n\
    #line 4 \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t x, uint64_t\
    \ k, int32_t MOD) {\n    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n \
    \   uint_fast64_t y = 1;\n    for (; k; k >>= 1) {\n        if (k & 1) (y *= x)\
    \ %= MOD;\n        (x *= x) %= MOD;\n    }\n    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);\n\
    \    return y;\n}\n#line 5 \"modulus/modsqrt.hpp\"\n\n/**\n * @brief find the\
    \ sqrt $b$ of $a$ modulo $p$\n * @param p must be a prime\n * @note i.e. $b^2\
    \ \\equiv a \\pmod{p}$\n * @note -1 if not found\n */\nint modsqrt(int a, int\
    \ p) {\n    auto legendre_symbol = [&](int a) {\n        return modpow(a, (p -\
    \ 1) / 2, p);  // Euler's criterion\n    };\n    a %= p;\n    if (a == 0) return\
    \ 0;\n    if (p == 2) return a;\n    assert (p >= 3);\n    if (legendre_symbol(a)\
    \ != +1) return -1;\n    int b = 1;\n    while (legendre_symbol(b) == 1) {\n \
    \       b += 1;\n    }\n    int e = 0;\n    int m = p - 1;\n    while (m % 2 ==\
    \ 0) {\n        m /= 2;\n        e += 1;\n    }\n    int64_t x = modpow(a, (m\
    \ - 1) / 2, p);\n    int64_t y = a * x % p * x % p;\n    x = x * a % p;\n    int64_t\
    \ z = modpow(b, m, p);\n    while (y != 1) {\n        int j = 0;\n        for\
    \ (int64_t t = y; t != 1; t = t * t % p) ++ j;\n        if (e <= j) return -1;\n\
    \        z = modpow(z, 1ll << (e - j - 1), p);\n        x = x * z % p;\n     \
    \   z = z * z % p;\n        y = y * z % p;\n        e = j;\n    }\n    assert\
    \ (x * x % p == a);\n    return x;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include \"modulus/modpow.hpp\"\
    \n\n/**\n * @brief find the sqrt $b$ of $a$ modulo $p$\n * @param p must be a\
    \ prime\n * @note i.e. $b^2 \\equiv a \\pmod{p}$\n * @note -1 if not found\n */\n\
    int modsqrt(int a, int p) {\n    auto legendre_symbol = [&](int a) {\n       \
    \ return modpow(a, (p - 1) / 2, p);  // Euler's criterion\n    };\n    a %= p;\n\
    \    if (a == 0) return 0;\n    if (p == 2) return a;\n    assert (p >= 3);\n\
    \    if (legendre_symbol(a) != +1) return -1;\n    int b = 1;\n    while (legendre_symbol(b)\
    \ == 1) {\n        b += 1;\n    }\n    int e = 0;\n    int m = p - 1;\n    while\
    \ (m % 2 == 0) {\n        m /= 2;\n        e += 1;\n    }\n    int64_t x = modpow(a,\
    \ (m - 1) / 2, p);\n    int64_t y = a * x % p * x % p;\n    x = x * a % p;\n \
    \   int64_t z = modpow(b, m, p);\n    while (y != 1) {\n        int j = 0;\n \
    \       for (int64_t t = y; t != 1; t = t * t % p) ++ j;\n        if (e <= j)\
    \ return -1;\n        z = modpow(z, 1ll << (e - j - 1), p);\n        x = x * z\
    \ % p;\n        z = z * z % p;\n        y = y * z % p;\n        e = j;\n    }\n\
    \    assert (x * x % p == a);\n    return x;\n}\n"
  dependsOn:
  - modulus/modpow.hpp
  isVerificationFile: false
  path: modulus/modsqrt.hpp
  requiredBy: []
  timestamp: '2020-06-16 07:51:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - modulus/modsqrt.yosupo.test.cpp
documentation_of: modulus/modsqrt.hpp
layout: document
redirect_from:
- /library/modulus/modsqrt.hpp
- /library/modulus/modsqrt.hpp.html
title: find the sqrt $b$ of $a$ modulo $p$
---
