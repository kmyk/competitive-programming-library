/**
 * @return a list of vertices which sorted topologically
 * @note the empty list is returned if cycles exist
 * @note O(V + E)
 */
vector<int> topological_sort(const vector<vector<int> > & g_rev) {
    int n = g_rev.size();
    vector<int> order;
    vector<char> used(n);
    function<bool (int)> go = [&](int i) {
        used[i] = 1;  // in stack
        for (int j : g_rev[i]) {
            if (used[j] == 1) return true;
            if (not used[j]) {
                if (go(j)) return true;
            }
        }
        used[i] = 2;  // completely used
        order.push_back(i);
        return false;
    };
    REP (i, n) if (not used[i]) {
        if (go(i)) return vector<int>();
    }
    return order;
}

/**
 * @note you can use std::reverse instead of this
 */
vector<vector<int> > opposite_graph(const vector<vector<int> > & g) {
    vector<vector<int> > g_rev(g.size());
    REP (i, g.size()) {
        for (int j : g[i]) {
            g_rev[j].push_back(i);
        }
    }
    return g_rev;
}
