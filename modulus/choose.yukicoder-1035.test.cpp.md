---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulus/choose.hpp
    title: "combination / \u7D44\u5408\u305B ${} _ n C _ r$ (\u524D\u51E6\u7406 $O(n)$\
      \ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/factorial.hpp
    title: modulus/factorial.hpp
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1035
    links:
    - https://yukicoder.me/problems/no/1035
  bundledCode: "#line 1 \"modulus/choose.yukicoder-1035.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1035\"\n#include <iostream>\n#line 2 \"utils/macros.hpp\"\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 2 \"modulus/factorial.hpp\"\
    \n#include <vector>\n#line 4 \"modulus/factorial.hpp\"\n\ntemplate <int32_t MOD>\n\
    mint<MOD> fact(int n) {\n    static std::vector<mint<MOD> > memo(1, 1);\n    while\
    \ (n >= memo.size()) {\n        memo.push_back(memo.back() * mint<MOD>(memo.size()));\n\
    \    }\n    return memo[n];\n}\ntemplate <int32_t MOD>\nmint<MOD> inv_fact(int\
    \ n) {\n    static std::vector<mint<MOD> > memo;\n    if (memo.size() <= n) {\n\
    \        int l = memo.size();\n        int r = n * 1.3 + 100;\n        memo.resize(r);\n\
    \        memo[r - 1] = fact<MOD>(r - 1).inv();\n        for (int i = r - 2; i\
    \ >= l; -- i) {\n            memo[i] = memo[i + 1] * (i + 1);\n        }\n   \
    \ }\n    return memo[n];\n}\n#line 5 \"modulus/choose.hpp\"\n\n/**\n * @brief\
    \ combination / \u7D44\u5408\u305B ${} _ n C _ r$ (\u524D\u51E6\u7406 $O(n)$ +\
    \ $O(1)$)\n */\ntemplate <int32_t MOD>\nmint<MOD> choose(int n, int r) {\n   \
    \ assert (0 <= r and r <= n);\n    return fact<MOD>(n) * inv_fact<MOD>(n - r)\
    \ * inv_fact<MOD>(r);\n}\n#line 6 \"modulus/choose.yukicoder-1035.test.cpp\"\n\
    using namespace std;\n\nconstexpr int64_t MOD = 1000000007;\nmint<MOD> solve(int\
    \ n, int m) {\n    mint<MOD> ans = 0;\n    REP (i, m + 1) {\n        int sign\
    \ = (i % 2 == 0 ? 1 : -1);\n        ans += sign * choose<MOD>(m, m - i) * mint<MOD>(m\
    \ - i).pow(n);\n    }\n    return ans;\n}\n\nint main() {\n    int N, M; cin >>\
    \ N >> M;\n    cout << solve(N, M) << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1035\"\n#include <iostream>\n\
    #include \"utils/macros.hpp\"\n#include \"modulus/mint.hpp\"\n#include \"modulus/choose.hpp\"\
    \nusing namespace std;\n\nconstexpr int64_t MOD = 1000000007;\nmint<MOD> solve(int\
    \ n, int m) {\n    mint<MOD> ans = 0;\n    REP (i, m + 1) {\n        int sign\
    \ = (i % 2 == 0 ? 1 : -1);\n        ans += sign * choose<MOD>(m, m - i) * mint<MOD>(m\
    \ - i).pow(n);\n    }\n    return ans;\n}\n\nint main() {\n    int N, M; cin >>\
    \ N >> M;\n    cout << solve(N, M) << endl;\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  - modulus/choose.hpp
  - modulus/factorial.hpp
  isVerificationFile: true
  path: modulus/choose.yukicoder-1035.test.cpp
  requiredBy: []
  timestamp: '2020-07-16 00:35:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: modulus/choose.yukicoder-1035.test.cpp
layout: document
redirect_from:
- /verify/modulus/choose.yukicoder-1035.test.cpp
- /verify/modulus/choose.yukicoder-1035.test.cpp.html
title: modulus/choose.yukicoder-1035.test.cpp
---
