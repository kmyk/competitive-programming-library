#pragma once
#include <cassert>

/**
 * @brief Minimum Excluded Value ($O(n)$ for a given sorted container)
 * @sa https://en.wikipedia.org/wiki/Mex_(mathematics)
 * @note xs must be weakly increasing
 */
template <typename InputIterator>
int mex(InputIterator first, InputIterator last) {
    int last_x = 0;  // only for debug
    int y = 0;
    for (; first != last; ++ first) {
        int x = *first;
        assert (last_x <= x);
        last_x = x;
        if (y < x) break;
        if (y == x) ++ y;
    }
    return y;
}
