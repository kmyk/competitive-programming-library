struct disjoint_sets {
    vector<int> xs;
    disjoint_sets() = default;
    explicit disjoint_sets(size_t n) : xs(n, -1) {}
    bool is_root(int i) { return xs[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (xs[i] = find_root(xs[i])); }
    int set_size(int i) { return - xs[find_root(i)]; }
    int union_sets(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (set_size(i) < set_size(j)) swap(i,j);
            xs[i] += xs[j];
            xs[j] = i;
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
};
