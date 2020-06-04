#pragma once
#include <stack>
#include <vector>
#include "utils/macros.hpp"

/**
 * @param g is an undirected graph
 */
int count_connected_components(const std::vector<std::vector<int> > & g) {
    int n = g.size();
    int cnt = 0;
    std::vector<bool> used(n);
    std::stack<int> stk;
    REP (z, n) if (not used[z]) {
        ++ cnt;
        used[z] = true;
        stk.push(z);
        while (not stk.empty()) {
            int x = stk.top();
            stk.pop();
            for (int y : g[x]) if (not used[y]) {
                used[y] = true;
                stk.push(y);
            }
        }
    }
    return cnt;
}

/**
 * @param g is an undirected graph
 */
bool is_connected_graph(const std::vector<std::vector<int> > & g) {
    return count_connected_components(g) == 1;
}
