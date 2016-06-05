const int mod = 1e9+7;
ll fib(ll n) {
    static unordered_map<ll,int> memo;
    if (memo.count(n)) return memo[n];
    if (n == 0 or n== 1) return memo[n] = 1;
    ll a = n/2, b = (n+1)/2;
    return memo[n] = (fib(a)*(ll)fib(b) + fib(a-1)*(ll)fib(b-1)) % mod;
}

// use matrix operator *
// 2x faster then fib(n/2)*...
const ll mod = 1e9+7;
ll fib(ll n) {
    vector<vector<ll> > f(2, vector<ll>(2));
    vector<vector<ll> > e(2, vector<ll>(2));
    f[0][0] = f[1][1] = 1;
    e[0][0] = e[0][1] = e[1][0] = 1;
    for (ll i = 1; i <= n; i <<= 1) {
        if (n & i) f = f * e;
        e = e * e;
    }
    return f[0][0];
}
