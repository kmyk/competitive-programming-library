---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "a binary search on floating point numbers / \u4E8C\u5206\u63A2\
      \u7D22 (\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570)"
    links: []
  bundledCode: "#line 2 \"utils/binary_search_float.hpp\"\n#include <cassert>\n#line\
    \ 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++\
    \ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 4 \"utils/binary_search_float.hpp\"\n\n/**\n * @brief a binary\
    \ search on floating point numbers / \u4E8C\u5206\u63A2\u7D22 (\u6D6E\u52D5\u5C0F\
    \u6570\u70B9\u6570)\n */\ntemplate <int Iteration = 64, typename UnaryPredicate>\n\
    double binsearch_float(double l, double r, UnaryPredicate p) {\n    assert (l\
    \ <= r);\n    REP (i, Iteration) {\n        double m = (l + r) / 2;\n        (p(m)\
    \ ? r : l) = m;\n    }\n    return r;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include \"utils/macros.hpp\"\n\n/**\n\
    \ * @brief a binary search on floating point numbers / \u4E8C\u5206\u63A2\u7D22\
    \ (\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570)\n */\ntemplate <int Iteration = 64, typename\
    \ UnaryPredicate>\ndouble binsearch_float(double l, double r, UnaryPredicate p)\
    \ {\n    assert (l <= r);\n    REP (i, Iteration) {\n        double m = (l + r)\
    \ / 2;\n        (p(m) ? r : l) = m;\n    }\n    return r;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: utils/binary_search_float.hpp
  requiredBy: []
  timestamp: '2020-05-23 03:04:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/binary_search_float.hpp
layout: document
redirect_from:
- /library/utils/binary_search_float.hpp
- /library/utils/binary_search_float.hpp.html
title: "a binary search on floating point numbers / \u4E8C\u5206\u63A2\u7D22 (\u6D6E\
  \u52D5\u5C0F\u6570\u70B9\u6570)"
---
