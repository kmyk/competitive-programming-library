#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
#include "utils/common.hpp"
#include "data_structure/dual_segment_tree.hpp"
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    dual_segment_tree<const_operator_monoid<int64_t> > segtree(n, (1ll << 31) - 1);
    while (q --) {
        int com; cin >> com;
        if (com == 0) {
            int l, r; int64_t x; cin >> l >> r >> x;
            ++r;
            segtree.range_apply(l, r, make_pair(true, x));
        } else if (com == 1) {
            int i; cin >> i;
            cout << segtree.point_get(i) << endl;
        }
    }
    return 0;
}
