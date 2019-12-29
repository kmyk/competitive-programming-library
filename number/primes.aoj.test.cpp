#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "number/primes.hpp"
#include <cassert>
#include <cstdio>

int main() {
    int n; scanf("%d", &n);
    prepared_primes primes(1e6 + 3);
    int cnt = 0;
    REP (i, n) {
        int a; scanf("%d", &a);
        cnt += primes.is_prime(a);
    }
    printf("%d\n", cnt);
    return 0;
}
