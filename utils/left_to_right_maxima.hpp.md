---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table (idempotent monoid)
  - icon: ':heavy_check_mark:'
    path: monoids/min.hpp
    title: monoids/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/cartesian_tree.yukicoder-1031.test.cpp
    title: graph/cartesian_tree.yukicoder-1031.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "Length of Left-to-right Maxima (\u524D\u51E6\u7406 $O(n \\log\
      \ n)$ + $O(1)$)"
    links: []
  bundledCode: "#line 2 \"utils/left_to_right_maxima.hpp\"\n#include <stack>\n#include\
    \ <tuple>\n#include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 2 \"data_structure/sparse_table.hpp\"\n#include <cassert>\n#line 5 \"data_structure/sparse_table.hpp\"\
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
    \    }\n};\n"
  code: "#pragma once\n#include <stack>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n#include \"utils/macros.hpp\"\n#include \"data_structure/sparse_table.hpp\"\
    \n#include \"monoids/min.hpp\"\n\n/**\n * @brief Length of Left-to-right Maxima\
    \ (\u524D\u51E6\u7406 $O(n \\log n)$ + $O(1)$)\n * @description computes the lengths\
    \ of the left-to-right maxima for the given interval\n * @note the left-to-right\
    \ maxima for a sequence $a$ means the subsubsequence of the elements $a_i$ which\
    \ satisfy $\\forall j \\lt i. a_j \\lt a_i$.\n */\nclass left_to_right_maxima\
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
    \    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  - data_structure/sparse_table.hpp
  - monoids/min.hpp
  isVerificationFile: false
  path: utils/left_to_right_maxima.hpp
  requiredBy: []
  timestamp: '2020-07-21 05:31:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/cartesian_tree.yukicoder-1031.test.cpp
documentation_of: utils/left_to_right_maxima.hpp
layout: document
redirect_from:
- /library/utils/left_to_right_maxima.hpp
- /library/utils/left_to_right_maxima.hpp.html
title: "Length of Left-to-right Maxima (\u524D\u51E6\u7406 $O(n \\log n)$ + $O(1)$)"
---
