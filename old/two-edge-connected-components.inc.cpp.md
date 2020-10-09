---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "2-edge-connected components decomposition / 2-\u8FBA\u9023\u7D50\
      \u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"old/two-edge-connected-components.inc.cpp\"\n/**\n * @brief\
    \ 2-edge-connected components decomposition / 2-\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\n * @param g an adjacent list of the simple undirected graph\n *\
    \ @note O(V + E)\n */\npair<int, vector<int> > decompose_to_two_edge_connected_components(vector<vector<int>\
    \ > const & g) {\n    int n = g.size();\n    vector<int> imos(n); { // imos[i]\
    \ == 0  iff  the edge i -> parent is a bridge\n        vector<char> used(n); //\
    \ 0: unused ; 1: exists on stack ; 2: removed from stack\n        function<void\
    \ (int, int)> go = [&](int i, int parent) {\n            used[i] = 1;\n      \
    \      for (int j : g[i]) if (j != parent) {\n                if (used[j] == 0)\
    \ {\n                    go(j, i);\n                    imos[i] += imos[j];\n\
    \                } else if (used[j] == 1) {\n                    imos[i] += 1;\n\
    \                    imos[j] -= 1;\n                }\n            }\n       \
    \     used[i] = 2;\n        };\n        REP (i, n) if (used[i] == 0) {\n     \
    \       go(i, -1);\n        }\n    }\n    int size = 0;\n    vector<int> component_of(n,\
    \ -1); {\n        function<void (int)> go = [&](int i) {\n            for (int\
    \ j : g[i]) if (component_of[j] == -1) {\n                component_of[j] = imos[j]\
    \ == 0 ? size ++ : component_of[i];\n                go(j);\n            }\n \
    \       };\n        REP (i, n) if (component_of[i] == -1) {\n            component_of[i]\
    \ = size ++;\n            go(i);\n        }\n    }\n    return { size, move(component_of)\
    \ };\n}\n"
  code: "/**\n * @brief 2-edge-connected components decomposition / 2-\u8FBA\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\n * @param g an adjacent list of the simple undirected\
    \ graph\n * @note O(V + E)\n */\npair<int, vector<int> > decompose_to_two_edge_connected_components(vector<vector<int>\
    \ > const & g) {\n    int n = g.size();\n    vector<int> imos(n); { // imos[i]\
    \ == 0  iff  the edge i -> parent is a bridge\n        vector<char> used(n); //\
    \ 0: unused ; 1: exists on stack ; 2: removed from stack\n        function<void\
    \ (int, int)> go = [&](int i, int parent) {\n            used[i] = 1;\n      \
    \      for (int j : g[i]) if (j != parent) {\n                if (used[j] == 0)\
    \ {\n                    go(j, i);\n                    imos[i] += imos[j];\n\
    \                } else if (used[j] == 1) {\n                    imos[i] += 1;\n\
    \                    imos[j] -= 1;\n                }\n            }\n       \
    \     used[i] = 2;\n        };\n        REP (i, n) if (used[i] == 0) {\n     \
    \       go(i, -1);\n        }\n    }\n    int size = 0;\n    vector<int> component_of(n,\
    \ -1); {\n        function<void (int)> go = [&](int i) {\n            for (int\
    \ j : g[i]) if (component_of[j] == -1) {\n                component_of[j] = imos[j]\
    \ == 0 ? size ++ : component_of[i];\n                go(j);\n            }\n \
    \       };\n        REP (i, n) if (component_of[i] == -1) {\n            component_of[i]\
    \ = size ++;\n            go(i);\n        }\n    }\n    return { size, move(component_of)\
    \ };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/two-edge-connected-components.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/two-edge-connected-components.inc.cpp
layout: document
redirect_from:
- /library/old/two-edge-connected-components.inc.cpp
- /library/old/two-edge-connected-components.inc.cpp.html
title: "2-edge-connected components decomposition / 2-\u8FBA\u9023\u7D50\u6210\u5206\
  \u5206\u89E3"
---
