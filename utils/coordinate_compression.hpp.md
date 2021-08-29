---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: data_structure/wavelet_matrix.rectangle_sum.test.cpp
    title: data_structure/wavelet_matrix.rectangle_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/coordinate_compression.hpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i\
    \ = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) <\
    \ (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 5 \"utils/coordinate_compression.hpp\"\
    \n\ntemplate <class T>\nstruct coordinate_compression {\n    std::vector<T> data;\n\
    \    coordinate_compression() = default;\n    template <class Iterator>\n    coordinate_compression(Iterator\
    \ first, Iterator last) {\n        unsafe_insert(first, last);\n        unsafe_rebuild();\n\
    \    }\n    template <class Iterator>\n    void unsafe_insert(Iterator first,\
    \ Iterator last) {\n        data.insert(data.end(), first, last);\n    }\n   \
    \ void unsafe_rebuild() {\n        std::sort(ALL(data));\n        data.erase(std::unique(ALL(data)),\
    \ data.end());\n    }\n    int operator [] (const T & value) {\n        return\
    \ std::lower_bound(ALL(data), value) - data.begin();\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"../utils/macros.hpp\"\
    \n\ntemplate <class T>\nstruct coordinate_compression {\n    std::vector<T> data;\n\
    \    coordinate_compression() = default;\n    template <class Iterator>\n    coordinate_compression(Iterator\
    \ first, Iterator last) {\n        unsafe_insert(first, last);\n        unsafe_rebuild();\n\
    \    }\n    template <class Iterator>\n    void unsafe_insert(Iterator first,\
    \ Iterator last) {\n        data.insert(data.end(), first, last);\n    }\n   \
    \ void unsafe_rebuild() {\n        std::sort(ALL(data));\n        data.erase(std::unique(ALL(data)),\
    \ data.end());\n    }\n    int operator [] (const T & value) {\n        return\
    \ std::lower_bound(ALL(data), value) - data.begin();\n    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: utils/coordinate_compression.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - data_structure/wavelet_matrix.rectangle_sum.test.cpp
documentation_of: utils/coordinate_compression.hpp
layout: document
redirect_from:
- /library/utils/coordinate_compression.hpp
- /library/utils/coordinate_compression.hpp.html
title: utils/coordinate_compression.hpp
---
