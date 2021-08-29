#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../data_structure/wavelet_matrix.hpp"
#include "../utils/macros.hpp"
#include "../hack/fastio.hpp"
#include <cstdint>
using namespace std;

int main() {
    // input
    int n = in<int>();
    int q = in<int>();
    vector<int32_t> a(n);
    REP (i, n) {
        a[i] = in<int32_t>();
    }

    // construct
    wavelet_matrix<30> wm(a);

    // output
    while (q --) {
        int l = in<int>();
        int r = in<int>();
        int k = in<int>();
        int32_t b = wm.quantile(k, l, r);
        out<int32_t>(b);
        out<char>('\n');
    }
    return 0;
}
