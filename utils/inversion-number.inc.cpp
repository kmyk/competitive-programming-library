ll inversion_number(vector<int> const & a) {
    int n = a.size();
    binary_indexed_tree<plus_monoid> bit(n + 1);
    ll cnt = 0;
    REP (i, n) {
        cnt += i - bit.initial_range_concat(a[i] + 1);
        bit.point_append(a[i], 1);
    }
    return cnt;
}
