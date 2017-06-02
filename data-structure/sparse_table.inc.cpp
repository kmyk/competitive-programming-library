template <class Monoid>
struct sparse_table {
    typedef typename Monoid::type T;
    vector<vector<T> > table;
    Monoid mon;
    sparse_table(vector<T> const & init, Monoid const & a_mon = Monoid())
            : mon(a_mon) {
        int n = init.size();
        int log_n = sqrt(n) + 1;
        table.resize(log_n, vector<T>(n, mon.unit));
        table[0] = init;
        for (int k = 0; k < log_n-1; ++ k) {
            for (int i = 0; i < n; ++ i) {
                table[k+1][i] = mon.append(table[k][i], i + (1ll<<k) < n ? table[k][i + (1ll<<k)] : mon.unit);
            }
        }
    }
    T operator () (int l, int r) {
        assert (0 <= l and l <= r and r <= table[0].size());
        if (l == r) return mon.unit;
        int k = log2(r - l);
        return mon.append(table[k][l], table[k][r - (1ll<<k)]);
    }
};
struct min_t {
    typedef int type;
    const int unit = 1e9+7;
    int append(int a, int b) { return min(a, b); }
};
