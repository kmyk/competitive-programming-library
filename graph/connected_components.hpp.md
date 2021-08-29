---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/connected_components.hpp\"\n#include <stack>\n#include\
    \ <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i)\
    \ < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n\
    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 5 \"graph/connected_components.hpp\"\
    \n\n/**\n * @param g is an undirected graph\n */\nint count_connected_components(const\
    \ std::vector<std::vector<int> > & g) {\n    int n = g.size();\n    int cnt =\
    \ 0;\n    std::vector<bool> used(n);\n    std::stack<int> stk;\n    REP (z, n)\
    \ if (not used[z]) {\n        ++ cnt;\n        used[z] = true;\n        stk.push(z);\n\
    \        while (not stk.empty()) {\n            int x = stk.top();\n         \
    \   stk.pop();\n            for (int y : g[x]) if (not used[y]) {\n          \
    \      used[y] = true;\n                stk.push(y);\n            }\n        }\n\
    \    }\n    return cnt;\n}\n\n/**\n * @param g is an undirected graph\n */\nbool\
    \ is_connected_graph(const std::vector<std::vector<int> > & g) {\n    return count_connected_components(g)\
    \ == 1;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <vector>\n#include \"../utils/macros.hpp\"\
    \n\n/**\n * @param g is an undirected graph\n */\nint count_connected_components(const\
    \ std::vector<std::vector<int> > & g) {\n    int n = g.size();\n    int cnt =\
    \ 0;\n    std::vector<bool> used(n);\n    std::stack<int> stk;\n    REP (z, n)\
    \ if (not used[z]) {\n        ++ cnt;\n        used[z] = true;\n        stk.push(z);\n\
    \        while (not stk.empty()) {\n            int x = stk.top();\n         \
    \   stk.pop();\n            for (int y : g[x]) if (not used[y]) {\n          \
    \      used[y] = true;\n                stk.push(y);\n            }\n        }\n\
    \    }\n    return cnt;\n}\n\n/**\n * @param g is an undirected graph\n */\nbool\
    \ is_connected_graph(const std::vector<std::vector<int> > & g) {\n    return count_connected_components(g)\
    \ == 1;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/connected_components.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/connected_components.hpp
layout: document
redirect_from:
- /library/graph/connected_components.hpp
- /library/graph/connected_components.hpp.html
title: graph/connected_components.hpp
---
