---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 2 \"number/matrix_template.hpp\"\n#include <array>\n#include\
    \ <cstdint>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i)\
    \ < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n\
    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 5 \"number/matrix_template.hpp\"\n\n\
    template <typename T, size_t H, size_t W>\nusing matrix = std::array<std::array<T,\
    \ W>, H>;\n\ntemplate <typename T, size_t A, size_t B, size_t C>\nmatrix<T, A,\
    \ C> operator * (matrix<T, A, B> const & a, matrix<T, B, C> const & b) {\n   \
    \ matrix<T, A, C> c = {};\n    REP (y, A) REP (z, B) REP (x, C) c[y][x] += a[y][z]\
    \ * b[z][x];\n    return c;\n}\ntemplate <typename T, size_t H, size_t W>\nstd::array<T,\
    \ H> operator * (matrix<T, H, W> const & a, std::array<T, W> const & b) {\n  \
    \  std::array<T, H> c = {};\n    REP (y, H) REP (z, W) c[y] += a[y][z] * b[z];\n\
    \    return c;\n}\n\ntemplate <typename T, size_t H, size_t W>\nmatrix<T, H, W>\
    \ operator + (matrix<T, H, W> const & a, matrix<T, H, W> const & b) {\n    matrix<T,\
    \ H, W> c;\n    REP (y, H) REP (x, W) c[y][x] = a[y][x] + b[y][x];\n    return\
    \ c;\n}\n\ntemplate <typename T, size_t N>\nstd::array<T, N> operator + (std::array<T,\
    \ N> const & a, std::array<T, N> const & b) {\n    std::array<T, N> c;\n    REP\
    \ (i, N) c[i] = a[i] + b[i];\n    return c;\n}\n\ntemplate <typename T, size_t\
    \ H, size_t W>\nmatrix<T, H, W> zero_matrix() {\n    return {};\n}\n\ntemplate\
    \ <typename T, size_t N>\nmatrix<T, N, N> unit_matrix() {\n    matrix<T, N, N>\
    \ a = {};\n    REP (i, N) a[i][i] = 1;\n    return a;\n}\n\ntemplate <typename\
    \ T, size_t N>\nmatrix<T, N, N> powmat(matrix<T, N, N> x, int64_t k) {\n    matrix<T,\
    \ N, N> y = unit_matrix<T, N>();\n    for (; k; k >>= 1) {\n        if (k & 1)\
    \ y = y * x;\n        x = x * x;\n    }\n    return y;\n}\n#line 3 \"monoids/matrix_template.hpp\"\
    \n\ntemplate <class T, int N>\nstruct matrix_monoid {\n    typedef matrix<T, N,\
    \ N> value_type;\n    value_type f;\n    value_type unit() const {\n        return\
    \ unit_matrix<T, N>();\n    }\n    value_type mult(const value_type & f, const\
    \ value_type & g) const {\n        return f * g;\n    }\n};\n"
  code: "#pragma once\n#include \"number/matrix_template.hpp\"\n\ntemplate <class\
    \ T, int N>\nstruct matrix_monoid {\n    typedef matrix<T, N, N> value_type;\n\
    \    value_type f;\n    value_type unit() const {\n        return unit_matrix<T,\
    \ N>();\n    }\n    value_type mult(const value_type & f, const value_type & g)\
    \ const {\n        return f * g;\n    }\n};\n"
  dependsOn:
  - number/matrix_template.hpp
  - utils/macros.hpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number/matrix_template.hpp
    title: number/matrix_template.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: monoids/matrix_template.hpp
  requiredBy: []
  timestamp: '2019-12-20 06:12:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: monoids/matrix_template.hpp
layout: document
redirect_from:
- /library/monoids/matrix_template.hpp
- /library/monoids/matrix_template.hpp.html
title: monoids/matrix_template.hpp
---
