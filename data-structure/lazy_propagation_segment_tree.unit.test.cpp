#include "utils/common.hpp"
#include "data-structure/lazy_propagation_segment_tree.hpp"
using namespace std;

int main() {
    {
        lazy_propagation_segment_tree<min_monoid, plus_with_int_max_operator_monoid> segtree(9);
        segtree.point_set(2, 2);
        segtree.point_set(3, 3);
        segtree.point_set(4, 4);
        segtree.point_set(6, 6);
        assert (segtree.range_concat(2, 3) == 2);
        assert (segtree.range_concat(5, 8) == 6);
        segtree.range_apply(1, 4, 9);
        assert (segtree.range_concat(3, 6) == 4);
        assert (segtree.range_concat(0, 3) == 11);
    }

    {
        constexpr int MOD = 1e9 + 7;
        constexpr int n = 13;
        vector<mint<MOD> > ary(n);
        lazy_propagation_segment_tree<modplus_length_monoid<MOD>, modular_linear_operator_monoid<MOD> > segtree(n, make_pair(0, 1));
        auto check = [&]() {
            REP (l, n) {
                mint<MOD> acc = 0;
                REP3 (r, l + 1, n + 1) {
                    acc += ary[r - 1];
                    assert (segtree.range_concat(l, r).first == acc);
                }
            }
        };
        auto apply = [&](int l, int r, mint<MOD> a, mint<MOD> b) {
            REP3 (i, l, r) {
                ary[i] = a * ary[i] + b;
            }
            segtree.range_apply(l, r, modular_linear_operator_monoid<MOD>::make(a, b));
            check();
        };
        apply(1, 4, 1, 1);
        apply(3, 7, 2, 3);
        apply(2, 9, 5, 4);
        apply(0, 5, 7, 6);
    }
    return 0;
}
