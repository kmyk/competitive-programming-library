#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>
#include "data_structure/sparse_table.hpp"
#include "monoids/min_index.hpp"

/**
 * @brief lowest common ancestor with $\pm$ 1 RMQ and sparse table
 * @see https://www.slideshare.net/yumainoue965/lca-and-rmq
 * @note verified http://www.utpc.jp/2011/problems/travel.html
 */
struct lowest_common_ancestor {
    sparse_table<min_index_monoid<int> > table;
    std::vector<int> index;
    lowest_common_ancestor() = default;
    /**
     * @note $O(N)$
     * @param g is an adjacent list of a tree
     * @note you can easily modify this to accept forests
     */
    lowest_common_ancestor(int root, std::vector<std::vector<int> > const & g) {
        std::vector<std::pair<int, int> > tour;
        index.assign(g.size(), -1);
        dfs(root, -1, 0, g, tour);
        table = sparse_table<min_index_monoid<int> >(tour);
    }
private:
    /**
     * @note sometimes causes stack overflow without ulimit -s unlimited
     */
    void dfs(int x, int parent, int depth, std::vector<std::vector<int> > const & g, std::vector<std::pair<int, int> > & tour) {
        index[x] = tour.size();
        tour.emplace_back(depth, x);
        for (int y : g[x]) if (y != parent) {
            dfs(y, x, depth + 1, g, tour);
            tour.emplace_back(depth, x);
        }
    }
public:
    /**
     * @note $O(1)$
     */
    int operator () (int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        x = index[x];
        y = index[y];
        if (x > y) std::swap(x, y);
        return table.range_get(x, y + 1).second;
    }
    int get_depth(int x) const {
        assert (0 <= x and x < index.size());
        return table.range_get(index[x], index[x] + 1).first;
    }
    int get_dist(int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        int z = (*this)(x, y);
        return get_depth(x) + get_depth(y) - 2 * get_depth(z);
    }
};
