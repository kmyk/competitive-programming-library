---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/functional_graph.hpp
    title: "Namori cycle / \u306A\u3082\u308A\u9589\u8DEF"
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1254
    links:
    - https://yukicoder.me/problems/no/1254
  bundledCode: "#line 1 \"graph/functional_graph.yuki1254.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1254\"\n#include <cstdio>\n#include <map>\n\
    #include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 2 \"\
    graph/functional_graph.hpp\"\n#include <cassert>\n#include <deque>\n#include <functional>\n\
    #line 6 \"graph/functional_graph.hpp\"\n\n/**\n * @brief Namori cycle / \u306A\
    \u3082\u308A\u9589\u8DEF\n * @param g a simple connected undirected graph with\
    \ |E| = |V|\n */\nstd::deque<int> get_namori_cycle(const std::vector<std::vector<int>\
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
    \  }\n    return stk;\n}\n#line 8 \"graph/functional_graph.yuki1254.test.cpp\"\
    \nusing namespace std;\n\nvector<int> solve(int n, const vector<pair<int, int>\
    \ >& edges) {\n    vector<vector<int> > g(n);\n    map<pair<int, int>, int> lookup;\n\
    \    REP (i, edges.size()) {\n        auto [a, b] = edges[i];\n        g[a].push_back(b);\n\
    \        g[b].push_back(a);\n        lookup[make_pair(a, b)] = i;\n        lookup[make_pair(b,\
    \ a)] = i;\n    }\n\n    auto cycle = get_namori_cycle(g);\n    vector<int> ans;\n\
    \    REP (i, cycle.size()) {\n        int a = cycle[i];\n        int b = cycle[(i\
    \ + 1) % cycle.size()];\n        ans.push_back(lookup[make_pair(a, b)]);\n   \
    \ }\n    return ans;\n}\n\nint main() {\n    int n; scanf(\"%d\", &n);\n    vector<pair<int,\
    \ int> > edges(n);\n    REP (i, n) {\n        int a, b; scanf(\"%d%d\", &a, &b);\n\
    \        -- a;\n        -- b;\n        edges[i] = make_pair(a, b);\n    }\n  \
    \  vector<int> ans = solve(n, edges);\n    printf(\"%d\\n\", (int)ans.size());\n\
    \    REP (i, ans.size()) {\n        printf(\"%d%c\", ans[i] + 1, i + 1 < ans.size()\
    \ ? ' ' : '\\n');\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1254\"\n#include <cstdio>\n\
    #include <map>\n#include <utility>\n#include <vector>\n#include \"utils/macros.hpp\"\
    \n#include \"graph/functional_graph.hpp\"\nusing namespace std;\n\nvector<int>\
    \ solve(int n, const vector<pair<int, int> >& edges) {\n    vector<vector<int>\
    \ > g(n);\n    map<pair<int, int>, int> lookup;\n    REP (i, edges.size()) {\n\
    \        auto [a, b] = edges[i];\n        g[a].push_back(b);\n        g[b].push_back(a);\n\
    \        lookup[make_pair(a, b)] = i;\n        lookup[make_pair(b, a)] = i;\n\
    \    }\n\n    auto cycle = get_namori_cycle(g);\n    vector<int> ans;\n    REP\
    \ (i, cycle.size()) {\n        int a = cycle[i];\n        int b = cycle[(i + 1)\
    \ % cycle.size()];\n        ans.push_back(lookup[make_pair(a, b)]);\n    }\n \
    \   return ans;\n}\n\nint main() {\n    int n; scanf(\"%d\", &n);\n    vector<pair<int,\
    \ int> > edges(n);\n    REP (i, n) {\n        int a, b; scanf(\"%d%d\", &a, &b);\n\
    \        -- a;\n        -- b;\n        edges[i] = make_pair(a, b);\n    }\n  \
    \  vector<int> ans = solve(n, edges);\n    printf(\"%d\\n\", (int)ans.size());\n\
    \    REP (i, ans.size()) {\n        printf(\"%d%c\", ans[i] + 1, i + 1 < ans.size()\
    \ ? ' ' : '\\n');\n    }\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - graph/functional_graph.hpp
  isVerificationFile: true
  path: graph/functional_graph.yuki1254.test.cpp
  requiredBy: []
  timestamp: '2020-10-09 23:24:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: graph/functional_graph.yuki1254.test.cpp
layout: document
redirect_from:
- /verify/graph/functional_graph.yuki1254.test.cpp
- /verify/graph/functional_graph.yuki1254.test.cpp.html
title: graph/functional_graph.yuki1254.test.cpp
---
