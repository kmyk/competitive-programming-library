#pragma once
#include <cassert>
#include <cstdint>
#include "../modulus/modpow.hpp"

/**
 * @brief find the sqrt $b$ of $a$ modulo $p$
 * @param p must be a prime
 * @note i.e. $b^2 \equiv a \pmod{p}$
 * @note -1 if not found
 */
int modsqrt(int a, int p) {
    auto legendre_symbol = [&](int a) {
        return modpow(a, (p - 1) / 2, p);  // Euler's criterion
    };
    a %= p;
    if (a == 0) return 0;
    if (p == 2) return a;
    assert (p >= 3);
    if (legendre_symbol(a) != +1) return -1;
    int b = 1;
    while (legendre_symbol(b) == 1) {
        b += 1;
    }
    int e = 0;
    int m = p - 1;
    while (m % 2 == 0) {
        m /= 2;
        e += 1;
    }
    int64_t x = modpow(a, (m - 1) / 2, p);
    int64_t y = a * x % p * x % p;
    x = x * a % p;
    int64_t z = modpow(b, m, p);
    while (y != 1) {
        int j = 0;
        for (int64_t t = y; t != 1; t = t * t % p) ++ j;
        if (e <= j) return -1;
        z = modpow(z, 1ll << (e - j - 1), p);
        x = x * z % p;
        z = z * z % p;
        y = y * z % p;
        e = j;
    }
    assert (x * x % p == a);
    return x;
}
