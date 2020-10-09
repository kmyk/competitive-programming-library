#pragma once
#include <cassert>
#include <deque>
#include <functional>
#include <vector>

/**
 * @brief Namori cycle / なもり閉路
 * @param g a simple connected undirected graph with |E| = |V|
 */
std::deque<int> get_namori_cycle(const std::vector<std::vector<int> >& g) {
    int n = g.size();
    {  // check the namori-ty
        int m = 0;
        REP (i, n) {
            m += g[i].size();
        }
        assert (m == 2 * n);
    }

    std::deque<int> stk;
    std::vector<bool> used(n);
    auto go = [&](auto&& go, int i, int parent) -> int {
        if (used[i]) return i;
        stk.push_back(i);
        used[i] = true;
        for (int j : g[i]) if (j != parent) {
            int k = go(go, j, i);
            if (k != -1) return k;
        }
        assert (stk.back() == i);
        stk.pop_back();
        used[i] = false;
        return -1;
    };
    int i = go(go, 0, -1);
    assert (i != -1);  // fails if the graph is not simple
    while (stk.front() != i) {
        stk.pop_front();
    }
    return stk;
}
