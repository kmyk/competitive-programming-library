#pragma once
#include <cassert>
#include <random>
#include "utils/macros.hpp"
#include "modulus/modpow.hpp"

/**
 * @brief miller-rabin primality test
 * @note $O(k \log n)$
 */
template <class RandomEngine>
bool is_prime(int64_t n, int iteration, RandomEngine& gen) {
    assert (0 <= n);
    if (n == 2) return true;
    if (n == 1 or n % 2 == 0) return false;
    const int64_t d = (n - 1) >> __builtin_ctzll(n - 1);  // remove trailing zeros
    std::uniform_int_distribution<int64_t> dist(1, n - 2);  // [l, r]
    REP (dummy, iteration) {
        int64_t a = dist(gen);
        int64_t t = d;
        int64_t y = modpow(a, t, n);
        while (t != n - 1 and y != 1 and y != n - 1) {
            y = y * y % n;
            t *= 2;
        }
        if (y != n - 1 and t % 2 == 0) return false;
    }
    return true;
}

bool is_prime(int64_t n) {
    static std::default_random_engine gen = std::default_random_engine(std::random_device()());
    return is_prime(n, 20, gen);
}
