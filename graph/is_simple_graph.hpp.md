---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/is_simple_graph.hpp\"\n#include <set>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 5 \"graph/is_simple_graph.hpp\"\n\nbool is_simple_graph(const\
    \ std::vector<std::vector<int>> &g) {\n    int n = g.size();\n    REP (x, n) {\n\
    \        std::set<int> used;\n        for (int y : g[x]) {\n            if (y\
    \ == x or used.count(y)) {\n                return false;\n            }\n   \
    \         used.insert(y);\n        }\n    }\n    return true;\n}\n"
  code: "#pragma once\n#include <set>\n#include <vector>\n#include \"../utils/macros.hpp\"\
    \n\nbool is_simple_graph(const std::vector<std::vector<int>> &g) {\n    int n\
    \ = g.size();\n    REP (x, n) {\n        std::set<int> used;\n        for (int\
    \ y : g[x]) {\n            if (y == x or used.count(y)) {\n                return\
    \ false;\n            }\n            used.insert(y);\n        }\n    }\n    return\
    \ true;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/is_simple_graph.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/is_simple_graph.hpp
layout: document
redirect_from:
- /library/graph/is_simple_graph.hpp
- /library/graph/is_simple_graph.hpp.html
title: graph/is_simple_graph.hpp
---
