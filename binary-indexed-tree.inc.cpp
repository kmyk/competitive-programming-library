// http://yukicoder.me/submissions/94306
// http://abc038.contest.atcoder.jp/submissions/744503
template <typename T>
struct binary_indexed_tree { // on monoid
    vector<T> data;
    T unit;
    function<T (T,T)> append; // associative
    template <typename F>
    binary_indexed_tree(size_t n, T a_unit, F a_append) : data(n, a_unit), unit(a_unit), append(a_append) {}
    void point_append(size_t i, T z) { // data[i] += z
        for (size_t j = i+1; j <= data.size(); j += j & -j) data[j-1] = append(data[j-1], z);
    }
    T initial_range_concat(size_t i) { // sum [0, i)
        T acc = unit;
        for (size_t j = i; 0 < j; j -= j & -j) acc = append(data[j-1], acc);
        return acc;
    }
};
