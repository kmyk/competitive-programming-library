---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Link-Cut tree (monoids without commutativity, vertex set + path get) <small>(data_structure/link_cut_tree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/link_cut_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-26 14:11:54+09:00




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

-   $\mathtt{point\unicode{95}set}(x, b)$: 頂点 $x$ の重みを $a_x \gets b$ と更新する。
-   $\mathtt{path\unicode{95}get}(x, y)$: 頂点 $x$ から $y$ への唯一のパス $x, z_1, z_2, \dots, y$ に沿った重みの積 $a_x \cdot a _ {z_1} \cdot a _ {z_2} \cdot \dots \cdot a_y$ を計算する。


## Depends on

* :heavy_check_mark: <a href="../monoids/reversible.hpp.html">monoids/reversible.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp.html">data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.marked_ancestor.test.cpp.html">data_structure/link_cut_tree.marked_ancestor.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.vertex_add_path_sum.test.cpp.html">data_structure/link_cut_tree.vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.vertex_set_path_composite.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
        propagate_reverse_expose(a);
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
    }
    void propagate_reverse_expose(int a) {
        if (parent[a] != -1) {
            propagate_reverse_expose(parent[a]);
        }
        propagate_reverse_node(a);
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
    link_cut_tree(int size, const reversible_monoid<Monoid> & mon_ = reversible_monoid<Monoid>())
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
            if (left[b] == -1) return b;
        }
    }

    int get_root(int a) {
        expose(a);
        assert (not is_reversed[a]);
        while (right[a] != -1) {
            a = right[a];
        }
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

    void point_set(int a, value_type value) {
        splay(a);  // to make `a` the root of a splay tree
        data[a] = value;
        update_path(a);
    }

    value_type point_get(int a) const {
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/link_cut_tree.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <sstream>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 2 "monoids/reversible.hpp"
#include <utility>

template <class Monoid>
struct reversible_monoid {
    typedef typename Monoid::value_type base_type;
    typedef std::pair<base_type, base_type> value_type;
    Monoid base;
    value_type unit() const { return std::make_pair(base.unit(), base.unit()); }
    value_type mult(const value_type & a, const value_type & b) const { return std::make_pair(base.mult(a.first, b.first), base.mult(b.second, a.second)); }
    static value_type make(const base_type & x) { return std::make_pair(x, x); }
    static value_type reverse(const value_type & a) { return std::make_pair(a.second, a.first); }
    static base_type get(const value_type & a) { return a.first; }
};
#line 9 "data_structure/link_cut_tree.hpp"


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
        propagate_reverse_expose(a);
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
    }
    void propagate_reverse_expose(int a) {
        if (parent[a] != -1) {
            propagate_reverse_expose(parent[a]);
        }
        propagate_reverse_node(a);
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
    link_cut_tree(int size, const reversible_monoid<Monoid> & mon_ = reversible_monoid<Monoid>())
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
            if (left[b] == -1) return b;
        }
    }

    int get_root(int a) {
        expose(a);
        assert (not is_reversed[a]);
        while (right[a] != -1) {
            a = right[a];
        }
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

    void point_set(int a, value_type value) {
        splay(a);  // to make `a` the root of a splay tree
        data[a] = value;
        update_path(a);
    }

    value_type point_get(int a) const {
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

