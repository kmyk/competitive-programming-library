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


# :warning: data_structure/link_cut_tree.spaceships.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/link_cut_tree.spaceships.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00


* see: <a href="https://atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships">https://atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships</a>


## Depends on

* :heavy_check_mark: <a href="link_cut_tree.hpp.html">an extended structure of union-find tree <small>(data_structure/link_cut_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// #define PROBLEM "https://atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships"
#include <cassert>
#include "data_structure/link_cut_tree.hpp"

/*
int main() {
    int n, q; cin >> n >> q;
    link_cut_tree g(n);
    while (q --) {
        int t, a; cin >> t >> a; -- a;
        if (t == 1) {
            int b; cin >> b; -- b;
            g.link(a, b);
        } else if (t == 2) {
            g.cut(a);
        } else if (t == 3) {
            int b; cin >> b; -- b;
            int c = g.get_lowest_common_ancestor(a, b);
            cout << (c == -1 ? -1 : c + 1) << endl;
        } else {
            assert (false);
        }
    }
    return 0;
}
*/

void sample1() {
    link_cut_tree g(6);
    g.link(1, 3);
    assert (g.get_lowest_common_ancestor(1, 5) == -1);
    g.link(3, 2);
    g.link(5, 3);
    assert (g.get_lowest_common_ancestor(1, 5) == 3);
}

void sample2() {
    link_cut_tree g(8);
    g.link(0, 1);
    g.link(5, 4);
    g.link(6, 7);
    assert (g.get_lowest_common_ancestor(4, 5) == 4);
    g.link(4, 3);
    g.link(7, 0);
    assert (g.get_lowest_common_ancestor(6, 1) == 1);
    assert (g.get_lowest_common_ancestor(2, 7) == -1);
    assert (g.get_lowest_common_ancestor(0, 7) == 0);
    g.link(2, 1);
    g.link(3, 0);
    assert (g.get_lowest_common_ancestor(7, 4) == 0);
    assert (g.get_lowest_common_ancestor(3, 2) == 1);
    g.cut(3);
    assert (g.get_lowest_common_ancestor(5, 7) == -1);
    g.link(1, 4);
    assert (g.get_lowest_common_ancestor(5, 7) == 4);
    g.cut(7);
    assert (g.get_lowest_common_ancestor(0, 3) == 3);
    assert (g.get_lowest_common_ancestor(5, 7) == -1);
    assert (g.get_lowest_common_ancestor(5, 2) == 4);
    g.cut(2);
    assert (g.get_lowest_common_ancestor(0, 1) == 1);
    g.link(3, 2);
    assert (g.get_lowest_common_ancestor(1, 5) == 4);
    g.link(7, 2);
    assert (g.get_lowest_common_ancestor(0, 6) == 2);
    assert (g.get_lowest_common_ancestor(0, 5) == 4);
    assert (g.get_lowest_common_ancestor(4, 3) == 3);
    g.cut(1);
    g.cut(4);
    g.link(2, 5);
    g.link(1, 6);
    assert (g.get_lowest_common_ancestor(0, 3) == 2);
    assert (g.get_lowest_common_ancestor(0, 4) == 4);
    assert (g.get_lowest_common_ancestor(5, 6) == 5);
}

int main() {
    sample1();
    sample2();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/link_cut_tree.spaceships.random-test.cpp"
// #define PROBLEM "https://atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships"
#line 2 "data_structure/link_cut_tree.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 9 "data_structure/link_cut_tree.hpp"


/**
 * @brief an extended structure of union-find tree
 * @note this is for the problem "Spaceships", JOI Sprint Training Camp (http://imoz.jp/data/joi/2013-sp-d4-spaceships.pdf)
 * @note in each splay tree, nodes are sorted from bottom to top. the rightmost node of the root splay tree of the auxiliary tree is the root of represented tree.
 */
class link_cut_tree {
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
     * @note `a` must not be a terminal of the heavy path
     */
    void expose(int a) {
        // make a light path from `a` to the root
        for (int b = a; b != -1; b = parent[b]) {
            splay(b);
        }
        // make the path heavy
        for (int b = a; parent[b] != -1; b = parent[b]) {
            left[parent[b]] = b;
        }
    }

    void access(int a) {
        expose(a);
        splay(a);
        assert (parent[a] == -1);
    }

public:
    link_cut_tree(int size)
            : parent(size, -1), left(size, -1), right(size, -1) {
    }

    /**
     * @description make a direct edge from `a` to `b`
     * @note `a` must be a root
     * @note `b` must not be a descendant of `a`
     */
    void link(int a, int b) {
        access(b);  // for the time complexity
        access(a);  // to make a the root
        assert (right[a] == -1);  // a must be a root
        parent[a] = b;
    }

    /**
     * @description remove the direct edge from `a`
     */
    void cut(int a) {
        access(a);  // to make a the root
        if (right[a] == -1) return;  // there is no parent on the represented tree
        parent[right[a]] = -1;
        right[a] = -1;
    }

    /**
     * @note -1 is returned when `a` and `b` are not in the same tree
     */
    int get_lowest_common_ancestor(int a, int b) {
        access(b);  // for the time complexity
        access(a);  // to make `a` the root
        left[a] = -1;  // make `a` and `b` belong different splay trees if `b` is a descendant of `a`
        int result = b;
        int c = b;
        for (; c != a and c != -1; c = parent[c]) {
            if (parent[c] != -1 and not get_parent_edge_type(c)) {  // when it enters another splay tree
                result = parent[c];
            }
        }
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

    std::string to_graphviz() const {
        using namespace std;
        ostringstream oss;
        oss << "digraph G {" << endl;
        oss << "    graph [ rankdir = BT, bgcolor = \"#00000000\" ]" << endl;
        oss << "    node [ shape = circle, style = filled, fillcolor = \"#ffffffff\" ]" << endl;
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
#line 3 "data_structure/link_cut_tree.spaceships.random-test.cpp"
#include "data_structure/link_cut_tree.hpp"

/*
int main() {
    int n, q; cin >> n >> q;
    link_cut_tree g(n);
    while (q --) {
        int t, a; cin >> t >> a; -- a;
        if (t == 1) {
            int b; cin >> b; -- b;
            g.link(a, b);
        } else if (t == 2) {
            g.cut(a);
        } else if (t == 3) {
            int b; cin >> b; -- b;
            int c = g.get_lowest_common_ancestor(a, b);
            cout << (c == -1 ? -1 : c + 1) << endl;
        } else {
            assert (false);
        }
    }
    return 0;
}
*/

void sample1() {
    link_cut_tree g(6);
    g.link(1, 3);
    assert (g.get_lowest_common_ancestor(1, 5) == -1);
    g.link(3, 2);
    g.link(5, 3);
    assert (g.get_lowest_common_ancestor(1, 5) == 3);
}

void sample2() {
    link_cut_tree g(8);
    g.link(0, 1);
    g.link(5, 4);
    g.link(6, 7);
    assert (g.get_lowest_common_ancestor(4, 5) == 4);
    g.link(4, 3);
    g.link(7, 0);
    assert (g.get_lowest_common_ancestor(6, 1) == 1);
    assert (g.get_lowest_common_ancestor(2, 7) == -1);
    assert (g.get_lowest_common_ancestor(0, 7) == 0);
    g.link(2, 1);
    g.link(3, 0);
    assert (g.get_lowest_common_ancestor(7, 4) == 0);
    assert (g.get_lowest_common_ancestor(3, 2) == 1);
    g.cut(3);
    assert (g.get_lowest_common_ancestor(5, 7) == -1);
    g.link(1, 4);
    assert (g.get_lowest_common_ancestor(5, 7) == 4);
    g.cut(7);
    assert (g.get_lowest_common_ancestor(0, 3) == 3);

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

