#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "graph/lowest_common_ancestor.hpp"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    // read a tree
    int n; cin >> n;
    vector<vector<int> > g(n);
    REP (i, n) {
        int k; cin >> k;
        REP (j, k) {
            int c; cin >> c;
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }

    // construct the LCA
    constexpr int root = 0;
    lowest_common_ancestor lca(root, g);

    // answer to queries
    int q; cin >> q;
    while (q --) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}
