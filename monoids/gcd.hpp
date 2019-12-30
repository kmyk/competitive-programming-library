#pragma once
#include "number/gcd.hpp"

/**
 * @note a semilattice
 */
struct gcd_monoid {
    typedef int value_type;
    int unit() const { return 0; }
    int mult(int a, int b) const { return gcd(a, b); }
};
