#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../data_structure/euler_tour_subtree_query.hpp"
#include "../monoids/plus.hpp"
#include "../utils/macros.hpp"
#include "../hack/fastio.hpp"
#include <vector>
using namespace std;

int main() {
    int n = in<int>();
    int q = in<int>();

    // initialize
    vector<int64_t> a(n);
    REP (i, n) {
        a[i] = in<int64_t>();
    }
    vector<vector<int> > g(n);
    REP3 (i, 1, n) {
        int p_i = in<int>();
        g[i].push_back(p_i);
        g[p_i].push_back(i);
    }
    constexpr int root = 0;
    euler_tour_subtree_query<plus_monoid<int64_t> > euler(g, root, ALL(a));

    // answer to queries
    while (q --) {
        int t = in<int>();
        if (t == 0) {
            int u = in<int>();
            int64_t x = in<int64_t>();
            euler.vertex_set(u, euler.vertex_get(u) + x);
        } else if (t == 1) {
            int u = in<int>();
            out<int64_t>(euler.subtree_get(u));
            out<char>('\n');
        }
    }
    return 0;
}
