/**
 * @brief compute the distances from root
 * @note O(n)
 * @arg g is a digraph
 * @note loops and double edges are allowed
 */
vector<int> breadth_first_search(int root, vector<vector<int> > const & g) {
    int n = g.size();
    vector<int> dist(n, INT_MAX);
    queue<int> que;
    dist[root] = 0;
    que.push(root);
    while (not que.empty()) {
        int i = que.front(); que.pop();
        for (int j : g[i]) if (dist[j] == INT_MAX) {
            dist[j] = dist[i] + 1;
            que.push(j);
        }
    }
    return dist;
}

/**
 * @brief 0-1 BFS
 * @arg g is a weighted digraph whose weights are 0 or 1
 * @note loops and double edges are allowed
 */
vector<int> zero_one_breadth_first_search(int root, vector<vector<pair<int, bool> > > const & g) {
    int n = g.size();
    vector<int> dist(n, INT_MAX);
    deque<pair<int, int> > que;
    dist[root] = 0;
    que.emplace_back(root, dist[root]);
    while (not que.empty()) {
        int i, dist_i; tie(i, dist_i) = que.front(); que.pop_front();
        if (dist[i] < dist_i) continue;
        for (auto edge : g[i]) {
            int j; bool cost; tie(j, cost) = edge;
            if (dist[i] + cost < dist[j]) {
                dist[j] = dist[i] + cost;
                if (cost) {
                    que.emplace_back(j, dist[j]);
                } else {
                    que.emplace_front(j, dist[j]);
                }
            }
        }
    }
    return dist;
}
