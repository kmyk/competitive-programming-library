#pragma once
#include <vector>
#include "../graph/transpose_graph.hpp"
#include "../utils/macros.hpp"

/**
 * @param g is an adjacent list of a digraph
 * @param size is the size of equivalence classes
 * @param component_of is the map from original vertices to equivalence classes
 * @note $O(V + E)$
 * @see https://en.wikipedia.org/wiki/Quotient_graph
 */
std::vector<std::vector<int> > make_quotient_graph(const std::vector<std::vector<int> > & g, int size, const std::vector<int> & component_of) {
    int n = g.size();
    std::vector<std::vector<int> > h(size);
    REP (i, n) for (int j : g[i]) {
        if (component_of[i] != component_of[j]) {
            h[component_of[i]].push_back(component_of[j]);
        }
    }
    REP (k, size) {
        std::sort(ALL(h[k]));
        h[k].erase(std::unique(ALL(h[k])), h[k].end());
    }
    return h;
}
