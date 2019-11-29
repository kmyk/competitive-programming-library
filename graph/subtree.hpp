#pragma once
#include <algorithm>
#include <vector>

struct subtree_info_t {
    int parent;  // in the entire tree
    int depth;  // in the entire tree
    int size;  // of the subtree
    int height;  // of the subtree
};

/**
 * @arg g must be a tree
 * @note O(n) time
 * @note O(n) space on heap
 */
std::vector<subtree_info_t> prepare_subtree_info(std::vector<std::vector<int> > const & g, int root) {
    int n = g.size();
    std::vector<subtree_info_t> info(n, (subtree_info_t) { -1, -1, -1, -1 });
    std::vector<int> topological(n);
    topological[0] = root;
    info[root].parent = root;
    info[root].depth = 0;
    int r = 1;
    for (int l = 0; l < r; ++ l) {
        int i = topological[l];
        for (int j : g[i]) if (j != info[i].parent) {
            topological[r ++] = j;
            info[j].parent = i;
            info[j].depth = info[i].depth + 1;
        }
    }
    while ((-- r) >= 0) {
        int i = topological[r];
        info[i].size = 1;
        info[i].height = 0;
        for (int j : g[i]) if (j != info[i].parent) {
            info[i].size += info[j].size;
            info[i].height = std::max(info[i].height, info[j].height + 1);
        }
    }
    info[root].parent = -1;
    return info;
}
