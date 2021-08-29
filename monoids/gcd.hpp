#pragma once
#include "../number/gcd.hpp"

/**
 * @note a semilattice
 */
template <class Integer>
struct gcd_monoid {
    typedef Integer value_type;
    Integer unit() const { return 0; }
    Integer mult(Integer a, Integer b) const { return gcd(a, b); }
};
