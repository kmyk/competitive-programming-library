---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: the Bernoulli number
    links:
    - https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0
    - https://yukicoder.me/problems/no/665
  bundledCode: "#line 1 \"old/bernoulli-number.inc.cpp\"\n/**\n * @brief the Bernoulli\
    \ number\n * @tparam MOD must be a prime\n * @note $O(n^2)$\n * @see https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0\n\
    \ */\ntemplate <int MOD>\nint bernoulli_number(int i) {\n    static vector<int>\
    \ dp(1, 1);\n    while (dp.size() <= i) {\n        int n = dp.size();\n      \
    \  ll acc = 0;\n        REP (k, n) {\n            acc += choose<MOD>(n + 1, k)\
    \ *(ll) dp[k] % MOD;\n        }\n        acc %= MOD;\n        (acc *= modinv(n\
    \ + 1, MOD)) %= MOD;\n        acc = (acc == 0 ? 0 : MOD - acc);\n        dp.push_back(acc);\n\
    \    }\n    return dp[i];\n}\nunittest {\n    constexpr int MOD = 1e9 + 7;\n \
    \   assert (bernoulli_number<MOD>(0) == 1);\n    assert (bernoulli_number<MOD>(1)\
    \ == (MOD - 1ll) * modinv(2, MOD) % MOD);\n    assert (bernoulli_number<MOD>(2)\
    \ == modinv(6, MOD));\n    assert (bernoulli_number<MOD>(3) == 0);\n    assert\
    \ (bernoulli_number<MOD>(4) == (MOD - 1ll) * modinv(30, MOD) % MOD);\n    assert\
    \ (bernoulli_number<MOD>(26) == 8553103ll * modinv(6, MOD) % MOD);\n}\n\n/**\n\
    \ * @brief $0^k + 1^k + 2^k + ... + (n - 1)^k$\n * @see https://yukicoder.me/problems/no/665\n\
    \ * @note n can be >= MOD\n */\ntemplate <int MOD>\nint sum_of_pow(ll n, int k)\
    \ {\n    ll acc = 0;\n    REP (j, k + 1) {\n        acc += choose<MOD>(k + 1,\
    \ j) *(ll) bernoulli_number<MOD>(j) % MOD *(ll) powmod(n % MOD, k - j + 1, MOD)\
    \ % MOD;\n    }\n    acc %= MOD;\n    (acc *= modinv(k + 1, MOD)) %= MOD;\n  \
    \  return acc;\n}\n"
  code: "/**\n * @brief the Bernoulli number\n * @tparam MOD must be a prime\n * @note\
    \ $O(n^2)$\n * @see https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0\n\
    \ */\ntemplate <int MOD>\nint bernoulli_number(int i) {\n    static vector<int>\
    \ dp(1, 1);\n    while (dp.size() <= i) {\n        int n = dp.size();\n      \
    \  ll acc = 0;\n        REP (k, n) {\n            acc += choose<MOD>(n + 1, k)\
    \ *(ll) dp[k] % MOD;\n        }\n        acc %= MOD;\n        (acc *= modinv(n\
    \ + 1, MOD)) %= MOD;\n        acc = (acc == 0 ? 0 : MOD - acc);\n        dp.push_back(acc);\n\
    \    }\n    return dp[i];\n}\nunittest {\n    constexpr int MOD = 1e9 + 7;\n \
    \   assert (bernoulli_number<MOD>(0) == 1);\n    assert (bernoulli_number<MOD>(1)\
    \ == (MOD - 1ll) * modinv(2, MOD) % MOD);\n    assert (bernoulli_number<MOD>(2)\
    \ == modinv(6, MOD));\n    assert (bernoulli_number<MOD>(3) == 0);\n    assert\
    \ (bernoulli_number<MOD>(4) == (MOD - 1ll) * modinv(30, MOD) % MOD);\n    assert\
    \ (bernoulli_number<MOD>(26) == 8553103ll * modinv(6, MOD) % MOD);\n}\n\n/**\n\
    \ * @brief $0^k + 1^k + 2^k + ... + (n - 1)^k$\n * @see https://yukicoder.me/problems/no/665\n\
    \ * @note n can be >= MOD\n */\ntemplate <int MOD>\nint sum_of_pow(ll n, int k)\
    \ {\n    ll acc = 0;\n    REP (j, k + 1) {\n        acc += choose<MOD>(k + 1,\
    \ j) *(ll) bernoulli_number<MOD>(j) % MOD *(ll) powmod(n % MOD, k - j + 1, MOD)\
    \ % MOD;\n    }\n    acc %= MOD;\n    (acc *= modinv(k + 1, MOD)) %= MOD;\n  \
    \  return acc;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/bernoulli-number.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/bernoulli-number.inc.cpp
layout: document
redirect_from:
- /library/old/bernoulli-number.inc.cpp
- /library/old/bernoulli-number.inc.cpp.html
title: the Bernoulli number
---
