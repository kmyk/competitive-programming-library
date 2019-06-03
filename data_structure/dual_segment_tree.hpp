#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

template <class OperatorMonoid>
struct dual_segment_tree {
    typedef typename OperatorMonoid::underlying_type operator_type;
    typedef typename OperatorMonoid::target_type underlying_type;
    int n;
    std::vector<operator_type> f;
    std::vector<underlying_type> a;
    const OperatorMonoid op;
    dual_segment_tree() = default;
    dual_segment_tree(int a_n, underlying_type initial_value, OperatorMonoid const & a_op = OperatorMonoid()) : op(a_op) {
        n = 1; while (n < a_n) n *= 2;
        a.resize(n, initial_value);
        f.resize(n - 1, op.unit());
    }
    underlying_type point_get(int i) { // 0-based
        underlying_type acc = a[i];
        for (i = (i + n) / 2; i > 0; i /= 2) { // 1-based
            acc = op.apply(f[i - 1], acc);
        }
        return acc;
    }
    void range_apply(int l, int r, operator_type z) { // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        range_apply(0, 0, n, l, r, z);
    }
    void range_apply(int i, int il, int ir, int l, int r, operator_type z) {
        if (l <= il and ir <= r) { // 0-based
            if (i < f.size()) {
                f[i] = op.append(z, f[i]);
            } else {
                a[i - n + 1] = op.apply(z, a[i - n + 1]);
            }
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);
            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);
            f[i] = op.unit();
            range_apply(2 * i + 1, il, (il + ir) / 2, l, r, z);
            range_apply(2 * i + 2, (il + ir) / 2, ir, l, r, z);
        }
    }
    void point_set(int i, underlying_type z) {
        range_apply(i, i + 1, op.unit());  // to flush lazed ops
        a[i + n - 1] = z;  // bug??
    }
};


#include <climits>
#include <utility>

template <typename T> 
struct const_operator_monoid {
    // typedef std::optional<T> underlying_type;
    typedef std::pair<bool, T> underlying_type;
    typedef T target_type;
    underlying_type unit() const { return std::make_pair(false, target_type()); }
    underlying_type append(underlying_type a, underlying_type b) const { return a.first ? a : b; }
    target_type apply(underlying_type a, target_type b) const { return a.first ? a.second : b; }
};

struct plus_operator_monoid {
    typedef int underlying_type;
    typedef int target_type;
    int unit() const { return 0; }
    int append(int a, int b) const { return a + b; }
    int apply(int a, int b) const { return a + b; }
};
struct max_operator_monoid {
    typedef int underlying_type;
    typedef int target_type;
    int unit() const { return INT_MIN; }
    int append(int a, int b) const { return std::max(a, b); }
    int apply(int a, int b) const { return std::max(a, b); }
};
struct min_operator_monoid {
    typedef int underlying_type;
    typedef int target_type;
    int unit() const { return INT_MAX; }
    int append(int a, int b) const { return std::min(a, b); }
    int apply(int a, int b) const { return std::min(a, b); }
};

template <int MOD>
struct linear_operator_monoid {
    typedef std::pair<int64_t, int64_t> underlying_type;
    typedef int64_t target_type;
    linear_operator_monoid() = default;
    underlying_type unit() const {
        return std::make_pair(1, 0);
    }
    underlying_type append(underlying_type g, underlying_type f) const {
        target_type fst = g.first * f.first % MOD;
        target_type snd = (g.second + g.first * f.second) % MOD;
        return std::make_pair(fst, snd);
    }
    target_type apply(underlying_type f, target_type x) const {
        return (f.first * x + f.second) % MOD;
    }
};
