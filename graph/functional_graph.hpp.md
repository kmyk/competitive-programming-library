---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: graph/functional_graph.yuki1254.test.cpp
    title: graph/functional_graph.yuki1254.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Namori cycle / \u306A\u3082\u308A\u9589\u8DEF"
    links: []
  bundledCode: "#line 2 \"graph/functional_graph.hpp\"\n#include <cassert>\n#include\
    \ <deque>\n#include <functional>\n#include <vector>\n\n/**\n * @brief Namori cycle\
    \ / \u306A\u3082\u308A\u9589\u8DEF\n * @param g a simple connected undirected\
    \ graph with |E| = |V|\n */\nstd::deque<int> get_namori_cycle(const std::vector<std::vector<int>\
    \ >& g) {\n    int n = g.size();\n    {  // check the namori-ty\n        int m\
    \ = 0;\n        REP (i, n) {\n            m += g[i].size();\n        }\n     \
    \   assert (m == 2 * n);\n    }\n\n    std::deque<int> stk;\n    std::vector<bool>\
    \ used(n);\n    auto go = [&](auto&& go, int i, int parent) -> int {\n       \
    \ if (used[i]) return i;\n        stk.push_back(i);\n        used[i] = true;\n\
    \        for (int j : g[i]) if (j != parent) {\n            int k = go(go, j,\
    \ i);\n            if (k != -1) return k;\n        }\n        assert (stk.back()\
    \ == i);\n        stk.pop_back();\n        used[i] = false;\n        return -1;\n\
    \    };\n    int i = go(go, 0, -1);\n    assert (i != -1);  // fails if the graph\
    \ is not simple\n    while (stk.front() != i) {\n        stk.pop_front();\n  \
    \  }\n    return stk;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <deque>\n#include <functional>\n\
    #include <vector>\n\n/**\n * @brief Namori cycle / \u306A\u3082\u308A\u9589\u8DEF\
    \n * @param g a simple connected undirected graph with |E| = |V|\n */\nstd::deque<int>\
    \ get_namori_cycle(const std::vector<std::vector<int> >& g) {\n    int n = g.size();\n\
    \    {  // check the namori-ty\n        int m = 0;\n        REP (i, n) {\n   \
    \         m += g[i].size();\n        }\n        assert (m == 2 * n);\n    }\n\n\
    \    std::deque<int> stk;\n    std::vector<bool> used(n);\n    auto go = [&](auto&&\
    \ go, int i, int parent) -> int {\n        if (used[i]) return i;\n        stk.push_back(i);\n\
    \        used[i] = true;\n        for (int j : g[i]) if (j != parent) {\n    \
    \        int k = go(go, j, i);\n            if (k != -1) return k;\n        }\n\
    \        assert (stk.back() == i);\n        stk.pop_back();\n        used[i] =\
    \ false;\n        return -1;\n    };\n    int i = go(go, 0, -1);\n    assert (i\
    \ != -1);  // fails if the graph is not simple\n    while (stk.front() != i) {\n\
    \        stk.pop_front();\n    }\n    return stk;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/functional_graph.hpp
  requiredBy: []
  timestamp: '2020-10-09 23:24:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - graph/functional_graph.yuki1254.test.cpp
documentation_of: graph/functional_graph.hpp
layout: document
redirect_from:
- /library/graph/functional_graph.hpp
- /library/graph/functional_graph.hpp.html
title: "Namori cycle / \u306A\u3082\u308A\u9589\u8DEF"
---
