int legendre_symbol(int a, int p) {
    return powmod(a, (p - 1) / 2, p); // Euler's criterion
}
int modsqrt(int a, int p) {
    a %= p;
    if (a == 0) return 0;
    if (p == 2) return a;
    assert (p >= 3);
    if (legendre_symbol(a, p) != +1) return -1;
    int b = 1;
    while (legendre_symbol(b, p) == 1) {
        b += 1;
    }
    int e = 0;
    int m = p - 1;
    while (m % 2 == 0) {
        m /= 2;
        e += 1;
    }
    ll x = powmod(a, (m - 1) / 2, p);
    ll y = a * x % p * x % p;
    x = x * a % p;
    ll z = powmod(b, m, p);
    while (y != 1) {
        int j = 0;
        for (ll t = y; t != 1; t = t * t % p) ++ j;
        if (e <= j) return -1;
        z = powmod(z, 1ll << (e - j - 1), p);
        x = x * z % p;
        z = z * z % p;
        y = y * z % p;
        e = j;
    }
    assert (x * x % p == a);
    return x;
}

unittest {
    for (int p : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 1009, 1000000007 }) {
        repeat (a, min(p - 1, 42)) {
            if (legendre_symbol(a, p) == 1) {
                ll x = modsqrt(a, p);
                assert (x * x % p == a);
            }
        }
    }
}

// https://yukicoder.me/problems/no/551
vector<int> solve_modeqn(int a, int b, int c, int p) { // ax^2 + bx + c = 0 mod p
    int d = (b *(ll) b - 4ll * a * c) % p;
    if (d < 0) d += p;
    int w = modsqrt(d, p);
    if (w == -1) return vector<int>();
    vector<int> xs;
    xs.push_back((- b + w) *(ll) modinv(2 * a % p, p) % p);
    xs.push_back((- b - w) *(ll) modinv(2 * a % p, p) % p);
    if (xs[0] < 0) xs[0] += p;
    if (xs[1] < 0) xs[1] += p;
    whole(sort, xs);
    xs.erase(whole(unique, xs), xs.end());
    return xs;
}

