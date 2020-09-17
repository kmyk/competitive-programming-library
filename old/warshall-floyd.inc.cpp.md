---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Warshall-Floyd algorithm
    links: []
  bundledCode: "#line 1 \"old/warshall-floyd.inc.cpp\"\n/**\n * @brief Warshall-Floyd\
    \ algorithm\n * @note O(n^3)\n * @param g is a digraph\n */\nvector<vector<ll>\
    \ > warshall_floyd(vector<vector<pair<int, ll> > > const & g) {\n    int n = g.size();\n\
    \    vector<vector<ll> > dist(n, vector<ll>(n, LLONG_MAX));\n    REP (i, n) {\n\
    \        dist[i][i] = 0;\n        for (auto edge : g[i]) {\n            int j;\
    \ ll cost; tie(j, cost) = edge;\n            dist[i][j] = cost;\n        }\n \
    \   }\n    REP (k, n) {\n        REP (i, n) if (dist[i][k] != LLONG_MAX) {\n \
    \           REP (j, n) if (dist[k][j] != LLONG_MAX) {\n                chmin(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n            }\n        }\n    }\n    return dist;\n\
    }\n\n/**\n * @brief Warshall-Floyd algorithm for connectivity\n */\nvector<vector<bool>\
    \ > warshall_floyd(vector<vector<int> > const & g) {\n    int n = g.size();\n\
    \    vector<vector<bool> > conn(n, vector<bool>(n));\n    REP (i, n) {\n     \
    \   conn[i][i] = true;\n        for (int j : g[i]) {\n            conn[i][j] =\
    \ true;\n        }\n    }\n    REP (k, n) REP (i, n) REP (j, n) {\n        if\
    \ (conn[i][k] and conn[k][j]) {\n            conn[i][j] = true;\n        }\n \
    \   }\n    return conn;\n}\n"
  code: "/**\n * @brief Warshall-Floyd algorithm\n * @note O(n^3)\n * @param g is\
    \ a digraph\n */\nvector<vector<ll> > warshall_floyd(vector<vector<pair<int, ll>\
    \ > > const & g) {\n    int n = g.size();\n    vector<vector<ll> > dist(n, vector<ll>(n,\
    \ LLONG_MAX));\n    REP (i, n) {\n        dist[i][i] = 0;\n        for (auto edge\
    \ : g[i]) {\n            int j; ll cost; tie(j, cost) = edge;\n            dist[i][j]\
    \ = cost;\n        }\n    }\n    REP (k, n) {\n        REP (i, n) if (dist[i][k]\
    \ != LLONG_MAX) {\n            REP (j, n) if (dist[k][j] != LLONG_MAX) {\n   \
    \             chmin(dist[i][j], dist[i][k] + dist[k][j]);\n            }\n   \
    \     }\n    }\n    return dist;\n}\n\n/**\n * @brief Warshall-Floyd algorithm\
    \ for connectivity\n */\nvector<vector<bool> > warshall_floyd(vector<vector<int>\
    \ > const & g) {\n    int n = g.size();\n    vector<vector<bool> > conn(n, vector<bool>(n));\n\
    \    REP (i, n) {\n        conn[i][i] = true;\n        for (int j : g[i]) {\n\
    \            conn[i][j] = true;\n        }\n    }\n    REP (k, n) REP (i, n) REP\
    \ (j, n) {\n        if (conn[i][k] and conn[k][j]) {\n            conn[i][j] =\
    \ true;\n        }\n    }\n    return conn;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/warshall-floyd.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/warshall-floyd.inc.cpp
layout: document
redirect_from:
- /library/old/warshall-floyd.inc.cpp
- /library/old/warshall-floyd.inc.cpp.html
title: Warshall-Floyd algorithm
---
