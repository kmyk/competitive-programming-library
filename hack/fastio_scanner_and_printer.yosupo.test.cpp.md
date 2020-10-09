---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: hack/fastio_printer.hpp
    title: hack/fastio_printer.hpp
  - icon: ':heavy_check_mark:'
    path: hack/fastio_scanner.hpp
    title: hack/fastio_scanner.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"hack/fastio_scanner_and_printer.yosupo.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#line 2 \"hack/fastio_scanner.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <cstdlib>\n#include <cstring>\n\
    #include <string>\n#include <type_traits>\n#include <unistd.h>\n\nclass scanner\
    \ {\n    static constexpr int N = 131072;\n    static constexpr int K = 64;\n\
    \    char buf[K + N];\n    int l = 0;\n    int r = 0;\n    void flush() {\n  \
    \      if (K < r - l) return;\n        memmove(buf + K - (r - l), buf + l, r -\
    \ l);\n        l = K - (r - l);\n        r = K + read(STDIN_FILENO, buf + K, N);\n\
    \        assert (l < r);\n    }\n    void prepare() {\n        flush();\n    \
    \    while (isspace(buf[l])) {\n            ++ l;\n            flush();\n    \
    \    }\n    }\npublic:\n    scanner() = default;\n    scanner(const scanner &)\
    \ = delete;\n    scanner & operator = (const scanner &) = delete;\n    template\
    \ <class Char, std::enable_if_t<std::is_same<Char, char>::value, int> = 0>\n \
    \   inline char get() {\n        prepare();\n        return buf[l ++];\n    }\n\
    \    template <class String, std::enable_if_t<std::is_same<String, std::string>::value,\
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
    \ }\n};\n#line 8 \"hack/fastio_printer.hpp\"\n\nclass printer {\n    static constexpr\
    \ int N = 131072;\n    static constexpr int K = 64;\n    char buf[N];\n    int\
    \ i = 0;\n    inline void flush() {\n        write(STDOUT_FILENO, buf, i);\n \
    \       i = 0;\n    }\npublic:\n    printer() = default;\n    printer(const printer\
    \ &) = delete;\n    printer & operator = (const printer &) = delete;\n    ~printer()\
    \ {\n        flush();\n    }\n    template <class Char, std::enable_if_t<std::is_same<Char,\
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
    \        }\n    }\n};\n#line 4 \"hack/fastio_scanner_and_printer.yosupo.test.cpp\"\
    \n\nscanner sc;\nprinter pr;\n\nint main() {\n    int t = sc.get<int>();\n   \
    \ while (t --) {\n        uint64_t a = sc.get<uint64_t>();\n        uint64_t b\
    \ = sc.get<uint64_t>();\n        pr.put<uint64_t>(a + b);\n        pr.put<char>('\\\
    n');\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"hack/fastio_scanner.hpp\"\n#include \"hack/fastio_printer.hpp\"\n\nscanner\
    \ sc;\nprinter pr;\n\nint main() {\n    int t = sc.get<int>();\n    while (t --)\
    \ {\n        uint64_t a = sc.get<uint64_t>();\n        uint64_t b = sc.get<uint64_t>();\n\
    \        pr.put<uint64_t>(a + b);\n        pr.put<char>('\\n');\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - hack/fastio_scanner.hpp
  - hack/fastio_printer.hpp
  isVerificationFile: true
  path: hack/fastio_scanner_and_printer.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-03-04 16:58:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: hack/fastio_scanner_and_printer.yosupo.test.cpp
layout: document
redirect_from:
- /verify/hack/fastio_scanner_and_printer.yosupo.test.cpp
- /verify/hack/fastio_scanner_and_printer.yosupo.test.cpp.html
title: hack/fastio_scanner_and_printer.yosupo.test.cpp
---
