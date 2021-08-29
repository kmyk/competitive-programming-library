---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/yen_algorithm.hpp
    title: K shortest simple paths (Yen's algorithm + Dijkstra, $O(K V (E + V) \log
      V)$)
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-4
    PROBLEM: https://yukicoder.me/problems/no/1069
    links:
    - https://yukicoder.me/problems/no/1069
  bundledCode: "#line 1 \"graph/yen_algorithm.yukicoder-1069.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1069\"\n#define ERROR 1e-4\n#include <bits/stdc++.h>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 9 \"graph/yen_algorithm.hpp\"\n\n/**\n * @brief K shortest\
    \ simple paths (Yen's algorithm + Dijkstra, $O(K V (E + V) \\log V)$)\n * @param\
    \ g is an adjacent list of a simple undirected graph\n * @return simple paths.\
    \ If there are only less than K paths, return all paths in sorted order.\n */\n\
    template <class T>\nstd::vector<std::vector<int> > yen_algorithm_with_dijkstra(const\
    \ std::vector<std::vector<std::pair<int, T> > > & g, int start, int goal, int\
    \ k) {\n    using namespace std;\n    using reversed_priority_queue = priority_queue<pair<T,\
    \ int> , vector<pair<T, int> >, greater<pair<T, int> > >;\n\n    // trivial cases\n\
    \    if (k == 0) return vector<vector<int> >();\n    if (start == goal) {\n  \
    \      return vector<vector<int> >(1, vector<int>(1, start));\n    }\n    assert\
    \ (k >= 1);\n\n    // prepare\n    int n = g.size();\n    auto dijkstra = [&](int\
    \ start, const set<int> & removed_vertices, const set<pair<int, int> > & removed_edges)\
    \ -> pair<T, vector<int> > {\n        // dijkstra\n        vector<pair<T, int>\
    \ > dist(n, make_pair(numeric_limits<T>::max(), -1));\n        reversed_priority_queue\
    \ que;\n        dist[start] = make_pair(0, -1);\n        que.emplace(0, start);\n\
    \        while (not que.empty()) {\n            auto [dist_x, x] = que.top();\n\
    \            que.pop();\n            if (dist[x].first < dist_x) continue;\n \
    \           for (auto [y, cost] : g[x]) if (not removed_vertices.count(y) and\
    \ not removed_edges.count(make_pair(x, y))) {\n                if (dist_x + cost\
    \ < dist[y].first) {\n                    dist[y] = make_pair(dist_x + cost, x);\n\
    \                    que.emplace(dist_x + cost, y);\n                }\n     \
    \       }\n        }\n\n        // reconstruct the path\n        if (start !=\
    \ goal and dist[goal].second == -1) {\n            // failure\n            return\
    \ make_pair(dist[goal].first, vector<int>());\n        }\n        vector<int>\
    \ path;\n        for (int x = goal; x != -1; x = dist[x].second) {\n         \
    \   path.push_back(x);\n        }\n        reverse(ALL(path));\n        return\
    \ make_pair(dist[goal].first, path);\n    };\n    map<pair<int, int>, double>\
    \ lookup;\n    REP (i, n) {\n        for (auto [j, cost] : g[i]) {\n         \
    \   lookup[make_pair(i, j)] = cost;\n        }\n    }\n\n    // run Yen's algorithm\n\
    \    vector<vector<int> > result;\n    set<pair<T, vector<int> > > que;\n    result.push_back(dijkstra(start,\
    \ set<int>(), set<pair<int, int> >()).second);\n    while ((int)result.size()\
    \ < k) {\n        auto & root = result.back();\n\n        T root_cost = 0;\n \
    \       set<int> removed_vertices;\n        vector<int> prefix(result.size());\n\
    \        iota(ALL(prefix), 0);\n        REP (i, (int)root.size() - 1) {\n    \
    \        // remove edges used in other shortest paths from the graph\n       \
    \     set<pair<int, int> > removed_edges;\n            vector<int> next_prefix;\n\
    \            for (int j : prefix) {\n                if (i + 1 < result[j].size()\
    \ and result[j][i] == root[i]) {\n                    int x = result[j][i];\n\
    \                    int y = result[j][i + 1];\n                    removed_edges.emplace(x,\
    \ y);\n                    removed_edges.emplace(y, x);\n                    next_prefix.push_back(j);\n\
    \                }\n            }\n            prefix.swap(next_prefix);\n\n \
    \           // make the new path\n            auto [spur_cost, spur] = dijkstra(root[i],\
    \ removed_vertices, removed_edges);\n            if (not spur.empty()) {\n   \
    \             vector<int> path(i + spur.size());\n                copy(root.begin(),\
    \ root.begin() + i, path.begin());\n                copy(ALL(spur), path.begin()\
    \ + i);\n                que.emplace(root_cost + spur_cost, path);\n         \
    \       if (que.size() > k - (int)result.size()) {\n                    que.erase(prev(que.end()));\n\
    \                }\n            }\n\n            // remove vertices in root from\
    \ the graph\n            removed_vertices.insert(root[i]);\n            root_cost\
    \ += lookup[make_pair(root[i], root[i + 1])];\n        }\n\n        // found i-th\
    \ smallest path\n        if (que.empty()) {\n            return result;\n    \
    \    }\n        result.push_back(que.begin()->second);\n        que.erase(que.begin());\n\
    \    }\n    return result;\n}\n#line 6 \"graph/yen_algorithm.yukicoder-1069.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    // input\n    int n, m, k; scanf(\"\
    %d%d%d\", &n, &m, &k);\n    int start, goal; scanf(\"%d%d\", &start, &goal);\n\
    \    -- start;\n    -- goal;\n    vector<long long> x(n), y(n);\n    REP (i, n)\
    \ {\n        scanf(\"%lld%lld\", &x[i], &y[i]);\n    }\n    vector<vector<pair<int,\
    \ double> > > g(n);\n    REP (i, m) {\n        int p, q; cin >> p >> q;\n    \
    \    -- p;\n        -- q;\n        double cost = sqrt(pow(x[p] - x[q], 2) + pow(y[p]\
    \ - y[q], 2));\n        g[p].emplace_back(q, cost);\n        g[q].emplace_back(p,\
    \ cost);\n    }\n\n    // solve\n    auto path = yen_algorithm_with_dijkstra(g,\
    \ start, goal, k);\n    vector<double> cost(k, -1);\n    map<pair<int, int>, double>\
    \ lookup;\n    REP (i, n) {\n        for (auto [j, cost] : g[i]) {\n         \
    \   lookup[make_pair(i, j)] = cost;\n        }\n    }\n    REP (i, path.size())\
    \ {\n        cost[i] = 0;\n        REP (j, (int)path[i].size() - 1) {\n      \
    \      cost[i] += lookup[make_pair(path[i][j], path[i][j + 1])];\n        }\n\
    \    }\n\n    // output\n    REP (i, k) {\n        printf(\"%.12lf\\n\", cost[i]);\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1069\"\n#define ERROR\
    \ 1e-4\n#include <bits/stdc++.h>\n#include \"../utils/macros.hpp\"\n#include \"\
    ../graph/yen_algorithm.hpp\"\nusing namespace std;\n\nint main() {\n    // input\n\
    \    int n, m, k; scanf(\"%d%d%d\", &n, &m, &k);\n    int start, goal; scanf(\"\
    %d%d\", &start, &goal);\n    -- start;\n    -- goal;\n    vector<long long> x(n),\
    \ y(n);\n    REP (i, n) {\n        scanf(\"%lld%lld\", &x[i], &y[i]);\n    }\n\
    \    vector<vector<pair<int, double> > > g(n);\n    REP (i, m) {\n        int\
    \ p, q; cin >> p >> q;\n        -- p;\n        -- q;\n        double cost = sqrt(pow(x[p]\
    \ - x[q], 2) + pow(y[p] - y[q], 2));\n        g[p].emplace_back(q, cost);\n  \
    \      g[q].emplace_back(p, cost);\n    }\n\n    // solve\n    auto path = yen_algorithm_with_dijkstra(g,\
    \ start, goal, k);\n    vector<double> cost(k, -1);\n    map<pair<int, int>, double>\
    \ lookup;\n    REP (i, n) {\n        for (auto [j, cost] : g[i]) {\n         \
    \   lookup[make_pair(i, j)] = cost;\n        }\n    }\n    REP (i, path.size())\
    \ {\n        cost[i] = 0;\n        REP (j, (int)path[i].size() - 1) {\n      \
    \      cost[i] += lookup[make_pair(path[i][j], path[i][j + 1])];\n        }\n\
    \    }\n\n    // output\n    REP (i, k) {\n        printf(\"%.12lf\\n\", cost[i]);\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - graph/yen_algorithm.hpp
  isVerificationFile: true
  path: graph/yen_algorithm.yukicoder-1069.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: graph/yen_algorithm.yukicoder-1069.test.cpp
layout: document
redirect_from:
- /verify/graph/yen_algorithm.yukicoder-1069.test.cpp
- /verify/graph/yen_algorithm.yukicoder-1069.test.cpp.html
title: graph/yen_algorithm.yukicoder-1069.test.cpp
---
