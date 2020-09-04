---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"old/factoradic.inc.cpp\"\ntemplate <class RandomAccessIterator>\n\
    uint64_t encode_factoradic(RandomAccessIterator first, RandomAccessIterator last)\
    \ { // O(N^2)\n    static vector<int> fact(1, 1);\n    while (fact.size() < n)\
    \ {\n        fact.push_back(fact.size() * fact.back());\n    }\n    int n = last\
    \ - first;\n    uint64_t y = 0;\n    REP (i, n) {\n        int xi = *(first +\
    \ i);\n        int rank = count_if(first, first + i, [&](int xj) { return xi <\
    \ xj; });\n        y += rank * fact[i];\n    }\n    return y;\n}\nvector<int>\
    \ decode_factoradic(uint64_t y, int n) { // O(N^2)\n    static vector<int> fact(1,\
    \ 1);\n    while (fact.size() < n) {\n        fact.push_back(fact.size() * fact.back());\n\
    \    }\n    vector<int> xs(n);\n    vector<int> zs(n); iota(zs.begin(), zs.end(),\
    \ 0);\n    REP_R (i, n) {\n        auto it = zs.begin() + (i - y / fact[i]);\n\
    \        xs[i] = *it;\n        zs.erase(it);\n        y %= fact[i];\n    }\n \
    \   return xs;\n}\n"
  code: "template <class RandomAccessIterator>\nuint64_t encode_factoradic(RandomAccessIterator\
    \ first, RandomAccessIterator last) { // O(N^2)\n    static vector<int> fact(1,\
    \ 1);\n    while (fact.size() < n) {\n        fact.push_back(fact.size() * fact.back());\n\
    \    }\n    int n = last - first;\n    uint64_t y = 0;\n    REP (i, n) {\n   \
    \     int xi = *(first + i);\n        int rank = count_if(first, first + i, [&](int\
    \ xj) { return xi < xj; });\n        y += rank * fact[i];\n    }\n    return y;\n\
    }\nvector<int> decode_factoradic(uint64_t y, int n) { // O(N^2)\n    static vector<int>\
    \ fact(1, 1);\n    while (fact.size() < n) {\n        fact.push_back(fact.size()\
    \ * fact.back());\n    }\n    vector<int> xs(n);\n    vector<int> zs(n); iota(zs.begin(),\
    \ zs.end(), 0);\n    REP_R (i, n) {\n        auto it = zs.begin() + (i - y / fact[i]);\n\
    \        xs[i] = *it;\n        zs.erase(it);\n        y %= fact[i];\n    }\n \
    \   return xs;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/factoradic.inc.cpp
  requiredBy: []
  timestamp: '2020-05-23 00:47:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/factoradic.inc.cpp
layout: document
redirect_from:
- /library/old/factoradic.inc.cpp
- /library/old/factoradic.inc.cpp.html
title: old/factoradic.inc.cpp
---
