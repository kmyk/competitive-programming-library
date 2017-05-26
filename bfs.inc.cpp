vector<int> bfs(vector<vector<int> > const & g) {
    vector<int> dist(g.size(), inf);
    queue<int> que;
    dist[src] = 0;
    que.push(src);
    while (not que.empty()) {
        int i = que.front(); que.pop();
        for (int j : g[i]) {
            if (dist[i] + 1 < dist[j]) {
                dist[j] = dist[i] + 1;
                que.push(j);
            }
        }
    }
    return dist;
}
