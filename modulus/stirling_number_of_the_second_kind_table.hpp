#pragma once
#include <cassert>
#include <vector>
#include "../utils/macros.hpp"
#include "../modulus/mint.hpp"

/**
 * @brief the Stirling number of the second kind (前処理 $O(NK)$ + $O(1)$)
 * @description the number of ways of partitioning a set of n elements into k nonempty sets
 * @see http://mathworld.wolfram.com/StirlingNumberoftheSecondKind.html
 * @see http://oeis.org/A008277
 * @see https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0
 */
template <int MOD>
mint<MOD> stirling_number_of_the_second_kind_table(int n, int k) {
    assert (0 <= n and 0 <= k);
    if (n  < k) return 0;
    if (n == k) return 1;
    if (k == 0) return 0;
    static std::vector<std::vector<mint<MOD> > > memo;
    if (memo.size() <= n) {
        int l = memo.size();
        memo.resize(n + 1);
        REP3 (i, l, n + 1) {
            memo[i].resize(i);
        }
    }
    if (memo[n][k]) return memo[n][k];
    return memo[n][k] =
        stirling_number_of_the_second_kind_table<MOD>(n - 1, k - 1) +
        stirling_number_of_the_second_kind_table<MOD>(n - 1, k) * k;
}
