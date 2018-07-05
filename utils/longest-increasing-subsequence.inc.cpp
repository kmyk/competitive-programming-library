template <typename T>
vector<T> longest_strict_increasing_subsequence(vector<T> const & xs) {
    vector<T> l;  // l[i] is the last element of the increasing subsequence whose length is i + 1
    l.push_back(xs.front());
    for (auto && x : xs) {
        auto it = lower_bound(l.begin(), l.end(), x);
        if (it == l.end()) {
            l.push_back(x);
        } else {
            *it = x;
        }
    }
    return l;
}

template <typename T>
vector<T> longest_weak_increasing_subsequence(vector<T> const & xs) {
    vector<T> l;
    for (auto && x : xs) {
        auto it = upper_bound(l.begin(), l.end(), x);
        if (it == l.end()) {
            l.push_back(x);
        } else {
            *it = x;
        }
    }
    return l;
}
