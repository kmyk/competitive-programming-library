---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "heavy light decomposition / \u91CD\u8EFD\u5206\u89E3"
    links:
    - http://math314.hateblo.jp/entry/2014/06/24/220107
  bundledCode: "#line 1 \"old/heavy_light_decomposition.inc.cpp\"\n/**\n * @brief\
    \ heavy light decomposition / \u91CD\u8EFD\u5206\u89E3\n * @description for given\
    \ rooted tree $G = (V, E)$, decompose the vertices to disjoint paths, and construct\
    \ new small rooted tree $G' = (V', E')$ of the disjoint paths.\n * @see http://math314.hateblo.jp/entry/2014/06/24/220107\n\
    \ */\nstruct heavy_light_decomposition {\n    vector<vector<int> > path; // :\
    \ V' -> list of V, bottom to top order\n    vector<int> path_of; // : V -> V'\n\
    \    vector<int> index_of; // : V -> int, the index of the vertex in the path\
    \ that belongs to\n    vector<int> parent; // : V' -> V, one node has -1 as the\
    \ parent\n    heavy_light_decomposition(int root, vector<vector<int> > const &\
    \ g) {\n        int n = g.size();\n        vector<int> tour_parent(n, -1);\n \
    \       vector<int> euler_tour(n); {\n            int i = 0;\n            stack<int>\
    \ stk;\n            tour_parent[root] = -1;\n            euler_tour[i ++] = root;\n\
    \            stk.push(root);\n            while (not stk.empty()) {\n        \
    \        int x = stk.top(); stk.pop();\n                for (int y : g[x]) if\
    \ (y != tour_parent[x]) {\n                    tour_parent[y] = x;\n         \
    \           euler_tour[i ++] = y;\n                    stk.push(y);\n        \
    \        }\n            }\n        }\n        path_of.resize(n);\n        index_of.resize(n);\n\
    \        vector<int> subtree_height(n);\n        int path_count = 0;\n       \
    \ REP_R (i, n) {\n            int y = euler_tour[i];\n            if (y != root)\
    \ {\n                int x = tour_parent[y];\n                chmax(subtree_height[x],\
    \ subtree_height[y] + 1);\n            }\n            if (subtree_height[y] ==\
    \ 0) {\n                // make a new path\n                path_of[y] = path_count\
    \ ++;\n                index_of[y] = 0;\n                path.emplace_back();\n\
    \                path.back().push_back(y);\n                parent.push_back(tour_parent[y]);\n\
    \            } else {\n                // add to an existing path\n          \
    \      int i = -1;\n                for (int z : g[y]) {\n                   \
    \ if (subtree_height[z] == subtree_height[y] - 1) {\n                        i\
    \ = path_of[z];\n                        break;\n                    }\n     \
    \           }\n                assert (i != -1);\n                path_of[y] =\
    \ i;\n                index_of[y] = path[i].size();\n                path[i].push_back(y);\n\
    \                parent[i] = tour_parent[y];\n            }\n        }\n    }\n\
    \n    /**\n     * @brief construct an adjacency list for the decomposed tree\n\
    \     * @note undircted\n     */\n    vector<vector<int> > to_adjacency_list()\
    \ const {\n        int n = path.size();\n        vector<vector<int> > g(n);\n\
    \        REP (i, n) {\n            if (parent[i] == -1) continue;\n          \
    \  int j = path_of[parent[i]];\n            g[i].push_back(j);\n            g[j].push_back(i);\n\
    \        }\n        return g;\n    }\n\n    /**\n     * @brief reduce a path-query\
    \ to range-queries aboud nodes\n     * @arg lca is for the original tree, not\
    \ the decomposed tree\n     * @arg func is a callback function f(i, l, r), where\
    \ i in V is an index of path, [l, r) is a range on the path\n     */\n    template\
    \ <class LowestCommonAncestor, class Func>\n    void path_node_do_something(LowestCommonAncestor\
    \ const & lca, int x, int y, Func func) const {\n        int z = lca(x, y);\n\
    \        auto climb = [&](int & v) {\n            while (path_of[v] != path_of[z])\
    \ {\n                int i = path_of[v];\n                func(i, index_of[v],\
    \ path[i].size());\n                v = parent[i];\n            }\n        };\n\
    \        climb(x);\n        climb(y);\n        int i = path_of[z];\n        if\
    \ (index_of[x] > index_of[y]) swap(x, y);\n        func(i, index_of[x], index_of[y]\
    \ + 1);\n    }\n};\n\n\ntemplate <typename SegmentTree>\nstruct heavy_light_decomposition_edge_adapter\
    \ {\n    typedef typename SegmentTree::monoid_type CommutativeMonoid;\n    typedef\
    \ typename SegmentTree::endomorphism_type Endomorphism;\n    typedef typename\
    \ CommutativeMonoid::type type;\n\n    vector<SegmentTree> segtree;\n    vector<type>\
    \ link; // edges between a segtree and the parent segtree\n    heavy_light_decomposition\
    \ & hl;\n    lowest_common_ancestor & lca;\n    CommutativeMonoid mon;\n    Endomorphism\
    \ endo;\n    heavy_light_decomposition_edge_adapter(\n            heavy_light_decomposition\
    \ & a_hl,\n            lowest_common_ancestor & a_lca,\n            type initial_value\
    \ = CommutativeMonoid().unit(),\n            CommutativeMonoid const & a_mon =\
    \ CommutativeMonoid(),\n            Endomorphism const & a_endo = Endomorphism())\n\
    \            : hl(a_hl), lca(a_lca), mon(a_mon), endo(a_endo) {\n        repeat\
    \ (i, hl.path.size()) {\n            segtree.emplace_back(hl.path[i].size()-1,\
    \ initial_value, a_mon, a_endo);\n        }\n        link.resize(hl.path.size(),\
    \ initial_value);\n    }\n\n    template <class Func1, class Func2>\n    void\
    \ path_do_something(int x, int y, Func1 func1, Func2 func2) {\n        int z =\
    \ lca(x, y);\n        auto climb = [&](int & x) {\n            while (hl.path_of[x]\
    \ != hl.path_of[z]) {\n                int i = hl.path_of[x];\n              \
    \  func1(segtree[i], hl.index_of[x], hl.path[i].size()-1);\n                func2(link[i]);\n\
    \                x = hl.parent[i];\n            }\n        };\n        climb(x);\n\
    \        climb(y);\n        int i = hl.path_of[z];\n        if (hl.index_of[x]\
    \ > hl.index_of[y]) swap(x, y);\n        func1(segtree[i], hl.index_of[x], hl.index_of[y]);\n\
    \    }\n    type path_concat(int x, int y) {\n        type acc = mon.unit();\n\
    \        path_do_something(x, y, [&](SegmentTree & segtree, int l, int r) {\n\
    \            acc = mon.append(acc, segtree.range_concat(l, r));\n        }, [&](type\
    \ & value) {\n            acc = mon.append(acc, value);\n        });\n       \
    \ return acc;\n    }\n    void path_apply(int x, int y, typename Endomorphism::type\
    \ f) {\n        path_do_something(x, y, [&](SegmentTree & segtree, int l, int\
    \ r) {\n            segtree.range_apply(l, r, f);\n        }, [&](type & value)\
    \ {\n            value = endo.apply(f, value);\n        });\n    }\n};\n"
  code: "/**\n * @brief heavy light decomposition / \u91CD\u8EFD\u5206\u89E3\n * @description\
    \ for given rooted tree $G = (V, E)$, decompose the vertices to disjoint paths,\
    \ and construct new small rooted tree $G' = (V', E')$ of the disjoint paths.\n\
    \ * @see http://math314.hateblo.jp/entry/2014/06/24/220107\n */\nstruct heavy_light_decomposition\
    \ {\n    vector<vector<int> > path; // : V' -> list of V, bottom to top order\n\
    \    vector<int> path_of; // : V -> V'\n    vector<int> index_of; // : V -> int,\
    \ the index of the vertex in the path that belongs to\n    vector<int> parent;\
    \ // : V' -> V, one node has -1 as the parent\n    heavy_light_decomposition(int\
    \ root, vector<vector<int> > const & g) {\n        int n = g.size();\n       \
    \ vector<int> tour_parent(n, -1);\n        vector<int> euler_tour(n); {\n    \
    \        int i = 0;\n            stack<int> stk;\n            tour_parent[root]\
    \ = -1;\n            euler_tour[i ++] = root;\n            stk.push(root);\n \
    \           while (not stk.empty()) {\n                int x = stk.top(); stk.pop();\n\
    \                for (int y : g[x]) if (y != tour_parent[x]) {\n             \
    \       tour_parent[y] = x;\n                    euler_tour[i ++] = y;\n     \
    \               stk.push(y);\n                }\n            }\n        }\n  \
    \      path_of.resize(n);\n        index_of.resize(n);\n        vector<int> subtree_height(n);\n\
    \        int path_count = 0;\n        REP_R (i, n) {\n            int y = euler_tour[i];\n\
    \            if (y != root) {\n                int x = tour_parent[y];\n     \
    \           chmax(subtree_height[x], subtree_height[y] + 1);\n            }\n\
    \            if (subtree_height[y] == 0) {\n                // make a new path\n\
    \                path_of[y] = path_count ++;\n                index_of[y] = 0;\n\
    \                path.emplace_back();\n                path.back().push_back(y);\n\
    \                parent.push_back(tour_parent[y]);\n            } else {\n   \
    \             // add to an existing path\n                int i = -1;\n      \
    \          for (int z : g[y]) {\n                    if (subtree_height[z] ==\
    \ subtree_height[y] - 1) {\n                        i = path_of[z];\n        \
    \                break;\n                    }\n                }\n          \
    \      assert (i != -1);\n                path_of[y] = i;\n                index_of[y]\
    \ = path[i].size();\n                path[i].push_back(y);\n                parent[i]\
    \ = tour_parent[y];\n            }\n        }\n    }\n\n    /**\n     * @brief\
    \ construct an adjacency list for the decomposed tree\n     * @note undircted\n\
    \     */\n    vector<vector<int> > to_adjacency_list() const {\n        int n\
    \ = path.size();\n        vector<vector<int> > g(n);\n        REP (i, n) {\n \
    \           if (parent[i] == -1) continue;\n            int j = path_of[parent[i]];\n\
    \            g[i].push_back(j);\n            g[j].push_back(i);\n        }\n \
    \       return g;\n    }\n\n    /**\n     * @brief reduce a path-query to range-queries\
    \ aboud nodes\n     * @arg lca is for the original tree, not the decomposed tree\n\
    \     * @arg func is a callback function f(i, l, r), where i in V is an index\
    \ of path, [l, r) is a range on the path\n     */\n    template <class LowestCommonAncestor,\
    \ class Func>\n    void path_node_do_something(LowestCommonAncestor const & lca,\
    \ int x, int y, Func func) const {\n        int z = lca(x, y);\n        auto climb\
    \ = [&](int & v) {\n            while (path_of[v] != path_of[z]) {\n         \
    \       int i = path_of[v];\n                func(i, index_of[v], path[i].size());\n\
    \                v = parent[i];\n            }\n        };\n        climb(x);\n\
    \        climb(y);\n        int i = path_of[z];\n        if (index_of[x] > index_of[y])\
    \ swap(x, y);\n        func(i, index_of[x], index_of[y] + 1);\n    }\n};\n\n\n\
    template <typename SegmentTree>\nstruct heavy_light_decomposition_edge_adapter\
    \ {\n    typedef typename SegmentTree::monoid_type CommutativeMonoid;\n    typedef\
    \ typename SegmentTree::endomorphism_type Endomorphism;\n    typedef typename\
    \ CommutativeMonoid::type type;\n\n    vector<SegmentTree> segtree;\n    vector<type>\
    \ link; // edges between a segtree and the parent segtree\n    heavy_light_decomposition\
    \ & hl;\n    lowest_common_ancestor & lca;\n    CommutativeMonoid mon;\n    Endomorphism\
    \ endo;\n    heavy_light_decomposition_edge_adapter(\n            heavy_light_decomposition\
    \ & a_hl,\n            lowest_common_ancestor & a_lca,\n            type initial_value\
    \ = CommutativeMonoid().unit(),\n            CommutativeMonoid const & a_mon =\
    \ CommutativeMonoid(),\n            Endomorphism const & a_endo = Endomorphism())\n\
    \            : hl(a_hl), lca(a_lca), mon(a_mon), endo(a_endo) {\n        repeat\
    \ (i, hl.path.size()) {\n            segtree.emplace_back(hl.path[i].size()-1,\
    \ initial_value, a_mon, a_endo);\n        }\n        link.resize(hl.path.size(),\
    \ initial_value);\n    }\n\n    template <class Func1, class Func2>\n    void\
    \ path_do_something(int x, int y, Func1 func1, Func2 func2) {\n        int z =\
    \ lca(x, y);\n        auto climb = [&](int & x) {\n            while (hl.path_of[x]\
    \ != hl.path_of[z]) {\n                int i = hl.path_of[x];\n              \
    \  func1(segtree[i], hl.index_of[x], hl.path[i].size()-1);\n                func2(link[i]);\n\
    \                x = hl.parent[i];\n            }\n        };\n        climb(x);\n\
    \        climb(y);\n        int i = hl.path_of[z];\n        if (hl.index_of[x]\
    \ > hl.index_of[y]) swap(x, y);\n        func1(segtree[i], hl.index_of[x], hl.index_of[y]);\n\
    \    }\n    type path_concat(int x, int y) {\n        type acc = mon.unit();\n\
    \        path_do_something(x, y, [&](SegmentTree & segtree, int l, int r) {\n\
    \            acc = mon.append(acc, segtree.range_concat(l, r));\n        }, [&](type\
    \ & value) {\n            acc = mon.append(acc, value);\n        });\n       \
    \ return acc;\n    }\n    void path_apply(int x, int y, typename Endomorphism::type\
    \ f) {\n        path_do_something(x, y, [&](SegmentTree & segtree, int l, int\
    \ r) {\n            segtree.range_apply(l, r, f);\n        }, [&](type & value)\
    \ {\n            value = endo.apply(f, value);\n        });\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/heavy_light_decomposition.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/heavy_light_decomposition.inc.cpp
layout: document
redirect_from:
- /library/old/heavy_light_decomposition.inc.cpp
- /library/old/heavy_light_decomposition.inc.cpp.html
title: "heavy light decomposition / \u91CD\u8EFD\u5206\u89E3"
---
