template <int mod>
int fact(int n) {
    static vector<int> memo(1, 1);
    if (memo.size() <= n) {
        int l = memo.size();
        memo.resize(n+1);
        repeat_from (i, l, n+1) memo[i] = memo[i-1] *(ll) i % mod;
    }
    return memo[n];
}
/**
 * @note O(1) if memoize inv_fact
 */
template <int mod>
int choose(int n, int r) { // O(n) at first time, otherwise O(\log n)
    if (n < r) return 0;
    r = min(r, n - r);
    return fact<mod>(n) *(ll) inv(fact<mod>(n-r), mod) % mod *(ll) inv(fact<mod>(r), mod) % mod;
}
template <int mod>
int permute(int n, int r) {
    if (n < r) return 0;
    return fact<mod>(n) *(ll) inv(fact<mod>(n-r), mod) % mod;
}
template <int mod>
int multichoose(int n, int r) {
    if (n == 0 and r == 0) return 1;
    return choose<mod>(n+r-1, r);
}

ll choose(ll n, int r, ll p) { // O(r) for a prime p
    ll acc = 1;
    repeat (i,r) acc = acc * (n-i) % p * inv(i+1, p) % p;
    return acc;
}

ll choose(int n, int r) { // O(r) for small n
    ll acc = 1;
    repeat (i,r) acc = acc * (n-i) / (i+1);
    return acc;
}
