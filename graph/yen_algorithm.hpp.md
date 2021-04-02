---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/yen_algorithm.yukicoder-1069.test.cpp
    title: graph/yen_algorithm.yukicoder-1069.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: K shortest simple paths (Yen's algorithm + Dijkstra, $O(K V (E
      + V) \log V)$)
    links: []
  bundledCode: "#line 2 \"graph/yen_algorithm.hpp\"\n#include <cassert>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief K shortest simple paths (Yen's algorithm +\
    \ Dijkstra, $O(K V (E + V) \\log V)$)\n * @param g is an adjacent list of a simple\
    \ undirected graph\n * @return simple paths. If there are only less than K paths,\
    \ return all paths in sorted order.\n */\ntemplate <class T>\nstd::vector<std::vector<int>\
    \ > yen_algorithm_with_dijkstra(const std::vector<std::vector<std::pair<int, T>\
    \ > > & g, int start, int goal, int k) {\n    using namespace std;\n    using\
    \ reversed_priority_queue = priority_queue<pair<T, int> , vector<pair<T, int>\
    \ >, greater<pair<T, int> > >;\n\n    // trivial cases\n    if (k == 0) return\
    \ vector<vector<int> >();\n    if (start == goal) {\n        return vector<vector<int>\
    \ >(1, vector<int>(1, start));\n    }\n    assert (k >= 1);\n\n    // prepare\n\
    \    int n = g.size();\n    auto dijkstra = [&](int start, const set<int> & removed_vertices,\
    \ const set<pair<int, int> > & removed_edges) -> pair<T, vector<int> > {\n   \
    \     // dijkstra\n        vector<pair<T, int> > dist(n, make_pair(numeric_limits<T>::max(),\
    \ -1));\n        reversed_priority_queue que;\n        dist[start] = make_pair(0,\
    \ -1);\n        que.emplace(0, start);\n        while (not que.empty()) {\n  \
    \          auto [dist_x, x] = que.top();\n            que.pop();\n           \
    \ if (dist[x].first < dist_x) continue;\n            for (auto [y, cost] : g[x])\
    \ if (not removed_vertices.count(y) and not removed_edges.count(make_pair(x, y)))\
    \ {\n                if (dist_x + cost < dist[y].first) {\n                  \
    \  dist[y] = make_pair(dist_x + cost, x);\n                    que.emplace(dist_x\
    \ + cost, y);\n                }\n            }\n        }\n\n        // reconstruct\
    \ the path\n        if (start != goal and dist[goal].second == -1) {\n       \
    \     // failure\n            return make_pair(dist[goal].first, vector<int>());\n\
    \        }\n        vector<int> path;\n        for (int x = goal; x != -1; x =\
    \ dist[x].second) {\n            path.push_back(x);\n        }\n        reverse(ALL(path));\n\
    \        return make_pair(dist[goal].first, path);\n    };\n    map<pair<int,\
    \ int>, double> lookup;\n    REP (i, n) {\n        for (auto [j, cost] : g[i])\
    \ {\n            lookup[make_pair(i, j)] = cost;\n        }\n    }\n\n    // run\
    \ Yen's algorithm\n    vector<vector<int> > result;\n    set<pair<T, vector<int>\
    \ > > que;\n    result.push_back(dijkstra(start, set<int>(), set<pair<int, int>\
    \ >()).second);\n    while ((int)result.size() < k) {\n        auto & root = result.back();\n\
    \n        T root_cost = 0;\n        set<int> removed_vertices;\n        vector<int>\
    \ prefix(result.size());\n        iota(ALL(prefix), 0);\n        REP (i, (int)root.size()\
    \ - 1) {\n            // remove edges used in other shortest paths from the graph\n\
    \            set<pair<int, int> > removed_edges;\n            vector<int> next_prefix;\n\
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
    \    }\n    return result;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <utility>\n#include <vector>\n\n/**\n * @brief\
    \ K shortest simple paths (Yen's algorithm + Dijkstra, $O(K V (E + V) \\log V)$)\n\
    \ * @param g is an adjacent list of a simple undirected graph\n * @return simple\
    \ paths. If there are only less than K paths, return all paths in sorted order.\n\
    \ */\ntemplate <class T>\nstd::vector<std::vector<int> > yen_algorithm_with_dijkstra(const\
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
    \    }\n    return result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/yen_algorithm.hpp
  requiredBy: []
  timestamp: '2020-05-30 02:50:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/yen_algorithm.yukicoder-1069.test.cpp
documentation_of: graph/yen_algorithm.hpp
layout: document
redirect_from:
- /library/graph/yen_algorithm.hpp
- /library/graph/yen_algorithm.hpp.html
title: K shortest simple paths (Yen's algorithm + Dijkstra, $O(K V (E + V) \log V)$)
---
