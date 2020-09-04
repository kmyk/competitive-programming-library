---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"number/gcd.hpp\"\n#include <algorithm>\n\n/**\n * @note\
    \ if arguments are negative, the result may be negative\n */\ntemplate <typename\
    \ T>\nT gcd(T a, T b) {\n    while (a) {\n        b %= a;\n        std::swap(a,\
    \ b);\n    }\n    return b;\n}\n\ntemplate <typename T>\nT lcm(T a, T b) {\n \
    \   return a / gcd(a, b) * b;\n}\n"
  code: "#pragma once\n#include <algorithm>\n\n/**\n * @note if arguments are negative,\
    \ the result may be negative\n */\ntemplate <typename T>\nT gcd(T a, T b) {\n\
    \    while (a) {\n        b %= a;\n        std::swap(a, b);\n    }\n    return\
    \ b;\n}\n\ntemplate <typename T>\nT lcm(T a, T b) {\n    return a / gcd(a, b)\
    \ * b;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: monoids/gcd.hpp
    title: monoids/gcd.hpp
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.yukicoder-1036.test.cpp
    title: data_structure/sparse_table.yukicoder-1036.test.cpp
  isVerificationFile: false
  path: number/gcd.hpp
  requiredBy:
  - monoids/gcd.hpp
  timestamp: '2019-06-04 14:45:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - data_structure/sparse_table.yukicoder-1036.test.cpp
documentation_of: number/gcd.hpp
layout: document
redirect_from:
- /library/number/gcd.hpp
- /library/number/gcd.hpp.html
title: number/gcd.hpp
---
