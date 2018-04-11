/**
 * @tparam MOD must be a prime
 * @note O(n log n) at first time, otherwise O(1)
 */
template <int MOD>
int choose(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) *(ll) inv_fact<MOD>(n - r) % MOD *(ll) inv_fact<MOD>(r) % MOD;
}
template <int MOD>
int permute(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) *(ll) modinv(fact<MOD>(n - r), MOD) % MOD;
}
template <int MOD>
int multichoose(int n, int r) {
    assert (0 <= r and r <= n);
    if (n == 0 and r == 0) return 1;
    return choose<MOD>(n+r-1, r);
}
