#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
#include "utils/common.hpp"
#include "data-structure/segment_tree.hpp"
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    segment_tree<plus_monoid> segtree(n);
    while (q --) {
        int com, x, y; cin >> com >> x >> y;
        -- x;
        if (com == 0) {
            segtree.point_set(x, segtree.range_concat(x, x + 1) + y);
        } else if (com == 1) {
            cout << segtree.range_concat(x, y) << endl;
        }
    }
    return 0;
}
