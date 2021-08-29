#pragma once
#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include "../monoids/chmin_chmax_add.hpp"
#include "../monoids/min_max.hpp"

template <class T>
struct chmin_chmax_add_min_max_action {
    typedef typename chmin_chmax_add_monoid<T>::value_type F;
    typedef typename min_max_monoid<T>::value_type X;
    X operator () (F f, X x) const {
        if (x.first == std::numeric_limits<T>::max()) {
            assert (x.second == std::numeric_limits<T>::lowest());
            return x;
        }
        T a = std::min(f.chmin, std::max(f.chmax, f.add + x.first));
        T b = std::min(f.chmin, std::max(f.chmax, f.add + x.second));
        return std::make_pair(a, b);
    }
};
