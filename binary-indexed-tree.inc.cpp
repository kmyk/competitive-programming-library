// http://yukicoder.me/submissions/94306
// http://abc038.contest.atcoder.jp/submissions/744503
template <typename T>
struct binary_indexed_tree { // on monoid
    vector<T> a;
    T unit;
    function<T (T,T)> append; // associative
    template <typename F>
    binary_indexed_tree(size_t n, T a_unit, F a_append) : a(n, a_unit), unit(a_unit), append(a_append) {}
    void point_append(size_t i, T w) { // a[i] += w
        for (size_t j = i+1; j <= a.size(); j += j & -j) a[j-1] = append(a[j-1], w);
    }
    int initial_range_concat(size_t i) { // sum [0, i)
        T acc = unit;
        for (size_t j = i; 0 < j; j -= j & -j) acc = append(acc, a[j-1]);
        return acc;
    }
};

