#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
#include "utils/macros.hpp"


/**
 * @brief Link-Cut tree (with commutative monoids, vertex set + path get)
 * @description manages a dynamic forest of rooted trees
 * @note this is for the problem "Spaceships", JOI Sprint Training Camp (http://imoz.jp/data/joi/2013-sp-d4-spaceships.pdf)
 * @note in each splay tree, nodes are sorted from bottom to top. the rightmost node of the root splay tree of the auxiliary tree is the root of represented tree.
 * @note TODO: remove the assumption about commutativity
 */
template <class CommutativeMonoid>
class link_cut_tree {
    typedef typename CommutativeMonoid::value_type value_type;
    const CommutativeMonoid mon;
    std::vector<value_type> data;  // data of the original tree
    std::vector<value_type> path;  // sum of data of the sub-tree in the belonging splay tree
    std::vector<int> parent, left, right;  // of the auxiliary tree

    /**
     * @description returns whether `a` and `parent[a]` is in the same splay tree
     */
    int get_parent_edge_type(int a) const {
        if (parent[a] != -1 and left[parent[a]] == a) {
            return -1;  // heavy (left)
        } else if (parent[a] != -1 and right[parent[a]] == a) {
            return +1;  // heavy (right)
        } else {
            return 0;  // light
        }
    }

    /**
     * @description make `a` the parent of the current parent of `a`
     */
    void rotate(int a) {
        int b = parent[a];
        switch (get_parent_edge_type(b)) {
            case -1:  // left
                left[parent[b]] = a;
                break;
            case 1:  // right
                right[parent[b]] = a;
                break;
        }
        switch (get_parent_edge_type(a)) {
            case -1:  // left
                parent[a] = std::exchange(parent[b], a);
                left[b] = std::exchange(right[a], b);
                if (left[b] != -1) parent[left[b]] = b;
                break;
            case 1:  // right
                parent[a] = std::exchange(parent[b], a);
                right[b] = std::exchange(left[a], b);
                if (right[b] != -1) parent[right[b]] = b;
                break;
            default:  // root
                assert (false);
        }
        update_path(b);
        update_path(a);
    }

    /**
     * @description make `a` the root of the beloging splay tree
     */
    void splay(int a) {
        while (get_parent_edge_type(a)) {
            // a is not the root of the splay tree
            if (not get_parent_edge_type(parent[a])) {
                // zig step: parent[a] is the root of the splay tree
                rotate(a);
            } else if (get_parent_edge_type(a) == get_parent_edge_type(parent[a])) {
                // zig-zig step
                rotate(parent[a]);
                rotate(a);
            } else {
                // zig-zag step
                rotate(a);
                rotate(a);
            }
        }
    }

    /**
     * @description make `a` belongs the root of the auxiliary tree
     * @note doen't splay
     * @note `a` becomes a terminal of the heavy path
     */
    void expose(int a) {
        // make a light path from `a` to the root
        for (int b = a; b != -1; b = parent[b]) {
            splay(b);
        }
        // make `a` the terminal of the path
        left[a] = -1;
        update_path(a);
        // make the path heavy
        for (int b = a; parent[b] != -1; b = parent[b]) {
            left[parent[b]] = b;
            update_path(parent[b]);
        }
    }

    /**
     * @description make `a` the root of the auxiliary tree
     */
    void access(int a) {
        expose(a);
        splay(a);
        assert (parent[a] == -1);
    }

    /**
     * @note `a` should be the root of the splay tree
     */
    void update_path(int a) {
        path[a] = data[a];
        if (right[a] != -1) path[a] = mon.mult(path[right[a]], path[a]);
        if (left[a] != -1) path[a] = mon.mult(path[a], path[left[a]]);
    }

public:
    link_cut_tree(int size, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_), data(size, mon.unit()), path(size, mon.unit()), parent(size, -1), left(size, -1), right(size, -1) {
    }

    /**
     * @description make a direct edge from `a` to `b`
     * @note `a` must be a root
     * @note `b` must not be a descendant of `a`
     */
    void link(int a, int b) {
        access(b);  // for the time complexity
        access(a);  // to make `a` the root
        assert (right[a] == -1);  // `a` must be a root
        parent[a] = b;
    }

    /**
     * @description remove the direct edge from `a`
     * @note `a` must not be a root
     */
    void cut(int a) {
        access(a);  // to make `a` the root
        assert (right[a] != -1);  // `a` must not be a root
        parent[right[a]] = -1;
        right[a] = -1;
        update_path(a);
    }

