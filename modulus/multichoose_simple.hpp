#pragma once
#include <cassert>
#include "../modulus/mint.hpp"
#include "../modulus/choose_simple.hpp"

/**
 * @brief 重複組合せ ${} _ n H _ r = {} _ {n + r - 1} C _ r$ (愚直 $O(r)$)
 */
template <int32_t MOD>
mint<MOD> multichoose_simple(int64_t n, int32_t r) {
    assert (0 <= n and 0 <= r);
    if (n == 0 and r == 0) return 1;
    return choose_simple<MOD>(n + r - 1, r);
}
