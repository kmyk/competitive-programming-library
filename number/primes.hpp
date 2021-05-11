#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>
#include "utils/macros.hpp"

struct prepared_primes {
    int size;
    std::vector<int> sieve;
    std::vector<int> primes;

    /**
     * @note O(size)
     */
    prepared_primes(int size_)
        : size(size_) {

        sieve.resize(size);
        REP3 (p, 2, size) if (sieve[p] == 0) {
            primes.push_back(p);
            for (int k = p; k < size; k += p) {
                if (sieve[k] == 0) {
                    sieve[k] = p;
                }
            }
        }
    }

    /**
     * @note let k be the length of the result, O(k) if n < size; O(\sqrt{n} + k) if size <= n < size^2
     */
    std::vector<int64_t> list_prime_factors(int64_t n) const {
        assert (1 <= n and n < (int64_t)size * size);
        std::vector<int64_t> result;

        // trial division for large part
        for (int p : primes) {
            if (n < size or n < (int64_t)p * p) {
                break;
            }
            while (n % p == 0) {
                n /= p;
                result.push_back(p);
            }
        }

        // small part
        if (n == 1) {
            // nop
        } else if (n < size) {
            while (n != 1) {
                result.push_back(sieve[n]);
                n /= sieve[n];
            }
        } else {
            result.push_back(n);
        }

        assert (std::is_sorted(ALL(result)));
        return result;
    }

    std::vector<int64_t> list_all_factors(int64_t n) const {
        auto p = list_prime_factors(n);
        std::vector<int64_t> d;
        d.push_back(1);
        for (int l = 0; l < p.size(); ) {
            int r = l + 1;
            while (r < p.size() and p[r] == p[l]) ++ r;
            int n = d.size();
            REP (k1, r - l) {
                REP (k2, n) {
                    d.push_back(d[d.size() - n] * p[l]);
                }
            }
            l = r;
        }
        return d;
    }

    /**
     * @note O(1) if n < size; O(sqrt n) if size <= n < size^2
     */
    bool is_prime(int64_t n) const {
        assert (1 <= n and n < (int64_t)size * size);
        if (n < size) {
            return sieve[n] == n;
        }
        for (int p : primes) {
            if (n < (int64_t)p * p) {
                break;
            }
            if (n % p == 0) {
                return false;
            }
        }
        return true;
    }
};
