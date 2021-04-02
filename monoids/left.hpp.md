---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: monoids/left_action.hpp
    title: monoids/left_action.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/dual_segment_tree.range_update_query.test.cpp
    title: data_structure/dual_segment_tree.range_update_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoids/left.hpp\"\n#include <utility>\n\ntemplate <class\
    \ T>\nstruct left_monoid {\n    // typedef std::optional<T> value_type;\n    typedef\
    \ std::pair<bool, T> value_type;\n    value_type unit() const { return std::make_pair(false,\
    \ T()); }\n    value_type mult(value_type a, value_type b) const { return a.first\
    \ ? a : b; }\n};\n"
  code: "#pragma once\n#include <utility>\n\ntemplate <class T>\nstruct left_monoid\
    \ {\n    // typedef std::optional<T> value_type;\n    typedef std::pair<bool,\
    \ T> value_type;\n    value_type unit() const { return std::make_pair(false, T());\
    \ }\n    value_type mult(value_type a, value_type b) const { return a.first ?\
    \ a : b; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/left.hpp
  requiredBy:
  - monoids/left_action.hpp
  timestamp: '2019-12-27 19:16:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/dual_segment_tree.range_update_query.test.cpp
documentation_of: monoids/left.hpp
layout: document
redirect_from:
- /library/monoids/left.hpp
- /library/monoids/left.hpp.html
title: monoids/left.hpp
---
