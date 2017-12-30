/**
 * @brie a flexible binary search
 * @param[in] p  a monotone predicate defined on [l, r)
 * @return  \min \{ x \in [l, r) \mid p(x) \}, or r if it doesn't exist
 */
template <typename UnaryPredicate>
ll binsearch(ll l, ll r, UnaryPredicate p) {
    assert (l <= r);
    -- l;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r;
}

unittest {
    for (int l : { 0, 1, 2, 3 }) {
        for (int r : { 8, 9, 10, 11 }) {
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return true;   }) == l);
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return false;  }) == r);
            repeat_from (i, l, r + 1) {
                assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return n >= i; }) == i);
            }
        }
    }
}
