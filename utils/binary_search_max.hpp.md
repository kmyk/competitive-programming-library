---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/binary_search_max.hpp\"\n#include <cassert>\n#include\
    \ <cstdint>\n\n/**\n * @return $\\max \\lbrace x \\in (l, r] \\mid p(x) \\rbrace$,\
    \ or l if it doesn't exist\n */\ntemplate <typename UnaryPredicate>\nint64_t binsearch_max(int64_t\
    \ l, int64_t r, UnaryPredicate p) {\n    assert (l <= r);\n    ++ r;\n    while\
    \ (r - l > 1) {\n        int64_t m = l + (r - l) / 2;\n        (p(m) ? l : r)\
    \ = m;\n    }\n    return l;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n\n/**\n * @return $\\\
    max \\lbrace x \\in (l, r] \\mid p(x) \\rbrace$, or l if it doesn't exist\n */\n\
    template <typename UnaryPredicate>\nint64_t binsearch_max(int64_t l, int64_t r,\
    \ UnaryPredicate p) {\n    assert (l <= r);\n    ++ r;\n    while (r - l > 1)\
    \ {\n        int64_t m = l + (r - l) / 2;\n        (p(m) ? l : r) = m;\n    }\n\
    \    return l;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/binary_search_max.hpp
  requiredBy: []
  timestamp: '2021-08-29 20:28:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/binary_search_max.hpp
layout: document
redirect_from:
- /library/utils/binary_search_max.hpp
- /library/utils/binary_search_max.hpp.html
title: utils/binary_search_max.hpp
---
