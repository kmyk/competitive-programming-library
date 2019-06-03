#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
#include "utils/common.hpp"
#include "data_structure/union_find_tree.hpp"
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    union_find_tree uft(n);
    while (q --) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) {
            uft.unite_trees(x, y);
        } else if (com == 1) {
            cout << uft.is_same(x, y) << endl;
        }
    }
    return 0;
}
