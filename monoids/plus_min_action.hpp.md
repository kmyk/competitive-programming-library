---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: monoids/min.hpp
    title: monoids/min.hpp
  - icon: ':question:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
    title: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
  - icon: ':x:'
    path: utils/mo_algorithm.yuki1270.test.cpp
    title: utils/mo_algorithm.yuki1270.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoids/plus.hpp\"\n\ntemplate <class T>\nstruct plus_monoid\
    \ {\n    typedef T value_type;\n    value_type unit() const { return value_type();\
    \ }\n    value_type mult(value_type a, value_type b) const { return a + b; }\n\
    };\n#line 2 \"monoids/min.hpp\"\n#include <algorithm>\n#include <limits>\n\ntemplate\
    \ <class T>\nstruct min_monoid {\n    typedef T value_type;\n    value_type unit()\
    \ const { return std::numeric_limits<T>::max(); }\n    value_type mult(value_type\
    \ a, value_type b) const { return std::min(a, b); }\n};\n#line 4 \"monoids/plus_min_action.hpp\"\
    \n\ntemplate <class T>\nstruct plus_min_action {\n    typename min_monoid<T>::value_type\
    \ operator () (typename plus_monoid<T>::value_type f, typename min_monoid<T>::value_type\
    \ x) const {\n        return (x == min_monoid<T>().unit() ? x : f + x);\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../monoids/plus.hpp\"\n#include \"../monoids/min.hpp\"\
    \n\ntemplate <class T>\nstruct plus_min_action {\n    typename min_monoid<T>::value_type\
    \ operator () (typename plus_monoid<T>::value_type f, typename min_monoid<T>::value_type\
    \ x) const {\n        return (x == min_monoid<T>().unit() ? x : f + x);\n    }\n\
    };\n"
  dependsOn:
  - monoids/plus.hpp
  - monoids/min.hpp
  isVerificationFile: false
  path: monoids/plus_min_action.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
  - utils/mo_algorithm.yuki1270.test.cpp
documentation_of: monoids/plus_min_action.hpp
layout: document
redirect_from:
- /library/monoids/plus_min_action.hpp
- /library/monoids/plus_min_action.hpp.html
title: monoids/plus_min_action.hpp
---
