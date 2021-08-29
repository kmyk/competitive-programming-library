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
    document_title: Lagrange interpolation
    links: []
  bundledCode: "#line 1 \"number/lagrange_interpolation.hpp\"\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 5 \"\
    number/lagrange_interpolation.hpp\"\n\n/**\n * @brief Lagrange interpolation\n\
    \ * @note O(n^2)\n * @note works on any field\n * @note the error is very big\n\
    \ */\nstd::vector<long double> lagrange_interpolate(const std::vector<std::pair<long\
    \ double, long double> > & points) {\n    // given ((x_0, y_1), \\dots, (x_{n\
    \ - 1}, y_{n - 1}))\n    int n = points.size();\n\n    // functions\n    auto\
    \ mul_monomial = [&](std::vector<long double> & f, long double a) {  // f \\gets\
    \ f \\cdot (x - a)\n        assert (f[n] == 0);\n        REP_R (i, n + 1) {\n\
    \            f[i] = (i >= 1 ? f[i - 1] : 0) - a * f[i];\n        }\n    };\n \
    \   auto div_monomial = [&](std::vector<long double> & f, long double a) {  //\
    \ f \\gets f / (x - a)\n        long double last = 0;\n        REP_R (i, n + 1)\
    \ {\n            std::swap(f[i], last);\n            last += a * f[i];\n     \
    \   }\n    };\n    auto apply = [&](std::vector<long double> & f, long double\
    \ x) {  // f(x)\n        long double y = 0;\n        REP_R (i, n + 1) {\n    \
    \        y = y * x + f[i];\n        }\n        return y;\n    };\n\n    // let\
    \ g = \\prod_i (x - x_i)\n    // let g_i = g / (x - x_i)\n    // assert for all\
    \ j \\ne i. g_i(x_j) = 0\n    std::vector<long double> g(n + 1);\n    g[0] = 1;\n\
    \    for (auto point : points) {\n        mul_monomial(g, point.first);\n    }\n\
    \n    // let c_i = y_i / g_i(x_i)\n    // let f = \\sum_i c_i g_i / (x - x_i)\n\
    \    // assert for all i. f(x_i) = y_i\n    std::vector<long double> f(n + 1);\n\
    \    for (auto point : points) {\n        div_monomial(g, point.first);\n    \
    \    long double c_i = point.second / apply(g, point.first);\n        REP (j,\
    \ n + 1) {\n            f[j] += c_i * g[j];\n        }\n        mul_monomial(g,\
    \ point.first);\n    }\n    assert (f.back() == 0);\n    f.pop_back();\n    return\
    \ f;\n}\n"
  code: "#include <cassert>\n#include <utility>\n#include <vector>\n#include \"../utils/macros.hpp\"\
    \n\n/**\n * @brief Lagrange interpolation\n * @note O(n^2)\n * @note works on\
    \ any field\n * @note the error is very big\n */\nstd::vector<long double> lagrange_interpolate(const\
    \ std::vector<std::pair<long double, long double> > & points) {\n    // given\
    \ ((x_0, y_1), \\dots, (x_{n - 1}, y_{n - 1}))\n    int n = points.size();\n\n\
    \    // functions\n    auto mul_monomial = [&](std::vector<long double> & f, long\
    \ double a) {  // f \\gets f \\cdot (x - a)\n        assert (f[n] == 0);\n   \
    \     REP_R (i, n + 1) {\n            f[i] = (i >= 1 ? f[i - 1] : 0) - a * f[i];\n\
    \        }\n    };\n    auto div_monomial = [&](std::vector<long double> & f,\
    \ long double a) {  // f \\gets f / (x - a)\n        long double last = 0;\n \
    \       REP_R (i, n + 1) {\n            std::swap(f[i], last);\n            last\
    \ += a * f[i];\n        }\n    };\n    auto apply = [&](std::vector<long double>\
    \ & f, long double x) {  // f(x)\n        long double y = 0;\n        REP_R (i,\
    \ n + 1) {\n            y = y * x + f[i];\n        }\n        return y;\n    };\n\
    \n    // let g = \\prod_i (x - x_i)\n    // let g_i = g / (x - x_i)\n    // assert\
    \ for all j \\ne i. g_i(x_j) = 0\n    std::vector<long double> g(n + 1);\n   \
    \ g[0] = 1;\n    for (auto point : points) {\n        mul_monomial(g, point.first);\n\
    \    }\n\n    // let c_i = y_i / g_i(x_i)\n    // let f = \\sum_i c_i g_i / (x\
    \ - x_i)\n    // assert for all i. f(x_i) = y_i\n    std::vector<long double>\
    \ f(n + 1);\n    for (auto point : points) {\n        div_monomial(g, point.first);\n\
    \        long double c_i = point.second / apply(g, point.first);\n        REP\
    \ (j, n + 1) {\n            f[j] += c_i * g[j];\n        }\n        mul_monomial(g,\
    \ point.first);\n    }\n    assert (f.back() == 0);\n    f.pop_back();\n    return\
    \ f;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: number/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/number/lagrange_interpolation.hpp
- /library/number/lagrange_interpolation.hpp.html
title: Lagrange interpolation
---
