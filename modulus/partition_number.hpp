#pragma once
#include "modulus/mint.hpp"
#include "modulus/choose.hpp"
#include "modulus/stirling_number_of_the_second_kind_table.hpp"

/**
 * @brief the partition number (前処理 $O(NK)$ + $O(1)$)
 * @description the number of non-decreasing sequences with the length k which the sum is n
 */
template <int MOD>
mint<MOD> partition_number(int n, int k) {
    static std::vector<std::vector<mint<MOD> > > memo;
    if (memo.size() <= n) {
        memo.resize(n + 1);
    }
    while (memo[n].size() <= k) {
        if (n == 0) {
            memo[0].resize(k + 1, 1);
        } else if (memo[n].empty()) {
            memo[n].push_back(0);
        } else {
            int j = memo[n].size();
            auto a = (n - j >= 0 ? partition_number<MOD>(n - j, j) : 0);
            auto b = (j - 1 >= 0 ? partition_number<MOD>(n, j - 1) : 0);
            memo[n].push_back(a + b);
        }
    }
    return memo[n][k];
}

template <int MOD>
mint<MOD> unary_partition_number(int n) {
    return partition_number<MOD>(n, n);
}

