/**
 * @brief the Bell number
 * @description the number of ways a set of n elements can be partitioned into nonempty subsets
 * @see http://mathworld.wolfram.com/BellNumber.html
 * @see https://oeis.org/A110
 * @see https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0
 * @note O(n^2)
 */
template <int MOD = mod>
int bell_number(int n) {
    int acc = 0;
    REP (k, n + 1) {
        acc += stirling_number_of_the_second_kind<MOD>(n, k);
        if (acc >= MOD) acc -= MOD;
    }
    return acc;
}
