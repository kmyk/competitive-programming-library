#pragma once
#include <algorithm>
#include <cassert>
#include <type_traits>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief Lazy Propagation Segment Tree / 遅延伝播セグメント木 (monoids, 完全二分木)
 * @docs data_structure/lazy_propagation_segment_tree.md
 * @tparam MonoidX is a monoid
 * @tparam MonoidF is a monoid
 * @tparam Action is a function phi : F * X -> X where the partial applied phi(f, -) : X -> X is a homomorphism on X
 */
template <class MonoidX, class MonoidF, class Action>
struct lazy_propagation_segment_tree {
    static_assert (std::is_invocable_r<typename MonoidX::value_type, Action, typename MonoidF::value_type, typename MonoidX::value_type>::value, "");
    typedef typename MonoidX::value_type value_type;
    typedef typename MonoidF::value_type operator_type;
    MonoidX mon_x;
    MonoidF mon_f;
    Action act;
    int n;
    std::vector<value_type> a;
    std::vector<operator_type> f;

    lazy_propagation_segment_tree() = default;
    lazy_propagation_segment_tree(int n_, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_ = MonoidF(), const Action & act_ = Action())
            : mon_x(mon_x_), mon_f(mon_f_), act(act_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1, mon_x.unit());
        f.resize(n - 1, mon_f.unit());
    }
    template <class InputIterator>
    lazy_propagation_segment_tree(InputIterator first, InputIterator last, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_ = MonoidF(), const Action & act_ = Action())
            : mon_x(mon_x_), mon_f(mon_f_), act(act_) {
        int size = std::distance(first, last);
        n = 1; while (n < size) n *= 2;
        a.resize(2 * n - 1, mon_x.unit());
        f.resize(n - 1, mon_f.unit());
        std::copy(first, last, a.begin() + (n - 1));
        REP_R (i, n - 1) {
            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    void point_set(int i, value_type b) {
        range_set(i, i + 1, b);
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
            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);
            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);
            f[i] = mon_f.unit();
            range_set(2 * i + 1, il, (il + ir) / 2, l, r, b);
            range_set(2 * i + 2, (il + ir) / 2, ir, l, r, b);
            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    void point_apply(int i, operator_type g) {
        range_apply(i, i + 1, g);
    }
    void range_apply(int l, int r, operator_type g) {
        assert (0 <= l and l <= r and r <= n);
        range_apply(0, 0, n, l, r, g);
    }
    void range_apply(int i, int il, int ir, int l, int r, operator_type g) {
        if (l <= il and ir <= r) { // 0-based
            a[i] = act(g, a[i]);
            if (i < f.size()) f[i] = mon_f.mult(g, f[i]);
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);
            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);
            f[i] = mon_f.unit();  // unnecessary if the oprator monoid is commutative
            range_apply(2 * i + 1, il, (il + ir) / 2, l, r, g);
            range_apply(2 * i + 2, (il + ir) / 2, ir, l, r, g);
            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    value_type point_get(int i) {
        return range_get(i, i + 1);
    }
    value_type range_get(int l, int r) {
        assert (0 <= l and l <= r and r <= n);
        if (l == 0 and r == n) return a[0];
        value_type lacc = mon_x.unit(), racc = mon_x.unit();
        for (int l1 = (l += n), r1 = (r += n) - 1; l1 > 1; l /= 2, r /= 2, l1 /= 2, r1 /= 2) {  // 1-based loop, 2x faster than recursion
            if (l < r) {
                if (l % 2 == 1) lacc = mon_x.mult(lacc, a[(l ++) - 1]);
                if (r % 2 == 1) racc = mon_x.mult(a[(-- r) - 1], racc);
            }
            lacc = act(f[l1 / 2 - 1], lacc);
            racc = act(f[r1 / 2 - 1], racc);
        }
        return mon_x.mult(lacc, racc);
    }
};
