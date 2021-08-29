#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "../data_structure/segment_tree_beats.hpp"

#include <cstdint>
#include <vector>
#include "../utils/macros.hpp"
#include "../hack/fastio.hpp"

int main() {
    int n = in<int>();
    int q = in<int>();

    segment_tree_beats beats(n);

    while (q --) {
        int ty = in<int>();
        int l = in<int>();
        int r = in<int>();
        ++ r;
        if (ty == 0) {
            int64_t x = in<int64_t>();
            beats.range_add(l, r, x);
        } else {
            int64_t min = beats.range_min(l, r);
            out<int64_t>(min);
            out<char>('\n');
        }
    }
    return 0;
}
