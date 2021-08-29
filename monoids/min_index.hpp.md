---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "lowest common ancestor / \u6700\u5C0F\u5171\u901A\u7956\u5148 (\u524D\u51E6\
      \u7406 $O(N)$ + $O(1)$, $\\pm 1$ RMQ and sparse table)"
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
    links: []
  bundledCode: "#line 2 \"monoids/min_index.hpp\"\n#include <algorithm>\n#include\
    \ <climits>\n#include <limits>\n#include <utility>\n\n/**\n * @note a semilattice\n\
    \ */\ntemplate <class T>\nstruct min_index_monoid {\n    typedef std::pair<T,\
    \ int> value_type;\n    value_type unit() const { return std::make_pair(std::numeric_limits<T>::max(),\
    \ INT_MAX); }\n    value_type mult(value_type a, value_type b) const { return\
    \ std::min(a, b); }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <climits>\n#include <limits>\n\
    #include <utility>\n\n/**\n * @note a semilattice\n */\ntemplate <class T>\nstruct\
    \ min_index_monoid {\n    typedef std::pair<T, int> value_type;\n    value_type\
    \ unit() const { return std::make_pair(std::numeric_limits<T>::max(), INT_MAX);\
    \ }\n    value_type mult(value_type a, value_type b) const { return std::min(a,\
    \ b); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/min_index.hpp
  requiredBy:
  - graph/lowest_common_ancestor.hpp
  - graph/virtual_trees.hpp
  timestamp: '2019-12-30 22:14:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/lowest_common_ancestor.yosupo.test.cpp
  - graph/lowest_common_ancestor.aoj.test.cpp
documentation_of: monoids/min_index.hpp
layout: document
redirect_from:
- /library/monoids/min_index.hpp
- /library/monoids/min_index.hpp.html
title: monoids/min_index.hpp
---
