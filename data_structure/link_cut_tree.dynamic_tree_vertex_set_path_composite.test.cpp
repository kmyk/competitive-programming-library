#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"
#include "../data_structure/link_cut_tree.hpp"
#include "../modulus/mint.hpp"
#include "../monoids/linear_function.hpp"
#include "../monoids/dual.hpp"
#include "../utils/macros.hpp"
#include "../hack/fastio.hpp"
#include <stack>
#include <vector>

constexpr int MOD = 998244353;
int main() {
    int n = in<int>();
    int q = in<int>();

    // initialize
    link_cut_tree<dual_monoid<linear_function_monoid<mint<MOD> > > > lct(n);
    REP (i, n) {
        mint<MOD> a_i = in<int32_t>();
        mint<MOD> b_i = in<int32_t>();
        lct.vertex_set(i, std::make_pair(a_i, b_i));
    }
    std::vector<std::vector<int> > g(n);
    REP (i, n - 1) {
        int u = in<int>();
        int v = in<int>();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<bool> used(n);
    std::stack<int> stk;
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
            int u = in<int>();
            int v = in<int>();
            int w = in<int>();
            int x = in<int>();
            lct.cut(lct.get_parent(u) == v ? u : v);
            lct.evert(w);
            lct.link(w, x);
        } else if (t == 1) {
            int u = in<int>();
            mint<MOD> c = in<int32_t>();
            mint<MOD> d = in<int32_t>();
            lct.vertex_set(u, std::make_pair(c, d));
        } else if (t == 2) {
            int u = in<int>();
            int v = in<int>();
            mint<MOD> x = in<int32_t>();
            auto [a, b] = lct.path_get(u, v);
            out<int32_t>((a * x + b).value);
            out<char>('\n');
        }
    }
    return 0;
}
