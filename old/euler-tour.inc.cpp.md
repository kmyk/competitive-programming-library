---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: euler tour
    links:
    - https://yukicoder.me/problems/no/899
  bundledCode: "#line 1 \"old/euler-tour.inc.cpp\"\n/**\n * @brief euler tour\n *\
    \ @arg g must be a tree, directed or undirected\n * @note for constraints, see\
    \ the unittest\n */\nvoid do_euler_tour(vector<vector<int> > const & g, int root,\
    \ vector<int> & tour, vector<int> & left, vector<int> & right) {\n    int n =\
    \ g.size();\n    tour.clear();\n    left.resize(n);\n    right.resize(n);\n  \
    \  function<void (int, int)> go = [&](int x, int parent) {\n        left[x] =\
    \ tour.size();\n        tour.push_back(x);\n        for (int y : g[x]) if (y !=\
    \ parent) {\n            go(y, x);\n        }\n        right[x] = tour.size();\n\
    \        tour.push_back(x);\n    };\n    go(root, -1);\n}\nunittest {\n    default_random_engine\
    \ gen;\n    int n = 100;\n    vector<vector<int> > g(n);\n    REP (i, n - 1) {\n\
    \        int j = uniform_int_distribution<int>(i + 1, n - 1)(gen);\n        g[i].push_back(j);\n\
    \        g[j].push_back(i);\n    }\n    vector<int> tour, left, right; do_euler_tour(g,\
    \ 0, tour, left, right);\n    assert (tour.size() == 2 * n);\n    REP (i, n) {\n\
    \        assert (tour[ left[i]] == i);\n        assert (tour[right[i]] == i);\n\
    \    }\n}\n\n/**\n * @brief euler tour, push vertices only visiting\n * @arg g\
    \ must be a tree, directed or undirected\n */\nvoid do_left_euler_tour(vector<vector<int>\
    \ > const & g, int root, vector<int> & tour, vector<int> & left, vector<int> &\
    \ right) {\n    int n = g.size();\n    tour.clear();\n    left.resize(n);\n  \
    \  right.resize(n);\n    function<void (int, int)> go = [&](int x, int parent)\
    \ {\n        left[x] = tour.size();\n        tour.push_back(x);\n        for (int\
    \ y : g[x]) if (y != parent) {\n            go(y, x);\n        }\n        right[x]\
    \ = tour.size();\n    };\n    go(root, -1);\n}\nunittest {\n    default_random_engine\
    \ gen;\n    int n = 100;\n    vector<vector<int> > g(n);\n    REP (i, n - 1) {\n\
    \        int j = uniform_int_distribution<int>(i + 1, n - 1)(gen);\n        g[i].push_back(j);\n\
    \        g[j].push_back(i);\n    }\n    vector<int> tour, left, right; do_left_euler_tour(g,\
    \ 0, tour, left, right);\n    assert (tour.size() == n);\n    REP (i, n) {\n \
    \       assert (tour[left[i]] == i);\n    }\n}\n\n/**\n * @brief something like\
    \ euler tour but do BFS\n * @arg g must be a tree, directed or undirected\n *\
    \ @note for constraints, see the unittest\n * @arg parent is initialized\n * @arg\
    \ left and\n * @arg right are the ranges of descendants of k-th level\n * @note\
    \ O(N * DEPTH)\n * @sa https://yukicoder.me/problems/no/899\n */\ntemplate <int\
    \ DEPTH>\nvoid do_bfs_euler_tour(vector<vector<int> > const & g, int root, vector<int>\
    \ & tour, vector<int> & parent, vector<array<int, DEPTH> > & left, vector<array<int,\
    \ DEPTH> > & right) {\n    int n = g.size();\n    tour.clear();\n    parent.assign(n,\
    \ -1);\n    left.resize(n);\n    right.resize(n);\n    queue<int> que;\n    que.push(root);\n\
    \    while (not que.empty()) {\n        int x = que.front();\n        que.pop();\n\
    \        int i = tour.size();\n        // initialize current\n        tour.push_back(x);\n\
    \        fill(ALL(left[x]), n);\n        fill(ALL(right[x]), n);\n        // update\
    \ parent\n        int y = x;\n        REP (d, DEPTH) {\n            y = parent[y];\n\
    \            if (y == -1) break;\n            left[y][d] = min(left[y][d], i);\n\
    \            right[y][d] = i + 1;\n        }\n        // go children\n       \
    \ for (int y : g[x]) if (y != parent[x]) {\n            parent[y] = x;\n     \
    \       que.push(y);\n        }\n    }\n}\n"
  code: "/**\n * @brief euler tour\n * @arg g must be a tree, directed or undirected\n\
    \ * @note for constraints, see the unittest\n */\nvoid do_euler_tour(vector<vector<int>\
    \ > const & g, int root, vector<int> & tour, vector<int> & left, vector<int> &\
    \ right) {\n    int n = g.size();\n    tour.clear();\n    left.resize(n);\n  \
    \  right.resize(n);\n    function<void (int, int)> go = [&](int x, int parent)\
    \ {\n        left[x] = tour.size();\n        tour.push_back(x);\n        for (int\
    \ y : g[x]) if (y != parent) {\n            go(y, x);\n        }\n        right[x]\
    \ = tour.size();\n        tour.push_back(x);\n    };\n    go(root, -1);\n}\nunittest\
    \ {\n    default_random_engine gen;\n    int n = 100;\n    vector<vector<int>\
    \ > g(n);\n    REP (i, n - 1) {\n        int j = uniform_int_distribution<int>(i\
    \ + 1, n - 1)(gen);\n        g[i].push_back(j);\n        g[j].push_back(i);\n\
    \    }\n    vector<int> tour, left, right; do_euler_tour(g, 0, tour, left, right);\n\
    \    assert (tour.size() == 2 * n);\n    REP (i, n) {\n        assert (tour[ left[i]]\
    \ == i);\n        assert (tour[right[i]] == i);\n    }\n}\n\n/**\n * @brief euler\
    \ tour, push vertices only visiting\n * @arg g must be a tree, directed or undirected\n\
    \ */\nvoid do_left_euler_tour(vector<vector<int> > const & g, int root, vector<int>\
    \ & tour, vector<int> & left, vector<int> & right) {\n    int n = g.size();\n\
    \    tour.clear();\n    left.resize(n);\n    right.resize(n);\n    function<void\
    \ (int, int)> go = [&](int x, int parent) {\n        left[x] = tour.size();\n\
    \        tour.push_back(x);\n        for (int y : g[x]) if (y != parent) {\n \
    \           go(y, x);\n        }\n        right[x] = tour.size();\n    };\n  \
    \  go(root, -1);\n}\nunittest {\n    default_random_engine gen;\n    int n = 100;\n\
    \    vector<vector<int> > g(n);\n    REP (i, n - 1) {\n        int j = uniform_int_distribution<int>(i\
    \ + 1, n - 1)(gen);\n        g[i].push_back(j);\n        g[j].push_back(i);\n\
    \    }\n    vector<int> tour, left, right; do_left_euler_tour(g, 0, tour, left,\
    \ right);\n    assert (tour.size() == n);\n    REP (i, n) {\n        assert (tour[left[i]]\
    \ == i);\n    }\n}\n\n/**\n * @brief something like euler tour but do BFS\n *\
    \ @arg g must be a tree, directed or undirected\n * @note for constraints, see\
    \ the unittest\n * @arg parent is initialized\n * @arg left and\n * @arg right\
    \ are the ranges of descendants of k-th level\n * @note O(N * DEPTH)\n * @sa https://yukicoder.me/problems/no/899\n\
    \ */\ntemplate <int DEPTH>\nvoid do_bfs_euler_tour(vector<vector<int> > const\
    \ & g, int root, vector<int> & tour, vector<int> & parent, vector<array<int, DEPTH>\
    \ > & left, vector<array<int, DEPTH> > & right) {\n    int n = g.size();\n   \
    \ tour.clear();\n    parent.assign(n, -1);\n    left.resize(n);\n    right.resize(n);\n\
    \    queue<int> que;\n    que.push(root);\n    while (not que.empty()) {\n   \
    \     int x = que.front();\n        que.pop();\n        int i = tour.size();\n\
    \        // initialize current\n        tour.push_back(x);\n        fill(ALL(left[x]),\
    \ n);\n        fill(ALL(right[x]), n);\n        // update parent\n        int\
    \ y = x;\n        REP (d, DEPTH) {\n            y = parent[y];\n            if\
    \ (y == -1) break;\n            left[y][d] = min(left[y][d], i);\n           \
    \ right[y][d] = i + 1;\n        }\n        // go children\n        for (int y\
    \ : g[x]) if (y != parent[x]) {\n            parent[y] = x;\n            que.push(y);\n\
    \        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/euler-tour.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/euler-tour.inc.cpp
layout: document
redirect_from:
- /library/old/euler-tour.inc.cpp
- /library/old/euler-tour.inc.cpp.html
title: euler tour
---