    /**
     * @note -1 is returned when `a` and `b` are not in the same tree
     */
    int get_lowest_common_ancestor(int a, int b) {
        access(b);  // for the time complexity
        access(a);  // to make `a` the root
        int preserved = -1;
        std::swap(left[a], preserved);  // make `a` and `b` belong different splay trees even if `b` is a descendant of `a`
        int result = b;
        int c = b;
        for (; c != a and c != -1; c = parent[c]) {
            assert (parent[c] != -1);
            if (not get_parent_edge_type(c)) {  // when it enters another splay tree
                result = parent[c];
            }
        }
        std::swap(left[a], preserved);
        return c == a ? result : -1;
    }

#if 0  // not verified yet
    bool is_same_tree(int a, int b) {
        return get_lowest_common_ancestor(a, b) != -1;
    }

    int get_parent(int a) {
        splay(a);
        return parent[a];
    }
#endif

    int get_root(int a) {
        access(a);
        while (right[a] != -1) {
            a = right[a];
        }
        return a;
    }

    void point_set(int a, value_type value) {
        splay(a);  // to make `a` the root of a splay tree
        data[a] = value;
        update_path(a);
    }

    value_type point_get(int a) const {
        return data[a];
    }

    value_type path_get(int a, int b) {
        access(b);  // for the time complexity
        access(a);  // to make `a` the root
        value_type cur = (left[b] == -1 ? data[b] : mon.mult(data[b], path[left[b]]));
        value_type nxt = (right[b] == -1 ? data[b] : mon.mult(path[right[b]], data[b]));
        for (int c = b; c != a and c != -1; c = parent[c]) {
            assert (parent[c] != -1);
            switch (get_parent_edge_type(c)) {
                case -1:  // heavy (left)
                    nxt = mon.mult(data[parent[c]], nxt);
                    if (right[parent[c]] != -1) nxt = mon.mult(path[right[parent[c]]], nxt);
                    break;
                case 1:  // heavy (right)
                    cur = mon.mult(cur, data[parent[c]]);
                    if (left[parent[c]] != -1) cur = mon.mult(cur, path[left[parent[c]]]);
                    break;
                case 0:  // light
                    cur = nxt;
                    nxt = mon.mult(data[parent[c]], nxt);
                    if (right[parent[c]] != -1) nxt = mon.mult(path[right[parent[c]]], nxt);
                    cur = mon.mult(cur, data[parent[c]]);
                    if (left[parent[c]] != -1) cur = mon.mult(cur, path[left[parent[c]]]);
                    break;
            }
        }
        return cur;
    }

    std::string to_graphviz() const {
        using namespace std;
        ostringstream oss;
        oss << "digraph G {" << endl;
        oss << "    graph [ rankdir = BT, bgcolor = \"#00000000\" ]" << endl;
        oss << "    node [ shape = circle, style = filled, fillcolor = \"#ffffffff\" ]" << endl;
        REP (a, parent.size()) {
            // oss << "    " << a << ";" << endl;
            oss << "    " << a << "[ label = \"" << a << "(" << data[a] << "," << path[a] << ")\"];" << endl;
        }
        function <void (int)> go = [&](int a) {
            if (parent[a] != -1 and not get_parent_edge_type(a)) {
                oss << "    " << a << " -> " << parent[a] << " [ style = dashed ]" << endl;
            }
            if (left[a] != -1 or right[a] != -1) {
                string l = (left[a] != -1 ? to_string(left[a]) : "l" + to_string(a));
                string r = (right[a] != -1 ? to_string(right[a]) : "r" + to_string(a));
                oss << "    " << l << " -> " << a << endl;
                oss << "    " << l << " -> " << r << " [ style = invis ]" << endl;
                oss << "    " << r << " -> " << a << endl;
                oss << "    { rank = same; " << l << "; " << r << "; }" << endl;
                if (left[a] == -1) oss << "    " << l << " [ style = invis ]" << endl;
                if (right[a] == -1) oss << "    " << r << " [ style = invis ]" << endl;
            }
            if (left[a] != -1) go(left[a]);
            if (right[a] != -1) go(right[a]);
        };
        REP (a, parent.size()) if (not get_parent_edge_type(a)) {
            go(a);
        }
        oss << "}";
        return oss.str();
    }
};
