#pragma once
#include <cassert>
#include "modulus/mint.hpp"
#include "utils/macros.hpp"

/**
 * @brief 組合せ ${} _ n C _ r$ (愚直 $O(r)$)
 */
template <int32_t MOD>
mint<MOD> choose_simple(int n, int r) {
    assert (0 <= r and r <= n);
    mint<MOD> num = 1;
    mint<MOD> den = 1;
    REP (i, r) {
        num *= n - i;
        den *= i + 1;
    }
    return num / den;
}
