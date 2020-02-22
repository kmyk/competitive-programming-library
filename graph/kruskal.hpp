#pragma once
#include "data_structure/union_find_tree.hpp"
#include "utils/macros.hpp"
#include <algorithm>
#include <numeric>
#include <tuple>
#include <vector>

/**
 * @brief minimum spanning tree / 最小全域木 (Kruskal's method)
 * @note $O(E \log E)$
 * @note it becomes a forest if the given graph is not connected
 * @return a list of indices of edges
 */
template <typename T>
std::vector<int> compute_minimum_spanning_tree(int n, std::vector<std::tuple<int, int, T> > edges) {
    std::vector<int> order(edges.size());
    std::iota(ALL(order), 0);
    std::sort(ALL(order), [&](int i, int j) {
        return std::make_pair(std::get<2>(edges[i]), i) < std::make_pair(std::get<2>(edges[j]), j);
    });
    std::vector<int> tree;
    union_find_tree uft(n);
    for (int i : order) {
        int x = std::get<0>(edges[i]);
        int y = std::get<1>(edges[i]);
        if (not uft.is_same(x, y)) {
            uft.unite_trees(x, y);
            tree.push_back(i);
        }
    }
    return tree;
}
