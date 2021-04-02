---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: enumerate primes in [2, n) with O(n log log n)
    links: []
  bundledCode: "#line 1 \"old/primes-small.inc.cpp\"\n/**\n * @brief enumerate primes\
    \ in [2, n) with O(n log log n)\n */\nvector<int> list_primes(int n) {\n    vector<bool>\
    \ is_prime(n, true);\n    is_prime[0] = is_prime[1] = false;\n    for (int i =\
    \ 2; i *(int64_t) i < n; ++ i)\n        if (is_prime[i])\n            for (int\
    \ k = 2 * i; k < n; k += i)\n                is_prime[k] = false;\n    vector<int>\
    \ primes;\n    for (int i = 2; i < n; ++ i)\n        if (is_prime[i])\n      \
    \      primes.push_back(i);\n    return primes;\n}\n\n/**\n * @note O(sqrt n)\n\
    \ */\nbool is_prime(int64_t n, vector<int> const & primes) {\n    if (n == 1)\
    \ return false;\n    for (int p : primes) {\n        if (n < (int64_t)p * p) break;\n\
    \        if (n % p == 0) return true;\n    }\n    return false;\n}\n\n/**\n *\
    \ @note the last number of primes must be >= sqrt n\n */\nmap<int64_t, int> prime_factorize(int64_t\
    \ n, vector<int> const & primes) {\n    map<int64_t, int> result;\n    for (int\
    \ p : primes) {\n        if (n < p *(int64_t) p) break;\n        while (n % p\
    \ == 0) {\n            result[p] += 1;\n            n /= p;\n        }\n    }\n\
    \    if (n != 1) result[n] += 1;\n    return result;\n}\n\n/**\n * @note if n\
    \ < 10^9, d(n) < 1200 + a\n */\nvector<int64_t> list_divisors_from_prime_factors(int64_t\
    \ n, vector<int64_t> const & prime_factors) {\n    vector<int64_t> result;\n \
    \   result.push_back(1);\n    for (auto it : prime_factors) {\n        int64_t\
    \ p; int k; tie(p, k) = it;\n        int size = result.size();\n        REP (y,\
    \ k) {\n            REP (x, size) {\n                result.push_back(result[y\
    \ * size + x] * p);\n            }\n        }\n    }\n    return result;\n}\n\n\
    /**\n * @brief fully factorize all numbers in [0, n) with O(n log log n)\n */\n\
    vector<vector<int> > extended_sieve_of_eratosthenes(int n) {\n    vector<vector<int>\
    \ > prime_factors(n + 1);\n    REP3 (i, 2, n) {\n        if (prime_factors[i].empty())\
    \ {\n            for (int k = i; k < n; k += i) {\n                prime_factors[k].push_back(i);\n\
    \            }\n        }\n    }\n    return prime_factors;\n}\n\n/**\n * @note\
    \ O(sqrt(n))\n */\nmap<int64_t, int> prime_factorize1(int64_t n) {\n    map<int64_t,\
    \ int> factors;\n    for (int p : { 2, 3, 5 }) {\n        while (n % p == 0) {\n\
    \            n /= p;\n            ++ factors[p];\n        }\n    }\n    for (int\
    \ p = 6; (int64_t)p * p <= n; p += 6) {\n        for (int q : { p + 1, p + 5 })\
    \ {\n            while (n % q == 0) {\n                n /= q;\n             \
    \   ++ factors[q];\n            }\n        }\n    }\n    if (n) {\n        ++\
    \ factors[n];\n    }\n    return factors;\n}\n"
  code: "/**\n * @brief enumerate primes in [2, n) with O(n log log n)\n */\nvector<int>\
    \ list_primes(int n) {\n    vector<bool> is_prime(n, true);\n    is_prime[0] =\
    \ is_prime[1] = false;\n    for (int i = 2; i *(int64_t) i < n; ++ i)\n      \
    \  if (is_prime[i])\n            for (int k = 2 * i; k < n; k += i)\n        \
    \        is_prime[k] = false;\n    vector<int> primes;\n    for (int i = 2; i\
    \ < n; ++ i)\n        if (is_prime[i])\n            primes.push_back(i);\n   \
    \ return primes;\n}\n\n/**\n * @note O(sqrt n)\n */\nbool is_prime(int64_t n,\
    \ vector<int> const & primes) {\n    if (n == 1) return false;\n    for (int p\
    \ : primes) {\n        if (n < (int64_t)p * p) break;\n        if (n % p == 0)\
    \ return true;\n    }\n    return false;\n}\n\n/**\n * @note the last number of\
    \ primes must be >= sqrt n\n */\nmap<int64_t, int> prime_factorize(int64_t n,\
    \ vector<int> const & primes) {\n    map<int64_t, int> result;\n    for (int p\
    \ : primes) {\n        if (n < p *(int64_t) p) break;\n        while (n % p ==\
    \ 0) {\n            result[p] += 1;\n            n /= p;\n        }\n    }\n \
    \   if (n != 1) result[n] += 1;\n    return result;\n}\n\n/**\n * @note if n <\
    \ 10^9, d(n) < 1200 + a\n */\nvector<int64_t> list_divisors_from_prime_factors(int64_t\
    \ n, vector<int64_t> const & prime_factors) {\n    vector<int64_t> result;\n \
    \   result.push_back(1);\n    for (auto it : prime_factors) {\n        int64_t\
    \ p; int k; tie(p, k) = it;\n        int size = result.size();\n        REP (y,\
    \ k) {\n            REP (x, size) {\n                result.push_back(result[y\
    \ * size + x] * p);\n            }\n        }\n    }\n    return result;\n}\n\n\
    /**\n * @brief fully factorize all numbers in [0, n) with O(n log log n)\n */\n\
    vector<vector<int> > extended_sieve_of_eratosthenes(int n) {\n    vector<vector<int>\
    \ > prime_factors(n + 1);\n    REP3 (i, 2, n) {\n        if (prime_factors[i].empty())\
    \ {\n            for (int k = i; k < n; k += i) {\n                prime_factors[k].push_back(i);\n\
    \            }\n        }\n    }\n    return prime_factors;\n}\n\n/**\n * @note\
    \ O(sqrt(n))\n */\nmap<int64_t, int> prime_factorize1(int64_t n) {\n    map<int64_t,\
    \ int> factors;\n    for (int p : { 2, 3, 5 }) {\n        while (n % p == 0) {\n\
    \            n /= p;\n            ++ factors[p];\n        }\n    }\n    for (int\
    \ p = 6; (int64_t)p * p <= n; p += 6) {\n        for (int q : { p + 1, p + 5 })\
    \ {\n            while (n % q == 0) {\n                n /= q;\n             \
    \   ++ factors[q];\n            }\n        }\n    }\n    if (n) {\n        ++\
    \ factors[n];\n    }\n    return factors;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/primes-small.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/primes-small.inc.cpp
layout: document
redirect_from:
- /library/old/primes-small.inc.cpp
- /library/old/primes-small.inc.cpp.html
title: enumerate primes in [2, n) with O(n log log n)
---
