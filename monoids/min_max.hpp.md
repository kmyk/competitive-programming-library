---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"monoids/min_max.hpp\"\n#include <algorithm>\n#include <numeric>\n\
    #include <utility>\n\ntemplate <class T>\nstruct min_max_monoid {\n    typedef\
    \ std::pair<T, T> value_type;\n    value_type unit() const {\n        return std::make_pair(std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::lowest());\n    }\n    value_type mult(value_type a,\
    \ value_type b) const {\n        return std::make_pair(std::min(a.min, b.min),\
    \ std::max(a.max, b.max));\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <utility>\n\
    \ntemplate <class T>\nstruct min_max_monoid {\n    typedef std::pair<T, T> value_type;\n\
    \    value_type unit() const {\n        return std::make_pair(std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::lowest());\n    }\n    value_type mult(value_type a,\
    \ value_type b) const {\n        return std::make_pair(std::min(a.min, b.min),\
    \ std::max(a.max, b.max));\n    }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':warning:'
    path: monoids/chmin_chmax_add_min_max_action.hpp
    title: monoids/chmin_chmax_add_min_max_action.hpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: monoids/min_max.hpp
  requiredBy:
  - monoids/chmin_chmax_add_min_max_action.hpp
  timestamp: '2020-01-08 14:04:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: monoids/min_max.hpp
layout: document
redirect_from:
- /library/monoids/min_max.hpp
- /library/monoids/min_max.hpp.html
title: monoids/min_max.hpp
---
