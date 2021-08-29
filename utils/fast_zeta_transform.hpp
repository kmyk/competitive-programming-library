#pragma once
#include <cassert>
#include <vector>
#include "../number/primes.hpp"
#include "../utils/macros.hpp"

/**
 * @brief upward fast zeta transform on primes
 * @note $O(n \log n)$ (or, $O(n \log \log n)$ ???)
 * @return $b_i = \sum _ {i \mid j} a_j$
 * @note $a_0, b_0$ means the greatest element
 */
template <class CommutativeSemiring>
std::vector<typename CommutativeSemiring::value_type> upward_fast_zeta_transform_on_primes(std::vector<typename CommutativeSemiring::value_type> a, const prepared_primes & primes, const CommutativeSemiring & mon = CommutativeSemiring()) {
    assert (a.size() <= primes.size);
    if (a.empty()) return a;
    for (int64_t p : primes.primes) {
        REP3R (x, 1, (a.size() - 1) / p + 1) {
            a[x] = mon.mult(a[x], a[p * x]);
        }
    }
    REP3 (x, 1, a.size()) {
        a[x] = mon.mult(a[x], a[0]);
    }
    return a;
}
