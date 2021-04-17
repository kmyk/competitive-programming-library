---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: hack/fastio.hpp
    title: hack/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':heavy_check_mark:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/number_theoretic_transformation.hpp
    title: Number Theoretic Transformation (NTT) for Proth primes
  - icon: ':heavy_check_mark:'
    path: modulus/number_theoretic_transformation_with_garner.hpp
    title: multiprecation on $\mathbb{Z}/n\mathbb{Z}[x]$
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 2 \"modulus/number_theoretic_transformation_with_garner.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n#include <tuple>\n\
    #include <vector>\n#line 3 \"modulus/mint.hpp\"\n#include <iostream>\n#line 4\
    \ \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t x, uint64_t k,\
    \ int32_t MOD) {\n    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n    uint_fast64_t\
    \ y = 1;\n    for (; k; k >>= 1) {\n        if (k & 1) (y *= x) %= MOD;\n    \
    \    (x *= x) %= MOD;\n    }\n    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);\n\
    \    return y;\n}\n#line 5 \"modulus/modinv.hpp\"\n\ninline int32_t modinv_nocheck(int32_t\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 9 \"modulus/number_theoretic_transformation.hpp\"\n\ntemplate <int32_t PRIME>\
    \ struct proth_prime {};\ntemplate <> struct proth_prime<1224736769> { static\
    \ constexpr int a =             73, b = 24, g =  3; };\ntemplate <> struct proth_prime<1053818881>\
    \ { static constexpr int a =     3 * 5 * 67, b = 20, g =  7; };\ntemplate <> struct\
    \ proth_prime<1051721729> { static constexpr int a =        17 * 59, b = 20, g\
    \ =  6; };\ntemplate <> struct proth_prime<1045430273> { static constexpr int\
    \ a =            997, b = 20, g =  3; };\ntemplate <> struct proth_prime<1012924417>\
    \ { static constexpr int a =     3 * 7 * 23, b = 21, g =  5; };\ntemplate <> struct\
    \ proth_prime<1007681537> { static constexpr int a =        31 * 31, b = 20, g\
    \ =  3; };\ntemplate <> struct proth_prime<1004535809> { static constexpr int\
    \ a =            479, b = 21, g =  3; };\ntemplate <> struct proth_prime< 998244353>\
    \ { static constexpr int a =         7 * 17, b = 23, g =  3; };\ntemplate <> struct\
    \ proth_prime< 985661441> { static constexpr int a =         5 * 47, b = 22, g\
    \ =  3; };\ntemplate <> struct proth_prime< 976224257> { static constexpr int\
    \ a =     7 * 7 * 19, b = 20, g =  3; };\ntemplate <> struct proth_prime< 975175681>\
    \ { static constexpr int a =     3 * 5 * 31, b = 21, g = 17; };\ntemplate <> struct\
    \ proth_prime< 962592769> { static constexpr int a = 3 * 3 * 3 * 17, b = 21, g\
    \ =  7; };\ntemplate <> struct proth_prime< 950009857> { static constexpr int\
    \ a =        4 * 151, b = 21, g =  7; };\ntemplate <> struct proth_prime< 943718401>\
    \ { static constexpr int a =  3 * 3 * 5 * 5, b = 22, g =  7; };\ntemplate <> struct\
    \ proth_prime< 935329793> { static constexpr int a =            223, b = 22, g\
    \ =  3; };\ntemplate <> struct proth_prime< 924844033> { static constexpr int\
    \ a =  3 * 3 * 7 * 7, b = 21, g =  5; };\ntemplate <> struct proth_prime< 469762049>\
    \ { static constexpr int a =              7, b = 26, g =  3; };\ntemplate <> struct\
    \ proth_prime< 167772161> { static constexpr int a =              5, b = 25, g\
    \ =  3; };\n\nstruct is_proth_prime_impl {\n    template <int32_t PRIME, class\
    \ T> static auto check(T *) -> decltype(proth_prime<PRIME>::g, std::true_type());\n\
    \    template <int32_t PRIME, class T> static auto check(...) -> std::false_type;\n\
    };\ntemplate <int32_t PRIME>\nstruct is_proth_prime : decltype(is_proth_prime_impl::check<PRIME,\
    \ std::nullptr_t>(nullptr)) {\n};\n\n/**\n * @brief Number Theoretic Transformation\
    \ (NTT) for Proth primes\n * @note O(N log N)\n * @note radix-2, decimation-in-frequency,\
    \ Cooley-Tukey\n * @note cache std::polar (~ 2x faster)\n */\ntemplate <int32_t\
    \ PRIME>\nvoid ntt_inplace(std::vector<mint<PRIME> > & a, bool inverse) {\n  \
    \  const int n = a.size();\n    const int log2_n = __builtin_ctz(n);\n    assert\
    \ (n == 1 << log2_n);\n    assert (log2_n <= proth_prime<PRIME>::b);\n\n    //\
    \ prepare rotors\n    std::vector<mint<PRIME> > ep, iep;\n    while ((int)ep.size()\
    \ <= log2_n) {\n        ep.push_back(mint<PRIME>(proth_prime<PRIME>::g).pow(mint<PRIME>(-1).value\
    \ / (1 << ep.size())));\n        iep.push_back(ep.back().inv());\n    }\n\n  \
    \  // divide and conquer\n    std::vector<mint<PRIME> > b(n);\n    REP3 (i, 1,\
    \ log2_n + 1) {\n        int w = 1 << (log2_n - i);\n        mint<PRIME> base\
    \ = (inverse ? iep : ep)[i];\n        mint<PRIME> now = 1;\n        for (int y\
    \ = 0; y < n / 2; y += w) {\n            REP (x, w) {\n                auto l\
    \ = a[y << 1 | x];\n                auto r = now * a[y << 1 | x | w];\n      \
    \          b[y | x] = l + r;\n                b[y | x | n >> 1] = l - r;\n   \
    \         }\n            now *= base;\n        }\n        std::swap(a, b);\n \
    \   }\n\n    // div by n if inverse\n    if (inverse) {\n        auto n_inv =\
    \ mint<PRIME>(n).inv();\n        REP (i, n) {\n            a[i] *= n_inv;\n  \
    \      }\n    }\n}\n\n/**\n * @brief multiprecation on $\\mathbb{F}_p[x]$ for\
    \ Proth primes\n * @note O(N log N)\n * @note (f \\ast g)(i) = \\sum_{0 \\le j\
    \ \\lt i + 1} f(j) g(i - j)\n */\ntemplate <int32_t PRIME>\ntypename std::enable_if<is_proth_prime<PRIME>::value,\
    \ std::vector<mint<PRIME> > >::type ntt_convolution(const std::vector<mint<PRIME>\
    \ > & a_, const std::vector<mint<PRIME> > & b_) {\n    if (a_.size() <= 32 or\
    \ b_.size() <= 32) {\n        std::vector<mint<PRIME> > c(a_.size() + b_.size()\
    \ - 1);\n        REP (i, a_.size()) REP (j, b_.size()) c[i + j] += a_[i] * b_[j];\n\
    \        return c;\n    }\n    int m = a_.size() + b_.size() - 1;\n    int n =\
    \ (m == 1 ? 1 : 1 << (32 - __builtin_clz(m - 1)));\n    auto a = a_;\n    auto\
    \ b = b_;\n    a.resize(n);\n    b.resize(n);\n    ntt_inplace(a, false);\n  \
    \  ntt_inplace(b, false);\n    REP (i, n) {\n        a[i] *= b[i];\n    }\n  \
    \  ntt_inplace(a, true);\n    a.resize(m);\n    return a;\n}\n#line 10 \"modulus/number_theoretic_transformation_with_garner.hpp\"\
    \n\ntemplate <int32_t MOD, int32_t MOD1, int32_t MOD2, int32_t MOD3>\nmint<MOD>\
    \ garner_algorithm_template(mint<MOD1> a1, mint<MOD2> a2, mint<MOD3> a3) {\n \
    \   static const auto r12 = mint<MOD2>(MOD1).inv();\n    static const auto r13\
    \ = mint<MOD3>(MOD1).inv();\n    static const auto r23 = mint<MOD3>(MOD2).inv();\n\
    \    a2 = (a2 - a1.value) * r12;\n    a3 = (a3 - a1.value) * r13;\n    a3 = (a3\
    \ - a2.value) * r23;\n    return mint<MOD>(a1.value) + a2.value * mint<MOD>(MOD1)\
    \ + a3.value * (mint<MOD>(MOD1) * mint<MOD>(MOD2));\n}\n\n/**\n * @brief multiprecation\
    \ on $\\mathbb{Z}/n\\mathbb{Z}[x]$\n */\ntemplate <int32_t MOD>\ntypename std::enable_if<not\
    \ is_proth_prime<MOD>::value, std::vector<mint<MOD> > >::type ntt_convolution(const\
    \ std::vector<mint<MOD> > & a, const std::vector<mint<MOD> > & b) {\n    if (a.size()\
    \ <= 32 or b.size() <= 32) {\n        std::vector<mint<MOD> > c(a.size() + b.size()\
    \ - 1);\n        REP (i, a.size()) REP (j, b.size()) c[i + j] += a[i] * b[j];\n\
    \        return c;\n    }\n    constexpr int PRIMES[3] = { 1004535809, 998244353,\
    \ 985661441 };\n    std::vector<mint<PRIMES[0]> > x0(a.size());\n    std::vector<mint<PRIMES[1]>\
    \ > x1(a.size());\n    std::vector<mint<PRIMES[2]> > x2(a.size());\n    REP (i,\
    \ a.size()) {\n        x0[i] = a[i].value;\n        x1[i] = a[i].value;\n    \
    \    x2[i] = a[i].value;\n    }\n    std::vector<mint<PRIMES[0]> > y0(b.size());\n\
    \    std::vector<mint<PRIMES[1]> > y1(b.size());\n    std::vector<mint<PRIMES[2]>\
    \ > y2(b.size());\n    REP (j, b.size()) {\n        y0[j] = b[j].value;\n    \
    \    y1[j] = b[j].value;\n        y2[j] = b[j].value;\n    }\n    std::vector<mint<PRIMES[0]>\
    \ > z0 = ntt_convolution<PRIMES[0]>(x0, y0);\n    std::vector<mint<PRIMES[1]>\
    \ > z1 = ntt_convolution<PRIMES[1]>(x1, y1);\n    std::vector<mint<PRIMES[2]>\
    \ > z2 = ntt_convolution<PRIMES[2]>(x2, y2);\n    std::vector<mint<MOD> > c(z0.size());\n\
    \    REP (k, z0.size()) {\n        c[k] = garner_algorithm_template<MOD>(z0[k],\
    \ z1[k], z2[k]);\n    }\n    return c;\n}\n#line 2 \"modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#line 3 \"hack/fastio.hpp\"\n#include <cstdio>\n#include <string>\n#include\
    \ <type_traits>\n\ntemplate <class Char, std::enable_if_t<std::is_same_v<Char,\
    \ char>, int> = 0>\ninline Char in() { return getchar_unlocked(); }\ntemplate\
    \ <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> =\
    \ 0>\ninline std::string in() {\n    char c; do { c = getchar_unlocked(); } while\
    \ (isspace(c));\n    std::string s;\n    do { s.push_back(c); } while (not isspace(c\
    \ = getchar_unlocked()));\n    return s;\n}\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>\
    \ and not std::is_same_v<Integer, char>, int> = 0>\ninline Integer in() {\n  \
    \  char c; do { c = getchar_unlocked(); } while (isspace(c));\n    if (std::is_signed<Integer>::value\
    \ and c == '-') return -in<Integer>();\n    Integer n = 0;\n    do { n = n * 10\
    \ + c - '0'; } while (not isspace(c = getchar_unlocked()));\n    return n;\n}\n\
    \ntemplate <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\n\
    inline void out(char c) { putchar_unlocked(c); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline void out(const std::string & s) { for (char\
    \ c : s) putchar_unlocked(c); }\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>,\
    \ int> = 0>\ninline void out(Integer n) {\n    char s[20];\n    int i = 0;\n \
    \   if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *=\
    \ -1; }\n    do { s[i ++] = n % 10; n /= 10; } while (n);\n    while (i) putchar_unlocked(s[--\
    \ i] + '0');\n}\n#line 7 \"modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp\"\
    \n\nconstexpr int MOD = 1000000007;\nint main() {\n    // input\n    int n = in<uint32_t>();\n\
    \    int m = in<uint32_t>();\n    std::vector<mint<MOD> > a(n);\n    REP (i, n)\
    \ {\n        a[i].value = in<uint32_t>();\n    }\n    std::vector<mint<MOD> >\
    \ b(m);\n    REP (j, m) {\n        b[j].value = in<uint32_t>();\n    }\n\n   \
    \ // solve\n    std::vector<mint<MOD> > c = ntt_convolution(a, b);\n\n    // output\n\
    \    REP (i, n + m - 1) {\n        out<uint32_t>(c[i].value);\n        out<char>('\
    \ ');\n    }\n    out<char>('\\n');\n    return 0;\n}\n"
  code: "#include \"modulus/number_theoretic_transformation_with_garner.hpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\n\n#include\
    \ <vector>\n#include \"utils/macros.hpp\"\n#include \"hack/fastio.hpp\"\n\nconstexpr\
    \ int MOD = 1000000007;\nint main() {\n    // input\n    int n = in<uint32_t>();\n\
    \    int m = in<uint32_t>();\n    std::vector<mint<MOD> > a(n);\n    REP (i, n)\
    \ {\n        a[i].value = in<uint32_t>();\n    }\n    std::vector<mint<MOD> >\
    \ b(m);\n    REP (j, m) {\n        b[j].value = in<uint32_t>();\n    }\n\n   \
    \ // solve\n    std::vector<mint<MOD> > c = ntt_convolution(a, b);\n\n    // output\n\
    \    REP (i, n + m - 1) {\n        out<uint32_t>(c[i].value);\n        out<char>('\
    \ ');\n    }\n    out<char>('\\n');\n    return 0;\n}\n"
  dependsOn:
  - modulus/number_theoretic_transformation_with_garner.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  - utils/macros.hpp
  - modulus/number_theoretic_transformation.hpp
  - hack/fastio.hpp
  isVerificationFile: true
  path: modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-07-16 00:35:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp
layout: document
redirect_from:
- /verify/modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp
- /verify/modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp.html
title: modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp
---
