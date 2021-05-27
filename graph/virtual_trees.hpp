#pragma once
#include <vector>
#include "utils/macros.hpp"
#include "graph/euler_tour_preorder.hpp"
#include "graph/lowest_common_ancestor.hpp"

/**
 * @brief 虚樹 / virtual trees
 * @note O(\lvert X \rvert \log \lvert X \rvert)
 * @return the list of vertices in the virtual tree, and the adjacent list using indices on the returned list of vertices
 * @note verified at https://codeforces.com/problemset/problem/613/D
 */
std::pair<std::vector<int>, std::vector<std::vector<int>>> construct_virtual_tree(const std::vector<std::vector<int>>& g, int root, const lowest_common_ancestor& lca, const std::vector<int>& tour_left, std::vector<int> marked) {
    std::vector<int> vertices;
    std::vector<std::vector<int>> h;

    std::vector<int> stk;
    std::sort(ALL(marked), [&](int x, int y) -> bool {
        return tour_left[x] < tour_left[y];
    });
    for (int x : marked) {
        int index_x = vertices.size();
        vertices.push_back(x);
        h.emplace_back();
        if (not stk.empty()) {
            int z = lca(x, vertices[stk.back()]);

            // pop vectirces deeper than z
            std::vector<int> popped;
            while (not stk.empty() and lca.get_depth(z) < lca.get_depth(vertices[stk.back()])) {
                int index_y = stk.back();
                stk.pop_back();
                popped.push_back(index_y);
            }

            // add the LCA if required
            if (stk.empty() or vertices[stk.back()] != z) {
                int index_z = vertices.size();
                vertices.push_back(z);
                h.emplace_back();
                stk.push_back(index_z);
            }

            // add edges
            if (not popped.empty()) {
                int index_z = stk.back();
                int index_y = popped.back();
                h[index_z].push_back(index_y);
                h[index_y].push_back(index_z);
            }
            REP (i, (int)popped.size() - 1) {
                int index_y1 = popped[i];
                int index_y2 = popped[i + 1];
                h[index_y1].push_back(index_y2);
                h[index_y2].push_back(index_y1);
            }
        }
        stk.push_back(index_x);
    }
    REP (i, (int)stk.size() - 1) {
        int index_x = stk[i];
        int index_y = stk[i + 1];
        h[index_x].push_back(index_y);
        h[index_y].push_back(index_x);
    }

    return {vertices, h};
}

/**
 * @note O(N log N + \lvert X \rvert \log \lvert X \rvert)
 */
std::pair<std::vector<int>, std::vector<std::vector<int>>> construct_virtual_tree(const std::vector<std::vector<int>>& g, int root, const std::vector<int>& marked) {
    lowest_common_ancestor lca(root, g);
    std::vector<int> tour, left, right;
    do_euler_tour_preorder(g, root, tour, left, right);
    return construct_virtual_tree(g, root, lca, left, marked);
}
