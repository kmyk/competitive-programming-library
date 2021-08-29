#pragma once
#include "../number/matrix_template.hpp"

template <class T, int N>
struct matrix_monoid {
    typedef matrix<T, N, N> value_type;
    value_type f;
    value_type unit() const {
        return unit_matrix<T, N>();
    }
    value_type mult(const value_type & f, const value_type & g) const {
        return f * g;
    }
};
