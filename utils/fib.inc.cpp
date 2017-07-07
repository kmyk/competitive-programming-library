int fib(ll n, int mod) {
    assert (3 * pow(mod, 2) < pow(2, 63));
    assert (n >= 0);
    if (n <= 1) return n;
    int a = 0;
    int b = 1;
    ll i = 1ll << (63 - __builtin_clzll(n) - 1);
    for (; i; i >>= 1) {
        int na = (a *(ll) a + b *(ll) b) % mod;
        int nb = (2ll * a + b) * b % mod;
        a = na;
        b = nb;
        if (n & i) {
            int c = a + b; if (c >= mod) c -= mod;
            a = b;
            b = c;
        }
    }
    return b;
}
