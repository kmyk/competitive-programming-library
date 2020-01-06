#include "modulus/number_theoretic_transformation.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <vector>
#include "utils/macros.hpp"
#include "utils/fastio_scanner.hpp"
#include "utils/fastio_printer.hpp"

constexpr int MOD = 998244353;
int main() {
    scanner sc;
    printer pr;

    // input
    int n = sc.get<int32_t>();
    int m = sc.get<int32_t>();
    std::vector<mint<MOD> > a(n);
    REP (i, n) {
        a[i].value = sc.get<int32_t>();
    }
    std::vector<mint<MOD> > b(m);
    REP (j, m) {
        b[j].value = sc.get<int32_t>();
    }

    // solve
    std::vector<mint<MOD> > c = ntt_convolution(a, b);

    // output
    REP (i, n + m - 1) {
        pr.put(c[i].value);
        pr.put<char>(' ');
    }
    pr.put<char>('\n');
    return 0;
}
