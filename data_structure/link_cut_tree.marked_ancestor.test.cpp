#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2170&lang=jp
#include <iostream>
#include "data_structure/link_cut_tree.hpp"
#include "utils/macros.hpp"
using namespace std;


int main() {
    while (true) {
        int n, q; cin >> n >> q;
        if (n == 0 and q == 0) break;

        link_cut_tree lct(n);
        REP3 (i, 1, n) {
            int parent; cin >> parent;
            -- parent;
            lct.link(i, parent);
        }

        long long sum = 0;
        while (q --) {
            char c; int v; cin >> c >> v;
            -- v;
            if (c == 'M') {
                lct.cut(v);
            } else if (c == 'Q') {
                sum += lct.get_root(v) + 1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
