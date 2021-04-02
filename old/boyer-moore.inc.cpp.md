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
  bundledCode: "#line 1 \"old/boyer-moore.inc.cpp\"\narray<int,26> bm_build_skip(string\
    \ const & pattern) { // O(m)\n    int m = pattern.length();\n    array<int,26>\
    \ skip = {};\n    repeat (i,m) skip[pattern[i]-'a'] = m-i-1;\n    return skip;\n\
    }\nvector<int> bm_build_next(string const & pattern) { // O(m)\n    int m = pattern.length();\n\
    \    int g[m]; fill(g, g+m, m);\n    vector<int> next(m);\n    repeat (i,m) next[i]\
    \ = 2*m-i-1;\n    int j = m;\n    for (int i = m-1; i >= 0; --i, --j) {\n    \
    \    g[i] = j;\n        while (j < m and pattern[j] != pattern[i]) {\n       \
    \     next[j] = min(next[j], m-i-1);\n            j = g[j];\n        }\n    }\n\
    \    repeat (i,m) {\n        next[i] = min(next[i], j+m-i);\n        if (i >=\
    \ j) j = g[j];\n    }\n    return next;\n}\nint bm_match(string const & target,\
    \ string const & pattern, array<int,26> const & skip, vector<int> const & next)\
    \ { // O(nm)\n    int n = target.length();\n    int m = pattern.length();\n  \
    \  int result = 0;\n    for (int i = m-1; i < n; ) {\n        int j = m-1;\n \
    \       while (j >= 0 and target[i] == pattern[j]) { --i; --j; }\n        if (j\
    \ < 0) {\n            ++ result; // match at text[i+1, ..., i+m]\n           \
    \ i += m + 1;\n        } else {\n            i += max(skip[target[i]-'a'], next[j]);\n\
    \        }\n    }\n    return result;\n}\nint bm_match(string const & target,\
    \ string const & pattern) { // Boyer-Moore\n    return bm_match(target, pattern,\
    \ bm_build_skip(pattern), bm_build_next(pattern));\n}\n"
  code: "array<int,26> bm_build_skip(string const & pattern) { // O(m)\n    int m\
    \ = pattern.length();\n    array<int,26> skip = {};\n    repeat (i,m) skip[pattern[i]-'a']\
    \ = m-i-1;\n    return skip;\n}\nvector<int> bm_build_next(string const & pattern)\
    \ { // O(m)\n    int m = pattern.length();\n    int g[m]; fill(g, g+m, m);\n \
    \   vector<int> next(m);\n    repeat (i,m) next[i] = 2*m-i-1;\n    int j = m;\n\
    \    for (int i = m-1; i >= 0; --i, --j) {\n        g[i] = j;\n        while (j\
    \ < m and pattern[j] != pattern[i]) {\n            next[j] = min(next[j], m-i-1);\n\
    \            j = g[j];\n        }\n    }\n    repeat (i,m) {\n        next[i]\
    \ = min(next[i], j+m-i);\n        if (i >= j) j = g[j];\n    }\n    return next;\n\
    }\nint bm_match(string const & target, string const & pattern, array<int,26> const\
    \ & skip, vector<int> const & next) { // O(nm)\n    int n = target.length();\n\
    \    int m = pattern.length();\n    int result = 0;\n    for (int i = m-1; i <\
    \ n; ) {\n        int j = m-1;\n        while (j >= 0 and target[i] == pattern[j])\
    \ { --i; --j; }\n        if (j < 0) {\n            ++ result; // match at text[i+1,\
    \ ..., i+m]\n            i += m + 1;\n        } else {\n            i += max(skip[target[i]-'a'],\
    \ next[j]);\n        }\n    }\n    return result;\n}\nint bm_match(string const\
    \ & target, string const & pattern) { // Boyer-Moore\n    return bm_match(target,\
    \ pattern, bm_build_skip(pattern), bm_build_next(pattern));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/boyer-moore.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/boyer-moore.inc.cpp
layout: document
redirect_from:
- /library/old/boyer-moore.inc.cpp
- /library/old/boyer-moore.inc.cpp.html
title: old/boyer-moore.inc.cpp
---
