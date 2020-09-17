---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoids/max_index.hpp\"\n#include <algorithm>\n#include\
    \ <climits>\n#include <limits>\n#include <utility>\n\n/**\n * @note a semilattice\n\
    \ */\ntemplate <class T>\nstruct max_index_monoid {\n    typedef std::pair<T,\
    \ int> value_type;\n    value_type unit() const { return std::make_pair(std::numeric_limits<T>::lowest(),\
    \ INT_MIN); }\n    value_type mult(value_type a, value_type b) const { return\
    \ std::max(a, b); }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <climits>\n#include <limits>\n\
    #include <utility>\n\n/**\n * @note a semilattice\n */\ntemplate <class T>\nstruct\
    \ max_index_monoid {\n    typedef std::pair<T, int> value_type;\n    value_type\
    \ unit() const { return std::make_pair(std::numeric_limits<T>::lowest(), INT_MIN);\
    \ }\n    value_type mult(value_type a, value_type b) const { return std::max(a,\
    \ b); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/max_index.hpp
  requiredBy: []
  timestamp: '2020-01-11 22:02:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoids/max_index.hpp
layout: document
redirect_from:
- /library/monoids/max_index.hpp
- /library/monoids/max_index.hpp.html
title: monoids/max_index.hpp
---
