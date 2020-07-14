#define PROBLEM "https://yukicoder.me/problems/no/1031"
#include "utils/macros.hpp"
#include "graph/cartesian_tree.hpp"
#include "graph/format.hpp"
#include "graph/subtree.hpp"
#include "data_structure/sparse_table.hpp"
#include "monoids/min.hpp"
#include <cstdio>
#include <functional>
#include <utility>
#include <vector>
using namespace std;

int64_t solve1(int n, const vector<int> & p) {
    // prepare a data structure for LIS
    vector<int> depth(n);
    {
        vector<int> parent = construct_cartesian_tree<int, greater<int> >(p);
        vector<vector<int> > children; int root; tie(children, root) = children_from_parent(parent);
        auto g = adjacent_list_from_children(children);
        auto info = prepare_subtree_info(g, root);
        REP (x, n) {
            depth[x] = info[x].depth;
        }
    }
    sparse_table<min_monoid<int> > table(ALL(depth));
    auto lis = [&](int l, int r) {
        if (l == r) return 0;
        return depth[l] - table.range_get(l, r) + 1;
    };

    // fold the Cartesian tree
    vector<int> parent = construct_cartesian_tree(p);
    vector<vector<int> > children; int root; tie(children, root) = children_from_parent(parent);
    int64_t ans = 0;
    auto go = [&](auto && go, int l, int m, int r) -> void {
        if (l == r) {
            return;
        }
        ans += lis(m + 1, r);
        for (int x : children[m]) {
            if (x < m) {
                go(go, l, x, m);
            } else {
                go(go, m + 1, x, r);
            }
        }
    };
    go(go, 0, root, n);
    return ans;
}

int64_t solve(int n, vector<int> p) {
    int64_t ans = solve1(n, p);
    reverse(ALL(p));
    return ans + solve1(n, p);
}

int main() {
    int n; scanf("%d", &n);
    vector<int> p(n);
    REP (i, n) {
        scanf("%d", &p[i]);
    }
    long long ans = solve(n, p);
    printf("%lld\n", ans);
    return 0;
}
