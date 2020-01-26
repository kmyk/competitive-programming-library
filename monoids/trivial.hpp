#pragma once

struct trivial_monoid {
    typedef struct {} value_type;
    value_type unit() const { return (value_type) {}; }
    value_type mult(value_type a, value_type b) const { return (value_type) {}; }
};
