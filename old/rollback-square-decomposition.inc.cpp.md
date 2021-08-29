---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: old/rollback-square-decomposition.yukicoder-1031.test.cpp
    title: old/rollback-square-decomposition.yukicoder-1031.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: the extended Mo's algorithm
    links:
    - http://codeforces.com/blog/entry/7383?#comment-161520
    - http://snuke.hatenablog.com/entry/2016/07/01/000000
  bundledCode: "#line 1 \"old/rollback-square-decomposition.inc.cpp\"\n/**\n * @brief\
    \ the extended Mo's algorithm\n * @arg stupid is called O(Q) times, each length\
    \ is O(\\sqrt{N})\n * @arg mo si the following:\n *     struct rollback_mo_interface\
    \ {\n *         void reset(int l);  // called O(N) times\n *         void extend_left(\
    \ int l, int r);  // called O(Q) times, the sum of length is O(N \\sqrt {N})\n\
    \ *         void extend_right(int l, int r);  // called O(Q) times, the sum of\
    \ length is O(Q \\sqrt {N})\n *         void snapshot();  // called O(Q) times\n\
    \ *         void rollback();  // called O(Q) times\n *         void query(); \
    \    // called O(Q) times\n *     };\n * @see http://snuke.hatenablog.com/entry/2016/07/01/000000\n\
    \ * @see http://codeforces.com/blog/entry/7383?#comment-161520\n */\ntemplate\
    \ <class Func, class RollbackMoInterface>\nvoid rollback_square_decomposition(int\
    \ n, vector<pair<int, int> > const & range, RollbackMoInterface & mo, Func stupid)\
    \ {\n    int bucket_size = sqrt(n);\n    int bucket_count = (n + bucket_size -\
    \ 1) / bucket_size;\n    vector<vector<int> > bucket(bucket_count);\n    REP (i,\
    \ int(range.size())) {\n        int l, r; tie(l, r) = range[i];\n        if (r\
    \ - l <= bucket_size) {\n            stupid(l, r);\n        } else {\n       \
    \     bucket[l / bucket_size].push_back(i);\n        }\n    }\n    REP (b, bucket_count)\
    \ {\n        sort(ALL(bucket[b]), [&](int i, int j) { return range[i].second <\
    \ range[j].second; });\n        int l = (b + 1) * bucket_size;\n        mo.reset(l);\n\
    \        int r = l;\n        for (int i : bucket[b]) {\n            int l_i, r_i;\
    \ tie(l_i, r_i) = range[i];\n            mo.extend_right(r, r_i);\n          \
    \  mo.snapshot();\n            mo.extend_left(l_i, l);\n            mo.query();\n\
    \            mo.rollback();\n            r = r_i;\n        }\n    }\n}\n"
  code: "/**\n * @brief the extended Mo's algorithm\n * @arg stupid is called O(Q)\
    \ times, each length is O(\\sqrt{N})\n * @arg mo si the following:\n *     struct\
    \ rollback_mo_interface {\n *         void reset(int l);  // called O(N) times\n\
    \ *         void extend_left( int l, int r);  // called O(Q) times, the sum of\
    \ length is O(N \\sqrt {N})\n *         void extend_right(int l, int r);  // called\
    \ O(Q) times, the sum of length is O(Q \\sqrt {N})\n *         void snapshot();\
    \  // called O(Q) times\n *         void rollback();  // called O(Q) times\n *\
    \         void query();     // called O(Q) times\n *     };\n * @see http://snuke.hatenablog.com/entry/2016/07/01/000000\n\
    \ * @see http://codeforces.com/blog/entry/7383?#comment-161520\n */\ntemplate\
    \ <class Func, class RollbackMoInterface>\nvoid rollback_square_decomposition(int\
    \ n, vector<pair<int, int> > const & range, RollbackMoInterface & mo, Func stupid)\
    \ {\n    int bucket_size = sqrt(n);\n    int bucket_count = (n + bucket_size -\
    \ 1) / bucket_size;\n    vector<vector<int> > bucket(bucket_count);\n    REP (i,\
    \ int(range.size())) {\n        int l, r; tie(l, r) = range[i];\n        if (r\
    \ - l <= bucket_size) {\n            stupid(l, r);\n        } else {\n       \
    \     bucket[l / bucket_size].push_back(i);\n        }\n    }\n    REP (b, bucket_count)\
    \ {\n        sort(ALL(bucket[b]), [&](int i, int j) { return range[i].second <\
    \ range[j].second; });\n        int l = (b + 1) * bucket_size;\n        mo.reset(l);\n\
    \        int r = l;\n        for (int i : bucket[b]) {\n            int l_i, r_i;\
    \ tie(l_i, r_i) = range[i];\n            mo.extend_right(r, r_i);\n          \
    \  mo.snapshot();\n            mo.extend_left(l_i, l);\n            mo.query();\n\
    \            mo.rollback();\n            r = r_i;\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/rollback-square-decomposition.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - old/rollback-square-decomposition.yukicoder-1031.test.cpp
documentation_of: old/rollback-square-decomposition.inc.cpp
layout: document
redirect_from:
- /library/old/rollback-square-decomposition.inc.cpp
- /library/old/rollback-square-decomposition.inc.cpp.html
title: the extended Mo's algorithm
---
