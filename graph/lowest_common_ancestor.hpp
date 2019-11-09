#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>
#include "data_structure/sparse_table.hpp"

/**
 * @brief lowest common ancestor with \pm 1 RMQ and sparse table
 * @see https://www.slideshare.net/yumainoue965/lca-and-rmq
 * @note verified http://www.utpc.jp/2011/problems/travel.html
 */
struct lowest_common_ancestor {
    sparse_table<indexed_min_semilattice> table;
    std::vector<int> index;
    lowest_common_ancestor() = default;
    /**
     * @note O(N)
     * @param g is an adjacent list of a tree
     */
    lowest_common_ancestor(int root, std::vector<std::vector<int> > const & g) {
        std::vector<std::pair<int, int> > tour;
        index.assign(g.size(), -1);
        dfs(root, -1, 0, g, tour);
        table = sparse_table<indexed_min_semilattice>(tour);
    }
private:
    /**
     * @note to avoid stack overflow
     */
    void dfs(int i, int parent, int depth, std::vector<std::vector<int> > const & g, std::vector<std::pair<int, int> > & tour) {
        index[i] = tour.size();
        tour.emplace_back(depth, i);
        for (int j : g[i]) if (j != parent) {
            dfs(j, i, depth + 1, g, tour);
            tour.emplace_back(depth, i);
        }
    }
public:
    /**
     * @note O(1)
     */
    int operator () (int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        x = index[x];
        y = index[y];
        if (x > y) std::swap(x, y);
        return table.range_concat(x, y + 1).second;
    }
};
