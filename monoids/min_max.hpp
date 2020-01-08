#pragma once
#include <algorithm>
#include <numeric>
#include <utility>

template <class T>
struct min_max_monoid {
    typedef std::pair<T, T> value_type;
    value_type unit() const {
        return std::make_pair(std::numeric_limits<T>::max(), std::numeric_limits<T>::lowest());
    }
    value_type mult(value_type a, value_type b) const {
        return std::make_pair(std::min(a.min, b.min), std::max(a.max, b.max));
    }
};
