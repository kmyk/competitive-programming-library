---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: monoids/plus_min_count_action.hpp
    title: monoids/plus_min_count_action.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoids/min_count.hpp\"\n#include <limits>\n#include <utility>\n\
    \ntemplate <class T>\nstruct min_count_monoid {\n    typedef std::pair<T, int>\
    \ value_type;\n    value_type unit() const {\n        return std::make_pair(std::numeric_limits<T>::max(),\
    \ 0);\n    }\n    value_type mult(value_type a, value_type b) const {\n      \
    \  if (a.first < b.first) return a;\n        if (a.first > b.first) return b;\n\
    \        return std::make_pair(a.first, a.second + b.second);\n    }\n    static\
    \ value_type make(T a) {\n        return std::make_pair(a, 1);\n    }\n};\n"
  code: "#pragma once\n#include <limits>\n#include <utility>\n\ntemplate <class T>\n\
    struct min_count_monoid {\n    typedef std::pair<T, int> value_type;\n    value_type\
    \ unit() const {\n        return std::make_pair(std::numeric_limits<T>::max(),\
    \ 0);\n    }\n    value_type mult(value_type a, value_type b) const {\n      \
    \  if (a.first < b.first) return a;\n        if (a.first > b.first) return b;\n\
    \        return std::make_pair(a.first, a.second + b.second);\n    }\n    static\
    \ value_type make(T a) {\n        return std::make_pair(a, 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/min_count.hpp
  requiredBy:
  - monoids/plus_min_count_action.hpp
  timestamp: '2019-12-27 19:16:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoids/min_count.hpp
layout: document
redirect_from:
- /library/monoids/min_count.hpp
- /library/monoids/min_count.hpp.html
title: monoids/min_count.hpp
---
