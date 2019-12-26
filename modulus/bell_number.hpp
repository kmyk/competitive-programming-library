#pragma once
#include "modulus/mint.hpp"
#include "modulus/choose.hpp"
#include "modulus/stirling_number_of_the_second_kind.hpp"

/**
 * @brief the Bell number
 * @description the number of ways a set of n elements can be partitioned into nonempty subsets
 * @see http://mathworld.wolfram.com/BellNumber.html
 * @see https://oeis.org/A110
 * @see https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0
 * @tparam MOD must be a prime
 * @note $O(nk)$, memoized
 */
template <int MOD>
mint<MOD> bell_number(int n, int k) {
    static std::vector<std::vector<mint<MOD> > > memo;
    if (memo.size() <= n) {
        memo.resize(n + 1);
    }
    if (memo[n].empty()) {
        memo[n].push_back(0);
    }
    while (memo[n].size() <= k) {
        int i = memo[n].size();
        memo[n].push_back(memo[n].back() + stirling_number_of_the_second_kind<MOD>(n, i));
    }
    return memo[n][k];
}

template <int MOD>
mint<MOD> unary_bell_number(int n) {
    return bell_number<MOD>(n, n);
}
