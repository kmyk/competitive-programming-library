#pragma once
#include <cassert>
#include <climits>
#include <cstdint>
#include <deque>
#include <tuple>
#include <utility>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief Shortest Path Faster Algorithm
 * @note the interface is same to one of Bellman Ford
 */
std::vector<int64_t> shortest_path_faster_algorithm(int root, std::vector<std::vector<std::pair<int, int64_t> > > const & g) {
    assert (not g.empty());
    int n = g.size();
    std::vector<int64_t> dist(n, INT64_MAX);
    std::deque<int> cur, nxt;
    std::vector<bool> pushed(n);
    dist[root] = 0;
    nxt.push_back(root);
    pushed[root] = true;

    REP (iteration, 2 * n - 2) {
        cur.swap(nxt);
        while (not cur.empty()) {
            int x = cur.front();
            cur.pop_front();
            pushed[x] = false;
            for (const auto & edge : g[x]) {
                int y; int64_t cost; std::tie(y, cost) = edge;
                if ((dist[x] == INT64_MIN ? INT64_MIN : dist[x] + cost) < dist[y]) {
                    dist[y] = (iteration >= n - 1 ? INT64_MIN : dist[x] + cost);
                    if (not pushed[y]) {
                        if (not nxt.empty() and dist[y] < dist[nxt.front()]) {
                            // Small Label First
                            nxt.push_front(y);
                        } else {
                            nxt.push_back(y);
                        }
                        pushed[y] = true;
                    }
                }
            }
        }
        if (nxt.empty()) break;
    }

    return dist;
}
