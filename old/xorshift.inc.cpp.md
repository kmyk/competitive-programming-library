---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/xorshift.inc.cpp\"\nclass xor_shift_128 {\npublic:\n\
    \    typedef uint32_t result_type;\n    xor_shift_128(uint32_t seed = 42) {\n\
    \        set_seed(seed);\n    }\n    void set_seed(uint32_t seed) {\n        a\
    \ = seed = 1812433253u * (seed ^ (seed >> 30));\n        b = seed = 1812433253u\
    \ * (seed ^ (seed >> 30)) + 1;\n        c = seed = 1812433253u * (seed ^ (seed\
    \ >> 30)) + 2;\n        d = seed = 1812433253u * (seed ^ (seed >> 30)) + 3;\n\
    \    }\n    uint32_t operator() () {\n        uint32_t t = (a ^ (a << 11));\n\
    \        a = b; b = c; c = d;\n        return d = (d ^ (d >> 19)) ^ (t ^ (t >>\
    \ 8));\n    }\n    static constexpr uint32_t max() { return numeric_limits<result_type>::max();\
    \ }\n    static constexpr uint32_t min() { return numeric_limits<result_type>::min();\
    \ }\nprivate:\n    uint32_t a, b, c, d;\n};\n"
  code: "class xor_shift_128 {\npublic:\n    typedef uint32_t result_type;\n    xor_shift_128(uint32_t\
    \ seed = 42) {\n        set_seed(seed);\n    }\n    void set_seed(uint32_t seed)\
    \ {\n        a = seed = 1812433253u * (seed ^ (seed >> 30));\n        b = seed\
    \ = 1812433253u * (seed ^ (seed >> 30)) + 1;\n        c = seed = 1812433253u *\
    \ (seed ^ (seed >> 30)) + 2;\n        d = seed = 1812433253u * (seed ^ (seed >>\
    \ 30)) + 3;\n    }\n    uint32_t operator() () {\n        uint32_t t = (a ^ (a\
    \ << 11));\n        a = b; b = c; c = d;\n        return d = (d ^ (d >> 19)) ^\
    \ (t ^ (t >> 8));\n    }\n    static constexpr uint32_t max() { return numeric_limits<result_type>::max();\
    \ }\n    static constexpr uint32_t min() { return numeric_limits<result_type>::min();\
    \ }\nprivate:\n    uint32_t a, b, c, d;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/xorshift.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/xorshift.inc.cpp
layout: document
redirect_from:
- /library/old/xorshift.inc.cpp
- /library/old/xorshift.inc.cpp.html
title: old/xorshift.inc.cpp
---
