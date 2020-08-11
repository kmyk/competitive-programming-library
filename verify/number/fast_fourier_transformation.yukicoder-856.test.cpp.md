---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: number/fast_fourier_transformation.yukicoder-856.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/fast_fourier_transformation.yukicoder-856.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 20:59:07+09:00


* see: <a href="https://yukicoder.me/problems/no/856">https://yukicoder.me/problems/no/856</a>


## Depends on

* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/number/fast_fourier_transformation.hpp.html">FFT convolution <small>(number/fast_fourier_transformation.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/856"
#include <algorithm>
#include <iostream>
#include <vector>
#include "utils/macros.hpp"
#include "modulus/mint.hpp"
#include "number/fast_fourier_transformation.hpp"
using namespace std;

constexpr int64_t MOD = 1000000007;

mint<MOD> solve(int n, const vector<int> &a) {
    // \prod_i \prod_{j > i} (A_i + A_j)
    mint<MOD> x = 1;
    {
        int max_a = *max_element(ALL(a));
        vector<long double> cnt(max_a + 1);
        for (int a_i : a) {
            ++ cnt[a_i];
        }
        cnt = fft_convolution(cnt, cnt);
        for (int a_i : a) {
            -- cnt[2 * a_i];
        }
        REP (i, cnt.size()) {
            cnt[i] /= 2;
        }
        REP (i, cnt.size()) {
            int64_t k = round(cnt[i]);
            assert (abs(cnt[i] - k) <= 1e-6);
            x *= mint<MOD>(i).pow(k);
        }
    }

    // \prod_i \prod_{j > i} A_i^{A_j}
    mint<MOD> y = 1;
    {
        int64_t sum_a_j = 0;
        REP_R (i, n) {
            y *= mint<MOD>(a[i]).pow(sum_a_j);
            sum_a_j += a[i];
        }
    }

    // \min_i \mimn_{j > i} (A_i + A_j)A_i^{A_j}
    mint<MOD> z = 0;
    {
        double log_z = INFINITY;
        int64_t a_j = a[n - 1];
        REP_R (i, n - 1) {
            double log_a_i_a_j = log(a[i] + a_j) + a_j * log(a[i]);
            if (log_a_i_a_j < log_z) {
                log_z = log_a_i_a_j;
                z = mint<MOD>(a[i] + a_j) * mint<MOD>(a[i]).pow(a_j);
            }
            a_j = min<int64_t>(a[i], a_j);
        }
    }
    return x * y / z;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    auto ans = solve(n, a);
    cout << ans << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "number/fast_fourier_transformation.yukicoder-856.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/856"
#include <algorithm>
#include <iostream>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 2 "modulus/mint.hpp"
#include <cstdint>
#line 2 "modulus/modpow.hpp"
#include <cassert>
#line 4 "modulus/modpow.hpp"

inline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);
    return y;
}
#line 5 "modulus/modinv.hpp"

inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    if (value == 0) return -1;
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    if (not (value * x + MOD * y == b and b == 1)) return -1;
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

inline int32_t modinv(int32_t x, int32_t MOD) {
    int32_t y = modinv_nocheck(x, MOD);
    assert (y != -1);
    return y;
}
#line 6 "modulus/mint.hpp"

/**
 * @brief quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$
 */
template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline bool operator == (mint<MOD> other) const { return value == other.value; }
    inline bool operator != (mint<MOD> other) const { return value != other.value; }
    inline mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline mint<MOD> operator / (mint<MOD> other) const { return *this * other.inv(); }
    inline mint<MOD> & operator /= (mint<MOD> other) { return *this *= other.inv(); }
};
template <int32_t MOD> mint<MOD> operator + (int64_t value, mint<MOD> n) { return mint<MOD>(value) + n; }
template <int32_t MOD> mint<MOD> operator - (int64_t value, mint<MOD> n) { return mint<MOD>(value) - n; }
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> mint<MOD> operator / (int64_t value, mint<MOD> n) { return mint<MOD>(value) / n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }
#line 4 "number/fast_fourier_transformation.hpp"
#include <cmath>
#include <complex>
#line 8 "number/fast_fourier_transformation.hpp"

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
 * @brief FFT convolution
 * @note O(N log N)
 * @note (f \ast g)(i) = \sum_{0 \le j \lt i + 1} f(j) g(i - j)
 */
template <typename T, typename R = double>
std::vector<T> fft_convolution(std::vector<T> const & a, std::vector<T> const & b) {
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
#line 8 "number/fast_fourier_transformation.yukicoder-856.test.cpp"
using namespace std;

constexpr int64_t MOD = 1000000007;

mint<MOD> solve(int n, const vector<int> &a) {
    // \prod_i \prod_{j > i} (A_i + A_j)
    mint<MOD> x = 1;
    {
        int max_a = *max_element(ALL(a));
        vector<long double> cnt(max_a + 1);
        for (int a_i : a) {
            ++ cnt[a_i];
        }
        cnt = fft_convolution(cnt, cnt);
        for (int a_i : a) {
            -- cnt[2 * a_i];
        }
        REP (i, cnt.size()) {
            cnt[i] /= 2;
        }
        REP (i, cnt.size()) {
            int64_t k = round(cnt[i]);
            assert (abs(cnt[i] - k) <= 1e-6);
            x *= mint<MOD>(i).pow(k);
        }
    }

    // \prod_i \prod_{j > i} A_i^{A_j}
    mint<MOD> y = 1;
    {
        int64_t sum_a_j = 0;
        REP_R (i, n) {
            y *= mint<MOD>(a[i]).pow(sum_a_j);
            sum_a_j += a[i];
        }
    }

    // \min_i \mimn_{j > i} (A_i + A_j)A_i^{A_j}
    mint<MOD> z = 0;
    {
        double log_z = INFINITY;
        int64_t a_j = a[n - 1];
        REP_R (i, n - 1) {
            double log_a_i_a_j = log(a[i] + a_j) + a_j * log(a[i]);
            if (log_a_i_a_j < log_z) {
                log_z = log_a_i_a_j;
                z = mint<MOD>(a[i] + a_j) * mint<MOD>(a[i]).pow(a_j);
            }
            a_j = min<int64_t>(a[i], a_j);
        }
    }
    return x * y / z;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    auto ans = solve(n, a);
    cout << ans << endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

