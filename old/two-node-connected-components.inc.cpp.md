---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "2-node-connected components decomposition / 2-\u9802\u70B9\u9023\
      \u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"old/two-node-connected-components.inc.cpp\"\n/**\n * @brief\
    \ 2-node-connected components decomposition / 2-\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\n * @param g an adjacent list of the simple undirected graph\n\
    \ * @note O(V + E)\n * @return list of (list of edges in the component)\n */\n\
    vector<vector<pair<int, int> > > decompose_to_two_node_connected_components(vector<vector<int>\
    \ > const & g) {\n    int n = g.size();\n    vector<int> ord(n, -1);\n    vector<int>\
    \ low(n, -1);\n    vector<bool> used(n);\n    vector<vector<pair<int, int> > >\
    \ components;\n    stack<pair<int, int> > stk;\n    int k = 0;\n    function<void\
    \ (int, int)> go = [&](int i, int parent) {\n        used[i] = true;\n       \
    \ ord[i] = k ++;\n        low[i] = ord[i];\n        for (auto j : g[i]) if (j\
    \ != parent) {\n            if (ord[j] < ord[i]) {\n                stk.emplace(minmax({\
    \ i, j }));\n            }\n            if (used[j]) {\n                chmin(low[i],\
    \ ord[j]);\n            } else {\n                go(j, i);\n                chmin(low[i],\
    \ low[j]);\n                if (low[j] >= ord[i]) {\n                    components.emplace_back();\n\
    \                    while (true) {\n                        pair<int, int> e\
    \ = stk.top();\n                        components.back().push_back(e);\n    \
    \                    stk.pop();\n                        if (e == minmax({ i,\
    \ j })) {\n                            break;\n                        }\n   \
    \                 }\n                }\n            }\n        }\n    };\n   \
    \ REP (i, n) if (not used[i]) {\n        go(i, -1);\n    }\n    return components;\n\
    }\n"
  code: "/**\n * @brief 2-node-connected components decomposition / 2-\u9802\u70B9\
    \u9023\u7D50\u6210\u5206\u5206\u89E3\n * @param g an adjacent list of the simple\
    \ undirected graph\n * @note O(V + E)\n * @return list of (list of edges in the\
    \ component)\n */\nvector<vector<pair<int, int> > > decompose_to_two_node_connected_components(vector<vector<int>\
    \ > const & g) {\n    int n = g.size();\n    vector<int> ord(n, -1);\n    vector<int>\
    \ low(n, -1);\n    vector<bool> used(n);\n    vector<vector<pair<int, int> > >\
    \ components;\n    stack<pair<int, int> > stk;\n    int k = 0;\n    function<void\
    \ (int, int)> go = [&](int i, int parent) {\n        used[i] = true;\n       \
    \ ord[i] = k ++;\n        low[i] = ord[i];\n        for (auto j : g[i]) if (j\
    \ != parent) {\n            if (ord[j] < ord[i]) {\n                stk.emplace(minmax({\
    \ i, j }));\n            }\n            if (used[j]) {\n                chmin(low[i],\
    \ ord[j]);\n            } else {\n                go(j, i);\n                chmin(low[i],\
    \ low[j]);\n                if (low[j] >= ord[i]) {\n                    components.emplace_back();\n\
    \                    while (true) {\n                        pair<int, int> e\
    \ = stk.top();\n                        components.back().push_back(e);\n    \
    \                    stk.pop();\n                        if (e == minmax({ i,\
    \ j })) {\n                            break;\n                        }\n   \
    \                 }\n                }\n            }\n        }\n    };\n   \
    \ REP (i, n) if (not used[i]) {\n        go(i, -1);\n    }\n    return components;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: old/two-node-connected-components.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/two-node-connected-components.inc.cpp
layout: document
redirect_from:
- /library/old/two-node-connected-components.inc.cpp
- /library/old/two-node-connected-components.inc.cpp.html
title: "2-node-connected components decomposition / 2-\u9802\u70B9\u9023\u7D50\u6210\
  \u5206\u5206\u89E3"
---
