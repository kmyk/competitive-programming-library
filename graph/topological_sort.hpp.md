---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.yosupo.test.cpp
    title: graph/strongly_connected_components.yosupo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: topological sort
    links: []
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n#include <algorithm>\n#include\
    \ <functional>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 6 \"\
    graph/topological_sort.hpp\"\n\n/**\n * @brief topological sort\n * @return a\
    \ list of vertices which sorted topologically\n * @note the empty list is returned\
    \ if cycles exist\n * @note $O(V + E)$\n */\nstd::vector<int> topological_sort(const\
    \ std::vector<std::vector<int> > & g) {\n    int n = g.size();\n    std::vector<int>\
    \ order;\n    std::vector<char> used(n);\n    std::function<bool (int)> go = [&](int\
    \ i) {\n        used[i] = 1;  // in stack\n        for (int j : g[i]) {\n    \
    \        if (used[j] == 1) return true;\n            if (not used[j]) {\n    \
    \            if (go(j)) return true;\n            }\n        }\n        used[i]\
    \ = 2;  // completely used\n        order.push_back(i);\n        return false;\n\
    \    };\n    REP (i, n) if (not used[i]) {\n        if (go(i)) return std::vector<int>();\n\
    \    }\n    std::reverse(ALL(order));\n    return order;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <functional>\n#include <vector>\n\
    #include \"utils/macros.hpp\"\n\n/**\n * @brief topological sort\n * @return a\
    \ list of vertices which sorted topologically\n * @note the empty list is returned\
    \ if cycles exist\n * @note $O(V + E)$\n */\nstd::vector<int> topological_sort(const\
    \ std::vector<std::vector<int> > & g) {\n    int n = g.size();\n    std::vector<int>\
    \ order;\n    std::vector<char> used(n);\n    std::function<bool (int)> go = [&](int\
    \ i) {\n        used[i] = 1;  // in stack\n        for (int j : g[i]) {\n    \
    \        if (used[j] == 1) return true;\n            if (not used[j]) {\n    \
    \            if (go(j)) return true;\n            }\n        }\n        used[i]\
    \ = 2;  // completely used\n        order.push_back(i);\n        return false;\n\
    \    };\n    REP (i, n) if (not used[i]) {\n        if (go(i)) return std::vector<int>();\n\
    \    }\n    std::reverse(ALL(order));\n    return order;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2020-02-22 23:03:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/strongly_connected_components.yosupo.test.cpp
documentation_of: graph/topological_sort.hpp
layout: document
redirect_from:
- /library/graph/topological_sort.hpp
- /library/graph/topological_sort.hpp.html
title: topological sort
---
