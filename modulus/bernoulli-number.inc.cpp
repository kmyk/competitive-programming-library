/**
 * @tparam MOD must be a prime
 * @note O(n^2)
 * @see https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0
 */
template <int MOD>
int bernoulli_number(int i) {
    static vector<int> dp(1, 1);
    while (dp.size() <= i) {
        int n = dp.size();
        ll acc = 0;
        REP (k, n) {
            acc += choose<MOD>(n + 1, k) *(ll) dp[k] % MOD;
        }
        acc %= MOD;
        (acc *= modinv(n + 1, MOD)) %= MOD;
        acc = (acc == 0 ? 0 : MOD - acc);
        dp.push_back(acc);
    }
    return dp[i];
}
unittest {
    constexpr int MOD = 1e9 + 7;
    assert (bernoulli_number<MOD>(0) == 1);
    assert (bernoulli_number<MOD>(1) == (MOD - 1ll) * modinv(2, MOD) % MOD);
    assert (bernoulli_number<MOD>(2) == modinv(6, MOD));
    assert (bernoulli_number<MOD>(3) == 0);
    assert (bernoulli_number<MOD>(4) == (MOD - 1ll) * modinv(30, MOD) % MOD);
    assert (bernoulli_number<MOD>(26) == 8553103ll * modinv(6, MOD) % MOD);
}

/**
 * @brief 0^k + 1^k + 2^k + ... + (n - 1)^k
 * @see https://yukicoder.me/problems/no/665
 * @note n can be >= MOD
 */
template <int MOD>
int sum_of_pow(ll n, int k) {
    ll acc = 0;
    REP (j, k + 1) {
        acc += choose<MOD>(k + 1, j) *(ll) bernoulli_number<MOD>(j) % MOD *(ll) powmod(n % MOD, k - j + 1, MOD) % MOD;
    }
    acc %= MOD;
    (acc *= modinv(k + 1, MOD)) %= MOD;
    return acc;
}
