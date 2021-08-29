#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../graph/strongly_connected_components.hpp"
#include "../graph/quotient_graph.hpp"
#include "../graph/topological_sort.hpp"
#include "../utils/macros.hpp"
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int> > g(n);
    REP (i, m) {
        int a, b; scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }

    // solve
    int size; vector<int> component_of; tie(size, component_of) = decompose_to_strongly_connected_components(g);
    vector<vector<int> > component(size);
    REP (i, n) {
        component[component_of[i]].push_back(i);
    }
    vector<vector<int> > h = make_quotient_graph(g, size, component_of);
    vector<int> order = topological_sort(h);
    assert (order.size() == size);

    // output
    printf("%d\n", size);
    for (int a : order) {
        printf("%d", (int)component[a].size());
        for (int i : component[a]) {
            printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}
