#pragma once
#include <cstdint>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

/**
 * @brief Dijkstra ($O((E + V) \log V)$)
 */
template <class T = int64_t>
std::vector<T> dijkstra(std::vector<std::vector<std::pair<int, T> > > const & g, int root) {
    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());
    std::priority_queue<std::pair<T, int> > que;
    dist[root] = 0;
    que.emplace(- dist[root], root);
    while (not que.empty()) {
        T dist_x; int x; std::tie(dist_x, x) = que.top(); que.pop();
        if (dist[x] < - dist_x) continue;
        for (auto it : g[x]) {
            int y; T cost; std::tie(y, cost) = it;
            if (- dist_x + cost < dist[y]) {
                dist[y] = - dist_x + cost;
                que.emplace(dist_x - cost, y);
            }
        }
    }
    return dist;
}
