---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: graph/cartesian_tree.yukicoder-1031.test.cpp
    title: graph/cartesian_tree.yukicoder-1031.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/format.hpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i\
    \ = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) <\
    \ (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 6 \"graph/format.hpp\"\
    \n\nstd::pair<std::vector<std::vector<int> >, int> children_from_parent(const\
    \ std::vector<int> & parent) {\n    int n = parent.size();\n    std::vector<std::vector<int>\
    \ > children(n);\n    int root = -1;\n    REP (x, n) {\n        if (parent[x]\
    \ == -1) {\n            assert (root == -1);\n            root = x;\n        }\
    \ else {\n            children[parent[x]].push_back(x);\n        }\n    }\n  \
    \  assert (root != -1);\n    return std::make_pair(children, root);\n}\n\nstd::vector<std::vector<int>\
    \ > adjacent_list_from_children(const std::vector<std::vector<int> > & children)\
    \ {\n    int n = children.size();\n    std::vector<std::vector<int> > g(n);\n\
    \    REP (x, n) {\n        for (int y : children[x]) {\n            g[x].push_back(y);\n\
    \            g[y].push_back(x);\n        }\n    }\n    return g;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../utils/macros.hpp\"\n\nstd::pair<std::vector<std::vector<int> >,\
    \ int> children_from_parent(const std::vector<int> & parent) {\n    int n = parent.size();\n\
    \    std::vector<std::vector<int> > children(n);\n    int root = -1;\n    REP\
    \ (x, n) {\n        if (parent[x] == -1) {\n            assert (root == -1);\n\
    \            root = x;\n        } else {\n            children[parent[x]].push_back(x);\n\
    \        }\n    }\n    assert (root != -1);\n    return std::make_pair(children,\
    \ root);\n}\n\nstd::vector<std::vector<int> > adjacent_list_from_children(const\
    \ std::vector<std::vector<int> > & children) {\n    int n = children.size();\n\
    \    std::vector<std::vector<int> > g(n);\n    REP (x, n) {\n        for (int\
    \ y : children[x]) {\n            g[x].push_back(y);\n            g[y].push_back(x);\n\
    \        }\n    }\n    return g;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/format.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - graph/cartesian_tree.yukicoder-1031.test.cpp
documentation_of: graph/format.hpp
layout: document
redirect_from:
- /library/graph/format.hpp
- /library/graph/format.hpp.html
title: graph/format.hpp
---
