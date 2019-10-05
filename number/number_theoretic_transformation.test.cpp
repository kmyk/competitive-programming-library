#include "number/number_theoretic_transformation.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

constexpr int MOD = 998244353;
int main() {
    // input
    int n, m; cin >> n >> m;
    vector<mint<MOD> > a(n);
    REP (i, n) {
        cin >> a[i];
    }
    vector<mint<MOD> > b(m);
    REP (j, m) {
        cin >> b[j];
    }

    // solve
    vector<mint<MOD> > c = convolution(a, b);

    // output
    REP (i, n + m - 1) {
        if (i) cout << ' ';
        cout << c[i];
    }
    cout << endl;
    return 0;
}
