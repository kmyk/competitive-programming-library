#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "../data_structure/dual_segment_tree.hpp"
#include "../monoids/left.hpp"

#include <iostream>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    dual_segment_tree<left_monoid<uint32_t> > segtree(n);
    segtree.range_apply(0, n, make_pair(true, (1u << 31) - 1));
    while (q --) {
        int com; cin >> com;
        if (com == 0) {
            int l, r; uint32_t x; cin >> l >> r >> x;
            ++ r;
            segtree.range_apply(l, r, make_pair(true, x));
        } else if (com == 1) {
            int i; cin >> i;
            cout << segtree.point_get(i).second << endl;
        }
    }
    return 0;
}
