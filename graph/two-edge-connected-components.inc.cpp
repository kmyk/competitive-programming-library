/**
 * @brief 2-edge-connected components decomposition
 * @param g an adjacent list of the simple undirected graph
 * @note O(V + E)
 */
pair<int, vector<int> > decompose_to_two_edge_connected_components(vector<vector<int> > const & g) {
    int n = g.size();
    vector<int> imos(n); { // imos[i] == 0  iff  the edge i -> parent is a bridge
        vector<char> used(n); // 0: unused ; 1: exists on stack ; 2: removed from stack
        function<void (int, int)> go = [&](int i, int parent) {
            used[i] = 1;
            for (int j : g[i]) if (j != parent) {
                if (used[j] == 0) {
                    go(j, i);
                    imos[i] += imos[j];
                } else if (used[j] == 1) {
                    imos[i] += 1;
                    imos[j] -= 1;
                }
            }
            used[i] = 2;
        };
        REP (i, n) if (used[i] == 0) {
            go(i, -1);
        }
    }
    int size = 0;
    vector<int> component_of(n, -1); {
        function<void (int)> go = [&](int i) {
            for (int j : g[i]) if (component_of[j] == -1) {
                component_of[j] = imos[j] == 0 ? size ++ : component_of[i];
                go(j);
            }
        };
        REP (i, n) if (component_of[i] == -1) {
            component_of[i] = size ++;
            go(i);
        }
    }
    return { size, move(component_of) };
}
