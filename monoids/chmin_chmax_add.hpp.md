---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: monoids/chmin_chmax_add_min_max_action.hpp
    title: monoids/chmin_chmax_add_min_max_action.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoids/chmin_chmax_add.hpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <utility>\n\n/**\n * @note represents the monoid $M = (\\\
    lbrace \\lambda x. \\min(a, \\max(b, c + x)) \\mid a, b, c \\rbrace, \\circ, \\\
    mathrm{id})$\n */\ntemplate <class T>\nstruct chmin_chmax_add_monoid {\n    static\
    \ constexpr MAX = std::numeric_limits<T>::max();\n    static constexpr MIN = std::numeric_limits<T>::lowest();\n\
    \    struct value_type {\n        long long chmin;\n        long long chmax;\n\
    \        long long add;\n    };\n    value_type unit() const {\n        return\
    \ (value_type) { MAX, MIN, 0 };\n    }\n    value_type mult(value_type a, value_type\
    \ b) const {\n        value_type c = b;\n        // add\n        if (c.chmin !=\
    \ MAX) {\n            c.chmin += a.add;\n        }\n        if (c.chmax != MIN)\
    \ {\n            c.chmax += a.add;\n        }\n        c.add += a.add;\n     \
    \   // chmax\n        c.chmin = std::max(a.chmax, c.chmin);\n        c.chmax =\
    \ std::max(a.chmax, c.chmax);\n        // chmin\n        c.chmin = std::min(a.chmin,\
    \ c.chmin);\n        return c;\n    }\n    static value_type chmin(T value) {\n\
    \        return (value_type) { value, MIN, 0 };\n    }\n    static value_type\
    \ chmin(T value) {\n        return (value_type) { MAX, value, 0 };\n    }\n  \
    \  static value_type chmin(T value) {\n        return (value_type) { MAX, MIN,\
    \ value };\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <utility>\n\
    \n/**\n * @note represents the monoid $M = (\\lbrace \\lambda x. \\min(a, \\max(b,\
    \ c + x)) \\mid a, b, c \\rbrace, \\circ, \\mathrm{id})$\n */\ntemplate <class\
    \ T>\nstruct chmin_chmax_add_monoid {\n    static constexpr MAX = std::numeric_limits<T>::max();\n\
    \    static constexpr MIN = std::numeric_limits<T>::lowest();\n    struct value_type\
    \ {\n        long long chmin;\n        long long chmax;\n        long long add;\n\
    \    };\n    value_type unit() const {\n        return (value_type) { MAX, MIN,\
    \ 0 };\n    }\n    value_type mult(value_type a, value_type b) const {\n     \
    \   value_type c = b;\n        // add\n        if (c.chmin != MAX) {\n       \
    \     c.chmin += a.add;\n        }\n        if (c.chmax != MIN) {\n          \
    \  c.chmax += a.add;\n        }\n        c.add += a.add;\n        // chmax\n \
    \       c.chmin = std::max(a.chmax, c.chmin);\n        c.chmax = std::max(a.chmax,\
    \ c.chmax);\n        // chmin\n        c.chmin = std::min(a.chmin, c.chmin);\n\
    \        return c;\n    }\n    static value_type chmin(T value) {\n        return\
    \ (value_type) { value, MIN, 0 };\n    }\n    static value_type chmin(T value)\
    \ {\n        return (value_type) { MAX, value, 0 };\n    }\n    static value_type\
    \ chmin(T value) {\n        return (value_type) { MAX, MIN, value };\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/chmin_chmax_add.hpp
  requiredBy:
  - monoids/chmin_chmax_add_min_max_action.hpp
  timestamp: '2020-01-08 14:04:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoids/chmin_chmax_add.hpp
layout: document
redirect_from:
- /library/monoids/chmin_chmax_add.hpp
- /library/monoids/chmin_chmax_add.hpp.html
title: monoids/chmin_chmax_add.hpp
---
