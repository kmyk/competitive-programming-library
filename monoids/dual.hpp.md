---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"monoids/dual.hpp\"\n\n/**\n * @see http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual\n\
    \ */\ntemplate <class Monoid>\nstruct dual_monoid {\n    typedef typename Monoid::value_type\
    \ value_type;\n    Monoid base;\n    value_type unit() const { return base.unit();\
    \ }\n    value_type mult(const value_type & a, const value_type & b) const { return\
    \ base.mult(b, a); }\n};\n"
  code: "#pragma once\n\n/**\n * @see http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual\n\
    \ */\ntemplate <class Monoid>\nstruct dual_monoid {\n    typedef typename Monoid::value_type\
    \ value_type;\n    Monoid base;\n    value_type unit() const { return base.unit();\
    \ }\n    value_type mult(const value_type & a, const value_type & b) const { return\
    \ base.mult(b, a); }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sliding_window_aggregation.yosupo.test.cpp
    title: data_structure/sliding_window_aggregation.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.point_set_range_composite.test.cpp
    title: data_structure/segment_tree.point_set_range_composite.test.cpp
  isVerificationFile: false
  path: monoids/dual.hpp
  requiredBy: []
  timestamp: '2019-12-19 00:15:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - data_structure/sliding_window_aggregation.yosupo.test.cpp
  - data_structure/segment_tree.point_set_range_composite.test.cpp
documentation_of: monoids/dual.hpp
layout: document
redirect_from:
- /library/monoids/dual.hpp
- /library/monoids/dual.hpp.html
title: monoids/dual.hpp
---
