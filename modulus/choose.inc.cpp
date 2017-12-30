template <int MOD>
int fact(int n) {
    static vector<int> memo(1, 1);
    while (n >= memo.size()) {
        memo.push_back(memo.back() *(ll) memo.size() % MOD);
    }
    return memo[n];
}
/**
 * @tparam MOD must be a prime
 */
template <int MOD>
int inv_fact(int n) {
    static vector<int> memo(1, 1);
    while (n >= memo.size()) {
        memo.push_back(memo.back() *(ll) modinv(memo.size(), MOD) % MOD);
    }
    return memo[n];
}

/**
 * @tparam MOD must be a prime
 * @note O(n log n) at first time, otherwise O(1)
 */
template <int MOD>
int choose(int n, int r) {
    if (n < r) return 0;
    return fact<MOD>(n) *(ll) inv_fact<MOD>(n - r) % MOD *(ll) inv_fact<MOD>(r) % MOD;
}
template <int MOD>
int permute(int n, int r) {
    if (n < r) return 0;
    return fact<MOD>(n) *(ll) modinv(fact<MOD>(n - r), MOD) % MOD;
}
template <int MOD>
int multichoose(int n, int r) {
    if (n == 0 and r == 0) return 1;
    return choose<MOD>(n+r-1, r);
}
