#pragma once
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

namespace min_cost_flow {

template <class T>
struct edge { int to; T cap, cost; int rev; };

template <class T>
void add_edge(std::vector<std::vector<edge<T> > > & graph, int from, int to, T cap, T cost) {
    graph[from].push_back((edge<T>) {   to, cap,  cost, int(graph[  to].size())     });
    graph[  to].push_back((edge<T>) { from,  0, - cost, int(graph[from].size()) - 1 });
}

template <class T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

/**
 * @brief minimum cost flow / 最小費用流 (primal-dual)
 * @note mainly $O(V^2 U C)$ for U is the sum of capacities and $C$ is the sum of costs. and additional $O(V E)$ if negative edges exist
 */
template <class T>
T run_destructive(std::vector<std::vector<edge<T> > > & graph, int src, int dst, T flow) {

    T result = 0;
    std::vector<T> potential(graph.size());
    if (0 < flow) {  // initialize potential when negative edges exist (slow). you can remove this if unnecessary
        std::fill(ALL(potential), std::numeric_limits<T>::max());
        potential[src] = 0;
        while (true) {  // Bellman-Ford algorithm
            bool updated = false;
            REP (e_from, graph.size()) for (auto & e : graph[e_from]) if (e.cap) {
                if (potential[e_from] == std::numeric_limits<T>::max()) continue;
                if (potential[e.to] > potential[e_from] + e.cost) {
                    potential[e.to] = potential[e_from] + e.cost;  // min
                    updated = true;
                }
            }
            if (not updated) break;
        }
    }

    while (0 < flow) {
        // update potential using dijkstra
        std::vector<T> distance(graph.size(), std::numeric_limits<T>::max());  // minimum distance
        std::vector<int> prev_v(graph.size());  // constitute a single-linked-list represents the flow-path
        std::vector<int> prev_e(graph.size());
        {  // initialize distance and prev_{v,e}
            reversed_priority_queue<std::pair<T, int> > que;  // distance * vertex
            distance[src] = 0;
            que.emplace(0, src);
            while (not que.empty()) {  // Dijkstra's algorithm
                T d; int v; std::tie(d, v) = que.top(); que.pop();
                if (potential[v] == std::numeric_limits<T>::max()) continue;  // for unreachable nodes
                if (distance[v] < d) continue;
                // look round the vertex
                REP (e_index, graph[v].size()) {
                    // consider updating
                    edge<T> e = graph[v][e_index];
                    int w = e.to;
                    if (potential[w] == std::numeric_limits<T>::max()) continue;
                    T d1 = distance[v] + e.cost + potential[v] - potential[w];  // updated distance
                    if (0 < e.cap and d1 < distance[e.to]) {
                        distance[w] = d1;
                        prev_v[w] = v;
                        prev_e[w] = e_index;
                        que.emplace(d1, w);
                    }
                }
            }
        }
        if (distance[dst] == std::numeric_limits<T>::max()) return -1;  // no such flow
        REP (v, graph.size()) {
            if (potential[v] == std::numeric_limits<T>::max()) continue;
            potential[v] += distance[v];
        }

        // finish updating the potential
        // let flow on the src->dst minimum path
        T delta = flow; // capacity of the path
        for (int v = dst; v != src; v = prev_v[v]) {
            delta = std::min(delta, graph[prev_v[v]][prev_e[v]].cap);
        }
        flow -= delta;
        result += delta * potential[dst];
        for (int v = dst; v != src; v = prev_v[v]) {
            edge<T> & e = graph[prev_v[v]][prev_e[v]];  // reference
            e.cap -= delta;
            graph[v][e.rev].cap += delta;
        }
    }
    return result;
}

}
