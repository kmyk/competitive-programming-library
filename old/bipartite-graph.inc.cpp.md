---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"old/bipartite-graph.inc.cpp\"\n/**\n * @note g must be connected\n\
    \ * @return is the size of a part\n */\nint check_bipartite_graph(vector<vector<int>\
    \ > const & g) {\n    int n = g.size();\n    vector<char> used(n, -1);\n    function<bool\
    \ (int, int)> dfs = [&](int i, int parent) {\n        for (int j : g[i]) {\n \
    \           if (used[j] != -1) {\n                if (used[j] == used[i]) {\n\
    \                    return false;\n                }\n            } else {\n\
    \                used[j] = used[i] ^ 1;\n                if (not dfs(j, i)) return\
    \ false;\n            }\n        }\n        return true;\n    };\n    used[0]\
    \ = 0;\n    if (not dfs(0, -1)) return -1;\n    return count(whole(used), 0);\n\
    }\n"
  code: "/**\n * @note g must be connected\n * @return is the size of a part\n */\n\
    int check_bipartite_graph(vector<vector<int> > const & g) {\n    int n = g.size();\n\
    \    vector<char> used(n, -1);\n    function<bool (int, int)> dfs = [&](int i,\
    \ int parent) {\n        for (int j : g[i]) {\n            if (used[j] != -1)\
    \ {\n                if (used[j] == used[i]) {\n                    return false;\n\
    \                }\n            } else {\n                used[j] = used[i] ^\
    \ 1;\n                if (not dfs(j, i)) return false;\n            }\n      \
    \  }\n        return true;\n    };\n    used[0] = 0;\n    if (not dfs(0, -1))\
    \ return -1;\n    return count(whole(used), 0);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/bipartite-graph.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/bipartite-graph.inc.cpp
layout: document
redirect_from:
- /library/old/bipartite-graph.inc.cpp
- /library/old/bipartite-graph.inc.cpp.html
title: old/bipartite-graph.inc.cpp
---
