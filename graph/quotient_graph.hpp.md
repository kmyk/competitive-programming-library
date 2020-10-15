---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/transpose_graph.hpp
    title: graph/transpose_graph.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.yosupo.test.cpp
    title: graph/strongly_connected_components.yosupo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Quotient_graph
  bundledCode: "#line 2 \"graph/quotient_graph.hpp\"\n#include <vector>\n#line 2 \"\
    utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n\
    #define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i,\
    \ n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for\
    \ (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 4 \"graph/transpose_graph.hpp\"\n\n/**\n * @param g is an\
    \ adjacent list of a digraph\n * @note $O(V + E)$\n * @see https://en.wikipedia.org/wiki/Transpose_graph\n\
    \ */\nstd::vector<std::vector<int> > make_transpose_graph(std::vector<std::vector<int>\
    \ > const & g) {\n    int n = g.size();\n    std::vector<std::vector<int> > h(n);\n\
    \    REP (i, n) {\n        for (int j : g[i]) {\n            h[j].push_back(i);\n\
    \        }\n    }\n    return h;\n}\n#line 5 \"graph/quotient_graph.hpp\"\n\n\
    /**\n * @param g is an adjacent list of a digraph\n * @param size is the size\
    \ of equivalence classes\n * @param component_of is the map from original vertices\
    \ to equivalence classes\n * @note $O(V + E)$\n * @see https://en.wikipedia.org/wiki/Quotient_graph\n\
    \ */\nstd::vector<std::vector<int> > make_quotient_graph(const std::vector<std::vector<int>\
    \ > & g, int size, const std::vector<int> & component_of) {\n    int n = g.size();\n\
    \    std::vector<std::vector<int> > h(size);\n    REP (i, n) for (int j : g[i])\
    \ {\n        if (component_of[i] != component_of[j]) {\n            h[component_of[i]].push_back(component_of[j]);\n\
    \        }\n    }\n    REP (k, size) {\n        std::sort(ALL(h[k]));\n      \
    \  h[k].erase(std::unique(ALL(h[k])), h[k].end());\n    }\n    return h;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"graph/transpose_graph.hpp\"\n\
    #include \"utils/macros.hpp\"\n\n/**\n * @param g is an adjacent list of a digraph\n\
    \ * @param size is the size of equivalence classes\n * @param component_of is\
    \ the map from original vertices to equivalence classes\n * @note $O(V + E)$\n\
    \ * @see https://en.wikipedia.org/wiki/Quotient_graph\n */\nstd::vector<std::vector<int>\
    \ > make_quotient_graph(const std::vector<std::vector<int> > & g, int size, const\
    \ std::vector<int> & component_of) {\n    int n = g.size();\n    std::vector<std::vector<int>\
    \ > h(size);\n    REP (i, n) for (int j : g[i]) {\n        if (component_of[i]\
    \ != component_of[j]) {\n            h[component_of[i]].push_back(component_of[j]);\n\
    \        }\n    }\n    REP (k, size) {\n        std::sort(ALL(h[k]));\n      \
    \  h[k].erase(std::unique(ALL(h[k])), h[k].end());\n    }\n    return h;\n}\n"
  dependsOn:
  - graph/transpose_graph.hpp
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/quotient_graph.hpp
  requiredBy: []
  timestamp: '2019-12-30 23:14:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/strongly_connected_components.yosupo.test.cpp
documentation_of: graph/quotient_graph.hpp
layout: document
redirect_from:
- /library/graph/quotient_graph.hpp
- /library/graph/quotient_graph.hpp.html
title: graph/quotient_graph.hpp
---
