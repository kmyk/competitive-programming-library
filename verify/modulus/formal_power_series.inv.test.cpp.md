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


# :heavy_check_mark: modulus/formal_power_series.inv.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/formal_power_series.inv.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-22 23:03:03+09:00


* see: <a href="https://judge.yosupo.jp/problem/inv_of_formal_power_series">https://judge.yosupo.jp/problem/inv_of_formal_power_series</a>


## Depends on

* :heavy_check_mark: <a href="../../library/modulus/formal_power_series.hpp.html">formal power series / 形式的羃級数環 $\mathbb{Z}/n\mathbb{Z}\lbrack\lbrack x\rbrack\rbrack$ <small>(modulus/formal_power_series.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/number_theoretic_transformation.hpp.html">Number Theoretic Transformation (NTT) for Proth primes <small>(modulus/number_theoretic_transformation.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "modulus/formal_power_series.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <cstdio>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

constexpr int MOD = 998244353;
int main() {
    // input
    int n; scanf("%d", &n);
    vector<mint<MOD> > a(n);
    REP (i, n) {
        scanf("%d", &a[i].value);
    }

    // solve
    vector<mint<MOD> > b = formal_power_series<mint<MOD> >(a).inv(n).data();
    b.resize(n);

    // output
    REP (i, n) {
        printf("%d ", b[i].value);
    }
    printf("\n");
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modulus/formal_power_series.hpp"
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <initializer_list>
#include <tuple>
#include <vector>
#line 4 "modulus/mint.hpp"
#include <iostream>
#line 3 "modulus/modpow.hpp"

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
#line 4 "modulus/modinv.hpp"

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
#line 11 "modulus/formal_power_series.hpp"

/**
 * @brief formal power series / 形式的羃級数環 $\mathbb{Z}/n\mathbb{Z}\lbrack\lbrack x\rbrack\rbrack$
 */
template <class T>
struct formal_power_series {
    std::vector<T> a;

    inline size_t size() const { return a.size(); }
    inline bool empty() const { return a.empty(); }
    inline T at(int i) const { return (i < size() ? a[i] : T(0)); }
    inline const std::vector<T> & data() const { return a; }

    formal_power_series() = default;
    formal_power_series(const std::vector<T> & a_) : a(a_) { shrink(); }
    formal_power_series(const std::initializer_list<T> & init) : a(init) { shrink(); }
    template <class Iterator>
    formal_power_series(Iterator first, Iterator last) : a(first, last) { shrink(); }
    void shrink() { while (not a.empty() and a.back().value == 0) a.pop_back(); }

    inline formal_power_series<T> operator + (const formal_power_series<T> & other) const {
        return formal_power_series<T>(a) += other;
    }
    inline formal_power_series<T> operator - (const formal_power_series<T> & other) const {
        return formal_power_series<T>(a) -= other;
    }
    inline formal_power_series<T> & operator += (const formal_power_series<T> & other) {
        if (a.size() < other.a.size()) a.resize(other.a.size(), T(0));
        REP (i, other.a.size()) a[i] += other.a[i];
        return *this;
    }
    inline formal_power_series<T> & operator -= (const formal_power_series<T> & other) {
        if (a.size() < other.a.size()) a.resize(other.a.size(), T(0));
        REP (i, other.a.size()) a[i] -= other.a[i];
        return *this;
    }
    inline formal_power_series<T> operator * (const formal_power_series<T> & other) const {
        return formal_power_series<T>(ntt_convolution(a, other.a));
    }
    inline formal_power_series<T> operator * (T b) {
        return formal_power_series<T>(a) *= b;
    }
    inline formal_power_series<T> & operator *= (T b) {
        REP (i, size()) a[i] *= b;
        return *this;
    }

    inline formal_power_series<T> integral() const {
        std::vector<T> b(size() + 1);
        REP (i, size()) {
            b[i + 1] = a[i] / (i + 1);
        }
        return b;
    }
    inline formal_power_series<T> differential() const {
        if (empty()) return *this;
        std::vector<T> b(size() - 1);
        REP (i, size() - 1) {
            b[i] = a[i + 1] * (i + 1);
        }
        return b;
    }
    inline formal_power_series<T> modulo_x_to(int k) const {
        return formal_power_series<T>(a.begin(), a.begin() + std::min<int>(size(), k));
    }

    formal_power_series<T> inv(int n) const {
        assert (at(0) != 0);
        formal_power_series<T> res { at(0).inv() };
        for (int i = 1; i < n; i *= 2) {
            res = (res * T(2) - res * res * modulo_x_to(2 * i)).modulo_x_to(2 * i);
        }
        return res.modulo_x_to(n);
    }
    formal_power_series<T> exp(int n) const {
        formal_power_series<T> f{ 1 };
        formal_power_series<T> g{ 1 };
        for (int i = 1; i < n; i *= 2) {
            g = (g * 2 - f * g * g).modulo_x_to(i);
            formal_power_series<T> q = differential().modulo_x_to(i - 1);
            formal_power_series<T> w = (q + g * (f.differential() - f * q)).modulo_x_to(2 * i - 1);
            f = (f + f * (*this - w.integral()).modulo_x_to(2 * i)).modulo_x_to(2 * i);
        }
        return f.modulo_x_to(n);
    }
    inline formal_power_series<T> log(int n) const {
        assert (at(0) == 1);
        return (this->differential() * this->inv(n - 1)).modulo_x_to(n - 1).integral();
    }
    inline formal_power_series<T> pow(int k, int n) const {
        return (this->log(n) * k).exp(n);
    }
};
#line 2 "modulus/formal_power_series.inv.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <cstdio>
#line 7 "modulus/formal_power_series.inv.test.cpp"
using namespace std;

constexpr int MOD = 998244353;
int main() {
    // input
    int n; scanf("%d", &n);
    vector<mint<MOD> > a(n);
    REP (i, n) {
        scanf("%d", &a[i].value);
    }

    // solve
    vector<mint<MOD> > b = formal_power_series<mint<MOD> >(a).inv(n).data();
    b.resize(n);

    // output
    REP (i, n) {
        printf("%d ", b[i].value);
    }
    printf("\n");
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

