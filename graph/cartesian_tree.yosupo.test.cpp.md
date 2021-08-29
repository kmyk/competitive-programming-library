---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/cartesian_tree.hpp
    title: Cartesian tree ($O(n)$)
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"graph/cartesian_tree.yosupo.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#include <cstdio>\n#include\
    \ <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i)\
    \ < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n\
    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 2 \"graph/cartesian_tree.hpp\"\n#include\
    \ <functional>\n#line 5 \"graph/cartesian_tree.hpp\"\n\n/**\n * @brief Cartesian\
    \ tree ($O(n)$)\n * @note the smallest value is the root\n * @note if a is not\
    \ distinct, the way for tie-break is undefined\n * @return the binary tree as\
    \ the list of parents\n */\ntemplate <class T, class Comparator = std::less<int>\
    \ >\nstd::vector<int> construct_cartesian_tree(const std::vector<T> & a, const\
    \ Comparator & cmp = Comparator()) {\n    int n = a.size();\n    std::vector<int>\
    \ parent(n, -1);\n    REP3 (i, 1, n) {\n        int p = i - 1;  // parent of i\n\
    \        int l = -1;  // left child of i\n        while (p != -1 and cmp(a[i],\
    \ a[p])) {\n            int pp = parent[p];  // parent of parent of i\n      \
    \      if (l != -1) {\n                parent[l] = p;\n            }\n       \
    \     parent[p] = i;\n            l = p;\n            p = pp;\n        }\n   \
    \     parent[i] = p;\n    }\n    return parent;\n}\n#line 6 \"graph/cartesian_tree.yosupo.test.cpp\"\
    \n\nint main(){\n    // input\n    int n; scanf(\"%d\", &n);\n    std::vector<int>\
    \ a(n);\n    REP (i, n) {\n        scanf(\"%d\", &a[i]);\n    }\n\n    // solve\n\
    \    std::vector<int> p = construct_cartesian_tree(a);\n\n    // output\n    REP\
    \ (i, n) {\n        printf(\"%d%c\", p[i] == -1 ? i : p[i], i + 1 < n ? ' ' :\
    \ '\\n');\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#include\
    \ <cstdio>\n#include <vector>\n#include \"../utils/macros.hpp\"\n#include \"../graph/cartesian_tree.hpp\"\
    \n\nint main(){\n    // input\n    int n; scanf(\"%d\", &n);\n    std::vector<int>\
    \ a(n);\n    REP (i, n) {\n        scanf(\"%d\", &a[i]);\n    }\n\n    // solve\n\
    \    std::vector<int> p = construct_cartesian_tree(a);\n\n    // output\n    REP\
    \ (i, n) {\n        printf(\"%d%c\", p[i] == -1 ? i : p[i], i + 1 < n ? ' ' :\
    \ '\\n');\n    }\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - graph/cartesian_tree.hpp
  isVerificationFile: true
  path: graph/cartesian_tree.yosupo.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: graph/cartesian_tree.yosupo.test.cpp
layout: document
redirect_from:
- /verify/graph/cartesian_tree.yosupo.test.cpp
- /verify/graph/cartesian_tree.yosupo.test.cpp.html
title: graph/cartesian_tree.yosupo.test.cpp
---
