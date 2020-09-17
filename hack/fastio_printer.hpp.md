---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: hack/fastio_scanner_and_printer.yosupo.test.cpp
    title: hack/fastio_scanner_and_printer.yosupo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"hack/fastio_printer.hpp\"\n#include <algorithm>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <string>\n#include <type_traits>\n#include\
    \ <unistd.h>\n\nclass printer {\n    static constexpr int N = 131072;\n    static\
    \ constexpr int K = 64;\n    char buf[N];\n    int i = 0;\n    inline void flush()\
    \ {\n        write(STDOUT_FILENO, buf, i);\n        i = 0;\n    }\npublic:\n \
    \   printer() = default;\n    printer(const printer &) = delete;\n    printer\
    \ & operator = (const printer &) = delete;\n    ~printer() {\n        flush();\n\
    \    }\n    template <class Char, std::enable_if_t<std::is_same<Char, char>::value,\
    \ int> = 0>\n    inline void put(char c) {\n        if (i == N) flush();\n   \
    \     buf[i ++] = c;\n    }\n    template <class String, std::enable_if_t<std::is_same<String,\
    \ std::string>::value, int> = 0>\n    void put(const std::string & s) {\n    \
    \    for (int l = 0; l < (int)s.length(); ) {\n            if (i == N) flush();\n\
    \            int r = std::min<int>(s.length(), l + (N - i));\n            memcpy(buf\
    \ + i, s.data() + l, r - l);\n            i += r - l;\n            l = r;\n  \
    \      }\n    }\n    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value,\
    \ int> = 0>\n    void put(Integer x) {\n        if (N - i < K) flush();\n    \
    \    if (std::is_signed<Integer>::value and x < 0) {\n            x *= -1;\n \
    \           buf[i ++] = '-';\n        }\n        if (x == 0) {\n            buf[i\
    \ ++] = '0';\n            return;\n        }\n        char s[K];\n        int\
    \ j = 0;\n        while (x) {\n            s[j ++] = x % 10 + '0';\n         \
    \   x /= 10;\n        }\n        while (j) {\n            buf[i ++] = s[-- j];\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cstdlib>\n#include <cstring>\n\
    #include <string>\n#include <type_traits>\n#include <unistd.h>\n\nclass printer\
    \ {\n    static constexpr int N = 131072;\n    static constexpr int K = 64;\n\
    \    char buf[N];\n    int i = 0;\n    inline void flush() {\n        write(STDOUT_FILENO,\
    \ buf, i);\n        i = 0;\n    }\npublic:\n    printer() = default;\n    printer(const\
    \ printer &) = delete;\n    printer & operator = (const printer &) = delete;\n\
    \    ~printer() {\n        flush();\n    }\n    template <class Char, std::enable_if_t<std::is_same<Char,\
    \ char>::value, int> = 0>\n    inline void put(char c) {\n        if (i == N)\
    \ flush();\n        buf[i ++] = c;\n    }\n    template <class String, std::enable_if_t<std::is_same<String,\
    \ std::string>::value, int> = 0>\n    void put(const std::string & s) {\n    \
    \    for (int l = 0; l < (int)s.length(); ) {\n            if (i == N) flush();\n\
    \            int r = std::min<int>(s.length(), l + (N - i));\n            memcpy(buf\
    \ + i, s.data() + l, r - l);\n            i += r - l;\n            l = r;\n  \
    \      }\n    }\n    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value,\
    \ int> = 0>\n    void put(Integer x) {\n        if (N - i < K) flush();\n    \
    \    if (std::is_signed<Integer>::value and x < 0) {\n            x *= -1;\n \
    \           buf[i ++] = '-';\n        }\n        if (x == 0) {\n            buf[i\
    \ ++] = '0';\n            return;\n        }\n        char s[K];\n        int\
    \ j = 0;\n        while (x) {\n            s[j ++] = x % 10 + '0';\n         \
    \   x /= 10;\n        }\n        while (j) {\n            buf[i ++] = s[-- j];\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: hack/fastio_printer.hpp
  requiredBy: []
  timestamp: '2020-03-04 16:58:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - hack/fastio_scanner_and_printer.yosupo.test.cpp
documentation_of: hack/fastio_printer.hpp
layout: document
redirect_from:
- /library/hack/fastio_printer.hpp
- /library/hack/fastio_printer.hpp.html
title: hack/fastio_printer.hpp
---
