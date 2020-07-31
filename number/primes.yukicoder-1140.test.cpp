#define PROBLEM "https://yukicoder.me/problems/no/1140"
#include <cstdio>
#include "utils/macros.hpp"
#include "number/primes.hpp"

prepared_primes primes(1e6 + 100);

int solve(long long a, int p) {
    if (not primes.is_prime(p)) return -1;
    if (a % p == 0) return 0;
    return 1;
}

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        long long a; int p; scanf("%lld%d", &a, &p);
        auto ans = solve(a, p);
        printf("%d\n", ans);
    }
    return 0;
}
