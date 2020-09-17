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
  bundledCode: "#line 1 \"old/distributed-code-jam.inc.cpp\"\ntemplate <class T> void\
    \ PutGeneric(int target, T value);\ntemplate <> void PutGeneric(int target, char\
    \ value) { PutChar(target, value); }\ntemplate <> void PutGeneric(int target,\
    \ int value) { PutInt(target, value); }\ntemplate <> void PutGeneric(int target,\
    \ long long value) { PutLL(target, value); }\n\ntemplate <class Container>\nvoid\
    \ PutVec(int target, Container & values) {\n    PutInt(target, values.size());\n\
    \    for (auto value : values) PutGeneric(target, value);\n}\n\ntemplate <class\
    \ T> T GetGeneric(int source);\ntemplate <> char GetGeneric(int source) { return\
    \ GetChar(source); }\ntemplate <> int GetGeneric(int source) { return GetInt(source);\
    \ }\ntemplate <> long long GetGeneric(int source) { return GetLL(source); }\n\n\
    template <class Container>\nContainer GetVec(int source) {\n    int size = GetInt(source);\n\
    \    Container values;\n    values.resize(size);\n    repeat (i, size) values[i]\
    \ = GetGeneric<typename Container::value_type>(source);\n    return values;\n\
    }\n"
  code: "template <class T> void PutGeneric(int target, T value);\ntemplate <> void\
    \ PutGeneric(int target, char value) { PutChar(target, value); }\ntemplate <>\
    \ void PutGeneric(int target, int value) { PutInt(target, value); }\ntemplate\
    \ <> void PutGeneric(int target, long long value) { PutLL(target, value); }\n\n\
    template <class Container>\nvoid PutVec(int target, Container & values) {\n  \
    \  PutInt(target, values.size());\n    for (auto value : values) PutGeneric(target,\
    \ value);\n}\n\ntemplate <class T> T GetGeneric(int source);\ntemplate <> char\
    \ GetGeneric(int source) { return GetChar(source); }\ntemplate <> int GetGeneric(int\
    \ source) { return GetInt(source); }\ntemplate <> long long GetGeneric(int source)\
    \ { return GetLL(source); }\n\ntemplate <class Container>\nContainer GetVec(int\
    \ source) {\n    int size = GetInt(source);\n    Container values;\n    values.resize(size);\n\
    \    repeat (i, size) values[i] = GetGeneric<typename Container::value_type>(source);\n\
    \    return values;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/distributed-code-jam.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/distributed-code-jam.inc.cpp
layout: document
redirect_from:
- /library/old/distributed-code-jam.inc.cpp
- /library/old/distributed-code-jam.inc.cpp.html
title: old/distributed-code-jam.inc.cpp
---
