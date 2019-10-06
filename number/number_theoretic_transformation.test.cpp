#include "number/number_theoretic_transformation.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <cstdio>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

constexpr int MOD = 998244353;
int main() {
    // input
    int n, m; cin >> n >> m;
    vector<mint<MOD> > a(n);
    REP (i, n) {
        scanf("%d", &a[i].value);
    }
    vector<mint<MOD> > b(m);
    REP (j, m) {
        scanf("%d", &b[j].value);
    }

    // solve
    vector<mint<MOD> > c = convolution(a, b);

    // output
    REP (i, n + m - 1) {
        printf("%d ", c[i].value);
    }
    printf("\n");
    return 0;
}
