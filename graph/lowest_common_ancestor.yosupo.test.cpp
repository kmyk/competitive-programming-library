#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../graph/lowest_common_ancestor.hpp"

#include "../utils/macros.hpp"
#include "../hack/stack_pivot.hpp"
#include <cstdio>
#include <vector>
using namespace std;

int moin() {
    // read a tree
    int n, q; scanf("%d%d", &n, &q);
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int p; scanf("%d", &p);
        g[i + 1].push_back(p);
        g[p].push_back(i + 1);
    }

    // construct the LCA
    constexpr int root = 0;
    lowest_common_ancestor lca(root, g);

    // answer to queries
    while (q --) {
        int u, v; scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}

STACK_PIVOT_MAIN(moin)
