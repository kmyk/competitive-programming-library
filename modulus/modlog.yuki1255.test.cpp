#define PROBLEM "https://yukicoder.me/problems/no/1255"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <utility>
#include "utils/macros.hpp"
#include "modulus/modinv.hpp"
#include "modulus/modlog.hpp"
using namespace std;

int64_t solve(int64_t n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    assert (n >= 3);

    int64_t m = 2 * n - 1;
    auto f = [&](int64_t aq, int64_t ar, int64_t bq, int64_t br) {
        int64_t cq = aq + bq;
        int64_t cr = ar + br;
        if (cr >= m) {
            cr -= m;
            cq += 1;
        }
        return make_pair(cq, cr);
    };

    int64_t k = modlog(2, modinv(2, m), m) + 1;
    int64_t q0 = 0;
    int64_t r0 = 0;
    int64_t q1 = 0;
    int64_t r1 = 1;
    REP (i, 60) {
        if (k & (1ll << i)) {
            tie(q0, r0) = f(q0, r0, q1, r1);
        }
        tie(q1, r1) = f(q1, r1, q1, r1);
    }
    return k + q0;
}

int main() {
    int t; cin >> t;
    while (t --) {
        int64_t n; cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
