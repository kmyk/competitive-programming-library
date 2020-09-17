---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"old/suffix-array.inc.cpp\"\nint sa_lower_bound(string const\
    \ & s, vector<int> const & sa, string const & t) { // returns an index on suffix\
    \ array\n    int n = s.size();\n    int l = 0, r = n+1; // (l, r]\n    while (l\
    \ + 1 < r) {\n        int m = (l + r) / 2;\n        (s.compare(sa[m], string::npos,\
    \ t) < 0 ? l : r) = m;\n    }\n    return r;\n}\nint sa_prefix_upper_bound(string\
    \ const & s, vector<int> const & sa, string const & t) { // returns an index on\
    \ suffix array\n    int n = s.size();\n    int l = 0, r = n+1; // (l, r]\n   \
    \ while (l + 1 < r) {\n        int m = (l + r) / 2;\n        (s.compare(sa[m],\
    \ t.size(), t) <= 0 ? l : r) = m;\n    }\n    return r;\n}\nint sa_match(string\
    \ const & target, string const & pattern, vector<int> const & sa, segment_tree<int>\
    \ const & lcp) { // O(m \\log n)\n    int l = sa_lower_bound(target, sa, pattern);\n\
    \    int r = sa_prefix_upper_bound(target, sa, pattern);\n    return r - l;\n\
    }\n"
  code: "int sa_lower_bound(string const & s, vector<int> const & sa, string const\
    \ & t) { // returns an index on suffix array\n    int n = s.size();\n    int l\
    \ = 0, r = n+1; // (l, r]\n    while (l + 1 < r) {\n        int m = (l + r) /\
    \ 2;\n        (s.compare(sa[m], string::npos, t) < 0 ? l : r) = m;\n    }\n  \
    \  return r;\n}\nint sa_prefix_upper_bound(string const & s, vector<int> const\
    \ & sa, string const & t) { // returns an index on suffix array\n    int n = s.size();\n\
    \    int l = 0, r = n+1; // (l, r]\n    while (l + 1 < r) {\n        int m = (l\
    \ + r) / 2;\n        (s.compare(sa[m], t.size(), t) <= 0 ? l : r) = m;\n    }\n\
    \    return r;\n}\nint sa_match(string const & target, string const & pattern,\
    \ vector<int> const & sa, segment_tree<int> const & lcp) { // O(m \\log n)\n \
    \   int l = sa_lower_bound(target, sa, pattern);\n    int r = sa_prefix_upper_bound(target,\
    \ sa, pattern);\n    return r - l;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/suffix-array.inc.cpp
  requiredBy: []
  timestamp: '2020-03-04 13:12:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/suffix-array.inc.cpp
layout: document
redirect_from:
- /library/old/suffix-array.inc.cpp
- /library/old/suffix-array.inc.cpp.html
title: old/suffix-array.inc.cpp
---
