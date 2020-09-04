---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Shortest Path Faster Algorithm
  bundledCode: "#line 2 \"graph/shortest_path_faster_algorithm.hpp\"\n#include <cassert>\n\
    #include <climits>\n#include <cstdint>\n#include <deque>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n)\
    \ for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i =\
    \ (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1;\
    \ (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >=\
    \ (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 10 \"graph/shortest_path_faster_algorithm.hpp\"\
    \n\n/**\n * @brief Shortest Path Faster Algorithm\n * @note the interface is same\
    \ to one of Bellman Ford\n */\nstd::vector<int64_t> shortest_path_faster_algorithm(int\
    \ root, std::vector<std::vector<std::pair<int, int64_t> > > const & g) {\n   \
    \ assert (not g.empty());\n    int n = g.size();\n    std::vector<int64_t> dist(n,\
    \ INT64_MAX);\n    std::deque<int> cur, nxt;\n    std::vector<bool> pushed(n);\n\
    \    dist[root] = 0;\n    nxt.push_back(root);\n    pushed[root] = true;\n\n \
    \   REP (iteration, 2 * n - 2) {\n        cur.swap(nxt);\n        while (not cur.empty())\
    \ {\n            int x = cur.front();\n            cur.pop_front();\n        \
    \    pushed[x] = false;\n            for (const auto & edge : g[x]) {\n      \
    \          int y; int64_t cost; std::tie(y, cost) = edge;\n                if\
    \ ((dist[x] == INT64_MIN ? INT64_MIN : dist[x] + cost) < dist[y]) {\n        \
    \            dist[y] = (iteration >= n - 1 ? INT64_MIN : dist[x] + cost);\n  \
    \                  if (not pushed[y]) {\n                        if (not nxt.empty()\
    \ and dist[y] < dist[nxt.front()]) {\n                            // Small Label\
    \ First\n                            nxt.push_front(y);\n                    \
    \    } else {\n                            nxt.push_back(y);\n               \
    \         }\n                        pushed[y] = true;\n                    }\n\
    \                }\n            }\n        }\n        if (nxt.empty()) break;\n\
    \    }\n\n    return dist;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <climits>\n#include <cstdint>\n\
    #include <deque>\n#include <tuple>\n#include <utility>\n#include <vector>\n#include\
    \ \"utils/macros.hpp\"\n\n/**\n * @brief Shortest Path Faster Algorithm\n * @note\
    \ the interface is same to one of Bellman Ford\n */\nstd::vector<int64_t> shortest_path_faster_algorithm(int\
    \ root, std::vector<std::vector<std::pair<int, int64_t> > > const & g) {\n   \
    \ assert (not g.empty());\n    int n = g.size();\n    std::vector<int64_t> dist(n,\
    \ INT64_MAX);\n    std::deque<int> cur, nxt;\n    std::vector<bool> pushed(n);\n\
    \    dist[root] = 0;\n    nxt.push_back(root);\n    pushed[root] = true;\n\n \
    \   REP (iteration, 2 * n - 2) {\n        cur.swap(nxt);\n        while (not cur.empty())\
    \ {\n            int x = cur.front();\n            cur.pop_front();\n        \
    \    pushed[x] = false;\n            for (const auto & edge : g[x]) {\n      \
    \          int y; int64_t cost; std::tie(y, cost) = edge;\n                if\
    \ ((dist[x] == INT64_MIN ? INT64_MIN : dist[x] + cost) < dist[y]) {\n        \
    \            dist[y] = (iteration >= n - 1 ? INT64_MIN : dist[x] + cost);\n  \
    \                  if (not pushed[y]) {\n                        if (not nxt.empty()\
    \ and dist[y] < dist[nxt.front()]) {\n                            // Small Label\
    \ First\n                            nxt.push_front(y);\n                    \
    \    } else {\n                            nxt.push_back(y);\n               \
    \         }\n                        pushed[y] = true;\n                    }\n\
    \                }\n            }\n        }\n        if (nxt.empty()) break;\n\
    \    }\n\n    return dist;\n}\n"
  dependsOn:
  - utils/macros.hpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: graph/shortest_path_faster_algorithm.hpp
  requiredBy: []
  timestamp: '2019-12-20 06:12:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: graph/shortest_path_faster_algorithm.hpp
layout: document
redirect_from:
- /library/graph/shortest_path_faster_algorithm.hpp
- /library/graph/shortest_path_faster_algorithm.hpp.html
title: Shortest Path Faster Algorithm
---
