struct disjoint_sets {
    vector<int> data;
    disjoint_sets() = default;
    explicit disjoint_sets(size_t n) : data(n, -1) {}
    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }
    int set_size(int i) { return - data[find_root(i)]; }
    int unite_sets(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (set_size(i) < set_size(j)) swap(i,j);
            data[i] += data[j];
            data[j] = i;
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
};

namespace disjoint_sets {
    typedef vector<int> type;
    type construct(size_t n) { return type(n, -1); }
    bool is_root(type const & data, int i) { return data[i] < 0; }
    int find_root(type & data, int i) { return is_root(data, i) ? i : (data[i] = find_root(data, data[i])); }
    int set_size(type & data, int i) { return - data[find_root(data, i)]; }
    int unite_sets(type & data, int i, int j) {
        i = find_root(data, i); j = find_root(data, j);
        if (i != j) {
            if (set_size(data, i) < set_size(data, j)) swap(i,j);
            data[i] += data[j];
            data[j] = i;
        }
        return i;
    }
    bool is_same(type & data, int i, int j) { return find_root(data, i) == find_root(data, j); }
    void compress(type & data) {
        repeat (i, data.size()) {
            find_root(data, i);
        }
    }

    namespace without_compression {
        int find_root(type const & data, int i) { while (not is_root(data, i)) i = data[i]; }
        int unite_sets(type & data, int i, int j, vector<tuple<int, int, int> > & history) {
            i = without_compression::find_root(data, i);
            j = without_compression::find_root(data, j);
            if (i != j) {
                if (set_size(data, i) < set_size(data, j)) swap(i,j);
                history.emplace_back(i, j, data[j]);
                data[i] += data[j];
                data[j] = i;
            }
            return i;
        }
        bool is_same(type const & data, int i, int j) { return without_compression::find_root(data, i) == without_compression::find_root(data, j); }
        void undo_history(type & data, tuple<int, int, int> history) {
            int i, j, data_j; tie(i, j, data_j) = history;
            data[j] = data_j;
            data[i] -= data[j];
        }
        void undo_history(type & data, vector<tuple<int, int, int> > const & history) {
            repeat_reverse (i, history.size()) {
                undo_history(data, history[i]);
            }
        }
    }
}
