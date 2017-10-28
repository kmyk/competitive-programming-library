struct convex_hull_trick_with_monotonicity {
    convex_hull_trick_with_monotonicity() {
        last_x = LLONG_MIN;
    }
    void add_line(ll a, ll b) {
        assert (lines.empty() or lines.back().first >= a);  // weakly monotonically decreasing
        while (lines.size() >= 2 and not is_required(*(lines.end() - 2), lines.back(), { a, b })) {
            lines.pop_back();
        }
        lines.emplace_back(a, b);
    }
    ll get_min(ll x) {
        assert (last_x <= x); last_x = x;  // weakly monotonically increasing
        while (lines.size() >= 2 and get_value(0, x) > get_value(1, x)) {
            lines.pop_front();
        }
        return get_value(0, x);
    }
private:
    typedef pair<ll, ll> line_t;
    bool is_required(line_t f1, line_t f2, line_t f3) {
        return (f2.first - f1.first) * (f3.second - f2.second) < (f2.second - f1.second) * (f3.first - f2.first);
    }
    ll get_value(int i, ll x) {
        ll a, b; tie(a, b) = lines[i];
        return a * x + b;
    }
    deque<line_t> lines;
    ll last_x;  // for the assertion
};
unittest {
    default_random_engine gen;
    repeat (iteration, 1000) {
        vector<pair<int, int> > lines;
        repeat (i, 30) {
            int a = uniform_int_distribution<int>(- 30, 30)(gen);
            int b = uniform_int_distribution<int>(- 30, 30)(gen);
            lines.emplace_back(a, b);
        }
        sort(whole(lines));
        reverse(whole(lines));
        convex_hull_trick_with_monotonicity cht;
        int x = - 100;
        repeat (i, 30) {
            int y = INT_MAX;
            repeat (j, i + 1) {
                int a, b; tie(a, b) = lines[j];
                setmin(y, a * x + b);
            }
            int a, b; tie(a, b) = lines[i];
            cht.add_line(a, b);
            assert (cht.get_min(x) == y);
            x += uniform_int_distribution<int>(0, 5)(gen);
        }
    }
}
