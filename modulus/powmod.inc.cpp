/**
 * @param m must be a positive integer
 * @note O(log y)
 */
ll powmod(ll x, ll y, ll m) {
    assert (0 <= x and x < m);
    assert (0 <= y);
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % m;
        x = x * x % m;
    }
    return z;
}
/**
 * @param p must be a prime
 * @note O(log p)
 */
ll modinv(ll x, ll p) {
    assert (x % p != 0);
    return powmod(x, p - 2, p);
}
