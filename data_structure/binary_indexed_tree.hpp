#pragma once
#include <vector>

/**
 * @brief binary indexed tree
 */
template <typename Monoid>
struct binary_indexed_tree {
    typedef typename Monoid::value_type value_type;
    std::vector<value_type> data;
    Monoid mon;
    binary_indexed_tree(size_t n, Monoid const & a_mon = Monoid())
            : mon(a_mon) {
        data.resize(n, mon.unit());
    }
    /**
     * @note a_i \gets z
     */
    void point_mult(size_t i, value_type z) {
        for (size_t j = i + 1; j <= data.size(); j += j & -j) {
            data[j - 1] = mon.mult(data[j - 1], z);
        }
    }
    /**
     * @note \sum _ {j \lt i} a_j
     */
    value_type initial_range_get(size_t i) {
        value_type acc = mon.unit();
        for (size_t j = i; 0 < j; j -= j & -j) acc = mon.mult(data[j - 1], acc);
        return acc;
    }
};
