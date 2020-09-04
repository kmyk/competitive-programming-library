---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "a binary search / \u4E8C\u5206\u63A2\u7D22"
  bundledCode: "#line 2 \"utils/binary_search.hpp\"\n#include <cassert>\n#include\
    \ <cstdint>\n\n/**\n * @brief a binary search / \u4E8C\u5206\u63A2\u7D22\n * @param[in]\
    \ p  a monotone predicate defined on $[l, r)$\n * @return $\\min \\lbrace x \\\
    in [l, r) \\mid p(x) \\rbrace$, or r if it doesn't exist\n */\ntemplate <typename\
    \ UnaryPredicate>\nint64_t binsearch(int64_t l, int64_t r, UnaryPredicate p) {\n\
    \    assert (l <= r);\n    -- l;\n    while (r - l > 1) {\n        int64_t m =\
    \ l + (r - l) / 2;\n        (p(m) ? r : l) = m;\n    }\n    return r;\n}\n\n/**\n\
    \ * @return $\\max \\lbrace x \\in (l, r] \\mid p(x) \\rbrace$, or l if it doesn't\
    \ exist\n */\ntemplate <typename UnaryPredicate>\nint64_t binsearch_max(int64_t\
    \ l, int64_t r, UnaryPredicate p) {\n    assert (l <= r);\n    ++ r;\n    while\
    \ (r - l > 1) {\n        int64_t m = l + (r - l) / 2;\n        (p(m) ? l : r)\
    \ = m;\n    }\n    return l;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n\n/**\n * @brief a\
    \ binary search / \u4E8C\u5206\u63A2\u7D22\n * @param[in] p  a monotone predicate\
    \ defined on $[l, r)$\n * @return $\\min \\lbrace x \\in [l, r) \\mid p(x) \\\
    rbrace$, or r if it doesn't exist\n */\ntemplate <typename UnaryPredicate>\nint64_t\
    \ binsearch(int64_t l, int64_t r, UnaryPredicate p) {\n    assert (l <= r);\n\
    \    -- l;\n    while (r - l > 1) {\n        int64_t m = l + (r - l) / 2;\n  \
    \      (p(m) ? r : l) = m;\n    }\n    return r;\n}\n\n/**\n * @return $\\max\
    \ \\lbrace x \\in (l, r] \\mid p(x) \\rbrace$, or l if it doesn't exist\n */\n\
    template <typename UnaryPredicate>\nint64_t binsearch_max(int64_t l, int64_t r,\
    \ UnaryPredicate p) {\n    assert (l <= r);\n    ++ r;\n    while (r - l > 1)\
    \ {\n        int64_t m = l + (r - l) / 2;\n        (p(m) ? l : r) = m;\n    }\n\
    \    return l;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: utils/binary_search.aoj.test.cpp
    title: utils/binary_search.aoj.test.cpp
  isVerificationFile: false
  path: utils/binary_search.hpp
  requiredBy: []
  timestamp: '2019-12-15 04:15:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - utils/binary_search.aoj.test.cpp
documentation_of: utils/binary_search.hpp
layout: document
redirect_from:
- /library/utils/binary_search.hpp
- /library/utils/binary_search.hpp.html
title: "a binary search / \u4E8C\u5206\u63A2\u7D22"
---
