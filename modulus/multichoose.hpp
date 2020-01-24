#pragma once
#include <cassert>
#include "modulus/mint.hpp"
#include "modulus/factorial.hpp"

template <int32_t MOD>
mint<MOD> multichoose(int n, int r) {
    assert (0 <= n and 0 <= r);
    if (n == 0 and r == 0) return 1;
    return choose<MOD>(n + r - 1, r);
}
