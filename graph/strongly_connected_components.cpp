vector<vector<int> > opposite_graph(vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<int> > h(n);
    repeat (i, n) for (int j : g[i]) h[j].push_back(i);
    return h;
}
/**
 * @brief strongly connected components decomposition, Kosaraju's algorithm
 * @return the pair (the number k of components, the function from vertices of g to components)
 * @note O(V + E)
 */
pair<int, vector<int> > decompose_to_strongly_connected_components(vector<vector<int> > const & g, vector<vector<int> > const & g_rev) {
    int n = g.size();
    vector<int> acc(n); {
        vector<bool> used(n);
        function<void (int)> dfs = [&](int i) {
            used[i] = true;
            for (int j : g[i]) if (not used[j]) dfs(j);
            acc.push_back(i);
        };
        repeat (i,n) if (not used[i]) dfs(i);
        whole(reverse, acc);
    }
    int size = 0;
    vector<int> component_of(n); {
        vector<bool> used(n);
        function<void (int)> rdfs = [&](int i) {
            used[i] = true;
            component_of[i] = size;
            for (int j : g_rev[i]) if (not used[j]) rdfs(j);
        };
        for (int i : acc) if (not used[i]) {
            rdfs(i);
            ++ size;
        }
    }
    return { size, move(component_of) };
}
vector<vector<int> > decomposed_graph(int size, vector<int> const & component_of, vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<int> > h(size);
    repeat (i, n) for (int j : g[i]) {
        if (component_of[i] != component_of[j]) {
            h[component_of[i]].push_back(component_of[j]);
        }
    }
    repeat (k, size) {
        whole(sort, h[k]);
        h[k].erase(whole(unique, h[k]), h[k].end());
    }
    return h;
}

/**
 * @brief memory optimized version
 * @note 速度差はほぼない stack overflowしたとき用
 */
pair<int, vector<int> > decompose_to_strongly_connected_components(vector<vector<int> > const & g, vector<vector<int> > const & g_rev) {
    int n = g.size();
    vector<int> acc(n); {
        auto it = acc.rbegin();
        vector<bool> used(n);
        stack<pair<int, int> > stk;
        repeat (k, n) if (not used[k]) {
            stk.emplace(k, 0);
            used[k] = true;
            while (not stk.empty()) { // dfs
                int i = stk.top().first;
                int & e = stk.top().second;
                while (e < g[i].size()) {
                    int j = g[i][e];
                    ++ e;
                    if (not used[j]) {
                        stk.emplace(j, 0);
                        used[j] = true;
                        break;
                    }
                }
                if (stk.top().first == i) {
                    *(it ++) = i;
                    stk.pop();
                }
            }
        }
    }
    int size = 0;
    vector<int> component_of(n); {
        vector<bool> used(n);
        stack<int> stk;
        for (int k : acc) if (not used[k]) {
            stk.push(k);
            used[k] = true;
            while (not stk.empty()) { // dfs
                int i = stk.top(); stk.pop();
                component_of[i] = size;
                for (int j : g_rev[i]) if (not used[j]) {
                    stk.push(j);
                    used[j] = true;
                }
            }
            ++ size;
        }
    }
    return { size, move(component_of) };
}
