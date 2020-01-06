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


# :heavy_check_mark: modulus/number_theoretic_transformation.998244353.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/modulus/number_theoretic_transformation.998244353.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-07 07:28:15+09:00


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod">https://judge.yosupo.jp/problem/convolution_mod</a>


## Depends on

* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/number_theoretic_transformation.hpp.html">a specialized version of Garner's algorithm <small>(modulus/number_theoretic_transformation.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/fastio_printer.hpp.html">utils/fastio_printer.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/fastio_scanner.hpp.html">utils/fastio_scanner.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "modulus/number_theoretic_transformation.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <vector>
#include "utils/macros.hpp"
#include "utils/fastio_scanner.hpp"
#include "utils/fastio_printer.hpp"

constexpr int MOD = 998244353;
int main() {
    scanner sc;
    printer pr;

    // input
    int n = sc.get<uint32_t>();
    int m = sc.get<uint32_t>();
    std::vector<mint<MOD> > a(n);
    REP (i, n) {
        a[i].value = sc.get<uint32_t>();
    }
    std::vector<mint<MOD> > b(m);
    REP (j, m) {
        b[j].value = sc.get<uint32_t>();
    }

    // solve
    std::vector<mint<MOD> > c = ntt_convolution(a, b);

    // output
    REP (i, n + m - 1) {
        pr.put<uint32_t>(c[i].value);
        pr.put<char>(' ');
    }
    pr.put<char>('\n');
    return 0;
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

/*
 * @brief a specialized version of Garner's algorithm
 */
template <int32_t MOD, int32_t MOD1, int32_t MOD2, int32_t MOD3>
mint<MOD> garner_algorithm(mint<MOD1> a1, mint<MOD2> a2, mint<MOD3> a3) {
    static const auto r12 = mint<MOD2>(MOD1).inv();
    static const auto r13 = mint<MOD3>(MOD1).inv();
    static const auto r23 = mint<MOD3>(MOD2).inv();
    a2 = (a2 - a1.value) * r12;
    a3 = (a3 - a1.value) * r13;
    a3 = (a3 - a2.value) * r23;
    return a1.value + a2.value * mint<MOD>(MOD1) + a3.value * (mint<MOD>(MOD1) * mint<MOD>(MOD2));
}

/*
 * @arg eqns is equations like x = a_i (mod m_i)
 * @return the minimal solution of given equations
 */
int32_t garner_algorithm(std::vector<std::pair<int32_t, int32_t> > eqns, int32_t MOD) {
    eqns.emplace_back(0, MOD);
    std::vector<int64_t> k(eqns.size(), 1);
    std::vector<int64_t> c(eqns.size(), 0);
    REP (i, eqns.size() - 1) {
        int32_t a_i, m_i; std::tie(a_i, m_i) = eqns[i];

        int32_t x = (a_i - c[i]) * modinv(k[i], m_i) % m_i;
        if (x < 0) x += m_i;
        assert (a_i == (k[i] * x + c[i]) % m_i);

        REP3 (j, i + 1, eqns.size()) {
            int32_t a_j, m_j; std::tie(a_j, m_j) = eqns[j];
            (c[j] += k[j] * x) %= m_j;
            (k[j] *= m_i) %= m_j;
        }
    }
    return c.back();
}

template <int32_t MOD>
std::vector<mint<MOD> > ntt_convolution_small(const std::vector<mint<MOD> > & a, const std::vector<mint<MOD> > & b) {
    std::vector<mint<MOD> > c(a.size() + b.size() - 1);
    REP (i, a.size()) {
        REP (j, b.size()) {
            c[i + j] += a[i] * b[j];
        }
    }
    return c;
}

/**
 * @brief the convolution on Z/pZ
 * @note O(N log N)
 * @note (f \ast g)(i) = \sum_{0 \le j \lt i + 1} f(j) g(i - j)
 */
template <int32_t PRIME>
typename std::enable_if<is_proth_prime<PRIME>::value, std::vector<mint<PRIME> > >::type ntt_convolution(const std::vector<mint<PRIME> > & a_, const std::vector<mint<PRIME> > & b_) {
    if (a_.size() <= 8 or b_.size() <= 8) return ntt_convolution_small(a_, b_);
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
    return a;
}

template <int32_t MOD>
typename std::enable_if<not is_proth_prime<MOD>::value, std::vector<mint<MOD> > >::type ntt_convolution(const std::vector<mint<MOD> > & a, const std::vector<mint<MOD> > & b) {
    if (a.size() <= 8 or b.size() <= 8) return ntt_convolution_small(a, b);
    constexpr int PRIMES[3] = { 1004535809, 998244353, 985661441 };
    std::vector<mint<PRIMES[0]> > x0(a.size());
    std::vector<mint<PRIMES[1]> > x1(a.size());
    std::vector<mint<PRIMES[2]> > x2(a.size());
    REP (i, a.size()) {
        x0[i] = a[i].value;
        x1[i] = a[i].value;
        x2[i] = a[i].value;
    }
    std::vector<mint<PRIMES[0]> > y0(b.size());
    std::vector<mint<PRIMES[1]> > y1(b.size());
    std::vector<mint<PRIMES[2]> > y2(b.size());
    REP (j, b.size()) {
        y0[j] = b[j].value;
        y1[j] = b[j].value;
        y2[j] = b[j].value;
    }
    std::vector<mint<PRIMES[0]> > z0 = ntt_convolution<PRIMES[0]>(x0, y0);
    std::vector<mint<PRIMES[1]> > z1 = ntt_convolution<PRIMES[1]>(x1, y1);
    std::vector<mint<PRIMES[2]> > z2 = ntt_convolution<PRIMES[2]>(x2, y2);
    std::vector<mint<MOD> > c(z0.size());
    REP (k, z0.size()) {
        c[k] = garner_algorithm<MOD>(z0[k], z1[k], z2[k]);
    }
    return c;
}
#line 2 "modulus/number_theoretic_transformation.998244353.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <vector>
#line 2 "utils/fastio_scanner.hpp"
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <type_traits>
#include <unistd.h>

class scanner {
    static constexpr int N = 65536;
    static constexpr int K = 64;
    char buf[K + N];
    int l = 0;
    int r = 0;
    void flush() {
        if (K < r - l) return;
        memmove(buf + K - (r - l), buf + l, r - l);
        l = K - (r - l);
        r = K + read(STDIN_FILENO, buf + K, N);
        assert (l < r);
    }
    void prepare() {
        flush();
        while (isspace(buf[l])) {
            ++ l;
            flush();
        }
    }
public:
    scanner() = default;
    scanner(const scanner &) = delete;
    scanner & operator = (const scanner &) = delete;
    template <class Char, std::enable_if_t<std::is_same<Char, char>::value, int> = 0>
    inline char get() {
        prepare();
        return buf[l ++];
    }
    template <class String, std::enable_if_t<std::is_same<String, std::string>::value, int> = 0>
    std::string get() {
        prepare();
        std::string s;
        do {
            s.push_back(buf[l ++]);
            if (r == l) flush();
        } while (not isspace(buf[l]));
        return s;
    }
    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    Integer get() {
        prepare();
        bool is_negative = false;
        if (std::is_signed<Integer>::value and buf[l] == '-') {
            is_negative = true;
            ++ l;
        }
        Integer x = 0;
        while (l < r and isdigit(buf[l])) {
            x *= 10;
            x += buf[l] - '0';
            ++ l;
        }
        if (std::is_signed<Integer>::value and is_negative) {
            x *= -1;
        }
        return x;
    }
};
#line 2 "utils/fastio_printer.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <type_traits>
#include <unistd.h>

class printer {
    static constexpr int N = 65536;
    static constexpr int K = 64;
    char buf[N];
    int i = 0;
    inline void flush() {
        write(STDOUT_FILENO, buf, i);
        i = 0;
    }
public:
    printer() = default;
    printer(const printer &) = delete;
    printer & operator = (const printer &) = delete;
    ~printer() {
        flush();
    }
    template <class Char, std::enable_if_t<std::is_same<Char, char>::value, int> = 0>
    inline void put(char c) {
        if (i == N) flush();
        buf[i ++] = c;
    }
    template <class String, std::enable_if_t<std::is_same<String, std::string>::value, int> = 0>
    void put(const std::string & s) {
        for (int l = 0; l < (int)s.length(); ) {
            if (i == N) flush();
            int r = std::min<int>(s.length(), l + (N - i));
            memcpy(buf + i, s.data() + l, r - l);
            i += r - l;
            l = r;
        }
    }
    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    void put(Integer x) {
        if (N - i < K) flush();
        if (std::is_signed<Integer>::value and x < 0) {
            x *= -1;
            buf[i ++] = '-';
        }
        if (x == 0) {
            buf[i ++] = '0';
            return;
        }
        char s[K];
        int j = 0;
        while (x) {
            s[j ++] = x % 10 + '0';
            x /= 10;
        }
        while (j) {
            buf[i ++] = s[-- j];
        }
    }
};
#line 8 "modulus/number_theoretic_transformation.998244353.test.cpp"

constexpr int MOD = 998244353;
int main() {
    scanner sc;
    printer pr;

    // input
    int n = sc.get<uint32_t>();
    int m = sc.get<uint32_t>();
    std::vector<mint<MOD> > a(n);
    REP (i, n) {
        a[i].value = sc.get<uint32_t>();
    }
    std::vector<mint<MOD> > b(m);
    REP (j, m) {
        b[j].value = sc.get<uint32_t>();
    }

    // solve
    std::vector<mint<MOD> > c = ntt_convolution(a, b);

    // output
    REP (i, n + m - 1) {
        pr.put<uint32_t>(c[i].value);
        pr.put<char>(' ');
    }
    pr.put<char>('\n');
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

