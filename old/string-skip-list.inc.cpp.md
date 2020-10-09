---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/string-skip-list.inc.cpp\"\ntemplate <typename Iterator>\n\
    vector<array<int, 26> > get_next_index(Iterator first, Iterator last) {\n    int\
    \ n = distance(first, last);\n    vector<array<int, 26> > x(n + 1);\n    fill(whole(x[n]),\
    \ n);\n    repeat_reverse (i, n) {\n        x[i] = x[i + 1];\n        x[i][*(first\
    \ + i) - 'a'] = i;\n    }\n    return x;  // x_{i, c} = \\min \\{ j \\ge i \\\
    mid s_j = c \\}\n}\nunittest {\n    string s = \"aabcab\";\n    auto x = get_next_index(s.begin(),\
    \ s.end());\n    assert (x[0][0] == 0);  // () [a]abcab\n    assert (x[0][1] ==\
    \ 2);  // () aa[b]cab\n    assert (x[0][2] == 3);  // () aab[c]ab\n    assert\
    \ (x[4][0] == 4);  // (aabc) [a]b\n    assert (x[4][1] == 5);  // (aabc) a[b]\n\
    \    assert (x[4][2] == 6);  // (aabc) ab[]\n}\n"
  code: "template <typename Iterator>\nvector<array<int, 26> > get_next_index(Iterator\
    \ first, Iterator last) {\n    int n = distance(first, last);\n    vector<array<int,\
    \ 26> > x(n + 1);\n    fill(whole(x[n]), n);\n    repeat_reverse (i, n) {\n  \
    \      x[i] = x[i + 1];\n        x[i][*(first + i) - 'a'] = i;\n    }\n    return\
    \ x;  // x_{i, c} = \\min \\{ j \\ge i \\mid s_j = c \\}\n}\nunittest {\n    string\
    \ s = \"aabcab\";\n    auto x = get_next_index(s.begin(), s.end());\n    assert\
    \ (x[0][0] == 0);  // () [a]abcab\n    assert (x[0][1] == 2);  // () aa[b]cab\n\
    \    assert (x[0][2] == 3);  // () aab[c]ab\n    assert (x[4][0] == 4);  // (aabc)\
    \ [a]b\n    assert (x[4][1] == 5);  // (aabc) a[b]\n    assert (x[4][2] == 6);\
    \  // (aabc) ab[]\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/string-skip-list.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/string-skip-list.inc.cpp
layout: document
redirect_from:
- /library/old/string-skip-list.inc.cpp
- /library/old/string-skip-list.inc.cpp.html
title: old/string-skip-list.inc.cpp
---
