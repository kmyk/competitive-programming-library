struct indexed_min_monoid {
    typedef pair<int, int> value_type;
    value_type unit() const { return { INT_MAX, INT_MAX }; }
    value_type append(value_type a, value_type b) const { return min(a, b); }
};
/**
 * @brief lowest common ancestor with \pm 1 RMQ and sparse table
 * @see https://www.slideshare.net/yumainoue965/lca-and-rmq
 * @note verified http://www.utpc.jp/2011/problems/travel.html
 */
struct lowest_common_ancestor {
    sparse_table<indexed_min_monoid> table;
    vector<int> index;
    lowest_common_ancestor() = default;
    /**
     * @note O(N)
     * @param g is an adjacent list of a tree
     */
    lowest_common_ancestor(int root, vector<vector<int> > const & g) {
        vector<pair<int, int> > tour;
        index.assign(g.size(), -1);
        function<void (int, int, int)> go = [&](int i, int parent, int depth) {
            index[i] = tour.size();
            tour.emplace_back(depth, i);
            for (int j : g[i]) if (j != parent) {
                go(j, i, depth + 1);
                tour.emplace_back(depth, i);
            }
        };
        go(root, -1, 0);
        table = sparse_table<indexed_min_monoid>(tour);
    }
    /**
     * @note O(1)
     */
    int operator () (int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        x = index[x];
        y = index[y];
        if (x > y) swap(x, y);
        return table.range_concat(x, y + 1).second;
    }
};
