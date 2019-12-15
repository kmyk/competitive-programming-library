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


# :warning: heavy light decomposition / 重軽分解 <small>(graph/heavy_light_decomposition.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/heavy_light_decomposition.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900


* construct an adjacency list for the decomposed tree
* reduce a path-query to range-queries aboud nodes
* see: <a href="http://math314.hateblo.jp/entry/2014/06/24/220107">http://math314.hateblo.jp/entry/2014/06/24/220107</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief heavy light decomposition / 重軽分解
 * @description for given rooted tree $G = (V, E)$, decompose the vertices to disjoint paths, and construct new small rooted tree $G' = (V', E')$ of the disjoint paths.
 * @see http://math314.hateblo.jp/entry/2014/06/24/220107
 */
struct heavy_light_decomposition {
    vector<vector<int> > path; // : V' -> list of V, bottom to top order
    vector<int> path_of; // : V -> V'
    vector<int> index_of; // : V -> int, the index of the vertex in the path that belongs to
    vector<int> parent; // : V' -> V, one node has -1 as the parent
    heavy_light_decomposition(int root, vector<vector<int> > const & g) {
        int n = g.size();
        vector<int> tour_parent(n, -1);
        vector<int> euler_tour(n); {
            int i = 0;
            stack<int> stk;
            tour_parent[root] = -1;
            euler_tour[i ++] = root;
            stk.push(root);
            while (not stk.empty()) {
                int x = stk.top(); stk.pop();
                for (int y : g[x]) if (y != tour_parent[x]) {
                    tour_parent[y] = x;
                    euler_tour[i ++] = y;
                    stk.push(y);
                }
            }
        }
        path_of.resize(n);
        index_of.resize(n);
        vector<int> subtree_height(n);
        int path_count = 0;
        REP_R (i, n) {
            int y = euler_tour[i];
            if (y != root) {
                int x = tour_parent[y];
                chmax(subtree_height[x], subtree_height[y] + 1);
            }
            if (subtree_height[y] == 0) {
                // make a new path
                path_of[y] = path_count ++;
                index_of[y] = 0;
                path.emplace_back();
                path.back().push_back(y);
                parent.push_back(tour_parent[y]);
            } else {
                // add to an existing path
                int i = -1;
                for (int z : g[y]) {
                    if (subtree_height[z] == subtree_height[y] - 1) {
                        i = path_of[z];
                        break;
                    }
                }
                assert (i != -1);
                path_of[y] = i;
                index_of[y] = path[i].size();
                path[i].push_back(y);
                parent[i] = tour_parent[y];
            }
        }
    }

    /**
     * @brief construct an adjacency list for the decomposed tree
     * @note undircted
     */
    vector<vector<int> > to_adjacency_list() const {
        int n = path.size();
        vector<vector<int> > g(n);
        REP (i, n) {
            if (parent[i] == -1) continue;
            int j = path_of[parent[i]];
            g[i].push_back(j);
            g[j].push_back(i);
        }
        return g;
    }

    /**
     * @brief reduce a path-query to range-queries aboud nodes
     * @arg lca is for the original tree, not the decomposed tree
     * @arg func is a callback function f(i, l, r), where i in V is an index of path, [l, r) is a range on the path
     */
    template <class LowestCommonAncestor, class Func>
    void path_node_do_something(LowestCommonAncestor const & lca, int x, int y, Func func) const {
        int z = lca(x, y);
        auto climb = [&](int & v) {
            while (path_of[v] != path_of[z]) {
                int i = path_of[v];
                func(i, index_of[v], path[i].size());
                v = parent[i];
            }
        };
        climb(x);
        climb(y);
        int i = path_of[z];
        if (index_of[x] > index_of[y]) swap(x, y);
        func(i, index_of[x], index_of[y] + 1);
    }
};


template <typename SegmentTree>
struct heavy_light_decomposition_edge_adapter {
    typedef typename SegmentTree::monoid_type CommutativeMonoid;
    typedef typename SegmentTree::endomorphism_type Endomorphism;
    typedef typename CommutativeMonoid::type type;

