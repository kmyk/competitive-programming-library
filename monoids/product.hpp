#pragma once
#include <utility>

template <class Monoid1, class Monoid2>
struct product_monoid {
    typedef std::pair<typename Monoid1::value_type, typename Monoid2::value_type> value_type;
    Monoid1 mon1;
    Monoid2 mon2;
    value_type unit() const {
        return std::make_pair(mon1.unit(), mon2.unit());
    }
    value_type mult(value_type a, value_type b) const {
        return std::make_pair(mon1.mult(a.first, b.first), mon2.mult(a.second, b.second));
    }
};
