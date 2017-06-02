int maximum_independent_set(vector<vector<int> > const & g) {
    int n = g.size();
    vector<bool> used(n);
    function<int (int)> dfs = [&](int i) {
        if (i == n) return 0;
        if (used[i]) return dfs(i+1);
        used[i] = true;
        int l = g[i].size();
        vector<bool> preserved(l);
        repeat (j,l) {
            preserved[j] = used[g[i][j]];
            used[g[i][j]] = true;
        }
        int hit = 1 + dfs(i+1);
        repeat (j,l) {
            used[g[i][j]] = preserved[j];
        }
        int ign = l <= 1 ? 0 : dfs(i+1);
        used[i] = false;
        return max(hit, ign);
    };
    return dfs(0);
}
