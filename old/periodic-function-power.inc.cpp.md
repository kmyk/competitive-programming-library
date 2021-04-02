---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/periodic-function-power.inc.cpp\"\ntemplate <class F,\
    \ class T>\nT periodic_function_power(F f, ll k, T x) {\n    assert (k >= 1);\n\
    \    if (k == 1) return x;\n    vector<T> history;\n    unordered_map<T, int>\
    \ lookup;\n    history.push_back(x);\n    lookup[x] = 0;\n    for (int i = 1;\
    \ ; ++ i) {\n        T y = f(x);\n        if (i == k) return y;\n        if (lookup.count(y))\
    \ break;\n        history.push_back(y);\n        lookup[y] = lookup[x] + 1;\n\
    \        x = y;\n    }\n    T y = f(x);\n    int base = lookup[y];\n    int cycle\
    \ = lookup[x] + 1 - lookup[y];\n    return history[(k - base) % cycle + base];\n\
    }\n"
  code: "template <class F, class T>\nT periodic_function_power(F f, ll k, T x) {\n\
    \    assert (k >= 1);\n    if (k == 1) return x;\n    vector<T> history;\n   \
    \ unordered_map<T, int> lookup;\n    history.push_back(x);\n    lookup[x] = 0;\n\
    \    for (int i = 1; ; ++ i) {\n        T y = f(x);\n        if (i == k) return\
    \ y;\n        if (lookup.count(y)) break;\n        history.push_back(y);\n   \
    \     lookup[y] = lookup[x] + 1;\n        x = y;\n    }\n    T y = f(x);\n   \
    \ int base = lookup[y];\n    int cycle = lookup[x] + 1 - lookup[y];\n    return\
    \ history[(k - base) % cycle + base];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/periodic-function-power.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/periodic-function-power.inc.cpp
layout: document
redirect_from:
- /library/old/periodic-function-power.inc.cpp
- /library/old/periodic-function-power.inc.cpp.html
title: old/periodic-function-power.inc.cpp
---
