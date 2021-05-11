---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: monoids/linear_function_plus_count_action.hpp
    title: monoids/linear_function_plus_count_action.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.point_set_range_composite.test.cpp
    title: data_structure/segment_tree.point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sliding_window_aggregation.yosupo.test.cpp
    title: data_structure/sliding_window_aggregation.yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoids/linear_function.hpp\"\n#include <utility>\n\ntemplate\
    \ <class CommutativeRing>\nstruct linear_function_monoid {\n    typedef std::pair<CommutativeRing,\
    \ CommutativeRing> value_type;\n    linear_function_monoid() = default;\n    value_type\
    \ unit() const {\n        return std::make_pair(1, 0);\n    }\n    value_type\
    \ mult(value_type g, value_type f) const {\n        CommutativeRing fst = g.first\
    \ * f.first;\n        CommutativeRing snd = g.second + g.first * f.second;\n \
    \       return std::make_pair(fst, snd);\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n\ntemplate <class CommutativeRing>\nstruct\
    \ linear_function_monoid {\n    typedef std::pair<CommutativeRing, CommutativeRing>\
    \ value_type;\n    linear_function_monoid() = default;\n    value_type unit()\
    \ const {\n        return std::make_pair(1, 0);\n    }\n    value_type mult(value_type\
    \ g, value_type f) const {\n        CommutativeRing fst = g.first * f.first;\n\
    \        CommutativeRing snd = g.second + g.first * f.second;\n        return\
    \ std::make_pair(fst, snd);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/linear_function.hpp
  requiredBy:
  - monoids/linear_function_plus_count_action.hpp
  timestamp: '2019-12-27 19:16:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  - data_structure/sliding_window_aggregation.yosupo.test.cpp
  - data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
  - data_structure/segment_tree.point_set_range_composite.test.cpp
documentation_of: monoids/linear_function.hpp
layout: document
redirect_from:
- /library/monoids/linear_function.hpp
- /library/monoids/linear_function.hpp.html
title: monoids/linear_function.hpp
---
