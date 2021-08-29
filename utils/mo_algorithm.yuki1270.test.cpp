#define PROBLEM "https://yukicoder.me/problems/no/1270"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include "../utils/macros.hpp"
#include "../data_structure/segment_tree.hpp"
#include "../data_structure/lazy_propagation_segment_tree.hpp"
#include "../monoids/min.hpp"
#include "../monoids/plus.hpp"
#include "../monoids/plus_min_action.hpp"
#include "../utils/mo_algorithm.hpp"
using namespace std;


struct mo_struct {
    typedef int64_t value_type;
    typedef int64_t result_type;

private:
    typedef segment_tree<plus_monoid<int> > plus_segtree_type;
    typedef lazy_propagation_segment_tree<min_monoid<int64_t>, plus_monoid<int64_t>, plus_min_action<int64_t> > plus_min_segtree_type;

    // input
    int n;
    const vector<int64_t>& a;

    // static
    unordered_map<int64_t, int> compress;
    int k;
    vector<int64_t> dp_l;
    vector<int64_t> dp_r;

    // dynamic
    int l;
    int r;
    int64_t value_lr;
    plus_segtree_type segtree_l;
    plus_min_segtree_type segtree_m;
    plus_segtree_type segtree_r;

public:
    mo_struct(const vector<int64_t>& a_)
            : n(a_.size())
            , a(a_) {
        // static compress
        vector<int64_t> sorted_a = a;
        sort(ALL(sorted_a));
        for (int64_t a_i : sorted_a) {
            compress.emplace(a_i, compress.size());
        }
        k = compress.size();

        // static left
        dp_l.resize(n + 1);
        segtree_l = plus_segtree_type(k);
        segtree_l.range_set(0, k, 0);
        REP (i, n) {
            dp_l[i + 1] = dp_l[i] + segtree_l.range_get(compress[a[i]] + 1, k);
            segtree_l.point_set(compress[a[i]], segtree_l.point_get(compress[a[i]]) + 1);
        }
        segtree_l = plus_segtree_type(k);
        segtree_l.range_set(0, k, 0);

        // static right
        dp_r.resize(n + 1);
        segtree_r = plus_segtree_type(k);
        segtree_r.range_set(0, k, 0);
        REP_R (i, n) {
            dp_r[i] = dp_r[i + 1] + segtree_r.range_get(0, compress[a[i]]);
            segtree_r.point_set(compress[a[i]], segtree_r.point_get(compress[a[i]]) + 1);
        }

        // dynamic
        l = 0;
        r = 0;
        value_lr = 0;
        segtree_m = plus_min_segtree_type(k);
        segtree_m.range_set(0, k, 0);
        REP (i, n) {
            segtree_m.range_apply(compress[a[i]] + 1, k, 1);
        }
    }

    void add_right(int nr, int64_t x_r) {
        assert (nr == r + 1);
        int y = compress[x_r];
        value_lr -= segtree_l.range_get(y + 1, k);
        segtree_m.range_apply(y + 1, k, -1);
        segtree_r.point_set(y, segtree_r.point_get(y) - 1);
        r = nr;
    }

    void add_left(int nl, int64_t x_nl) {
        assert (nl == l - 1);
        int y = compress[x_nl];
        value_lr -= segtree_r.range_get(0, y);
        segtree_l.point_set(y, segtree_l.point_get(y) - 1);
        segtree_m.range_apply(0, y, -1);
        l = nl;
    }

    void remove_right(int nr, int64_t x_nr) {
        assert (nr == r - 1);
        int y = compress[x_nr];
        value_lr += segtree_l.range_get(y + 1, k);
        segtree_m.range_apply(y + 1, k, 1);
        segtree_r.point_set(y, segtree_r.point_get(y) + 1);
        r = nr;
    }

    void remove_left(int nl, int64_t x_l) {
        assert (nl == l + 1);
        int y = compress[x_l];
        value_lr += segtree_r.range_get(0, y);
        segtree_l.point_set(y, segtree_l.point_get(y) + 1);
        segtree_m.range_apply(0, y, 1);
        l = nl;
    }

    int64_t query() {
        int64_t ans = 0;
        ans += dp_l[l];  // the inversion number in [0, l)
        ans += dp_r[r];  // the inversion number in [r, n)
        ans += value_lr;  // the inversion number between [0, l) and [r, n)
        ans += (int64_t)(r - l) * segtree_m.range_get(0, k);  // the inversion number between [0, l) and [l, r) plus the inversion number between [l, r) and [r, n)
        return ans;
    }
};

vector<int64_t> solve(int n, int q, const vector<int64_t>& a, const vector<pair<int, int> >& queries) {
    return run_mo_algorithm(mo_struct(a), a, queries);
}

int main() {
    int n, q; cin >> n >> q;
    vector<int64_t> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    vector<pair<int, int> > queries(q);
    REP (i, q) {
        int l, r; cin >> l >> r;
        -- l;
        queries[i] = make_pair(l, r);
    }
    auto ans = solve(n, q, a, queries);
    REP (i, q) {
        cout << ans[i] << endl;
    }
    return 0;
}
