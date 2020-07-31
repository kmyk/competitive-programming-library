#define PROBLEM "https://yukicoder.me/problems/no/1145"
#include <cstdio>
#include <vector>
#include "utils/macros.hpp"
#include "modulus/mint.hpp"
#include "modulus/formal_power_series.hpp"
using namespace std;

constexpr int MOD = 998244353;
vector<mint<MOD> > solve(int n, int m, const vector<mint<MOD> > & a) {
    auto go = [&](auto && go, int l, int r) {
        if (r - l == 0) return formal_power_series<mint<MOD> >{ 1 };
        if (r - l == 1) return formal_power_series<mint<MOD> >{ 1, - a[l] };
        int m_ = (l + r) / 2;
        return (go(go, l, m_) * go(go, m_, r)).modulo_x_to(m + 2);
    };
    vector<mint<MOD> > ans = (- go(go, 0, n).log(m + 2)).data();
    ans.resize(m + 1);
    REP3 (k, 1, m + 1) {
        ans[k] *= k;
    }
    return ans;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<mint<MOD> > a(n);
    REP (i, n) {
        scanf("%d", &a[i].value);
    }
    auto ans = solve(n, m, a);
    assert (ans[0] == 0);
    REP (i, m) {
        printf("%d%c", ans[i + 1].value, i + 1 < m ? ' ' : '\n');
    }
    return 0;
}
