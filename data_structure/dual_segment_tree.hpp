#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

template <class OperatorMonoid>
struct dual_segment_tree {
    typedef typename OperatorMonoid::value_type operator_type;
    typedef typename OperatorMonoid::target_type value_type;
    int n;
    std::vector<operator_type> f;
    std::vector<value_type> a;
    const OperatorMonoid op;
    dual_segment_tree() = default;
    dual_segment_tree(int a_n, value_type initial_value, OperatorMonoid const & a_op = OperatorMonoid()) : op(a_op) {
        n = 1; while (n < a_n) n *= 2;
        a.resize(n, initial_value);
        f.resize(n - 1, op.unit());
    }
    value_type point_get(int i) { // 0-based
        value_type acc = a[i];
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
    void point_set(int i, value_type z) {
        range_apply(i, i + 1, op.unit());  // to flush lazed ops
        a[i + n - 1] = z;  // bug??
    }
};


#include <climits>
#include <utility>

template <typename T>
struct const_operator_monoid {
    // typedef std::optional<T> value_type;
    typedef std::pair<bool, T> value_type;
    typedef T target_type;
    value_type unit() const { return std::make_pair(false, target_type()); }
    value_type append(value_type a, value_type b) const { return a.first ? a : b; }
    target_type apply(value_type a, target_type b) const { return a.first ? a.second : b; }
};

struct plus_operator_monoid {
    typedef int value_type;
    typedef int target_type;
    value_type unit() const { return 0; }
    value_type append(value_type a, value_type b) const { return a + b; }
    target_type apply(value_type a, target_type b) const { return a + b; }
};
struct max_operator_monoid {
    typedef int value_type;
    typedef int target_type;
    value_type unit() const { return INT_MIN; }
    value_type append(value_type a, value_type b) const { return std::max(a, b); }
    target_type apply(value_type a, target_type b) const { return std::max(a, b); }
};
struct min_operator_monoid {
    typedef int value_type;
    typedef int target_type;
    value_type unit() const { return INT_MAX; }
    value_type append(value_type a, value_type b) const { return std::min(a, b); }
    target_type apply(value_type a, target_type b) const { return std::min(a, b); }
};

template <int MOD>
struct linear_operator_monoid {
    typedef std::pair<int64_t, int64_t> value_type;
    typedef int64_t target_type;
    linear_operator_monoid() = default;
    value_type unit() const {
        return std::make_pair(1, 0);
    }
    value_type append(value_type g, value_type f) const {
        int64_t fst = g.first * f.first % MOD;
        int64_t snd = (g.second + g.first * f.second) % MOD;
        return std::make_pair(fst, snd);
    }
    target_type apply(value_type f, target_type x) const {
        return (f.first * x + f.second) % MOD;
    }
};
