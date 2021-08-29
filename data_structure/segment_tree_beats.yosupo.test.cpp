#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../data_structure/segment_tree_beats.hpp"

#include <cstdint>
#include <vector>
#include "../utils/macros.hpp"
#include "../hack/fastio.hpp"

int main() {
    int n = in<int>();
    int q = in<int>();

    std::vector<int64_t> a(n);
    REP (i, n) {
        a[i] = in<int64_t>();
    }
    segment_tree_beats beats(ALL(a));

    while (q --) {
        int ty = in<int>();
        int l = in<int>();
        int r = in<int>();
        if (ty == 0) {
            int64_t b = in<int64_t>();
            beats.range_chmin(l, r, b);
        } else if (ty == 1) {
            int64_t b = in<int64_t>();
            beats.range_chmax(l, r, b);
        } else if (ty == 2) {
            int64_t b = in<int64_t>();
            beats.range_add(l, r, b);
        } else {
            int64_t sum = beats.range_sum(l, r);
            out<int64_t>(sum);
            out<char>('\n');
        }
    }
    return 0;
}
