ll fact(ll n) {
    static vector<ll> memo(1,1);
    if (memo.size() <= n) {
        int l = memo.size();
        memo.resize(n + 1);
        repeat_from (i,l,n+1) memo[i] = memo[i-1] * i % mod;
    }
    return memo[n];
}
ll ifact(ll n) {
    static vector<ll> memo(1,1);
    if (memo.size() <= n) {
        int l = memo.size();
        memo.resize(n + 1);
        repeat_from (i,l,n+1) memo[i] = inv(fact(i), mod);
    }
    return memo[n];
}
ll choose(ll n, ll r) { // O(n) at first time, otherwise O(1)
    r = min(r, n - r);
    return fact(n) * ifact(n-r) % mod * ifact(r) % mod;
}

ll choose(ll n, int r, ll p) { // O(r) for a prime p
    ll acc = 1;
    repeat (i,r) acc = acc * (n-i) % p * inv(i+1, p) % p;
    return acc;
}
