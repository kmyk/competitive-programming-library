---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"monoids/reversible.hpp\"\n#include <utility>\n\ntemplate\
    \ <class Monoid>\nstruct reversible_monoid {\n    typedef typename Monoid::value_type\
    \ base_type;\n    typedef std::pair<base_type, base_type> value_type;\n    Monoid\
    \ base;\n    reversible_monoid() = default;\n    reversible_monoid(const Monoid\
    \ & base_) : base(base_) {}\n    value_type unit() const { return std::make_pair(base.unit(),\
    \ base.unit()); }\n    value_type mult(const value_type & a, const value_type\
    \ & b) const { return std::make_pair(base.mult(a.first, b.first), base.mult(b.second,\
    \ a.second)); }\n    static value_type make(const base_type & x) { return std::make_pair(x,\
    \ x); }\n    static value_type reverse(const value_type & a) { return std::make_pair(a.second,\
    \ a.first); }\n    static base_type get(const value_type & a) { return a.first;\
    \ }\n};\n"
  code: "#pragma once\n#include <utility>\n\ntemplate <class Monoid>\nstruct reversible_monoid\
    \ {\n    typedef typename Monoid::value_type base_type;\n    typedef std::pair<base_type,\
    \ base_type> value_type;\n    Monoid base;\n    reversible_monoid() = default;\n\
    \    reversible_monoid(const Monoid & base_) : base(base_) {}\n    value_type\
    \ unit() const { return std::make_pair(base.unit(), base.unit()); }\n    value_type\
    \ mult(const value_type & a, const value_type & b) const { return std::make_pair(base.mult(a.first,\
    \ b.first), base.mult(b.second, a.second)); }\n    static value_type make(const\
    \ base_type & x) { return std::make_pair(x, x); }\n    static value_type reverse(const\
    \ value_type & a) { return std::make_pair(a.second, a.first); }\n    static base_type\
    \ get(const value_type & a) { return a.first; }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.hpp
    title: Link-Cut tree (monoids without commutativity, vertex set + path get)
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.marked_ancestor.test.cpp
    title: data_structure/link_cut_tree.marked_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
  isVerificationFile: false
  path: monoids/reversible.hpp
  requiredBy:
  - data_structure/link_cut_tree.hpp
  timestamp: '2020-02-26 18:09:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - data_structure/link_cut_tree.marked_ancestor.test.cpp
  - data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
documentation_of: monoids/reversible.hpp
layout: document
redirect_from:
- /library/monoids/reversible.hpp
- /library/monoids/reversible.hpp.html
title: monoids/reversible.hpp
---
