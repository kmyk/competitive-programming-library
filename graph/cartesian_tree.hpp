#pragma once
#include <functional>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief Cartesian tree ($O(n)$)
 * @note the smallest value is the root
 * @note if a is not distinct, the way for tie-break is undefined
 * @return the binary tree as the list of parents
 */
template <class T, class Comparator = std::less<int> >
std::vector<int> construct_cartesian_tree(const std::vector<T> & a, const Comparator & cmp = Comparator()) {
    int n = a.size();
    std::vector<int> parent(n, -1);
    REP3 (i, 1, n) {
        int p = i - 1;  // parent of i
        int l = -1;  // left child of i
        while (p != -1 and cmp(a[i], a[p])) {
            int pp = parent[p];  // parent of parent of i
            if (l != -1) {
                parent[l] = p;
            }
            parent[p] = i;
            l = p;
            p = pp;
        }
        parent[i] = p;
    }
    return parent;
}
