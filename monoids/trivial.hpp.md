---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: monoids/trivial_action.hpp
    title: monoids/trivial_action.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.marked_ancestor.test.cpp
    title: data_structure/link_cut_tree.marked_ancestor.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoids/trivial.hpp\"\n\nstruct trivial_monoid {\n    typedef\
    \ struct {} value_type;\n    value_type unit() const { return (value_type) {};\
    \ }\n    value_type mult(value_type a, value_type b) const { return (value_type)\
    \ {}; }\n};\n"
  code: "#pragma once\n\nstruct trivial_monoid {\n    typedef struct {} value_type;\n\
    \    value_type unit() const { return (value_type) {}; }\n    value_type mult(value_type\
    \ a, value_type b) const { return (value_type) {}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/trivial.hpp
  requiredBy:
  - monoids/trivial_action.hpp
  timestamp: '2020-01-27 07:18:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/link_cut_tree.marked_ancestor.test.cpp
documentation_of: monoids/trivial.hpp
layout: document
redirect_from:
- /library/monoids/trivial.hpp
- /library/monoids/trivial.hpp.html
title: monoids/trivial.hpp
---
