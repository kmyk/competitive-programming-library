#include "../modulus/formal_power_series.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <cstdio>
#include <vector>
#include "../utils/macros.hpp"
using namespace std;

constexpr int MOD = 998244353;
int main() {
    // input
    int n; scanf("%d", &n);
    vector<mint<MOD> > a(n);
    REP (i, n) {
        scanf("%d", &a[i].value);
    }

    // solve
    vector<mint<MOD> > b = formal_power_series<mint<MOD> >(a).inv(n).data();
    b.resize(n);

    // output
    REP (i, n) {
        printf("%d ", b[i].value);
    }
    printf("\n");
    return 0;
}
