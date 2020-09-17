---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: compute the distances from root
    links: []
  bundledCode: "#line 1 \"old/breadth-first-search.inc.cpp\"\n/**\n * @brief compute\
    \ the distances from root\n * @note O(n)\n * @arg g is a digraph\n * @note loops\
    \ and double edges are allowed\n */\nvector<int> breadth_first_search(int root,\
    \ vector<vector<int> > const & g) {\n    int n = g.size();\n    vector<int> dist(n,\
    \ INT_MAX);\n    queue<int> que;\n    dist[root] = 0;\n    que.push(root);\n \
    \   while (not que.empty()) {\n        int i = que.front(); que.pop();\n     \
    \   for (int j : g[i]) if (dist[j] == INT_MAX) {\n            dist[j] = dist[i]\
    \ + 1;\n            que.push(j);\n        }\n    }\n    return dist;\n}\n\n/**\n\
    \ * @brief 0-1 BFS\n * @arg g is a weighted digraph whose weights are 0 or 1\n\
    \ * @note loops and double edges are allowed\n */\nvector<int> zero_one_breadth_first_search(int\
    \ root, vector<vector<pair<int, bool> > > const & g) {\n    int n = g.size();\n\
    \    vector<int> dist(n, INT_MAX);\n    deque<pair<int, int> > que;\n    dist[root]\
    \ = 0;\n    que.emplace_back(root, dist[root]);\n    while (not que.empty()) {\n\
    \        int i, dist_i; tie(i, dist_i) = que.front(); que.pop_front();\n     \
    \   if (dist[i] < dist_i) continue;\n        for (auto edge : g[i]) {\n      \
    \      int j; bool cost; tie(j, cost) = edge;\n            if (dist[i] + cost\
    \ < dist[j]) {\n                dist[j] = dist[i] + cost;\n                if\
    \ (cost) {\n                    que.emplace_back(j, dist[j]);\n              \
    \  } else {\n                    que.emplace_front(j, dist[j]);\n            \
    \    }\n            }\n        }\n    }\n    return dist;\n}\n"
  code: "/**\n * @brief compute the distances from root\n * @note O(n)\n * @arg g\
    \ is a digraph\n * @note loops and double edges are allowed\n */\nvector<int>\
    \ breadth_first_search(int root, vector<vector<int> > const & g) {\n    int n\
    \ = g.size();\n    vector<int> dist(n, INT_MAX);\n    queue<int> que;\n    dist[root]\
    \ = 0;\n    que.push(root);\n    while (not que.empty()) {\n        int i = que.front();\
    \ que.pop();\n        for (int j : g[i]) if (dist[j] == INT_MAX) {\n         \
    \   dist[j] = dist[i] + 1;\n            que.push(j);\n        }\n    }\n    return\
    \ dist;\n}\n\n/**\n * @brief 0-1 BFS\n * @arg g is a weighted digraph whose weights\
    \ are 0 or 1\n * @note loops and double edges are allowed\n */\nvector<int> zero_one_breadth_first_search(int\
    \ root, vector<vector<pair<int, bool> > > const & g) {\n    int n = g.size();\n\
    \    vector<int> dist(n, INT_MAX);\n    deque<pair<int, int> > que;\n    dist[root]\
    \ = 0;\n    que.emplace_back(root, dist[root]);\n    while (not que.empty()) {\n\
    \        int i, dist_i; tie(i, dist_i) = que.front(); que.pop_front();\n     \
    \   if (dist[i] < dist_i) continue;\n        for (auto edge : g[i]) {\n      \
    \      int j; bool cost; tie(j, cost) = edge;\n            if (dist[i] + cost\
    \ < dist[j]) {\n                dist[j] = dist[i] + cost;\n                if\
    \ (cost) {\n                    que.emplace_back(j, dist[j]);\n              \
    \  } else {\n                    que.emplace_front(j, dist[j]);\n            \
    \    }\n            }\n        }\n    }\n    return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/breadth-first-search.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/breadth-first-search.inc.cpp
layout: document
redirect_from:
- /library/old/breadth-first-search.inc.cpp
- /library/old/breadth-first-search.inc.cpp.html
title: compute the distances from root
---
