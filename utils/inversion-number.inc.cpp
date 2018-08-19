ll inversion_number(vector<int> const & a) {
    int n = a.size();
    binary_indexed_tree<plus_t> bit(n + 1);
    ll result = 0;
    REP (i, n) {
        result += i - bit.initial_range_concat(a[i] + 1);
        bit.point_append(a[i], 1);
    }
    return result;
}
