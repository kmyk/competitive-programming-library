#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <vector>
#include "utils/macros.hpp"

/**
 * @note O(N log N)
 */
template <typename R>
void fft_inplace(std::vector<std::complex<R> > & f, int dir) {
    int n = f.size();
    assert (n == pow(2, log2(n)));
    R theta = dir * 2 * M_PI / n;
    for (int m = n; m >= 2; m >>= 1) {
        REP (i, m / 2) {
            std::complex<R> w = std::polar<R>(1, i * theta);
            for (int j = i; j < n; j += m) {
                int k = j + m / 2;
                std::complex<R> x = f[j] - f[k];
                f[j] += f[k];
                f[k] = w * x;
            }
        }
        theta *= 2;
    }
    int i = 0;
    REP3 (j, 1, n - 1) {
        for (int k = n >> 1; k > (i ^= k); ) k >>= 1;
        if (j < i) {
            std::swap(f[i], f[j]);
        }
    }
}
template <typename R>
std::vector<std::complex<R> > fft(std::vector<std::complex<R> > f) {
    f.resize(pow(2, ceil(log2(f.size()))));
    fft_inplace(f, +1);
    return f;
}
template <typename R>
std::vector<std::complex<R> > ifft(std::vector<std::complex<R> > f) {
    f.resize(pow(2, ceil(log2(f.size()))));
    fft_inplace(f, -1);
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
    fft_inplace(x, +1);
    fft_inplace(y, +1);
    std::vector<std::complex<R> > z(n);
    REP (i, n) {
        z[i] = x[i] * y[i];
    }
    fft_inplace(z, -1);
    std::vector<T> c(m);
    REP (i, m) {
        c[i] = std::is_integral<T>::value ? round(z[i].real() / n) : z[i].real() / n;
    }
    return c;
}
