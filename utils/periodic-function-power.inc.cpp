template <class F, class T>
T periodic_function_power(F f, ll k, T x) {
    assert (k >= 1);
    if (k == 1) return x;
    vector<T> history;
    unordered_map<T, int> lookup;
    history.push_back(x);
    lookup[x] = 0;
    for (int i = 1; ; ++ i) {
        T y = f(x);
        if (i == k) return y;
        if (lookup.count(y)) break;
        history.push_back(y);
        lookup[y] = lookup[x] + 1;
        x = y;
    }
    T y = f(x);
    int base = lookup[y];
    int cycle = lookup[x] + 1 - lookup[y];
    return history[(k - base) % cycle + base];
}
