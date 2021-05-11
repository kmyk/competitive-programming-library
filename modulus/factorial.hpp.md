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
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: modulus/bell_number.hpp
    title: "the Bell number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/choose.hpp
    title: "combination / \u7D44\u5408\u305B ${} _ n C _ r$ (\u524D\u51E6\u7406 $O(n)$\
      \ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/multichoose.hpp
    title: "\u91CD\u8907\u7D44\u5408\u305B ${} _ n H _ r = {} _ {n + r - 1} C _ r$\
      \ (\u524D\u51E6\u7406 $O(n)$ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/partition_number.hpp
    title: "the partition number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/permute.hpp
    title: "permutation / \u9806\u5217 ${} _ n P _ r$ (\u524D\u51E6\u7406 $O(n)$ +\
      \ $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/stirling_number_of_the_second_kind_convolution.hpp
    title: the Stirling number of the second kind (for given $N$, compute $S(N, \ast)$
      in $O(N \log N)$)
  - icon: ':heavy_check_mark:'
    path: modulus/stirling_number_of_the_second_kind_direct.hpp
    title: the Stirling number of the second kind ($O(K \log N)$)
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.hpp
    title: "twelvefold way / \u5199\u50CF12\u76F8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: modulus/choose.yukicoder-1035.test.cpp
    title: modulus/choose.yukicoder-1035.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp
    title: modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_1.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_10.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_10.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_11.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_11.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_2.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_3.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_5.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_5.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_6.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_6.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_7.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_7.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_8.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_8.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_9.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_9.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulus/factorial.hpp\"\n#include <vector>\n#line 2 \"modulus/mint.hpp\"\
    \n#include <cstdint>\n#include <iostream>\n#line 2 \"modulus/modpow.hpp\"\n#include\
    \ <cassert>\n#line 4 \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 4 \"modulus/factorial.hpp\"\
    \n\ntemplate <int32_t MOD>\nmint<MOD> fact(int n) {\n    static std::vector<mint<MOD>\
    \ > memo(1, 1);\n    while (n >= memo.size()) {\n        memo.push_back(memo.back()\
    \ * mint<MOD>(memo.size()));\n    }\n    return memo[n];\n}\ntemplate <int32_t\
    \ MOD>\nmint<MOD> inv_fact(int n) {\n    static std::vector<mint<MOD> > memo;\n\
    \    if (memo.size() <= n) {\n        int l = memo.size();\n        int r = n\
    \ * 1.3 + 100;\n        memo.resize(r);\n        memo[r - 1] = fact<MOD>(r - 1).inv();\n\
    \        for (int i = r - 2; i >= l; -- i) {\n            memo[i] = memo[i + 1]\
    \ * (i + 1);\n        }\n    }\n    return memo[n];\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"modulus/mint.hpp\"\n\ntemplate\
    \ <int32_t MOD>\nmint<MOD> fact(int n) {\n    static std::vector<mint<MOD> > memo(1,\
    \ 1);\n    while (n >= memo.size()) {\n        memo.push_back(memo.back() * mint<MOD>(memo.size()));\n\
    \    }\n    return memo[n];\n}\ntemplate <int32_t MOD>\nmint<MOD> inv_fact(int\
    \ n) {\n    static std::vector<mint<MOD> > memo;\n    if (memo.size() <= n) {\n\
    \        int l = memo.size();\n        int r = n * 1.3 + 100;\n        memo.resize(r);\n\
    \        memo[r - 1] = fact<MOD>(r - 1).inv();\n        for (int i = r - 2; i\
    \ >= l; -- i) {\n            memo[i] = memo[i + 1] * (i + 1);\n        }\n   \
    \ }\n    return memo[n];\n}\n"
  dependsOn:
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  isVerificationFile: false
  path: modulus/factorial.hpp
  requiredBy:
  - modulus/stirling_number_of_the_second_kind_direct.hpp
  - modulus/permute.hpp
  - modulus/twelvefold_way.hpp
  - modulus/multichoose.hpp
  - modulus/bell_number.hpp
  - modulus/choose.hpp
  - modulus/partition_number.hpp
  - modulus/stirling_number_of_the_second_kind_convolution.hpp
  timestamp: '2020-07-16 00:35:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - modulus/twelvefold_way.balls_and_boxes_2.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_10.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_4.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_1.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_7.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_5.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_3.test.cpp
  - modulus/choose.yukicoder-1035.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_6.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_11.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_8.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_9.test.cpp
  - modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp
documentation_of: modulus/factorial.hpp
layout: document
redirect_from:
- /library/modulus/factorial.hpp
- /library/modulus/factorial.hpp.html
title: modulus/factorial.hpp
---
