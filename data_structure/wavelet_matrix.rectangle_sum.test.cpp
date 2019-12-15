#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "data_structure/wavelet_matrix.hpp"
#include "utils/macros.hpp"
#include <cstdint>
#include <cstdio>
#include <numeric>
using namespace std;

int main() {
    // read points
    int n, q; scanf("%d%d", &n, &q);
    vector<int> x(n);
    vector<int> y(n);
    vector<long long> w(n);
    REP (i, n) {
        scanf("%d%d%lld", &x[i], &y[i], &w[i]);
    }

    // construct wavlet matrices
    constexpr int BITS = 30;
    vector<int> order(n);
    iota(ALL(order), 0);
    sort(ALL(order), [&](int i, int j) {
        return x[i] < x[j];
    });
    constexpr int WIDTH = 16;
    constexpr int HEIGHT = 8;
    array<vector<int>, HEIGHT> x1;
    array<vector<int>, HEIGHT> y1;
    for (int i : order) {
        long long w_i = w[i];
        for (int k = 0; w_i; ++ k) {
            assert (k < HEIGHT);
            REP (j, w_i % WIDTH) {
                x1[k].push_back(x[i]);
                y1[k].push_back(y[i]);
            }
            w_i /= WIDTH;
        }
    }
    array<wavelet_matrix<BITS>, HEIGHT> wm;
    REP (k, HEIGHT) {
        wm[k] = wavelet_matrix<BITS>(y1[k]);
    }

    // answer to queries
    REP (i, q) {
        int lx, ly, rx, ry; scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        long long answer = 0;
        REP_R (k, HEIGHT) {
            int l = lower_bound(ALL(x1[k]), lx) - x1[k].begin();
            int r = lower_bound(ALL(x1[k]), rx) - x1[k].begin();
            int a = ly;
            int b = ry;
            answer *= WIDTH;
            answer += wm[k].range_frequency(l, r, a, b);
        }
        printf("%lld\n", answer);
    }
    return 0;
}
