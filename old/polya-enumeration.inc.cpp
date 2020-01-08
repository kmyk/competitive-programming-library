/**
 * @note using Polya enumeration theorem
 * @note factorization + O(d(n)^2 + sqrt n)
 */
template <int MOD>
mint<MOD> count_cycle_coloring(int n, int k) {
    auto primes = list_primes(sqrt(n) + 3);
    map<ll, int> factors = prime_factorize(n, primes);
    vector<ll> divs = list_divisors(n, primes);
    mint<MOD> cnt = 0;
    for (ll div : divs) {
        ll e = div;  // Euler's phi of div
        for (auto it : factors) {
            int p = it.first;
            if (div % p == 0) {
                e = e / p * (p - 1);
            }
        }
        cnt += mint<MOD>(k).pow(n / div) * e;
    }
    return cnt / n;
}

unittest {
    constexpr int MOD = 1e9 + 7;
    assert (count_cycle_coloring<MOD>(2, 10).value == 55);
    assert (count_cycle_coloring<MOD>(4, 10).value == 2530);
    assert (count_cycle_coloring<MOD>(4, 2).value == 6);
    assert (count_cycle_coloring<MOD>(1000000000, 1000000000).value == 898487047);
}
