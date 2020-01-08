#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "data_structure/segment_tree_beats.hpp"

#include <cstdint>
#include <vector>
#include "utils/macros.hpp"
#include "utils/fastio_scanner.hpp"
#include "utils/fastio_printer.hpp"

int main() {
    scanner sc;
    printer pr;

    int n = sc.get<int>();
    int q = sc.get<int>();

    std::vector<int64_t> a(n);
    REP (i, n) {
        a[i] = sc.get<int64_t>();
    }
    segment_tree_beats beats(ALL(a));

    while (q --) {
        int ty = sc.get<int>();
        int l = sc.get<int>();
        int r = sc.get<int>();
        if (ty == 0) {
            int64_t b = sc.get<int64_t>();
            beats.range_chmin(l, r, b);
        } else if (ty == 1) {
            int64_t b = sc.get<int64_t>();
            beats.range_chmax(l, r, b);
        } else if (ty == 2) {
            int64_t b = sc.get<int64_t>();
            beats.range_add(l, r, b);
        } else {
            int64_t sum = beats.range_sum(l, r);
            pr.put<int64_t>(sum);
            pr.put<char>('\n');
        }
    }
    return 0;
}
