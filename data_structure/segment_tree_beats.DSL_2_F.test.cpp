#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include "../data_structure/segment_tree_beats.hpp"

#include <cstdint>
#include <vector>
#include "../utils/macros.hpp"
#include "../hack/fastio.hpp"

int main() {
    int n = in<int>();
    int q = in<int>();

    constexpr int64_t initial = (1ull << 31) - 1;
    segment_tree_beats beats(n);
    beats.range_update(0, n, initial);

    while (q --) {
        int ty = in<int>();
        int l = in<int>();
        int r = in<int>();
        ++ r;
        if (ty == 0) {
            int64_t x = in<int64_t>();
            beats.range_update(l, r, x);
        } else {
            int64_t min = beats.range_min(l, r);
            out<int64_t>(min);
            out<char>('\n');
        }
    }
    return 0;
}
