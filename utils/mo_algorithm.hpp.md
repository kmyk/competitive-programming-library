---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: utils/mo_algorithm.yuki1270.test.cpp
    title: utils/mo_algorithm.yuki1270.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/mo_algorithm.hpp\"\n#include <algorithm>\n#include\
    \ <cmath>\n#include <numeric>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n// struct mo_struct {\n//     typedef int64_t value_type;\n//  \
    \   typedef int64_t result_type;\n//     void add_right(int nr, value_type x_r)\
    \ {\n//     }\n//     void add_left(int nl, value_type x_nl) {\n//     }\n// \
    \    void remove_right(int nr, value_type x_nr) {\n//     }\n//     void remove_left(int\
    \ nl, value_type x_l) {\n//     }\n//     result_type query() {\n//         return\
    \ 0;\n//     }\n// };\n\ntemplate <class Mo>\nstd::vector<typename Mo::result_type>\
    \ run_mo_algorithm(Mo mo, const std::vector<typename Mo::value_type>& values,\
    \ const std::vector<std::pair<int, int> >& queries) {\n    int n = values.size();\n\
    \    int m = queries.size();\n\n    // sort queries\n    int sq_n = std::sqrt(n);\n\
    \    std::vector<int> order(m);\n    std::iota(ALL(order), 0);\n    std::sort(ALL(order),\
    \ [&](int i, int j) {\n        int l_i, r_i; std::tie(l_i, r_i) = queries[i];\n\
    \        int l_j, r_j; std::tie(l_j, r_j) = queries[j];\n        return std::make_pair(l_i\
    \ / sq_n, r_i) < std::make_pair(l_j / sq_n, r_j);\n    });\n\n    // compute queries\n\
    \    std::vector<typename Mo::result_type> ans(m);\n    int l = 0;\n    int r\
    \ = 0;\n    for (int j : order) {\n        int nl, nr; std::tie(nl, nr) = queries[j];\n\
    \        for (; r < nr; ++ r) mo.add_right(r + 1, values[r]);\n        for (;\
    \ nl < l; -- l) mo.add_left(l - 1, values[l - 1]);\n        for (; nr < r; --\
    \ r) mo.remove_right(r - 1, values[r - 1]);\n        for (; l < nl; ++ l) mo.remove_left(l\
    \ + 1, values[l]);\n        ans[j] = mo.query();\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n#include <numeric>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n// struct mo_struct\
    \ {\n//     typedef int64_t value_type;\n//     typedef int64_t result_type;\n\
    //     void add_right(int nr, value_type x_r) {\n//     }\n//     void add_left(int\
    \ nl, value_type x_nl) {\n//     }\n//     void remove_right(int nr, value_type\
    \ x_nr) {\n//     }\n//     void remove_left(int nl, value_type x_l) {\n//   \
    \  }\n//     result_type query() {\n//         return 0;\n//     }\n// };\n\n\
    template <class Mo>\nstd::vector<typename Mo::result_type> run_mo_algorithm(Mo\
    \ mo, const std::vector<typename Mo::value_type>& values, const std::vector<std::pair<int,\
    \ int> >& queries) {\n    int n = values.size();\n    int m = queries.size();\n\
    \n    // sort queries\n    int sq_n = std::sqrt(n);\n    std::vector<int> order(m);\n\
    \    std::iota(ALL(order), 0);\n    std::sort(ALL(order), [&](int i, int j) {\n\
    \        int l_i, r_i; std::tie(l_i, r_i) = queries[i];\n        int l_j, r_j;\
    \ std::tie(l_j, r_j) = queries[j];\n        return std::make_pair(l_i / sq_n,\
    \ r_i) < std::make_pair(l_j / sq_n, r_j);\n    });\n\n    // compute queries\n\
    \    std::vector<typename Mo::result_type> ans(m);\n    int l = 0;\n    int r\
    \ = 0;\n    for (int j : order) {\n        int nl, nr; std::tie(nl, nr) = queries[j];\n\
    \        for (; r < nr; ++ r) mo.add_right(r + 1, values[r]);\n        for (;\
    \ nl < l; -- l) mo.add_left(l - 1, values[l - 1]);\n        for (; nr < r; --\
    \ r) mo.remove_right(r - 1, values[r - 1]);\n        for (; l < nl; ++ l) mo.remove_left(l\
    \ + 1, values[l]);\n        ans[j] = mo.query();\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/mo_algorithm.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:22:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - utils/mo_algorithm.yuki1270.test.cpp
documentation_of: utils/mo_algorithm.hpp
layout: document
redirect_from:
- /library/utils/mo_algorithm.hpp
- /library/utils/mo_algorithm.hpp.html
title: utils/mo_algorithm.hpp
---
