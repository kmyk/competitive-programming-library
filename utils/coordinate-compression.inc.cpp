template <typename T>
map<T, int> coordinate_compression_map(vector<T> const & xs) {
    int n = xs.size();
    vector<int> ys(n);
    iota(whole(ys), 0);
    sort(whole(ys), [&](int i, int j) { return xs[i] < xs[j]; });
    map<T,int> f;
    for (int i : ys) {
        if (not f.count(xs[i])) { // make unique
            int j = f.size();
            f[xs[i]] = j; // f[xs[i]] has a side effect, increasing the f.size()
        }
    }
    return f;
}

template <typename T>
vector<int> apply_compression(map<T,int> const & f, vector<T> const & xs) {
    int n = xs.size();
    vector<int> ys(n);
    repeat (i,n) ys[i] = f.at(xs[i]);
    return ys;
}

// template <typename T>
// vector<int> invert_compression_map(map<T, int> const & f) {
// }

template <typename T, typename U>
map<T,U>::iterator nearest_up(map<T,U> & f, T & x) {
    return f.lower_bound(x)->first;
}
template <typename T, typename U>
map<T,U>::iterator nearest_down(map<T,U> & f, T & x) {
    return -- f.upper_bound(x)->first;
}
