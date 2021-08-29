#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"
#include "../data_structure/dynamic_connectivity_offline.hpp"
#include "../monoids/plus.hpp"
#include "../hack/fastio.hpp"
#include "../utils/macros.hpp"

int main() {
    int n = in<int>();
    int q = in<int>();

    dynamic_connectivity_offline<plus_monoid<int64_t> > dycon(n);
    REP (v, n) {
        int64_t a = in<int64_t>();
        dycon.point_set(v, a);
    }
    REP (i, q) {
        int t = in<int>();
        if (t == 0) {
            int u = in<int>();
            int v = in<int>();
            dycon.link(u, v);
        } else if (t == 1) {
            int u = in<int>();
            int v = in<int>();
            dycon.cut(u, v);
        } else if (t == 2) {
            int v = in<int>();
            int64_t x = in<int64_t>();
            dycon.point_mult(v, x);
        } else if (t == 3) {
            int v = in<int>();
            dycon.component_get(v);
        } else {
            assert (false);
        }
    }

    std::vector<int64_t> answer = dycon.run();
    for (int64_t a : answer) {
        out<int64_t>(a);
        out<char>('\n');
    }
    return 0;
}
