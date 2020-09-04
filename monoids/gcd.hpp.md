---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"number/gcd.hpp\"\n#include <algorithm>\n\n/**\n * @note\
    \ if arguments are negative, the result may be negative\n */\ntemplate <typename\
    \ T>\nT gcd(T a, T b) {\n    while (a) {\n        b %= a;\n        std::swap(a,\
    \ b);\n    }\n    return b;\n}\n\ntemplate <typename T>\nT lcm(T a, T b) {\n \
    \   return a / gcd(a, b) * b;\n}\n#line 3 \"monoids/gcd.hpp\"\n\n/**\n * @note\
    \ a semilattice\n */\ntemplate <class Integer>\nstruct gcd_monoid {\n    typedef\
    \ Integer value_type;\n    Integer unit() const { return 0; }\n    Integer mult(Integer\
    \ a, Integer b) const { return gcd(a, b); }\n};\n"
  code: "#pragma once\n#include \"number/gcd.hpp\"\n\n/**\n * @note a semilattice\n\
    \ */\ntemplate <class Integer>\nstruct gcd_monoid {\n    typedef Integer value_type;\n\
    \    Integer unit() const { return 0; }\n    Integer mult(Integer a, Integer b)\
    \ const { return gcd(a, b); }\n};\n"
  dependsOn:
  - number/gcd.hpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number/gcd.hpp
    title: number/gcd.hpp
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.yukicoder-1036.test.cpp
    title: data_structure/sparse_table.yukicoder-1036.test.cpp
  isVerificationFile: false
  path: monoids/gcd.hpp
  requiredBy: []
  timestamp: '2020-04-24 23:33:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - data_structure/sparse_table.yukicoder-1036.test.cpp
documentation_of: monoids/gcd.hpp
layout: document
redirect_from:
- /library/monoids/gcd.hpp
- /library/monoids/gcd.hpp.html
title: monoids/gcd.hpp
---
