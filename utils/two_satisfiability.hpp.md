---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "strongly connected components decomposition, Kosaraju's algorithm / \u5F37\
      \u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/transpose_graph.hpp
    title: graph/transpose_graph.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: utils/two_satisfiability.yosupo.test.cpp
    title: utils/two_satisfiability.yosupo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: 2-SAT ($O(N)$)
    links: []
  bundledCode: "#line 2 \"utils/two_satisfiability.hpp\"\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"graph/strongly_connected_components.hpp\"\
    \n#include <functional>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int\
    \ i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i)\
    \ < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 4 \"graph/transpose_graph.hpp\"\
    \n\n/**\n * @param g is an adjacent list of a digraph\n * @note $O(V + E)$\n *\
    \ @see https://en.wikipedia.org/wiki/Transpose_graph\n */\nstd::vector<std::vector<int>\
    \ > make_transpose_graph(std::vector<std::vector<int> > const & g) {\n    int\
    \ n = g.size();\n    std::vector<std::vector<int> > h(n);\n    REP (i, n) {\n\
    \        for (int j : g[i]) {\n            h[j].push_back(i);\n        }\n   \
    \ }\n    return h;\n}\n#line 7 \"graph/strongly_connected_components.hpp\"\n\n\
    /**\n * @brief strongly connected components decomposition, Kosaraju's algorithm\
    \ / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @return the pair (the number\
    \ k of components, the function from vertices of g to components)\n * @param g\
    \ is an adjacent list of a digraph\n * @param g_rev is the transpose graph of\
    \ g\n * @note $O(V + E)$\n */\nstd::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const\
    \ std::vector<std::vector<int> > & g, const std::vector<std::vector<int> > & g_rev)\
    \ {\n    int n = g.size();\n    std::vector<int> acc(n); {\n        std::vector<bool>\
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
    \ make_transpose_graph(g));\n}\n#line 6 \"utils/two_satisfiability.hpp\"\n\n/**\n\
    \ * @brief 2-SAT ($O(N)$)\n * @param n is the number of variables\n * @param cnf\
    \ is a proposition in a conjunctive normal form. Each literal is expressed as\
    \ number $x$ s.t. $1 \\le \\vert x \\vert \\le n$\n * @return a vector with the\
    \ length $n$ if SAT. It's empty if UNSAT.\n */\nstd::vector<bool> compute_two_satisfiability(int\
    \ n, const std::vector<std::pair<int, int> > & cnf) {\n    // make digraph\n \
    \   std::vector<std::vector<int> > g(2 * n);\n    auto index = [&](int x) {\n\
    \        assert (x != 0 and abs(x) <= n);\n        return x > 0 ? x - 1 : n -\
    \ x - 1;\n    };\n    for (auto it : cnf) {\n        int x, y; std::tie(x, y)\
    \ = it;  // x or y\n        g[index(- x)].push_back(index(y));  // not x implies\
    \ y\n        g[index(- y)].push_back(index(x));  // not y implies x\n    }\n\n\
    \    // do SCC\n    std::vector<int> component = decompose_to_strongly_connected_components(g).second;\n\
    \    std::vector<bool> valuation(n);\n    REP3 (x, 1, n + 1) {\n        if (component[index(x)]\
    \ == component[index(- x)]) {  // x iff not x\n            return std::vector<bool>();\
    \  // unsat\n        }\n        valuation[x - 1] = component[index(x)] > component[index(-\
    \ x)];  // use components which indices are large\n    }\n    return valuation;\n\
    }\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"graph/strongly_connected_components.hpp\"\n\n/**\n * @brief 2-SAT ($O(N)$)\n\
    \ * @param n is the number of variables\n * @param cnf is a proposition in a conjunctive\
    \ normal form. Each literal is expressed as number $x$ s.t. $1 \\le \\vert x \\\
    vert \\le n$\n * @return a vector with the length $n$ if SAT. It's empty if UNSAT.\n\
    \ */\nstd::vector<bool> compute_two_satisfiability(int n, const std::vector<std::pair<int,\
    \ int> > & cnf) {\n    // make digraph\n    std::vector<std::vector<int> > g(2\
    \ * n);\n    auto index = [&](int x) {\n        assert (x != 0 and abs(x) <= n);\n\
    \        return x > 0 ? x - 1 : n - x - 1;\n    };\n    for (auto it : cnf) {\n\
    \        int x, y; std::tie(x, y) = it;  // x or y\n        g[index(- x)].push_back(index(y));\
    \  // not x implies y\n        g[index(- y)].push_back(index(x));  // not y implies\
    \ x\n    }\n\n    // do SCC\n    std::vector<int> component = decompose_to_strongly_connected_components(g).second;\n\
    \    std::vector<bool> valuation(n);\n    REP3 (x, 1, n + 1) {\n        if (component[index(x)]\
    \ == component[index(- x)]) {  // x iff not x\n            return std::vector<bool>();\
    \  // unsat\n        }\n        valuation[x - 1] = component[index(x)] > component[index(-\
    \ x)];  // use components which indices are large\n    }\n    return valuation;\n\
    }\n"
  dependsOn:
  - graph/strongly_connected_components.hpp
  - graph/transpose_graph.hpp
  - utils/macros.hpp
  isVerificationFile: false
  path: utils/two_satisfiability.hpp
  requiredBy: []
  timestamp: '2020-06-12 22:07:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - utils/two_satisfiability.yosupo.test.cpp
documentation_of: utils/two_satisfiability.hpp
layout: document
redirect_from:
- /library/utils/two_satisfiability.hpp
- /library/utils/two_satisfiability.hpp.html
title: 2-SAT ($O(N)$)
---
