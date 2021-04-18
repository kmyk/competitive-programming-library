#pragma once
#include <algorithm>
#include <utility>
#include <vector>

/**
 * @brief get the diameter of a tree / 木の直径
 * @note $O(N)$
 * @return (depth, vertex)
 * @sa http://techtipshoge.blogspot.jp/2016/09/blog-post.html
 */
std::pair<int, int> get_eccentricity(int root, const std::vector<std::vector<int> >& tree) {
    std::pair<int, int> result = { -1, -1 };  // (depth, vertex)
    auto dfs = [&](auto&& dfs, int x, int parent, int depth) -> void {
        result = std::max(result, std::make_pair(depth, x));
        for (int y : tree[x]) if (y != parent) {
            dfs(dfs, y, x, depth + 1);
        }
    };
    dfs(dfs, root, -1, 0);
    return result;
}

int get_diameter(const std::vector<std::vector<int> >& tree) {
    return get_eccentricity(get_eccentricity(0, tree).second, tree).first;
}