    vector<SegmentTree> segtree;
    vector<type> link; // edges between a segtree and the parent segtree
    heavy_light_decomposition & hl;
    lowest_common_ancestor & lca;
    CommutativeMonoid mon;
    Endomorphism endo;
    heavy_light_decomposition_edge_adapter(
            heavy_light_decomposition & a_hl,
            lowest_common_ancestor & a_lca,
            type initial_value = CommutativeMonoid().unit(),
            CommutativeMonoid const & a_mon = CommutativeMonoid(),
            Endomorphism const & a_endo = Endomorphism())
            : hl(a_hl), lca(a_lca), mon(a_mon), endo(a_endo) {
        repeat (i, hl.path.size()) {
            segtree.emplace_back(hl.path[i].size()-1, initial_value, a_mon, a_endo);
        }
        link.resize(hl.path.size(), initial_value);
    }

    template <class Func1, class Func2>
    void path_do_something(int x, int y, Func1 func1, Func2 func2) {
        int z = lca(x, y);
        auto climb = [&](int & x) {
            while (hl.path_of[x] != hl.path_of[z]) {
                int i = hl.path_of[x];
                func1(segtree[i], hl.index_of[x], hl.path[i].size()-1);
                func2(link[i]);
                x = hl.parent[i];
            }
        };
        climb(x);
        climb(y);
        int i = hl.path_of[z];
        if (hl.index_of[x] > hl.index_of[y]) swap(x, y);
        func1(segtree[i], hl.index_of[x], hl.index_of[y]);
    }
    type path_concat(int x, int y) {
        type acc = mon.unit();
        path_do_something(x, y, [&](SegmentTree & segtree, int l, int r) {
            acc = mon.append(acc, segtree.range_concat(l, r));
        }, [&](type & value) {
            acc = mon.append(acc, value);
        });
        return acc;
    }
    void path_apply(int x, int y, typename Endomorphism::type f) {
        path_do_something(x, y, [&](SegmentTree & segtree, int l, int r) {
            segtree.range_apply(l, r, f);
        }, [&](type & value) {
            value = endo.apply(f, value);
        });
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/heavy_light_decomposition.inc.cpp"
/**
 * @brief heavy light decomposition / 重軽分解
 * @description for given rooted tree $G = (V, E)$, decompose the vertices to disjoint paths, and construct new small rooted tree $G' = (V', E')$ of the disjoint paths.
 * @see http://math314.hateblo.jp/entry/2014/06/24/220107
 */
struct heavy_light_decomposition {
    vector<vector<int> > path; // : V' -> list of V, bottom to top order
    vector<int> path_of; // : V -> V'
    vector<int> index_of; // : V -> int, the index of the vertex in the path that belongs to
    vector<int> parent; // : V' -> V, one node has -1 as the parent
    heavy_light_decomposition(int root, vector<vector<int> > const & g) {
        int n = g.size();
        vector<int> tour_parent(n, -1);
        vector<int> euler_tour(n); {
            int i = 0;
            stack<int> stk;
            tour_parent[root] = -1;
            euler_tour[i ++] = root;
            stk.push(root);
            while (not stk.empty()) {
                int x = stk.top(); stk.pop();
                for (int y : g[x]) if (y != tour_parent[x]) {
                    tour_parent[y] = x;
                    euler_tour[i ++] = y;
                    stk.push(y);
                }
            }
        }
        path_of.resize(n);
        index_of.resize(n);
        vector<int> subtree_height(n);
        int path_count = 0;
        REP_R (i, n) {
            int y = euler_tour[i];
            if (y != root) {
                int x = tour_parent[y];
                chmax(subtree_height[x], subtree_height[y] + 1);
            }
            if (subtree_height[y] == 0) {
                // make a new path
                path_of[y] = path_count ++;
                index_of[y] = 0;
                path.emplace_back();
                path.back().push_back(y);
                parent.push_back(tour_parent[y]);
            } else {
                // add to an existing path
                int i = -1;
                for (int z : g[y]) {
                    if (subtree_height[z] == subtree_height[y] - 1) {
                        i = path_of[z];
                        break;
                    }
                }
                assert (i != -1);
                path_of[y] = i;
                index_of[y] = path[i].size();
                path[i].push_back(y);
                parent[i] = tour_parent[y];
            }
        }
    }

    /**
     * @brief construct an adjacency list for the decomposed tree
     * @note undircted
     */
    vector<vector<int> > to_adjacency_list() const {
        int n = path.size();
        vector<vector<int> > g(n);
        REP (i, n) {
            if (parent[i] == -1) continue;
            int j = path_of[parent[i]];
            g[i].push_back(j);
            g[j].push_back(i);
        }
        return g;
    }

    /**
     * @brief reduce a path-query to range-queries aboud nodes
     * @arg lca is for the original tree, not the decomposed tree
     * @arg func is a callback function f(i, l, r), where i in V is an index of path, [l, r) is a range on the path
     */
    template <class LowestCommonAncestor, class Func>
    void path_node_do_something(LowestCommonAncestor const & lca, int x, int y, Func func) const {
        int z = lca(x, y);
        auto climb = [&](int & v) {
            while (path_of[v] != path_of[z]) {
                int i = path_of[v];
                func(i, index_of[v], path[i].size());
                v = parent[i];
            }
        };
        climb(x);
        climb(y);
        int i = path_of[z];
        if (index_of[x] > index_of[y]) swap(x, y);
        func(i, index_of[x], index_of[y] + 1);
    }
};


template <typename SegmentTree>
struct heavy_light_decomposition_edge_adapter {
    typedef typename SegmentTree::monoid_type CommutativeMonoid;
    typedef typename SegmentTree::endomorphism_type Endomorphism;
    typedef typename CommutativeMonoid::type type;

    vector<SegmentTree> segtree;
    vector<type> link; // edges between a segtree and the parent segtree
    heavy_light_decomposition & hl;
    lowest_common_ancestor & lca;
    CommutativeMonoid mon;
    Endomorphism endo;
    heavy_light_decomposition_edge_adapter(
            heavy_light_decomposition & a_hl,
            lowest_common_ancestor & a_lca,
            type initial_value = CommutativeMonoid().unit(),
            CommutativeMonoid const & a_mon = CommutativeMonoid(),
            Endomorphism const & a_endo = Endomorphism())
            : hl(a_hl), lca(a_lca), mon(a_mon), endo(a_endo) {
        repeat (i, hl.path.size()) {
            segtree.emplace_back(hl.path[i].size()-1, initial_value, a_mon, a_endo);
        }
        link.resize(hl.path.size(), initial_value);
    }

    template <class Func1, class Func2>
    void path_do_something(int x, int y, Func1 func1, Func2 func2) {
        int z = lca(x, y);
        auto climb = [&](int & x) {
            while (hl.path_of[x] != hl.path_of[z]) {
                int i = hl.path_of[x];
                func1(segtree[i], hl.index_of[x], hl.path[i].size()-1);
                func2(link[i]);
                x = hl.parent[i];
            }
        };
        climb(x);
        climb(y);
        int i = hl.path_of[z];
        if (hl.index_of[x] > hl.index_of[y]) swap(x, y);
        func1(segtree[i], hl.index_of[x], hl.index_of[y]);
    }
    type path_concat(int x, int y) {
        type acc = mon.unit();
        path_do_something(x, y, [&](SegmentTree & segtree, int l, int r) {
            acc = mon.append(acc, segtree.range_concat(l, r));
        }, [&](type & value) {
            acc = mon.append(acc, value);
        });
        return acc;
    }
    void path_apply(int x, int y, typename Endomorphism::type f) {
        path_do_something(x, y, [&](SegmentTree & segtree, int l, int r) {
            segtree.range_apply(l, r, f);

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

