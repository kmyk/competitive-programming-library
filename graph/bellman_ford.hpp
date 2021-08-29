#pragma once
#include <cassert>
#include <climits>
#include <cstdint>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief Bellman-Ford algorithm
 * @note O(V E)
 * @arg g is a digraph with possibly negative cost edges
 * @note INT64_MIN for negative loops
 * @note INT64_MAX for unreachable nodes
 */
std::vector<int64_t> bellman_ford_shortest_path(int root, std::vector<std::vector<std::pair<int, int64_t> > > const & g) {
    assert (not g.empty());
    int n = g.size();
    std::vector<int64_t> dist(n, INT64_MAX);

    // update n - 1 times
    dist[root] = 0;
    REP (iteration, n - 1) {
        REP (i, n) if (dist[i] != INT64_MAX) {
            for (auto edge : g[i]) {
                int j; int64_t cost; std::tie(j, cost) = edge;
                dist[j] = std::min(dist[j], dist[i] + cost);
            }
        }
    }

    // propagate effects of negative cycles
    std::stack<int> stk;
    REP (i, n) if (dist[i] != INT64_MAX) {
        stk.push(i);
    }
    while (not stk.empty()) {
        int i = stk.top();
        stk.pop();
        for (auto edge : g[i]) {
            int j; int64_t cost; std::tie(j, cost) = edge;
            if (dist[j] != INT64_MIN) {
                if (dist[i] == INT64_MIN or dist[i] + cost < dist[j]) {
                    dist[j] = INT64_MIN;
                    stk.push(j);
                }
            }
        }
    }

    return dist;
}
