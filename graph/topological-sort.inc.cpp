vector<int> topological_sort(int n, vector<vector<int> > const & g_rev) {
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
