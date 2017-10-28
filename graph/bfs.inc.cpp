vector<int> breadth_first_search(int root, vector<vector<int> > const & g) {
    vector<int> dist(g.size(), numeric_limits<int>::max());
    queue<int> que;
    dist[root] = 0;
    que.push(root);
    while (not que.empty()) {
        int i = que.front();
        que.pop();
        for (int j : g[i]) if (dist[j] == numeric_limits<int>::max()) {
            dist[j] = dist[i] + 1;
            que.push(j);
        }
    }
    return dist;
}
