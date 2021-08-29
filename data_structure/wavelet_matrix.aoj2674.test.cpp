#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"
#include "../data_structure/wavelet_matrix.hpp"
#include "../utils/macros.hpp"
#include <cstdio>
#include <numeric>
using namespace std;

int main() {
    constexpr int BITS = 30;
    constexpr int MIN_X = -1e8;
    constexpr int MAX_X = 1e8;

    // read a sequence
    int d; scanf("%d", &d);
    vector<int> x(d);
    REP (i, d) {
        scanf("%d", &x[i]);
        x[i] -= MIN_X;
    }

    // construct a wavelet matrix
    wavelet_matrix<BITS> wm(x);

    // answer to queries
    int q; scanf("%d", &q);
    while (q --) {
        int l, r, e; scanf("%d%d%d", &l, &r, &e);
        -- l;
        int a = min(x[l], x[r - 1]);
        int b = max(x[l], x[r - 1]);
        int cnt = 0;
        cnt += wm.range_frequency(l, r, 0, max(0, a - e));
        cnt += wm.range_frequency(l, r, min(MAX_X - MIN_X + 1, b + e + 1), MAX_X - MIN_X + 1);
        printf("%d\n", cnt);
    }
    return 0;
}
