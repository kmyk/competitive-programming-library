// https://kimiyuki.net/blog/2016/07/02/yuki-386/
// https://kimiyuki.net/blog/2016/05/18/arc-048-d/
template <typename T>
struct segment_tree { // on monoid
    int n;
    vector<T> a;
    function<T (T,T)> append; // associative
    T unit; // unit
    segment_tree() = default;
    segment_tree(int a_n, T a_unit, function<T (T,T)> a_append) {
        n = 1; while (n < a_n) n *= 2;
        a.resize(2*n-1, a_unit);
        unit = a_unit;
        append = a_append;
    }
    void point_update(int i, T z) { // 0-based
        a[i+n-1] = z;
        for (i = (i+n)/2; i > 0; i /= 2) {
            a[i-1] = append(a[2*i-1], a[2*i]);
        }
    }
    T range_concat(int l, int r) { // 0-based, [l, r)
        T lacc = unit, racc = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2) { // loop, 2x faster than recursion
            if (l % 2 == 1) lacc = append(lacc, a[(l ++) - 1]);
            if (r % 2 == 1) racc = append(a[(-- r) - 1], racc);
        }
        return append(lacc, racc);
    }
};

// https://kimiyuki.net/blog/2017/05/16/arc-068-e/
template <class Monoid>
struct segment_tree {
    typedef typename Monoid::type T;
    int n;
    vector<T> a;
    Monoid mon;
    segment_tree() = default;
    segment_tree(int a_n, Monoid const & a_mon = Monoid()) : mon(a_mon) {
        n = 1; while (n < a_n) n *= 2;
        a.resize(2*n-1, mon.unit());
    }
    void point_update(int i, T z) { // 0-based
        a[i+n-1] = z;
        for (i = (i+n)/2; i > 0; i /= 2) {
            a[i-1] = mon.append(a[2*i-1], a[2*i]);
        }
    }
    T range_concat(int l, int r) { // 0-based, [l, r)
        T lacc = mon.unit(), racc = mon.unit();
        for (l += n, r += n; l < r; l /= 2, r /= 2) { // loop, 2x faster than recursion
            if (l % 2 == 1) lacc = mon.append(lacc, a[(l ++) - 1]);
            if (r % 2 == 1) racc = mon.append(a[(-- r) - 1], racc);
        }
        return mon.append(lacc, racc);
    }
};

// http://dwacon2017-honsen.contest.atcoder.jp/tasks/dwango2017final_d
// http://yukicoder.me/problems/no/230
template <typename M, typename Q>
struct lazy_propagation_segment_tree { // on monoids
    int n;
    vector<M> a;
    vector<Q> q;
    function<M (M,M)> append_m; // associative
    function<Q (Q,Q)> append_q; // (\ x. q(x)) * (\ x. p(x)) -> (\ x. q(p(x))), associative, not necessarily commutative
    function<M (Q,M)> apply; // distributive, associative
    M unit_m; // unit
    Q unit_q; // unit
    lazy_propagation_segment_tree() = default;
    lazy_propagation_segment_tree(int a_n, M a_unit_m, Q a_unit_q, function<M (M,M)> a_append_m, function<Q (Q,Q)> a_append_q, function<M (Q,M)> a_apply) {
        n = pow(2,ceil(log2(a_n)));
        a.resize(2*n-1, a_unit_m);
        q.resize(max(0, 2*n-1-n), a_unit_q);
        unit_m = a_unit_m;
        unit_q = a_unit_q;
        append_m = a_append_m;
        append_q = a_append_q;
        apply = a_apply;
    }
    void range_apply(int l, int r, Q z) {
        assert (0 <= l and l <= r and r <= n);
        range_apply(0, 0, n, l, r, z);
    }
    void range_apply(int i, int il, int ir, int l, int r, Q z) {
        if (l <= il and ir <= r) {
            a[i] = apply(z, a[i]);
            if (i < q.size()) q[i] = append_q(z, q[i]);
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2*i+1, il, (il+ir)/2, 0, n, q[i]);
            range_apply(2*i+1, il, (il+ir)/2, l, r, z);
            range_apply(2*i+2, (il+ir)/2, ir, 0, n, q[i]);
            range_apply(2*i+2, (il+ir)/2, ir, l, r, z);
            a[i] = append_m(a[2*i+1], a[2*i+2]);
            q[i] = unit_q;
        }
    }
    M range_concat(int l, int r) {
        assert (0 <= l and l <= r and r <= n);
        return range_concat(0, 0, n, l, r);
    }
    M range_concat(int i, int il, int ir, int l, int r) {
        if (l <= il and ir <= r) {
            return a[i];
        } else if (ir <= l or r <= il) {
            return unit_m;
        } else {
            return apply(q[i], append_m(
                    range_concat(2*i+1, il, (il+ir)/2, l, r),
                    range_concat(2*i+2, (il+ir)/2, ir, l, r)));
        }
    }
};

// http://arc056.contest.atcoder.jp/submissions/1308018
template <class Monoid, class MagmaEndomorphism>
struct lazy_propagation_segment_tree { // on monoids
    static_assert (is_same<typename Monoid::type, typename MagmaEndomorphism::underlying_type>::value, "");
    typedef typename Monoid::type T;
    typedef typename MagmaEndomorphism::type F;
    Monoid mon;
    MagmaEndomorphism endo;
    int n;
    vector<T> a;
    vector<F> f;
    lazy_propagation_segment_tree() = default;
    lazy_propagation_segment_tree(int a_n, Monoid const & a_mon = Monoid(), MagmaEndomorphism const & a_endo = MagmaEndomorphism())
            : mon(a_mon), endo(a_endo) {
        n = 1; while (n <= a_n) n *= 2;
        a.resize(2*n-1, mon.unit());
        f.resize(max(0, 2*n-1-n), endo.identity());
    }
    void range_apply(int l, int r, F z) {
        assert (0 <= l and l <= r and r <= n);
        range_apply(0, 0, n, l, r, z);
    }
    void range_apply(int i, int il, int ir, int l, int r, F z) {
        if (l <= il and ir <= r) {
            a[i] = endo.apply(z, a[i]);
            if (i < f.size()) f[i] = endo.compose(z, f[i]);
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2*i+1, il, (il+ir)/2, 0, n, f[i]);
            range_apply(2*i+1, il, (il+ir)/2, l, r, z);
            range_apply(2*i+2, (il+ir)/2, ir, 0, n, f[i]);
            range_apply(2*i+2, (il+ir)/2, ir, l, r, z);
            a[i] = mon.append(a[2*i+1], a[2*i+2]);
            f[i] = endo.identity();
        }
    }
    T range_concat(int l, int r) {
        assert (0 <= l and l <= r and r <= n);
        return range_concat(0, 0, n, l, r);
    }
    T range_concat(int i, int il, int ir, int l, int r) {
        if (l <= il and ir <= r) {
            return a[i];
        } else if (ir <= l or r <= il) {
            return mon.unit();
        } else {
            return endo.apply(f[i], mon.append(
                    range_concat(2*i+1, il, (il+ir)/2, l, r),
                    range_concat(2*i+2, (il+ir)/2, ir, l, r)));
        }
    }
};
