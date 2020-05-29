#define PROBELM "https://yukicoder.me/problems/no/1069"
#define ERROR 1e-4
#include <bits/stdc++.h>
#include "utils/macros.hpp"
#include "graph/yen_algorithm.hpp"
using namespace std;

int main() {
    // input
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
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
    auto path = yen_algorithm_with_dijkstra(g, start, goal, k);
    vector<double> cost(k, -1);
    map<pair<int, int>, double> lookup;
    REP (i, n) {
        for (auto [j, cost] : g[i]) {
            lookup[make_pair(i, j)] = cost;
        }
    }
    REP (i, path.size()) {
        cost[i] = 0;
        REP (j, (int)path[i].size() - 1) {
            cost[i] += lookup[make_pair(path[i][j], path[i][j + 1])];
        }
    }

    // output
    REP (i, k) {
        printf("%.12lf\n", cost[i]);
    }
    return 0;
}
