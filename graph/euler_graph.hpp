#pragma once
#include <algorithm>
#include <tuple>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

/**
 * @param g must be an undirected graph
 * @param root specifies the component to find an Euler cycle
 * @return indices of edges. It's empty if g is not a Euler graph.
 */
std::vector<int> find_euler_cycle_with_root(int n, const std::vector<std::pair<int, int> > & edges, int root) {
    int m = edges.size();
    std::vector<std::vector<int> > g(n);
    REP (i, m) {
        int x, y; std::tie(x, y) = edges[i];
        g[x].push_back(i);
        g[y].push_back(i);
    }

    std::vector<int> order;
    std::vector<bool> used(m);
    auto go = [&](auto && go, int x, int start) -> bool {
        if (g[x].size() % 2 != 0) {
            return false;
        }
        while (not g[x].empty()) {
            int i = g[x].back();
            g[x].pop_back();
            if (not used[i]) {
                order.push_back(i);
                used[i] = true;
                int y = x ^ edges[i].first ^ edges[i].second;
                if (y != start) {
                    if (not go(go, y, start)) {
                        return false;
                    }
                }
                start = x;
            }
        }
        return true;
    };
    if (not go(go, root, root)) {
        return std::vector<int>();
    }
    return order;
}

/**
 * @brief Euler cycle (+ 復元)
 * @param g must be an undirected and connected graph.
 * @return indices of edges. It's empty if g is not a Euler graph.
 */
std::vector<int> find_euler_cycle(int n, const std::vector<std::pair<int, int> > & edges) {
    auto order = find_euler_cycle_with_root(n, edges, 0);
    if (order.size() != edges.size()) {
        return std::vector<int>();
    }
    return order;
}
