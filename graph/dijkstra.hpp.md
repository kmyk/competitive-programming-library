---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Dijkstra ($O((E + V) \log V)$)
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include <cstdint>\n#include <numeric>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n/**\n * @brief Dijkstra\
    \ ($O((E + V) \\log V)$)\n */\ntemplate <class T = int64_t>\nstd::vector<T> dijkstra(std::vector<std::vector<std::pair<int,\
    \ T> > > const & g, int root) {\n    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());\n\
    \    std::priority_queue<std::pair<T, int> > que;\n    dist[root] = 0;\n    que.emplace(-\
    \ dist[root], root);\n    while (not que.empty()) {\n        T dist_x; int x;\
    \ std::tie(dist_x, x) = que.top(); que.pop();\n        if (dist[x] < - dist_x)\
    \ continue;\n        for (auto it : g[x]) {\n            int y; T cost; std::tie(y,\
    \ cost) = it;\n            if (- dist_x + cost < dist[y]) {\n                dist[y]\
    \ = - dist_x + cost;\n                que.emplace(dist_x - cost, y);\n       \
    \     }\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <numeric>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief Dijkstra ($O((E + V) \\\
    log V)$)\n */\ntemplate <class T = int64_t>\nstd::vector<T> dijkstra(std::vector<std::vector<std::pair<int,\
    \ T> > > const & g, int root) {\n    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());\n\
    \    std::priority_queue<std::pair<T, int> > que;\n    dist[root] = 0;\n    que.emplace(-\
    \ dist[root], root);\n    while (not que.empty()) {\n        T dist_x; int x;\
    \ std::tie(dist_x, x) = que.top(); que.pop();\n        if (dist[x] < - dist_x)\
    \ continue;\n        for (auto it : g[x]) {\n            int y; T cost; std::tie(y,\
    \ cost) = it;\n            if (- dist_x + cost < dist[y]) {\n                dist[y]\
    \ = - dist_x + cost;\n                que.emplace(dist_x - cost, y);\n       \
    \     }\n        }\n    }\n    return dist;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.yukicoder-1065.test.cpp
    title: graph/dijkstra.yukicoder-1065.test.cpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2020-05-29 23:50:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - graph/dijkstra.yukicoder-1065.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: Dijkstra ($O((E + V) \log V)$)
---
