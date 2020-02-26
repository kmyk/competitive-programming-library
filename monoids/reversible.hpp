#pragma once
#include <utility>

template <class Monoid>
struct reversible_monoid {
    typedef typename Monoid::value_type base_type;
    typedef std::pair<base_type, base_type> value_type;
    Monoid base;
    reversible_monoid() = default;
    reversible_monoid(const Monoid & base_) : base(base_) {}
    value_type unit() const { return std::make_pair(base.unit(), base.unit()); }
    value_type mult(const value_type & a, const value_type & b) const { return std::make_pair(base.mult(a.first, b.first), base.mult(b.second, a.second)); }
    static value_type make(const base_type & x) { return std::make_pair(x, x); }
    static value_type reverse(const value_type & a) { return std::make_pair(a.second, a.first); }
    static base_type get(const value_type & a) { return a.first; }
};
