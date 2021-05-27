---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table (idempotent monoid)
  - icon: ':heavy_check_mark:'
    path: graph/euler_tour_preorder.hpp
    title: Euler Tour (preorder)
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "lowest common ancestor / \u6700\u5C0F\u5171\u901A\u7956\u5148 (\u524D\u51E6\
      \u7406 $O(N)$ + $O(1)$, $\\pm 1$ RMQ and sparse table)"
  - icon: ':heavy_check_mark:'
    path: monoids/min_index.hpp
    title: monoids/min_index.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u865A\u6A39 / virtual trees"
    links:
    - https://codeforces.com/problemset/problem/613/D
  bundledCode: "#line 2 \"graph/virtual_trees.hpp\"\n#include <vector>\n#line 2 \"\
    utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n\
    #define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i,\
    \ n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for\
    \ (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 2 \"graph/euler_tour_preorder.hpp\"\n#include <functional>\n\
    #line 4 \"graph/euler_tour_preorder.hpp\"\n\n/**\n * @brief Euler Tour (preorder)\n\
    \ * @arg g must be a rooted tree, directed or undirected\n */\nvoid do_euler_tour_preorder(std::vector<std::vector<int>\
    \ > const & g, int root, std::vector<int> & tour, std::vector<int> & left, std::vector<int>\
    \ & right) {\n    int n = g.size();\n    tour.clear();\n    left.assign(n, -1);\n\
    \    right.assign(n, -1);\n    std::function<void (int, int)> go = [&](int x,\
    \ int parent) {\n        left[x] = tour.size();\n        tour.push_back(x);\n\
    \        for (int y : g[x]) if (y != parent) {\n            go(y, x);\n      \
    \  }\n        right[x] = tour.size();\n    };\n    go(root, -1);\n}\n#line 2 \"\
    graph/lowest_common_ancestor.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #line 5 \"graph/lowest_common_ancestor.hpp\"\n#include <utility>\n#line 5 \"data_structure/sparse_table.hpp\"\
    \n\n/**\n * @brief Sparse Table (idempotent monoid)\n * @note the unit is required\
    \ just for convenience\n * @note $O(N \\log N)$ space\n */\ntemplate <class IdempotentMonoid>\n\
    struct sparse_table {\n    typedef typename IdempotentMonoid::value_type value_type;\n\
    \    std::vector<std::vector<value_type> > table;\n    IdempotentMonoid mon;\n\
    \    sparse_table() = default;\n\n    /**\n     * @note $O(N \\log N)$ time\n\
    \     */\n    template <class InputIterator>\n    sparse_table(InputIterator first,\
    \ InputIterator last, const IdempotentMonoid & mon_ = IdempotentMonoid())\n  \
    \          : mon(mon_) {\n        table.emplace_back(first, last);\n        int\
    \ n = table[0].size();\n        int log_n = 32 - __builtin_clz(n);\n        table.resize(log_n,\
    \ std::vector<value_type>(n));\n        REP (k, log_n - 1) {\n            REP\
    \ (i, n) {\n                table[k + 1][i] = i + (1ll << k) < n ?\n         \
    \           mon.mult(table[k][i], table[k][i + (1ll << k)]) :\n              \
    \      table[k][i];\n            }\n        }\n    }\n\n    /**\n     * @note\
    \ $O(1)$\n     */\n    value_type range_get(int l, int r) const {\n        if\
    \ (l == r) return mon.unit();  // if there is no unit, remove this line\n    \
    \    assert (0 <= l and l < r and r <= (int)table[0].size());\n        int k =\
    \ 31 - __builtin_clz(r - l);  // log2\n        return mon.mult(table[k][l], table[k][r\
    \ - (1ll << k)]);\n    }\n};\n#line 3 \"monoids/min_index.hpp\"\n#include <climits>\n\
    #include <limits>\n#line 6 \"monoids/min_index.hpp\"\n\n/**\n * @note a semilattice\n\
    \ */\ntemplate <class T>\nstruct min_index_monoid {\n    typedef std::pair<T,\
    \ int> value_type;\n    value_type unit() const { return std::make_pair(std::numeric_limits<T>::max(),\
    \ INT_MAX); }\n    value_type mult(value_type a, value_type b) const { return\
    \ std::min(a, b); }\n};\n#line 9 \"graph/lowest_common_ancestor.hpp\"\n\n/**\n\
    \ * @brief lowest common ancestor / \u6700\u5C0F\u5171\u901A\u7956\u5148 (\u524D\
    \u51E6\u7406 $O(N)$ + $O(1)$, $\\pm 1$ RMQ and sparse table)\n * @see https://www.slideshare.net/yumainoue965/lca-and-rmq\n\
    \ * @note verified http://www.utpc.jp/2011/problems/travel.html\n */\nstruct lowest_common_ancestor\
    \ {\n    sparse_table<min_index_monoid<int> > table;\n    std::vector<int> index;\n\
    \    lowest_common_ancestor() = default;\n    /**\n     * @note $O(N)$\n     *\
    \ @param g is an adjacent list of a tree\n     * @note you can easily modify this\
    \ to accept forests\n     */\n    lowest_common_ancestor(int root, std::vector<std::vector<int>\
    \ > const & g) {\n        std::vector<std::pair<int, int> > tour;\n        index.assign(g.size(),\
    \ -1);\n        dfs(root, -1, 0, g, tour);\n        table = sparse_table<min_index_monoid<int>\
    \ >(ALL(tour));\n    }\nprivate:\n    /**\n     * @note sometimes causes stack\
    \ overflow without ulimit -s unlimited\n     */\n    void dfs(int x, int parent,\
    \ int depth, std::vector<std::vector<int> > const & g, std::vector<std::pair<int,\
    \ int> > & tour) {\n        index[x] = tour.size();\n        tour.emplace_back(depth,\
    \ x);\n        for (int y : g[x]) if (y != parent) {\n            dfs(y, x, depth\
    \ + 1, g, tour);\n            tour.emplace_back(depth, x);\n        }\n    }\n\
    public:\n    /**\n     * @note $O(1)$\n     */\n    int operator () (int x, int\
    \ y) const {\n        assert (0 <= x and x < index.size());\n        assert (0\
    \ <= y and y < index.size());\n        x = index[x];\n        y = index[y];\n\
    \        if (x > y) std::swap(x, y);\n        return table.range_get(x, y + 1).second;\n\
    \    }\n    int get_depth(int x) const {\n        assert (0 <= x and x < index.size());\n\
    \        return table.range_get(index[x], index[x] + 1).first;\n    }\n    int\
    \ get_dist(int x, int y) const {\n        assert (0 <= x and x < index.size());\n\
    \        assert (0 <= y and y < index.size());\n        int z = (*this)(x, y);\n\
    \        return get_depth(x) + get_depth(y) - 2 * get_depth(z);\n    }\n};\n#line\
    \ 6 \"graph/virtual_trees.hpp\"\n\n/**\n * @brief \u865A\u6A39 / virtual trees\n\
    \ * @note O(\\lvert X \\rvert \\log \\lvert X \\rvert)\n * @return the list of\
    \ vertices in the virtual tree, and the adjacent list using indices on the returned\
    \ list of vertices\n * @note verified at https://codeforces.com/problemset/problem/613/D\n\
    \ */\nstd::pair<std::vector<int>, std::vector<std::vector<int>>> construct_virtual_tree(const\
    \ std::vector<std::vector<int>>& g, int root, const lowest_common_ancestor& lca,\
    \ const std::vector<int>& tour_left, std::vector<int> marked) {\n    std::vector<int>\
    \ vertices;\n    std::vector<std::vector<int>> h;\n\n    std::vector<int> stk;\n\
    \    std::sort(ALL(marked), [&](int x, int y) -> bool {\n        return tour_left[x]\
    \ < tour_left[y];\n    });\n    for (int x : marked) {\n        int index_x =\
    \ vertices.size();\n        vertices.push_back(x);\n        h.emplace_back();\n\
    \        if (not stk.empty()) {\n            int z = lca(x, vertices[stk.back()]);\n\
    \n            // pop vectirces deeper than z\n            std::vector<int> popped;\n\
    \            while (not stk.empty() and lca.get_depth(z) < lca.get_depth(vertices[stk.back()]))\
    \ {\n                int index_y = stk.back();\n                stk.pop_back();\n\
    \                popped.push_back(index_y);\n            }\n\n            // add\
    \ the LCA if required\n            if (stk.empty() or vertices[stk.back()] !=\
    \ z) {\n                int index_z = vertices.size();\n                vertices.push_back(z);\n\
    \                h.emplace_back();\n                stk.push_back(index_z);\n\
    \            }\n\n            // add edges\n            if (not popped.empty())\
    \ {\n                int index_z = stk.back();\n                int index_y =\
    \ popped.back();\n                h[index_z].push_back(index_y);\n           \
    \     h[index_y].push_back(index_z);\n            }\n            REP (i, (int)popped.size()\
    \ - 1) {\n                int index_y1 = popped[i];\n                int index_y2\
    \ = popped[i + 1];\n                h[index_y1].push_back(index_y2);\n       \
    \         h[index_y2].push_back(index_y1);\n            }\n        }\n       \
    \ stk.push_back(index_x);\n    }\n    REP (i, (int)stk.size() - 1) {\n       \
    \ int index_x = stk[i];\n        int index_y = stk[i + 1];\n        h[index_x].push_back(index_y);\n\
    \        h[index_y].push_back(index_x);\n    }\n\n    return {vertices, h};\n\
    }\n\n/**\n * @note O(N log N + \\lvert X \\rvert \\log \\lvert X \\rvert)\n */\n\
    std::pair<std::vector<int>, std::vector<std::vector<int>>> construct_virtual_tree(const\
    \ std::vector<std::vector<int>>& g, int root, const std::vector<int>& marked)\
    \ {\n    lowest_common_ancestor lca(root, g);\n    std::vector<int> tour, left,\
    \ right;\n    do_euler_tour_preorder(g, root, tour, left, right);\n    return\
    \ construct_virtual_tree(g, root, lca, left, marked);\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"utils/macros.hpp\"\n#include\
    \ \"graph/euler_tour_preorder.hpp\"\n#include \"graph/lowest_common_ancestor.hpp\"\
    \n\n/**\n * @brief \u865A\u6A39 / virtual trees\n * @note O(\\lvert X \\rvert\
    \ \\log \\lvert X \\rvert)\n * @return the list of vertices in the virtual tree,\
    \ and the adjacent list using indices on the returned list of vertices\n * @note\
    \ verified at https://codeforces.com/problemset/problem/613/D\n */\nstd::pair<std::vector<int>,\
    \ std::vector<std::vector<int>>> construct_virtual_tree(const std::vector<std::vector<int>>&\
    \ g, int root, const lowest_common_ancestor& lca, const std::vector<int>& tour_left,\
    \ std::vector<int> marked) {\n    std::vector<int> vertices;\n    std::vector<std::vector<int>>\
    \ h;\n\n    std::vector<int> stk;\n    std::sort(ALL(marked), [&](int x, int y)\
    \ -> bool {\n        return tour_left[x] < tour_left[y];\n    });\n    for (int\
    \ x : marked) {\n        int index_x = vertices.size();\n        vertices.push_back(x);\n\
    \        h.emplace_back();\n        if (not stk.empty()) {\n            int z\
    \ = lca(x, vertices[stk.back()]);\n\n            // pop vectirces deeper than\
    \ z\n            std::vector<int> popped;\n            while (not stk.empty()\
    \ and lca.get_depth(z) < lca.get_depth(vertices[stk.back()])) {\n            \
    \    int index_y = stk.back();\n                stk.pop_back();\n            \
    \    popped.push_back(index_y);\n            }\n\n            // add the LCA if\
    \ required\n            if (stk.empty() or vertices[stk.back()] != z) {\n    \
    \            int index_z = vertices.size();\n                vertices.push_back(z);\n\
    \                h.emplace_back();\n                stk.push_back(index_z);\n\
    \            }\n\n            // add edges\n            if (not popped.empty())\
    \ {\n                int index_z = stk.back();\n                int index_y =\
    \ popped.back();\n                h[index_z].push_back(index_y);\n           \
    \     h[index_y].push_back(index_z);\n            }\n            REP (i, (int)popped.size()\
    \ - 1) {\n                int index_y1 = popped[i];\n                int index_y2\
    \ = popped[i + 1];\n                h[index_y1].push_back(index_y2);\n       \
    \         h[index_y2].push_back(index_y1);\n            }\n        }\n       \
    \ stk.push_back(index_x);\n    }\n    REP (i, (int)stk.size() - 1) {\n       \
    \ int index_x = stk[i];\n        int index_y = stk[i + 1];\n        h[index_x].push_back(index_y);\n\
    \        h[index_y].push_back(index_x);\n    }\n\n    return {vertices, h};\n\
    }\n\n/**\n * @note O(N log N + \\lvert X \\rvert \\log \\lvert X \\rvert)\n */\n\
    std::pair<std::vector<int>, std::vector<std::vector<int>>> construct_virtual_tree(const\
    \ std::vector<std::vector<int>>& g, int root, const std::vector<int>& marked)\
    \ {\n    lowest_common_ancestor lca(root, g);\n    std::vector<int> tour, left,\
    \ right;\n    do_euler_tour_preorder(g, root, tour, left, right);\n    return\
    \ construct_virtual_tree(g, root, lca, left, marked);\n}\n"
  dependsOn:
  - utils/macros.hpp
  - graph/euler_tour_preorder.hpp
  - graph/lowest_common_ancestor.hpp
  - data_structure/sparse_table.hpp
  - monoids/min_index.hpp
  isVerificationFile: false
  path: graph/virtual_trees.hpp
  requiredBy: []
  timestamp: '2021-05-28 06:48:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/virtual_trees.hpp
layout: document
redirect_from:
- /library/graph/virtual_trees.hpp
- /library/graph/virtual_trees.hpp.html
title: "\u865A\u6A39 / virtual trees"
---
