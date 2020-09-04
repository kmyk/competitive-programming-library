---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"old/matrix.inc.cpp\"\ntemplate <typename T>\nvector<vector<T>\
    \ > operator * (vector<vector<T> > const & a, vector<vector<T> > const & b) {\n\
    \    int n = a.size();\n    vector<vector<T> > c = vectors(n, n, T());\n    REP\
    \ (y, n) REP (z, n) REP (x, n) c[y][x] += a[y][z] * b[z][x];\n    return c;\n\
    }\ntemplate <typename T>\nvector<T> operator * (vector<vector<T> > const & a,\
    \ vector<T> const & b) {\n    int n = a.size();\n    vector<T> c(n);\n    REP\
    \ (y, n) REP (z, n) c[y] += a[y][z] * b[z];\n    return c;\n}\ntemplate <typename\
    \ T>\nvector<vector<T> > unit_matrix(int n) {\n    vector<vector<T> > e = vectors(n,\
    \ n, T());\n    REP (i, n) e[i][i] = 1;\n    return e;\n}\ntemplate <typename\
    \ T>\nvector<vector<T> > zero_matrix(int n) {\n    vector<vector<T> > o = vectors(n,\
    \ n, T());\n    return o;\n}\n\ntemplate <typename T>\nT determinant(vector<vector<T>\
    \ > a) {\n    int n = a.size();\n    REP (z, n) { // make A upper trianglar\n\
    \        if (a[z][z] == 0) { // swap rows to avoid zero-division\n           \
    \ int x = z + 1;\n            for (; x < n; ++ x) {\n                if (a[x][z]\
    \ != 0) {\n                    a[z].swap(a[x]);\n                    break;\n\
    \                }\n            }\n            if (x == n) return 0; // A is singular\n\
    \        }\n        REP3 (y, z + 1, n) {\n            T k = a[y][z] / a[z][z];\n\
    \            REP3 (x, z + 1, n) {\n                a[y][x] -= k * a[z][x]; //\
    \ elim\n            }\n            a[y][z] = 0;\n        }\n    }\n    T acc =\
    \ 1;\n    REP (z, n) acc *= a[z][z]; // product of the diagonal elems\n    return\
    \ acc;\n}\n\ntemplate <class T>\nvector<vector<T> > small_matrix(vector<vector<T>\
    \ > const & a) {\n    int n = a.size();\n    assert (n >= 1);\n    auto b = a;\n\
    \    b.resize(n - 1);\n    REP (y, n - 1) {\n        b[y].resize(n - 1);\n   \
    \ }\n    return b;\n}\n\ntemplate <typename T>\nvector<T> gaussian_elimination(vector<vector<T>\
    \ > f, vector<T> x) {\n    int n = x.size();\n    REP (y, n) {\n        int pivot\
    \ = y;\n        while (pivot < n and abs(f[pivot][y]) < eps) ++ pivot;\n     \
    \   assert (pivot < n);\n        swap(f[y], f[pivot]);\n        x[y] /= f[y][y];\n\
    \        REP3 (x, y + 1, n) f[y][x] /= f[y][y];\n        f[y][y] = 1;\n      \
    \  REP (ny, n) if (ny != y) {\n            x[ny] -= f[ny][y] * x[y];\n       \
    \     REP3 (x, y + 1, n) f[ny][x] -= f[ny][y] * f[y][x];\n            f[ny][y]\
    \ = 0;\n        }\n    }\n    return x;\n}\n\nconstexpr double eps = 1e-8;\ntemplate\
    \ <typename T>\nvector<vector<T> > inverse_matrix(vector<vector<T> > f) {\n  \
    \  int n = f.size();\n    vector<vector<T> > g = unit_matrix<T>(n);\n    REP (y,\
    \ n) {\n        int pivot = y;\n        while (pivot < n and abs(f[pivot][y])\
    \ < eps) ++ pivot;\n        assert (pivot < n);\n        swap(f[y], f[pivot]);\n\
    \        REP (x, n) g[y][x] /= f[y][y];\n        REP3 (x, y + 1, n) f[y][x] /=\
    \ f[y][y];\n        f[y][y] = 1;\n        REP (ny, n) if (ny != y) {\n       \
    \     REP (x, n) g[ny][x] -= f[ny][y] * g[y][x];\n            REP3 (x, y + 1,\
    \ n) f[ny][x] -= f[ny][y] * f[y][x];\n            f[ny][y] = 0;\n        }\n \
    \   }\n    return g;\n}\nunittest {\n    vector<vector<double> > f { { 1, 2 },\
    \ { 3, 4 } };\n    auto g = f * inverse_matrix(f);\n    assert (abs(g[0][0] -\
    \ 1) < eps);\n    assert (abs(g[0][1]    ) < eps);\n    assert (abs(g[1][0]  \
    \  ) < eps);\n    assert (abs(g[1][1] - 1) < eps);\n}\n\ntemplate <typename T>\n\
    vector<vector<T> > powmat(vector<vector<T> > x, ll y) {\n    int n = x.size();\n\
    \    auto z = unit_matrix<T>(n);\n    for (ll i = 1; i <= y; i <<= 1) {\n    \
    \    if (y & i) z = z * x;\n        x = x * x;\n    }\n    return z;\n}\n\ntemplate\
    \ <typename T>\nvector<vector<T> > concat_matrix_vector(vector<vector<T> > const\
    \ & f, vector<T> const & x) {\n    int h = f.size();\n    int w = f.fornt().size();\n\
    \    vector<vector<T> > fx(h);\n    REP (y, h) {\n        fx[y].resize(w + 1);\n\
    \        copy(whole(f[y]), fx[y].begin());\n        fx[y][w] = x[y];\n    }\n\
    \    return fx;\n}\n"
  code: "template <typename T>\nvector<vector<T> > operator * (vector<vector<T> >\
    \ const & a, vector<vector<T> > const & b) {\n    int n = a.size();\n    vector<vector<T>\
    \ > c = vectors(n, n, T());\n    REP (y, n) REP (z, n) REP (x, n) c[y][x] += a[y][z]\
    \ * b[z][x];\n    return c;\n}\ntemplate <typename T>\nvector<T> operator * (vector<vector<T>\
    \ > const & a, vector<T> const & b) {\n    int n = a.size();\n    vector<T> c(n);\n\
    \    REP (y, n) REP (z, n) c[y] += a[y][z] * b[z];\n    return c;\n}\ntemplate\
    \ <typename T>\nvector<vector<T> > unit_matrix(int n) {\n    vector<vector<T>\
    \ > e = vectors(n, n, T());\n    REP (i, n) e[i][i] = 1;\n    return e;\n}\ntemplate\
    \ <typename T>\nvector<vector<T> > zero_matrix(int n) {\n    vector<vector<T>\
    \ > o = vectors(n, n, T());\n    return o;\n}\n\ntemplate <typename T>\nT determinant(vector<vector<T>\
    \ > a) {\n    int n = a.size();\n    REP (z, n) { // make A upper trianglar\n\
    \        if (a[z][z] == 0) { // swap rows to avoid zero-division\n           \
    \ int x = z + 1;\n            for (; x < n; ++ x) {\n                if (a[x][z]\
    \ != 0) {\n                    a[z].swap(a[x]);\n                    break;\n\
    \                }\n            }\n            if (x == n) return 0; // A is singular\n\
    \        }\n        REP3 (y, z + 1, n) {\n            T k = a[y][z] / a[z][z];\n\
    \            REP3 (x, z + 1, n) {\n                a[y][x] -= k * a[z][x]; //\
    \ elim\n            }\n            a[y][z] = 0;\n        }\n    }\n    T acc =\
    \ 1;\n    REP (z, n) acc *= a[z][z]; // product of the diagonal elems\n    return\
    \ acc;\n}\n\ntemplate <class T>\nvector<vector<T> > small_matrix(vector<vector<T>\
    \ > const & a) {\n    int n = a.size();\n    assert (n >= 1);\n    auto b = a;\n\
    \    b.resize(n - 1);\n    REP (y, n - 1) {\n        b[y].resize(n - 1);\n   \
    \ }\n    return b;\n}\n\ntemplate <typename T>\nvector<T> gaussian_elimination(vector<vector<T>\
    \ > f, vector<T> x) {\n    int n = x.size();\n    REP (y, n) {\n        int pivot\
    \ = y;\n        while (pivot < n and abs(f[pivot][y]) < eps) ++ pivot;\n     \
    \   assert (pivot < n);\n        swap(f[y], f[pivot]);\n        x[y] /= f[y][y];\n\
    \        REP3 (x, y + 1, n) f[y][x] /= f[y][y];\n        f[y][y] = 1;\n      \
    \  REP (ny, n) if (ny != y) {\n            x[ny] -= f[ny][y] * x[y];\n       \
    \     REP3 (x, y + 1, n) f[ny][x] -= f[ny][y] * f[y][x];\n            f[ny][y]\
    \ = 0;\n        }\n    }\n    return x;\n}\n\nconstexpr double eps = 1e-8;\ntemplate\
    \ <typename T>\nvector<vector<T> > inverse_matrix(vector<vector<T> > f) {\n  \
    \  int n = f.size();\n    vector<vector<T> > g = unit_matrix<T>(n);\n    REP (y,\
    \ n) {\n        int pivot = y;\n        while (pivot < n and abs(f[pivot][y])\
    \ < eps) ++ pivot;\n        assert (pivot < n);\n        swap(f[y], f[pivot]);\n\
    \        REP (x, n) g[y][x] /= f[y][y];\n        REP3 (x, y + 1, n) f[y][x] /=\
    \ f[y][y];\n        f[y][y] = 1;\n        REP (ny, n) if (ny != y) {\n       \
    \     REP (x, n) g[ny][x] -= f[ny][y] * g[y][x];\n            REP3 (x, y + 1,\
    \ n) f[ny][x] -= f[ny][y] * f[y][x];\n            f[ny][y] = 0;\n        }\n \
    \   }\n    return g;\n}\nunittest {\n    vector<vector<double> > f { { 1, 2 },\
    \ { 3, 4 } };\n    auto g = f * inverse_matrix(f);\n    assert (abs(g[0][0] -\
    \ 1) < eps);\n    assert (abs(g[0][1]    ) < eps);\n    assert (abs(g[1][0]  \
    \  ) < eps);\n    assert (abs(g[1][1] - 1) < eps);\n}\n\ntemplate <typename T>\n\
    vector<vector<T> > powmat(vector<vector<T> > x, ll y) {\n    int n = x.size();\n\
    \    auto z = unit_matrix<T>(n);\n    for (ll i = 1; i <= y; i <<= 1) {\n    \
    \    if (y & i) z = z * x;\n        x = x * x;\n    }\n    return z;\n}\n\ntemplate\
    \ <typename T>\nvector<vector<T> > concat_matrix_vector(vector<vector<T> > const\
    \ & f, vector<T> const & x) {\n    int h = f.size();\n    int w = f.fornt().size();\n\
    \    vector<vector<T> > fx(h);\n    REP (y, h) {\n        fx[y].resize(w + 1);\n\
    \        copy(whole(f[y]), fx[y].begin());\n        fx[y][w] = x[y];\n    }\n\
    \    return fx;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/matrix.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/matrix.inc.cpp
layout: document
redirect_from:
- /library/old/matrix.inc.cpp
- /library/old/matrix.inc.cpp.html
title: old/matrix.inc.cpp
---
