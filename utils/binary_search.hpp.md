---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: utils/binary_search.aoj.test.cpp
    title: utils/binary_search.aoj.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "a binary search / \u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 2 \"utils/binary_search.hpp\"\n#include <cassert>\n#include\
    \ <cstdint>\n\n/**\n * @brief a binary search / \u4E8C\u5206\u63A2\u7D22\n * @param[in]\
    \ p  a monotone predicate defined on $[l, r)$\n * @return $\\min \\lbrace x \\\
    in [l, r) \\mid p(x) \\rbrace$, or r if it doesn't exist\n */\ntemplate <typename\
    \ UnaryPredicate>\nint64_t binsearch(int64_t l, int64_t r, UnaryPredicate p) {\n\
    \    assert (l <= r);\n    -- l;\n    while (r - l > 1) {\n        int64_t m =\
    \ l + (r - l) / 2;\n        (p(m) ? r : l) = m;\n    }\n    return r;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n\n/**\n * @brief a\
    \ binary search / \u4E8C\u5206\u63A2\u7D22\n * @param[in] p  a monotone predicate\
    \ defined on $[l, r)$\n * @return $\\min \\lbrace x \\in [l, r) \\mid p(x) \\\
    rbrace$, or r if it doesn't exist\n */\ntemplate <typename UnaryPredicate>\nint64_t\
    \ binsearch(int64_t l, int64_t r, UnaryPredicate p) {\n    assert (l <= r);\n\
    \    -- l;\n    while (r - l > 1) {\n        int64_t m = l + (r - l) / 2;\n  \
    \      (p(m) ? r : l) = m;\n    }\n    return r;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/binary_search.hpp
  requiredBy: []
  timestamp: '2021-08-29 20:28:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - utils/binary_search.aoj.test.cpp
documentation_of: utils/binary_search.hpp
layout: document
redirect_from:
- /library/utils/binary_search.hpp
- /library/utils/binary_search.hpp.html
title: "a binary search / \u4E8C\u5206\u63A2\u7D22"
---
