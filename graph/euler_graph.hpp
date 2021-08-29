#pragma once
#include <algorithm>
#include <tuple>
#include <utility>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @param g must be an undirected graph. Loops and multiple edges are acceptable.
 * @param root specifies the component to find an Eulerian cycle
 * @return indices of edges. It's empty if g is not a Eulerian graph.
 */
std::vector<int> find_eulerian_cycle_with_root(int n, const std::vector<std::pair<int, int> > & edges, int root) {
    int m = edges.size();
    std::vector<std::vector<int> > g(n);
    std::vector<int> degree(n);
    REP (i, m) {
        int x, y; std::tie(x, y) = edges[i];
        g[x].push_back(i);
        g[y].push_back(i);
        ++ degree[x];
        ++ degree[y];  // This is required even if x == y
    }

    std::vector<int> order;
    std::vector<bool> used(m);
    auto go = [&](auto && go, int x) -> bool {
        if (degree[x] % 2 != 0) {
            return false;
        }
        while (not g[x].empty()) {
            int i = g[x].back();
            g[x].pop_back();
            if (not used[i]) {
                used[i] = true;
                int y = x ^ edges[i].first ^ edges[i].second;
                if (not go(go, y)) {
                    return false;
                }
                order.push_back(i);
            }
        }
        return true;
    };
    if (not go(go, root)) {
        return std::vector<int>();  // not a Eulerian graph
    }
    return order;
}

/**
 * @brief Eulerian cycle (無向, 復元)
 * @param g must be an undirected and connected graph.
 * @return indices of edges. It's empty if g is not a Eulerian graph.
 */
std::vector<int> find_eulerian_cycle(int n, const std::vector<std::pair<int, int> > & edges) {
    auto order = find_eulerian_cycle_with_root(n, edges, 0);
    if (order.size() != edges.size()) {
        return std::vector<int>();
    }
    return order;
}
