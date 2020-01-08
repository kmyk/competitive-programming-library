/**
 * @brief reverse a digraph
 */
vector<vector<int> > opposite_graph(vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<int> > h(n);
    REP (i, n) {
        for (int j : g[i]) {
            h[j].push_back(i);
        }
    }
    return h;
}
