/**
 * @brief enumerate primes in [2, n) with O(n log log n)
 */
vector<int> list_primes(int n) {
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i *(ll) i < n; ++ i)
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
bool is_prime(ll n, vector<int> const & primes) {
    if (n == 1) return false;
    for (int p : primes) {
        if (n < (ll)p * p) break;
        if (n % p == 0) return true;
    }
    return false;
}

/**
 * @note the last number of primes must be >= sqrt n
 */
map<ll, int> prime_factorize(ll n, vector<int> const & primes) {
    map<ll, int> result;
    for (int p : primes) {
        if (n < p *(ll) p) break;
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
vector<ll> list_divisors_from_prime_factors(ll n, vector<ll> const & prime_factors) {
    vector<ll> result;
    result.push_back(1);
    for (auto it : prime_factors) {
        ll p; int k; tie(p, k) = it;
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
map<ll, int> prime_factorize1(ll n) {
    map<ll, int> factors;
    for (int p : { 2, 3, 5 }) {
        while (n % p == 0) {
            n /= p;
            ++ factors[p];
        }
    }
    for (int p = 6; (ll)p * p <= n; p += 6) {
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

/**
 * @note O(\sqrt{n})
 * @note about 1.0 sec for 10^5 queries with n < 10^10
 */
struct prepared_primes {
    int size;
    vector<int> sieve;
    vector<int> primes;

    prepared_primes(int size_)
        : size(size_) {

        sieve.resize(size);
        REP3 (p, 2, size) if (sieve[p] == 0) {
            primes.push_back(p);
            for (int k = p; k < size; k += p) {
                if (sieve[k] == 0) {
                    sieve[k] = p;
                }
            }
        }
    }

    vector<ll> prime_factorize(ll n) {
        assert (1 <= n and n < (ll)size * size);
        vector<ll> result;

        // trial division for large part
        for (int p : primes) {
            if (n < size or n < (ll)p * p) {
                break;
            }
            while (n % p == 0) {
                n /= p;
                result.push_back(p);
            }
        }

        // small part
        if (n == 1) {
            // nop
        } else if (n < size) {
            while (n != 1) {
                result.push_back(sieve[n]);
                n /= sieve[n];
            }
        } else {
            result.push_back(n);
        }

        assert (is_sorted(ALL(result)));
        return result;
    }

    bool is_prime(ll n) {
        return prime_factorize(n).size() == 1;
    }

    vector<ll> list_all_factors(ll n) {
        auto p = prime_factorize(n);
        vector<ll> d;
        d.push_back(1);
        for (int l = 0; l < p.size(); ) {
            int r = l + 1;
            while (r < p.size() and p[r] == p[l]) ++ r;
            int n = d.size();
            REP (k1, r - l) {
                REP (k2, n) {
                    d.push_back(d[d.size() - n] * p[l]);
                }
            }
            l = r;
        }
        return d;
    }
};
