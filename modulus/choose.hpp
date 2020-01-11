#pragma once
#include <cassert>
#include "modulus/mint.hpp"
#include "modulus/factorial.hpp"
#include "utils/macros.hpp"

/**
 * @note O(n log n) at first time, otherwise O(1)
 */
template <int32_t MOD>
mint<MOD> choose(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) * inv_fact<MOD>(n - r) * inv_fact<MOD>(r);
}
template <int32_t MOD>
mint<MOD> permute(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) * inv_fact<MOD>(n - r);
}
template <int32_t MOD>
mint<MOD> multichoose(int n, int r) {
    assert (0 <= n and 0 <= r);
    if (n == 0 and r == 0) return 1;
    return choose<MOD>(n + r - 1, r);
}
