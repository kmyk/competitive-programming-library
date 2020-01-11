#pragma once
#include <algorithm>
#include <climits>
#include <limits>
#include <utility>

/**
 * @note a semilattice
 */
template <class T>
struct max_index_monoid {
    typedef std::pair<T, int> value_type;
    value_type unit() const { return std::make_pair(std::numeric_limits<T>::lowest(), INT_MIN); }
    value_type mult(value_type a, value_type b) const { return std::max(a, b); }
};
