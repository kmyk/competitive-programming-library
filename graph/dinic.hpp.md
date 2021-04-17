---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "maximum flow / \u6700\u5927\u6D41 (Dinic)"
    links: []
  bundledCode: "#line 2 \"graph/dinic.hpp\"\n#include <numeric>\n#include <queue>\n\
    #include <vector>\n\nnamespace max_flow {\n\ntemplate <class T>\nstruct edge {\n\
    \    int to;\n    T cap;\n    int rev;\n};\n\ntemplate <class T>\nvoid add_edge(std::vector<std::vector<edge<T>\
    \ > > & graph, int from, int to, int64_t cap) {\n    g[from].push_back((edge<T>)\
    \ { to, cap, static_cast<int>(g[to].size()) });\n    g[to].push_back((edge<T>)\
    \ { from, 0, static_cast<int>(g[from].size()) - 1 });\n}\n\n/**\n * @brief maximum\
    \ flow / \u6700\u5927\u6D41 (Dinic)\n */\ntemplate <class T>\nT run_destructive(std::vector<std::vector<edge<T>\
    \ > > & graph, int src, int dst) {\n    std::vector<int> iter, level;\n\n    auto\
    \ bfs = [&](int src) {\n        level.assign(v, -1);\n        std::queue<int>\
    \ q;\n        level[src] = 0;\n        q.push(src);\n        while (not q.empty())\
    \ {\n            int x = q.front();\n            q.pop();\n            for (auto\
    \ & e : g[x]) {\n                if (e.cap > 0 and level[e.to] < 0) {\n      \
    \              level[e.to] = level[x] + 1;\n                    q.push(e.to);\n\
    \                }\n            }\n        }\n    };\n\n    auto dfs = [&](auto&&\
    \ dfs, int x, int dst, T flow) -> T {\n        if (x == dst) return flow;\n  \
    \      for (int & i = iter[x]; i < static_cast<int>(g[x].size()); ++ i) {\n  \
    \          edge_t & e = g[x][i];\n            if (e.cap > 0 and level[x] < level[e.to])\
    \ {\n                T d = dfs(dfs, e.to, dst, min(flow, e.cap));\n          \
    \      if (d > 0) {\n                    e.cap -= d;\n                    g[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n\n    T flow = 0;\n    bfs(src);\n    while\
    \ (level[dst] >= 0) {\n        iter.assign(v, 0);\n        while (true) {\n  \
    \          T delta = dfs(dfs, src, dst, std::numeric_limits<T>::max());\n    \
    \        if (delta <= 0) break;\n            flow += delta;\n        }\n     \
    \   bfs(src);\n    }\n    return flow;\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <queue>\n#include <vector>\n\n\
    namespace max_flow {\n\ntemplate <class T>\nstruct edge {\n    int to;\n    T\
    \ cap;\n    int rev;\n};\n\ntemplate <class T>\nvoid add_edge(std::vector<std::vector<edge<T>\
    \ > > & graph, int from, int to, int64_t cap) {\n    g[from].push_back((edge<T>)\
    \ { to, cap, static_cast<int>(g[to].size()) });\n    g[to].push_back((edge<T>)\
    \ { from, 0, static_cast<int>(g[from].size()) - 1 });\n}\n\n/**\n * @brief maximum\
    \ flow / \u6700\u5927\u6D41 (Dinic)\n */\ntemplate <class T>\nT run_destructive(std::vector<std::vector<edge<T>\
    \ > > & graph, int src, int dst) {\n    std::vector<int> iter, level;\n\n    auto\
    \ bfs = [&](int src) {\n        level.assign(v, -1);\n        std::queue<int>\
    \ q;\n        level[src] = 0;\n        q.push(src);\n        while (not q.empty())\
    \ {\n            int x = q.front();\n            q.pop();\n            for (auto\
    \ & e : g[x]) {\n                if (e.cap > 0 and level[e.to] < 0) {\n      \
    \              level[e.to] = level[x] + 1;\n                    q.push(e.to);\n\
    \                }\n            }\n        }\n    };\n\n    auto dfs = [&](auto&&\
    \ dfs, int x, int dst, T flow) -> T {\n        if (x == dst) return flow;\n  \
    \      for (int & i = iter[x]; i < static_cast<int>(g[x].size()); ++ i) {\n  \
    \          edge_t & e = g[x][i];\n            if (e.cap > 0 and level[x] < level[e.to])\
    \ {\n                T d = dfs(dfs, e.to, dst, min(flow, e.cap));\n          \
    \      if (d > 0) {\n                    e.cap -= d;\n                    g[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n\n    T flow = 0;\n    bfs(src);\n    while\
    \ (level[dst] >= 0) {\n        iter.assign(v, 0);\n        while (true) {\n  \
    \          T delta = dfs(dfs, src, dst, std::numeric_limits<T>::max());\n    \
    \        if (delta <= 0) break;\n            flow += delta;\n        }\n     \
    \   bfs(src);\n    }\n    return flow;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.hpp
  requiredBy: []
  timestamp: '2021-04-18 02:34:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dinic.hpp
layout: document
redirect_from:
- /library/graph/dinic.hpp
- /library/graph/dinic.hpp.html
title: "maximum flow / \u6700\u5927\u6D41 (Dinic)"
---
