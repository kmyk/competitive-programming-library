#pragma once
#include <cassert>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <utility>
#include <vector>

/**
 * @brief K shortest simple paths (Yen's algorithm + Dijkstra, $O(K V (E + V) \log V)$)
 * @param g is an adjacent list of a simple undirected graph
 * @return simple paths. If there are only less than K paths, return all paths in sorted order.
 */
template <class T>
std::vector<std::vector<int> > yen_algorithm_with_dijkstra(const std::vector<std::vector<std::pair<int, T> > > & g, int start, int goal, int k) {
    using namespace std;
    using reversed_priority_queue = priority_queue<pair<T, int> , vector<pair<T, int> >, greater<pair<T, int> > >;

    // trivial cases
    if (k == 0) return vector<vector<int> >();
    if (start == goal) {
        return vector<vector<int> >(1, vector<int>(1, start));
    }
    assert (k >= 1);

    // prepare
    int n = g.size();
    auto dijkstra = [&](int start, const set<int> & removed_vertices, const set<pair<int, int> > & removed_edges) -> pair<T, vector<int> > {
        // dijkstra
        vector<pair<T, int> > dist(n, make_pair(numeric_limits<T>::max(), -1));
        reversed_priority_queue que;
        dist[start] = make_pair(0, -1);
        que.emplace(0, start);
        while (not que.empty()) {
            auto [dist_x, x] = que.top();
            que.pop();
            if (dist[x].first < dist_x) continue;
            for (auto [y, cost] : g[x]) if (not removed_vertices.count(y) and not removed_edges.count(make_pair(x, y))) {
                if (dist_x + cost < dist[y].first) {
                    dist[y] = make_pair(dist_x + cost, x);
                    que.emplace(dist_x + cost, y);
                }
            }
        }

        // reconstruct the path
        if (start != goal and dist[goal].second == -1) {
            // failure
            return make_pair(dist[goal].first, vector<int>());
        }
        vector<int> path;
        for (int x = goal; x != -1; x = dist[x].second) {
            path.push_back(x);
        }
        reverse(ALL(path));
        return make_pair(dist[goal].first, path);
    };
    map<pair<int, int>, double> lookup;
    REP (i, n) {
        for (auto [j, cost] : g[i]) {
            lookup[make_pair(i, j)] = cost;
        }
    }

    // run Yen's algorithm
    vector<vector<int> > result;
    set<pair<T, vector<int> > > que;
    result.push_back(dijkstra(start, set<int>(), set<pair<int, int> >()).second);
    while ((int)result.size() < k) {
        auto & root = result.back();

        T root_cost = 0;
        set<int> removed_vertices;
        vector<int> prefix(result.size());
        iota(ALL(prefix), 0);
        REP (i, (int)root.size() - 1) {
            // remove edges used in other shortest paths from the graph
            set<pair<int, int> > removed_edges;
            vector<int> next_prefix;
            for (int j : prefix) {
                if (i + 1 < result[j].size() and result[j][i] == root[i]) {
                    int x = result[j][i];
                    int y = result[j][i + 1];
                    removed_edges.emplace(x, y);
                    removed_edges.emplace(y, x);
                    next_prefix.push_back(j);
                }
            }
            prefix.swap(next_prefix);

            // make the new path
            auto [spur_cost, spur] = dijkstra(root[i], removed_vertices, removed_edges);
            if (not spur.empty()) {
                vector<int> path(i + spur.size());
                copy(root.begin(), root.begin() + i, path.begin());
                copy(ALL(spur), path.begin() + i);
                que.emplace(root_cost + spur_cost, path);
                if (que.size() > k - (int)result.size()) {
                    que.erase(prev(que.end()));
                }
            }

            // remove vertices in root from the graph
            removed_vertices.insert(root[i]);
            root_cost += lookup[make_pair(root[i], root[i + 1])];
        }

        // found i-th smallest path
        if (que.empty()) {
            return result;
        }
        result.push_back(que.begin()->second);
        que.erase(que.begin());
    }
    return result;
}
