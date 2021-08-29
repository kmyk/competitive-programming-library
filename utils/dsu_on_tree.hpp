#pragma once
#include <functional>
#include <stack>
#include <vector>
#include "../graph/subtree.hpp"
#include "../utils/macros.hpp"

/**
 * @brief DSU on tree (sack)
 * @arg g is a tree
 * @arg root
 * @arg add is a function object which takes a index of a vertex
 * @arg sub is a function object which takes a index of a vertex
 * @arg callback is a function object which takes a index of a vertex
 * @note for each x, add(x) and sub(x) are called O(log n) times
 * @note O(n log n) if add, sub, and callback are O(1)
 * @see https://codeforces.com/blog/entry/44351
 * @note sub(x) can be implemented as reset(), because sub(x) is called until it becomes empty after sub(x) is called once
 */
template <class Add, class Sub, class Callback>
void dsu_on_tree(const std::vector<std::vector<int> > & g, int root, Add & add, Sub & sub, Callback & callback) {
    auto info = prepare_subtree_info(g, root);
    auto subtree_apply = [&](int x, auto & f) {
        std::stack<int> stk;
        stk.push(x);
        while (not stk.empty()) {
            int y = stk.top();
            stk.pop();
            f(y);
            for (int z : g[y]) if (z != info[y].parent) {
                stk.push(z);
            }
        }
    };
    std::function<void (int, bool)> go = [&](int x, bool keep) {
        // leaf
        if (info[x].size == 1) {
            add(x);
            callback(x);
            if (not keep) {
                sub(x);
            }
            return;
        }
        // choose the heavy child
        int z = *max_element(ALL(g[x]), [&](int y1, int y2) {
            int size1 = (y1 == info[x].parent ? -1 : info[y1].size);
            int size2 = (y2 == info[x].parent ? -1 : info[y2].size);
            return size1 < size2;
        });
        // go light
        for (int y : g[x]) if (y != info[x].parent) {
            if (y != z) {
                go(y, false);
            }
        }
        // go heavy
        go(z, true);
        for (int y : g[x]) if (y != info[x].parent) {
            if (y != z) {
                subtree_apply(y, add);
            }
        }
        add(x);
        callback(x);
        if (not keep) {
            subtree_apply(x, sub);
        }
    };
    go(root, false);
}
