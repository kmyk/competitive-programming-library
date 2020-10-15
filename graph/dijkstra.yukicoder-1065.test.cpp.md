---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra ($O((E + V) \log V)$)
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-4
    PROBLEM: https://yukicoder.me/problems/no/1065
    links:
    - https://yukicoder.me/problems/no/1065
  bundledCode: "#line 1 \"graph/dijkstra.yukicoder-1065.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1065\"\n#define ERROR 1e-4\n#include <bits/stdc++.h>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 7 \"graph/dijkstra.hpp\"\n\n/**\n * @brief Dijkstra ($O((E\
    \ + V) \\log V)$)\n */\ntemplate <class T = int64_t>\nstd::vector<T> dijkstra(std::vector<std::vector<std::pair<int,\
    \ T> > > const & g, int root) {\n    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());\n\
    \    std::priority_queue<std::pair<T, int> > que;\n    dist[root] = 0;\n    que.emplace(-\
    \ dist[root], root);\n    while (not que.empty()) {\n        T dist_x; int x;\
    \ std::tie(dist_x, x) = que.top(); que.pop();\n        if (dist[x] < - dist_x)\
    \ continue;\n        for (auto it : g[x]) {\n            int y; T cost; std::tie(y,\
    \ cost) = it;\n            if (- dist_x + cost < dist[y]) {\n                dist[y]\
    \ = - dist_x + cost;\n                que.emplace(dist_x - cost, y);\n       \
    \     }\n        }\n    }\n    return dist;\n}\n#line 6 \"graph/dijkstra.yukicoder-1065.test.cpp\"\
    \nusing namespace std;\n\n\nint main() {\n    // input\n    int n, m; scanf(\"\
    %d%d\", &n, &m);\n    int start, goal; scanf(\"%d%d\", &start, &goal);\n    --\
    \ start;\n    -- goal;\n    vector<long long> x(n), y(n);\n    REP (i, n) {\n\
    \        scanf(\"%lld%lld\", &x[i], &y[i]);\n    }\n    vector<vector<pair<int,\
    \ double> > > g(n);\n    REP (i, m) {\n        int p, q; cin >> p >> q;\n    \
    \    -- p;\n        -- q;\n        double cost = sqrt(pow(x[p] - x[q], 2) + pow(y[p]\
    \ - y[q], 2));\n        g[p].emplace_back(q, cost);\n        g[q].emplace_back(p,\
    \ cost);\n    }\n\n    // solve\n    auto dist = dijkstra(g, start);\n\n    //\
    \ output\n    printf(\"%.12lf\\n\", dist[goal]);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1065\"\n#define ERROR\
    \ 1e-4\n#include <bits/stdc++.h>\n#include \"utils/macros.hpp\"\n#include \"graph/dijkstra.hpp\"\
    \nusing namespace std;\n\n\nint main() {\n    // input\n    int n, m; scanf(\"\
    %d%d\", &n, &m);\n    int start, goal; scanf(\"%d%d\", &start, &goal);\n    --\
    \ start;\n    -- goal;\n    vector<long long> x(n), y(n);\n    REP (i, n) {\n\
    \        scanf(\"%lld%lld\", &x[i], &y[i]);\n    }\n    vector<vector<pair<int,\
    \ double> > > g(n);\n    REP (i, m) {\n        int p, q; cin >> p >> q;\n    \
    \    -- p;\n        -- q;\n        double cost = sqrt(pow(x[p] - x[q], 2) + pow(y[p]\
    \ - y[q], 2));\n        g[p].emplace_back(q, cost);\n        g[q].emplace_back(p,\
    \ cost);\n    }\n\n    // solve\n    auto dist = dijkstra(g, start);\n\n    //\
    \ output\n    printf(\"%.12lf\\n\", dist[goal]);\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: graph/dijkstra.yukicoder-1065.test.cpp
  requiredBy: []
  timestamp: '2020-05-29 23:50:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/dijkstra.yukicoder-1065.test.cpp
layout: document
redirect_from:
- /verify/graph/dijkstra.yukicoder-1065.test.cpp
- /verify/graph/dijkstra.yukicoder-1065.test.cpp.html
title: graph/dijkstra.yukicoder-1065.test.cpp
---
