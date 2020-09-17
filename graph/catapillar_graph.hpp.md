---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: get a central path of a catapillar graph
    links:
    - https://atcoder.jp/contests/arc095/tasks/arc095_d
    - https://en.wikipedia.org/wiki/Caterpillar_tree
    - https://upload.wikimedia.org/wikipedia/commons/b/b7/Caterpillar_tree.svg)
  bundledCode: "#line 1 \"graph/catapillar_graph.hpp\"\n/**\n * @brief get a central\
    \ path of a catapillar graph\n * @arg g is a tree\n * @return a central path;\
    \ i.e. a longest path\n * @note $O(n)$\n * @note an empty vector if g is not a\
    \ catapillar\n * @see https://en.wikipedia.org/wiki/Caterpillar_tree\n * @note\
    \ example problem: https://atcoder.jp/contests/arc095/tasks/arc095_d\n * @note\
    \ ![](https://upload.wikimedia.org/wikipedia/commons/b/b7/Caterpillar_tree.svg)\n\
    \ */\nvector<int> get_catapillar_central_path(const vector<vector<int> > & g)\
    \ {\n    int n = g.size();\n\n    // construct the tree with non-leaf vertices\n\
    \    int m = 0;\n    vector<vector<int> > h(n);\n    REP (i, n) if (g[i].size()\
    \ != 1) {\n        ++ m;\n        for (int j : g[i]) if (g[j].size() != 1) {\n\
    \            h[i].push_back(j);\n        }\n    }\n\n    // the tree must be a\
    \ path graph\n    REP (i, n) {\n        if (h[i].size() >= 3) {\n            return\
    \ vector<int>();\n        }\n    }\n\n    // reconstruct the path\n    if (m ==\
    \ 0) {\n        if (n == 1) {\n            return vector<int>({ 0 });\n      \
    \  } else if (n == 2) {\n            return vector<int>({ 0, 1 });\n        }\
    \ else {\n            assert (false);\n        }\n\n    } else {\n        assert\
    \ (n >= 3);\n        vector<int> path;\n        int i = 0;\n        while (g[i].size()\
    \ == 1 or h[i].size() == 2) {\n            ++ i;\n        }\n        for (int\
    \ j : g[i]) if (g[i].size() == 1) {\n            path.push_back(j);\n        \
    \    break;\n        }\n        int parent = path.back();\n        while (true)\
    \ {\n            path.push_back(i);\n            bool found = false;\n       \
    \     for (int j : h[i]) if (j != parent) {\n                parent = i;\n   \
    \             i = j;\n                found = true;\n                break;\n\
    \            }\n            if (not found) {\n                break;\n       \
    \     }\n        }\n        for (int j : g[i]) if (g[i].size() == 1 and j != parent)\
    \ {\n            path.push_back(j);\n            break;\n        }\n        return\
    \ path;\n    }\n}\n"
  code: "/**\n * @brief get a central path of a catapillar graph\n * @arg g is a tree\n\
    \ * @return a central path; i.e. a longest path\n * @note $O(n)$\n * @note an\
    \ empty vector if g is not a catapillar\n * @see https://en.wikipedia.org/wiki/Caterpillar_tree\n\
    \ * @note example problem: https://atcoder.jp/contests/arc095/tasks/arc095_d\n\
    \ * @note ![](https://upload.wikimedia.org/wikipedia/commons/b/b7/Caterpillar_tree.svg)\n\
    \ */\nvector<int> get_catapillar_central_path(const vector<vector<int> > & g)\
    \ {\n    int n = g.size();\n\n    // construct the tree with non-leaf vertices\n\
    \    int m = 0;\n    vector<vector<int> > h(n);\n    REP (i, n) if (g[i].size()\
    \ != 1) {\n        ++ m;\n        for (int j : g[i]) if (g[j].size() != 1) {\n\
    \            h[i].push_back(j);\n        }\n    }\n\n    // the tree must be a\
    \ path graph\n    REP (i, n) {\n        if (h[i].size() >= 3) {\n            return\
    \ vector<int>();\n        }\n    }\n\n    // reconstruct the path\n    if (m ==\
    \ 0) {\n        if (n == 1) {\n            return vector<int>({ 0 });\n      \
    \  } else if (n == 2) {\n            return vector<int>({ 0, 1 });\n        }\
    \ else {\n            assert (false);\n        }\n\n    } else {\n        assert\
    \ (n >= 3);\n        vector<int> path;\n        int i = 0;\n        while (g[i].size()\
    \ == 1 or h[i].size() == 2) {\n            ++ i;\n        }\n        for (int\
    \ j : g[i]) if (g[i].size() == 1) {\n            path.push_back(j);\n        \
    \    break;\n        }\n        int parent = path.back();\n        while (true)\
    \ {\n            path.push_back(i);\n            bool found = false;\n       \
    \     for (int j : h[i]) if (j != parent) {\n                parent = i;\n   \
    \             i = j;\n                found = true;\n                break;\n\
    \            }\n            if (not found) {\n                break;\n       \
    \     }\n        }\n        for (int j : g[i]) if (g[i].size() == 1 and j != parent)\
    \ {\n            path.push_back(j);\n            break;\n        }\n        return\
    \ path;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/catapillar_graph.hpp
  requiredBy: []
  timestamp: '2019-12-15 03:57:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/catapillar_graph.hpp
layout: document
redirect_from:
- /library/graph/catapillar_graph.hpp
- /library/graph/catapillar_graph.hpp.html
title: get a central path of a catapillar graph
---
