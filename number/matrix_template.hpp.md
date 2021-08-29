---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: monoids/matrix_template.hpp
    title: monoids/matrix_template.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: number/matrix_template.yukicoder-1073.test.cpp
    title: number/matrix_template.yukicoder-1073.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number/matrix_template.hpp\"\n#include <array>\n#include\
    \ <cstdint>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i)\
    \ < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n\
    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 5 \"number/matrix_template.hpp\"\n\n\
    template <typename T, int H, int W>\nusing matrix = std::array<std::array<T, W>,\
    \ H>;\n\ntemplate <typename T, int A, int B, int C>\nmatrix<T, A, C> operator\
    \ * (matrix<T, A, B> const & a, matrix<T, B, C> const & b) {\n    matrix<T, A,\
    \ C> c = {};\n    REP (y, A) REP (z, B) REP (x, C) c[y][x] += a[y][z] * b[z][x];\n\
    \    return c;\n}\ntemplate <typename T, int H, int W>\nstd::array<T, H> operator\
    \ * (matrix<T, H, W> const & a, std::array<T, W> const & b) {\n    std::array<T,\
    \ H> c = {};\n    REP (y, H) REP (z, W) c[y] += a[y][z] * b[z];\n    return c;\n\
    }\n\ntemplate <typename T, int H, int W>\nmatrix<T, H, W> operator + (matrix<T,\
    \ H, W> const & a, matrix<T, H, W> const & b) {\n    matrix<T, H, W> c;\n    REP\
    \ (y, H) REP (x, W) c[y][x] = a[y][x] + b[y][x];\n    return c;\n}\n\ntemplate\
    \ <typename T, int N>\nstd::array<T, N> operator + (std::array<T, N> const & a,\
    \ std::array<T, N> const & b) {\n    std::array<T, N> c;\n    REP (i, N) c[i]\
    \ = a[i] + b[i];\n    return c;\n}\n\ntemplate <typename T, int H, int W>\nmatrix<T,\
    \ H, W> zero_matrix() {\n    return {};\n}\n\ntemplate <typename T, int N>\nmatrix<T,\
    \ N, N> unit_matrix() {\n    matrix<T, N, N> a = {};\n    REP (i, N) a[i][i] =\
    \ 1;\n    return a;\n}\n\ntemplate <typename T, int N>\nmatrix<T, N, N> matpow(matrix<T,\
    \ N, N> x, int64_t k) {\n    matrix<T, N, N> y = unit_matrix<T, N>();\n    for\
    \ (; k; k >>= 1) {\n        if (k & 1) y = y * x;\n        x = x * x;\n    }\n\
    \    return y;\n}\n"
  code: "#pragma once\n#include <array>\n#include <cstdint>\n#include \"../utils/macros.hpp\"\
    \n\ntemplate <typename T, int H, int W>\nusing matrix = std::array<std::array<T,\
    \ W>, H>;\n\ntemplate <typename T, int A, int B, int C>\nmatrix<T, A, C> operator\
    \ * (matrix<T, A, B> const & a, matrix<T, B, C> const & b) {\n    matrix<T, A,\
    \ C> c = {};\n    REP (y, A) REP (z, B) REP (x, C) c[y][x] += a[y][z] * b[z][x];\n\
    \    return c;\n}\ntemplate <typename T, int H, int W>\nstd::array<T, H> operator\
    \ * (matrix<T, H, W> const & a, std::array<T, W> const & b) {\n    std::array<T,\
    \ H> c = {};\n    REP (y, H) REP (z, W) c[y] += a[y][z] * b[z];\n    return c;\n\
    }\n\ntemplate <typename T, int H, int W>\nmatrix<T, H, W> operator + (matrix<T,\
    \ H, W> const & a, matrix<T, H, W> const & b) {\n    matrix<T, H, W> c;\n    REP\
    \ (y, H) REP (x, W) c[y][x] = a[y][x] + b[y][x];\n    return c;\n}\n\ntemplate\
    \ <typename T, int N>\nstd::array<T, N> operator + (std::array<T, N> const & a,\
    \ std::array<T, N> const & b) {\n    std::array<T, N> c;\n    REP (i, N) c[i]\
    \ = a[i] + b[i];\n    return c;\n}\n\ntemplate <typename T, int H, int W>\nmatrix<T,\
    \ H, W> zero_matrix() {\n    return {};\n}\n\ntemplate <typename T, int N>\nmatrix<T,\
    \ N, N> unit_matrix() {\n    matrix<T, N, N> a = {};\n    REP (i, N) a[i][i] =\
    \ 1;\n    return a;\n}\n\ntemplate <typename T, int N>\nmatrix<T, N, N> matpow(matrix<T,\
    \ N, N> x, int64_t k) {\n    matrix<T, N, N> y = unit_matrix<T, N>();\n    for\
    \ (; k; k >>= 1) {\n        if (k & 1) y = y * x;\n        x = x * x;\n    }\n\
    \    return y;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: number/matrix_template.hpp
  requiredBy:
  - monoids/matrix_template.hpp
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - number/matrix_template.yukicoder-1073.test.cpp
documentation_of: number/matrix_template.hpp
layout: document
redirect_from:
- /library/number/matrix_template.hpp
- /library/number/matrix_template.hpp.html
title: number/matrix_template.hpp
---
