---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: monoids/plus_max_action.hpp
    title: monoids/plus_max_action.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus_min_action.hpp
    title: monoids/plus_min_action.hpp
  - icon: ':warning:'
    path: monoids/plus_min_count_action.hpp
    title: monoids/plus_min_count_action.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.test.cpp
    title: data_structure/binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
    title: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
    title: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
    title: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.point_add_range_sum.test.cpp
    title: data_structure/segment_tree.point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.range_sum_query.test.cpp
    title: data_structure/segment_tree.range_sum_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: utils/dsu_on_tree.aoj.test.cpp
    title: utils/dsu_on_tree.aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: utils/mo_algorithm.yuki1270.test.cpp
    title: utils/mo_algorithm.yuki1270.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoids/plus.hpp\"\n\ntemplate <class T>\nstruct plus_monoid\
    \ {\n    typedef T value_type;\n    value_type unit() const { return value_type();\
    \ }\n    value_type mult(value_type a, value_type b) const { return a + b; }\n\
    };\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct plus_monoid {\n    typedef T value_type;\n\
    \    value_type unit() const { return value_type(); }\n    value_type mult(value_type\
    \ a, value_type b) const { return a + b; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/plus.hpp
  requiredBy:
  - monoids/plus_min_action.hpp
  - monoids/plus_max_action.hpp
  - monoids/plus_min_count_action.hpp
  timestamp: '2019-12-27 19:16:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - utils/dsu_on_tree.aoj.test.cpp
  - utils/mo_algorithm.yuki1270.test.cpp
  - data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
  - data_structure/segment_tree.point_add_range_sum.test.cpp
  - data_structure/segment_tree.range_sum_query.test.cpp
  - data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  - data_structure/binary_indexed_tree.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
  - data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
documentation_of: monoids/plus.hpp
layout: document
redirect_from:
- /library/monoids/plus.hpp
- /library/monoids/plus.hpp.html
title: monoids/plus.hpp
---
