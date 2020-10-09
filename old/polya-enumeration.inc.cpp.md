---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/polya-enumeration.inc.cpp\"\n/**\n * @note using Polya\
    \ enumeration theorem\n * @note factorization + O(d(n)^2 + sqrt n)\n */\ntemplate\
    \ <int MOD>\nmint<MOD> count_cycle_coloring(int n, int k) {\n    auto primes =\
    \ list_primes(sqrt(n) + 3);\n    map<ll, int> factors = prime_factorize(n, primes);\n\
    \    vector<ll> divs = list_divisors(n, primes);\n    mint<MOD> cnt = 0;\n   \
    \ for (ll div : divs) {\n        ll e = div;  // Euler's phi of div\n        for\
    \ (auto it : factors) {\n            int p = it.first;\n            if (div %\
    \ p == 0) {\n                e = e / p * (p - 1);\n            }\n        }\n\
    \        cnt += mint<MOD>(k).pow(n / div) * e;\n    }\n    return cnt / n;\n}\n\
    \nunittest {\n    constexpr int MOD = 1e9 + 7;\n    assert (count_cycle_coloring<MOD>(2,\
    \ 10).value == 55);\n    assert (count_cycle_coloring<MOD>(4, 10).value == 2530);\n\
    \    assert (count_cycle_coloring<MOD>(4, 2).value == 6);\n    assert (count_cycle_coloring<MOD>(1000000000,\
    \ 1000000000).value == 898487047);\n}\n"
  code: "/**\n * @note using Polya enumeration theorem\n * @note factorization + O(d(n)^2\
    \ + sqrt n)\n */\ntemplate <int MOD>\nmint<MOD> count_cycle_coloring(int n, int\
    \ k) {\n    auto primes = list_primes(sqrt(n) + 3);\n    map<ll, int> factors\
    \ = prime_factorize(n, primes);\n    vector<ll> divs = list_divisors(n, primes);\n\
    \    mint<MOD> cnt = 0;\n    for (ll div : divs) {\n        ll e = div;  // Euler's\
    \ phi of div\n        for (auto it : factors) {\n            int p = it.first;\n\
    \            if (div % p == 0) {\n                e = e / p * (p - 1);\n     \
    \       }\n        }\n        cnt += mint<MOD>(k).pow(n / div) * e;\n    }\n \
    \   return cnt / n;\n}\n\nunittest {\n    constexpr int MOD = 1e9 + 7;\n    assert\
    \ (count_cycle_coloring<MOD>(2, 10).value == 55);\n    assert (count_cycle_coloring<MOD>(4,\
    \ 10).value == 2530);\n    assert (count_cycle_coloring<MOD>(4, 2).value == 6);\n\
    \    assert (count_cycle_coloring<MOD>(1000000000, 1000000000).value == 898487047);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: old/polya-enumeration.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/polya-enumeration.inc.cpp
layout: document
redirect_from:
- /library/old/polya-enumeration.inc.cpp
- /library/old/polya-enumeration.inc.cpp.html
title: old/polya-enumeration.inc.cpp
---
