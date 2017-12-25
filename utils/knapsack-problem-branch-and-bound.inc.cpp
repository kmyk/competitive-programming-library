ll knapsack_problem_branch_and_bound(int n, ll max_w, vector<ll> const & a_v, vector<ll> const & a_w) {
    vector<ll> v(n), w(n); {
        vector<int> xs(n);
        iota(ALL(xs), 0);
        sort(ALL(xs), [&](int i, int j) {
            return a_v[i] *(double) a_w[j] > a_v[j] *(double) a_w[i];
        });
        REP (i, n) {
            v[i] = a_v[xs[i]];
            w[i] = a_w[xs[i]];
        }
    }
    ll ans = 0;
    function<void (int, ll, ll)> go = [&](int i, ll cur_v, ll cur_w) {
        if (max_w < cur_w) return; // not executable
        if (i == n) {
            chmax(ans, cur_v);
            return; // terminate
        }
        ll lr_v = cur_v; // linear relaxation
        ll lr_w = cur_w;
        int j = i;;
        for (; j < n and lr_w + w[j] <= max_w; ++ j) { // greedy
            lr_w += w[j];
            lr_v += v[j];
        }
        if (lr_w == max_w or j == n) {
            chmax(ans, lr_v);
            return; // accept greedy
        }
        double lr_ans = lr_v + v[j] * ((max_w - lr_w) /(double) w[j]);
        if (lr_ans <= ans) return; // bound
        go(i + 1, cur_v + v[i], cur_w + w[i]);
        go(i + 1, cur_v,        cur_w       );
    };
    go(0, 0, 0);
    return ans;
}
