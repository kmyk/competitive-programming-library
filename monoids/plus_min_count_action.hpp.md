---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: monoids/min_count.hpp
    title: monoids/min_count.hpp
  - icon: ':question:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoids/plus_min_count_action.hpp\"\n#include <utility>\n\
    #line 2 \"monoids/plus.hpp\"\n\ntemplate <class T>\nstruct plus_monoid {\n   \
    \ typedef T value_type;\n    value_type unit() const { return value_type(); }\n\
    \    value_type mult(value_type a, value_type b) const { return a + b; }\n};\n\
    #line 2 \"monoids/min_count.hpp\"\n#include <limits>\n#line 4 \"monoids/min_count.hpp\"\
    \n\ntemplate <class T>\nstruct min_count_monoid {\n    typedef std::pair<T, int>\
    \ value_type;\n    value_type unit() const {\n        return std::make_pair(std::numeric_limits<T>::max(),\
    \ 0);\n    }\n    value_type mult(value_type a, value_type b) const {\n      \
    \  if (a.first < b.first) return a;\n        if (a.first > b.first) return b;\n\
    \        return std::make_pair(a.first, a.second + b.second);\n    }\n    static\
    \ value_type make(T a) {\n        return std::make_pair(a, 1);\n    }\n};\n#line\
    \ 5 \"monoids/plus_min_count_action.hpp\"\n\n/**\n * @note lazy_propagation_segment_tree<min_count_monoid<T>,\
    \ plus_monoid<T>, plus_min_count_action<T> > can count a number of zeros (or,\
    \ non-zero numbers) in the array\n */\ntemplate <class T>\nstruct plus_min_count_action\
    \ {\n    typename min_count_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type\
    \ f, typename min_count_monoid<T>::value_type x) const {\n        if (x.first\
    \ == min_count_monoid<T>().unit().first) return x;\n        return std::make_pair(f\
    \ + x.first, x.second);\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n#include \"../monoids/plus.hpp\"\n#include\
    \ \"../monoids/min_count.hpp\"\n\n/**\n * @note lazy_propagation_segment_tree<min_count_monoid<T>,\
    \ plus_monoid<T>, plus_min_count_action<T> > can count a number of zeros (or,\
    \ non-zero numbers) in the array\n */\ntemplate <class T>\nstruct plus_min_count_action\
    \ {\n    typename min_count_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type\
    \ f, typename min_count_monoid<T>::value_type x) const {\n        if (x.first\
    \ == min_count_monoid<T>().unit().first) return x;\n        return std::make_pair(f\
    \ + x.first, x.second);\n    }\n};\n"
  dependsOn:
  - monoids/plus.hpp
  - monoids/min_count.hpp
  isVerificationFile: false
  path: monoids/plus_min_count_action.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoids/plus_min_count_action.hpp
layout: document
redirect_from:
- /library/monoids/plus_min_count_action.hpp
- /library/monoids/plus_min_count_action.hpp.html
title: monoids/plus_min_count_action.hpp
---
