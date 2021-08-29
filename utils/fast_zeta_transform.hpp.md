---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number/primes.hpp
    title: number/primes.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: upward fast zeta transform on primes
    links: []
  bundledCode: "#line 2 \"utils/fast_zeta_transform.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n#line 2 \"number/primes.hpp\"\n#include <algorithm>\n#line 4 \"number/primes.hpp\"\
    \n#include <cstdint>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int\
    \ i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i)\
    \ < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 7 \"number/primes.hpp\"\
    \n\nstruct prepared_primes {\n    int size;\n    std::vector<int> sieve;\n   \
    \ std::vector<int> primes;\n\n    /**\n     * @note O(size)\n     */\n    prepared_primes(int\
    \ size_)\n        : size(size_) {\n\n        sieve.resize(size);\n        REP3\
    \ (p, 2, size) if (sieve[p] == 0) {\n            primes.push_back(p);\n      \
    \      for (int k = p; k < size; k += p) {\n                if (sieve[k] == 0)\
    \ {\n                    sieve[k] = p;\n                }\n            }\n   \
    \     }\n    }\n\n    /**\n     * @note let k be the length of the result, O(k)\
    \ if n < size; O(\\sqrt{n} + k) if size <= n < size^2\n     */\n    std::vector<int64_t>\
    \ list_prime_factors(int64_t n) const {\n        assert (1 <= n and n < (int64_t)size\
    \ * size);\n        std::vector<int64_t> result;\n\n        // trial division\
    \ for large part\n        for (int p : primes) {\n            if (n < size or\
    \ n < (int64_t)p * p) {\n                break;\n            }\n            while\
    \ (n % p == 0) {\n                n /= p;\n                result.push_back(p);\n\
    \            }\n        }\n\n        // small part\n        if (n == 1) {\n  \
    \          // nop\n        } else if (n < size) {\n            while (n != 1)\
    \ {\n                result.push_back(sieve[n]);\n                n /= sieve[n];\n\
    \            }\n        } else {\n            result.push_back(n);\n        }\n\
    \n        assert (std::is_sorted(ALL(result)));\n        return result;\n    }\n\
    \n    std::vector<int64_t> list_all_factors(int64_t n) const {\n        auto p\
    \ = list_prime_factors(n);\n        std::vector<int64_t> d;\n        d.push_back(1);\n\
    \        for (int l = 0; l < p.size(); ) {\n            int r = l + 1;\n     \
    \       while (r < p.size() and p[r] == p[l]) ++ r;\n            int n = d.size();\n\
    \            REP (k1, r - l) {\n                REP (k2, n) {\n              \
    \      d.push_back(d[d.size() - n] * p[l]);\n                }\n            }\n\
    \            l = r;\n        }\n        return d;\n    }\n\n    /**\n     * @note\
    \ O(1) if n < size; O(sqrt n) if size <= n < size^2\n     */\n    bool is_prime(int64_t\
    \ n) const {\n        assert (1 <= n and n < (int64_t)size * size);\n        if\
    \ (n < size) {\n            return sieve[n] == n;\n        }\n        for (int\
    \ p : primes) {\n            if (n < (int64_t)p * p) {\n                break;\n\
    \            }\n            if (n % p == 0) {\n                return false;\n\
    \            }\n        }\n        return true;\n    }\n};\n#line 6 \"utils/fast_zeta_transform.hpp\"\
    \n\n/**\n * @brief upward fast zeta transform on primes\n * @note $O(n \\log n)$\
    \ (or, $O(n \\log \\log n)$ ???)\n * @return $b_i = \\sum _ {i \\mid j} a_j$\n\
    \ * @note $a_0, b_0$ means the greatest element\n */\ntemplate <class CommutativeSemiring>\n\
    std::vector<typename CommutativeSemiring::value_type> upward_fast_zeta_transform_on_primes(std::vector<typename\
    \ CommutativeSemiring::value_type> a, const prepared_primes & primes, const CommutativeSemiring\
    \ & mon = CommutativeSemiring()) {\n    assert (a.size() <= primes.size);\n  \
    \  if (a.empty()) return a;\n    for (int64_t p : primes.primes) {\n        REP3R\
    \ (x, 1, (a.size() - 1) / p + 1) {\n            a[x] = mon.mult(a[x], a[p * x]);\n\
    \        }\n    }\n    REP3 (x, 1, a.size()) {\n        a[x] = mon.mult(a[x],\
    \ a[0]);\n    }\n    return a;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../number/primes.hpp\"\
    \n#include \"../utils/macros.hpp\"\n\n/**\n * @brief upward fast zeta transform\
    \ on primes\n * @note $O(n \\log n)$ (or, $O(n \\log \\log n)$ ???)\n * @return\
    \ $b_i = \\sum _ {i \\mid j} a_j$\n * @note $a_0, b_0$ means the greatest element\n\
    \ */\ntemplate <class CommutativeSemiring>\nstd::vector<typename CommutativeSemiring::value_type>\
    \ upward_fast_zeta_transform_on_primes(std::vector<typename CommutativeSemiring::value_type>\
    \ a, const prepared_primes & primes, const CommutativeSemiring & mon = CommutativeSemiring())\
    \ {\n    assert (a.size() <= primes.size);\n    if (a.empty()) return a;\n   \
    \ for (int64_t p : primes.primes) {\n        REP3R (x, 1, (a.size() - 1) / p +\
    \ 1) {\n            a[x] = mon.mult(a[x], a[p * x]);\n        }\n    }\n    REP3\
    \ (x, 1, a.size()) {\n        a[x] = mon.mult(a[x], a[0]);\n    }\n    return\
    \ a;\n}\n"
  dependsOn:
  - number/primes.hpp
  - utils/macros.hpp
  isVerificationFile: false
  path: utils/fast_zeta_transform.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/fast_zeta_transform.hpp
layout: document
redirect_from:
- /library/utils/fast_zeta_transform.hpp
- /library/utils/fast_zeta_transform.hpp.html
title: upward fast zeta transform on primes
---
