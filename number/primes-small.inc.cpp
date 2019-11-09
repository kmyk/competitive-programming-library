/**
 * @brief enumerate primes in [2, n) with O(n log log n)
 */
vector<int> list_primes(int n) {
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i *(int64_t) i < n; ++ i)
        if (is_prime[i])
            for (int k = 2 * i; k < n; k += i)
                is_prime[k] = false;
    vector<int> primes;
    for (int i = 2; i < n; ++ i)
        if (is_prime[i])
            primes.push_back(i);
    return primes;
}

/**
 * @note O(sqrt n)
 */
bool is_prime(int64_t n, vector<int> const & primes) {
    if (n == 1) return false;
    for (int p : primes) {
        if (n < (int64_t)p * p) break;
        if (n % p == 0) return true;
    }
    return false;
}

/**
 * @note the last number of primes must be >= sqrt n
 */
map<int64_t, int> prime_factorize(int64_t n, vector<int> const & primes) {
    map<int64_t, int> result;
    for (int p : primes) {
        if (n < p *(int64_t) p) break;
        while (n % p == 0) {
            result[p] += 1;
            n /= p;
        }
    }
    if (n != 1) result[n] += 1;
    return result;
}

/**
 * @note if n < 10^9, d(n) < 1200 + a
 */
vector<int64_t> list_divisors_from_prime_factors(int64_t n, vector<int64_t> const & prime_factors) {
    vector<int64_t> result;
    result.push_back(1);
    for (auto it : prime_factors) {
        int64_t p; int k; tie(p, k) = it;
        int size = result.size();
        REP (y, k) {
            REP (x, size) {
                result.push_back(result[y * size + x] * p);
            }
        }
    }
    return result;
}

/**
 * @brief fully factorize all numbers in [0, n) with O(n log log n)
 */
vector<vector<int> > extended_sieve_of_eratosthenes(int n) {
    vector<vector<int> > prime_factors(n + 1);
    REP3 (i, 2, n) {
        if (prime_factors[i].empty()) {
            for (int k = i; k < n; k += i) {
                prime_factors[k].push_back(i);
            }
        }
    }
    return prime_factors;
}

/**
 * @note O(sqrt(n))
 */
map<int64_t, int> prime_factorize1(int64_t n) {
    map<int64_t, int> factors;
    for (int p : { 2, 3, 5 }) {
        while (n % p == 0) {
            n /= p;
            ++ factors[p];
        }
    }
    for (int p = 6; (int64_t)p * p <= n; p += 6) {
        for (int q : { p + 1, p + 5 }) {
            while (n % q == 0) {
                n /= q;
                ++ factors[q];
            }
        }
    }
    if (n) {
        ++ factors[n];
    }
    return factors;
}
