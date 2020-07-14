#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

std::pair<std::vector<std::vector<int> >, int> children_from_parent(const std::vector<int> & parent) {
    int n = parent.size();
    std::vector<std::vector<int> > children(n);
    int root = -1;
    REP (x, n) {
        if (parent[x] == -1) {
            assert (root == -1);
            root = x;
        } else {
            children[parent[x]].push_back(x);
        }
    }
    assert (root != -1);
    return std::make_pair(children, root);
}

std::vector<std::vector<int> > adjacent_list_from_children(const std::vector<std::vector<int> > & children) {
    int n = children.size();
    std::vector<std::vector<int> > g(n);
    REP (x, n) {
        for (int y : children[x]) {
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    return g;
}
