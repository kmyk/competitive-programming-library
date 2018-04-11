/**
 * @brief Warshall-Floyd algorithm
 * @note O(n^3)
 * @param g is a digraph
 */
vector<vector<ll> > warshall_floyd(vector<vector<pair<int, ll> > > const & g) {
    int n = g.size();
    vector<vector<ll> > dist(n, vector<ll>(n, LLONG_MAX));
    REP (i, n) {
        dist[i][i] = 0;
        for (auto edge : g[i]) {
            int j; ll cost; tie(j, cost) = edge;
            dist[i][j] = cost;
        }
    }
    REP (k, n) {
        REP (i, n) if (dist[i][k] != LLONG_MAX) {
            REP (j, n) if (dist[k][j] != LLONG_MAX) {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

/**
 * @brief Warshall-Floyd algorithm for connectivity
 */
vector<vector<bool> > warshall_floyd(vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<bool> > conn(n, vector<bool>(n));
    REP (i, n) {
        conn[i][i] = true;
        for (int j : g[i]) {
            conn[i][j] = true;
        }
    }
    REP (k, n) REP (i, n) REP (j, n) {
        if (conn[i][k] and conn[k][j]) {
            conn[i][j] = true;
        }
    }
    return conn;
}
