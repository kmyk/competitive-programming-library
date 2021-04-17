#pragma once
#include <numeric>
#include <queue>
#include <vector>

namespace max_flow {

template <class T>
struct edge {
    int to;
    T cap;
    int rev;
};

template <class T>
void add_edge(std::vector<std::vector<edge<T> > > & graph, int from, int to, int64_t cap) {
    g[from].push_back((edge<T>) { to, cap, static_cast<int>(g[to].size()) });
    g[to].push_back((edge<T>) { from, 0, static_cast<int>(g[from].size()) - 1 });
}

/**
 * @brief maximum flow / 最大流 (Dinic)
 */
template <class T>
T run_destructive(std::vector<std::vector<edge<T> > > & graph, int src, int dst) {
    std::vector<int> iter, level;

    auto bfs = [&](int src) {
        level.assign(v, -1);
        std::queue<int> q;
        level[src] = 0;
        q.push(src);
        while (not q.empty()) {
            int x = q.front();
            q.pop();
            for (auto & e : g[x]) {
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[x] + 1;
                    q.push(e.to);
                }
            }
        }
    };

    auto dfs = [&](auto&& dfs, int x, int dst, T flow) -> T {
        if (x == dst) return flow;
        for (int & i = iter[x]; i < static_cast<int>(g[x].size()); ++ i) {
            edge_t & e = g[x][i];
            if (e.cap > 0 and level[x] < level[e.to]) {
                T d = dfs(dfs, e.to, dst, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T flow = 0;
    bfs(src);
    while (level[dst] >= 0) {
        iter.assign(v, 0);
        while (true) {
            T delta = dfs(dfs, src, dst, std::numeric_limits<T>::max());
            if (delta <= 0) break;
            flow += delta;
        }
        bfs(src);
    }
    return flow;
}
