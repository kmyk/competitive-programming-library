/**
 * @brief get centers of a tree / 木の中心
 */
vector<int> get_centers(vector<vector<int> > const & tree) {
    int n = tree.size();
    vector<bool> used(n);
    vector<int> cur, prv;
    REP (i, n) {
        if (tree[i].size() <= 1) {
            cur.push_back(i);
            used[i] = true;
        }
    }
    while (not cur.empty()) {
        cur.swap(prv);
        cur.clear();
        for (int i : prv) {
            for (int j : tree[i]) if (not used[j]) {
                cur.push_back(j);
                used[j] = true;
            }
        }
    }
    return prv;
}
