#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
#include "utils/common.hpp"
#include "data-structure/lazy_propagation_segment_tree.hpp"
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    lazy_propagation_segment_tree<min_monoid, plus_with_int_max_operator_monoid> segtree(n, 0);
    while (q --) {
        int com, l, r; cin >> com >> l >> r;
        ++ r;
        if (com == 0) {
            int x; cin >> x;
            segtree.range_apply(l, r, x);
        } else if (com == 1) {
            cout << segtree.range_concat(l, r) << endl;
        }
    }
    return 0;
}
