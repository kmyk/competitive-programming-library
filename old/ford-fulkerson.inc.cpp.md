---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/ford-fulkerson.inc.cpp\"\nstruct edge_t { int to, cap,\
    \ rev; };\nint maximum_flow_destructive(int s, int t, vector<vector<edge_t> >\
    \ & g) { // ford fulkerson, O(EF)\n    int n = g.size();\n    vector<bool> used(n);\n\
    \    function<int (int, int)> dfs = [&](int i, int f) {\n        if (i == t) return\
    \ f;\n        used[i] = true;\n        for (edge_t & e : g[i]) {\n           \
    \ if (used[e.to] or e.cap <= 0) continue;\n            int nf = dfs(e.to, min(f,\
    \ e.cap));\n            if (nf > 0) {\n                e.cap -= nf;\n        \
    \        g[e.to][e.rev].cap += nf;\n                return nf;\n            }\n\
    \        }\n        return 0;\n    };\n    int result = 0;\n    while (true) {\n\
    \        used.clear(); used.resize(n);\n        int f = dfs(s, numeric_limits<int>::max());\n\
    \        if (f == 0) break;\n        result += f;\n    }\n    return result;\n\
    }\nvoid add_edge(vector<vector<edge_t> > & g, int from, int to, int cap) {\n \
    \   g[from].push_back((edge_t) {   to, cap, int(g[  to].size()    ) });\n    g[\
    \  to].push_back((edge_t) { from,   0, int(g[from].size() - 1) });\n}\nint maximum_flow(int\
    \ s, int t, vector<vector<edge_t> > g /* adjacency list */) { // ford fulkerson,\
    \ O(FE)\n    return maximum_flow_destructive(s, t, g);\n}\n\nvector<pair<int,int>\
    \ > perfect_bipartite_matching(set<int> const & a, set<int> const & b, vector<vector<int>\
    \ > const & g /* adjacency list */) { // O(V + FE)\n    assert (a.size() + b.size()\
    \ <= g.size());\n    int n = g.size();\n    int src = n;\n    int dst = n + 1;\n\
    \    vector<vector<edge_t> > h(n + 2);\n    auto add_edge = [&](int from, int\
    \ to, int cap) {\n        h[from].push_back((edge_t) {   to, cap, int(h[  to].size()\
    \    ) });\n        h[  to].push_back((edge_t) { from,   0, int(h[from].size()\
    \ - 1) });\n    };\n    repeat (i,n) {\n        if (a.count(i)) {\n          \
    \  add_edge(src, i, 1);\n            for (int j : g[i]) if (b.count(j)) {\n  \
    \              add_edge(i, j, 1); // collect edges e : a -> b, from g\n      \
    \      }\n        }\n        if (b.count(i)) {\n            add_edge(i, dst, 1);\n\
    \        }\n    }\n    maximum_flow_destructive(src, dst, h);\n    vector<pair<int,int>\
    \ > ans;\n    for (int from : a) {\n        for (edge_t e : h[from]) if (b.count(e.to)\
    \ and e.cap == 0) {\n            ans.emplace_back(from, e.to);\n        }\n  \
    \  }\n    return ans;\n}\n"
  code: "struct edge_t { int to, cap, rev; };\nint maximum_flow_destructive(int s,\
    \ int t, vector<vector<edge_t> > & g) { // ford fulkerson, O(EF)\n    int n =\
    \ g.size();\n    vector<bool> used(n);\n    function<int (int, int)> dfs = [&](int\
    \ i, int f) {\n        if (i == t) return f;\n        used[i] = true;\n      \
    \  for (edge_t & e : g[i]) {\n            if (used[e.to] or e.cap <= 0) continue;\n\
    \            int nf = dfs(e.to, min(f, e.cap));\n            if (nf > 0) {\n \
    \               e.cap -= nf;\n                g[e.to][e.rev].cap += nf;\n    \
    \            return nf;\n            }\n        }\n        return 0;\n    };\n\
    \    int result = 0;\n    while (true) {\n        used.clear(); used.resize(n);\n\
    \        int f = dfs(s, numeric_limits<int>::max());\n        if (f == 0) break;\n\
    \        result += f;\n    }\n    return result;\n}\nvoid add_edge(vector<vector<edge_t>\
    \ > & g, int from, int to, int cap) {\n    g[from].push_back((edge_t) {   to,\
    \ cap, int(g[  to].size()    ) });\n    g[  to].push_back((edge_t) { from,   0,\
    \ int(g[from].size() - 1) });\n}\nint maximum_flow(int s, int t, vector<vector<edge_t>\
    \ > g /* adjacency list */) { // ford fulkerson, O(FE)\n    return maximum_flow_destructive(s,\
    \ t, g);\n}\n\nvector<pair<int,int> > perfect_bipartite_matching(set<int> const\
    \ & a, set<int> const & b, vector<vector<int> > const & g /* adjacency list */)\
    \ { // O(V + FE)\n    assert (a.size() + b.size() <= g.size());\n    int n = g.size();\n\
    \    int src = n;\n    int dst = n + 1;\n    vector<vector<edge_t> > h(n + 2);\n\
    \    auto add_edge = [&](int from, int to, int cap) {\n        h[from].push_back((edge_t)\
    \ {   to, cap, int(h[  to].size()    ) });\n        h[  to].push_back((edge_t)\
    \ { from,   0, int(h[from].size() - 1) });\n    };\n    repeat (i,n) {\n     \
    \   if (a.count(i)) {\n            add_edge(src, i, 1);\n            for (int\
    \ j : g[i]) if (b.count(j)) {\n                add_edge(i, j, 1); // collect edges\
    \ e : a -> b, from g\n            }\n        }\n        if (b.count(i)) {\n  \
    \          add_edge(i, dst, 1);\n        }\n    }\n    maximum_flow_destructive(src,\
    \ dst, h);\n    vector<pair<int,int> > ans;\n    for (int from : a) {\n      \
    \  for (edge_t e : h[from]) if (b.count(e.to) and e.cap == 0) {\n            ans.emplace_back(from,\
    \ e.to);\n        }\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/ford-fulkerson.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/ford-fulkerson.inc.cpp
layout: document
redirect_from:
- /library/old/ford-fulkerson.inc.cpp
- /library/old/ford-fulkerson.inc.cpp.html
title: old/ford-fulkerson.inc.cpp
---
