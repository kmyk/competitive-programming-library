// https://kimiyuki.net/blog/2017/06/06/agc-014-e/
/**
 * @brief heavy light decomposition
 * @description for given rooted tree G = (V, E), decompose the vertices to disjoint paths, and construct new small rooted tree G' = (V', E') of the disjoint paths.
 * @see http://math314.hateblo.jp/entry/2014/06/24/220107
 */
struct heavy_light_decomposition {
    vector<vector<int> > path; // V' -> list of V, bottom to top order
    vector<int> path_of; // V -> V'
    vector<int> index_of; // V -> int: the index of the vertex in the path that belongs to
    vector<int> parent; // V' -> V
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
        repeat_reverse (i, n) {
            int y = euler_tour[i];
            if (y != root) {
                int x = tour_parent[y];
                setmax(subtree_height[x], subtree_height[y] + 1);
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

// http://yukicoder.me/submissions/179395
template <typename SegmentTree>
struct heavy_light_decomposition_node_adapter {
    typedef typename SegmentTree::monoid_type CommutativeMonoid;
    typedef typename CommutativeMonoid::type underlying_type;

    vector<SegmentTree> segtree;
    heavy_light_decomposition & hl;
    lowest_common_ancestor & lca;
    CommutativeMonoid mon;
    heavy_light_decomposition_node_adapter(
            heavy_light_decomposition & a_hl,
            lowest_common_ancestor & a_lca,
            underlying_type initial_value = CommutativeMonoid().unit(),
            CommutativeMonoid const & a_mon = CommutativeMonoid())
            : hl(a_hl), lca(a_lca), mon(a_mon) {
        repeat (i, hl.path.size()) {
            segtree.emplace_back(hl.path[i].size(), initial_value, a_mon);
        }
    }

    void node_set(int x, underlying_type value) {
        int i = hl.path_of[x];
        int j = hl.index_of[x];
        segtree[i].point_set(j, value);
    }

    template <class Func>
    void path_do_something(int x, int y, Func func) {
        int z = lca(x, y);
        auto climb = [&](int & x) {
            while (hl.path_of[x] != hl.path_of[z]) {
                int i = hl.path_of[x];
                func(segtree[i], hl.index_of[x], hl.path[i].size());
                x = hl.parent[i];
            }
        };
        climb(x);
        climb(y);
        int i = hl.path_of[z];
        if (hl.index_of[x] > hl.index_of[y]) swap(x, y);
        func(segtree[i], hl.index_of[x], hl.index_of[y] + 1);
    }
    underlying_type path_concat(int x, int y) {
        underlying_type acc = mon.unit();
        path_do_something(x, y, [&](SegmentTree & segtree, int l, int r) {
            acc = mon.append(acc, segtree.range_concat(l, r));
        });
        return acc;
    }
};
