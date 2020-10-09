---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: monoids/linear_function.hpp
    title: monoids/linear_function.hpp
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
    links: []
  bundledCode: "#line 2 \"monoids/linear_function_plus_count_action.hpp\"\n#include\
    \ <utility>\n#line 3 \"monoids/linear_function.hpp\"\n\ntemplate <class CommutativeRing>\n\
    struct linear_function_monoid {\n    typedef std::pair<CommutativeRing, CommutativeRing>\
    \ value_type;\n    linear_function_monoid() = default;\n    value_type unit()\
    \ const {\n        return std::make_pair(1, 0);\n    }\n    value_type mult(value_type\
    \ g, value_type f) const {\n        CommutativeRing fst = g.first * f.first;\n\
    \        CommutativeRing snd = g.second + g.first * f.second;\n        return\
    \ std::make_pair(fst, snd);\n    }\n};\n#line 4 \"monoids/linear_function_plus_count_action.hpp\"\
    \n\n/**\n * @note lazy_propagation_segment_tree<plus_count_monoid<T>, linear_function_monoid<T>,\
    \ linear_function_plus_count_action<T> >\n */\ntemplate <class T>\nstruct linear_function_plus_count_action\
    \ {\n    typename plus_count_monoid<T>::value_type operator () (typename linear_function_monoid<T>::value_type\
    \ f, typename plus_count_monoid<T>::value_type x) const {\n        return std::make_pair(f.first\
    \ * x.first + f.second * x.second, x.second);\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n#include \"monoids/linear_function.hpp\"\
    \n\n/**\n * @note lazy_propagation_segment_tree<plus_count_monoid<T>, linear_function_monoid<T>,\
    \ linear_function_plus_count_action<T> >\n */\ntemplate <class T>\nstruct linear_function_plus_count_action\
    \ {\n    typename plus_count_monoid<T>::value_type operator () (typename linear_function_monoid<T>::value_type\
    \ f, typename plus_count_monoid<T>::value_type x) const {\n        return std::make_pair(f.first\
    \ * x.first + f.second * x.second, x.second);\n    }\n};\n"
  dependsOn:
  - monoids/linear_function.hpp
  isVerificationFile: false
  path: monoids/linear_function_plus_count_action.hpp
  requiredBy: []
  timestamp: '2019-12-27 19:16:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  - data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
documentation_of: monoids/linear_function_plus_count_action.hpp
layout: document
redirect_from:
- /library/monoids/linear_function_plus_count_action.hpp
- /library/monoids/linear_function_plus_count_action.hpp.html
title: monoids/linear_function_plus_count_action.hpp
---
