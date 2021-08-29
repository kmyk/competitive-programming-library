#pragma once
#include <set>
#include <vector>
#include "utils/macros.hpp"

bool is_simple_graph(const std::vector<std::vector<int>> &g) {
    int n = g.size();
    REP (x, n) {
        std::set<int> used;
        for (int y : g[x]) {
            if (y == x or used.count(y)) {
                return false;
            }
            used.insert(y);
        }
    }
    return true;
}
