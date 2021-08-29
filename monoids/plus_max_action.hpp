#pragma once
#include "../monoids/plus.hpp"
#include "../monoids/max.hpp"

/**
 * @note lazy_propagation_segment_tree<max_monoid<T>, plus_monoid<T>, plus_max_action<T> > is a starry sky tree
 */
template <class T>
struct plus_max_action {
    typename max_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename max_monoid<T>::value_type x) const {
        return (x == max_monoid<T>().unit() ? x : f + x);
    }
};
