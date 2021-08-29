---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table (idempotent monoid)
  - icon: ':heavy_check_mark:'
    path: monoids/min_index.hpp
    title: monoids/min_index.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/virtual_trees.hpp
    title: "\u865A\u6A39 / virtual trees"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.aoj.test.cpp
    title: graph/lowest_common_ancestor.aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.yosupo.test.cpp
    title: graph/lowest_common_ancestor.yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "lowest common ancestor / \u6700\u5C0F\u5171\u901A\u7956\u5148\
      \ (\u524D\u51E6\u7406 $O(N)$ + $O(1)$, $\\pm 1$ RMQ and sparse table)"
    links:
    - http://www.utpc.jp/2011/problems/travel.html
    - https://www.slideshare.net/yumainoue965/lca-and-rmq
  bundledCode: "#line 2 \"graph/lowest_common_ancestor.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <utility>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 5 \"data_structure/sparse_table.hpp\"\n\n/**\n * @brief Sparse\
    \ Table (idempotent monoid)\n * @note the unit is required just for convenience\n\
    \ * @note $O(N \\log N)$ space\n */\ntemplate <class IdempotentMonoid>\nstruct\
    \ sparse_table {\n    typedef typename IdempotentMonoid::value_type value_type;\n\
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
    \        return get_depth(x) + get_depth(y) - 2 * get_depth(z);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <utility>\n#include <vector>\n#include \"../data_structure/sparse_table.hpp\"\
    \n#include \"../monoids/min_index.hpp\"\n\n/**\n * @brief lowest common ancestor\
    \ / \u6700\u5C0F\u5171\u901A\u7956\u5148 (\u524D\u51E6\u7406 $O(N)$ + $O(1)$,\
    \ $\\pm 1$ RMQ and sparse table)\n * @see https://www.slideshare.net/yumainoue965/lca-and-rmq\n\
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
    \        return get_depth(x) + get_depth(y) - 2 * get_depth(z);\n    }\n};\n"
  dependsOn:
  - data_structure/sparse_table.hpp
  - utils/macros.hpp
  - monoids/min_index.hpp
  isVerificationFile: false
  path: graph/lowest_common_ancestor.hpp
  requiredBy:
  - graph/virtual_trees.hpp
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/lowest_common_ancestor.yosupo.test.cpp
  - graph/lowest_common_ancestor.aoj.test.cpp
documentation_of: graph/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/graph/lowest_common_ancestor.hpp
- /library/graph/lowest_common_ancestor.hpp.html
title: "lowest common ancestor / \u6700\u5C0F\u5171\u901A\u7956\u5148 (\u524D\u51E6\
  \u7406 $O(N)$ + $O(1)$, $\\pm 1$ RMQ and sparse table)"
---
