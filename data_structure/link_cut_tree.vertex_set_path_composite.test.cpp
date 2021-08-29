#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../data_structure/link_cut_tree.hpp"
#include "../modulus/mint.hpp"
#include "../monoids/linear_function.hpp"
#include "../monoids/dual.hpp"
#include "../utils/macros.hpp"
#include "../hack/fastio.hpp"
#include <stack>
#include <vector>
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int n = in<int>();
    int q = in<int>();

    // initialize
    link_cut_tree<dual_monoid<linear_function_monoid<mint<MOD> > > > lct(n);
    REP (i, n) {
        mint<MOD> a_i = in<int32_t>();
        mint<MOD> b_i = in<int32_t>();
        lct.vertex_set(i, make_pair(a_i, b_i));
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
            mint<MOD> c = in<int32_t>();
            mint<MOD> d = in<int32_t>();
            lct.vertex_set(p, make_pair(c, d));
        } else if (t == 1) {
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
