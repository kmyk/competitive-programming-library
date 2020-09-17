---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoids/plus_count.hpp\"\n#include <utility>\n\ntemplate\
    \ <class T>\nstruct plus_count_monoid {\n    typedef std::pair<T, int> value_type;\n\
    \    value_type unit() const {\n        return std::make_pair(T(), 0);\n    }\n\
    \    value_type mult(value_type a, value_type b) const {\n        return std::make_pair(a.first\
    \ + b.first, a.second + b.second);\n    }\n    static value_type make(T a) {\n\
    \        return std::make_pair(a, 1);\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n\ntemplate <class T>\nstruct plus_count_monoid\
    \ {\n    typedef std::pair<T, int> value_type;\n    value_type unit() const {\n\
    \        return std::make_pair(T(), 0);\n    }\n    value_type mult(value_type\
    \ a, value_type b) const {\n        return std::make_pair(a.first + b.first, a.second\
    \ + b.second);\n    }\n    static value_type make(T a) {\n        return std::make_pair(a,\
    \ 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/plus_count.hpp
  requiredBy: []
  timestamp: '2019-12-27 19:16:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
  - data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
documentation_of: monoids/plus_count.hpp
layout: document
redirect_from:
- /library/monoids/plus_count.hpp
- /library/monoids/plus_count.hpp.html
title: monoids/plus_count.hpp
---
