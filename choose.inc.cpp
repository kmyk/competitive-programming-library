ll choose(ll n, ll r) { // O(n), O(1)
    static vector<ll> fact(1,1);
    static vector<ll> ifact(1,1);
    if (fact.size() <= n) {
        int l = fact.size();
        fact.resize( n + 1);
        ifact.resize(n + 1);
        repeat_from (i,l,n+1) {
            fact[i]  = fact[i-1] * i % mod;
            ifact[i] = inv(fact[i], mod);
        }
    }
    r = min(r, n - r);
    return fact[n] * ifact[n-r] % mod * ifact[r] % mod;
}
