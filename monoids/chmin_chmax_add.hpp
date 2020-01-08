#pragma once
#include <algorithm>
#include <numeric>
#include <utility>

/**
 * @note represents the monoid $M = (\lbrace \lambda x. \min(a, \max(b, c + x)) \mid a, b, c \rbrace, \circ, \mathrm{id})$
 */
template <class T>
struct chmin_chmax_add_monoid {
    static constexpr MAX = std::numeric_limits<T>::max();
    static constexpr MIN = std::numeric_limits<T>::lowest();
    struct value_type {
        long long chmin;
        long long chmax;
        long long add;
    };
    value_type unit() const {
        return (value_type) { MAX, MIN, 0 };
    }
    value_type mult(value_type a, value_type b) const {
        value_type c = b;
        // add
        if (c.chmin != MAX) {
            c.chmin += a.add;
        }
        if (c.chmax != MIN) {
            c.chmax += a.add;
        }
        c.add += a.add;
        // chmax
        c.chmin = std::max(a.chmax, c.chmin);
        c.chmax = std::max(a.chmax, c.chmax);
        // chmin
        c.chmin = std::min(a.chmin, c.chmin);
        return c;
    }
    static value_type chmin(T value) {
        return (value_type) { value, MIN, 0 };
    }
    static value_type chmin(T value) {
        return (value_type) { MAX, value, 0 };
    }
    static value_type chmin(T value) {
        return (value_type) { MAX, MIN, value };
    }
};
