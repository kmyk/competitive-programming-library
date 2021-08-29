#pragma once
#include <cassert>
#include "../utils/macros.hpp"

/**
 * @brief a binary search on floating point numbers / 二分探索 (浮動小数点数)
 */
template <int Iteration = 64, typename UnaryPredicate>
double binsearch_float(double l, double r, UnaryPredicate p) {
    assert (l <= r);
    REP (i, Iteration) {
        double m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r;
}
