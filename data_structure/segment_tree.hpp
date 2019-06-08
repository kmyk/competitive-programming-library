#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief a segment tree
 * @tparam Monoid (commutativity is not required)
 */
template <class Monoid>
struct segment_tree {
    typedef typename Monoid::value_type value_type;
    int n;
    std::vector<value_type> a;
    const Monoid mon;
    segment_tree() = default;
    segment_tree(int a_n, value_type initial_value = Monoid().unit(), Monoid const & a_mon = Monoid()) : mon(a_mon) {
        n = 1; while (n < a_n) n *= 2;
        a.resize(2 * n - 1, mon.unit());
        std::fill(a.begin() + (n - 1), a.begin() + ((n - 1) + a_n), initial_value); // set initial values
        REP_R (i, n - 1) a[i] = mon.append(a[2 * i + 1], a[2 * i + 2]); // propagate initial values
    }
    void point_set(int i, value_type z) { // 0-based
        assert (0 <= i and i <= n);
        a[i + n - 1] = z;
        for (i = (i + n) / 2; i > 0; i /= 2) { // 1-based
            a[i - 1] = mon.append(a[2 * i - 1], a[2 * i]);
        }
    }
    value_type range_concat(int l, int r) { // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        value_type lacc = mon.unit(), racc = mon.unit();
        for (l += n, r += n; l < r; l /= 2, r /= 2) { // 1-based loop, 2x faster than recursion
            if (l % 2 == 1) lacc = mon.append(lacc, a[(l ++) - 1]);
            if (r % 2 == 1) racc = mon.append(a[(-- r) - 1], racc);
        }
        return mon.append(lacc, racc);
    }
};


#include <climits>

struct plus_monoid {
    typedef int value_type;
    int unit() const { return 0; }
    int append(int a, int b) const { return a + b; }
};
struct max_monoid {
    typedef int value_type;
    int unit() const { return INT_MIN; }
    int append(int a, int b) const { return std::max(a, b); }
};
struct min_monoid {
    typedef int value_type;
    int unit() const { return INT_MAX; }
    int append(int a, int b) const { return std::min(a, b); }
};
