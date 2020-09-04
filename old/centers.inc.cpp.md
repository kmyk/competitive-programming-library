---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "get centers of a tree / \u6728\u306E\u4E2D\u5FC3"
  bundledCode: "#line 1 \"old/centers.inc.cpp\"\n/**\n * @brief get centers of a tree\
    \ / \u6728\u306E\u4E2D\u5FC3\n */\nvector<int> get_centers(vector<vector<int>\
    \ > const & tree) {\n    int n = tree.size();\n    vector<bool> used(n);\n   \
    \ vector<int> cur, prv;\n    REP (i, n) {\n        if (tree[i].size() <= 1) {\n\
    \            cur.push_back(i);\n            used[i] = true;\n        }\n    }\n\
    \    while (not cur.empty()) {\n        cur.swap(prv);\n        cur.clear();\n\
    \        for (int i : prv) {\n            for (int j : tree[i]) if (not used[j])\
    \ {\n                cur.push_back(j);\n                used[j] = true;\n    \
    \        }\n        }\n    }\n    return prv;\n}\n"
  code: "/**\n * @brief get centers of a tree / \u6728\u306E\u4E2D\u5FC3\n */\nvector<int>\
    \ get_centers(vector<vector<int> > const & tree) {\n    int n = tree.size();\n\
    \    vector<bool> used(n);\n    vector<int> cur, prv;\n    REP (i, n) {\n    \
    \    if (tree[i].size() <= 1) {\n            cur.push_back(i);\n            used[i]\
    \ = true;\n        }\n    }\n    while (not cur.empty()) {\n        cur.swap(prv);\n\
    \        cur.clear();\n        for (int i : prv) {\n            for (int j : tree[i])\
    \ if (not used[j]) {\n                cur.push_back(j);\n                used[j]\
    \ = true;\n            }\n        }\n    }\n    return prv;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/centers.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/centers.inc.cpp
layout: document
redirect_from:
- /library/old/centers.inc.cpp
- /library/old/centers.inc.cpp.html
title: "get centers of a tree / \u6728\u306E\u4E2D\u5FC3"
---
