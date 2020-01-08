/**
 * @note g must be connected
 * @return is the size of a part
 */
int check_bipartite_graph(vector<vector<int> > const & g) {
    int n = g.size();
    vector<char> used(n, -1);
    function<bool (int, int)> dfs = [&](int i, int parent) {
        for (int j : g[i]) {
            if (used[j] != -1) {
                if (used[j] == used[i]) {
                    return false;
                }
            } else {
                used[j] = used[i] ^ 1;
                if (not dfs(j, i)) return false;
            }
        }
        return true;
    };
    used[0] = 0;
    if (not dfs(0, -1)) return -1;
    return count(whole(used), 0);
}
