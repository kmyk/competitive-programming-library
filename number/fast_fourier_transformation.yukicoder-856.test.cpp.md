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
  - icon: ':x:'
    path: number/fast_fourier_transformation.hpp
    title: FFT convolution
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
    PROBLEM: https://yukicoder.me/problems/no/856
    links:
    - https://yukicoder.me/problems/no/856
  bundledCode: "#line 1 \"number/fast_fourier_transformation.yukicoder-856.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/856\"\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define\
    \ REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for\
    \ (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n)\
    \ - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 2 \"\
    modulus/mint.hpp\"\n#include <cstdint>\n#line 2 \"modulus/modpow.hpp\"\n#include\
    \ <cassert>\n#line 4 \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t\
    \ x, uint64_t k, int32_t MOD) {\n    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n\
    \    uint_fast64_t y = 1;\n    for (; k; k >>= 1) {\n        if (k & 1) (y *=\
    \ x) %= MOD;\n        (x *= x) %= MOD;\n    }\n    assert (/* 0 <= y and */ y\
    \ < (uint_fast64_t)MOD);\n    return y;\n}\n#line 5 \"modulus/modinv.hpp\"\n\n\
    inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {\n    assert (0 <=\
    \ value and value < MOD);\n    if (value == 0) return -1;\n    int64_t a = value,\
    \ b = MOD;\n    int64_t x = 0, y = 1;\n    for (int64_t u = 1, v = 0; a; ) {\n\
    \        int64_t q = b / a;\n        x -= q * u; std::swap(x, u);\n        y -=\
    \ q * v; std::swap(y, v);\n        b -= q * a; std::swap(b, a);\n    }\n    if\
    \ (not (value * x + MOD * y == b and b == 1)) return -1;\n    if (x < 0) x +=\
    \ MOD;\n    assert (0 <= x and x < MOD);\n    return x;\n}\n\ninline int32_t modinv(int32_t\
    \ x, int32_t MOD) {\n    int32_t y = modinv_nocheck(x, MOD);\n    assert (y !=\
    \ -1);\n    return y;\n}\n#line 6 \"modulus/mint.hpp\"\n\n/**\n * @brief quotient\
    \ ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$\n */\ntemplate <int32_t\
    \ MOD>\nstruct mint {\n    int32_t value;\n    mint() : value() {}\n    mint(int64_t\
    \ value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD\
    \ : value_) {}\n    mint(int32_t value_, std::nullptr_t) : value(value_) {}\n\
    \    explicit operator bool() const { return value; }\n    inline mint<MOD> operator\
    \ + (mint<MOD> other) const { return mint<MOD>(*this) += other; }\n    inline\
    \ mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other;\
    \ }\n    inline mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this)\
    \ *= other; }\n    inline mint<MOD> & operator += (mint<MOD> other) { this->value\
    \ += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }\n\
    \    inline mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value;\
    \ if (this->value <    0) this->value += MOD; return *this; }\n    inline mint<MOD>\
    \ & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value *\
    \ other.value % MOD; return *this; }\n    inline mint<MOD> operator - () const\
    \ { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }\n    inline\
    \ bool operator == (mint<MOD> other) const { return value == other.value; }\n\
    \    inline bool operator != (mint<MOD> other) const { return value != other.value;\
    \ }\n    inline mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value,\
    \ k, MOD), nullptr); }\n    inline mint<MOD> inv() const { return mint<MOD>(modinv(value,\
    \ MOD), nullptr); }\n    inline mint<MOD> operator / (mint<MOD> other) const {\
    \ return *this * other.inv(); }\n    inline mint<MOD> & operator /= (mint<MOD>\
    \ other) { return *this *= other.inv(); }\n};\ntemplate <int32_t MOD> mint<MOD>\
    \ operator + (int64_t value, mint<MOD> n) { return mint<MOD>(value) + n; }\ntemplate\
    \ <int32_t MOD> mint<MOD> operator - (int64_t value, mint<MOD> n) { return mint<MOD>(value)\
    \ - n; }\ntemplate <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD>\
    \ n) { return mint<MOD>(value) * n; }\ntemplate <int32_t MOD> mint<MOD> operator\
    \ / (int64_t value, mint<MOD> n) { return mint<MOD>(value) / n; }\ntemplate <int32_t\
    \ MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t\
    \ value; in >> value; n = value; return in; }\ntemplate <int32_t MOD> std::ostream\
    \ & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }\n\
    #line 4 \"number/fast_fourier_transformation.hpp\"\n#include <cmath>\n#include\
    \ <complex>\n#line 8 \"number/fast_fourier_transformation.hpp\"\n\n/**\n * @note\
    \ O(N log N)\n * @note radix-2, decimation-in-frequency, Cooley-Tukey\n * @note\
    \ cache std::polar (~ 2x faster)\n */\ntemplate <typename R>\nvoid fft_inplace(std::vector<std::complex<R>\
    \ > & f, bool inverse) {\n    const int n = f.size();\n    assert (n == pow(2,\
    \ log2(n)));\n\n    // cache\n    static std::vector<std::complex<R> > cache;\n\
    \    if ((int)cache.size() != n / 2) {\n        const R theta = 2 * M_PI / n;\n\
    \        cache.resize(n / 2);\n        REP (irev, n / 2) {\n            cache[irev]\
    \ = std::polar<R>(1, irev * theta);\n        }\n    }\n\n    // bit reverse\n\
    \    int i = 0;\n    REP3 (j, 1, n - 1) {\n        for (int k = n >> 1; (i ^=\
    \ k) < k; k >>= 1);\n        if (j < i) swap(f[i], f[j]);\n    }\n\n    // divide\
    \ and conquer\n    for (int mh = 1; (mh << 1) <= n; mh <<= 1) {\n        int irev\
    \ = 0;\n        for (int i = 0; i < n; i += (mh << 1)) {\n            auto w =\
    \ (inverse ? conj(cache[irev]) : cache[irev]);\n            for (int k = n >>\
    \ 2; (irev ^= k) < k; k >>= 1);\n            REP3 (j, i, mh + i) {\n         \
    \       int k = j + mh;\n                std::complex<R> x = f[j] - f[k];\n  \
    \              f[j] += f[k];\n                f[k] = w * x;\n            }\n \
    \       }\n    }\n}\n\ntemplate <typename R>\nstd::vector<std::complex<R> > fft(std::vector<std::complex<R>\
    \ > f) {\n    f.resize(pow(2, ceil(log2(f.size()))));\n    fft_inplace(f, false);\n\
    \    return f;\n}\ntemplate <typename R>\nstd::vector<std::complex<R> > ifft(std::vector<std::complex<R>\
    \ > f) {\n    f.resize(pow(2, ceil(log2(f.size()))));\n    fft_inplace(f, true);\n\
    \    return f;\n}\n\n/**\n * @brief FFT convolution\n * @note O(N log N)\n * @note\
    \ (f \\ast g)(i) = \\sum_{0 \\le j \\lt i + 1} f(j) g(i - j)\n */\ntemplate <typename\
    \ T, typename R = double>\nstd::vector<T> fft_convolution(std::vector<T> const\
    \ & a, std::vector<T> const & b) {\n    assert (not a.empty() and not b.empty());\n\
    \    int m = a.size() + b.size() - 1;\n    int n = pow(2, ceil(log2(m)));\n  \
    \  std::vector<std::complex<R> > x(n), y(n);\n    copy(ALL(a), x.begin());\n \
    \   copy(ALL(b), y.begin());\n    fft_inplace(x, false);\n    fft_inplace(y, false);\n\
    \    std::vector<std::complex<R> > z(n);\n    REP (i, n) {\n        z[i] = x[i]\
    \ * y[i];\n    }\n    fft_inplace(z, true);\n    std::vector<T> c(m);\n    REP\
    \ (i, m) {\n        c[i] = std::is_integral<T>::value ? round(z[i].real() / n)\
    \ : z[i].real() / n;\n    }\n    return c;\n}\n#line 8 \"number/fast_fourier_transformation.yukicoder-856.test.cpp\"\
    \nusing namespace std;\n\nconstexpr int64_t MOD = 1000000007;\n\nmint<MOD> solve(int\
    \ n, const vector<int> &a) {\n    // \\prod_i \\prod_{j > i} (A_i + A_j)\n   \
    \ mint<MOD> x = 1;\n    {\n        int max_a = *max_element(ALL(a));\n       \
    \ vector<long double> cnt(max_a + 1);\n        for (int a_i : a) {\n         \
    \   ++ cnt[a_i];\n        }\n        cnt = fft_convolution(cnt, cnt);\n      \
    \  for (int a_i : a) {\n            -- cnt[2 * a_i];\n        }\n        REP (i,\
    \ cnt.size()) {\n            cnt[i] /= 2;\n        }\n        REP (i, cnt.size())\
    \ {\n            int64_t k = round(cnt[i]);\n            assert (abs(cnt[i] -\
    \ k) <= 1e-6);\n            x *= mint<MOD>(i).pow(k);\n        }\n    }\n\n  \
    \  // \\prod_i \\prod_{j > i} A_i^{A_j}\n    mint<MOD> y = 1;\n    {\n       \
    \ int64_t sum_a_j = 0;\n        REP_R (i, n) {\n            y *= mint<MOD>(a[i]).pow(sum_a_j);\n\
    \            sum_a_j += a[i];\n        }\n    }\n\n    // \\min_i \\mimn_{j >\
    \ i} (A_i + A_j)A_i^{A_j}\n    mint<MOD> z = 0;\n    {\n        double log_z =\
    \ INFINITY;\n        int64_t a_j = a[n - 1];\n        REP_R (i, n - 1) {\n   \
    \         double log_a_i_a_j = log(a[i] + a_j) + a_j * log(a[i]);\n          \
    \  if (log_a_i_a_j < log_z) {\n                log_z = log_a_i_a_j;\n        \
    \        z = mint<MOD>(a[i] + a_j) * mint<MOD>(a[i]).pow(a_j);\n            }\n\
    \            a_j = min<int64_t>(a[i], a_j);\n        }\n    }\n    return x *\
    \ y / z;\n}\n\nint main() {\n    int n; cin >> n;\n    vector<int> a(n);\n   \
    \ REP (i, n) {\n        cin >> a[i];\n    }\n    auto ans = solve(n, a);\n   \
    \ cout << ans << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/856\"\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n#include \"../utils/macros.hpp\"\n#include\
    \ \"../modulus/mint.hpp\"\n#include \"../number/fast_fourier_transformation.hpp\"\
    \nusing namespace std;\n\nconstexpr int64_t MOD = 1000000007;\n\nmint<MOD> solve(int\
    \ n, const vector<int> &a) {\n    // \\prod_i \\prod_{j > i} (A_i + A_j)\n   \
    \ mint<MOD> x = 1;\n    {\n        int max_a = *max_element(ALL(a));\n       \
    \ vector<long double> cnt(max_a + 1);\n        for (int a_i : a) {\n         \
    \   ++ cnt[a_i];\n        }\n        cnt = fft_convolution(cnt, cnt);\n      \
    \  for (int a_i : a) {\n            -- cnt[2 * a_i];\n        }\n        REP (i,\
    \ cnt.size()) {\n            cnt[i] /= 2;\n        }\n        REP (i, cnt.size())\
    \ {\n            int64_t k = round(cnt[i]);\n            assert (abs(cnt[i] -\
    \ k) <= 1e-6);\n            x *= mint<MOD>(i).pow(k);\n        }\n    }\n\n  \
    \  // \\prod_i \\prod_{j > i} A_i^{A_j}\n    mint<MOD> y = 1;\n    {\n       \
    \ int64_t sum_a_j = 0;\n        REP_R (i, n) {\n            y *= mint<MOD>(a[i]).pow(sum_a_j);\n\
    \            sum_a_j += a[i];\n        }\n    }\n\n    // \\min_i \\mimn_{j >\
    \ i} (A_i + A_j)A_i^{A_j}\n    mint<MOD> z = 0;\n    {\n        double log_z =\
    \ INFINITY;\n        int64_t a_j = a[n - 1];\n        REP_R (i, n - 1) {\n   \
    \         double log_a_i_a_j = log(a[i] + a_j) + a_j * log(a[i]);\n          \
    \  if (log_a_i_a_j < log_z) {\n                log_z = log_a_i_a_j;\n        \
    \        z = mint<MOD>(a[i] + a_j) * mint<MOD>(a[i]).pow(a_j);\n            }\n\
    \            a_j = min<int64_t>(a[i], a_j);\n        }\n    }\n    return x *\
    \ y / z;\n}\n\nint main() {\n    int n; cin >> n;\n    vector<int> a(n);\n   \
    \ REP (i, n) {\n        cin >> a[i];\n    }\n    auto ans = solve(n, a);\n   \
    \ cout << ans << endl;\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  - number/fast_fourier_transformation.hpp
  isVerificationFile: true
  path: number/fast_fourier_transformation.yukicoder-856.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: number/fast_fourier_transformation.yukicoder-856.test.cpp
layout: document
redirect_from:
- /verify/number/fast_fourier_transformation.yukicoder-856.test.cpp
- /verify/number/fast_fourier_transformation.yukicoder-856.test.cpp.html
title: number/fast_fourier_transformation.yukicoder-856.test.cpp
---
