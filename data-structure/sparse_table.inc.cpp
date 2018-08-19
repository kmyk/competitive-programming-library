/**
 * @brief sparse table on a semilattice
 * @note a semilattice is a commutative idempotent semigroup
 * @note for convenience, it requires the unit
 * @note space: O(N log N)
 * @note time:  O(N log N) for construction; O(1) for query
 */
template <class Semilattice>
struct sparse_table {
    typedef typename Semilattice::underlying_type underlying_type;
    vector<vector<underlying_type> > table;
    Semilattice lat;
    sparse_table() = default;
    sparse_table(vector<underlying_type> const & data, Semilattice const & a_lat = Semilattice())
            : lat(a_lat) {
        int n = data.size();
        int log_n = 32 - __builtin_clz(n);
        table.resize(log_n, vector<underlying_type>(n));
        table[0] = data;
        REP (k, log_n - 1) {
            REP (i, n) {
                table[k + 1][i] = i + (1ll << k) < n ?
                    lat.append(table[k][i], table[k][i + (1ll << k)]) :
                    table[k][i];
            }
        }
    }
    underlying_type range_concat(int l, int r) const {
        if (l == r) return lat.unit();  // if there is no unit, remove this line
        assert (0 <= l and l < r and r <= table[0].size());
        int k = 31 - __builtin_clz(r - l);  // log2
        return lat.append(table[k][l], table[k][r - (1ll << k)]);
    }
};
struct max_semilattice {
    typedef int underlying_type;
    int unit() const { return INT_MIN; }
    int append(int a, int b) const { return max(a, b); }
};
struct min_semilattice {
    typedef int underlying_type;
    int unit() const { return INT_MAX; }
    int append(int a, int b) const { return min(a, b); }
};
struct gcd_semilattice {
    typedef int underlying_type;
    int unit() const { return 0; }
    int append(int a, int b) const { return gcd(a, b); }
};

unittest {
    random_device device;
    default_random_engine gen(device());
    int n = uniform_int_distribution<int>(1, 500)(gen);
    vector<int> data(n);
    REP (i, n) data[i] = uniform_int_distribution<int>(- 1000000, 1000000)(gen);
    sparse_table<max_semilattice> table(data);
    auto range_concat = [&](int l, int r) {
        int acc = INT_MIN;
        REP3 (i, l, r) chmax(acc, data[i]);
        return acc;
    };
    REP (iteration, 500) {
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        assert (table.range_concat(l, r) == range_concat(l, r));
    }
}
