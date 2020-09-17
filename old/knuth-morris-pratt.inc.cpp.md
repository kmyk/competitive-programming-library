---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Morris-Pratt algorithm
    links: []
  bundledCode: "#line 1 \"old/knuth-morris-pratt.inc.cpp\"\n/**\n * @brief Morris-Pratt\
    \ algorithm\n * @description compute the list of the lengthes of the longest borders\n\
    \ * @note O(N)\n */\ntemplate <class Iterator>\nvector<int> morris_pratt(Iterator\
    \ first, Iterator last) {\n    int length = distance(first, last);\n    vector<int>\
    \ border(length + 1);\n    border[0] = -1;\n    int j = -1;\n    REP (i, length)\
    \ {\n        while (j >= 0 and pattern[i] != pattern[j]) {\n            j = border[j];\n\
    \        }\n        ++ j;\n        border[i + 1] = j;\n    }\n    return border;\n\
    }\n\n/*\nvector<int> kmp_build_fail(string const & pattern) { // O(m)\n    int\
    \ m = pattern.size();\n    vector<int> fali(m+1);\n    fail[0] = -1;\n    int\
    \ j = -1;\n    repeat (i,m) {\n        while (j >= 0 and pattern[i] != pattern[j])\
    \ j = fail[j];\n        fail[i+1] = ++ j;\n    }\n    return fail;\n}\nint kmp_match(string\
    \ const & target, string const & pattern, vector<int> const & fail) { // O(n+m)\n\
    \    int n = target.length();\n    int m = pattern.length();\n    int result =\
    \ 0;\n    for (int i = 0, k = 0; i < n; ++ i) {\n        while (k >= 0 and pattern[k]\
    \ != target[i]) k = fail[k];\n        if (++ k >= m) {\n            ++ result;\
    \ // match at t[i-m+1 .. i]\n            k = fail[k];\n        }\n    }\n    return\
    \ result;\n}\nint kmp_match(string const & target, string const & pattern) {\n\
    \    return kmp_match(target, pattern, kmp_build_fail(pattern));\n}\n*/\n"
  code: "/**\n * @brief Morris-Pratt algorithm\n * @description compute the list of\
    \ the lengthes of the longest borders\n * @note O(N)\n */\ntemplate <class Iterator>\n\
    vector<int> morris_pratt(Iterator first, Iterator last) {\n    int length = distance(first,\
    \ last);\n    vector<int> border(length + 1);\n    border[0] = -1;\n    int j\
    \ = -1;\n    REP (i, length) {\n        while (j >= 0 and pattern[i] != pattern[j])\
    \ {\n            j = border[j];\n        }\n        ++ j;\n        border[i +\
    \ 1] = j;\n    }\n    return border;\n}\n\n/*\nvector<int> kmp_build_fail(string\
    \ const & pattern) { // O(m)\n    int m = pattern.size();\n    vector<int> fali(m+1);\n\
    \    fail[0] = -1;\n    int j = -1;\n    repeat (i,m) {\n        while (j >= 0\
    \ and pattern[i] != pattern[j]) j = fail[j];\n        fail[i+1] = ++ j;\n    }\n\
    \    return fail;\n}\nint kmp_match(string const & target, string const & pattern,\
    \ vector<int> const & fail) { // O(n+m)\n    int n = target.length();\n    int\
    \ m = pattern.length();\n    int result = 0;\n    for (int i = 0, k = 0; i < n;\
    \ ++ i) {\n        while (k >= 0 and pattern[k] != target[i]) k = fail[k];\n \
    \       if (++ k >= m) {\n            ++ result; // match at t[i-m+1 .. i]\n \
    \           k = fail[k];\n        }\n    }\n    return result;\n}\nint kmp_match(string\
    \ const & target, string const & pattern) {\n    return kmp_match(target, pattern,\
    \ kmp_build_fail(pattern));\n}\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: old/knuth-morris-pratt.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/knuth-morris-pratt.inc.cpp
layout: document
redirect_from:
- /library/old/knuth-morris-pratt.inc.cpp
- /library/old/knuth-morris-pratt.inc.cpp.html
title: Morris-Pratt algorithm
---
