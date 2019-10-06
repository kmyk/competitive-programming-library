#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <tuple>
#include <vector>
#include "modulus/mint.hpp"
#include "utils/macros.hpp"
#include <iostream>

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
struct is_proth_prime : decltype(is_proth_prime_impl::check<PRIME, nullptr_t>(nullptr)) {
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
