#pragma once
#include <cassert>
#include <vector>
#include <map>
#include "../utils/macros.hpp"
#include "../modulus/mint.hpp"
#include "../modulus/factorial.hpp"
#include "../modulus/choose.hpp"

/**
 * @brief the Stirling number of the second kind ($O(K \log N)$)
 */
template <int MOD>
mint<MOD> stirling_number_of_the_second_kind_direct(int n, int k) {
    assert (0 <= n and 0 <= k);
    mint<MOD> acc = 0;
    REP (i, k + 1) {
        int parity = ((k - i) % 2 == 0 ? +1 : -1);
        acc += choose<MOD>(k, i) * mint<MOD>(i).pow(n) * parity;
    }
    return acc * inv_fact<MOD>(k);
}
