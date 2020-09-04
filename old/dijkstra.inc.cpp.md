---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"old/dijkstra.inc.cpp\"\n/**\n * @note O((E + V) log V)\n\
    \ */\nvector<ll> dijkstra(vector<vector<pair<int, ll> > > const & g, int root)\
    \ {\n    vector<ll> dist(g.size(), LLONG_MAX);\n    priority_queue<pair<ll, int>\
    \ > que;\n    dist[root] = 0;\n    que.emplace(- dist[root], root);\n    while\
    \ (not que.empty()) {\n        ll dist_i; int i; tie(dist_i, i) = que.top(); que.pop();\n\
    \        if (dist[i] < - dist_i) continue;\n        for (auto it : g[i]) {\n \
    \           int j; ll cost; tie(j, cost) = it;\n            if (- dist_i + cost\
    \ < dist[j]) {\n                dist[j] = - dist_i + cost;\n                que.emplace(dist_i\
    \ - cost, j);\n            }\n        }\n    }\n    return dist;\n}\n\ntemplate\
    \ <typename T>\nvector<T> original_dijkstra(vector<vector<pair<int, T> > > const\
    \ & g, int start, T inf) { // O(V^2)\n    int n = g.size();\n    vector<double>\
    \ dist(n, inf);\n    vector<int> ixs(n); whole(iota, ixs, 0);\n    dist[start]\
    \ = 0;\n    repeat (loop,n) {\n        int i; {\n            auto it = whole(min_element,\
    \ ixs, [&](int i, int j) { return dist[i] < dist[j]; });\n            i = *it;\n\
    \            *it = ixs.back();\n            ixs.pop_back();\n        }\n     \
    \   for (auto it : g[i]) {\n            int j; T cost; tie(j, cost) = it;\n  \
    \          setmin(dist[j], dist[i] + cost);\n        }\n    }\n    return dist;\n\
    }\n\n/**\n * @note generic one\n */\ntemplate <class T, class Func>\nvector<T>\
    \ run_dijkstra(int n, int src, Func iterate) {\n    vector<T> dist(n, numeric_limits<T>::max());\n\
    \    priority_queue<pair<T, int> > que;\n    dist[src] = 0;\n    que.emplace(-\
    \ dist[src], src);\n    while (not que.empty()) {\n        T dist_i; int i; tie(dist_i,\
    \ i) = que.top(); que.pop();\n        if (dist[i] < - dist_i) continue;\n    \
    \    iterate(i, [&](int j, T cost) {\n            if (- dist_i + cost < dist[j])\
    \ {\n                dist[j] = - dist_i + cost;\n                que.emplace(dist_i\
    \ - cost, j);\n            }\n        });\n    }\n    return dist;\n}\n\ntemplate\
    \ <class T, class Func>\nvector<int> reconstruct_dijkstra(int n, int src, int\
    \ dst, vector<T> const & dist, Func iterate) {\n}\n\ntemplate <class T, class\
    \ Func>\nvector<int> reconstruct_edges_dijkstra(int n, int src, int dst, vector<T>\
    \ const & dist, Func iterate) {\n    vector<int> edges;\n    int i = dst;\n  \
    \  while (i != src) {\n        int next = -1;\n        int next_edge = -1;\n \
    \       iterate(i, [&](int j, int edge, T cost) {\n            if (dist[i] ==\
    \ dist[j] + cost) {\n                next = j;\n                next_edge = edge;\n\
    \            }\n        });\n        assert (next != -1);\n        i = next;\n\
    \        edges.push_back(next_edge);\n    }\n    reverse(ALL(edges));\n    return\
    \ edges;\n}\n"
  code: "/**\n * @note O((E + V) log V)\n */\nvector<ll> dijkstra(vector<vector<pair<int,\
    \ ll> > > const & g, int root) {\n    vector<ll> dist(g.size(), LLONG_MAX);\n\
    \    priority_queue<pair<ll, int> > que;\n    dist[root] = 0;\n    que.emplace(-\
    \ dist[root], root);\n    while (not que.empty()) {\n        ll dist_i; int i;\
    \ tie(dist_i, i) = que.top(); que.pop();\n        if (dist[i] < - dist_i) continue;\n\
    \        for (auto it : g[i]) {\n            int j; ll cost; tie(j, cost) = it;\n\
    \            if (- dist_i + cost < dist[j]) {\n                dist[j] = - dist_i\
    \ + cost;\n                que.emplace(dist_i - cost, j);\n            }\n   \
    \     }\n    }\n    return dist;\n}\n\ntemplate <typename T>\nvector<T> original_dijkstra(vector<vector<pair<int,\
    \ T> > > const & g, int start, T inf) { // O(V^2)\n    int n = g.size();\n   \
    \ vector<double> dist(n, inf);\n    vector<int> ixs(n); whole(iota, ixs, 0);\n\
    \    dist[start] = 0;\n    repeat (loop,n) {\n        int i; {\n            auto\
    \ it = whole(min_element, ixs, [&](int i, int j) { return dist[i] < dist[j]; });\n\
    \            i = *it;\n            *it = ixs.back();\n            ixs.pop_back();\n\
    \        }\n        for (auto it : g[i]) {\n            int j; T cost; tie(j,\
    \ cost) = it;\n            setmin(dist[j], dist[i] + cost);\n        }\n    }\n\
    \    return dist;\n}\n\n/**\n * @note generic one\n */\ntemplate <class T, class\
    \ Func>\nvector<T> run_dijkstra(int n, int src, Func iterate) {\n    vector<T>\
    \ dist(n, numeric_limits<T>::max());\n    priority_queue<pair<T, int> > que;\n\
    \    dist[src] = 0;\n    que.emplace(- dist[src], src);\n    while (not que.empty())\
    \ {\n        T dist_i; int i; tie(dist_i, i) = que.top(); que.pop();\n       \
    \ if (dist[i] < - dist_i) continue;\n        iterate(i, [&](int j, T cost) {\n\
    \            if (- dist_i + cost < dist[j]) {\n                dist[j] = - dist_i\
    \ + cost;\n                que.emplace(dist_i - cost, j);\n            }\n   \
    \     });\n    }\n    return dist;\n}\n\ntemplate <class T, class Func>\nvector<int>\
    \ reconstruct_dijkstra(int n, int src, int dst, vector<T> const & dist, Func iterate)\
    \ {\n}\n\ntemplate <class T, class Func>\nvector<int> reconstruct_edges_dijkstra(int\
    \ n, int src, int dst, vector<T> const & dist, Func iterate) {\n    vector<int>\
    \ edges;\n    int i = dst;\n    while (i != src) {\n        int next = -1;\n \
    \       int next_edge = -1;\n        iterate(i, [&](int j, int edge, T cost) {\n\
    \            if (dist[i] == dist[j] + cost) {\n                next = j;\n   \
    \             next_edge = edge;\n            }\n        });\n        assert (next\
    \ != -1);\n        i = next;\n        edges.push_back(next_edge);\n    }\n   \
    \ reverse(ALL(edges));\n    return edges;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/dijkstra.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/dijkstra.inc.cpp
layout: document
redirect_from:
- /library/old/dijkstra.inc.cpp
- /library/old/dijkstra.inc.cpp.html
title: old/dijkstra.inc.cpp
---
