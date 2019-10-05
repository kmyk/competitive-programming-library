#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <vector>
#include "utils/macros.hpp"

/**
 * @note O(N log N)
 * @note radix-2, decimation-in-frequency, Cooley-Tukey
 * @note cache std::polar (~ 2x faster)
 */
template <typename R>
void fft_inplace(std::vector<std::complex<R> > & f, bool inverse) {
    const int n = f.size();
    assert (n == pow(2, log2(n)));

    // cache
    static std::vector<std::complex<R> > cache;
    if ((int)cache.size() != n / 2) {
        const R theta = 2 * M_PI / n;
        cache.resize(n / 2);
        REP (irev, n / 2) {
            cache[irev] = std::polar<R>(1, irev * theta);
        }
    }

    // bit reverse
    int i = 0;
    REP3 (j, 1, n - 1) {
        for (int k = n >> 1; (i ^= k) < k; k >>= 1);
        if (j < i) swap(f[i], f[j]);
    }

    // divide and conquer
    for (int mh = 1; (mh << 1) <= n; mh <<= 1) {
        int irev = 0;
        for (int i = 0; i < n; i += (mh << 1)) {
            auto w = (inverse ? conj(cache[irev]) : cache[irev]);
            for (int k = n >> 2; (irev ^= k) < k; k >>= 1);
            REP3 (j, i, mh + i) {
                int k = j + mh;
                std::complex<R> x = f[j] - f[k];
                f[j] += f[k];
                f[k] = w * x;
            }
        }
    }
}

template <typename R>
std::vector<std::complex<R> > fft(std::vector<std::complex<R> > f) {
    f.resize(pow(2, ceil(log2(f.size()))));
    fft_inplace(f, false);
    return f;
}
template <typename R>
std::vector<std::complex<R> > ifft(std::vector<std::complex<R> > f) {
    f.resize(pow(2, ceil(log2(f.size()))));
    fft_inplace(f, true);
    return f;
}

/**
 * @brief the convolution
 * @note O(N log N)
 * @note (f \ast g)(i) = \sum_{0 \le j \lt i + 1} f(j) g(i - j)
 */
template <typename T, typename R = double>
std::vector<T> convolution(std::vector<T> const & a, std::vector<T> const & b) {
    assert (not a.empty() and not b.empty());
    int m = a.size() + b.size() - 1;
    int n = pow(2, ceil(log2(m)));
    std::vector<std::complex<R> > x(n), y(n);
    copy(ALL(a), x.begin());
    copy(ALL(b), y.begin());
    fft_inplace(x, false);
    fft_inplace(y, false);
    std::vector<std::complex<R> > z(n);
    REP (i, n) {
        z[i] = x[i] * y[i];
    }
    fft_inplace(z, true);
    std::vector<T> c(m);
    REP (i, m) {
        c[i] = std::is_integral<T>::value ? round(z[i].real() / n) : z[i].real() / n;
    }
    return c;
}
