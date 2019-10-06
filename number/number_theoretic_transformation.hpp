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

/**
 * @note O(N log N)
 * @note radix-2, decimation-in-frequency, Cooley-Tukey
 * @note cache std::polar (~ 2x faster)
 */
template <int32_t PRIME>
void ntt_inplace(std::vector<mint<PRIME> > & f, bool inverse) {
    const int n = f.size();
    const int log2_n = __builtin_ctz(n);
    assert (n == 1 << log2_n);
    assert (log2_n <= proth_prime<PRIME>::b);

    // cache
    static std::vector<mint<PRIME> > zeta;
    static std::vector<mint<PRIME> > zeta_inv;
    if ((int)zeta.size() != n / 2) {
        constexpr int a = proth_prime<PRIME>::a;
        constexpr int b = proth_prime<PRIME>::b;
        constexpr int g = proth_prime<PRIME>::g;
        const mint<PRIME> theta = mint<PRIME>(g).pow(a * (1 << (b - log2_n)));
        const mint<PRIME> theta_inv = theta.inv();
        zeta.resize(n / 2);
        zeta_inv.resize(n / 2);
        zeta[0] = 1;
        zeta_inv[0] = 1;
        REP (irev, n / 2 - 1) {
            zeta[irev + 1] = zeta[irev] * theta;
            zeta_inv[irev + 1] = zeta_inv[irev] * theta_inv;
        }
    }

    // bit reverse
    int i = 0;
    REP3 (j, 1, n - 1) {
        for (int k = n >> 1; (i ^= k) < k; k >>= 1);
        if (j < i) std::swap(f[i], f[j]);
    }

    // divide and conquer
    for (int mh = 1; (mh << 1) <= n; mh <<= 1) {
        int irev = 0;
        for (int i = 0; i < n; i += (mh << 1)) {
            auto w = (inverse ? zeta_inv : zeta)[irev];
            for (int k = n >> 2; (irev ^= k) < k; k >>= 1);
            REP3 (j, i, mh + i) {
                int k = j + mh;
                mint<PRIME> x = f[j] - f[k];
                f[j] += f[k];
                f[k] = w * x;
            }
        }
    }

    // div by n
    if (inverse) {
        REP (i, n) {
            f[i] /= n;
        }
    }
}

template <int32_t PRIME>
std::vector<mint<PRIME> > ntt(std::vector<mint<PRIME> > f) {
    f.resize(f.size() == 1 ? 1 : 1 << (32 - __builtin_clz(f.size() - 1)));
    ntt_inplace(f, false);
    return f;
}
template <int32_t PRIME>
std::vector<mint<PRIME> > intt(std::vector<mint<PRIME> > f) {
    f.resize(f.size() == 1 ? 1 : 1 << (32 - __builtin_clz(f.size() - 1)));
    ntt_inplace(f, true);
    return f;
}

/**
 * @brief the convolution
 * @note O(N log N)
 * @note (f \ast g)(i) = \sum_{0 \le j \lt i + 1} f(j) g(i - j)
 */
template <int32_t PRIME>
std::vector<mint<PRIME> > convolution(std::vector<mint<PRIME> > a, std::vector<mint<PRIME> > b) {
    assert (not a.empty() and not b.empty());
    int m = a.size() + b.size() - 1;
    int n = (m == 1 ? 1 : 1 << (32 - __builtin_clz(m - 1)));
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
std::vector<mint<MOD> > convolution_arbitrary_modulo(const std::vector<mint<MOD> > & a, const std::vector<mint<MOD> > & b) {
    constexpr int PRIMES[3] = { 1224736769, 998244353, 985661441 };
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
    std::vector<mint<PRIMES[0]> > z0 = convolution(x0, y0);
    std::vector<mint<PRIMES[1]> > z1 = convolution(x1, y1);
    std::vector<mint<PRIMES[2]> > z2 = convolution(x2, y2);
    std::vector<mint<MOD> > c(z0.size());
    REP (k, z0.size()) {
        std::vector<std::pair<int32_t, int32_t> > eqns {
            std::make_pair(z0[k].value, PRIMES[0]),
            std::make_pair(z1[k].value, PRIMES[1]),
            std::make_pair(z2[k].value, PRIMES[2]),
        };
        c[k] = garner_algorithm(eqns, MOD);
    }
    return c;
}
