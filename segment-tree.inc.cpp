// https://kimiyuki.net/blog/2016/07/02/yuki-386/
// https://kimiyuki.net/blog/2016/05/18/arc-048-d/
template <typename T>
struct segment_tree { // on monoid
    int n;
    vector<T> a;
    function<T (T,T)> append; // associative
    T unit; // unit
    segment_tree() = default;
    template <typename F>
    segment_tree(int a_n, T a_unit, F a_append) {
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

// http://yukicoder.me/submissions/114337
template <typename T>
struct lazed_segment_tree { // on associative symmetric operation
    int n;
    vector<T> a;
    function<T (T,T)> append; // associative, symmetric
    co_segment_tree() = default;
    template <typename F>
    co_segment_tree(int a_n, T a_init, F a_append) {
        n = pow(2,ceil(log2(a_n)));
        a.resize(2*n-1, a_init);
        append = a_append;
    }
    void range_update(int l, int r, T z) {
        range_update(0, 0, n, l, r, z);
    }
    void range_update(int i, int il, int ir, int l, int r, T z) {
        if (l <= il and ir <= r) {
            a[i] = append(a[i], z);
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_update(2*i+1, il, (il+ir)/2, l, r, z);
            range_update(2*i+2, (il+ir)/2, ir, l, r, z);
        }
    }
    T point_concat(int i) {
        T z = a[i+n-1];
        for (i = (i+n)/2; i > 0; i /= 2) {
            z = append(z, a[i-1]);
        }
        return z;
    }
};
