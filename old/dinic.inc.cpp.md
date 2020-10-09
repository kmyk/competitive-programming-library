---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dinic
    links:
    - http://algoogle.hadrori.jp/algorithm/dinic.html
    - https://gist.github.com/MiSawa/9532038
  bundledCode: "#line 1 \"old/dinic.inc.cpp\"\n/**\n * @brief Dinic\n * @note O(V^2\
    \ E)\n * @note based on http://algoogle.hadrori.jp/algorithm/dinic.html\n * @note\
    \ tihs works with almost same speed to MiSawa's one https://gist.github.com/MiSawa/9532038\
    \ if you do s/ll/int/\n */\nclass max_flow {\n    struct edge_t {\n        int\
    \ to;\n        ll cap;\n        int rev;\n    };\n    int v;\n    vector<vector<edge_t>\
    \ > g;\n    vector<int> iter, level;\npublic:\n    max_flow(int v_)\n        \
    \    : v(v_), g(v) {\n    }\n    void add_edge(int from, int to, ll cap) {\n \
    \       g[from].push_back((edge_t) { to, cap, (int)g[to].size() });\n        g[to].push_back((edge_t)\
    \ { from, 0ll, (int)g[from].size() - 1 });\n    }\nprivate:\n    void bfs(int\
    \ src) {\n        level.assign(v, -1);\n        queue<int> q;\n        level[src]\
    \ = 0;\n        q.push(src);\n        while (not q.empty()) {\n            int\
    \ x = q.front();\n            q.pop();\n            for (auto & e : g[x]) {\n\
    \                if (e.cap > 0 and level[e.to] < 0) {\n                    level[e.to]\
    \ = level[x] + 1;\n                    q.push(e.to);\n                }\n    \
    \        }\n        }\n    }\n    ll dfs(int x, int dst, ll flow) {\n        if\
    \ (x == dst) return flow;\n        for (int & i = iter[x]; i < (int)g[x].size();\
    \ ++ i) {\n            edge_t & e = g[x][i];\n            if (e.cap > 0 and level[x]\
    \ < level[e.to]) {\n                ll d = dfs(e.to, dst, min(flow, e.cap));\n\
    \                if (d > 0) {\n                    e.cap -= d;\n             \
    \       g[e.to][e.rev].cap += d;\n                    return d;\n            \
    \    }\n            }\n        }\n        return 0;\n    }\npublic:\n    ll run_destructive(int\
    \ src, int dst) {\n        ll flow = 0;\n        bfs(src);\n        while (level[dst]\
    \ >= 0) {\n            iter.assign(v, 0);\n            while (true) {\n      \
    \          ll delta = dfs(src, dst, INF);\n                if (delta <= 0) break;\n\
    \                flow += delta;\n            }\n            bfs(src);\n      \
    \  }\n        return flow;\n    }\n};\n"
  code: "/**\n * @brief Dinic\n * @note O(V^2 E)\n * @note based on http://algoogle.hadrori.jp/algorithm/dinic.html\n\
    \ * @note tihs works with almost same speed to MiSawa's one https://gist.github.com/MiSawa/9532038\
    \ if you do s/ll/int/\n */\nclass max_flow {\n    struct edge_t {\n        int\
    \ to;\n        ll cap;\n        int rev;\n    };\n    int v;\n    vector<vector<edge_t>\
    \ > g;\n    vector<int> iter, level;\npublic:\n    max_flow(int v_)\n        \
    \    : v(v_), g(v) {\n    }\n    void add_edge(int from, int to, ll cap) {\n \
    \       g[from].push_back((edge_t) { to, cap, (int)g[to].size() });\n        g[to].push_back((edge_t)\
    \ { from, 0ll, (int)g[from].size() - 1 });\n    }\nprivate:\n    void bfs(int\
    \ src) {\n        level.assign(v, -1);\n        queue<int> q;\n        level[src]\
    \ = 0;\n        q.push(src);\n        while (not q.empty()) {\n            int\
    \ x = q.front();\n            q.pop();\n            for (auto & e : g[x]) {\n\
    \                if (e.cap > 0 and level[e.to] < 0) {\n                    level[e.to]\
    \ = level[x] + 1;\n                    q.push(e.to);\n                }\n    \
    \        }\n        }\n    }\n    ll dfs(int x, int dst, ll flow) {\n        if\
    \ (x == dst) return flow;\n        for (int & i = iter[x]; i < (int)g[x].size();\
    \ ++ i) {\n            edge_t & e = g[x][i];\n            if (e.cap > 0 and level[x]\
    \ < level[e.to]) {\n                ll d = dfs(e.to, dst, min(flow, e.cap));\n\
    \                if (d > 0) {\n                    e.cap -= d;\n             \
    \       g[e.to][e.rev].cap += d;\n                    return d;\n            \
    \    }\n            }\n        }\n        return 0;\n    }\npublic:\n    ll run_destructive(int\
    \ src, int dst) {\n        ll flow = 0;\n        bfs(src);\n        while (level[dst]\
    \ >= 0) {\n            iter.assign(v, 0);\n            while (true) {\n      \
    \          ll delta = dfs(src, dst, INF);\n                if (delta <= 0) break;\n\
    \                flow += delta;\n            }\n            bfs(src);\n      \
    \  }\n        return flow;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/dinic.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/dinic.inc.cpp
layout: document
redirect_from:
- /library/old/dinic.inc.cpp
- /library/old/dinic.inc.cpp.html
title: Dinic
---
