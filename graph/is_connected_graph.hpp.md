---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/is_connected_graph.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\nbool is_connected_graph(const std::vector<std::vector<int>> &g)\
    \ {\n    int n = g.size();\n    std::vector<bool> used(n);\n    auto go = [&](auto\
    \ &&go, int x) -> void {\n        used[x] = true;\n        for (int y : g[x])\
    \ {\n            if (not used[y]) {\n                go(go, y);\n            }\n\
    \        }\n    };\n    go(go, 0);\n    return std::find(ALL(used), false) ==\
    \ used.end();\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nbool is_connected_graph(const\
    \ std::vector<std::vector<int>> &g) {\n    int n = g.size();\n    std::vector<bool>\
    \ used(n);\n    auto go = [&](auto &&go, int x) -> void {\n        used[x] = true;\n\
    \        for (int y : g[x]) {\n            if (not used[y]) {\n              \
    \  go(go, y);\n            }\n        }\n    };\n    go(go, 0);\n    return std::find(ALL(used),\
    \ false) == used.end();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/is_connected_graph.hpp
  requiredBy: []
  timestamp: '2021-08-29 20:30:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/is_connected_graph.hpp
layout: document
redirect_from:
- /library/graph/is_connected_graph.hpp
- /library/graph/is_connected_graph.hpp.html
title: graph/is_connected_graph.hpp
---
