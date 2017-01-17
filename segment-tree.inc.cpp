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
        n = pow(2,ceil(log2(a_n)));
        a.resize(2*n-1, a_unit);
        unit = a_unit;
        append = a_append;
    }
    void point_update(int i, T z) {
        a[i+n-1] = z;
        for (i = (i+n)/2; i > 0; i /= 2) {
            a[i-1] = append(a[2*i-1], a[2*i]);
        }
    }
    T range_concat(int l, int r) {
        return range_concat(0, 0, n, l, r);
    }
    T range_concat(int i, int il, int ir, int l, int r) {
        if (l <= il and ir <= r) {
            return a[i];
        } else if (ir <= l or r <= il) {
            return unit;
        } else {
            return append(
                    range_concat(2*i+1, il, (il+ir)/2, l, r),
                    range_concat(2*i+2, (il+ir)/2, ir, l, r));
        }
    }
};

// http://dwacon2017-honsen.contest.atcoder.jp/tasks/dwango2017final_d
template <typename M, typename Q>
struct lazy_propagation_segment_tree { // on monoids
    int n;
    vector<M> a;
    vector<Q> q;
    function<M (M,M)> append_m; // associative
    function<Q (Q,Q)> append_q; // associative, not necessarily commutative
    function<M (Q,M)> apply; // distributive, associative
    M unit_m; // unit
    Q unit_q; // unit
    lazy_propagation_segment_tree() = default;
    lazy_propagation_segment_tree(int a_n, M a_unit_m, Q a_unit_q, function<M (M,M)> a_append_m, function<Q (Q,Q)> a_append_q, function<M (Q,M)> a_apply) {
        n = pow(2,ceil(log2(a_n)));
        a.resize(2*n-1,     a_unit_m);
        // q.resize(2*(n-1)-1, a_unit_q);
        q.resize(2*n-1, a_unit_q);
        unit_m = a_unit_m;
        unit_q = a_unit_q;
        append_m = a_append_m;
        append_q = a_append_q;
        apply = a_apply;
    }
    void range_apply(int l, int r, Q z) {
        range_apply(0, 0, n, l, r, z);
    }
    void range_apply(int i, int il, int ir, int l, int r, Q z) {
        if (l <= il and ir <= r) {
            a[i] = apply(z, a[i]);
            // if (i < q.size()) q[i] = append_q(z, q[i]);
            q[i] = append_q(z, q[i]);
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
