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
