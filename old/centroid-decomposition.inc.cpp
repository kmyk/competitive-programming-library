/**
 * @brief get centroids of a graph / 重心分解
 * @note O(n) time
 * @note O(n) space on heap
 * @return the size is 1 or 2
 */
vector<int> get_centroids(vector<vector<int> > const & g, int root, set<int> const & forbidden) {
    map<int, int> available; {
        function<void (int, int)> go = [&](int i, int parent) {
            available.emplace(i, available.size());
            for (auto j : g[i]) if (j != parent and not forbidden.count(j)) {
                go(j, i);
            }
        };
        go(root, -1);
    }
    int n = available.size();
    vector<int> result;
    vector<int> size(n, -1);
    function<void (int, int)> go = [&](int x, int parent) {
        bool is_centroid = true;
        int i = available[x];
        size[i] = 1;
        for (auto y : g[x]) if (y != parent and available.count(y)) {
            int j = available[y];
            go(y, x);
            size[i] += size[j];
            if (size[j] > n / 2) is_centroid = false;
        }
        if (n - size[i] > n / 2) is_centroid = false;
        if (is_centroid) result.push_back(x);
    };
    go(root, -1);
    return result;
}
