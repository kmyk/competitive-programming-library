---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: (upward) fast zeta transformation
    links:
    - http://pekempey.hatenablog.com/entry/2016/10/30/205852
  bundledCode: "#line 1 \"old/fast-mobius-transformation.inc.cpp\"\n/**\n * @brief\
    \ (upward) fast zeta transformation\n * @note for f : 2^n \\to R; \\zeta f(X)\
    \ = \\sum\\_{X \\subseteq Y} f(Y)\n * @note not verified\n */\ntemplate <typename\
    \ T>\nvector<T> upward_fast_zeta_transform(vector<T> f) {\n    int pow_n = f.size();\n\
    \    for (int i = 1; i < pow_n; i <<= 1) {\n        REP (s, pow_n) {\n       \
    \     if (not (s & i)) {\n                f[s] += f[s ^ i];\n            }\n \
    \       }\n    }\n    return f;\n}\n\n/**\n * @brief (downward) fast zeta transformation\n\
    \ * @note for f : 2^n \\to R; \\zeta f(Y) = \\sum\\_{X \\subseteq Y} f(X)\n *\
    \ @note O(n 2^n)\n * @param T is a commutative semigroup\n */\ntemplate <typename\
    \ T>\nvector<T> downward_fast_zeta_transform(vector<T> f) {\n    int pow_n = f.size();\n\
    \    for (int i = 1; i < pow_n; i <<= 1) {\n        REP (s, pow_n) {\n       \
    \     if (s & i) {\n                f[s] += f[s ^ i];\n            }\n       \
    \ }\n    }\n    return f;\n}\n\n/**\n * @brief (upward) fast mobius transformation\n\
    \ * @note for f : 2^n \\to R; \\mu f(X) = \\sum\\_{X \\subseteq Y} (-1)^{\\|Y\
    \ \\setminues X\\|} f(Y)\n * @note not verified\n */\ntemplate <typename T>\n\
    vector<T> upward_fast_mobius_transform(vector<T> f) {\n    int pow_n = f.size();\n\
    \    for (int i = 1; i < pow_n; i <<= 1) {\n        REP (s, pow_n) {\n       \
    \     if (not (s & i)) {\n                f[s] -= f[s ^ i];\n            }\n \
    \       }\n    }\n    return f;\n}\n\n/**\n * @brief (downward) fast mobius transformation\n\
    \ * @note for f : 2^n \\to R; \\mu f(Y) = \\sum\\_{X \\subseteq Y} (-1)^{\\|Y\
    \ \\setminues X\\|} f(X)\n * @note O(n 2^n)\n * @note related to inclusion-exclusion\
    \ principle\n * @note inverse of (downward) fast zeta transformation\n * @see\
    \ http://pekempey.hatenablog.com/entry/2016/10/30/205852\n * @param T is a commutative\
    \ group\n */\ntemplate <typename T>\nvector<T> downward_fast_mobius_transform(vector<T>\
    \ f) {\n    int pow_n = f.size();\n    for (int i = 1; i < pow_n; i <<= 1) {\n\
    \        REP (s, pow_n) {\n            if (s & i) {\n                f[s] -= f[s\
    \ ^ i];\n            }\n        }\n    }\n    return f;\n}\n"
  code: "/**\n * @brief (upward) fast zeta transformation\n * @note for f : 2^n \\\
    to R; \\zeta f(X) = \\sum\\_{X \\subseteq Y} f(Y)\n * @note not verified\n */\n\
    template <typename T>\nvector<T> upward_fast_zeta_transform(vector<T> f) {\n \
    \   int pow_n = f.size();\n    for (int i = 1; i < pow_n; i <<= 1) {\n       \
    \ REP (s, pow_n) {\n            if (not (s & i)) {\n                f[s] += f[s\
    \ ^ i];\n            }\n        }\n    }\n    return f;\n}\n\n/**\n * @brief (downward)\
    \ fast zeta transformation\n * @note for f : 2^n \\to R; \\zeta f(Y) = \\sum\\\
    _{X \\subseteq Y} f(X)\n * @note O(n 2^n)\n * @param T is a commutative semigroup\n\
    \ */\ntemplate <typename T>\nvector<T> downward_fast_zeta_transform(vector<T>\
    \ f) {\n    int pow_n = f.size();\n    for (int i = 1; i < pow_n; i <<= 1) {\n\
    \        REP (s, pow_n) {\n            if (s & i) {\n                f[s] += f[s\
    \ ^ i];\n            }\n        }\n    }\n    return f;\n}\n\n/**\n * @brief (upward)\
    \ fast mobius transformation\n * @note for f : 2^n \\to R; \\mu f(X) = \\sum\\\
    _{X \\subseteq Y} (-1)^{\\|Y \\setminues X\\|} f(Y)\n * @note not verified\n */\n\
    template <typename T>\nvector<T> upward_fast_mobius_transform(vector<T> f) {\n\
    \    int pow_n = f.size();\n    for (int i = 1; i < pow_n; i <<= 1) {\n      \
    \  REP (s, pow_n) {\n            if (not (s & i)) {\n                f[s] -= f[s\
    \ ^ i];\n            }\n        }\n    }\n    return f;\n}\n\n/**\n * @brief (downward)\
    \ fast mobius transformation\n * @note for f : 2^n \\to R; \\mu f(Y) = \\sum\\\
    _{X \\subseteq Y} (-1)^{\\|Y \\setminues X\\|} f(X)\n * @note O(n 2^n)\n * @note\
    \ related to inclusion-exclusion principle\n * @note inverse of (downward) fast\
    \ zeta transformation\n * @see http://pekempey.hatenablog.com/entry/2016/10/30/205852\n\
    \ * @param T is a commutative group\n */\ntemplate <typename T>\nvector<T> downward_fast_mobius_transform(vector<T>\
    \ f) {\n    int pow_n = f.size();\n    for (int i = 1; i < pow_n; i <<= 1) {\n\
    \        REP (s, pow_n) {\n            if (s & i) {\n                f[s] -= f[s\
    \ ^ i];\n            }\n        }\n    }\n    return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/fast-mobius-transformation.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/fast-mobius-transformation.inc.cpp
layout: document
redirect_from:
- /library/old/fast-mobius-transformation.inc.cpp
- /library/old/fast-mobius-transformation.inc.cpp.html
title: (upward) fast zeta transformation
---
