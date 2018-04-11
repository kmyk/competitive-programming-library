/**
 * @arg g is a digraph with possibly negative cost edges
 * @note - inf for unreachable node
 */
vector<ll> bellman_ford_longest_path(int root, vector<vector<pair<int, ll> > > const & g) {
    int n = g.size();
    vector<ll> dist(n, - inf);
    dist[root] = 0;
    REP (iteration, n - 1) {
        REP (i, n) for (auto edge : g[i]) {
            int j; ll cost; tie(j, cost) = edge;
            chmax(dist[j], dist[i] + cost);
        }
    }
    REP (iteration, n - 1) {
        REP (i, n) for (auto edge : g[i]) {
            int j; ll cost; tie(j, cost) = edge;
            if (dist[i] == inf or dist[j] < dist[i] + cost) {
                dist[j] = inf;
            }
        }
    }
    return dist;
}
