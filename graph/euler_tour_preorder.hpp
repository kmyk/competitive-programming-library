#pragma once
#include <functional>
#include <vector>

/**
 * @brief Euler Tour (preorder)
 * @arg g must be a rooted tree, directed or undirected
 */
void do_euler_tour_preorder(std::vector<std::vector<int> > const & g, int root, std::vector<int> & tour, std::vector<int> & left, std::vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.resize(n);
    right.resize(n);
    std::function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
    };
    go(root, -1);
}
