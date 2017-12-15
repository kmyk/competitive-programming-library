/**
 * @param p must be a prime
 * @note O(log y)
 */
ll powmod(ll x, ll y, ll p) {
    assert (0 <= x and x < p);
    assert (0 <= y);
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % p;
        x = x * x % p;
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
