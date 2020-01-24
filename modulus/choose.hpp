#pragma once
#include <cassert>
#include "modulus/mint.hpp"
#include "modulus/factorial.hpp"

/**
 * @note O(n log n) at first time, otherwise O(1)
 */
template <int32_t MOD>
mint<MOD> choose(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) * inv_fact<MOD>(n - r) * inv_fact<MOD>(r);
}
