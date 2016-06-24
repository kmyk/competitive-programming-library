// CAUTION: not verified yet
ll binsearch(ll l, ll r, function<bool (ll)> p) { // [l, r), p is monotone
    assert (l < r);
    -- l; -- r; // (l, r]
    while (l + 1 < r) {
        ll m = (l + r + 1) / 2;
        (p(m) ? r : l) = m;
    }
    return r; // = min { x | p(x) }
}
