---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "get the namori cycle / \u306A\u3082\u308A\u9589\u8DEF"
  bundledCode: "#line 1 \"old/namori-graph.inc.cpp\"\n/**\n * @brief get the namori\
    \ cycle / \u306A\u3082\u308A\u9589\u8DEF\n * @param g a simple connected undirected\
    \ graph with |E| = |V|\n */\ndeque<int> get_namori_cycle(vector<vector<int> >\
    \ const & g) {\n    int n = g.size();\n    { int m = 0; REP (i, n) m += g[i].size();\
    \ assert (m == 2 * n); }  // assume the namori-ty\n    deque<int> stk;\n    vector<bool>\
    \ used(n);\n    function<void (int, int)> go = [&](int i, int parent) {\n    \
    \    if (used[i]) throw i;\n        stk.push_back(i);\n        used[i] = true;\n\
    \        for (int j : g[i]) if (j != parent) {\n            go(j, i);\n      \
    \  }\n        assert (stk.back() == i);\n        stk.pop_back();\n        used[i]\
    \ = false;\n    };\n    try {\n        go(0, -1);\n        assert (false);  //\
    \ fails if the graph is not simple\n    } catch (int i) {\n        while (stk.front()\
    \ != i) {\n            stk.pop_front();\n        }\n    }\n    return stk;\n}\n\
    unittest {\n    vector<vector<int> > g(10);\n    auto add_edge = [&](int i, int\
    \ j) {\n        g[i].push_back(j);\n        g[j].push_back(i);\n    };\n    add_edge(0,\
    \ 5);\n    add_edge(1, 7);\n    add_edge(2, 7);\n    add_edge(3, 8);\n    add_edge(4,\
    \ 5);\n    add_edge(5, 9);\n    add_edge(6, 7);\n    add_edge(7, 8);\n    add_edge(8,\
    \ 9);\n    add_edge(3, 1);\n    assert (get_namori_cycle(g) == deque<int>({ 8,\
    \ 3, 1, 7 }));\n}\nunittest {\n    vector<vector<int> > g(10);\n    auto add_edge\
    \ = [&](int i, int j) {\n        g[i].push_back(j);\n        g[j].push_back(i);\n\
    \    };\n    add_edge(0, 1);\n    add_edge(1, 2);\n    add_edge(1, 3);\n    add_edge(2,\
    \ 4);\n    add_edge(3, 5);\n    add_edge(4, 6);\n    add_edge(6, 2);\n    add_edge(6,\
    \ 7);\n    add_edge(7, 8);\n    add_edge(8, 9);\n    assert (get_namori_cycle(g)\
    \ == deque<int>({ 2, 4, 6 }));\n}\n"
  code: "/**\n * @brief get the namori cycle / \u306A\u3082\u308A\u9589\u8DEF\n *\
    \ @param g a simple connected undirected graph with |E| = |V|\n */\ndeque<int>\
    \ get_namori_cycle(vector<vector<int> > const & g) {\n    int n = g.size();\n\
    \    { int m = 0; REP (i, n) m += g[i].size(); assert (m == 2 * n); }  // assume\
    \ the namori-ty\n    deque<int> stk;\n    vector<bool> used(n);\n    function<void\
    \ (int, int)> go = [&](int i, int parent) {\n        if (used[i]) throw i;\n \
    \       stk.push_back(i);\n        used[i] = true;\n        for (int j : g[i])\
    \ if (j != parent) {\n            go(j, i);\n        }\n        assert (stk.back()\
    \ == i);\n        stk.pop_back();\n        used[i] = false;\n    };\n    try {\n\
    \        go(0, -1);\n        assert (false);  // fails if the graph is not simple\n\
    \    } catch (int i) {\n        while (stk.front() != i) {\n            stk.pop_front();\n\
    \        }\n    }\n    return stk;\n}\nunittest {\n    vector<vector<int> > g(10);\n\
    \    auto add_edge = [&](int i, int j) {\n        g[i].push_back(j);\n       \
    \ g[j].push_back(i);\n    };\n    add_edge(0, 5);\n    add_edge(1, 7);\n    add_edge(2,\
    \ 7);\n    add_edge(3, 8);\n    add_edge(4, 5);\n    add_edge(5, 9);\n    add_edge(6,\
    \ 7);\n    add_edge(7, 8);\n    add_edge(8, 9);\n    add_edge(3, 1);\n    assert\
    \ (get_namori_cycle(g) == deque<int>({ 8, 3, 1, 7 }));\n}\nunittest {\n    vector<vector<int>\
    \ > g(10);\n    auto add_edge = [&](int i, int j) {\n        g[i].push_back(j);\n\
    \        g[j].push_back(i);\n    };\n    add_edge(0, 1);\n    add_edge(1, 2);\n\
    \    add_edge(1, 3);\n    add_edge(2, 4);\n    add_edge(3, 5);\n    add_edge(4,\
    \ 6);\n    add_edge(6, 2);\n    add_edge(6, 7);\n    add_edge(7, 8);\n    add_edge(8,\
    \ 9);\n    assert (get_namori_cycle(g) == deque<int>({ 2, 4, 6 }));\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/namori-graph.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/namori-graph.inc.cpp
layout: document
redirect_from:
- /library/old/namori-graph.inc.cpp
- /library/old/namori-graph.inc.cpp.html
title: "get the namori cycle / \u306A\u3082\u308A\u9589\u8DEF"
---
