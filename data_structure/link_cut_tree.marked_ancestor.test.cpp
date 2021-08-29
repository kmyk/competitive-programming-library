#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2170&lang=jp"
#include <iostream>
#include "../data_structure/link_cut_tree.hpp"
#include "../monoids/trivial.hpp"
#include "../utils/macros.hpp"
using namespace std;


int main() {
    while (true) {
        int n, q; cin >> n >> q;
        if (n == 0 and q == 0) break;

        link_cut_tree<trivial_monoid> lct(n);
        REP3 (i, 1, n) {
            int parent; cin >> parent;
            -- parent;
            lct.link(i, parent);
        }

        long long sum = 0;
        vector<bool> marked(n);
        marked[0] = true;
        while (q --) {
            char c; int v; cin >> c >> v;
            -- v;
            if (c == 'M') {
                if (not marked[v]) {
                    marked[v] = true;
                    lct.cut(v);
                }
            } else if (c == 'Q') {
                sum += lct.get_root(v) + 1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
