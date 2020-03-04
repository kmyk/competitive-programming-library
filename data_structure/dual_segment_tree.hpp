#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

/**
 * @brief Dual Segment Tree / 双対セグメント木 (monoids, 完全二分木)
 * @docs data_structure/dual_segment_tree.md
 * @tparam Monoid (commutativity is not required)
 */
template <class Monoid>
struct dual_segment_tree {
    typedef typename Monoid::value_type value_type;
    const Monoid mon;
    int n;
    std::vector<value_type> f;
    dual_segment_tree() = default;
    dual_segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {
        n = 1; while (n < n_) n *= 2;
        f.resize(2 * n - 1, mon.unit());
    }
    value_type point_get(int i) {  // 0-based
        assert (0 <= i and i < n);
        value_type acc = mon.unit();
        for (i += n; i > 0; i /= 2) {  // 1-based
            acc = mon.mult(f[i - 1], acc);
        }
        return acc;
    }
    void range_apply(int l, int r, value_type g) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        range_apply(0, 0, n, l, r, g);
    }
    void range_apply(int i, int il, int ir, int l, int r, value_type g) {
        if (l <= il and ir <= r) {  // 0-based
            f[i] = mon.mult(g, f[i]);
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);
            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);
            f[i] = mon.unit();
            range_apply(2 * i + 1, il, (il + ir) / 2, l, r, g);
            range_apply(2 * i + 2, (il + ir) / 2, ir, l, r, g);
        }
    }
};
