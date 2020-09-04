---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"old/maximum-independent-set.inc.cpp\"\n/**\n * @see https://www.slideshare.net/wata_orz/ss-12131479\n\
    \ * @note O(1.466^n n)\n * @param g is an adjacency matrix\n */\nint maximum_independent_set(vector<vector<bool>\
    \ > const & g) {\n    int n = g.size();\n    function<int (int, vector<bool> const\
    \ &)> go = [&](int i, vector<bool> used) {\n        while (i < n and used[i])\
    \ ++ i;\n        if (i == n) return 0;\n        int degree = 0;\n        repeat_from\
    \ (j, i + 1, n) {\n            degree += (not used[j] and g[i][j]);\n        }\n\
    \        int result = 0;\n        used[i] = true;\n        if (degree >= 2) {\n\
    \            setmax(result, go(i + 1, used));  // don't use i\n        }\n   \
    \     repeat_from (j, i + 1, n) {\n            used[j] = (used[j] or g[i][j]);\n\
    \        }\n        setmax(result, 1 + go(i + 1, used));  // use i\n        return\
    \ result;\n    };\n    return go(0, vector<bool>(n));\n}\n"
  code: "/**\n * @see https://www.slideshare.net/wata_orz/ss-12131479\n * @note O(1.466^n\
    \ n)\n * @param g is an adjacency matrix\n */\nint maximum_independent_set(vector<vector<bool>\
    \ > const & g) {\n    int n = g.size();\n    function<int (int, vector<bool> const\
    \ &)> go = [&](int i, vector<bool> used) {\n        while (i < n and used[i])\
    \ ++ i;\n        if (i == n) return 0;\n        int degree = 0;\n        repeat_from\
    \ (j, i + 1, n) {\n            degree += (not used[j] and g[i][j]);\n        }\n\
    \        int result = 0;\n        used[i] = true;\n        if (degree >= 2) {\n\
    \            setmax(result, go(i + 1, used));  // don't use i\n        }\n   \
    \     repeat_from (j, i + 1, n) {\n            used[j] = (used[j] or g[i][j]);\n\
    \        }\n        setmax(result, 1 + go(i + 1, used));  // use i\n        return\
    \ result;\n    };\n    return go(0, vector<bool>(n));\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/maximum-independent-set.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/maximum-independent-set.inc.cpp
layout: document
redirect_from:
- /library/old/maximum-independent-set.inc.cpp
- /library/old/maximum-independent-set.inc.cpp.html
title: old/maximum-independent-set.inc.cpp
---
