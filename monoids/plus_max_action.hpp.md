---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: monoids/max.hpp
    title: monoids/max.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoids/plus.hpp\"\n\ntemplate <class T>\nstruct plus_monoid\
    \ {\n    typedef T value_type;\n    value_type unit() const { return value_type();\
    \ }\n    value_type mult(value_type a, value_type b) const { return a + b; }\n\
    };\n#line 2 \"monoids/max.hpp\"\n#include <algorithm>\n#include <limits>\n\ntemplate\
    \ <class T>\nstruct max_monoid {\n    typedef T value_type;\n    value_type unit()\
    \ const { return std::numeric_limits<T>::lowest(); }\n    value_type mult(value_type\
    \ a, value_type b) const { return std::max(a, b); }\n};\n#line 4 \"monoids/plus_max_action.hpp\"\
    \n\n/**\n * @note lazy_propagation_segment_tree<max_monoid<T>, plus_monoid<T>,\
    \ plus_max_action<T> > is a starry sky tree\n */\ntemplate <class T>\nstruct plus_max_action\
    \ {\n    typename max_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type\
    \ f, typename max_monoid<T>::value_type x) const {\n        return (x == max_monoid<T>().unit()\
    \ ? x : f + x);\n    }\n};\n"
  code: "#pragma once\n#include \"monoids/plus.hpp\"\n#include \"monoids/max.hpp\"\
    \n\n/**\n * @note lazy_propagation_segment_tree<max_monoid<T>, plus_monoid<T>,\
    \ plus_max_action<T> > is a starry sky tree\n */\ntemplate <class T>\nstruct plus_max_action\
    \ {\n    typename max_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type\
    \ f, typename max_monoid<T>::value_type x) const {\n        return (x == max_monoid<T>().unit()\
    \ ? x : f + x);\n    }\n};\n"
  dependsOn:
  - monoids/plus.hpp
  - monoids/max.hpp
  isVerificationFile: false
  path: monoids/plus_max_action.hpp
  requiredBy: []
  timestamp: '2019-12-27 19:16:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoids/plus_max_action.hpp
layout: document
redirect_from:
- /library/monoids/plus_max_action.hpp
- /library/monoids/plus_max_action.hpp.html
title: monoids/plus_max_action.hpp
---
