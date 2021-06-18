---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: monoids/reversible.hpp
    title: monoids/reversible.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.marked_ancestor.test.cpp
    title: data_structure/link_cut_tree.marked_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: data_structure/link_cut_tree.md
    document_title: Link-Cut tree (monoids without commutativity, vertex set + path
      get)
    links: []
  bundledCode: "#line 2 \"data_structure/link_cut_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <sstream>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 2 \"monoids/reversible.hpp\"\n#include <utility>\n\ntemplate\
    \ <class Monoid>\nstruct reversible_monoid {\n    typedef typename Monoid::value_type\
    \ base_type;\n    typedef std::pair<base_type, base_type> value_type;\n    Monoid\
    \ base;\n    reversible_monoid() = default;\n    reversible_monoid(const Monoid\
    \ & base_) : base(base_) {}\n    value_type unit() const { return std::make_pair(base.unit(),\
    \ base.unit()); }\n    value_type mult(const value_type & a, const value_type\
    \ & b) const { return std::make_pair(base.mult(a.first, b.first), base.mult(b.second,\
    \ a.second)); }\n    static value_type make(const base_type & x) { return std::make_pair(x,\
    \ x); }\n    static value_type reverse(const value_type & a) { return std::make_pair(a.second,\
    \ a.first); }\n    static base_type get(const value_type & a) { return a.first;\
    \ }\n};\n#line 9 \"data_structure/link_cut_tree.hpp\"\n\n\n/**\n * @brief Link-Cut\
    \ tree (monoids without commutativity, vertex set + path get)\n * @docs data_structure/link_cut_tree.md\n\
    \ * @description manages a dynamic forest of rooted trees\n * @note in each splay\
    \ tree, nodes are sorted from bottom to top. the rightmost node of the root splay\
    \ tree of the auxiliary tree is the root of represented tree.\n */\ntemplate <class\
    \ Monoid>\nclass link_cut_tree {\n    typedef typename Monoid::value_type value_type;\n\
    \    typedef typename reversible_monoid<Monoid>::value_type reversible_type;\n\
    \    const reversible_monoid<Monoid> mon;\n    std::vector<value_type> data; \
    \ // data of the original tree\n    std::vector<reversible_type> path;  // sum\
    \ of data of the sub-tree in the belonging splay tree\n    std::vector<int> parent,\
    \ left, right;  // of the auxiliary tree\n    std::vector<bool> is_reversed; \
    \ // of the auxiliary tree; not applied to left, right, and path yet\n\n    /**\n\
    \     * @description returns whether `a` and `parent[a]` is in the same splay\
    \ tree\n     */\n    int get_parent_edge_type(int a) const {\n        if (parent[a]\
    \ != -1 and left[parent[a]] == a) {\n            assert (not is_reversed[parent[a]]);\n\
    \            return -1;  // heavy (left-child)\n        } else if (parent[a] !=\
    \ -1 and right[parent[a]] == a) {\n            assert (not is_reversed[parent[a]]);\n\
    \            return +1;  // heavy (right-child)\n        } else {\n          \
    \  return 0;  // light\n        }\n    }\n\n    /**\n     * @description make\
    \ `a` the parent of the current parent of `a`\n     */\n    void rotate(int a)\
    \ {\n        int b = parent[a];\n        assert (b != -1);\n        assert (not\
    \ is_reversed[b]);\n        assert (not is_reversed[a]);\n        switch (get_parent_edge_type(b))\
    \ {\n            case -1:  // left\n                left[parent[b]] = a;\n   \
    \             break;\n            case 1:  // right\n                right[parent[b]]\
    \ = a;\n                break;\n        }\n        switch (get_parent_edge_type(a))\
    \ {\n            case -1:  // left\n                parent[a] = std::exchange(parent[b],\
    \ a);\n                left[b] = std::exchange(right[a], b);\n               \
    \ if (left[b] != -1) parent[left[b]] = b;\n                break;\n          \
    \  case 1:  // right\n                parent[a] = std::exchange(parent[b], a);\n\
    \                right[b] = std::exchange(left[a], b);\n                if (right[b]\
    \ != -1) parent[right[b]] = b;\n                break;\n            default: \
    \ // root\n                assert (false);\n        }\n        update_path(b);\n\
    \        update_path(a);\n    }\n\n    /**\n     * @description make `a` the root\
    \ of the beloging splay tree\n     */\n    void splay(int a) {\n        propagate_reverse_splay(a);\n\
    \        while (get_parent_edge_type(a)) {\n            // a is not the root of\
    \ the splay tree\n            if (not get_parent_edge_type(parent[a])) {\n   \
    \             // zig step: parent[a] is the root of the splay tree\n         \
    \       rotate(a);\n            } else if (get_parent_edge_type(a) == get_parent_edge_type(parent[a]))\
    \ {\n                // zig-zig step\n                rotate(parent[a]);\n   \
    \             rotate(a);\n            } else {\n                // zig-zag step\n\
    \                rotate(a);\n                rotate(a);\n            }\n     \
    \   }\n    }\n\n    /**\n     * @description make `a` the root of the auxiliary\
    \ tree\n     * @note `a` becomes a terminal of the heavy path\n     */\n    void\
    \ expose(int a) {\n        // make a light path from `a` to the root\n       \
    \ for (int b = a; b != -1; b = parent[b]) {\n            splay(b);\n        }\n\
    \        // make `a` the terminal of the path\n        assert (not is_reversed[a]);\n\
    \        left[a] = -1;\n        update_path(a);\n        // make the path heavy\n\
    \        for (int b = a; parent[b] != -1; b = parent[b]) {\n            left[parent[b]]\
    \ = b;\n            update_path(parent[b]);\n        }\n        splay(a);\n  \
    \  }\n\n    void propagate_reverse_node(int a) {\n        if (is_reversed[a])\
    \ {\n            is_reversed[a] = false;\n            path[a] = reversible_monoid<Monoid>::reverse(path[a]);\n\
    \            if (right[a] != -1) is_reversed[right[a]] = not is_reversed[right[a]];\n\
    \            if (left[a] != -1) is_reversed[left[a]] = not is_reversed[left[a]];\n\
    \            std::swap(left[a], right[a]);\n        }\n    }\n    void propagate_reverse_splay(int\
    \ a) {\n        if (parent[a] != -1 and (left[parent[a]] == a or right[parent[a]]\
    \ == a)) {\n            propagate_reverse_splay(parent[a]);\n        }\n     \
    \   propagate_reverse_node(a);\n        if (right[a] != -1) propagate_reverse_node(right[a]);\n\
    \        if (left[a] != -1) propagate_reverse_node(left[a]);\n    }\n\n    /**\n\
    \     * @note `a` should be the root of the splay tree\n     */\n    void update_path(int\
    \ a) {\n        path[a] = reversible_monoid<Monoid>::make(data[a]);\n        if\
    \ (right[a] != -1) path[a] = mon.mult(path[a], path[right[a]]);\n        if (left[a]\
    \ != -1) path[a] = mon.mult(path[left[a]], path[a]);\n    }\n\npublic:\n    link_cut_tree(int\
    \ size, const Monoid & mon_ = Monoid())\n            : mon(mon_), data(size, mon.base.unit()),\
    \ path(size, mon.unit()), parent(size, -1), left(size, -1), right(size, -1), is_reversed(size,\
    \ false) {\n    }\n\n    /**\n     * @description make a direct edge from `a`\
    \ to `b`\n     * @note `a` must be a root\n     * @note `b` must not be a descendant\
    \ of `a`\n     */\n    void link(int a, int b) {\n        expose(b);  // for the\
    \ time complexity\n        expose(a);  // to make `a` the root\n        assert\
    \ (not is_reversed[a]);\n        assert (right[a] == -1);  // `a` must be a root\n\
    \        parent[a] = b;\n    }\n\n    /**\n     * @description remove the direct\
    \ edge from `a`\n     * @note `a` must not be a root\n     */\n    void cut(int\
    \ a) {\n        expose(a);  // to make `a` the root\n        assert (not is_reversed[a]);\n\
    \        assert (right[a] != -1);  // `a` must not be a root\n        parent[right[a]]\
    \ = -1;\n        right[a] = -1;\n        update_path(a);\n    }\n\n    /**\n \
    \    * @note -1 is returned when `a` and `b` are not in the same tree\n     */\n\
    \    int get_lowest_common_ancestor(int a, int b) {\n        expose(b);  // for\
    \ the time complexity\n        expose(a);  // to make `a` the root\n        assert\
    \ (not is_reversed[a]);\n        int preserved = -1;\n        std::swap(left[a],\
    \ preserved);  // make `a` and `b` belong different splay trees even if `b` is\
    \ a descendant of `a`\n        int result = b;\n        int c = b;\n        for\
    \ (; c != a and c != -1; c = parent[c]) {\n            assert (parent[c] != -1);\n\
    \            if (not get_parent_edge_type(c)) {  // when it enters another splay\
    \ tree\n                result = parent[c];\n            }\n        }\n      \
    \  std::swap(left[a], preserved);\n        return c == a ? result : -1;\n    }\n\
    \n    bool are_connected(int a, int b) {\n        return get_lowest_common_ancestor(a,\
    \ b) != -1;\n    }\n\n    int get_parent(int a) {\n        expose(a);\n      \
    \  assert (not is_reversed[a]);\n        if (right[a] == -1) return parent[a];\n\
    \        for (int b = right[a]; ; b = left[b]) {\n            propagate_reverse_node(b);\n\
    \            if (left[b] == -1) {\n                splay(b);  // for the time\
    \ complexity\n                return b;\n            }\n        }\n    }\n\n \
    \   int get_root(int a) {\n        expose(a);\n        assert (not is_reversed[a]);\n\
    \        while (right[a] != -1) {\n            a = right[a];\n        }\n    \
    \    splay(a);  // for the time complexity\n        return a;\n    }\n\n    /**\n\
    \     * @description make `a` the root of the represented tree\n     */\n    void\
    \ evert(int a) {\n        expose(a);  // to make `a` the root\n        assert\
    \ (not is_reversed[a]);\n        assert (left[a] == -1);  // `a` is the terminal\n\
    \        is_reversed[a] = true;\n    }\n\n    void vertex_set(int a, value_type\
    \ value) {\n        splay(a);  // to make `a` the root of a splay tree\n     \
    \   data[a] = value;\n        update_path(a);\n    }\n\n    value_type vertex_get(int\
    \ a) const {\n        return data[a];\n    }\n\n    value_type path_get(int a,\
    \ int b) {\n        expose(a);  // for the time complexity\n        expose(b);\
    \  // to make `b` the root\n        assert (not is_reversed[a]);\n        auto\
    \ data_a = reversible_monoid<Monoid>::make(data[a]);\n        reversible_type\
    \ up = (right[a] == -1 ? data_a : mon.mult(data_a, path[right[a]]));\n       \
    \ reversible_type down = (left[a] == -1 ? data_a : mon.mult(path[left[a]], data_a));\n\
    \        for (int c = a; c != b and c != -1; c = parent[c]) {\n            assert\
    \ (parent[c] != -1);\n            assert (not is_reversed[parent[c]]);\n     \
    \       auto data_parent_c = reversible_monoid<Monoid>::make(data[parent[c]]);\n\
    \            switch (get_parent_edge_type(c)) {\n                case -1:  //\
    \ heavy (left-child)\n                    up = mon.mult(up, data_parent_c);\n\
    \                    if (right[parent[c]] != -1) up = mon.mult(up, path[right[parent[c]]]);\n\
    \                    break;\n                case 1:  // heavy (right-child)\n\
    \                    down = mon.mult(data_parent_c, down);\n                 \
    \   if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]], down);\n\
    \                    break;\n                case 0:  // light\n             \
    \       down = reversible_monoid<Monoid>::reverse(up);\n                    up\
    \ = mon.mult(up, data_parent_c);\n                    if (right[parent[c]] !=\
    \ -1) up = mon.mult(up, path[right[parent[c]]]);\n                    down = mon.mult(data_parent_c,\
    \ down);\n                    if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]],\
    \ down);\n                    break;\n            }\n        }\n        return\
    \ reversible_monoid<Monoid>::get(reversible_monoid<Monoid>::reverse(down));\n\
    \    }\n\n    std::string to_graphviz() const {\n        using namespace std;\n\
    \        ostringstream oss;\n        oss << \"digraph G {\" << endl;\n       \
    \ oss << \"    graph [ rankdir = BT, bgcolor = \\\"#00000000\\\" ]\" << endl;\n\
    \        oss << \"    node [ shape = circle, style = filled, fillcolor = \\\"\
    #ffffffff\\\" ]\" << endl;\n        REP (a, parent.size()) {\n            // oss\
    \ << \"    \" << a << \";\" << endl;\n            oss << \"    \" << a << \"[\
    \ label = \\\"\" << a << \"(\" << data[a] << \",\" << path[a] << (is_reversed[a]\
    \ ? \" +rev\" : \"\") << \")\\\"];\" << endl;\n        }\n        function <void\
    \ (int)> go = [&](int a) {\n            if (parent[a] != -1 and not get_parent_edge_type(a))\
    \ {\n                oss << \"    \" << a << \" -> \" << parent[a] << \" [ style\
    \ = dashed ]\" << endl;\n            }\n            if (left[a] != -1 or right[a]\
    \ != -1) {\n                string l = (left[a] != -1 ? to_string(left[a]) : \"\
    l\" + to_string(a));\n                string r = (right[a] != -1 ? to_string(right[a])\
    \ : \"r\" + to_string(a));\n                oss << \"    \" << l << \" -> \" <<\
    \ a << endl;\n                oss << \"    \" << l << \" -> \" << r << \" [ style\
    \ = invis ]\" << endl;\n                oss << \"    \" << r << \" -> \" << a\
    \ << endl;\n                oss << \"    { rank = same; \" << l << \"; \" << r\
    \ << \"; }\" << endl;\n                if (left[a] == -1) oss << \"    \" << l\
    \ << \" [ style = invis ]\" << endl;\n                if (right[a] == -1) oss\
    \ << \"    \" << r << \" [ style = invis ]\" << endl;\n            }\n       \
    \     if (left[a] != -1) go(left[a]);\n            if (right[a] != -1) go(right[a]);\n\
    \        };\n        REP (a, parent.size()) if (not get_parent_edge_type(a)) {\n\
    \            go(a);\n        }\n        oss << \"}\";\n        return oss.str();\n\
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <sstream>\n#include <vector>\n#include \"utils/macros.hpp\"\n#include\
    \ \"monoids/reversible.hpp\"\n\n\n/**\n * @brief Link-Cut tree (monoids without\
    \ commutativity, vertex set + path get)\n * @docs data_structure/link_cut_tree.md\n\
    \ * @description manages a dynamic forest of rooted trees\n * @note in each splay\
    \ tree, nodes are sorted from bottom to top. the rightmost node of the root splay\
    \ tree of the auxiliary tree is the root of represented tree.\n */\ntemplate <class\
    \ Monoid>\nclass link_cut_tree {\n    typedef typename Monoid::value_type value_type;\n\
    \    typedef typename reversible_monoid<Monoid>::value_type reversible_type;\n\
    \    const reversible_monoid<Monoid> mon;\n    std::vector<value_type> data; \
    \ // data of the original tree\n    std::vector<reversible_type> path;  // sum\
    \ of data of the sub-tree in the belonging splay tree\n    std::vector<int> parent,\
    \ left, right;  // of the auxiliary tree\n    std::vector<bool> is_reversed; \
    \ // of the auxiliary tree; not applied to left, right, and path yet\n\n    /**\n\
    \     * @description returns whether `a` and `parent[a]` is in the same splay\
    \ tree\n     */\n    int get_parent_edge_type(int a) const {\n        if (parent[a]\
    \ != -1 and left[parent[a]] == a) {\n            assert (not is_reversed[parent[a]]);\n\
    \            return -1;  // heavy (left-child)\n        } else if (parent[a] !=\
    \ -1 and right[parent[a]] == a) {\n            assert (not is_reversed[parent[a]]);\n\
    \            return +1;  // heavy (right-child)\n        } else {\n          \
    \  return 0;  // light\n        }\n    }\n\n    /**\n     * @description make\
    \ `a` the parent of the current parent of `a`\n     */\n    void rotate(int a)\
    \ {\n        int b = parent[a];\n        assert (b != -1);\n        assert (not\
    \ is_reversed[b]);\n        assert (not is_reversed[a]);\n        switch (get_parent_edge_type(b))\
    \ {\n            case -1:  // left\n                left[parent[b]] = a;\n   \
    \             break;\n            case 1:  // right\n                right[parent[b]]\
    \ = a;\n                break;\n        }\n        switch (get_parent_edge_type(a))\
    \ {\n            case -1:  // left\n                parent[a] = std::exchange(parent[b],\
    \ a);\n                left[b] = std::exchange(right[a], b);\n               \
    \ if (left[b] != -1) parent[left[b]] = b;\n                break;\n          \
    \  case 1:  // right\n                parent[a] = std::exchange(parent[b], a);\n\
    \                right[b] = std::exchange(left[a], b);\n                if (right[b]\
    \ != -1) parent[right[b]] = b;\n                break;\n            default: \
    \ // root\n                assert (false);\n        }\n        update_path(b);\n\
    \        update_path(a);\n    }\n\n    /**\n     * @description make `a` the root\
    \ of the beloging splay tree\n     */\n    void splay(int a) {\n        propagate_reverse_splay(a);\n\
    \        while (get_parent_edge_type(a)) {\n            // a is not the root of\
    \ the splay tree\n            if (not get_parent_edge_type(parent[a])) {\n   \
    \             // zig step: parent[a] is the root of the splay tree\n         \
    \       rotate(a);\n            } else if (get_parent_edge_type(a) == get_parent_edge_type(parent[a]))\
    \ {\n                // zig-zig step\n                rotate(parent[a]);\n   \
    \             rotate(a);\n            } else {\n                // zig-zag step\n\
    \                rotate(a);\n                rotate(a);\n            }\n     \
    \   }\n    }\n\n    /**\n     * @description make `a` the root of the auxiliary\
    \ tree\n     * @note `a` becomes a terminal of the heavy path\n     */\n    void\
    \ expose(int a) {\n        // make a light path from `a` to the root\n       \
    \ for (int b = a; b != -1; b = parent[b]) {\n            splay(b);\n        }\n\
    \        // make `a` the terminal of the path\n        assert (not is_reversed[a]);\n\
    \        left[a] = -1;\n        update_path(a);\n        // make the path heavy\n\
    \        for (int b = a; parent[b] != -1; b = parent[b]) {\n            left[parent[b]]\
    \ = b;\n            update_path(parent[b]);\n        }\n        splay(a);\n  \
    \  }\n\n    void propagate_reverse_node(int a) {\n        if (is_reversed[a])\
    \ {\n            is_reversed[a] = false;\n            path[a] = reversible_monoid<Monoid>::reverse(path[a]);\n\
    \            if (right[a] != -1) is_reversed[right[a]] = not is_reversed[right[a]];\n\
    \            if (left[a] != -1) is_reversed[left[a]] = not is_reversed[left[a]];\n\
    \            std::swap(left[a], right[a]);\n        }\n    }\n    void propagate_reverse_splay(int\
    \ a) {\n        if (parent[a] != -1 and (left[parent[a]] == a or right[parent[a]]\
    \ == a)) {\n            propagate_reverse_splay(parent[a]);\n        }\n     \
    \   propagate_reverse_node(a);\n        if (right[a] != -1) propagate_reverse_node(right[a]);\n\
    \        if (left[a] != -1) propagate_reverse_node(left[a]);\n    }\n\n    /**\n\
    \     * @note `a` should be the root of the splay tree\n     */\n    void update_path(int\
    \ a) {\n        path[a] = reversible_monoid<Monoid>::make(data[a]);\n        if\
    \ (right[a] != -1) path[a] = mon.mult(path[a], path[right[a]]);\n        if (left[a]\
    \ != -1) path[a] = mon.mult(path[left[a]], path[a]);\n    }\n\npublic:\n    link_cut_tree(int\
    \ size, const Monoid & mon_ = Monoid())\n            : mon(mon_), data(size, mon.base.unit()),\
    \ path(size, mon.unit()), parent(size, -1), left(size, -1), right(size, -1), is_reversed(size,\
    \ false) {\n    }\n\n    /**\n     * @description make a direct edge from `a`\
    \ to `b`\n     * @note `a` must be a root\n     * @note `b` must not be a descendant\
    \ of `a`\n     */\n    void link(int a, int b) {\n        expose(b);  // for the\
    \ time complexity\n        expose(a);  // to make `a` the root\n        assert\
    \ (not is_reversed[a]);\n        assert (right[a] == -1);  // `a` must be a root\n\
    \        parent[a] = b;\n    }\n\n    /**\n     * @description remove the direct\
    \ edge from `a`\n     * @note `a` must not be a root\n     */\n    void cut(int\
    \ a) {\n        expose(a);  // to make `a` the root\n        assert (not is_reversed[a]);\n\
    \        assert (right[a] != -1);  // `a` must not be a root\n        parent[right[a]]\
    \ = -1;\n        right[a] = -1;\n        update_path(a);\n    }\n\n    /**\n \
    \    * @note -1 is returned when `a` and `b` are not in the same tree\n     */\n\
    \    int get_lowest_common_ancestor(int a, int b) {\n        expose(b);  // for\
    \ the time complexity\n        expose(a);  // to make `a` the root\n        assert\
    \ (not is_reversed[a]);\n        int preserved = -1;\n        std::swap(left[a],\
    \ preserved);  // make `a` and `b` belong different splay trees even if `b` is\
    \ a descendant of `a`\n        int result = b;\n        int c = b;\n        for\
    \ (; c != a and c != -1; c = parent[c]) {\n            assert (parent[c] != -1);\n\
    \            if (not get_parent_edge_type(c)) {  // when it enters another splay\
    \ tree\n                result = parent[c];\n            }\n        }\n      \
    \  std::swap(left[a], preserved);\n        return c == a ? result : -1;\n    }\n\
    \n    bool are_connected(int a, int b) {\n        return get_lowest_common_ancestor(a,\
    \ b) != -1;\n    }\n\n    int get_parent(int a) {\n        expose(a);\n      \
    \  assert (not is_reversed[a]);\n        if (right[a] == -1) return parent[a];\n\
    \        for (int b = right[a]; ; b = left[b]) {\n            propagate_reverse_node(b);\n\
    \            if (left[b] == -1) {\n                splay(b);  // for the time\
    \ complexity\n                return b;\n            }\n        }\n    }\n\n \
    \   int get_root(int a) {\n        expose(a);\n        assert (not is_reversed[a]);\n\
    \        while (right[a] != -1) {\n            a = right[a];\n        }\n    \
    \    splay(a);  // for the time complexity\n        return a;\n    }\n\n    /**\n\
    \     * @description make `a` the root of the represented tree\n     */\n    void\
    \ evert(int a) {\n        expose(a);  // to make `a` the root\n        assert\
    \ (not is_reversed[a]);\n        assert (left[a] == -1);  // `a` is the terminal\n\
    \        is_reversed[a] = true;\n    }\n\n    void vertex_set(int a, value_type\
    \ value) {\n        splay(a);  // to make `a` the root of a splay tree\n     \
    \   data[a] = value;\n        update_path(a);\n    }\n\n    value_type vertex_get(int\
    \ a) const {\n        return data[a];\n    }\n\n    value_type path_get(int a,\
    \ int b) {\n        expose(a);  // for the time complexity\n        expose(b);\
    \  // to make `b` the root\n        assert (not is_reversed[a]);\n        auto\
    \ data_a = reversible_monoid<Monoid>::make(data[a]);\n        reversible_type\
    \ up = (right[a] == -1 ? data_a : mon.mult(data_a, path[right[a]]));\n       \
    \ reversible_type down = (left[a] == -1 ? data_a : mon.mult(path[left[a]], data_a));\n\
    \        for (int c = a; c != b and c != -1; c = parent[c]) {\n            assert\
    \ (parent[c] != -1);\n            assert (not is_reversed[parent[c]]);\n     \
    \       auto data_parent_c = reversible_monoid<Monoid>::make(data[parent[c]]);\n\
    \            switch (get_parent_edge_type(c)) {\n                case -1:  //\
    \ heavy (left-child)\n                    up = mon.mult(up, data_parent_c);\n\
    \                    if (right[parent[c]] != -1) up = mon.mult(up, path[right[parent[c]]]);\n\
    \                    break;\n                case 1:  // heavy (right-child)\n\
    \                    down = mon.mult(data_parent_c, down);\n                 \
    \   if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]], down);\n\
    \                    break;\n                case 0:  // light\n             \
    \       down = reversible_monoid<Monoid>::reverse(up);\n                    up\
    \ = mon.mult(up, data_parent_c);\n                    if (right[parent[c]] !=\
    \ -1) up = mon.mult(up, path[right[parent[c]]]);\n                    down = mon.mult(data_parent_c,\
    \ down);\n                    if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]],\
    \ down);\n                    break;\n            }\n        }\n        return\
    \ reversible_monoid<Monoid>::get(reversible_monoid<Monoid>::reverse(down));\n\
    \    }\n\n    std::string to_graphviz() const {\n        using namespace std;\n\
    \        ostringstream oss;\n        oss << \"digraph G {\" << endl;\n       \
    \ oss << \"    graph [ rankdir = BT, bgcolor = \\\"#00000000\\\" ]\" << endl;\n\
    \        oss << \"    node [ shape = circle, style = filled, fillcolor = \\\"\
    #ffffffff\\\" ]\" << endl;\n        REP (a, parent.size()) {\n            // oss\
    \ << \"    \" << a << \";\" << endl;\n            oss << \"    \" << a << \"[\
    \ label = \\\"\" << a << \"(\" << data[a] << \",\" << path[a] << (is_reversed[a]\
    \ ? \" +rev\" : \"\") << \")\\\"];\" << endl;\n        }\n        function <void\
    \ (int)> go = [&](int a) {\n            if (parent[a] != -1 and not get_parent_edge_type(a))\
    \ {\n                oss << \"    \" << a << \" -> \" << parent[a] << \" [ style\
    \ = dashed ]\" << endl;\n            }\n            if (left[a] != -1 or right[a]\
    \ != -1) {\n                string l = (left[a] != -1 ? to_string(left[a]) : \"\
    l\" + to_string(a));\n                string r = (right[a] != -1 ? to_string(right[a])\
    \ : \"r\" + to_string(a));\n                oss << \"    \" << l << \" -> \" <<\
    \ a << endl;\n                oss << \"    \" << l << \" -> \" << r << \" [ style\
    \ = invis ]\" << endl;\n                oss << \"    \" << r << \" -> \" << a\
    \ << endl;\n                oss << \"    { rank = same; \" << l << \"; \" << r\
    \ << \"; }\" << endl;\n                if (left[a] == -1) oss << \"    \" << l\
    \ << \" [ style = invis ]\" << endl;\n                if (right[a] == -1) oss\
    \ << \"    \" << r << \" [ style = invis ]\" << endl;\n            }\n       \
    \     if (left[a] != -1) go(left[a]);\n            if (right[a] != -1) go(right[a]);\n\
    \        };\n        REP (a, parent.size()) if (not get_parent_edge_type(a)) {\n\
    \            go(a);\n        }\n        oss << \"}\";\n        return oss.str();\n\
    \    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  - monoids/reversible.hpp
  isVerificationFile: false
  path: data_structure/link_cut_tree.hpp
  requiredBy: []
  timestamp: '2020-02-27 11:49:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - data_structure/link_cut_tree.marked_ancestor.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
  - data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
