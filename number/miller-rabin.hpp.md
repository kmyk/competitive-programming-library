---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: miller-rabin primality test
    links: []
  bundledCode: "#line 2 \"number/miller-rabin.hpp\"\n#include <cassert>\n#include\
    \ <random>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i)\
    \ < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n\
    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 3 \"modulus/modpow.hpp\"\n#include\
    \ <cstdint>\n\ninline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD)\
    \ {\n    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n    uint_fast64_t\
    \ y = 1;\n    for (; k; k >>= 1) {\n        if (k & 1) (y *= x) %= MOD;\n    \
    \    (x *= x) %= MOD;\n    }\n    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);\n\
    \    return y;\n}\n#line 6 \"number/miller-rabin.hpp\"\n\n/**\n * @brief miller-rabin\
    \ primality test\n * @note $O(k \\log n)$\n */\ntemplate <class RandomEngine>\n\
    bool is_prime(int64_t n, int iteration, RandomEngine& gen) {\n    assert (0 <=\
    \ n);\n    if (n == 2) return true;\n    if (n == 1 or n % 2 == 0) return false;\n\
    \    const int64_t d = (n - 1) >> __builtin_ctzll(n - 1);  // remove trailing\
    \ zeros\n    std::uniform_int_distribution<int64_t> dist(1, n - 2);  // [l, r]\n\
    \    REP (dummy, iteration) {\n        int64_t a = dist(gen);\n        int64_t\
    \ t = d;\n        int64_t y = modpow(a, t, n);\n        while (t != n - 1 and\
    \ y != 1 and y != n - 1) {\n            y = y * y % n;\n            t *= 2;\n\
    \        }\n        if (y != n - 1 and t % 2 == 0) return false;\n    }\n    return\
    \ true;\n}\n\nbool is_prime(int64_t n) {\n    static std::default_random_engine\
    \ gen = std::default_random_engine(std::random_device()());\n    return is_prime(n,\
    \ 20, gen);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <random>\n#include \"utils/macros.hpp\"\
    \n#include \"modulus/modpow.hpp\"\n\n/**\n * @brief miller-rabin primality test\n\
    \ * @note $O(k \\log n)$\n */\ntemplate <class RandomEngine>\nbool is_prime(int64_t\
    \ n, int iteration, RandomEngine& gen) {\n    assert (0 <= n);\n    if (n == 2)\
    \ return true;\n    if (n == 1 or n % 2 == 0) return false;\n    const int64_t\
    \ d = (n - 1) >> __builtin_ctzll(n - 1);  // remove trailing zeros\n    std::uniform_int_distribution<int64_t>\
    \ dist(1, n - 2);  // [l, r]\n    REP (dummy, iteration) {\n        int64_t a\
    \ = dist(gen);\n        int64_t t = d;\n        int64_t y = modpow(a, t, n);\n\
    \        while (t != n - 1 and y != 1 and y != n - 1) {\n            y = y * y\
    \ % n;\n            t *= 2;\n        }\n        if (y != n - 1 and t % 2 == 0)\
    \ return false;\n    }\n    return true;\n}\n\nbool is_prime(int64_t n) {\n  \
    \  static std::default_random_engine gen = std::default_random_engine(std::random_device()());\n\
    \    return is_prime(n, 20, gen);\n}\n"
  dependsOn:
  - utils/macros.hpp
  - modulus/modpow.hpp
  isVerificationFile: false
  path: number/miller-rabin.hpp
  requiredBy: []
  timestamp: '2021-04-03 00:01:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number/miller-rabin.hpp
layout: document
redirect_from:
- /library/number/miller-rabin.hpp
- /library/number/miller-rabin.hpp.html
title: miller-rabin primality test
---
