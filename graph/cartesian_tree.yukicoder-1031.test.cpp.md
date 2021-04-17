---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table (idempotent monoid)
  - icon: ':heavy_check_mark:'
    path: graph/cartesian_tree.hpp
    title: Cartesian tree ($O(n)$)
  - icon: ':heavy_check_mark:'
    path: graph/format.hpp
    title: graph/format.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/min.hpp
    title: monoids/min.hpp
  - icon: ':heavy_check_mark:'
    path: utils/left_to_right_maxima.hpp
    title: "Length of Left-to-right Maxima (\u524D\u51E6\u7406 $O(n \\log n)$ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1031
    links:
    - https://yukicoder.me/problems/no/1031
  bundledCode: "#line 1 \"graph/cartesian_tree.yukicoder-1031.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1031\"\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 2 \"graph/cartesian_tree.hpp\"\n#include <functional>\n#include <vector>\n#line\
    \ 5 \"graph/cartesian_tree.hpp\"\n\n/**\n * @brief Cartesian tree ($O(n)$)\n *\
    \ @note the smallest value is the root\n * @note if a is not distinct, the way\
    \ for tie-break is undefined\n * @return the binary tree as the list of parents\n\
    \ */\ntemplate <class T, class Comparator = std::less<int> >\nstd::vector<int>\
    \ construct_cartesian_tree(const std::vector<T> & a, const Comparator & cmp =\
    \ Comparator()) {\n    int n = a.size();\n    std::vector<int> parent(n, -1);\n\
    \    REP3 (i, 1, n) {\n        int p = i - 1;  // parent of i\n        int l =\
    \ -1;  // left child of i\n        while (p != -1 and cmp(a[i], a[p])) {\n   \
    \         int pp = parent[p];  // parent of parent of i\n            if (l !=\
    \ -1) {\n                parent[l] = p;\n            }\n            parent[p]\
    \ = i;\n            l = p;\n            p = pp;\n        }\n        parent[i]\
    \ = p;\n    }\n    return parent;\n}\n#line 2 \"graph/format.hpp\"\n#include <cassert>\n\
    #include <utility>\n#line 6 \"graph/format.hpp\"\n\nstd::pair<std::vector<std::vector<int>\
    \ >, int> children_from_parent(const std::vector<int> & parent) {\n    int n =\
    \ parent.size();\n    std::vector<std::vector<int> > children(n);\n    int root\
    \ = -1;\n    REP (x, n) {\n        if (parent[x] == -1) {\n            assert\
    \ (root == -1);\n            root = x;\n        } else {\n            children[parent[x]].push_back(x);\n\
    \        }\n    }\n    assert (root != -1);\n    return std::make_pair(children,\
    \ root);\n}\n\nstd::vector<std::vector<int> > adjacent_list_from_children(const\
    \ std::vector<std::vector<int> > & children) {\n    int n = children.size();\n\
    \    std::vector<std::vector<int> > g(n);\n    REP (x, n) {\n        for (int\
    \ y : children[x]) {\n            g[x].push_back(y);\n            g[y].push_back(x);\n\
    \        }\n    }\n    return g;\n}\n#line 2 \"utils/left_to_right_maxima.hpp\"\
    \n#include <stack>\n#include <tuple>\n#line 5 \"data_structure/sparse_table.hpp\"\
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
    \ - (1ll << k)]);\n    }\n};\n#line 2 \"monoids/min.hpp\"\n#include <algorithm>\n\
    #include <limits>\n\ntemplate <class T>\nstruct min_monoid {\n    typedef T value_type;\n\
    \    value_type unit() const { return std::numeric_limits<T>::max(); }\n    value_type\
    \ mult(value_type a, value_type b) const { return std::min(a, b); }\n};\n#line\
    \ 9 \"utils/left_to_right_maxima.hpp\"\n\n/**\n * @brief Length of Left-to-right\
    \ Maxima (\u524D\u51E6\u7406 $O(n \\log n)$ + $O(1)$)\n * @description computes\
    \ the lengths of the left-to-right maxima for the given interval\n * @note the\
    \ left-to-right maxima for a sequence $a$ means the subsubsequence of the elements\
    \ $a_i$ which satisfy $\\forall j \\lt i. a_j \\lt a_i$.\n */\nclass left_to_right_maxima\
    \ {\n    std::vector<int> depth;\n    sparse_table<min_monoid<int> > table;\n\n\
    public:\n    left_to_right_maxima() = default;\n\n    int operator () (int l,\
    \ int r) const {\n        assert (0 <= l and l <= r and r <= (int)depth.size());\n\
    \        if (l == r) return 0;\n        return depth[l] - table.range_get(l, r)\
    \ + 1;\n    }\n\nprivate:\n    left_to_right_maxima(const std::vector<int> & depth_)\n\
    \            : depth(depth_), table(ALL(depth_)) {\n    }\n\npublic:\n    /**\n\
    \     * @note this is just a constructor, but is needed to specify template arguments.\n\
    \     */\n    template <class T, class Comparator = std::less<T>, class RandomAccessIterator>\n\
    \    static left_to_right_maxima construct(RandomAccessIterator first, RandomAccessIterator\
    \ last, const Comparator & cmp = Comparator()) {\n        int n = std::distance(first,\
    \ last);\n\n        // make a forest\n        std::vector<int> parent(n, -1);\n\
    \        std::stack<int> stk;\n        REP (i, n) {\n            while (not stk.empty()\
    \ and cmp(*(first + stk.top()), *(first + i))) {\n                parent[stk.top()]\
    \ = i;\n                stk.pop();\n            }\n            stk.push(i);\n\
    \        }\n\n        // calculate depths\n        std::vector<int> depth(n);\n\
    \        REP_R (i, n) {\n            if (parent[i] != -1) {\n                depth[i]\
    \ = depth[parent[i]] + 1;\n            }\n        }\n\n        return left_to_right_maxima(depth);\n\
    \    }\n};\n#line 6 \"graph/cartesian_tree.yukicoder-1031.test.cpp\"\n#include\
    \ <cstdio>\n#line 10 \"graph/cartesian_tree.yukicoder-1031.test.cpp\"\n\n#include\
    \ <iostream>\nusing namespace std;\n\nint64_t solve1(int n, const vector<int>\
    \ & p) {\n    // prepare a data structure for the sequence\n    auto f = left_to_right_maxima::construct<int>(ALL(p));\n\
    \n    // construct the Cartesian tree\n    vector<int> parent = construct_cartesian_tree(p);\n\
    \    vector<vector<int> > children; int root; tie(children, root) = children_from_parent(parent);\n\
    \n    // fold the Cartesian tree\n    int64_t ans = 0;\n    auto go = [&](auto\
    \ && go, int l, int m, int r) -> void {\n        if (l == r) {\n            return;\n\
    \        }\n        ans += f(m + 1, r);\n        for (int x : children[m]) {\n\
    \            if (x < m) {\n                go(go, l, x, m);\n            } else\
    \ {\n                go(go, m + 1, x, r);\n            }\n        }\n    };\n\
    \    go(go, 0, root, n);\n    return ans;\n}\n\nint64_t solve(int n, vector<int>\
    \ p) {\n    int64_t ans = solve1(n, p);\n    reverse(ALL(p));\n    return ans\
    \ + solve1(n, p);\n}\n\nint main() {\n    int n; scanf(\"%d\", &n);\n    vector<int>\
    \ p(n);\n    REP (i, n) {\n        scanf(\"%d\", &p[i]);\n    }\n    long long\
    \ ans = solve(n, p);\n    printf(\"%lld\\n\", ans);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1031\"\n#include \"utils/macros.hpp\"\
    \n#include \"graph/cartesian_tree.hpp\"\n#include \"graph/format.hpp\"\n#include\
    \ \"utils/left_to_right_maxima.hpp\"\n#include <cstdio>\n#include <functional>\n\
    #include <utility>\n#include <vector>\n\n#include <iostream>\nusing namespace\
    \ std;\n\nint64_t solve1(int n, const vector<int> & p) {\n    // prepare a data\
    \ structure for the sequence\n    auto f = left_to_right_maxima::construct<int>(ALL(p));\n\
    \n    // construct the Cartesian tree\n    vector<int> parent = construct_cartesian_tree(p);\n\
    \    vector<vector<int> > children; int root; tie(children, root) = children_from_parent(parent);\n\
    \n    // fold the Cartesian tree\n    int64_t ans = 0;\n    auto go = [&](auto\
    \ && go, int l, int m, int r) -> void {\n        if (l == r) {\n            return;\n\
    \        }\n        ans += f(m + 1, r);\n        for (int x : children[m]) {\n\
    \            if (x < m) {\n                go(go, l, x, m);\n            } else\
    \ {\n                go(go, m + 1, x, r);\n            }\n        }\n    };\n\
    \    go(go, 0, root, n);\n    return ans;\n}\n\nint64_t solve(int n, vector<int>\
    \ p) {\n    int64_t ans = solve1(n, p);\n    reverse(ALL(p));\n    return ans\
    \ + solve1(n, p);\n}\n\nint main() {\n    int n; scanf(\"%d\", &n);\n    vector<int>\
    \ p(n);\n    REP (i, n) {\n        scanf(\"%d\", &p[i]);\n    }\n    long long\
    \ ans = solve(n, p);\n    printf(\"%lld\\n\", ans);\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - graph/cartesian_tree.hpp
  - graph/format.hpp
  - utils/left_to_right_maxima.hpp
  - data_structure/sparse_table.hpp
  - monoids/min.hpp
  isVerificationFile: true
  path: graph/cartesian_tree.yukicoder-1031.test.cpp
  requiredBy: []
  timestamp: '2020-07-21 05:31:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/cartesian_tree.yukicoder-1031.test.cpp
layout: document
redirect_from:
- /verify/graph/cartesian_tree.yukicoder-1031.test.cpp
- /verify/graph/cartesian_tree.yukicoder-1031.test.cpp.html
title: graph/cartesian_tree.yukicoder-1031.test.cpp
---
