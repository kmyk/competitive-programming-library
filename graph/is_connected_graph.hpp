#pragma once
#include <algorithm>
#include <vector>

bool is_connected_graph(const std::vector<std::vector<int>> &g) {
    int n = g.size();
    std::vector<bool> used(n);
    auto go = [&](auto &&go, int x) -> void {
        used[x] = true;
        for (int y : g[x]) {
            if (not used[y]) {
                go(go, y);
            }
        }
    };
    go(go, 0);
    return std::find(ALL(used), false) == used.end();
}
