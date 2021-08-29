#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "../data_structure/wavelet_matrix.hpp"
#include "../utils/macros.hpp"
#include "../utils/coordinate_compression.hpp"
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

    // coordinate compression (not so important, 0.5 sec faster)
    coordinate_compression<int> compress_x(ALL(x));
    coordinate_compression<int> compress_y(ALL(y));
    constexpr int BITS = 18;
    assert (compress_x.data.size() < (1 << BITS));
    assert (compress_y.data.size() < (1 << BITS));
    REP (i, n) {
        x[i] = compress_x[x[i]];
        y[i] = compress_y[y[i]];
    }

    // construct wavlet matrices
    constexpr int WIDTH = 16;
    constexpr int HEIGHT = 8;
    vector<int> order(n);
    iota(ALL(order), 0);
    sort(ALL(order), [&](int i, int j) {
        return x[i] < x[j];
    });
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
    vector<int> lx(q), ly(q), rx(q), ry(q);
    REP (i, q) {
        scanf("%d%d%d%d", &lx[i], &ly[i], &rx[i], &ry[i]);
        lx[i] = compress_x[lx[i]];
        rx[i] = compress_x[rx[i]];
        ly[i] = compress_y[ly[i]];
        ry[i] = compress_y[ry[i]];
    }
    vector<long long> answer(q);
    REP_R (k, HEIGHT) {
        REP (i, q) {  // swap loops to optimize cache (important, 2x faster)
            int l = lower_bound(ALL(x1[k]), lx[i]) - x1[k].begin();
            int r = lower_bound(ALL(x1[k]), rx[i]) - x1[k].begin();
            int a = ly[i];
            int b = ry[i];
            answer[i] *= WIDTH;
            answer[i] += wm[k].range_frequency(l, r, a, b);
        }
    }
    REP (i, q) {
        printf("%lld\n", answer[i]);
    }
    return 0;
}
