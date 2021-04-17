---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5168\u57DF\u6728\u306E\u500B\u6570\u3092\u6570\u3048\u308B\
      \ (\u884C\u5217\u6728\u5B9A\u7406)"
    links: []
  bundledCode: "#line 2 \"graph/matrix_tree_theorem.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace matrix_tree_theorem {\n\ntemplate <class T>\nT determinant(const\
    \ std::vector<std::vector<T> >& original_a) {\n    int n = original_a.size();\n\
    \    auto a = original_a;\n    T det = 1;\n    REP (i, n) {\n        REP (j, i)\
    \ {\n            if (a[j][j] == 0) {\n                int k = j + 1;\n       \
    \         for (; k < n; ++ k) {\n                    if (a[k][j] != 0) break;\n\
    \                }\n                if (k == n) return 0;\n                REP3\
    \ (l, j, n) {\n                    swap(a[j][l], a[k][l]);\n                }\n\
    \            }\n            assert (a[j][j] != 0);\n            T t = a[i][j]\
    \ / a[j][j];\n            REP3 (k, j + 1, n) {\n                a[i][k] -= a[j][k]\
    \ * t;\n            }\n        }\n    }\n    REP (i, a.size()) det *= a[i][i];\n\
    \    return det;\n}\n\ntemplate <class T>\nstd::vector<std::vector<T> > small_matrix(const\
    \ std::vector<std::vector<T> >& a) {\n    int n = a.size();\n    assert (n >=\
    \ 1);\n    auto b = a;\n    b.resize(n - 1);\n    REP (y, n - 1) {\n        b[y].resize(n\
    \ - 1);\n    }\n    return b;\n}\n\ntemplate <class T>\nstd::vector<std::vector<T>\
    \ > laplacian_matrix_from_adjacency_matrix(const std::vector<std::vector<T> >&\
    \ a) {\n    REP (y, a.size()) {\n        REP (x, a[y].size()) {\n            if\
    \ (y == x) {\n                assert (a[y][x] == 0);\n            }\n        }\n\
    \    }\n    std::vector<std::vector<T> > l = a;\n    REP (y, l.size()) {\n   \
    \     REP (x, l[y].size()) {\n            if (y == x) {\n                l[y][y]\
    \ += l[y][x];\n                l[y][x] *= -1;\n            }\n        }\n    }\n\
    \    return l;\n}\n\n/**\n * @brief \u5168\u57DF\u6728\u306E\u500B\u6570\u3092\
    \u6570\u3048\u308B (\u884C\u5217\u6728\u5B9A\u7406)\n * @arg a is an adjacency\
    \ matrix of a graph without self-loops. Multiple edges are allowed.\n */\ntemplate\
    \ <class T>\nT count_spanning_trees(const std::vector<std::vector<T> >& a) {\n\
    \    return determinant(small_matrix(laplacian_matrix_from_adjacency_matrix(a)));\n\
    }\n\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace matrix_tree_theorem\
    \ {\n\ntemplate <class T>\nT determinant(const std::vector<std::vector<T> >& original_a)\
    \ {\n    int n = original_a.size();\n    auto a = original_a;\n    T det = 1;\n\
    \    REP (i, n) {\n        REP (j, i) {\n            if (a[j][j] == 0) {\n   \
    \             int k = j + 1;\n                for (; k < n; ++ k) {\n        \
    \            if (a[k][j] != 0) break;\n                }\n                if (k\
    \ == n) return 0;\n                REP3 (l, j, n) {\n                    swap(a[j][l],\
    \ a[k][l]);\n                }\n            }\n            assert (a[j][j] !=\
    \ 0);\n            T t = a[i][j] / a[j][j];\n            REP3 (k, j + 1, n) {\n\
    \                a[i][k] -= a[j][k] * t;\n            }\n        }\n    }\n  \
    \  REP (i, a.size()) det *= a[i][i];\n    return det;\n}\n\ntemplate <class T>\n\
    std::vector<std::vector<T> > small_matrix(const std::vector<std::vector<T> >&\
    \ a) {\n    int n = a.size();\n    assert (n >= 1);\n    auto b = a;\n    b.resize(n\
    \ - 1);\n    REP (y, n - 1) {\n        b[y].resize(n - 1);\n    }\n    return\
    \ b;\n}\n\ntemplate <class T>\nstd::vector<std::vector<T> > laplacian_matrix_from_adjacency_matrix(const\
    \ std::vector<std::vector<T> >& a) {\n    REP (y, a.size()) {\n        REP (x,\
    \ a[y].size()) {\n            if (y == x) {\n                assert (a[y][x] ==\
    \ 0);\n            }\n        }\n    }\n    std::vector<std::vector<T> > l = a;\n\
    \    REP (y, l.size()) {\n        REP (x, l[y].size()) {\n            if (y ==\
    \ x) {\n                l[y][y] += l[y][x];\n                l[y][x] *= -1;\n\
    \            }\n        }\n    }\n    return l;\n}\n\n/**\n * @brief \u5168\u57DF\
    \u6728\u306E\u500B\u6570\u3092\u6570\u3048\u308B (\u884C\u5217\u6728\u5B9A\u7406\
    )\n * @arg a is an adjacency matrix of a graph without self-loops. Multiple edges\
    \ are allowed.\n */\ntemplate <class T>\nT count_spanning_trees(const std::vector<std::vector<T>\
    \ >& a) {\n    return determinant(small_matrix(laplacian_matrix_from_adjacency_matrix(a)));\n\
    }\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/matrix_tree_theorem.hpp
  requiredBy: []
  timestamp: '2021-04-17 18:31:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/matrix_tree_theorem.hpp
layout: document
redirect_from:
- /library/graph/matrix_tree_theorem.hpp
- /library/graph/matrix_tree_theorem.hpp.html
title: "\u5168\u57DF\u6728\u306E\u500B\u6570\u3092\u6570\u3048\u308B (\u884C\u5217\
  \u6728\u5B9A\u7406)"
---
