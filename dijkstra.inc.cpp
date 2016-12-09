vector<int> dijkstra_simple_distance_from(int root, vector<vector<int> > const & g) {
    vector<int> dist(n, -1);
    queue<int> que;
    dist[root] = 0;
    que.push(root);
    while (not que.empty()) {
        int i = que.front(); que.pop();
        for (int j : g[i]) if (dist[j] == -1) {
            dist[j] = dist[i] + 1;
            que.push(j);
        }
    }
    return dist;
}

template <typename T>
vector<T> original_dijkstra(vector<vector<pair<int, T> > > const & g, int start, T inf) { // O(V^2)
    int n = g.size();
    vector<double> dist(n, inf);
    vector<int> ixs(n); whole(iota, ixs, 0);
    dist[start] = 0;
    repeat (loop,n) {
        int i; {
            auto it = whole(min_element, ixs, [&](int i, int j) { return dist[i] < dist[j]; });
            i = *it;
            *it = ixs.back();
            ixs.pop_back();
        }
        for (auto it : g[i]) {
            int j; T cost; tie(j, cost) = it;
            setmin(dist[j], dist[i] + cost);
        }
    }
    return dist;
}
