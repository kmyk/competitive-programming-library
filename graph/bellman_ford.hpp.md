---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.test.cpp
    title: graph/bellman_ford.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bellman-Ford algorithm
    links: []
  bundledCode: "#line 2 \"graph/bellman_ford.hpp\"\n#include <cassert>\n#include <climits>\n\
    #include <cstdint>\n#include <stack>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i)\
    \ < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n\
    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 10 \"graph/bellman_ford.hpp\"\n\n/**\n\
    \ * @brief Bellman-Ford algorithm\n * @note O(V E)\n * @arg g is a digraph with\
    \ possibly negative cost edges\n * @note INT64_MIN for negative loops\n * @note\
    \ INT64_MAX for unreachable nodes\n */\nstd::vector<int64_t> bellman_ford_shortest_path(int\
    \ root, std::vector<std::vector<std::pair<int, int64_t> > > const & g) {\n   \
    \ assert (not g.empty());\n    int n = g.size();\n    std::vector<int64_t> dist(n,\
    \ INT64_MAX);\n\n    // update n - 1 times\n    dist[root] = 0;\n    REP (iteration,\
    \ n - 1) {\n        REP (i, n) if (dist[i] != INT64_MAX) {\n            for (auto\
    \ edge : g[i]) {\n                int j; int64_t cost; std::tie(j, cost) = edge;\n\
    \                dist[j] = std::min(dist[j], dist[i] + cost);\n            }\n\
    \        }\n    }\n\n    // propagate effects of negative cycles\n    std::stack<int>\
    \ stk;\n    REP (i, n) if (dist[i] != INT64_MAX) {\n        stk.push(i);\n   \
    \ }\n    while (not stk.empty()) {\n        int i = stk.top();\n        stk.pop();\n\
    \        for (auto edge : g[i]) {\n            int j; int64_t cost; std::tie(j,\
    \ cost) = edge;\n            if (dist[j] != INT64_MIN) {\n                if (dist[i]\
    \ == INT64_MIN or dist[i] + cost < dist[j]) {\n                    dist[j] = INT64_MIN;\n\
    \                    stk.push(j);\n                }\n            }\n        }\n\
    \    }\n\n    return dist;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <climits>\n#include <cstdint>\n\
    #include <stack>\n#include <tuple>\n#include <utility>\n#include <vector>\n#include\
    \ \"utils/macros.hpp\"\n\n/**\n * @brief Bellman-Ford algorithm\n * @note O(V\
    \ E)\n * @arg g is a digraph with possibly negative cost edges\n * @note INT64_MIN\
    \ for negative loops\n * @note INT64_MAX for unreachable nodes\n */\nstd::vector<int64_t>\
    \ bellman_ford_shortest_path(int root, std::vector<std::vector<std::pair<int,\
    \ int64_t> > > const & g) {\n    assert (not g.empty());\n    int n = g.size();\n\
    \    std::vector<int64_t> dist(n, INT64_MAX);\n\n    // update n - 1 times\n \
    \   dist[root] = 0;\n    REP (iteration, n - 1) {\n        REP (i, n) if (dist[i]\
    \ != INT64_MAX) {\n            for (auto edge : g[i]) {\n                int j;\
    \ int64_t cost; std::tie(j, cost) = edge;\n                dist[j] = std::min(dist[j],\
    \ dist[i] + cost);\n            }\n        }\n    }\n\n    // propagate effects\
    \ of negative cycles\n    std::stack<int> stk;\n    REP (i, n) if (dist[i] !=\
    \ INT64_MAX) {\n        stk.push(i);\n    }\n    while (not stk.empty()) {\n \
    \       int i = stk.top();\n        stk.pop();\n        for (auto edge : g[i])\
    \ {\n            int j; int64_t cost; std::tie(j, cost) = edge;\n            if\
    \ (dist[j] != INT64_MIN) {\n                if (dist[i] == INT64_MIN or dist[i]\
    \ + cost < dist[j]) {\n                    dist[j] = INT64_MIN;\n            \
    \        stk.push(j);\n                }\n            }\n        }\n    }\n\n\
    \    return dist;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2019-12-20 06:12:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/bellman_ford.test.cpp
documentation_of: graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/graph/bellman_ford.hpp
- /library/graph/bellman_ford.hpp.html
title: Bellman-Ford algorithm
---
