/**
 * @brief 2-node-connected components decomposition / 2-頂点連結成分分解
 * @param g an adjacent list of the simple undirected graph
 * @note O(V + E)
 * @return list of (list of edges in the component)
 */
vector<vector<pair<int, int> > > decompose_to_two_node_connected_components(vector<vector<int> > const & g) {
    int n = g.size();
    vector<int> ord(n, -1);
    vector<int> low(n, -1);
    vector<bool> used(n);
    vector<vector<pair<int, int> > > components;
    stack<pair<int, int> > stk;
    int k = 0;
    function<void (int, int)> go = [&](int i, int parent) {
        used[i] = true;
        ord[i] = k ++;
        low[i] = ord[i];
        for (auto j : g[i]) if (j != parent) {
            if (ord[j] < ord[i]) {
                stk.emplace(minmax({ i, j }));
            }
            if (used[j]) {
                chmin(low[i], ord[j]);
            } else {
                go(j, i);
                chmin(low[i], low[j]);
                if (low[j] >= ord[i]) {
                    components.emplace_back();
                    while (true) {
                        pair<int, int> e = stk.top();
                        components.back().push_back(e);
                        stk.pop();
                        if (e == minmax({ i, j })) {
                            break;
                        }
                    }
                }
            }
        }
    };
    REP (i, n) if (not used[i]) {
        go(i, -1);
    }
    return components;
}
