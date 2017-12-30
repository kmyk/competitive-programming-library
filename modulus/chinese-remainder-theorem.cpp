pair<ll, ll> crt(pair<ll, ll> eqn1, pair<ll, ll> eqn2) {
    ll x1, m1; tie(x1, m1) = eqn1;
    ll x2, m2; tie(x2, m2) = eqn2;
    ll x = x1 + m1 * (x2 - x1) * modinv(m1, m2);
    ll m = m1 * m2;
    return { (x % m + m) % m, m };
}
