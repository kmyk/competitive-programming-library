#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "../data_structure/lazy_propagation_segment_tree.hpp"
#include "../monoids/min.hpp"
#include "../monoids/plus.hpp"
#include "../monoids/plus_min_action.hpp"
#include <cstdio>

int main() {
    int n, q; scanf("%d%d", &n, &q);
    lazy_propagation_segment_tree<min_monoid<int>, plus_monoid<int>, plus_min_action<int> > segtree(n);
    segtree.range_set(0, n, 0);
    while (q --) {
        int com, l, r; scanf("%d%d%d", &com, &l, &r);
        ++ r;
        if (com == 0) {
            int x; scanf("%d", &x);
            segtree.range_apply(l, r, x);
        } else if (com == 1) {
            printf("%d\n", segtree.range_get(l, r));
        }
    }
    return 0;
}
