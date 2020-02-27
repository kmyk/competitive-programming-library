#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <sstream>
#include <vector>
#include "utils/macros.hpp"
#include "monoids/reversible.hpp"


/**
 * @brief Link-Cut tree (monoids without commutativity, vertex set + path get)
 * @docs data_structure/link_cut_tree.md
 * @description manages a dynamic forest of rooted trees
 * @note in each splay tree, nodes are sorted from bottom to top. the rightmost node of the root splay tree of the auxiliary tree is the root of represented tree.
 */
template <class Monoid>
class link_cut_tree {
    typedef typename Monoid::value_type value_type;
    typedef typename reversible_monoid<Monoid>::value_type reversible_type;
    const reversible_monoid<Monoid> mon;
    std::vector<value_type> data;  // data of the original tree
    std::vector<reversible_type> path;  // sum of data of the sub-tree in the belonging splay tree
    std::vector<int> parent, left, right;  // of the auxiliary tree
    std::vector<bool> is_reversed;  // of the auxiliary tree; not applied to left, right, and path yet

    /**
     * @description returns whether `a` and `parent[a]` is in the same splay tree
     */
    int get_parent_edge_type(int a) const {
        if (parent[a] != -1 and left[parent[a]] == a) {
            assert (not is_reversed[parent[a]]);
            return -1;  // heavy (left-child)
        } else if (parent[a] != -1 and right[parent[a]] == a) {
            assert (not is_reversed[parent[a]]);
            return +1;  // heavy (right-child)
        } else {
            return 0;  // light
        }
    }

