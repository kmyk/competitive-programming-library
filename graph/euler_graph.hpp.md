---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Eulerian cycle (\u7121\u5411, \u5FA9\u5143)"
    links: []
  bundledCode: "#line 2 \"graph/euler_graph.hpp\"\n#include <algorithm>\n#include\
    \ <tuple>\n#include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 7 \"graph/euler_graph.hpp\"\n\n/**\n * @param g must be an undirected graph.\
    \ Loops and multiple edges are acceptable.\n * @param root specifies the component\
    \ to find an Eulerian cycle\n * @return indices of edges. It's empty if g is not\
    \ a Eulerian graph.\n */\nstd::vector<int> find_eulerian_cycle_with_root(int n,\
    \ const std::vector<std::pair<int, int> > & edges, int root) {\n    int m = edges.size();\n\
    \    std::vector<std::vector<int> > g(n);\n    std::vector<int> degree(n);\n \
    \   REP (i, m) {\n        int x, y; std::tie(x, y) = edges[i];\n        g[x].push_back(i);\n\
    \        g[y].push_back(i);\n        ++ degree[x];\n        ++ degree[y];  //\
    \ This is required even if x == y\n    }\n\n    std::vector<int> order;\n    std::vector<bool>\
    \ used(m);\n    auto go = [&](auto && go, int x) -> bool {\n        if (degree[x]\
    \ % 2 != 0) {\n            return false;\n        }\n        while (not g[x].empty())\
    \ {\n            int i = g[x].back();\n            g[x].pop_back();\n        \
    \    if (not used[i]) {\n                used[i] = true;\n                int\
    \ y = x ^ edges[i].first ^ edges[i].second;\n                if (not go(go, y))\
    \ {\n                    return false;\n                }\n                order.push_back(i);\n\
    \            }\n        }\n        return true;\n    };\n    if (not go(go, root))\
    \ {\n        return std::vector<int>();  // not a Eulerian graph\n    }\n    return\
    \ order;\n}\n\n/**\n * @brief Eulerian cycle (\u7121\u5411, \u5FA9\u5143)\n *\
    \ @param g must be an undirected and connected graph.\n * @return indices of edges.\
    \ It's empty if g is not a Eulerian graph.\n */\nstd::vector<int> find_eulerian_cycle(int\
    \ n, const std::vector<std::pair<int, int> > & edges) {\n    auto order = find_eulerian_cycle_with_root(n,\
    \ edges, 0);\n    if (order.size() != edges.size()) {\n        return std::vector<int>();\n\
    \    }\n    return order;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n#include \"../utils/macros.hpp\"\n\n/**\n * @param g must be\
    \ an undirected graph. Loops and multiple edges are acceptable.\n * @param root\
    \ specifies the component to find an Eulerian cycle\n * @return indices of edges.\
    \ It's empty if g is not a Eulerian graph.\n */\nstd::vector<int> find_eulerian_cycle_with_root(int\
    \ n, const std::vector<std::pair<int, int> > & edges, int root) {\n    int m =\
    \ edges.size();\n    std::vector<std::vector<int> > g(n);\n    std::vector<int>\
    \ degree(n);\n    REP (i, m) {\n        int x, y; std::tie(x, y) = edges[i];\n\
    \        g[x].push_back(i);\n        g[y].push_back(i);\n        ++ degree[x];\n\
    \        ++ degree[y];  // This is required even if x == y\n    }\n\n    std::vector<int>\
    \ order;\n    std::vector<bool> used(m);\n    auto go = [&](auto && go, int x)\
    \ -> bool {\n        if (degree[x] % 2 != 0) {\n            return false;\n  \
    \      }\n        while (not g[x].empty()) {\n            int i = g[x].back();\n\
    \            g[x].pop_back();\n            if (not used[i]) {\n              \
    \  used[i] = true;\n                int y = x ^ edges[i].first ^ edges[i].second;\n\
    \                if (not go(go, y)) {\n                    return false;\n   \
    \             }\n                order.push_back(i);\n            }\n        }\n\
    \        return true;\n    };\n    if (not go(go, root)) {\n        return std::vector<int>();\
    \  // not a Eulerian graph\n    }\n    return order;\n}\n\n/**\n * @brief Eulerian\
    \ cycle (\u7121\u5411, \u5FA9\u5143)\n * @param g must be an undirected and connected\
    \ graph.\n * @return indices of edges. It's empty if g is not a Eulerian graph.\n\
    \ */\nstd::vector<int> find_eulerian_cycle(int n, const std::vector<std::pair<int,\
    \ int> > & edges) {\n    auto order = find_eulerian_cycle_with_root(n, edges,\
    \ 0);\n    if (order.size() != edges.size()) {\n        return std::vector<int>();\n\
    \    }\n    return order;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/euler_graph.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/euler_graph.hpp
layout: document
redirect_from:
- /library/graph/euler_graph.hpp
- /library/graph/euler_graph.hpp.html
title: "Eulerian cycle (\u7121\u5411, \u5FA9\u5143)"
---
