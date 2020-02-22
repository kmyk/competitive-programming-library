#pragma once
#include <cassert>
#include "modulus/mint.hpp"
#include "modulus/factorial.hpp"

/**
 * @brief 重複組合せ ${} _ n H _ r = {} _ {n + r - 1} C _ r$ (前処理 $O(n)$ + $O(1)$)
 */
template <int32_t MOD>
mint<MOD> multichoose(int n, int r) {
    assert (0 <= n and 0 <= r);
    if (n == 0 and r == 0) return 1;
    return choose<MOD>(n + r - 1, r);
}
