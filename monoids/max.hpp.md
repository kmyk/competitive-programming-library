---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: monoids/plus_max_action.hpp
    title: monoids/plus_max_action.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: old/rollback-square-decomposition.yukicoder-1031.test.cpp
    title: old/rollback-square-decomposition.yukicoder-1031.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoids/max.hpp\"\n#include <algorithm>\n#include <limits>\n\
    \ntemplate <class T>\nstruct max_monoid {\n    typedef T value_type;\n    value_type\
    \ unit() const { return std::numeric_limits<T>::lowest(); }\n    value_type mult(value_type\
    \ a, value_type b) const { return std::max(a, b); }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n\ntemplate <class\
    \ T>\nstruct max_monoid {\n    typedef T value_type;\n    value_type unit() const\
    \ { return std::numeric_limits<T>::lowest(); }\n    value_type mult(value_type\
    \ a, value_type b) const { return std::max(a, b); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/max.hpp
  requiredBy:
  - monoids/plus_max_action.hpp
  timestamp: '2019-12-27 19:16:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - old/rollback-square-decomposition.yukicoder-1031.test.cpp
documentation_of: monoids/max.hpp
layout: document
redirect_from:
- /library/monoids/max.hpp
- /library/monoids/max.hpp.html
title: monoids/max.hpp
---
