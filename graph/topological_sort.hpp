#pragma once
#include <algorithm>
#include <functional>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief topological sort
 * @return a list of vertices which sorted topologically
 * @note the empty list is returned if cycles exist
 * @note $O(V + E)$
 */
std::vector<int> topological_sort(const std::vector<std::vector<int> > & g) {
    int n = g.size();
    std::vector<int> order;
    std::vector<char> used(n);
    std::function<bool (int)> go = [&](int i) {
        used[i] = 1;  // in stack
        for (int j : g[i]) {
            if (used[j] == 1) return true;
            if (not used[j]) {
                if (go(j)) return true;
            }
        }
        used[i] = 2;  // completely used
        order.push_back(i);
        return false;
    };
    REP (i, n) if (not used[i]) {
        if (go(i)) return std::vector<int>();
    }
    std::reverse(ALL(order));
    return order;
}
