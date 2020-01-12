#include "modulus/number_theoretic_transformation_with_garner.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <vector>
#include "utils/macros.hpp"
#include "hack/fastio.hpp"

constexpr int MOD = 1000000007;
int main() {
    // input
    int n = in<uint32_t>();
    int m = in<uint32_t>();
    std::vector<mint<MOD> > a(n);
    REP (i, n) {
        a[i].value = in<uint32_t>();
    }
    std::vector<mint<MOD> > b(m);
    REP (j, m) {
        b[j].value = in<uint32_t>();
    }

    // solve
    std::vector<mint<MOD> > c = ntt_convolution(a, b);

    // output
    REP (i, n + m - 1) {
        out<uint32_t>(c[i].value);
        out<char>(' ');
    }
    out<char>('\n');
    return 0;
}
