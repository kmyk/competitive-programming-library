#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "number/primes.hpp"
#include <cassert>
#include <iostream>

int main() {
    int n; std::cin >> n;
    prepared_primes primes(1e6 + 3);
    int cnt = 0;
    REP (i, n) {
        int a; std::cin >> a;
        cnt += primes.is_prime(a);
    }
    std::cout << cnt << std::endl;
    return 0;
}
