/**
 * @brief the doubling technique
 */
struct doubling_table {
    vector<vector<int> > table;
    doubling_table() = default;
    /**
     * @note O(N log K)
     */
    doubling_table(vector<int> const & next, int size = -1) {
        int n = next.size();
        {
            auto it = minmax_element(ALL(next));
            assert (0 <= *(it.first) and *(it.second) <= n);
        }
        if (size == -1) {
            size = max<int>(1, ceil(log2(n)));
        }
        table.resize(size);
        table[0] = next;
        REP (k, size - 1) {
            table[k + 1].resize(n, n);
            REP (i, n) if (table[k][i] != n) {
                table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }
    /**
     * @note O(log K)
     */
    int get(int i, int count) {
        assert (count < (1 << table.size()));
        int n = table[0].size();
        if (i == n) return n;
        assert (0 <= i and i < n);
        REP_R (k, table.size()) if (count & (1 << k)) {
            i = table[k][i];
            if (i == n) return n;
        }
        return i;
    }
};

unittest {
    vector<int> step { 1, 3, 3, 4, 5, 6, 8, 8, 9, 10 };
    doubling_table steps(step);
    assert (steps.get(6, 2) == step[step[6]]);
    assert (steps.get(3, 5) == step[step[step[step[step[3]]]]]);
}
