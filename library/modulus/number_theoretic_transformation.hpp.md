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


# :heavy_check_mark: Number Theoretic Transformation (NTT) for Proth primes <small>(modulus/number_theoretic_transformation.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/number_theoretic_transformation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-12 17:06:03+09:00


* multiprecation on $\mathbb{F}_p[x]$ for Proth primes


## Depends on

* :heavy_check_mark: <a href="mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Required by

* :heavy_check_mark: <a href="formal_power_series.hpp.html">modulus/formal_power_series.hpp</a>
* :heavy_check_mark: <a href="number_theoretic_transformation_with_garner.hpp.html">multiprecation on $\mathbb{Z}/n\mathbb{Z}\[x\]$ <small>(modulus/number_theoretic_transformation_with_garner.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.exp.test.cpp.html">modulus/formal_power_series.exp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.inv.test.cpp.html">modulus/formal_power_series.inv.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.log.test.cpp.html">modulus/formal_power_series.log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/number_theoretic_transformation.yosupo.test.cpp.html">modulus/number_theoretic_transformation.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp.html">modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <tuple>
#include <vector>
#include "modulus/mint.hpp"
#include "utils/macros.hpp"

template <int32_t PRIME> struct proth_prime {};
template <> struct proth_prime<1224736769> { static constexpr int a =             73, b = 24, g =  3; };
template <> struct proth_prime<1053818881> { static constexpr int a =     3 * 5 * 67, b = 20, g =  7; };
template <> struct proth_prime<1051721729> { static constexpr int a =        17 * 59, b = 20, g =  6; };
template <> struct proth_prime<1045430273> { static constexpr int a =            997, b = 20, g =  3; };
template <> struct proth_prime<1012924417> { static constexpr int a =     3 * 7 * 23, b = 21, g =  5; };
template <> struct proth_prime<1007681537> { static constexpr int a =        31 * 31, b = 20, g =  3; };
template <> struct proth_prime<1004535809> { static constexpr int a =            479, b = 21, g =  3; };
template <> struct proth_prime< 998244353> { static constexpr int a =         7 * 17, b = 23, g =  3; };
template <> struct proth_prime< 985661441> { static constexpr int a =         5 * 47, b = 22, g =  3; };
template <> struct proth_prime< 976224257> { static constexpr int a =     7 * 7 * 19, b = 20, g =  3; };
template <> struct proth_prime< 975175681> { static constexpr int a =     3 * 5 * 31, b = 21, g = 17; };
template <> struct proth_prime< 962592769> { static constexpr int a = 3 * 3 * 3 * 17, b = 21, g =  7; };
template <> struct proth_prime< 950009857> { static constexpr int a =        4 * 151, b = 21, g =  7; };
template <> struct proth_prime< 943718401> { static constexpr int a =  3 * 3 * 5 * 5, b = 22, g =  7; };
template <> struct proth_prime< 935329793> { static constexpr int a =            223, b = 22, g =  3; };
template <> struct proth_prime< 924844033> { static constexpr int a =  3 * 3 * 7 * 7, b = 21, g =  5; };
template <> struct proth_prime< 469762049> { static constexpr int a =              7, b = 26, g =  3; };
template <> struct proth_prime< 167772161> { static constexpr int a =              5, b = 25, g =  3; };

struct is_proth_prime_impl {
    template <int32_t PRIME, class T> static auto check(T *) -> decltype(proth_prime<PRIME>::g, std::true_type());
    template <int32_t PRIME, class T> static auto check(...) -> std::false_type;
};
template <int32_t PRIME>
struct is_proth_prime : decltype(is_proth_prime_impl::check<PRIME, std::nullptr_t>(nullptr)) {
};

/**
 * @brief Number Theoretic Transformation (NTT) for Proth primes
 * @note O(N log N)
 * @note radix-2, decimation-in-frequency, Cooley-Tukey
 * @note cache std::polar (~ 2x faster)
 */
template <int32_t PRIME>
void ntt_inplace(std::vector<mint<PRIME> > & a, bool inverse) {
    const int n = a.size();
    const int log2_n = __builtin_ctz(n);
    assert (n == 1 << log2_n);
    assert (log2_n <= proth_prime<PRIME>::b);

    // prepare rotors
    std::vector<mint<PRIME> > ep, iep;
    while ((int)ep.size() <= log2_n) {
        ep.push_back(mint<PRIME>(proth_prime<PRIME>::g).pow(mint<PRIME>(-1).value / (1 << ep.size())));
        iep.push_back(ep.back().inv());
    }

    // divide and conquer
    std::vector<mint<PRIME> > b(n);
    REP3 (i, 1, log2_n + 1) {
        int w = 1 << (log2_n - i);
        mint<PRIME> base = (inverse ? iep : ep)[i];
        mint<PRIME> now = 1;
        for (int y = 0; y < n / 2; y += w) {
            REP (x, w) {
                auto l = a[y << 1 | x];
                auto r = now * a[y << 1 | x | w];
                b[y | x] = l + r;
                b[y | x | n >> 1] = l - r;
            }
            now *= base;
        }
        std::swap(a, b);
    }

    // div by n if inverse
    if (inverse) {
        auto n_inv = mint<PRIME>(n).inv();
        REP (i, n) {
            a[i] *= n_inv;
        }
    }
}

/**
 * @brief multiprecation on $\mathbb{F}_p[x]$ for Proth primes
 * @note O(N log N)
 * @note (f \ast g)(i) = \sum_{0 \le j \lt i + 1} f(j) g(i - j)
 */
template <int32_t PRIME>
typename std::enable_if<is_proth_prime<PRIME>::value, std::vector<mint<PRIME> > >::type ntt_convolution(const std::vector<mint<PRIME> > & a_, const std::vector<mint<PRIME> > & b_) {
    if (a_.size() <= 32 or b_.size() <= 32) {
        std::vector<mint<PRIME> > c(a_.size() + b_.size() - 1);
        REP (i, a_.size()) REP (j, b_.size()) c[i + j] += a_[i] * b_[j];
        return c;
    }
    int m = a_.size() + b_.size() - 1;
    int n = (m == 1 ? 1 : 1 << (32 - __builtin_clz(m - 1)));
    auto a = a_;
    auto b = b_;
    a.resize(n);
    b.resize(n);
    ntt_inplace(a, false);
    ntt_inplace(b, false);
    REP (i, n) {
        a[i] *= b[i];
    }
    ntt_inplace(a, true);
    a.resize(m);
    return a;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modulus/number_theoretic_transformation.hpp"
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <tuple>
#include <vector>
#line 2 "modulus/mint.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#line 2 "modulus/modpow.hpp"
#include <cassert>

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}
#line 2 "modulus/modinv.hpp"
#include <algorithm>
#include <cassert>

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
#line 7 "modulus/mint.hpp"


template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline constexpr mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline constexpr mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline constexpr mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline constexpr mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline constexpr mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline constexpr mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline constexpr mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline constexpr mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline constexpr mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline constexpr mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline constexpr bool operator == (mint<MOD> other) const { return value == other.value; }
    inline constexpr bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 9 "modulus/number_theoretic_transformation.hpp"

template <int32_t PRIME> struct proth_prime {};
template <> struct proth_prime<1224736769> { static constexpr int a =             73, b = 24, g =  3; };
template <> struct proth_prime<1053818881> { static constexpr int a =     3 * 5 * 67, b = 20, g =  7; };
template <> struct proth_prime<1051721729> { static constexpr int a =        17 * 59, b = 20, g =  6; };
template <> struct proth_prime<1045430273> { static constexpr int a =            997, b = 20, g =  3; };
template <> struct proth_prime<1012924417> { static constexpr int a =     3 * 7 * 23, b = 21, g =  5; };
template <> struct proth_prime<1007681537> { static constexpr int a =        31 * 31, b = 20, g =  3; };
template <> struct proth_prime<1004535809> { static constexpr int a =            479, b = 21, g =  3; };
template <> struct proth_prime< 998244353> { static constexpr int a =         7 * 17, b = 23, g =  3; };
template <> struct proth_prime< 985661441> { static constexpr int a =         5 * 47, b = 22, g =  3; };
template <> struct proth_prime< 976224257> { static constexpr int a =     7 * 7 * 19, b = 20, g =  3; };
template <> struct proth_prime< 975175681> { static constexpr int a =     3 * 5 * 31, b = 21, g = 17; };
template <> struct proth_prime< 962592769> { static constexpr int a = 3 * 3 * 3 * 17, b = 21, g =  7; };
template <> struct proth_prime< 950009857> { static constexpr int a =        4 * 151, b = 21, g =  7; };
template <> struct proth_prime< 943718401> { static constexpr int a =  3 * 3 * 5 * 5, b = 22, g =  7; };
template <> struct proth_prime< 935329793> { static constexpr int a =            223, b = 22, g =  3; };
template <> struct proth_prime< 924844033> { static constexpr int a =  3 * 3 * 7 * 7, b = 21, g =  5; };
template <> struct proth_prime< 469762049> { static constexpr int a =              7, b = 26, g =  3; };
template <> struct proth_prime< 167772161> { static constexpr int a =              5, b = 25, g =  3; };

struct is_proth_prime_impl {
    template <int32_t PRIME, class T> static auto check(T *) -> decltype(proth_prime<PRIME>::g, std::true_type());
    template <int32_t PRIME, class T> static auto check(...) -> std::false_type;
};
template <int32_t PRIME>
struct is_proth_prime : decltype(is_proth_prime_impl::check<PRIME, std::nullptr_t>(nullptr)) {
};

/**
 * @brief Number Theoretic Transformation (NTT) for Proth primes
 * @note O(N log N)
 * @note radix-2, decimation-in-frequency, Cooley-Tukey
 * @note cache std::polar (~ 2x faster)
 */
template <int32_t PRIME>
void ntt_inplace(std::vector<mint<PRIME> > & a, bool inverse) {
    const int n = a.size();
    const int log2_n = __builtin_ctz(n);
    assert (n == 1 << log2_n);
    assert (log2_n <= proth_prime<PRIME>::b);

    // prepare rotors
    std::vector<mint<PRIME> > ep, iep;
    while ((int)ep.size() <= log2_n) {
        ep.push_back(mint<PRIME>(proth_prime<PRIME>::g).pow(mint<PRIME>(-1).value / (1 << ep.size())));
        iep.push_back(ep.back().inv());
    }

    // divide and conquer
    std::vector<mint<PRIME> > b(n);
    REP3 (i, 1, log2_n + 1) {
        int w = 1 << (log2_n - i);
        mint<PRIME> base = (inverse ? iep : ep)[i];
        mint<PRIME> now = 1;
        for (int y = 0; y < n / 2; y += w) {
            REP (x, w) {
                auto l = a[y << 1 | x];
                auto r = now * a[y << 1 | x | w];
                b[y | x] = l + r;
                b[y | x | n >> 1] = l - r;
            }
            now *= base;
        }
        std::swap(a, b);
    }

    // div by n if inverse
    if (inverse) {
        auto n_inv = mint<PRIME>(n).inv();
        REP (i, n) {
            a[i] *= n_inv;
        }
    }
}

/**
 * @brief multiprecation on $\mathbb{F}_p[x]$ for Proth primes
 * @note O(N log N)
 * @note (f \ast g)(i) = \sum_{0 \le j \lt i + 1} f(j) g(i - j)
 */
template <int32_t PRIME>
typename std::enable_if<is_proth_prime<PRIME>::value, std::vector<mint<PRIME> > >::type ntt_convolution(const std::vector<mint<PRIME> > & a_, const std::vector<mint<PRIME> > & b_) {
    if (a_.size() <= 32 or b_.size() <= 32) {
        std::vector<mint<PRIME> > c(a_.size() + b_.size() - 1);
        REP (i, a_.size()) REP (j, b_.size()) c[i + j] += a_[i] * b_[j];
        return c;
    }
    int m = a_.size() + b_.size() - 1;
    int n = (m == 1 ? 1 : 1 << (32 - __builtin_clz(m - 1)));
    auto a = a_;
    auto b = b_;
    a.resize(n);
    b.resize(n);
    ntt_inplace(a, false);
    ntt_inplace(b, false);
    REP (i, n) {
        a[i] *= b[i];
    }
    ntt_inplace(a, true);
    a.resize(m);
    return a;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

