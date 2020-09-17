---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://yukicoder.me/problems/no/260
  bundledCode: "#line 1 \"old/digit-dp.inc.cpp\"\n// http://yukicoder.me/problems/no/260\n\
    // strmodin(s, a, b, m)[i][j] = the number of digits t in mod m  for  t \\le s,\
    \ i = t \\bmod \\prod a and t contains digits j \\subset b\nvector<vector<ll>\
    \ > strmodin(string const & s, int a, vector<int> const & b, ll m) {\n    int\
    \ pow_b = 1 << b.size();\n    array<int,10> table = {};\n    repeat (d,10) {\n\
    \        auto it = whole(find, b, d);\n        if (it != b.end()) table[d] |=\
    \ 1 << (it - b.begin());\n    }\n    auto cur = vectors(a, pow_b, ll());\n   \
    \ auto prv = vectors(a, pow_b, ll());\n    int bound_i = 0, bound_j = 0;\n   \
    \ for (char c : s) {\n        c -= '0';\n        cur.swap(prv);\n        repeat\
    \ (d, c) cur[(bound_i * 10 + d) % a][bound_j | table[d]] += 1;\n        bound_i\
    \ = (bound_i * 10 + c) % a;\n        bound_j |= table[c];\n        repeat (i,a)\
    \ repeat (j,pow_b) {\n            repeat (d,10) {\n                ll & it = cur[(i\
    \ * 10 + d) % a][j | table[d]];\n                it = (it + prv[i][j]) % m;\n\
    \            }\n            prv[i][j] = 0;\n        }\n    }\n    cur[bound_i][bound_j]\
    \ += 1;\n    cur[bound_i][bound_j] %= m;\n    return cur;\n}\n"
  code: "// http://yukicoder.me/problems/no/260\n// strmodin(s, a, b, m)[i][j] = the\
    \ number of digits t in mod m  for  t \\le s, i = t \\bmod \\prod a and t contains\
    \ digits j \\subset b\nvector<vector<ll> > strmodin(string const & s, int a, vector<int>\
    \ const & b, ll m) {\n    int pow_b = 1 << b.size();\n    array<int,10> table\
    \ = {};\n    repeat (d,10) {\n        auto it = whole(find, b, d);\n        if\
    \ (it != b.end()) table[d] |= 1 << (it - b.begin());\n    }\n    auto cur = vectors(a,\
    \ pow_b, ll());\n    auto prv = vectors(a, pow_b, ll());\n    int bound_i = 0,\
    \ bound_j = 0;\n    for (char c : s) {\n        c -= '0';\n        cur.swap(prv);\n\
    \        repeat (d, c) cur[(bound_i * 10 + d) % a][bound_j | table[d]] += 1;\n\
    \        bound_i = (bound_i * 10 + c) % a;\n        bound_j |= table[c];\n   \
    \     repeat (i,a) repeat (j,pow_b) {\n            repeat (d,10) {\n         \
    \       ll & it = cur[(i * 10 + d) % a][j | table[d]];\n                it = (it\
    \ + prv[i][j]) % m;\n            }\n            prv[i][j] = 0;\n        }\n  \
    \  }\n    cur[bound_i][bound_j] += 1;\n    cur[bound_i][bound_j] %= m;\n    return\
    \ cur;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/digit-dp.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/digit-dp.inc.cpp
layout: document
redirect_from:
- /library/old/digit-dp.inc.cpp
- /library/old/digit-dp.inc.cpp.html
title: old/digit-dp.inc.cpp
---
