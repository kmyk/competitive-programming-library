#pragma once
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdint>
#include <functional>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief 木分解 (木幅 $t \le 2$)
 * @docs graph/tree_decomposition.md
 * @note $O(N)$ ?
 * @see https://ei1333.hateblo.jp/entry/2020/02/12/150319
 * @arg g is a simple connected graph $G = (V, E)$ whose treewidth $t \le 2$
 * @return a decomposed tree $T = (I, F)$ as a triple of (the root, the list of children $c : I \to \mathcal{P} \to I$, what vertices are contained $X : I \to \mathcal{P}(V)$)
 */
inline std::pair<std::vector<int>, std::vector<std::vector<int> > > get_tree_decomposition(const std::vector<std::vector<int> > & g) {
    int n = g.size();

    // prepare the info about g
    std::vector<int> used(n, -1);
    std::vector<int> degree(n);
    std::unordered_set<int64_t> edges;
    auto pack = [&](int x, int y) {
        if (x > y) std::swap(x, y);
        return ((int64_t)x << 32) | y;
    };
    REP (x, n) {
        degree[x] = g[x].size();
        for (int y : g[x]) if (x < y) {
            edges.insert(pack(x, y));
        }
    }

    // prepare the info about t
    std::vector<int> parent;
    std::vector<int> antecedent;
    std::function<int (int)> find_root = [&](int a) {
        // union-find tree with only path-compression
        return (antecedent[a] == -1 ? a : antecedent[a] = find_root(antecedent[a]));
    };
    std::vector<std::vector<int> > bags;

    // construct the tree with a stack
    std::stack<int> stk;
    REP (x, n) {
        if (g[x].size() <= 2) {
            stk.push(x);
        }
    }
    while (not stk.empty()) {
        int x = stk.top();
        stk.pop();
        if (degree[x] == 0) continue;
        used[x] = bags.size();
        parent.push_back(-1);
        antecedent.push_back(-1);
        bags.emplace_back();
        auto & bag = bags.back();

        // make the new bag
        bag.push_back(x);
        for (int y : g[x]) {
            if (used[y] == -1) {
                // add a vertex y into the new bag
                bag.push_back(y);

            } else if (used[y] >= 0) {
                // connect a bag used[y] as a child
                int root = find_root(used[y]);
                if (root == used[x]) {
                    // nop

                } else if (bags[used[y]].size() == 2) {
                    // the sub-bag is removing a vertex
                    if (parent[root] == -1) {
                        parent[root] = antecedent[root] = used[x];
                    }
                    assert (bags[used[y]][1] == x);
                    bag.push_back(y);

                } else if (bags[used[y]].size() == 3) {
                    // the sub-bag is removing an edge
                    if (parent[root] == -1) {
                        parent[root] = antecedent[root] = used[x];
                    }
                    assert (bags[root][1] == x or bags[root][2] == x);
                    bag.push_back(bags[root][1] ^ bags[root][2] ^ x);
                    used[bags[root][0]] = used[x];
                } else {
                    assert (false);
                }

            } else {
                // nop
            }
        }
        std::sort(bag.begin() + 1, bag.end());
        bag.erase(std::unique(bag.begin() + 1, bag.end()), bag.end());
        assert (bag.size() == degree[x] + 1);

        // remove and add edges
        auto decr = [&](int y) {
            -- degree[y];
            if (degree[y] == 2) {
                stk.push(y);
            }
        };
        if (degree[x] == 1) {
            decr(bag[1]);
        } if (degree[x] == 2) {
            if (not edges.insert(pack(bag[1], bag[2])).second) {
                decr(bag[1]);
                decr(bag[2]);
            }
        }
        degree[x] = 0;
    }

    if (std::count(ALL(degree), 0) != n) return std::make_pair(std::vector<int>(), std::vector<std::vector<int> >());
    assert (std::count(ALL(parent), -1) == 1);
    return std::make_pair(parent, bags);
}

enum nice_tree_decomposition_tag {
    LEAF,
    INTRODUCE,
    FORGET,
    JOIN,
};

/**
 * @note $O(t N)$
 */
inline std::vector<std::tuple<nice_tree_decomposition_tag, int, int> > get_nice_tree_decomposition(const std::vector<int> & parent, const std::vector<std::vector<int> > & bags) {
    assert (not parent.empty());
    assert (parent.back() == -1);  // assume that vertices are topologically sorted and reversed
    int n = parent.size();
    std::vector<std::vector<int> > children(n);
    std::vector<int> node(n, -1);
    std::vector<std::tuple<nice_tree_decomposition_tag, int, int> > nice;
    REP (a, n) {
        assert (not bags[a].empty());
        if (children[a].empty()) {
            for (int x : bags[a]) {
                if (x == bags[a].front()) {
                    nice.emplace_back(LEAF, x, -1);
                } else {
                    nice.emplace_back(INTRODUCE, x, nice.size() - 1);
                }
            }
            node[a] = nice.size() - 1;
        } else {
            for (int b : children[a]) {
                for (int y : bags[b]) {
                    if (not count(ALL(bags[a]), y)) {
                        nice.emplace_back(FORGET, y, node[b]);
                        node[b] = nice.size() - 1;
                    }
                }
                for (int x : bags[a]) {
                    if (not count(ALL(bags[b]), x)) {
                        nice.emplace_back(INTRODUCE, x, node[b]);
                        node[b] = nice.size() - 1;
                    }
                }
                if (b == children[a].front()) {
                    std::swap(node[a], node[b]);
                } else {
                    nice.emplace_back(JOIN, node[a], node[b]);
                    node[a] = nice.size() - 1;
                }
            }
        }
        if (parent[a] != -1) {
            children[parent[a]].push_back(a);
        }
    };
    for (int x : bags.back()) {
        nice.emplace_back(FORGET, x, node.back());
        node.back() = nice.size() - 1;
    }
    return nice;
}
