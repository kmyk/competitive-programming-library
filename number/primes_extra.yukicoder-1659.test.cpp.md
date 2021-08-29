---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: modulus/choose_simple.hpp
    title: "combination / \u7D44\u5408\u305B ${} _ n C _ r$ (\u611A\u76F4 $O(r)$)"
  - icon: ':question:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':question:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':question:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  - icon: ':x:'
    path: modulus/multichoose_simple.hpp
    title: "\u91CD\u8907\u7D44\u5408\u305B ${} _ n H _ r = {} _ {n + r - 1} C _ r$\
      \ (\u611A\u76F4 $O(r)$)"
  - icon: ':x:'
    path: number/primes.hpp
    title: number/primes.hpp
  - icon: ':x:'
    path: number/primes_extra.hpp
    title: number/primes_extra.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1659
    links:
    - https://github.com/online-judge-tools/template-generator)
    - https://yukicoder.me/problems/no/1659
  bundledCode: "#line 1 \"number/primes_extra.yukicoder-1659.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1659\"\n#include <iostream>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 2 \"modulus/mint.hpp\"\n#include <cstdint>\n#line 2 \"modulus/modpow.hpp\"\n\
    #include <cassert>\n#line 4 \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 5 \"number/primes.hpp\"\
    \n#include <vector>\n#line 7 \"number/primes.hpp\"\n\nstruct prepared_primes {\n\
    \    int size;\n    std::vector<int> sieve;\n    std::vector<int> primes;\n\n\
    \    /**\n     * @note O(size)\n     */\n    prepared_primes(int size_)\n    \
    \    : size(size_) {\n\n        sieve.resize(size);\n        REP3 (p, 2, size)\
    \ if (sieve[p] == 0) {\n            primes.push_back(p);\n            for (int\
    \ k = p; k < size; k += p) {\n                if (sieve[k] == 0) {\n         \
    \           sieve[k] = p;\n                }\n            }\n        }\n    }\n\
    \n    /**\n     * @note let k be the length of the result, O(k) if n < size; O(\\\
    sqrt{n} + k) if size <= n < size^2\n     */\n    std::vector<int64_t> list_prime_factors(int64_t\
    \ n) const {\n        assert (1 <= n and n < (int64_t)size * size);\n        std::vector<int64_t>\
    \ result;\n\n        // trial division for large part\n        for (int p : primes)\
    \ {\n            if (n < size or n < (int64_t)p * p) {\n                break;\n\
    \            }\n            while (n % p == 0) {\n                n /= p;\n  \
    \              result.push_back(p);\n            }\n        }\n\n        // small\
    \ part\n        if (n == 1) {\n            // nop\n        } else if (n < size)\
    \ {\n            while (n != 1) {\n                result.push_back(sieve[n]);\n\
    \                n /= sieve[n];\n            }\n        } else {\n           \
    \ result.push_back(n);\n        }\n\n        assert (std::is_sorted(ALL(result)));\n\
    \        return result;\n    }\n\n    std::vector<int64_t> list_all_factors(int64_t\
    \ n) const {\n        auto p = list_prime_factors(n);\n        std::vector<int64_t>\
    \ d;\n        d.push_back(1);\n        for (int l = 0; l < p.size(); ) {\n   \
    \         int r = l + 1;\n            while (r < p.size() and p[r] == p[l]) ++\
    \ r;\n            int n = d.size();\n            REP (k1, r - l) {\n         \
    \       REP (k2, n) {\n                    d.push_back(d[d.size() - n] * p[l]);\n\
    \                }\n            }\n            l = r;\n        }\n        return\
    \ d;\n    }\n\n    /**\n     * @note O(1) if n < size; O(sqrt n) if size <= n\
    \ < size^2\n     */\n    bool is_prime(int64_t n) const {\n        assert (1 <=\
    \ n and n < (int64_t)size * size);\n        if (n < size) {\n            return\
    \ sieve[n] == n;\n        }\n        for (int p : primes) {\n            if (n\
    \ < (int64_t)p * p) {\n                break;\n            }\n            if (n\
    \ % p == 0) {\n                return false;\n            }\n        }\n     \
    \   return true;\n    }\n};\n#line 3 \"number/primes_extra.hpp\"\n#include <map>\n\
    #line 7 \"number/primes_extra.hpp\"\n\nstd::map<int64_t, int> list_prime_factors_as_map(const\
    \ prepared_primes& primes, int64_t n) {\n    std::map<int64_t, int> cnt;\n   \
    \ for (int64_t p : primes.list_prime_factors(n)) {\n        ++ cnt[p];\n    }\n\
    \    return cnt;\n}\n\nint64_t euler_totient(const prepared_primes& primes, int64_t\
    \ n) {\n    int64_t phi = 1;\n    int64_t last = -1;\n    for (int64_t p : primes.list_prime_factors(n))\
    \ {\n        if (last != p) {\n            last = p;\n            phi *= p - 1;\n\
    \        } else {\n            phi *= p;\n        }\n    }\n    return phi;\n\
    }\n#line 5 \"modulus/choose_simple.hpp\"\n\n/**\n * @brief combination / \u7D44\
    \u5408\u305B ${} _ n C _ r$ (\u611A\u76F4 $O(r)$)\n */\ntemplate <int32_t MOD>\n\
    mint<MOD> choose_simple(int64_t n, int32_t r) {\n    assert (0 <= r and r <= n);\n\
    \    mint<MOD> num = 1;\n    mint<MOD> den = 1;\n    REP (i, r) {\n        num\
    \ *= n - i;\n        den *= i + 1;\n    }\n    return num / den;\n}\n#line 5 \"\
    modulus/multichoose_simple.hpp\"\n\n/**\n * @brief \u91CD\u8907\u7D44\u5408\u305B\
    \ ${} _ n H _ r = {} _ {n + r - 1} C _ r$ (\u611A\u76F4 $O(r)$)\n */\ntemplate\
    \ <int32_t MOD>\nmint<MOD> multichoose_simple(int64_t n, int32_t r) {\n    assert\
    \ (0 <= n and 0 <= r);\n    if (n == 0 and r == 0) return 1;\n    return choose_simple<MOD>(n\
    \ + r - 1, r);\n}\n#line 8 \"number/primes_extra.yukicoder-1659.test.cpp\"\nusing\
    \ namespace std;\n\nprepared_primes primes(1e6 + 100);\n\nconstexpr int64_t MOD\
    \ = 1000000007;\nmint<MOD> solve(int64_t n, int64_t k) {\n    mint<MOD> ans =\
    \ 1;\n    for (auto [p, e] : list_prime_factors_as_map(primes, n)) {\n       \
    \ // ans *= multichoose_simple<MOD>(k, e);\n        mint<MOD> y = 0;\n       \
    \ REP (x, e + 1) {\n            y += multichoose_simple<MOD>(k, x);\n        }\n\
    \        ans *= y;\n    }\n    return ans;\n}\n\n// generated by oj-template v4.8.0\
    \ (https://github.com/online-judge-tools/template-generator)\nint main() {\n \
    \   std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int64_t\
    \ N, K;\n    std::cin >> N >> K;\n    auto ans = solve(N, K);\n    std::cout <<\
    \ ans << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1659\"\n#include <iostream>\n\
    #include \"../utils/macros.hpp\"\n#include \"../modulus/mint.hpp\"\n#include \"\
    ../number/primes.hpp\"\n#include \"../number/primes_extra.hpp\"\n#include \"../modulus/multichoose_simple.hpp\"\
    \nusing namespace std;\n\nprepared_primes primes(1e6 + 100);\n\nconstexpr int64_t\
    \ MOD = 1000000007;\nmint<MOD> solve(int64_t n, int64_t k) {\n    mint<MOD> ans\
    \ = 1;\n    for (auto [p, e] : list_prime_factors_as_map(primes, n)) {\n     \
    \   // ans *= multichoose_simple<MOD>(k, e);\n        mint<MOD> y = 0;\n     \
    \   REP (x, e + 1) {\n            y += multichoose_simple<MOD>(k, x);\n      \
    \  }\n        ans *= y;\n    }\n    return ans;\n}\n\n// generated by oj-template\
    \ v4.8.0 (https://github.com/online-judge-tools/template-generator)\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int64_t\
    \ N, K;\n    std::cin >> N >> K;\n    auto ans = solve(N, K);\n    std::cout <<\
    \ ans << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  - number/primes.hpp
  - number/primes_extra.hpp
  - modulus/multichoose_simple.hpp
  - modulus/choose_simple.hpp
  isVerificationFile: true
  path: number/primes_extra.yukicoder-1659.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: number/primes_extra.yukicoder-1659.test.cpp
layout: document
redirect_from:
- /verify/number/primes_extra.yukicoder-1659.test.cpp
- /verify/number/primes_extra.yukicoder-1659.test.cpp.html
title: number/primes_extra.yukicoder-1659.test.cpp
---
