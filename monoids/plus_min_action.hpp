#pragma once
#include "../monoids/plus.hpp"
#include "../monoids/min.hpp"

template <class T>
struct plus_min_action {
    typename min_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename min_monoid<T>::value_type x) const {
        return (x == min_monoid<T>().unit() ? x : f + x);
    }
};
