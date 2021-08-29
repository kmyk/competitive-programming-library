---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulus/formal_power_series.hpp
    title: "formal power series / \u5F62\u5F0F\u7684\u7F83\u7D1A\u6570\u74B0 $\\mathbb{Z}/n\\\
      mathbb{Z}\\lbrack\\lbrack x\\rbrack\\rbrack$"
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
    path: modulus/number_theoretic_transformation.hpp
    title: Number Theoretic Transformation (NTT) for Proth primes
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
    PROBLEM: https://yukicoder.me/problems/no/1145
    links:
    - https://yukicoder.me/problems/no/1145
  bundledCode: "#line 1 \"modulus/formal_power_series.yukicoder-1145.test.cpp\"\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/1145\"\n#include <cstdio>\n\
    #include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i\
    \ = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) <\
    \ (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 2 \"modulus/mint.hpp\"\
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
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 5 \"modulus/formal_power_series.hpp\"\
    \n#include <initializer_list>\n#include <tuple>\n#line 9 \"modulus/number_theoretic_transformation.hpp\"\
    \n\ntemplate <int32_t PRIME> struct proth_prime {};\ntemplate <> struct proth_prime<1224736769>\
    \ { static constexpr int a =             73, b = 24, g =  3; };\ntemplate <> struct\
    \ proth_prime<1053818881> { static constexpr int a =     3 * 5 * 67, b = 20, g\
    \ =  7; };\ntemplate <> struct proth_prime<1051721729> { static constexpr int\
    \ a =        17 * 59, b = 20, g =  6; };\ntemplate <> struct proth_prime<1045430273>\
    \ { static constexpr int a =            997, b = 20, g =  3; };\ntemplate <> struct\
    \ proth_prime<1012924417> { static constexpr int a =     3 * 7 * 23, b = 21, g\
    \ =  5; };\ntemplate <> struct proth_prime<1007681537> { static constexpr int\
    \ a =        31 * 31, b = 20, g =  3; };\ntemplate <> struct proth_prime<1004535809>\
    \ { static constexpr int a =            479, b = 21, g =  3; };\ntemplate <> struct\
    \ proth_prime< 998244353> { static constexpr int a =         7 * 17, b = 23, g\
    \ =  3; };\ntemplate <> struct proth_prime< 985661441> { static constexpr int\
    \ a =         5 * 47, b = 22, g =  3; };\ntemplate <> struct proth_prime< 976224257>\
    \ { static constexpr int a =     7 * 7 * 19, b = 20, g =  3; };\ntemplate <> struct\
    \ proth_prime< 975175681> { static constexpr int a =     3 * 5 * 31, b = 21, g\
    \ = 17; };\ntemplate <> struct proth_prime< 962592769> { static constexpr int\
    \ a = 3 * 3 * 3 * 17, b = 21, g =  7; };\ntemplate <> struct proth_prime< 950009857>\
    \ { static constexpr int a =        4 * 151, b = 21, g =  7; };\ntemplate <> struct\
    \ proth_prime< 943718401> { static constexpr int a =  3 * 3 * 5 * 5, b = 22, g\
    \ =  7; };\ntemplate <> struct proth_prime< 935329793> { static constexpr int\
    \ a =            223, b = 22, g =  3; };\ntemplate <> struct proth_prime< 924844033>\
    \ { static constexpr int a =  3 * 3 * 7 * 7, b = 21, g =  5; };\ntemplate <> struct\
    \ proth_prime< 469762049> { static constexpr int a =              7, b = 26, g\
    \ =  3; };\ntemplate <> struct proth_prime< 167772161> { static constexpr int\
    \ a =              5, b = 25, g =  3; };\n\nstruct is_proth_prime_impl {\n   \
    \ template <int32_t PRIME, class T> static auto check(T *) -> decltype(proth_prime<PRIME>::g,\
    \ std::true_type());\n    template <int32_t PRIME, class T> static auto check(...)\
    \ -> std::false_type;\n};\ntemplate <int32_t PRIME>\nstruct is_proth_prime : decltype(is_proth_prime_impl::check<PRIME,\
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
    \  ntt_inplace(a, true);\n    a.resize(m);\n    return a;\n}\n#line 11 \"modulus/formal_power_series.hpp\"\
    \n\n/**\n * @brief formal power series / \u5F62\u5F0F\u7684\u7F83\u7D1A\u6570\u74B0\
    \ $\\mathbb{Z}/n\\mathbb{Z}\\lbrack\\lbrack x\\rbrack\\rbrack$\n */\ntemplate\
    \ <class T>\nstruct formal_power_series {\n    std::vector<T> a;\n\n    inline\
    \ size_t size() const { return a.size(); }\n    inline bool empty() const { return\
    \ a.empty(); }\n    inline T at(int i) const { return (i < size() ? a[i] : T(0));\
    \ }\n    inline const std::vector<T> & data() const { return a; }\n\n    formal_power_series()\
    \ = default;\n    formal_power_series(const std::vector<T> & a_) : a(a_) { shrink();\
    \ }\n    formal_power_series(const std::initializer_list<T> & init) : a(init)\
    \ { shrink(); }\n    template <class Iterator>\n    formal_power_series(Iterator\
    \ first, Iterator last) : a(first, last) { shrink(); }\n    void shrink() { while\
    \ (not a.empty() and a.back().value == 0) a.pop_back(); }\n\n    inline formal_power_series<T>\
    \ operator + (const formal_power_series<T> & other) const {\n        return formal_power_series<T>(a)\
    \ += other;\n    }\n    inline formal_power_series<T> operator - (const formal_power_series<T>\
    \ & other) const {\n        return formal_power_series<T>(a) -= other;\n    }\n\
    \    inline formal_power_series<T> & operator += (const formal_power_series<T>\
    \ & other) {\n        if (a.size() < other.a.size()) a.resize(other.a.size(),\
    \ T(0));\n        REP (i, other.a.size()) a[i] += other.a[i];\n        return\
    \ *this;\n    }\n    inline formal_power_series<T> & operator -= (const formal_power_series<T>\
    \ & other) {\n        if (a.size() < other.a.size()) a.resize(other.a.size(),\
    \ T(0));\n        REP (i, other.a.size()) a[i] -= other.a[i];\n        return\
    \ *this;\n    }\n    inline formal_power_series<T> operator * (const formal_power_series<T>\
    \ & other) const {\n        return formal_power_series<T>(ntt_convolution(a, other.a));\n\
    \    }\n    inline formal_power_series<T> operator * (T b) {\n        return formal_power_series<T>(a)\
    \ *= b;\n    }\n    inline formal_power_series<T> & operator *= (T b) {\n    \
    \    REP (i, size()) a[i] *= b;\n        return *this;\n    }\n    inline formal_power_series<T>\
    \ operator / (T b) {\n        return formal_power_series<T>(a) /= b;\n    }\n\
    \    inline formal_power_series<T> & operator /= (T b) {\n        REP (i, size())\
    \ a[i] /= b;\n        return *this;\n    }\n\n    inline formal_power_series<T>\
    \ integral() const {\n        std::vector<T> b(size() + 1);\n        REP (i, size())\
    \ {\n            b[i + 1] = a[i] / (i + 1);\n        }\n        return b;\n  \
    \  }\n    inline formal_power_series<T> differential() const {\n        if (empty())\
    \ return *this;\n        std::vector<T> b(size() - 1);\n        REP (i, size()\
    \ - 1) {\n            b[i] = a[i + 1] * (i + 1);\n        }\n        return b;\n\
    \    }\n    inline formal_power_series<T> modulo_x_to(int k) const {\n       \
    \ return formal_power_series<T>(a.begin(), a.begin() + std::min<int>(size(), k));\n\
    \    }\n\n    formal_power_series<T> inv(int n) const {\n        assert (at(0)\
    \ != 0);\n        formal_power_series<T> res { at(0).inv() };\n        for (int\
    \ i = 1; i < n; i *= 2) {\n            res = (res * T(2) - res * res * modulo_x_to(2\
    \ * i)).modulo_x_to(2 * i);\n        }\n        return res.modulo_x_to(n);\n \
    \   }\n    formal_power_series<T> exp(int n) const {\n        formal_power_series<T>\
    \ f{ 1 };\n        formal_power_series<T> g{ 1 };\n        for (int i = 1; i <\
    \ n; i *= 2) {\n            g = (g * 2 - f * g * g).modulo_x_to(i);\n        \
    \    formal_power_series<T> q = differential().modulo_x_to(i - 1);\n         \
    \   formal_power_series<T> w = (q + g * (f.differential() - f * q)).modulo_x_to(2\
    \ * i - 1);\n            f = (f + f * (*this - w.integral()).modulo_x_to(2 * i)).modulo_x_to(2\
    \ * i);\n        }\n        return f.modulo_x_to(n);\n    }\n    inline formal_power_series<T>\
    \ log(int n) const {\n        assert (at(0) != 0);\n        if (at(0) != 1) return\
    \ (formal_power_series<T>(a) / at(0)).log(n) * at(0);\n        if (size() == 1)\
    \ return formal_power_series();\n        return (this->differential() * this->inv(n\
    \ - 1)).modulo_x_to(n - 1).integral();\n    }\n    inline formal_power_series<T>\
    \ pow(int k, int n) const {\n        return (this->log(n) * k).exp(n);\n    }\n\
    };\n\ntemplate <class T>\ninline formal_power_series<T> operator - (const formal_power_series<T>\
    \ & f) {\n    return formal_power_series<T>(f) *= -1;\n}\n\ntemplate <class T>\n\
    std::ostream & operator << (std::ostream & out, const formal_power_series<T> &\
    \ f) {\n    bool is_zero = true;\n    REP (i, f.size()) {\n        if (f.at(i))\
    \ {\n            if (not is_zero) out << '+';\n            out << f.at(i);\n \
    \           if (i) out << \"x^\" << i;\n            is_zero = false;\n       \
    \ }\n    }\n    if (is_zero) {\n        out << \"0\";\n    }\n    return out;\n\
    }\n#line 7 \"modulus/formal_power_series.yukicoder-1145.test.cpp\"\nusing namespace\
    \ std;\n\nconstexpr int MOD = 998244353;\nvector<mint<MOD> > solve(int n, int\
    \ m, const vector<mint<MOD> > & a) {\n    auto go = [&](auto && go, int l, int\
    \ r) {\n        if (r - l == 0) return formal_power_series<mint<MOD> >{ 1 };\n\
    \        if (r - l == 1) return formal_power_series<mint<MOD> >{ 1, - a[l] };\n\
    \        int m_ = (l + r) / 2;\n        return (go(go, l, m_) * go(go, m_, r)).modulo_x_to(m\
    \ + 2);\n    };\n    vector<mint<MOD> > ans = (- go(go, 0, n).log(m + 2)).data();\n\
    \    ans.resize(m + 1);\n    REP3 (k, 1, m + 1) {\n        ans[k] *= k;\n    }\n\
    \    return ans;\n}\n\nint main() {\n    int n, m; scanf(\"%d%d\", &n, &m);\n\
    \    vector<mint<MOD> > a(n);\n    REP (i, n) {\n        scanf(\"%d\", &a[i].value);\n\
    \    }\n    auto ans = solve(n, m, a);\n    assert (ans[0] == 0);\n    REP (i,\
    \ m) {\n        printf(\"%d%c\", ans[i + 1].value, i + 1 < m ? ' ' : '\\n');\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1145\"\n#include <cstdio>\n\
    #include <vector>\n#include \"../utils/macros.hpp\"\n#include \"../modulus/mint.hpp\"\
    \n#include \"../modulus/formal_power_series.hpp\"\nusing namespace std;\n\nconstexpr\
    \ int MOD = 998244353;\nvector<mint<MOD> > solve(int n, int m, const vector<mint<MOD>\
    \ > & a) {\n    auto go = [&](auto && go, int l, int r) {\n        if (r - l ==\
    \ 0) return formal_power_series<mint<MOD> >{ 1 };\n        if (r - l == 1) return\
    \ formal_power_series<mint<MOD> >{ 1, - a[l] };\n        int m_ = (l + r) / 2;\n\
    \        return (go(go, l, m_) * go(go, m_, r)).modulo_x_to(m + 2);\n    };\n\
    \    vector<mint<MOD> > ans = (- go(go, 0, n).log(m + 2)).data();\n    ans.resize(m\
    \ + 1);\n    REP3 (k, 1, m + 1) {\n        ans[k] *= k;\n    }\n    return ans;\n\
    }\n\nint main() {\n    int n, m; scanf(\"%d%d\", &n, &m);\n    vector<mint<MOD>\
    \ > a(n);\n    REP (i, n) {\n        scanf(\"%d\", &a[i].value);\n    }\n    auto\
    \ ans = solve(n, m, a);\n    assert (ans[0] == 0);\n    REP (i, m) {\n       \
    \ printf(\"%d%c\", ans[i + 1].value, i + 1 < m ? ' ' : '\\n');\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  - modulus/formal_power_series.hpp
  - modulus/number_theoretic_transformation.hpp
  isVerificationFile: true
  path: modulus/formal_power_series.yukicoder-1145.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: modulus/formal_power_series.yukicoder-1145.test.cpp
layout: document
redirect_from:
- /verify/modulus/formal_power_series.yukicoder-1145.test.cpp
- /verify/modulus/formal_power_series.yukicoder-1145.test.cpp.html
title: modulus/formal_power_series.yukicoder-1145.test.cpp
---
