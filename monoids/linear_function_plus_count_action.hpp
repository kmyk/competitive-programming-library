#pragma once
#include <utility>
#include "../monoids/linear_function.hpp"

/**
 * @note lazy_propagation_segment_tree<plus_count_monoid<T>, linear_function_monoid<T>, linear_function_plus_count_action<T> >
 */
template <class T>
struct linear_function_plus_count_action {
    typename plus_count_monoid<T>::value_type operator () (typename linear_function_monoid<T>::value_type f, typename plus_count_monoid<T>::value_type x) const {
        return std::make_pair(f.first * x.first + f.second * x.second, x.second);
    }
};
