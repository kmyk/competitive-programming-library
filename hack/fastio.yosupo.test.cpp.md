---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: hack/fastio.hpp
    title: hack/fastio.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"hack/fastio.yosupo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n#line 2 \"hack/fastio.hpp\"\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <string>\n#include <type_traits>\n\ntemplate <class Char, std::enable_if_t<std::is_same_v<Char,\
    \ char>, int> = 0>\ninline Char in() { return getchar_unlocked(); }\ntemplate\
    \ <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> =\
    \ 0>\ninline std::string in() {\n    char c; do { c = getchar_unlocked(); } while\
    \ (isspace(c));\n    std::string s;\n    do { s.push_back(c); } while (not isspace(c\
    \ = getchar_unlocked()));\n    return s;\n}\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>\
    \ and not std::is_same_v<Integer, char>, int> = 0>\ninline Integer in() {\n  \
    \  char c; do { c = getchar_unlocked(); } while (isspace(c));\n    if (std::is_signed<Integer>::value\
    \ and c == '-') return -in<Integer>();\n    Integer n = 0;\n    do { n = n * 10\
    \ + c - '0'; } while (not isspace(c = getchar_unlocked()));\n    return n;\n}\n\
    \ntemplate <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\n\
    inline void out(char c) { putchar_unlocked(c); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline void out(const std::string & s) { for (char\
    \ c : s) putchar_unlocked(c); }\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>,\
    \ int> = 0>\ninline void out(Integer n) {\n    char s[20];\n    int i = 0;\n \
    \   if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *=\
    \ -1; }\n    do { s[i ++] = n % 10; n /= 10; } while (n);\n    while (i) putchar_unlocked(s[--\
    \ i] + '0');\n}\n#line 3 \"hack/fastio.yosupo.test.cpp\"\n\nint main() {\n   \
    \ int t = in<int>();\n    while (t --) {\n        uint64_t a = in<uint64_t>();\n\
    \        uint64_t b = in<uint64_t>();\n        out<uint64_t>(a + b);\n       \
    \ out<char>('\\n');\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"../hack/fastio.hpp\"\n\nint main() {\n    int t = in<int>();\n    while (t\
    \ --) {\n        uint64_t a = in<uint64_t>();\n        uint64_t b = in<uint64_t>();\n\
    \        out<uint64_t>(a + b);\n        out<char>('\\n');\n    }\n    return 0;\n\
    }\n"
  dependsOn:
  - hack/fastio.hpp
  isVerificationFile: true
  path: hack/fastio.yosupo.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: hack/fastio.yosupo.test.cpp
layout: document
redirect_from:
- /verify/hack/fastio.yosupo.test.cpp
- /verify/hack/fastio.yosupo.test.cpp.html
title: hack/fastio.yosupo.test.cpp
---