    /**
     * @description make `a` the parent of the current parent of `a`
     */
    void rotate(int a) {
        int b = parent[a];
        assert (b != -1);
        assert (not is_reversed[b]);
        assert (not is_reversed[a]);
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
        propagate_reverse_splay(a);
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
     * @description make `a` the root of the auxiliary tree
     * @note `a` becomes a terminal of the heavy path
     */
    void expose(int a) {
        // make a light path from `a` to the root
        for (int b = a; b != -1; b = parent[b]) {
            splay(b);
        }
        // make `a` the terminal of the path
        assert (not is_reversed[a]);
        left[a] = -1;
        update_path(a);
        // make the path heavy
        for (int b = a; parent[b] != -1; b = parent[b]) {
            left[parent[b]] = b;
            update_path(parent[b]);
        }
        splay(a);
    }

    void propagate_reverse_node(int a) {
        if (is_reversed[a]) {
            is_reversed[a] = false;
            path[a] = reversible_monoid<Monoid>::reverse(path[a]);
            if (right[a] != -1) is_reversed[right[a]] = not is_reversed[right[a]];
            if (left[a] != -1) is_reversed[left[a]] = not is_reversed[left[a]];
            std::swap(left[a], right[a]);
        }
    }
    void propagate_reverse_splay(int a) {
        if (parent[a] != -1 and (left[parent[a]] == a or right[parent[a]] == a)) {
            propagate_reverse_splay(parent[a]);
        }
        propagate_reverse_node(a);
        if (right[a] != -1) propagate_reverse_node(right[a]);
        if (left[a] != -1) propagate_reverse_node(left[a]);
    }

    /**
     * @note `a` should be the root of the splay tree
     */
    void update_path(int a) {
        path[a] = reversible_monoid<Monoid>::make(data[a]);
        if (right[a] != -1) path[a] = mon.mult(path[a], path[right[a]]);
        if (left[a] != -1) path[a] = mon.mult(path[left[a]], path[a]);
    }

public:
    link_cut_tree(int size, const Monoid & mon_ = Monoid())
            : mon(mon_), data(size, mon.base.unit()), path(size, mon.unit()), parent(size, -1), left(size, -1), right(size, -1), is_reversed(size, false) {
    }

    /**
     * @description make a direct edge from `a` to `b`
     * @note `a` must be a root
     * @note `b` must not be a descendant of `a`
     */
    void link(int a, int b) {
        expose(b);  // for the time complexity
        expose(a);  // to make `a` the root
        assert (not is_reversed[a]);
        assert (right[a] == -1);  // `a` must be a root
        parent[a] = b;
    }

    /**
     * @description remove the direct edge from `a`
     * @note `a` must not be a root
     */
    void cut(int a) {
        expose(a);  // to make `a` the root
        assert (not is_reversed[a]);
        assert (right[a] != -1);  // `a` must not be a root
        parent[right[a]] = -1;
        right[a] = -1;
        update_path(a);
    }

    /**
     * @note -1 is returned when `a` and `b` are not in the same tree
     */
    int get_lowest_common_ancestor(int a, int b) {
        expose(b);  // for the time complexity
        expose(a);  // to make `a` the root
        assert (not is_reversed[a]);
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

    bool are_connected(int a, int b) {
        return get_lowest_common_ancestor(a, b) != -1;
    }

    int get_parent(int a) {
        expose(a);
        assert (not is_reversed[a]);
        if (right[a] == -1) return parent[a];
        for (int b = right[a]; ; b = left[b]) {
            propagate_reverse_node(b);
            if (left[b] == -1) {
                splay(b);  // for the time complexity
                return b;
            }
        }
    }

    int get_root(int a) {
        expose(a);
        assert (not is_reversed[a]);
        while (right[a] != -1) {
            a = right[a];
        }
        splay(a);  // for the time complexity
        return a;
    }

    /**
     * @description make `a` the root of the represented tree
     */
    void evert(int a) {
        expose(a);  // to make `a` the root
        assert (not is_reversed[a]);
        assert (left[a] == -1);  // `a` is the terminal
        is_reversed[a] = true;
    }

    void vertex_set(int a, value_type value) {
        splay(a);  // to make `a` the root of a splay tree
        data[a] = value;
        update_path(a);
    }

    value_type vertex_get(int a) const {
        return data[a];
    }

    value_type path_get(int a, int b) {
        expose(a);  // for the time complexity
        expose(b);  // to make `b` the root
        assert (not is_reversed[a]);
        auto data_a = reversible_monoid<Monoid>::make(data[a]);
        reversible_type up = (right[a] == -1 ? data_a : mon.mult(data_a, path[right[a]]));
        reversible_type down = (left[a] == -1 ? data_a : mon.mult(path[left[a]], data_a));
        for (int c = a; c != b and c != -1; c = parent[c]) {
            assert (parent[c] != -1);
            assert (not is_reversed[parent[c]]);
            auto data_parent_c = reversible_monoid<Monoid>::make(data[parent[c]]);
            switch (get_parent_edge_type(c)) {
                case -1:  // heavy (left-child)
                    up = mon.mult(up, data_parent_c);
                    if (right[parent[c]] != -1) up = mon.mult(up, path[right[parent[c]]]);
                    break;
                case 1:  // heavy (right-child)
                    down = mon.mult(data_parent_c, down);
                    if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]], down);
                    break;
                case 0:  // light
                    down = reversible_monoid<Monoid>::reverse(up);
                    up = mon.mult(up, data_parent_c);
                    if (right[parent[c]] != -1) up = mon.mult(up, path[right[parent[c]]]);
                    down = mon.mult(data_parent_c, down);
                    if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]], down);
                    break;
            }
        }
        return reversible_monoid<Monoid>::get(reversible_monoid<Monoid>::reverse(down));
    }

    std::string to_graphviz() const {
        using namespace std;
        ostringstream oss;
        oss << "digraph G {" << endl;
        oss << "    graph [ rankdir = BT, bgcolor = \"#00000000\" ]" << endl;
        oss << "    node [ shape = circle, style = filled, fillcolor = \"#ffffffff\" ]" << endl;
        REP (a, parent.size()) {
            // oss << "    " << a << ";" << endl;
            oss << "    " << a << "[ label = \"" << a << "(" << data[a] << "," << path[a] << (is_reversed[a] ? " +rev" : "") << ")\"];" << endl;
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
