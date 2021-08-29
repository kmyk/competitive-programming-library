#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "../data_structure/link_cut_tree.hpp"
#include "../monoids/plus.hpp"
#include "../utils/macros.hpp"
#include "../hack/fastio.hpp"
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n = in<int>();
    int q = in<int>();

    // initialize
    link_cut_tree<plus_monoid<int64_t> > lct(n);
    REP (i, n) {
        int64_t a_i = in<int64_t>();
        lct.vertex_set(i, a_i);
    }
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int u = in<int>();
        int v = in<int>();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> used(n);
    stack<int> stk;
    stk.push(0);
    used[0] = true;
    while (not stk.empty()) {
        int u = stk.top();
        stk.pop();
        for (int v : g[u]) if (not used[v]) {
            lct.link(v, u);
            stk.push(v);
            used[v] = true;
        }
    }

    // answer to queries
    while (q --) {
        int t = in<int>();
        if (t == 0) {
            int p = in<int>();
            int64_t x = in<int64_t>();
            lct.vertex_set(p, lct.vertex_get(p) + x);
        } else if (t == 1) {
            int u = in<int>();
            int v = in<int>();
            out<int64_t>(lct.path_get(u, v));
            out<char>('\n');
        }
    }
    return 0;
}
