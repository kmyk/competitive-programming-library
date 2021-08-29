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
    document_title: "minimum cost flow / \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual)"
    links: []
  bundledCode: "#line 2 \"graph/minimum-cost-flow.hpp\"\n#include <numeric>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 7 \"graph/minimum-cost-flow.hpp\"\n\nnamespace min_cost_flow {\n\ntemplate <class\
    \ T>\nstruct edge { int to; T cap, cost; int rev; };\n\ntemplate <class T>\nvoid\
    \ add_edge(std::vector<std::vector<edge<T> > > & graph, int from, int to, T cap,\
    \ T cost) {\n    graph[from].push_back((edge<T>) {   to, cap,  cost, int(graph[\
    \  to].size())     });\n    graph[  to].push_back((edge<T>) { from,  0, - cost,\
    \ int(graph[from].size()) - 1 });\n}\n\ntemplate <class T>\nusing reversed_priority_queue\
    \ = std::priority_queue<T, std::vector<T>, std::greater<T> >;\n\n/**\n * @brief\
    \ minimum cost flow / \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual)\n * @note mainly\
    \ $O(V^2 U C)$ for U is the sum of capacities and $C$ is the sum of costs. and\
    \ additional $O(V E)$ if negative edges exist\n */\ntemplate <class T>\nT run_destructive(std::vector<std::vector<edge<T>\
    \ > > & graph, int src, int dst, T flow) {\n\n    T result = 0;\n    std::vector<T>\
    \ potential(graph.size());\n    if (0 < flow) {  // initialize potential when\
    \ negative edges exist (slow). you can remove this if unnecessary\n        std::fill(ALL(potential),\
    \ std::numeric_limits<T>::max());\n        potential[src] = 0;\n        while\
    \ (true) {  // Bellman-Ford algorithm\n            bool updated = false;\n   \
    \         REP (e_from, graph.size()) for (auto & e : graph[e_from]) if (e.cap)\
    \ {\n                if (potential[e_from] == std::numeric_limits<T>::max()) continue;\n\
    \                if (potential[e.to] > potential[e_from] + e.cost) {\n       \
    \             potential[e.to] = potential[e_from] + e.cost;  // min\n        \
    \            updated = true;\n                }\n            }\n            if\
    \ (not updated) break;\n        }\n    }\n\n    while (0 < flow) {\n        //\
    \ update potential using dijkstra\n        std::vector<T> distance(graph.size(),\
    \ std::numeric_limits<T>::max());  // minimum distance\n        std::vector<int>\
    \ prev_v(graph.size());  // constitute a single-linked-list represents the flow-path\n\
    \        std::vector<int> prev_e(graph.size());\n        {  // initialize distance\
    \ and prev_{v,e}\n            reversed_priority_queue<std::pair<T, int> > que;\
    \  // distance * vertex\n            distance[src] = 0;\n            que.emplace(0,\
    \ src);\n            while (not que.empty()) {  // Dijkstra's algorithm\n    \
    \            T d; int v; std::tie(d, v) = que.top(); que.pop();\n            \
    \    if (potential[v] == std::numeric_limits<T>::max()) continue;  // for unreachable\
    \ nodes\n                if (distance[v] < d) continue;\n                // look\
    \ round the vertex\n                REP (e_index, graph[v].size()) {\n       \
    \             // consider updating\n                    edge<T> e = graph[v][e_index];\n\
    \                    int w = e.to;\n                    if (potential[w] == std::numeric_limits<T>::max())\
    \ continue;\n                    T d1 = distance[v] + e.cost + potential[v] -\
    \ potential[w];  // updated distance\n                    if (0 < e.cap and d1\
    \ < distance[e.to]) {\n                        distance[w] = d1;\n           \
    \             prev_v[w] = v;\n                        prev_e[w] = e_index;\n \
    \                       que.emplace(d1, w);\n                    }\n         \
    \       }\n            }\n        }\n        if (distance[dst] == std::numeric_limits<T>::max())\
    \ return -1;  // no such flow\n        REP (v, graph.size()) {\n            if\
    \ (potential[v] == std::numeric_limits<T>::max()) continue;\n            potential[v]\
    \ += distance[v];\n        }\n\n        // finish updating the potential\n   \
    \     // let flow on the src->dst minimum path\n        T delta = flow; // capacity\
    \ of the path\n        for (int v = dst; v != src; v = prev_v[v]) {\n        \
    \    delta = std::min(delta, graph[prev_v[v]][prev_e[v]].cap);\n        }\n  \
    \      flow -= delta;\n        result += delta * potential[dst];\n        for\
    \ (int v = dst; v != src; v = prev_v[v]) {\n            edge<T> & e = graph[prev_v[v]][prev_e[v]];\
    \  // reference\n            e.cap -= delta;\n            graph[v][e.rev].cap\
    \ += delta;\n        }\n    }\n    return result;\n}\n\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n#include \"../utils/macros.hpp\"\n\nnamespace min_cost_flow\
    \ {\n\ntemplate <class T>\nstruct edge { int to; T cap, cost; int rev; };\n\n\
    template <class T>\nvoid add_edge(std::vector<std::vector<edge<T> > > & graph,\
    \ int from, int to, T cap, T cost) {\n    graph[from].push_back((edge<T>) {  \
    \ to, cap,  cost, int(graph[  to].size())     });\n    graph[  to].push_back((edge<T>)\
    \ { from,  0, - cost, int(graph[from].size()) - 1 });\n}\n\ntemplate <class T>\n\
    using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>\
    \ >;\n\n/**\n * @brief minimum cost flow / \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual)\n\
    \ * @note mainly $O(V^2 U C)$ for U is the sum of capacities and $C$ is the sum\
    \ of costs. and additional $O(V E)$ if negative edges exist\n */\ntemplate <class\
    \ T>\nT run_destructive(std::vector<std::vector<edge<T> > > & graph, int src,\
    \ int dst, T flow) {\n\n    T result = 0;\n    std::vector<T> potential(graph.size());\n\
    \    if (0 < flow) {  // initialize potential when negative edges exist (slow).\
    \ you can remove this if unnecessary\n        std::fill(ALL(potential), std::numeric_limits<T>::max());\n\
    \        potential[src] = 0;\n        while (true) {  // Bellman-Ford algorithm\n\
    \            bool updated = false;\n            REP (e_from, graph.size()) for\
    \ (auto & e : graph[e_from]) if (e.cap) {\n                if (potential[e_from]\
    \ == std::numeric_limits<T>::max()) continue;\n                if (potential[e.to]\
    \ > potential[e_from] + e.cost) {\n                    potential[e.to] = potential[e_from]\
    \ + e.cost;  // min\n                    updated = true;\n                }\n\
    \            }\n            if (not updated) break;\n        }\n    }\n\n    while\
    \ (0 < flow) {\n        // update potential using dijkstra\n        std::vector<T>\
    \ distance(graph.size(), std::numeric_limits<T>::max());  // minimum distance\n\
    \        std::vector<int> prev_v(graph.size());  // constitute a single-linked-list\
    \ represents the flow-path\n        std::vector<int> prev_e(graph.size());\n \
    \       {  // initialize distance and prev_{v,e}\n            reversed_priority_queue<std::pair<T,\
    \ int> > que;  // distance * vertex\n            distance[src] = 0;\n        \
    \    que.emplace(0, src);\n            while (not que.empty()) {  // Dijkstra's\
    \ algorithm\n                T d; int v; std::tie(d, v) = que.top(); que.pop();\n\
    \                if (potential[v] == std::numeric_limits<T>::max()) continue;\
    \  // for unreachable nodes\n                if (distance[v] < d) continue;\n\
    \                // look round the vertex\n                REP (e_index, graph[v].size())\
    \ {\n                    // consider updating\n                    edge<T> e =\
    \ graph[v][e_index];\n                    int w = e.to;\n                    if\
    \ (potential[w] == std::numeric_limits<T>::max()) continue;\n                \
    \    T d1 = distance[v] + e.cost + potential[v] - potential[w];  // updated distance\n\
    \                    if (0 < e.cap and d1 < distance[e.to]) {\n              \
    \          distance[w] = d1;\n                        prev_v[w] = v;\n       \
    \                 prev_e[w] = e_index;\n                        que.emplace(d1,\
    \ w);\n                    }\n                }\n            }\n        }\n  \
    \      if (distance[dst] == std::numeric_limits<T>::max()) return -1;  // no such\
    \ flow\n        REP (v, graph.size()) {\n            if (potential[v] == std::numeric_limits<T>::max())\
    \ continue;\n            potential[v] += distance[v];\n        }\n\n        //\
    \ finish updating the potential\n        // let flow on the src->dst minimum path\n\
    \        T delta = flow; // capacity of the path\n        for (int v = dst; v\
    \ != src; v = prev_v[v]) {\n            delta = std::min(delta, graph[prev_v[v]][prev_e[v]].cap);\n\
    \        }\n        flow -= delta;\n        result += delta * potential[dst];\n\
    \        for (int v = dst; v != src; v = prev_v[v]) {\n            edge<T> & e\
    \ = graph[prev_v[v]][prev_e[v]];  // reference\n            e.cap -= delta;\n\
    \            graph[v][e.rev].cap += delta;\n        }\n    }\n    return result;\n\
    }\n\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/minimum-cost-flow.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/minimum-cost-flow.hpp
layout: document
redirect_from:
- /library/graph/minimum-cost-flow.hpp
- /library/graph/minimum-cost-flow.hpp.html
title: "minimum cost flow / \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual)"
---
