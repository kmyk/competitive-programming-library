// http://yukicoder.me/problems/1048
// http://arc012.contest.atcoder.jp/submissions/749180
// http://yukicoder.me/submissions/96172
vector<int> sieve_of_eratosthenes(int n) { // enumerate primes in [2,n] with O(n log log n)
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= n; ++i)
        if (is_prime[i])
            for (int k = i+i; k <= n; k += i)
                is_prime[k] = false;
    vector<int> primes;
    for (int i = 2; i <= n; ++i)
        if (is_prime[i])
            primes.push_back(i);
    return primes;
}

// alternative interface
// http://yukicoder.me/submissions/96172
map<ll,int> prime_factrorize(ll n, vector<int> const & primes) {
    map<ll,int> result;
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

// http://yukicoder.me/submissions/96397
vector<ll> list_prime_factrors(ll n, vector<int> const & primes) {
    vector<ll> result;
    for (int p : primes) {
        if (n < p *(ll) p) break;
        while (n % p == 0) {
            result.push_back(p);
            n /= p;
        }
    }
    if (n != 1) result.push_back(n);
    return result;
}
