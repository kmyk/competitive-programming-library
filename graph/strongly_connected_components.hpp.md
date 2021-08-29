---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/transpose_graph.hpp
    title: graph/transpose_graph.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy:
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
    document_title: "strongly connected components decomposition, Kosaraju's algorithm\
      \ / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"graph/strongly_connected_components.hpp\"\n#include <functional>\n\
    #include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 4 \"\
    graph/transpose_graph.hpp\"\n\n/**\n * @param g is an adjacent list of a digraph\n\
    \ * @note $O(V + E)$\n * @see https://en.wikipedia.org/wiki/Transpose_graph\n\
    \ */\nstd::vector<std::vector<int> > make_transpose_graph(std::vector<std::vector<int>\
    \ > const & g) {\n    int n = g.size();\n    std::vector<std::vector<int> > h(n);\n\
    \    REP (i, n) {\n        for (int j : g[i]) {\n            h[j].push_back(i);\n\
    \        }\n    }\n    return h;\n}\n#line 7 \"graph/strongly_connected_components.hpp\"\
    \n\n/**\n * @brief strongly connected components decomposition, Kosaraju's algorithm\
    \ / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @return the pair (the number\
    \ k of components, the function from vertices of g to components)\n * @param g\
    \ is an adjacent list of a digraph\n * @param g_rev is the transpose graph of\
    \ g\n * @note $O(V + E)$\n */\nstd::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const\
    \ std::vector<std::vector<int> > & g, const std::vector<std::vector<int> > & g_rev)\
    \ {\n    int n = g.size();\n    std::vector<int> acc; {\n        std::vector<bool>\
    \ used(n);\n        std::function<void (int)> dfs = [&](int i) {\n           \
    \ used[i] = true;\n            for (int j : g[i]) if (not used[j]) dfs(j);\n \
    \           acc.push_back(i);\n        };\n        REP (i,n) if (not used[i])\
    \ dfs(i);\n        reverse(ALL(acc));\n    }\n    int size = 0;\n    std::vector<int>\
    \ component_of(n); {\n        std::vector<bool> used(n);\n        std::function<void\
    \ (int)> rdfs = [&](int i) {\n            used[i] = true;\n            component_of[i]\
    \ = size;\n            for (int j : g_rev[i]) if (not used[j]) rdfs(j);\n    \
    \    };\n        for (int i : acc) if (not used[i]) {\n            rdfs(i);\n\
    \            ++ size;\n        }\n    }\n    return { size, move(component_of)\
    \ };\n}\n\nstd::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const\
    \ std::vector<std::vector<int> > & g) {\n    return decompose_to_strongly_connected_components(g,\
    \ make_transpose_graph(g));\n}\n"
  code: "#pragma once\n#include <functional>\n#include <utility>\n#include <vector>\n\
    #include \"../graph/transpose_graph.hpp\"\n#include \"../utils/macros.hpp\"\n\n\
    /**\n * @brief strongly connected components decomposition, Kosaraju's algorithm\
    \ / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @return the pair (the number\
    \ k of components, the function from vertices of g to components)\n * @param g\
    \ is an adjacent list of a digraph\n * @param g_rev is the transpose graph of\
    \ g\n * @note $O(V + E)$\n */\nstd::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const\
    \ std::vector<std::vector<int> > & g, const std::vector<std::vector<int> > & g_rev)\
    \ {\n    int n = g.size();\n    std::vector<int> acc; {\n        std::vector<bool>\
    \ used(n);\n        std::function<void (int)> dfs = [&](int i) {\n           \
    \ used[i] = true;\n            for (int j : g[i]) if (not used[j]) dfs(j);\n \
    \           acc.push_back(i);\n        };\n        REP (i,n) if (not used[i])\
    \ dfs(i);\n        reverse(ALL(acc));\n    }\n    int size = 0;\n    std::vector<int>\
    \ component_of(n); {\n        std::vector<bool> used(n);\n        std::function<void\
    \ (int)> rdfs = [&](int i) {\n            used[i] = true;\n            component_of[i]\
    \ = size;\n            for (int j : g_rev[i]) if (not used[j]) rdfs(j);\n    \
    \    };\n        for (int i : acc) if (not used[i]) {\n            rdfs(i);\n\
    \            ++ size;\n        }\n    }\n    return { size, move(component_of)\
    \ };\n}\n\nstd::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const\
    \ std::vector<std::vector<int> > & g) {\n    return decompose_to_strongly_connected_components(g,\
    \ make_transpose_graph(g));\n}\n"
  dependsOn:
  - graph/transpose_graph.hpp
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/strongly_connected_components.hpp
  requiredBy:
  - utils/two_satisfiability.hpp
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/strongly_connected_components.yosupo.test.cpp
  - utils/two_satisfiability.yosupo.test.cpp
documentation_of: graph/strongly_connected_components.hpp
layout: document
redirect_from:
- /library/graph/strongly_connected_components.hpp
- /library/graph/strongly_connected_components.hpp.html
title: "strongly connected components decomposition, Kosaraju's algorithm / \u5F37\
  \u9023\u7D50\u6210\u5206\u5206\u89E3"
---
