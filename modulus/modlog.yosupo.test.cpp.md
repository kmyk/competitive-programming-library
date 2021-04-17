---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/modlog.hpp
    title: "discrete log / \u96E2\u6563\u5BFE\u6570 (the baby-step giant-step, $O(\\\
      sqrt{m})$)"
  - icon: ':heavy_check_mark:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"modulus/modlog.yosupo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#line 2 \"modulus/modlog.hpp\"\n#include <algorithm>\n#include <climits>\n#include\
    \ <cmath>\n#include <cstdint>\n#include <unordered_map>\n#line 3 \"modulus/modinv.hpp\"\
    \n#include <cassert>\n#line 5 \"modulus/modinv.hpp\"\n\ninline int32_t modinv_nocheck(int32_t\
    \ value, int32_t MOD) {\n    assert (0 <= value and value < MOD);\n    if (value\
    \ == 0) return -1;\n    int64_t a = value, b = MOD;\n    int64_t x = 0, y = 1;\n\
    \    for (int64_t u = 1, v = 0; a; ) {\n        int64_t q = b / a;\n        x\
    \ -= q * u; std::swap(x, u);\n        y -= q * v; std::swap(y, v);\n        b\
    \ -= q * a; std::swap(b, a);\n    }\n    if (not (value * x + MOD * y == b and\
    \ b == 1)) return -1;\n    if (x < 0) x += MOD;\n    assert (0 <= x and x < MOD);\n\
    \    return x;\n}\n\ninline int32_t modinv(int32_t x, int32_t MOD) {\n    int32_t\
    \ y = modinv_nocheck(x, MOD);\n    assert (y != -1);\n    return y;\n}\n#line\
    \ 4 \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t x, uint64_t\
    \ k, int32_t MOD) {\n    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n \
    \   uint_fast64_t y = 1;\n    for (; k; k >>= 1) {\n        if (k & 1) (y *= x)\
    \ %= MOD;\n        (x *= x) %= MOD;\n    }\n    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);\n\
    \    return y;\n}\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i\
    \ = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) <\
    \ (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 10 \"modulus/modlog.hpp\"\
    \n#include <iostream>\n\n/**\n * @brief discrete log / \u96E2\u6563\u5BFE\u6570\
    \ (the baby-step giant-step, $O(\\sqrt{m})$)\n * @description find the smallest\
    \ $x \\ge 0$ s.t. $g^x \\equiv y \\pmod{m}$\n * @param m is a positive integer\n\
    \ * @note -1 if not found\n */\ninline int modlog(int g, int y, int m) {\n   \
    \ assert (0 <= g and g < m);\n    assert (0 <= y and y < m);\n    if (m == 1)\
    \ return 0;\n    if (y == 1) return 0;\n    if (g == 0 and y == 0) return 1;\n\
    \n    // meet-in-the-middle; let x = a \\sqrt{m} + b\n    int sqrt_m = sqrt(m)\
    \ + 100;  // + 100 is required to bruteforce g^b for b < 100; this avoids problems\
    \ with g != 0 and y = 0\n    assert (sqrt_m >= 0);\n\n    // baby-step: list (y,\
    \ gy, g^2 y, ...) = (g^x, g^{x + 1}, g^{x + 2}, ...)\n    std::unordered_map<int,\
    \ int> table;\n    int baby = 1;\n    REP (b, sqrt_m) {\n        if (baby == y)\
    \ return b;\n        table[(int64_t)baby * y % m] = b;\n        baby = (int64_t)baby\
    \ * g % m;\n    }\n\n    // giant-step: list (g^{sqrt(m)}, g^{2 sqrt(m)}, g^{3\
    \ sqrt(m)}, ...)\n    int giant = 1;\n    REP3 (a, 1, sqrt_m + 3) {\n        giant\
    \ = (int64_t)giant * baby % m;\n        auto it = table.find(giant);\n       \
    \ if (it != table.end()) {\n            int b = it->second;\n            int x\
    \ = (int64_t)a * sqrt_m - b;\n            assert (x >= 0);\n            return\
    \ (modpow(g, x, m) == y ? x : -1);\n        }\n    }\n    return -1;\n}\n#line\
    \ 4 \"modulus/modlog.yosupo.test.cpp\"\n#include <cstdio>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n    int t; scanf(\"%d\", &t);\n    while\
    \ (t --) {\n        int x, y, m; scanf(\"%d%d%d\", &x, &y, &m);\n        int k\
    \ = modlog(x, y, m);\n        printf(\"%d\\n\", k);\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include \"modulus/modlog.hpp\"\n#include <cassert>\n#include <cstdio>\n#include\
    \ <vector>\nusing namespace std;\n\nint main() {\n    int t; scanf(\"%d\", &t);\n\
    \    while (t --) {\n        int x, y, m; scanf(\"%d%d%d\", &x, &y, &m);\n   \
    \     int k = modlog(x, y, m);\n        printf(\"%d\\n\", k);\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - modulus/modlog.hpp
  - modulus/modinv.hpp
  - modulus/modpow.hpp
  - utils/macros.hpp
  isVerificationFile: true
  path: modulus/modlog.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-06-16 07:51:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: modulus/modlog.yosupo.test.cpp
layout: document
redirect_from:
- /verify/modulus/modlog.yosupo.test.cpp
- /verify/modulus/modlog.yosupo.test.cpp.html
title: modulus/modlog.yosupo.test.cpp
---