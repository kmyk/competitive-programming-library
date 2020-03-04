#pragma once
#include "modulus/mint.hpp"
#include "modulus/choose.hpp"
#include "modulus/stirling_number_of_the_second_kind_table.hpp"

/**
 * @brief the Bell number (前処理 $O(NK)$ + $O(1)$)
 * @description the number of ways a set of n elements can be partitioned into nonempty subsets
 * @see http://mathworld.wolfram.com/BellNumber.html
 * @see https://oeis.org/A110
 * @see https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0
 */
template <int PRIME>
mint<PRIME> bell_number(int n, int k) {
    static std::vector<std::vector<mint<PRIME> > > memo;
    if (memo.size() <= n) {
        memo.resize(n + 1);
    }
    if (memo[n].empty()) {
        memo[n].push_back(0);
    }
    while (memo[n].size() <= k) {
        int i = memo[n].size();
        memo[n].push_back(memo[n].back() + stirling_number_of_the_second_kind_table<PRIME>(n, i));
    }
    return memo[n][k];
}

template <int PRIME>
mint<PRIME> unary_bell_number(int n) {
    return bell_number<PRIME>(n, n);
}
