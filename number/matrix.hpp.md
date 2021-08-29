---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number/matrix.yukicoder-1073.test.cpp
    title: number/matrix.yukicoder-1073.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number/matrix.hpp\"\n#include <cstdint>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 5 \"number/matrix.hpp\"\n\ntemplate <typename T>\nstd::vector<std::vector<T>\
    \ > operator * (const std::vector<std::vector<T> >& a, const std::vector<std::vector<T>\
    \ >& b) {\n    int n = a.size();\n    std::vector<std::vector<T> > c(n, std::vector<T>(n));\n\
    \    REP (y, n) {\n        REP (z, n) {\n            REP (x, n) {\n          \
    \      c[y][x] += a[y][z] * b[z][x];\n            }\n        }\n    }\n    return\
    \ c;\n}\n\ntemplate <typename T>\nstd::vector<T> operator * (const std::vector<std::vector<T>\
    \ >& a, const std::vector<T>& b) {\n    int n = a.size();\n    std::vector<T>\
    \ c(n);\n    REP (y, n) {\n        REP (z, n) {\n            c[y] += a[y][z] *\
    \ b[z];\n        }\n    }\n    return c;\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T>\
    \ > unit_matrix(int n) {\n    auto e = std::vector<std::vector<T> >(n, std::vector<T>(n));\n\
    \    REP (i, n) {\n        e[i][i] = 1;\n    }\n    return e;\n}\n\ntemplate <typename\
    \ T>\nstd::vector<std::vector<T> > zero_matrix(int n) {\n    return std::vector<std::vector<T>\
    \ >(n, std::vector<T>(n));\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T>\
    \ > matpow(std::vector<std::vector<T> > x, int64_t y) {\n    int n = x.size();\n\
    \    auto z = unit_matrix<T>(n);\n    for (int64_t i = 1; i <= y; i <<= 1) {\n\
    \        if (y & i) {\n            z = z * x;\n        }\n        x = x * x;\n\
    \    }\n    return z;\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n#include \"../utils/macros.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::vector<T> > operator * (const std::vector<std::vector<T>\
    \ >& a, const std::vector<std::vector<T> >& b) {\n    int n = a.size();\n    std::vector<std::vector<T>\
    \ > c(n, std::vector<T>(n));\n    REP (y, n) {\n        REP (z, n) {\n       \
    \     REP (x, n) {\n                c[y][x] += a[y][z] * b[z][x];\n          \
    \  }\n        }\n    }\n    return c;\n}\n\ntemplate <typename T>\nstd::vector<T>\
    \ operator * (const std::vector<std::vector<T> >& a, const std::vector<T>& b)\
    \ {\n    int n = a.size();\n    std::vector<T> c(n);\n    REP (y, n) {\n     \
    \   REP (z, n) {\n            c[y] += a[y][z] * b[z];\n        }\n    }\n    return\
    \ c;\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T> > unit_matrix(int\
    \ n) {\n    auto e = std::vector<std::vector<T> >(n, std::vector<T>(n));\n   \
    \ REP (i, n) {\n        e[i][i] = 1;\n    }\n    return e;\n}\n\ntemplate <typename\
    \ T>\nstd::vector<std::vector<T> > zero_matrix(int n) {\n    return std::vector<std::vector<T>\
    \ >(n, std::vector<T>(n));\n}\n\ntemplate <typename T>\nstd::vector<std::vector<T>\
    \ > matpow(std::vector<std::vector<T> > x, int64_t y) {\n    int n = x.size();\n\
    \    auto z = unit_matrix<T>(n);\n    for (int64_t i = 1; i <= y; i <<= 1) {\n\
    \        if (y & i) {\n            z = z * x;\n        }\n        x = x * x;\n\
    \    }\n    return z;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: number/matrix.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number/matrix.yukicoder-1073.test.cpp
documentation_of: number/matrix.hpp
layout: document
redirect_from:
- /library/number/matrix.hpp
- /library/number/matrix.hpp.html
title: number/matrix.hpp
---
