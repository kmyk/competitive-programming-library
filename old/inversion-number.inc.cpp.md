---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/inversion-number.inc.cpp\"\nll inversion_number(vector<int>\
    \ const & a) {\n    int n = a.size();\n    binary_indexed_tree<plus_monoid> bit(n\
    \ + 1);\n    ll cnt = 0;\n    REP (i, n) {\n        cnt += i - bit.initial_range_concat(a[i]\
    \ + 1);\n        bit.point_append(a[i], 1);\n    }\n    return cnt;\n}\n"
  code: "ll inversion_number(vector<int> const & a) {\n    int n = a.size();\n   \
    \ binary_indexed_tree<plus_monoid> bit(n + 1);\n    ll cnt = 0;\n    REP (i, n)\
    \ {\n        cnt += i - bit.initial_range_concat(a[i] + 1);\n        bit.point_append(a[i],\
    \ 1);\n    }\n    return cnt;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/inversion-number.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/inversion-number.inc.cpp
layout: document
redirect_from:
- /library/old/inversion-number.inc.cpp
- /library/old/inversion-number.inc.cpp.html
title: old/inversion-number.inc.cpp
---
