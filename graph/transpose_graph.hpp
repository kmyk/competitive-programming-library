#pragma once
#include <vector>
#include "utils/macros.hpp"

/**
 * @param g is an adjacent list of a digraph
 * @note $O(V + E)$
 * @see https://en.wikipedia.org/wiki/Transpose_graph
 */
std::vector<std::vector<int> > make_transpose_graph(std::vector<std::vector<int> > const & g) {
    int n = g.size();
    std::vector<std::vector<int> > h(n);
    REP (i, n) {
        for (int j : g[i]) {
            h[j].push_back(i);
        }
    }
    return h;
}
