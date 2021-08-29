#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../graph/lowest_common_ancestor.hpp"
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // read a tree
    int n; scanf("%d", &n);
    vector<vector<int> > g(n);
    REP (i, n) {
        int k; scanf("%d", &k);
        REP (j, k) {
            int c; scanf("%d", &c);
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }

    // construct the LCA
    constexpr int root = 0;
    lowest_common_ancestor lca(root, g);

    // answer to queries
    int q; scanf("%d", &q);
    while (q --) {
        int u, v; scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}
