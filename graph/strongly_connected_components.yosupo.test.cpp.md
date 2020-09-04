---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"graph/strongly_connected_components.yosupo.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#line 2 \"graph/strongly_connected_components.hpp\"\
    \n#include <functional>\n#include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 4 \"graph/transpose_graph.hpp\"\n\n/**\n * @param g is an adjacent list of a\
    \ digraph\n * @note $O(V + E)$\n * @see https://en.wikipedia.org/wiki/Transpose_graph\n\
    \ */\nstd::vector<std::vector<int> > make_transpose_graph(std::vector<std::vector<int>\
    \ > const & g) {\n    int n = g.size();\n    std::vector<std::vector<int> > h(n);\n\
    \    REP (i, n) {\n        for (int j : g[i]) {\n            h[j].push_back(i);\n\
    \        }\n    }\n    return h;\n}\n#line 7 \"graph/strongly_connected_components.hpp\"\
    \n\n/**\n * @brief strongly connected components decomposition, Kosaraju's algorithm\
    \ / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @return the pair (the number\
    \ k of components, the function from vertices of g to components)\n * @param g\
    \ is an adjacent list of a digraph\n * @param g_rev is the transpose graph of\
    \ g\n * @note $O(V + E)$\n */\nstd::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const\
    \ std::vector<std::vector<int> > & g, const std::vector<std::vector<int> > & g_rev)\
    \ {\n    int n = g.size();\n    std::vector<int> acc(n); {\n        std::vector<bool>\
    \ used(n);\n        std::function<void (int)> dfs = [&](int i) {\n           \
    \ used[i] = true;\n            for (int j : g[i]) if (not used[j]) dfs(j);\n \
    \           acc.push_back(i);\n        };\n        REP (i,n) if (not used[i])\
    \ dfs(i);\n        reverse(ALL(acc));\n    }\n    int size = 0;\n    std::vector<int>\
    \ component_of(n); {\n        std::vector<bool> used(n);\n        std::function<void\
    \ (int)> rdfs = [&](int i) {\n            used[i] = true;\n            component_of[i]\
    \ = size;\n            for (int j : g_rev[i]) if (not used[j]) rdfs(j);\n    \
    \    };\n        for (int i : acc) if (not used[i]) {\n            rdfs(i);\n\
    \            ++ size;\n        }\n    }\n    return { size, move(component_of)\
    \ };\n}\n\nstd::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const\
    \ std::vector<std::vector<int> > & g) {\n    return decompose_to_strongly_connected_components(g,\
    \ make_transpose_graph(g));\n}\n#line 5 \"graph/quotient_graph.hpp\"\n\n/**\n\
    \ * @param g is an adjacent list of a digraph\n * @param size is the size of equivalence\
    \ classes\n * @param component_of is the map from original vertices to equivalence\
    \ classes\n * @note $O(V + E)$\n * @see https://en.wikipedia.org/wiki/Quotient_graph\n\
    \ */\nstd::vector<std::vector<int> > make_quotient_graph(const std::vector<std::vector<int>\
    \ > & g, int size, const std::vector<int> & component_of) {\n    int n = g.size();\n\
    \    std::vector<std::vector<int> > h(size);\n    REP (i, n) for (int j : g[i])\
    \ {\n        if (component_of[i] != component_of[j]) {\n            h[component_of[i]].push_back(component_of[j]);\n\
    \        }\n    }\n    REP (k, size) {\n        std::sort(ALL(h[k]));\n      \
    \  h[k].erase(std::unique(ALL(h[k])), h[k].end());\n    }\n    return h;\n}\n\
    #line 2 \"graph/topological_sort.hpp\"\n#include <algorithm>\n#line 6 \"graph/topological_sort.hpp\"\
    \n\n/**\n * @brief topological sort\n * @return a list of vertices which sorted\
    \ topologically\n * @note the empty list is returned if cycles exist\n * @note\
    \ $O(V + E)$\n */\nstd::vector<int> topological_sort(const std::vector<std::vector<int>\
    \ > & g) {\n    int n = g.size();\n    std::vector<int> order;\n    std::vector<char>\
    \ used(n);\n    std::function<bool (int)> go = [&](int i) {\n        used[i] =\
    \ 1;  // in stack\n        for (int j : g[i]) {\n            if (used[j] == 1)\
    \ return true;\n            if (not used[j]) {\n                if (go(j)) return\
    \ true;\n            }\n        }\n        used[i] = 2;  // completely used\n\
    \        order.push_back(i);\n        return false;\n    };\n    REP (i, n) if\
    \ (not used[i]) {\n        if (go(i)) return std::vector<int>();\n    }\n    std::reverse(ALL(order));\n\
    \    return order;\n}\n#line 6 \"graph/strongly_connected_components.yosupo.test.cpp\"\
    \n#include <cassert>\n#include <cstdio>\n#line 9 \"graph/strongly_connected_components.yosupo.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    // input\n    int n, m; scanf(\"%d%d\"\
    , &n, &m);\n    vector<vector<int> > g(n);\n    REP (i, m) {\n        int a, b;\
    \ scanf(\"%d%d\", &a, &b);\n        g[a].push_back(b);\n    }\n\n    // solve\n\
    \    int size; vector<int> component_of; tie(size, component_of) = decompose_to_strongly_connected_components(g);\n\
    \    vector<vector<int> > component(size);\n    REP (i, n) {\n        component[component_of[i]].push_back(i);\n\
    \    }\n    vector<vector<int> > h = make_quotient_graph(g, size, component_of);\n\
    \    vector<int> order = topological_sort(h);\n    assert (order.size() == size);\n\
    \n    // output\n    printf(\"%d\\n\", size);\n    for (int a : order) {\n   \
    \     printf(\"%d\", (int)component[a].size());\n        for (int i : component[a])\
    \ {\n            printf(\" %d\", i);\n        }\n        printf(\"\\n\");\n  \
    \  }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"graph/strongly_connected_components.hpp\"\
    \n#include \"graph/quotient_graph.hpp\"\n#include \"graph/topological_sort.hpp\"\
    \n#include \"utils/macros.hpp\"\n#include <cassert>\n#include <cstdio>\n#include\
    \ <vector>\nusing namespace std;\n\nint main() {\n    // input\n    int n, m;\
    \ scanf(\"%d%d\", &n, &m);\n    vector<vector<int> > g(n);\n    REP (i, m) {\n\
    \        int a, b; scanf(\"%d%d\", &a, &b);\n        g[a].push_back(b);\n    }\n\
    \n    // solve\n    int size; vector<int> component_of; tie(size, component_of)\
    \ = decompose_to_strongly_connected_components(g);\n    vector<vector<int> > component(size);\n\
    \    REP (i, n) {\n        component[component_of[i]].push_back(i);\n    }\n \
    \   vector<vector<int> > h = make_quotient_graph(g, size, component_of);\n   \
    \ vector<int> order = topological_sort(h);\n    assert (order.size() == size);\n\
    \n    // output\n    printf(\"%d\\n\", size);\n    for (int a : order) {\n   \
    \     printf(\"%d\", (int)component[a].size());\n        for (int i : component[a])\
    \ {\n            printf(\" %d\", i);\n        }\n        printf(\"\\n\");\n  \
    \  }\n    return 0;\n}\n"
  dependsOn:
  - graph/strongly_connected_components.hpp
  - graph/transpose_graph.hpp
  - utils/macros.hpp
  - graph/quotient_graph.hpp
  - graph/topological_sort.hpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "strongly connected components decomposition, Kosaraju's algorithm / \u5F37\
      \u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/transpose_graph.hpp
    title: graph/transpose_graph.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  - icon: ':heavy_check_mark:'
    path: graph/quotient_graph.hpp
    title: graph/quotient_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/topological_sort.hpp
    title: topological sort
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: graph/strongly_connected_components.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-02-22 23:03:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: graph/strongly_connected_components.yosupo.test.cpp
layout: document
redirect_from:
- /verify/graph/strongly_connected_components.yosupo.test.cpp
- /verify/graph/strongly_connected_components.yosupo.test.cpp.html
title: graph/strongly_connected_components.yosupo.test.cpp
---
