---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://kimiyuki.net/blog/2016/02/01/cf-gym-100753/
  bundledCode: "#line 1 \"old/miller-rabin.inc.cpp\"\n// https://kimiyuki.net/blog/2016/02/01/cf-gym-100753/\n\
    template <class Generator>\nbool is_prime(ll n, int iteration, Generator & gen)\
    \ { // miller-rabin primality test, O(k log n)\n    assert (0 <= n);\n    if (n\
    \ == 2) return true;\n    if (n == 1 or n % 2 == 0) return false;\n    const ll\
    \ d = (n-1) >> __builtin_ctzll(n-1); // remove trailing zeros\n    uniform_int_distribution<ll>\
    \ dist(1, n-2); // [l, r]\n    repeat (dummy, iteration) {\n        ll a = dist(gen);\n\
    \        ll t = d;\n        ll y = powmod(a, t, n);\n        while (t != n-1 and\
    \ y != 1 and y != n-1) {\n            y = y * y % n;\n            t *= 2;\n  \
    \      }\n        if (y != n-1 and t % 2 == 0) return false;\n    }\n    return\
    \ true;\n}\nbool is_prime(ll n) {\n    static default_random_engine engine = default_random_engine(random_device()());\n\
    \    return is_prime(n, 20, engine);\n}\n"
  code: "// https://kimiyuki.net/blog/2016/02/01/cf-gym-100753/\ntemplate <class Generator>\n\
    bool is_prime(ll n, int iteration, Generator & gen) { // miller-rabin primality\
    \ test, O(k log n)\n    assert (0 <= n);\n    if (n == 2) return true;\n    if\
    \ (n == 1 or n % 2 == 0) return false;\n    const ll d = (n-1) >> __builtin_ctzll(n-1);\
    \ // remove trailing zeros\n    uniform_int_distribution<ll> dist(1, n-2); //\
    \ [l, r]\n    repeat (dummy, iteration) {\n        ll a = dist(gen);\n       \
    \ ll t = d;\n        ll y = powmod(a, t, n);\n        while (t != n-1 and y !=\
    \ 1 and y != n-1) {\n            y = y * y % n;\n            t *= 2;\n       \
    \ }\n        if (y != n-1 and t % 2 == 0) return false;\n    }\n    return true;\n\
    }\nbool is_prime(ll n) {\n    static default_random_engine engine = default_random_engine(random_device()());\n\
    \    return is_prime(n, 20, engine);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/miller-rabin.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/miller-rabin.inc.cpp
layout: document
redirect_from:
- /library/old/miller-rabin.inc.cpp
- /library/old/miller-rabin.inc.cpp.html
title: old/miller-rabin.inc.cpp
---
