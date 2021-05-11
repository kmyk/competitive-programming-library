---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulus/bell_number.hpp
    title: "the Bell number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
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
    path: modulus/stirling_number_of_the_second_kind_direct.hpp
    title: the Stirling number of the second kind ($O(K \log N)$)
  - icon: ':heavy_check_mark:'
    path: modulus/stirling_number_of_the_second_kind_table.hpp
    title: "the Stirling number of the second kind (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.hpp
    title: "twelvefold way / \u5199\u50CF12\u76F8"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D
  bundledCode: "#line 1 \"modulus/twelvefold_way.balls_and_boxes_4.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\
    \n#include <iostream>\n#line 2 \"modulus/mint.hpp\"\n#include <cstdint>\n#line\
    \ 2 \"modulus/modpow.hpp\"\n#include <cassert>\n#line 4 \"modulus/modpow.hpp\"\
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
    \ * inv_fact<MOD>(r);\n}\n#line 5 \"modulus/permute.hpp\"\n\n/**\n * @brief permutation\
    \ / \u9806\u5217 ${} _ n P _ r$ (\u524D\u51E6\u7406 $O(n)$ + $O(1)$)\n */\ntemplate\
    \ <int32_t MOD>\nmint<MOD> permute(int n, int r) {\n    assert (0 <= r and r <=\
    \ n);\n    return fact<MOD>(n) * inv_fact<MOD>(n - r);\n}\n#line 5 \"modulus/multichoose.hpp\"\
    \n\n/**\n * @brief \u91CD\u8907\u7D44\u5408\u305B ${} _ n H _ r = {} _ {n + r\
    \ - 1} C _ r$ (\u524D\u51E6\u7406 $O(n)$ + $O(1)$)\n */\ntemplate <int32_t MOD>\n\
    mint<MOD> multichoose(int n, int r) {\n    assert (0 <= n and 0 <= r);\n    if\
    \ (n == 0 and r == 0) return 1;\n    return choose<MOD>(n + r - 1, r);\n}\n#line\
    \ 4 \"modulus/stirling_number_of_the_second_kind_direct.hpp\"\n#include <map>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 9 \"modulus/stirling_number_of_the_second_kind_direct.hpp\"\
    \n\n/**\n * @brief the Stirling number of the second kind ($O(K \\log N)$)\n */\n\
    template <int MOD>\nmint<MOD> stirling_number_of_the_second_kind_direct(int n,\
    \ int k) {\n    assert (0 <= n and 0 <= k);\n    mint<MOD> acc = 0;\n    REP (i,\
    \ k + 1) {\n        int parity = ((k - i) % 2 == 0 ? +1 : -1);\n        acc +=\
    \ choose<MOD>(k, i) * mint<MOD>(i).pow(n) * parity;\n    }\n    return acc * inv_fact<MOD>(k);\n\
    }\n#line 6 \"modulus/stirling_number_of_the_second_kind_table.hpp\"\n\n/**\n *\
    \ @brief the Stirling number of the second kind (\u524D\u51E6\u7406 $O(NK)$ +\
    \ $O(1)$)\n * @description the number of ways of partitioning a set of n elements\
    \ into k nonempty sets\n * @see http://mathworld.wolfram.com/StirlingNumberoftheSecondKind.html\n\
    \ * @see http://oeis.org/A008277\n * @see https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0\n\
    \ */\ntemplate <int MOD>\nmint<MOD> stirling_number_of_the_second_kind_table(int\
    \ n, int k) {\n    assert (0 <= n and 0 <= k);\n    if (n  < k) return 0;\n  \
    \  if (n == k) return 1;\n    if (k == 0) return 0;\n    static std::vector<std::vector<mint<MOD>\
    \ > > memo;\n    if (memo.size() <= n) {\n        int l = memo.size();\n     \
    \   memo.resize(n + 1);\n        REP3 (i, l, n + 1) {\n            memo[i].resize(i);\n\
    \        }\n    }\n    if (memo[n][k]) return memo[n][k];\n    return memo[n][k]\
    \ =\n        stirling_number_of_the_second_kind_table<MOD>(n - 1, k - 1) +\n \
    \       stirling_number_of_the_second_kind_table<MOD>(n - 1, k) * k;\n}\n#line\
    \ 5 \"modulus/bell_number.hpp\"\n\n/**\n * @brief the Bell number (\u524D\u51E6\
    \u7406 $O(NK)$ + $O(1)$)\n * @description the number of ways a set of n elements\
    \ can be partitioned into nonempty subsets\n * @see http://mathworld.wolfram.com/BellNumber.html\n\
    \ * @see https://oeis.org/A110\n * @see https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0\n\
    \ */\ntemplate <int PRIME>\nmint<PRIME> bell_number(int n, int k) {\n    static\
    \ std::vector<std::vector<mint<PRIME> > > memo;\n    if (memo.size() <= n) {\n\
    \        memo.resize(n + 1);\n    }\n    if (memo[n].empty()) {\n        memo[n].push_back(0);\n\
    \    }\n    while (memo[n].size() <= k) {\n        int i = memo[n].size();\n \
    \       memo[n].push_back(memo[n].back() + stirling_number_of_the_second_kind_table<PRIME>(n,\
    \ i));\n    }\n    return memo[n][k];\n}\n\ntemplate <int PRIME>\nmint<PRIME>\
    \ unary_bell_number(int n) {\n    return bell_number<PRIME>(n, n);\n}\n#line 5\
    \ \"modulus/partition_number.hpp\"\n\n/**\n * @brief the partition number (\u524D\
    \u51E6\u7406 $O(NK)$ + $O(1)$)\n * @description the number of non-decreasing sequences\
    \ with the length k which the sum is n\n */\ntemplate <int MOD>\nmint<MOD> partition_number(int\
    \ n, int k) {\n    static std::vector<std::vector<mint<MOD> > > memo;\n    if\
    \ (memo.size() <= n) {\n        memo.resize(n + 1);\n    }\n    while (memo[n].size()\
    \ <= k) {\n        if (n == 0) {\n            memo[0].resize(k + 1, 1);\n    \
    \    } else if (memo[n].empty()) {\n            memo[n].push_back(0);\n      \
    \  } else {\n            int j = memo[n].size();\n            auto a = (n - j\
    \ >= 0 ? partition_number<MOD>(n - j, j) : 0);\n            auto b = (j - 1 >=\
    \ 0 ? partition_number<MOD>(n, j - 1) : 0);\n            memo[n].push_back(a +\
    \ b);\n        }\n    }\n    return memo[n][k];\n}\n\ntemplate <int MOD>\nmint<MOD>\
    \ unary_partition_number(int n) {\n    return partition_number<MOD>(n, n);\n}\n\
    \n#line 9 \"modulus/twelvefold_way.hpp\"\n\n/**\n * @brief twelvefold way / \u5199\
    \u50CF12\u76F8\n * @sa https://en.wikipedia.org/wiki/Twelvefold_way\n * @sa https://mathtrain.jp/twelveway\n\
    \ * @note the numbers of mapprings f putting N balls into K boxes\n */\n\n\n/**\n\
    \ * @brief labeled-N labeled-K any-f\n * @note the number of f for all f : N \\\
    to K\n * @note O(log K)\n */\ntemplate <int MOD>\nmint<MOD> twelvefold_lla(int\
    \ n, int k) {\n    return mint<MOD>(k).pow(n);\n}\n\n/**\n * @brief labeled-N\
    \ labeled-K injective-f\n * @note the number of f for injective f : N \\rightarrowtail\
    \ K\n * @note O(1) with precomputation O(N + K)\n */\ntemplate <int MOD>\nmint<MOD>\
    \ twelvefold_lli(int n, int k) {\n    if (n > k) return 0;\n    return permute<MOD>(k,\
    \ n);\n}\n\n/**\n * @brief labeled-N labeled-K surjective-f\n * @note the number\
    \ of f for surjective f : N \\twoheadrightarrow K\n * @note O(NK) or O(N \\log\
    \ K)\n */\ntemplate <int MOD>\nmint<MOD> twelvefold_lls(int n, int k) {\n    return\
    \ stirling_number_of_the_second_kind_direct<MOD>(n, k) * fact<MOD>(k);\n}\n\n\n\
    /**\n * @brief unlabeled-N labeled-K any-f\n * @note the number of f \\circ S_N\
    \ for any f : N \\to K\n * @note O(1) with precomputation O(N + K)\n */\ntemplate\
    \ <int MOD>\nmint<MOD> twelvefold_ula(int n, int k) {\n    return choose<MOD>(n\
    \ + k - 1, n);\n}\n\n/**\n * @brief unlabeled-N labeled-K injective-f\n * @note\
    \ the number of f \\circ S_N for injective f : N \\rightarrowtail K\n * @note\
    \ O(1) with precomputation O(K)\n */\ntemplate <int MOD>\nmint<MOD> twelvefold_uli(int\
    \ n, int k) {\n    if (n > k) return 0;\n    return choose<MOD>(k, n);\n}\n\n\
    /**\n * @brief unlabeled-N labeled-K surjective-f\n * @note the number of f \\\
    circ S_N for surjective f : N \\twoheadrightarrow K\n * @note O(1) with precomputation\
    \ O(N)\n */\ntemplate <int MOD>\nmint<MOD> twelvefold_uls(int n, int k) {\n  \
    \  if (n < k) return 0;\n    return choose<MOD>(n - 1, n - k);\n}\n\n\n/**\n *\
    \ @brief labeled-N unlabeled-K any-f\n * @note the number of S_K \\circ f for\
    \ all f : N \\to K\n */\ntemplate <int MOD>\nmint<MOD> twelvefold_lua(int n, int\
    \ k) {\n    return bell_number<MOD>(n, k);\n}\n\n/**\n * @brief labeled-N unlabeled-K\
    \ injective-f\n * @note the number of S_K \\circ f for injective f : N \\rightarrowtail\
    \ K\n * @note O(1)\n */\ntemplate <int MOD>\nmint<MOD> twelvefold_lui(int n, int\
    \ k) {\n    if (n > k) return 0;\n    return 1;\n}\n\n/**\n * @brief labeled-N\
    \ unlabeled-K surjective-f\n * @note the number of S_K \\circ f for surjective\
    \ f : N \\twoheadrightarrow K\n * @note O(NK) or O(N \\log K)\n */\ntemplate <int\
    \ MOD>\nmint<MOD> twelvefold_lus(int n, int k) {\n    return stirling_number_of_the_second_kind_direct<MOD>(n,\
    \ k);\n}\n\n\n/**\n * @brief unlabeled-N unlabeled-K any-f\n */\ntemplate <int\
    \ MOD>\nmint<MOD> twelvefold_uua(int n, int k) {\n    return partition_number<MOD>(n,\
    \ k);\n}\n\n\n/**\n * @brief unlabeled-N unlabeled-K injective-f\n * @note the\
    \ number of S_K \\circ f \\circ S_N for injective f : N \\rightarrowtail K\n *\
    \ @note O(1)\n */\ntemplate <int MOD>\nmint<MOD> twelvefold_uui(int n, int k)\
    \ {\n    if (n > k) return 0;\n    return 1;\n}\n#line 4 \"modulus/twelvefold_way.balls_and_boxes_4.test.cpp\"\
    \nusing namespace std;\n\nconstexpr int MOD = 1e9 + 7;\nint main() {\n    int\
    \ n, k; cin >> n >> k;\n    cout << twelvefold_ula<MOD>(n, k) << endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D\"\
    \n#include <iostream>\n#include \"modulus/twelvefold_way.hpp\"\nusing namespace\
    \ std;\n\nconstexpr int MOD = 1e9 + 7;\nint main() {\n    int n, k; cin >> n >>\
    \ k;\n    cout << twelvefold_ula<MOD>(n, k) << endl;\n    return 0;\n}\n"
  dependsOn:
  - modulus/twelvefold_way.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  - modulus/choose.hpp
  - modulus/factorial.hpp
  - modulus/permute.hpp
  - modulus/multichoose.hpp
  - modulus/stirling_number_of_the_second_kind_direct.hpp
  - utils/macros.hpp
  - modulus/bell_number.hpp
  - modulus/stirling_number_of_the_second_kind_table.hpp
  - modulus/partition_number.hpp
  isVerificationFile: true
  path: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
  requiredBy: []
  timestamp: '2020-07-16 00:35:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
layout: document
redirect_from:
- /verify/modulus/twelvefold_way.balls_and_boxes_4.test.cpp
- /verify/modulus/twelvefold_way.balls_and_boxes_4.test.cpp.html
title: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
---
