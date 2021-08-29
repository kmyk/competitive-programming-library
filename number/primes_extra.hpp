#pragma once
#include <cstdint>
#include <map>
#include <vector>
#include "../utils/macros.hpp"
#include "../number/primes.hpp"

std::map<int64_t, int> list_prime_factors_as_map(const prepared_primes& primes, int64_t n) {
    std::map<int64_t, int> cnt;
    for (int64_t p : primes.list_prime_factors(n)) {
        ++ cnt[p];
    }
    return cnt;
}

int64_t euler_totient(const prepared_primes& primes, int64_t n) {
    int64_t phi = 1;
    int64_t last = -1;
    for (int64_t p : primes.list_prime_factors(n)) {
        if (last != p) {
            last = p;
            phi *= p - 1;
        } else {
            phi *= p;
        }
    }
    return phi;
}
