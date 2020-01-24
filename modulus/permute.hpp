#pragma once
#include <cassert>
#include "modulus/mint.hpp"
#include "modulus/factorial.hpp"

template <int32_t MOD>
mint<MOD> permute(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) * inv_fact<MOD>(n - r);
}
