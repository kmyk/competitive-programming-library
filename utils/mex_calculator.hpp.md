---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/mex_calculator.hpp\"\n#include <cassert>\n\nclass\
    \ mex_calculator {\n    uint64_t used;\npublic:\n    mex_calculator()\n      \
    \      : used(0) {\n    }\n    void put(int x) {\n        assert (0 <= x and x\
    \ < 64 - 1);\n        used |= 1ull << x;\n    }\n    int get() const {\n     \
    \   return __builtin_ctzll(~ used);\n    }\n    void clear() {\n        used =\
    \ 0;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n\nclass mex_calculator {\n    uint64_t\
    \ used;\npublic:\n    mex_calculator()\n            : used(0) {\n    }\n    void\
    \ put(int x) {\n        assert (0 <= x and x < 64 - 1);\n        used |= 1ull\
    \ << x;\n    }\n    int get() const {\n        return __builtin_ctzll(~ used);\n\
    \    }\n    void clear() {\n        used = 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/mex_calculator.hpp
  requiredBy: []
  timestamp: '2020-07-27 01:00:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/mex_calculator.hpp
layout: document
redirect_from:
- /library/utils/mex_calculator.hpp
- /library/utils/mex_calculator.hpp.html
title: utils/mex_calculator.hpp
---
