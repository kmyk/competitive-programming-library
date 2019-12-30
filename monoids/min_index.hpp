#pragma once
#include <algorithm>
#include <climits>
#include <limits>
#include <utility>

/**
 * @note a semilattice
 */
template <class T>
struct min_index_monoid {
    typedef std::pair<T, int> value_type;
    value_type unit() const { return std::make_pair(std::numeric_limits<T>::max(), INT_MAX); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};
