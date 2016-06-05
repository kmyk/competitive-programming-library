// http://yukicoder.me/problems/1048
// http://arc012.contest.atcoder.jp/submissions/749180
ll powi(ll x, ll y, ll p) {
    assert (y >= 0);
    x = (x % p + p) % p;
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % p;
        x = x * x % p;
    }
    return z;
}

ll inv(ll x, ll p) {
    assert ((x % p + p) % p != 0);
    return powi(x, p-2, p);
}

template <typename T, typename F>
T powt(T x, ll y, T unit, F f) {
    T z = unit;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = f(z, x);
        x = f(x, x);
    }
    return z;
}
