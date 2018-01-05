/**
 * @brief extended gcd
 * @description for given a and b, find x, y and gcd(a, b) such that ax + by = 1
 * @note O(log n)
 * @see https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466
 */
tuple<ll, ll, ll> extgcd(ll a, ll b) {
    ll x = 0, y = 1;
    for (ll u = 1, v = 0; a; ) {
        ll q = b / a;
        swap(x -= q * u, u);
        swap(y -= q * v, v);
        swap(b -= q * a, a);
    }
    return make_tuple(x, y, d);
}
unittest {
    random_device device;
    default_random_engine gen(device());
    REP (iteration, 1000) {
        ll a = uniform_int_distribution<ll>(1, 10000)(gen);
        ll b = uniform_int_distribution<ll>(1, 10000)(gen);
        ll x, y, d; tie(x, y, d) = extgcd(a, b);
        assert (a * x + b * y == 1);
        assert (d == __gcd(a, b));
    }
}

/**
 * @note recursive version (slow)
 */
pair<int, int> extgcd_recursive(int a, int b) {
    if (b == 0) return { 1, 0 };
    int na, nb; tie(na, nb) = extgcd(b, a % b);
    return { nb, na - a/b * nb };
}

/**
 * @note x and n must be relatively prime
 * @note O(log n)
 */
ll modinv(ll x, ll n) {
    assert (1 <= x and x < n);
    ll y = get<0>(extgcd(x, n)) % n;
    return y >= 0 ? y : y + n;
}
