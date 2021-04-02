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
  bundledCode: "#line 1 \"old/longest-increasing-subsequence.inc.cpp\"\ntemplate <typename\
    \ T>\nvector<T> longest_strict_increasing_subsequence(vector<T> const & xs) {\n\
    \    vector<T> l;  // l[i] is the last element of the increasing subsequence whose\
    \ length is i + 1\n    l.push_back(xs.front());\n    for (auto && x : xs) {\n\
    \        auto it = lower_bound(l.begin(), l.end(), x);\n        if (it == l.end())\
    \ {\n            l.push_back(x);\n        } else {\n            *it = x;\n   \
    \     }\n    }\n    return l;\n}\n\ntemplate <typename T>\nvector<T> longest_weak_increasing_subsequence(vector<T>\
    \ const & xs) {\n    vector<T> l;\n    for (auto && x : xs) {\n        auto it\
    \ = upper_bound(l.begin(), l.end(), x);\n        if (it == l.end()) {\n      \
    \      l.push_back(x);\n        } else {\n            *it = x;\n        }\n  \
    \  }\n    return l;\n}\n"
  code: "template <typename T>\nvector<T> longest_strict_increasing_subsequence(vector<T>\
    \ const & xs) {\n    vector<T> l;  // l[i] is the last element of the increasing\
    \ subsequence whose length is i + 1\n    l.push_back(xs.front());\n    for (auto\
    \ && x : xs) {\n        auto it = lower_bound(l.begin(), l.end(), x);\n      \
    \  if (it == l.end()) {\n            l.push_back(x);\n        } else {\n     \
    \       *it = x;\n        }\n    }\n    return l;\n}\n\ntemplate <typename T>\n\
    vector<T> longest_weak_increasing_subsequence(vector<T> const & xs) {\n    vector<T>\
    \ l;\n    for (auto && x : xs) {\n        auto it = upper_bound(l.begin(), l.end(),\
    \ x);\n        if (it == l.end()) {\n            l.push_back(x);\n        } else\
    \ {\n            *it = x;\n        }\n    }\n    return l;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/longest-increasing-subsequence.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/longest-increasing-subsequence.inc.cpp
layout: document
redirect_from:
- /library/old/longest-increasing-subsequence.inc.cpp
- /library/old/longest-increasing-subsequence.inc.cpp.html
title: old/longest-increasing-subsequence.inc.cpp
---
