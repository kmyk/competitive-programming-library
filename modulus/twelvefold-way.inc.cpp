/**
 * @brief twelvefold way
 * @sa https://en.wikipedia.org/wiki/Twelvefold_way
 * @sa https://mathtrain.jp/twelveway
 * @note the numbers of mapprings f putting N balls into K boxes
 */


/**
 * @brief labeled-N labeled-K any-f
 * @note the number of f for all f : N \to K
 * @note O(log K)
 */
template <int MOD>
mint<MOD> twelvefold_lla(int n, int k) {
    return mint<MOD>(k).pow(n);
}

/**
 * @brief labeled-N labeled-K injective-f
 * @note the number of f for injective f : N \rightarrowtail K
 * @note O(1) with precomputation O(N + K)
 */
template <int MOD>
mint<MOD> twelvefold_lli(int n, int k) {
    if (n > k) return 0;
    return permute<MOD>(k, n);
}

/**
 * @brief labeled-N labeled-K surjective-f
 * @note the number of f for surjective f : N \twoheadrightarrow K
 * @note O(NK) or O(N \log K)
 */
template <int MOD>
mint<MOD> twelvefold_lls(int n, int k) {
    return stirling_number_of_the_second_kind<MOD>(n, k) * fact(k);
}


/**
 * @brief unlabeled-N labeled-K any-f
 * @note the number of f \circ S_N for any f : N \to K
 * @note O(1) with precomputation O(N + K)
 */
template <int MOD>
mint<MOD> twelvefold_ula(int n, int k) {
    return choose<MOD>(n + k - 1, n);
}

/**
 * @brief unlabeled-N labeled-K injective-f
 * @note the number of f \circ S_N for injective f : N \rightarrowtail K
 * @note O(1) with precomputation O(K)
 */
template <int MOD>
mint<MOD> twelvefold_uli(int n, int k) {
    if (n > k) return 0;
    return choose<MOD>(k, n);
}

/**
 * @brief unlabeled-N labeled-K surjective-f
 * @note the number of f \circ S_N for surjective f : N \twoheadrightarrow K
 * @note O(1) with precomputation O(N)
 */
template <int MOD>
mint<MOD> twelvefold_uls(int n, int k) {
    if (n < k) return 0;
    return choose<MOD>(n - 1, n - k);
}


/**
 * @brief labeled-N unlabeled-K any-f
 * @note the number of S_K \circ f for all f : N \to K
 */
template <int MOD>
mint<MOD> twelvefold_lua(int n, int k) {
    return binary_bell_number(n, k);
}

/**
 * @brief labeled-N unlabeled-K injective-f
 * @note the number of S_K \circ f for injective f : N \rightarrowtail K
 * @note O(1)
 */
template <int MOD>
mint<MOD> twelvefold_lui(int n, int k) {
    if (n > k) return 0;
    return 1;
}

/**
 * @brief labeled-N unlabeled-K surjective-f
 * @note the number of S_K \circ f for surjective f : N \twoheadrightarrow K
 * @note O(NK) or O(N \log K)
 */
template <int MOD>
mint<MOD> twelvefold_lus(int n, int k) {
    return stirling_number_of_the_second_kind<MOD>(n, k);
}


/**
 * @brief unlabeled-N unlabeled-K injective-f
 * @note the number of S_K \circ f \circ S_N for injective f : N \rightarrowtail K
 * @note O(1)
 */
template <int MOD>
mint<MOD> twelvefold_uui(int n, int k) {
    if (n > k) return 0;
    return 1;
}
