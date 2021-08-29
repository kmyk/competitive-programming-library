#pragma once
#include <cassert>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief Binary Indexed Tree
 */
template <typename CommutativeMonoid>
struct binary_indexed_tree {
    typedef typename CommutativeMonoid::value_type value_type;
    CommutativeMonoid mon;
    std::vector<value_type> data;
    binary_indexed_tree(int n, CommutativeMonoid const & mon_ = CommutativeMonoid())
            : mon(mon_),
              data(n, mon.unit()) {
    }
    template <class InputIterator>
    binary_indexed_tree(InputIterator first, InputIterator last, CommutativeMonoid const & mon_ = CommutativeMonoid())
            : mon(mon_),
              data(first, last) {
        REP3 (j, 1, data.size() + 1) {
            int k = j + (j & -j);
            if (k - 1 < static_cast<int>(data.size())) {
                data[k - 1] = mon.mult(data[k - 1], data[j - 1]);
            }
        }
    }
    /**
     * @note $a_i \gets a_i + z$
     * @note $O(\log N)$
     */
    void point_mult(int i, value_type z) {
        assert (0 <= i and i < static_cast<int>(data.size()));
        for (int j = i + 1; j <= static_cast<int>(data.size()); j += j & -j) {
            data[j - 1] = mon.mult(data[j - 1], z);
        }
    }
    /**
     * @note $\sum _ {i \lt r} a_i$
     * @note $O(\log N)$
     */
    value_type initial_range_get(int r) {
        assert (0 <= r and r <= static_cast<int>(data.size()));
        value_type acc = mon.unit();
        for (int i = r; 0 < i; i -= i & -i) {
            acc = mon.mult(data[i - 1], acc);
        }
        return acc;
    }
};
