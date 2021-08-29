#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief Segment Tree / セグメント木 (monoids, 完全二分木)
 * @docs data_structure/segment_tree.md
 * @tparam Monoid (commutativity is not required)
 */
template <class Monoid>
struct segment_tree {
    typedef typename Monoid::value_type value_type;
    Monoid mon;
    int n;
    std::vector<value_type> a;
    segment_tree() = default;
    segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1, mon.unit());
    }
    void point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
        for (i = (i + n) / 2; i > 0; i /= 2) {  // 1-based
            a[i - 1] = mon.mult(a[2 * i - 1], a[2 * i]);
        }
    }
    value_type range_get(int l, int r) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        value_type lacc = mon.unit(), racc = mon.unit();
        for (l += n, r += n; l < r; l /= 2, r /= 2) {  // 1-based loop, 2x faster than recursion
            if (l % 2 == 1) lacc = mon.mult(lacc, a[(l ++) - 1]);
            if (r % 2 == 1) racc = mon.mult(a[(-- r) - 1], racc);
        }
        return mon.mult(lacc, racc);
    }

    value_type point_get(int i) {  // 0-based
        assert (0 <= i and i < n);
        return a[i + n - 1];
    }

    /**
     * @note O(min(n, (r - l) log n))
     */
    void range_set(int l, int r, value_type b) {
        assert (0 <= l and l <= r and r <= n);
        range_set(0, 0, n, l, r, b);
    }
    void range_set(int i, int il, int ir, int l, int r, value_type b) {
        if (l <= il and ir <= r and ir - il == 1) {  // 0-based
            a[i] = b;
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_set(2 * i + 1, il, (il + ir) / 2, l, r, b);
            range_set(2 * i + 2, (il + ir) / 2, ir, l, r, b);
            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    /**
     * @brief a fast & semigroup-friendly version constructor
     * @note $O(n)$
     */
    template <class InputIterator>
    segment_tree(InputIterator first, InputIterator last, const Monoid & mon_ = Monoid()) : mon(mon_) {
        int size = std::distance(first, last);
        n = 1; while (n < size) n *= 2;
        a.resize(2 * n - 1, mon.unit());
        std::copy(first, last, a.begin() + (n - 1));
        unsafe_rebuild();
    }
    /**
     * @brief update a leaf node without updating ancestors
     * @note $O(1)$
     */
    void unsafe_point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
    }
    /**
     * @brief re-build non-leaf nodes from leaf nodes
     * @note $O(n)$
     */
    void unsafe_rebuild() {
        REP_R (i, n - 1) {
            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }
};
