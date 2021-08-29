---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Karatsuba method ($O(n^{\log_2 3})$)
    links: []
  bundledCode: "#line 2 \"number/karatsuba.hpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 5 \"number/karatsuba.hpp\"\n\n/**\n * @brief Karatsuba method\
    \ ($O(n^{\\log_2 3})$)\n */\ntemplate <class CommutativeRing>\nstd::vector<CommutativeRing>\
    \ karatsuba_convolution(const std::vector<CommutativeRing> & x, const std::vector<CommutativeRing>\
    \ & y) {\n    int n = x.size();\n    int m = y.size();\n    if ((int64_t)n * m\
    \ <= 100) {\n        std::vector<CommutativeRing> z(n + m - 1);\n        REP (i,\
    \ n) REP (j, m) {\n            z[i + j] += x[i] * y[j];\n        }\n        return\
    \ z;\n    }\n    int half = (std::max(n, m) + 1) / 2;\n\n    std::vector<CommutativeRing>\
    \ x0(x.begin(), x.begin() + std::min(n, half));\n    std::vector<CommutativeRing>\
    \ y0(y.begin(), y.begin() + std::min(m, half));\n    std::vector<CommutativeRing>\
    \ z0 = karatsuba_convolution(x0, y0);\n\n    std::vector<CommutativeRing> x1(x.begin()\
    \ + std::min(n, half), x.end());\n    std::vector<CommutativeRing> y1(y.begin()\
    \ + std::min(m, half), y.end());\n    std::vector<CommutativeRing> z2 = karatsuba_convolution(x1,\
    \ y1);\n\n    assert (x1.size() <= x0.size());\n    std::vector<CommutativeRing>\
    \ dx = x0;\n    REP (i, x1.size()) dx[i] -= x1[i];\n    assert (y1.size() <= y0.size());\n\
    \    std::vector<CommutativeRing> dy = y0;\n    REP (i, y1.size()) dy[i] -= y1[i];\n\
    \    std::vector<CommutativeRing> dz = karatsuba_convolution(dx, dy);\n\n    std::vector<CommutativeRing>\
    \ z(n + m - 1);\n    REP (i, z0.size()) {\n        z[i] += z0[i];\n        if\
    \ (half + i < (int)z.size()) z[half + i] += z0[i];\n    }\n    REP (i, dz.size())\
    \ {\n        if (half + i < (int)z.size()) z[half + i] -= dz[i];\n    }\n    REP\
    \ (i, z2.size()) {\n        z[half + i] += z2[i];\n        if (2 * half + i <\
    \ (int)z.size()) z[2 * half + i] += z2[i];\n    }\n    return z;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utils/macros.hpp\"\
    \n\n/**\n * @brief Karatsuba method ($O(n^{\\log_2 3})$)\n */\ntemplate <class\
    \ CommutativeRing>\nstd::vector<CommutativeRing> karatsuba_convolution(const std::vector<CommutativeRing>\
    \ & x, const std::vector<CommutativeRing> & y) {\n    int n = x.size();\n    int\
    \ m = y.size();\n    if ((int64_t)n * m <= 100) {\n        std::vector<CommutativeRing>\
    \ z(n + m - 1);\n        REP (i, n) REP (j, m) {\n            z[i + j] += x[i]\
    \ * y[j];\n        }\n        return z;\n    }\n    int half = (std::max(n, m)\
    \ + 1) / 2;\n\n    std::vector<CommutativeRing> x0(x.begin(), x.begin() + std::min(n,\
    \ half));\n    std::vector<CommutativeRing> y0(y.begin(), y.begin() + std::min(m,\
    \ half));\n    std::vector<CommutativeRing> z0 = karatsuba_convolution(x0, y0);\n\
    \n    std::vector<CommutativeRing> x1(x.begin() + std::min(n, half), x.end());\n\
    \    std::vector<CommutativeRing> y1(y.begin() + std::min(m, half), y.end());\n\
    \    std::vector<CommutativeRing> z2 = karatsuba_convolution(x1, y1);\n\n    assert\
    \ (x1.size() <= x0.size());\n    std::vector<CommutativeRing> dx = x0;\n    REP\
    \ (i, x1.size()) dx[i] -= x1[i];\n    assert (y1.size() <= y0.size());\n    std::vector<CommutativeRing>\
    \ dy = y0;\n    REP (i, y1.size()) dy[i] -= y1[i];\n    std::vector<CommutativeRing>\
    \ dz = karatsuba_convolution(dx, dy);\n\n    std::vector<CommutativeRing> z(n\
    \ + m - 1);\n    REP (i, z0.size()) {\n        z[i] += z0[i];\n        if (half\
    \ + i < (int)z.size()) z[half + i] += z0[i];\n    }\n    REP (i, dz.size()) {\n\
    \        if (half + i < (int)z.size()) z[half + i] -= dz[i];\n    }\n    REP (i,\
    \ z2.size()) {\n        z[half + i] += z2[i];\n        if (2 * half + i < (int)z.size())\
    \ z[2 * half + i] += z2[i];\n    }\n    return z;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: number/karatsuba.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number/karatsuba.hpp
layout: document
redirect_from:
- /library/number/karatsuba.hpp
- /library/number/karatsuba.hpp.html
title: Karatsuba method ($O(n^{\log_2 3})$)
---
