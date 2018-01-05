/**
 * @note O(n) time
 * @note O(n) space on heap
 * @return the size is 1 or 2
 */
vector<int> get_centroids(vector<vector<int> > const & g) {
    vector<int> size(g.size(), -1);
    function<void (int)> go = [&](int i) {
        bool is_centroid = true;
        size[i] = 1;
        for (auto j : g[i]) if (size[j] == -1) {
            go(j, i);
            size[i] += size[j];
            if (size[j] > n / 2) is_centroid = false;
        }
        if (n - size[i] > n / 2) is_centroid = false;
        if (is_centroid) result.push_back(i);
    };
    go(0, -1);
    return result;
}
