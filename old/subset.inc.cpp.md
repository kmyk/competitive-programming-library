---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/
  bundledCode: "#line 1 \"old/subset.inc.cpp\"\n/**\n * @sa https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/\n\
    \ */\n\n// for a set z, list y \\subseteq z, ascending order\nfor (int y = 0;\
    \ ; y = (y - z) & z) {\n    ...\n    if (y == z) break;\n}\n\n// for a set z,\
    \ list y \\subseteq z, descending order\nfor (int y = z; ; y = (y - 1) & z) {\n\
    \    ...\n    if (y == 0) break;\n}\n\n// for a set x and an ordinal n, list y\
    \ s.t. x \\subseteq y \\subseteq n\nor (int y = x; y < (1 << n); y = (y + 1) |\
    \ x) {\n    ...\n}\n\n// for an ordinal n and integer k, list x \\subseteq n s.t.\
    \ \\|x\\| = k\nfor (int x = (1 << k) - 1; x < (1 << n); ) {\n    ...\n    int\
    \ t = x | (x - 1);\n    x = (t + 1) | (((~ t & - ~ t) - 1) >> (__builtin_ctz(x)\
    \ + 1));\n}\n"
  code: "/**\n * @sa https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/\n\
    \ */\n\n// for a set z, list y \\subseteq z, ascending order\nfor (int y = 0;\
    \ ; y = (y - z) & z) {\n    ...\n    if (y == z) break;\n}\n\n// for a set z,\
    \ list y \\subseteq z, descending order\nfor (int y = z; ; y = (y - 1) & z) {\n\
    \    ...\n    if (y == 0) break;\n}\n\n// for a set x and an ordinal n, list y\
    \ s.t. x \\subseteq y \\subseteq n\nor (int y = x; y < (1 << n); y = (y + 1) |\
    \ x) {\n    ...\n}\n\n// for an ordinal n and integer k, list x \\subseteq n s.t.\
    \ \\|x\\| = k\nfor (int x = (1 << k) - 1; x < (1 << n); ) {\n    ...\n    int\
    \ t = x | (x - 1);\n    x = (t + 1) | (((~ t & - ~ t) - 1) >> (__builtin_ctz(x)\
    \ + 1));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/subset.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/subset.inc.cpp
layout: document
redirect_from:
- /library/old/subset.inc.cpp
- /library/old/subset.inc.cpp.html
title: old/subset.inc.cpp
---
