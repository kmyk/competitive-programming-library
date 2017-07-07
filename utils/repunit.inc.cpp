int repunit(ll n, int mod) { // O(log n)
    ll y = 0;
    ll x = 1;
    for (ll i = 1; i <= n; i <<= 1) {
        if (n & i) y = (y * powmod(10, i, mod) % mod + x) % mod;
        x = (x * powmod(10, i, mod) % mod + x) % mod;
    }
    return y;
}
