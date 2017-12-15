/**
 * @see https://www.slideshare.net/wata_orz/ss-12131479
 * @note O(1.466^n n)
 * @param g is an adjacency matrix
 */
int maximum_independent_set(vector<vector<bool> > const & g) {
    int n = g.size();
    function<int (int, vector<bool> const &)> go = [&](int i, vector<bool> used) {
        while (i < n and used[i]) ++ i;
        if (i == n) return 0;
        int degree = 0;
        repeat_from (j, i + 1, n) {
            degree += (not used[j] and g[i][j]);
        }
        int result = 0;
        used[i] = true;
        if (degree >= 2) {
            setmax(result, go(i + 1, used));  // don't use i
        }
        repeat_from (j, i + 1, n) {
            used[j] = (used[j] or g[i][j]);
        }
        setmax(result, 1 + go(i + 1, used));  // use i
        return result;
    };
    return go(0, vector<bool>(n));
}
