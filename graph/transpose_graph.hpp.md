---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/quotient_graph.hpp
    title: graph/quotient_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "strongly connected components decomposition, Kosaraju's algorithm / \u5F37\
      \u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: utils/two_satisfiability.hpp
    title: 2-SAT ($O(N)$)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.yosupo.test.cpp
    title: graph/strongly_connected_components.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: utils/two_satisfiability.yosupo.test.cpp
    title: utils/two_satisfiability.yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Transpose_graph
  bundledCode: "#line 2 \"graph/transpose_graph.hpp\"\n#include <vector>\n#line 2\
    \ \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n\
    #define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i,\
    \ n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for\
    \ (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 4 \"graph/transpose_graph.hpp\"\n\n/**\n * @param g is an\
    \ adjacent list of a digraph\n * @note $O(V + E)$\n * @see https://en.wikipedia.org/wiki/Transpose_graph\n\
    \ */\nstd::vector<std::vector<int> > make_transpose_graph(std::vector<std::vector<int>\
    \ > const & g) {\n    int n = g.size();\n    std::vector<std::vector<int> > h(n);\n\
    \    REP (i, n) {\n        for (int j : g[i]) {\n            h[j].push_back(i);\n\
    \        }\n    }\n    return h;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"utils/macros.hpp\"\n\n/**\n *\
    \ @param g is an adjacent list of a digraph\n * @note $O(V + E)$\n * @see https://en.wikipedia.org/wiki/Transpose_graph\n\
    \ */\nstd::vector<std::vector<int> > make_transpose_graph(std::vector<std::vector<int>\
    \ > const & g) {\n    int n = g.size();\n    std::vector<std::vector<int> > h(n);\n\
    \    REP (i, n) {\n        for (int j : g[i]) {\n            h[j].push_back(i);\n\
    \        }\n    }\n    return h;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/transpose_graph.hpp
  requiredBy:
  - utils/two_satisfiability.hpp
  - graph/strongly_connected_components.hpp
  - graph/quotient_graph.hpp
  timestamp: '2019-12-30 23:14:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - utils/two_satisfiability.yosupo.test.cpp
  - graph/strongly_connected_components.yosupo.test.cpp
documentation_of: graph/transpose_graph.hpp
layout: document
redirect_from:
- /library/graph/transpose_graph.hpp
- /library/graph/transpose_graph.hpp.html
title: graph/transpose_graph.hpp
---
