// http://yukicoder.me/problems/1048
// http://arc012.contest.atcoder.jp/submissions/749180
ll powmod(ll x, ll y, ll p) { // O(log y)
    assert (y >= 0);
    x %= p; if (x < 0) x += p;
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % p;
        x = x * x % p;
    }
    return z;
}

// http://yukicoder.me/submissions/97173
ll inv(ll x, ll p) { // p must be a prime, O(log p)
    assert ((x % p + p) % p != 0);
    return powmod(x, p-2, p);
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

pair<int,int> extgcd(int a, int b) {
    if (b == 0) return { 1, 0 };
    int na, nb; tie(na, nb) = extgcd(b, a % b);
    return { nb, na - a/b * nb };
}
int modinv(int a, int n) { // a and n must be relatively prime, O(log n)
    return (extgcd(a, n).first % n + n) % n;
}
