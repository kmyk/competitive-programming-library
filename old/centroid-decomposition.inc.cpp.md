---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "get centroids of a graph / \u91CD\u5FC3\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"old/centroid-decomposition.inc.cpp\"\n/**\n * @brief get\
    \ centroids of a graph / \u91CD\u5FC3\u5206\u89E3\n * @note O(n) time\n * @note\
    \ O(n) space on heap\n * @return the size is 1 or 2\n */\nvector<int> get_centroids(vector<vector<int>\
    \ > const & g, int root, set<int> const & forbidden) {\n    map<int, int> available;\
    \ {\n        function<void (int, int)> go = [&](int i, int parent) {\n       \
    \     available.emplace(i, available.size());\n            for (auto j : g[i])\
    \ if (j != parent and not forbidden.count(j)) {\n                go(j, i);\n \
    \           }\n        };\n        go(root, -1);\n    }\n    int n = available.size();\n\
    \    vector<int> result;\n    vector<int> size(n, -1);\n    function<void (int,\
    \ int)> go = [&](int x, int parent) {\n        bool is_centroid = true;\n    \
    \    int i = available[x];\n        size[i] = 1;\n        for (auto y : g[x])\
    \ if (y != parent and available.count(y)) {\n            int j = available[y];\n\
    \            go(y, x);\n            size[i] += size[j];\n            if (size[j]\
    \ > n / 2) is_centroid = false;\n        }\n        if (n - size[i] > n / 2) is_centroid\
    \ = false;\n        if (is_centroid) result.push_back(x);\n    };\n    go(root,\
    \ -1);\n    return result;\n}\n"
  code: "/**\n * @brief get centroids of a graph / \u91CD\u5FC3\u5206\u89E3\n * @note\
    \ O(n) time\n * @note O(n) space on heap\n * @return the size is 1 or 2\n */\n\
    vector<int> get_centroids(vector<vector<int> > const & g, int root, set<int> const\
    \ & forbidden) {\n    map<int, int> available; {\n        function<void (int,\
    \ int)> go = [&](int i, int parent) {\n            available.emplace(i, available.size());\n\
    \            for (auto j : g[i]) if (j != parent and not forbidden.count(j)) {\n\
    \                go(j, i);\n            }\n        };\n        go(root, -1);\n\
    \    }\n    int n = available.size();\n    vector<int> result;\n    vector<int>\
    \ size(n, -1);\n    function<void (int, int)> go = [&](int x, int parent) {\n\
    \        bool is_centroid = true;\n        int i = available[x];\n        size[i]\
    \ = 1;\n        for (auto y : g[x]) if (y != parent and available.count(y)) {\n\
    \            int j = available[y];\n            go(y, x);\n            size[i]\
    \ += size[j];\n            if (size[j] > n / 2) is_centroid = false;\n       \
    \ }\n        if (n - size[i] > n / 2) is_centroid = false;\n        if (is_centroid)\
    \ result.push_back(x);\n    };\n    go(root, -1);\n    return result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/centroid-decomposition.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/centroid-decomposition.inc.cpp
layout: document
redirect_from:
- /library/old/centroid-decomposition.inc.cpp
- /library/old/centroid-decomposition.inc.cpp.html
title: "get centroids of a graph / \u91CD\u5FC3\u5206\u89E3"
---
