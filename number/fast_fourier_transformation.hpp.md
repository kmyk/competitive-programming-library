---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number/fast_fourier_transformation.yukicoder-856.test.cpp
    title: number/fast_fourier_transformation.yukicoder-856.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: FFT convolution
    links: []
  bundledCode: "#line 2 \"number/fast_fourier_transformation.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 8 \"number/fast_fourier_transformation.hpp\"\n\n/**\n * @note\
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
    \ : z[i].real() / n;\n    }\n    return c;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <vector>\n#include \"utils/macros.hpp\"\n\n/**\n\
    \ * @note O(N log N)\n * @note radix-2, decimation-in-frequency, Cooley-Tukey\n\
    \ * @note cache std::polar (~ 2x faster)\n */\ntemplate <typename R>\nvoid fft_inplace(std::vector<std::complex<R>\
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
    \ : z[i].real() / n;\n    }\n    return c;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: number/fast_fourier_transformation.hpp
  requiredBy: []
  timestamp: '2020-08-11 20:59:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number/fast_fourier_transformation.yukicoder-856.test.cpp
documentation_of: number/fast_fourier_transformation.hpp
layout: document
redirect_from:
- /library/number/fast_fourier_transformation.hpp
- /library/number/fast_fourier_transformation.hpp.html
title: FFT convolution
---
