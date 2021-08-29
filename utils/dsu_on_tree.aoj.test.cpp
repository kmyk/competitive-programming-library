#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995"
#include "../utils/dsu_on_tree.hpp"
#include "../data_structure/union_find_tree_with_monoid.hpp"
#include "../monoids/plus.hpp"
#include "../hack/stack_pivot.hpp"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../utils/macros.hpp"
using namespace std;

vector<int> solve(int n, int k, const vector<vector<int> > & g, const vector<int> & c, const vector<int> & d) {
    union_find_tree_with_monoid<plus_monoid<int> > uft(k);
    unordered_set<int> used;
    int value = 0;
    auto func = [&](int e) {
        return min(uft.tree_size(e), uft.get_value(e));
    };

    auto add = [&](int i) {
        int c_i = uft.find_root(c[i]);
        int d_i = uft.find_root(d[i]);
        if (c_i == d_i) {
            value -= func(c_i);
            uft.set_value(c_i, uft.get_value(c_i) + 1);
            value += func(c_i);
        } else {
            value -= func(c_i);
            value -= func(d_i);
            uft.unite_trees(c_i, d_i);
            if (not uft.is_root(c_i)) {
                swap(c_i, d_i);
            }
            uft.set_value(c_i, uft.get_value(c_i) + 1);
            value += func(c_i);
        }
        used.insert(c_i);
        used.insert(d_i);
    };
    auto reset = [&](int i) {
        if (used.empty()) return;
        for (int e : used) {
            uft.data[e] = -1;
            uft.value[e] = 0;
        }
        used.clear();
        value = 0;
    };

    vector<int> answer(n, -1);
    auto callback = [&](int i) {
        answer[i] = value;
    };

    constexpr int root = 0;
    dsu_on_tree(g, root, add, reset, callback);
    return answer;
}

int moin() {
    // input
    int n, k; cin >> n >> k;
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int u, v; cin >> u >> v;
        -- u;
        -- v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> c(n);
    vector<int> d(n);
    REP (i, n) {
        cin >> c[i] >> d[i];
        -- c[i];
        -- d[i];
    }

    // solve
    auto answer = solve(n, k, g, c, d);

    // output
    REP (i, n) {
        cout << answer[i] << endl;
    }
    return 0;
}

STACK_PIVOT_MAIN(moin)
