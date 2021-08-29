---
data:
  _extendedDependsOn:
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
  _extendedRequiredBy:
  - icon: ':x:'
    path: modulus/bell_number.hpp
    title: "the Bell number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':x:'
    path: modulus/partition_number.hpp
    title: "the partition number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':x:'
    path: modulus/twelvefold_way.hpp
    title: "twelvefold way / \u5199\u50CF12\u76F8"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_1.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_1.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_10.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_10.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_11.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_11.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_2.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_2.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_3.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_3.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_5.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_5.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_6.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_6.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_7.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_7.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_8.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_8.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_9.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_9.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "the Stirling number of the second kind (\u524D\u51E6\u7406 $O(NK)$\
      \ + $O(1)$)"
    links:
    - http://mathworld.wolfram.com/StirlingNumberoftheSecondKind.html
    - http://oeis.org/A008277
    - https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0
  bundledCode: "#line 2 \"modulus/stirling_number_of_the_second_kind_table.hpp\"\n\
    #include <cassert>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 2 \"\
    modulus/mint.hpp\"\n#include <cstdint>\n#include <iostream>\n#line 4 \"modulus/modpow.hpp\"\
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
    \    assert (y != -1);\n    return y;\n}\n#line 6 \"modulus/mint.hpp\"\n\n/**\n\
    \ * @brief quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$\n */\n\
    template <int32_t MOD>\nstruct mint {\n    int32_t value;\n    mint() : value()\
    \ {}\n    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_\
    \ >= MOD ? value_ % MOD : value_) {}\n    mint(int32_t value_, std::nullptr_t)\
    \ : value(value_) {}\n    explicit operator bool() const { return value; }\n \
    \   inline mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this)\
    \ += other; }\n    inline mint<MOD> operator - (mint<MOD> other) const { return\
    \ mint<MOD>(*this) -= other; }\n    inline mint<MOD> operator * (mint<MOD> other)\
    \ const { return mint<MOD>(*this) *= other; }\n    inline mint<MOD> & operator\
    \ += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value\
    \ -= MOD; return *this; }\n    inline mint<MOD> & operator -= (mint<MOD> other)\
    \ { this->value -= other.value; if (this->value <    0) this->value += MOD; return\
    \ *this; }\n    inline mint<MOD> & operator *= (mint<MOD> other) { this->value\
    \ = (uint_fast64_t)this->value * other.value % MOD; return *this; }\n    inline\
    \ mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value\
    \ : 0, nullptr); }\n    inline bool operator == (mint<MOD> other) const { return\
    \ value == other.value; }\n    inline bool operator != (mint<MOD> other) const\
    \ { return value != other.value; }\n    inline mint<MOD> pow(uint64_t k) const\
    \ { return mint<MOD>(modpow(value, k, MOD), nullptr); }\n    inline mint<MOD>\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 6 \"modulus/stirling_number_of_the_second_kind_table.hpp\"\
    \n\n/**\n * @brief the Stirling number of the second kind (\u524D\u51E6\u7406\
    \ $O(NK)$ + $O(1)$)\n * @description the number of ways of partitioning a set\
    \ of n elements into k nonempty sets\n * @see http://mathworld.wolfram.com/StirlingNumberoftheSecondKind.html\n\
    \ * @see http://oeis.org/A008277\n * @see https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0\n\
    \ */\ntemplate <int MOD>\nmint<MOD> stirling_number_of_the_second_kind_table(int\
    \ n, int k) {\n    assert (0 <= n and 0 <= k);\n    if (n  < k) return 0;\n  \
    \  if (n == k) return 1;\n    if (k == 0) return 0;\n    static std::vector<std::vector<mint<MOD>\
    \ > > memo;\n    if (memo.size() <= n) {\n        int l = memo.size();\n     \
    \   memo.resize(n + 1);\n        REP3 (i, l, n + 1) {\n            memo[i].resize(i);\n\
    \        }\n    }\n    if (memo[n][k]) return memo[n][k];\n    return memo[n][k]\
    \ =\n        stirling_number_of_the_second_kind_table<MOD>(n - 1, k - 1) +\n \
    \       stirling_number_of_the_second_kind_table<MOD>(n - 1, k) * k;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utils/macros.hpp\"\
    \n#include \"../modulus/mint.hpp\"\n\n/**\n * @brief the Stirling number of the\
    \ second kind (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)\n * @description the number\
    \ of ways of partitioning a set of n elements into k nonempty sets\n * @see http://mathworld.wolfram.com/StirlingNumberoftheSecondKind.html\n\
    \ * @see http://oeis.org/A008277\n * @see https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0\n\
    \ */\ntemplate <int MOD>\nmint<MOD> stirling_number_of_the_second_kind_table(int\
    \ n, int k) {\n    assert (0 <= n and 0 <= k);\n    if (n  < k) return 0;\n  \
    \  if (n == k) return 1;\n    if (k == 0) return 0;\n    static std::vector<std::vector<mint<MOD>\
    \ > > memo;\n    if (memo.size() <= n) {\n        int l = memo.size();\n     \
    \   memo.resize(n + 1);\n        REP3 (i, l, n + 1) {\n            memo[i].resize(i);\n\
    \        }\n    }\n    if (memo[n][k]) return memo[n][k];\n    return memo[n][k]\
    \ =\n        stirling_number_of_the_second_kind_table<MOD>(n - 1, k - 1) +\n \
    \       stirling_number_of_the_second_kind_table<MOD>(n - 1, k) * k;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  isVerificationFile: false
  path: modulus/stirling_number_of_the_second_kind_table.hpp
  requiredBy:
  - modulus/bell_number.hpp
  - modulus/partition_number.hpp
  - modulus/twelvefold_way.hpp
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - modulus/twelvefold_way.balls_and_boxes_3.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_2.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_11.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_7.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_10.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_4.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_1.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_8.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_6.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_9.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_5.test.cpp
documentation_of: modulus/stirling_number_of_the_second_kind_table.hpp
layout: document
redirect_from:
- /library/modulus/stirling_number_of_the_second_kind_table.hpp
- /library/modulus/stirling_number_of_the_second_kind_table.hpp.html
title: "the Stirling number of the second kind (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
---
