---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: minimum-cost flow with primal-dual method
    links: []
  bundledCode: "#line 1 \"old/minimum-cost-flow.inc.cpp\"\ntemplate <class T>\nstruct\
    \ edge { int to; T cap, cost; int rev; };\ntemplate <class T>\nvoid add_edge(vector<vector<edge<T>\
    \ > > & graph, int from, int to, T cap, T cost) {\n    graph[from].push_back((edge<T>)\
    \ {   to, cap,  cost, int(graph[  to].size())     });\n    graph[  to].push_back((edge<T>)\
    \ { from,  0, - cost, int(graph[from].size()) - 1 });\n}\n/**\n * @brief minimum-cost\
    \ flow with primal-dual method\n * @note mainly O(V^2UC) for U is the sum of capacities\
    \ and C is the sum of costs. and additional O(VE) if negative edges exist\n */\n\
    template <class T>\nT min_cost_flow_destructive(int src, int dst, T flow, vector<vector<edge<T>\
    \ > > & graph) {\n    T result = 0;\n    vector<T> potential(graph.size());\n\
    \    if (0 < flow) { // initialize potential when negative edges exist (slow).\
    \ you can remove this if unnecessary\n        fill(ALL(potential), numeric_limits<T>::max());\n\
    \        potential[src] = 0;\n        while (true) { // Bellman-Ford algorithm\n\
    \            bool updated = false;\n            REP (e_from, graph.size()) for\
    \ (auto & e : graph[e_from]) if (e.cap) {\n                if (potential[e_from]\
    \ == numeric_limits<T>::max()) continue;\n                if (potential[e.to]\
    \ > potential[e_from] + e.cost) {\n                    potential[e.to] = potential[e_from]\
    \ + e.cost; // min\n                    updated = true;\n                }\n \
    \           }\n            if (not updated) break;\n        }\n    }\n    while\
    \ (0 < flow) {\n        // update potential using dijkstra\n        vector<T>\
    \ distance(graph.size(), numeric_limits<T>::max()); // minimum distance\n    \
    \    vector<int> prev_v(graph.size()); // constitute a single-linked-list represents\
    \ the flow-path\n        vector<int> prev_e(graph.size());\n        { // initialize\
    \ distance and prev_{v,e}\n            reversed_priority_queue<pair<T, int> >\
    \ que; // distance * vertex\n            distance[src] = 0;\n            que.emplace(0,\
    \ src);\n            while (not que.empty()) { // Dijkstra's algorithm\n     \
    \           T d; int v; tie(d, v) = que.top(); que.pop();\n                if\
    \ (potential[v] == numeric_limits<T>::max()) continue; // for unreachable nodes\n\
    \                if (distance[v] < d) continue;\n                // look round\
    \ the vertex\n                REP (e_index, graph[v].size()) {\n             \
    \       // consider updating\n                    edge<T> e = graph[v][e_index];\n\
    \                    int w = e.to;\n                    if (potential[w] == numeric_limits<T>::max())\
    \ continue;\n                    T d1 = distance[v] + e.cost + potential[v] -\
    \ potential[w]; // updated distance\n                    if (0 < e.cap and d1\
    \ < distance[e.to]) {\n                        distance[w] = d1;\n           \
    \             prev_v[w] = v;\n                        prev_e[w] = e_index;\n \
    \                       que.emplace(d1, w);\n                    }\n         \
    \       }\n            }\n        }\n        if (distance[dst] == numeric_limits<T>::max())\
    \ return -1; // no such flow\n        REP (v, graph.size()) {\n            if\
    \ (potential[v] == numeric_limits<T>::max()) continue;\n            potential[v]\
    \ += distance[v];\n        }\n        // finish updating the potential\n     \
    \   // let flow on the src->dst minimum path\n        T delta = flow; // capacity\
    \ of the path\n        for (int v = dst; v != src; v = prev_v[v]) {\n        \
    \    chmin(delta, graph[prev_v[v]][prev_e[v]].cap);\n        }\n        flow -=\
    \ delta;\n        result += delta * potential[dst];\n        for (int v = dst;\
    \ v != src; v = prev_v[v]) {\n            edge<T> & e = graph[prev_v[v]][prev_e[v]];\
    \ // reference\n            e.cap -= delta;\n            graph[v][e.rev].cap +=\
    \ delta;\n        }\n    }\n    return result;\n}\n"
  code: "template <class T>\nstruct edge { int to; T cap, cost; int rev; };\ntemplate\
    \ <class T>\nvoid add_edge(vector<vector<edge<T> > > & graph, int from, int to,\
    \ T cap, T cost) {\n    graph[from].push_back((edge<T>) {   to, cap,  cost, int(graph[\
    \  to].size())     });\n    graph[  to].push_back((edge<T>) { from,  0, - cost,\
    \ int(graph[from].size()) - 1 });\n}\n/**\n * @brief minimum-cost flow with primal-dual\
    \ method\n * @note mainly O(V^2UC) for U is the sum of capacities and C is the\
    \ sum of costs. and additional O(VE) if negative edges exist\n */\ntemplate <class\
    \ T>\nT min_cost_flow_destructive(int src, int dst, T flow, vector<vector<edge<T>\
    \ > > & graph) {\n    T result = 0;\n    vector<T> potential(graph.size());\n\
    \    if (0 < flow) { // initialize potential when negative edges exist (slow).\
    \ you can remove this if unnecessary\n        fill(ALL(potential), numeric_limits<T>::max());\n\
    \        potential[src] = 0;\n        while (true) { // Bellman-Ford algorithm\n\
    \            bool updated = false;\n            REP (e_from, graph.size()) for\
    \ (auto & e : graph[e_from]) if (e.cap) {\n                if (potential[e_from]\
    \ == numeric_limits<T>::max()) continue;\n                if (potential[e.to]\
    \ > potential[e_from] + e.cost) {\n                    potential[e.to] = potential[e_from]\
    \ + e.cost; // min\n                    updated = true;\n                }\n \
    \           }\n            if (not updated) break;\n        }\n    }\n    while\
    \ (0 < flow) {\n        // update potential using dijkstra\n        vector<T>\
    \ distance(graph.size(), numeric_limits<T>::max()); // minimum distance\n    \
    \    vector<int> prev_v(graph.size()); // constitute a single-linked-list represents\
    \ the flow-path\n        vector<int> prev_e(graph.size());\n        { // initialize\
    \ distance and prev_{v,e}\n            reversed_priority_queue<pair<T, int> >\
    \ que; // distance * vertex\n            distance[src] = 0;\n            que.emplace(0,\
    \ src);\n            while (not que.empty()) { // Dijkstra's algorithm\n     \
    \           T d; int v; tie(d, v) = que.top(); que.pop();\n                if\
    \ (potential[v] == numeric_limits<T>::max()) continue; // for unreachable nodes\n\
    \                if (distance[v] < d) continue;\n                // look round\
    \ the vertex\n                REP (e_index, graph[v].size()) {\n             \
    \       // consider updating\n                    edge<T> e = graph[v][e_index];\n\
    \                    int w = e.to;\n                    if (potential[w] == numeric_limits<T>::max())\
    \ continue;\n                    T d1 = distance[v] + e.cost + potential[v] -\
    \ potential[w]; // updated distance\n                    if (0 < e.cap and d1\
    \ < distance[e.to]) {\n                        distance[w] = d1;\n           \
    \             prev_v[w] = v;\n                        prev_e[w] = e_index;\n \
    \                       que.emplace(d1, w);\n                    }\n         \
    \       }\n            }\n        }\n        if (distance[dst] == numeric_limits<T>::max())\
    \ return -1; // no such flow\n        REP (v, graph.size()) {\n            if\
    \ (potential[v] == numeric_limits<T>::max()) continue;\n            potential[v]\
    \ += distance[v];\n        }\n        // finish updating the potential\n     \
    \   // let flow on the src->dst minimum path\n        T delta = flow; // capacity\
    \ of the path\n        for (int v = dst; v != src; v = prev_v[v]) {\n        \
    \    chmin(delta, graph[prev_v[v]][prev_e[v]].cap);\n        }\n        flow -=\
    \ delta;\n        result += delta * potential[dst];\n        for (int v = dst;\
    \ v != src; v = prev_v[v]) {\n            edge<T> & e = graph[prev_v[v]][prev_e[v]];\
    \ // reference\n            e.cap -= delta;\n            graph[v][e.rev].cap +=\
    \ delta;\n        }\n    }\n    return result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/minimum-cost-flow.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/minimum-cost-flow.inc.cpp
layout: document
redirect_from:
- /library/old/minimum-cost-flow.inc.cpp
- /library/old/minimum-cost-flow.inc.cpp.html
title: minimum-cost flow with primal-dual method
---
