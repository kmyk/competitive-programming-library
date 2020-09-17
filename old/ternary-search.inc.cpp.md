---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"old/ternary-search.inc.cpp\"\n/**\n * @arg f must be a downward-convex\
    \ function\n * @retrun argmin f\n * @note f is called (iteration + 1) times\n\
    \ */\ntemplate <class Function>\ndouble golden_section_search(double l, double\
    \ r, int iteration, Function f) {\n    static const double GOLDEN_RATIO = (1 +\
    \ sqrt(5)) / 2;\n    double m1 = l + (r - l) / (GOLDEN_RATIO + 1);\n    double\
    \ m2 = l + (r - l) / GOLDEN_RATIO;  // NOTE: this equals to GOLDEN_RATIO / (GOLDEN_RATIO\
    \ + 1.0)\n    double f1 = f(m1);\n    double f2 = f(m2);\n    while (iteration\
    \ --) {\n        if (f1 < f2){\n            r = m2;\n            m2 = m1;\n  \
    \          f2 = f1;\n            m1 = l + (r - l) / (GOLDEN_RATIO + 1);\n    \
    \        f1 = f(m1);\n        } else {\n            l = m1;\n            m1 =\
    \ m2;\n            f1 = f2;\n            m2 = l + (r - l) / GOLDEN_RATIO;\n  \
    \          f2 = f(m2);\n        }\n    }\n    return (l + r) / 2;\n}\n"
  code: "/**\n * @arg f must be a downward-convex function\n * @retrun argmin f\n\
    \ * @note f is called (iteration + 1) times\n */\ntemplate <class Function>\n\
    double golden_section_search(double l, double r, int iteration, Function f) {\n\
    \    static const double GOLDEN_RATIO = (1 + sqrt(5)) / 2;\n    double m1 = l\
    \ + (r - l) / (GOLDEN_RATIO + 1);\n    double m2 = l + (r - l) / GOLDEN_RATIO;\
    \  // NOTE: this equals to GOLDEN_RATIO / (GOLDEN_RATIO + 1.0)\n    double f1\
    \ = f(m1);\n    double f2 = f(m2);\n    while (iteration --) {\n        if (f1\
    \ < f2){\n            r = m2;\n            m2 = m1;\n            f2 = f1;\n  \
    \          m1 = l + (r - l) / (GOLDEN_RATIO + 1);\n            f1 = f(m1);\n \
    \       } else {\n            l = m1;\n            m1 = m2;\n            f1 =\
    \ f2;\n            m2 = l + (r - l) / GOLDEN_RATIO;\n            f2 = f(m2);\n\
    \        }\n    }\n    return (l + r) / 2;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/ternary-search.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/ternary-search.inc.cpp
layout: document
redirect_from:
- /library/old/ternary-search.inc.cpp
- /library/old/ternary-search.inc.cpp.html
title: old/ternary-search.inc.cpp
---