documentation_of: data_structure/link_cut_tree.hpp
layout: document
redirect_from:
- /library/data_structure/link_cut_tree.hpp
- /library/data_structure/link_cut_tree.hpp.html
title: Link-Cut tree (monoids without commutativity, vertex set + path get)
---
## Operations

根付き木からなる森 $G$ を動的に操作できる。頂点数を $N$ として均し $O(\log N)$ で次が処理できる。

-   $\mathtt{link}(x, y)$: 根である頂点 $x$ から頂点 $y$ に辺を追加する。
-   $\mathtt{cut}(x)$: 根でない頂点 $x$ とその親との間の辺を削除する。
-   この森における接続性についての様々な質問
    -   $\mathtt{get\unicode{95}parent}(x)$
    -   $\mathtt{get\unicode{95}root}(x)$
    -   $\mathtt{are\unicode{95}connected}(x, y)$
    -   $\mathtt{get\unicode{95}lowest\unicode{95}common\unicode{95}ancestor}(x, y)$
-   $\mathtt{evert}(x)$: 頂点 $x$ を根にする。つまり、頂点 $x$ からその所属する木の根までの辺をすべて反転させる。

加えて、それぞれの頂点 $x$ に monoid 値重み $a_x \in M$ を乗せて、次が処理できる。

-   $\mathtt{vertex\unicode{95}set}(x, b)$: 頂点 $x$ の重みを $a_x \gets b$ と更新する。
-   $\mathtt{vertex\unicode{95}get}(x, b)$: 頂点 $x$ の重み $a_x \gets b$ を計算する。
-   $\mathtt{path\unicode{95}get}(x, y)$: 頂点 $x$ から $y$ への唯一のパス $x, z_1, z_2, \dots, y$ に沿った重みの積 $a_x \cdot a _ {z_1} \cdot a _ {z_2} \cdot \dots \cdot a_y$ を計算する。
