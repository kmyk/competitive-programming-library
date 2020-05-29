#define PROBLEM "https://yukicoder.me/problems/no/1065"
#define ERROR 1e-4
#include <bits/stdc++.h>
#include "utils/macros.hpp"
#include "graph/dijkstra.hpp"
using namespace std;


int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    int start, goal; scanf("%d%d", &start, &goal);
    -- start;
    -- goal;
    vector<long long> x(n), y(n);
    REP (i, n) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    vector<vector<pair<int, double> > > g(n);
    REP (i, m) {
        int p, q; cin >> p >> q;
        -- p;
        -- q;
        double cost = sqrt(pow(x[p] - x[q], 2) + pow(y[p] - y[q], 2));
        g[p].emplace_back(q, cost);
        g[q].emplace_back(p, cost);
    }

    // solve
    auto dist = dijkstra(g, start);

    // output
    printf("%.12lf\n", dist[goal]);
    return 0;
}
