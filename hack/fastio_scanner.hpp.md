---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: hack/fastio_scanner_and_printer.yosupo.test.cpp
    title: hack/fastio_scanner_and_printer.yosupo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"hack/fastio_scanner.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cstdlib>\n#include <cstring>\n#include <string>\n#include\
    \ <type_traits>\n#include <unistd.h>\n\nclass scanner {\n    static constexpr\
    \ int N = 131072;\n    static constexpr int K = 64;\n    char buf[K + N];\n  \
    \  int l = 0;\n    int r = 0;\n    void flush() {\n        if (K < r - l) return;\n\
    \        memmove(buf + K - (r - l), buf + l, r - l);\n        l = K - (r - l);\n\
    \        r = K + read(STDIN_FILENO, buf + K, N);\n        assert (l < r);\n  \
    \  }\n    void prepare() {\n        flush();\n        while (isspace(buf[l]))\
    \ {\n            ++ l;\n            flush();\n        }\n    }\npublic:\n    scanner()\
    \ = default;\n    scanner(const scanner &) = delete;\n    scanner & operator =\
    \ (const scanner &) = delete;\n    template <class Char, std::enable_if_t<std::is_same<Char,\
    \ char>::value, int> = 0>\n    inline char get() {\n        prepare();\n     \
    \   return buf[l ++];\n    }\n    template <class String, std::enable_if_t<std::is_same<String,\
    \ std::string>::value, int> = 0>\n    std::string get() {\n        prepare();\n\
    \        std::string s;\n        do {\n            s.push_back(buf[l ++]);\n \
    \           if (r == l) flush();\n        } while (not isspace(buf[l]));\n   \
    \     return s;\n    }\n    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value,\
    \ int> = 0>\n    Integer get() {\n        prepare();\n        bool is_negative\
    \ = false;\n        if (std::is_signed<Integer>::value and buf[l] == '-') {\n\
    \            is_negative = true;\n            ++ l;\n        }\n        Integer\
    \ x = 0;\n        while (l < r and isdigit(buf[l])) {\n            x = 10 * x\
    \ + buf[l] - '0';\n            ++ l;\n        }\n        if (std::is_signed<Integer>::value\
    \ and is_negative) {\n            x *= -1;\n        }\n        return x;\n   \
    \ }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cstdlib>\n\
    #include <cstring>\n#include <string>\n#include <type_traits>\n#include <unistd.h>\n\
    \nclass scanner {\n    static constexpr int N = 131072;\n    static constexpr\
    \ int K = 64;\n    char buf[K + N];\n    int l = 0;\n    int r = 0;\n    void\
    \ flush() {\n        if (K < r - l) return;\n        memmove(buf + K - (r - l),\
    \ buf + l, r - l);\n        l = K - (r - l);\n        r = K + read(STDIN_FILENO,\
    \ buf + K, N);\n        assert (l < r);\n    }\n    void prepare() {\n       \
    \ flush();\n        while (isspace(buf[l])) {\n            ++ l;\n           \
    \ flush();\n        }\n    }\npublic:\n    scanner() = default;\n    scanner(const\
    \ scanner &) = delete;\n    scanner & operator = (const scanner &) = delete;\n\
    \    template <class Char, std::enable_if_t<std::is_same<Char, char>::value, int>\
    \ = 0>\n    inline char get() {\n        prepare();\n        return buf[l ++];\n\
    \    }\n    template <class String, std::enable_if_t<std::is_same<String, std::string>::value,\
    \ int> = 0>\n    std::string get() {\n        prepare();\n        std::string\
    \ s;\n        do {\n            s.push_back(buf[l ++]);\n            if (r ==\
    \ l) flush();\n        } while (not isspace(buf[l]));\n        return s;\n   \
    \ }\n    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value,\
    \ int> = 0>\n    Integer get() {\n        prepare();\n        bool is_negative\
    \ = false;\n        if (std::is_signed<Integer>::value and buf[l] == '-') {\n\
    \            is_negative = true;\n            ++ l;\n        }\n        Integer\
    \ x = 0;\n        while (l < r and isdigit(buf[l])) {\n            x = 10 * x\
    \ + buf[l] - '0';\n            ++ l;\n        }\n        if (std::is_signed<Integer>::value\
    \ and is_negative) {\n            x *= -1;\n        }\n        return x;\n   \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: hack/fastio_scanner.hpp
  requiredBy: []
  timestamp: '2020-03-04 16:58:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - hack/fastio_scanner_and_printer.yosupo.test.cpp
documentation_of: hack/fastio_scanner.hpp
layout: document
redirect_from:
- /library/hack/fastio_scanner.hpp
- /library/hack/fastio_scanner.hpp.html
title: hack/fastio_scanner.hpp
---
