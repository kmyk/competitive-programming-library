---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Minimum Excluded Value ($O(n)$ for a given sorted container)
    links:
    - https://en.wikipedia.org/wiki/Mex_(mathematics)
  bundledCode: "#line 2 \"utils/mex.hpp\"\n#include <cassert>\n\n/**\n * @brief Minimum\
    \ Excluded Value ($O(n)$ for a given sorted container)\n * @sa https://en.wikipedia.org/wiki/Mex_(mathematics)\n\
    \ * @note xs must be weakly increasing\n */\ntemplate <typename InputIterator>\n\
    int mex(InputIterator first, InputIterator last) {\n    int last_x = 0;  // only\
    \ for debug\n    int y = 0;\n    for (; first != last; ++ first) {\n        int\
    \ x = *first;\n        assert (last_x <= x);\n        last_x = x;\n        if\
    \ (y < x) break;\n        if (y == x) ++ y;\n    }\n    return y;\n}\n"
  code: "#pragma once\n#include <cassert>\n\n/**\n * @brief Minimum Excluded Value\
    \ ($O(n)$ for a given sorted container)\n * @sa https://en.wikipedia.org/wiki/Mex_(mathematics)\n\
    \ * @note xs must be weakly increasing\n */\ntemplate <typename InputIterator>\n\
    int mex(InputIterator first, InputIterator last) {\n    int last_x = 0;  // only\
    \ for debug\n    int y = 0;\n    for (; first != last; ++ first) {\n        int\
    \ x = *first;\n        assert (last_x <= x);\n        last_x = x;\n        if\
    \ (y < x) break;\n        if (y == x) ++ y;\n    }\n    return y;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/mex.hpp
  requiredBy: []
  timestamp: '2020-07-27 01:00:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/mex.hpp
layout: document
redirect_from:
- /library/utils/mex.hpp
- /library/utils/mex.hpp.html
title: Minimum Excluded Value ($O(n)$ for a given sorted container)
---
