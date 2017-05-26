// https://kimiyuki.net/blog/2016/02/01/cf-gym-100753/
template <class Generator>
bool is_prime(ll n, int iteration, Generator & gen) { // miller-rabin primality test, O(k log n)
    assert (0 <= n);
    if (n == 2) return true;
    if (n == 1 or n % 2 == 0) return false;
    const ll d = (n-1) >> __builtin_ctzll(n-1); // remove trailing zeros
    uniform_int_distribution<ll> dist(1,n-2); // [l,r]
    repeat (dummy,iteration) {
        ll a = dist(gen);
        ll t = d;
        ll y = powi(a,t,n);
        while (t != n-1 and y != 1 and y != n-1) {
            y = muli(y, y, n);
            t *= 2;
        }
        if (y != n-1 and t % 2 == 0) return false;
    }
    return true;
}
bool is_prime(ll n) {
    static default_random_engine engine = default_random_engine(random_device()());
    return is_prime(n, 20, engine);
}
