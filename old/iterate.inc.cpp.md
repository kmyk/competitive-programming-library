---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://yukicoder.me/submissions/142657
  bundledCode: "#line 1 \"old/iterate.inc.cpp\"\n// http://yukicoder.me/submissions/142657\n\
    struct sequence {\n    vector<int> data;\n    int offset, cycle;\n};\nsequence\
    \ iterate(int a, function<int (int)> f) {\n    sequence xs;\n    map<int, int>\
    \ used;\n    while (not used.count(a)) {\n        used[a] = xs.data.size();\n\
    \        xs.data.push_back(a);\n        a = f(a);\n    }\n    xs.offset  = used[a];\n\
    \    xs.cycle = xs.data.size() - xs.offset;\n    return xs;\n}\nint at(sequence\
    \ const & xs, int i) {\n    return xs.data[i < xs.offset ? i : (i - xs.offset)\
    \ % xs.cycle + xs.offset];\n}\n"
  code: "// http://yukicoder.me/submissions/142657\nstruct sequence {\n    vector<int>\
    \ data;\n    int offset, cycle;\n};\nsequence iterate(int a, function<int (int)>\
    \ f) {\n    sequence xs;\n    map<int, int> used;\n    while (not used.count(a))\
    \ {\n        used[a] = xs.data.size();\n        xs.data.push_back(a);\n      \
    \  a = f(a);\n    }\n    xs.offset  = used[a];\n    xs.cycle = xs.data.size()\
    \ - xs.offset;\n    return xs;\n}\nint at(sequence const & xs, int i) {\n    return\
    \ xs.data[i < xs.offset ? i : (i - xs.offset) % xs.cycle + xs.offset];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/iterate.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/iterate.inc.cpp
layout: document
redirect_from:
- /library/old/iterate.inc.cpp
- /library/old/iterate.inc.cpp.html
title: old/iterate.inc.cpp
---
