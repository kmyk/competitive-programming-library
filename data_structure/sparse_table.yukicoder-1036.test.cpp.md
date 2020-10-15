---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table (idempotent monoid)
  - icon: ':heavy_check_mark:'
    path: monoids/gcd.hpp
    title: monoids/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: number/gcd.hpp
    title: number/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1036
    links:
    - https://yukicoder.me/problems/no/1036
  bundledCode: "#line 1 \"data_structure/sparse_table.yukicoder-1036.test.cpp\"\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/1036\"\n#include <cstdio>\n\
    #include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i\
    \ = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) <\
    \ (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 2 \"data_structure/sparse_table.hpp\"\
    \n#include <cassert>\n#line 5 \"data_structure/sparse_table.hpp\"\n\n/**\n * @brief\
    \ Sparse Table (idempotent monoid)\n * @note the unit is required just for convenience\n\
    \ * @note $O(N \\log N)$ space\n */\ntemplate <class IdempotentMonoid>\nstruct\
    \ sparse_table {\n    typedef typename IdempotentMonoid::value_type value_type;\n\
    \    std::vector<std::vector<value_type> > table;\n    IdempotentMonoid mon;\n\
    \    sparse_table() = default;\n\n    /**\n     * @note $O(N \\log N)$ time\n\
    \     */\n    template <class InputIterator>\n    sparse_table(InputIterator first,\
    \ InputIterator last, const IdempotentMonoid & mon_ = IdempotentMonoid())\n  \
    \          : mon(mon_) {\n        table.emplace_back(first, last);\n        int\
    \ n = table[0].size();\n        int log_n = 32 - __builtin_clz(n);\n        table.resize(log_n,\
    \ std::vector<value_type>(n));\n        REP (k, log_n - 1) {\n            REP\
    \ (i, n) {\n                table[k + 1][i] = i + (1ll << k) < n ?\n         \
    \           mon.mult(table[k][i], table[k][i + (1ll << k)]) :\n              \
    \      table[k][i];\n            }\n        }\n    }\n\n    /**\n     * @note\
    \ $O(1)$\n     */\n    value_type range_get(int l, int r) const {\n        if\
    \ (l == r) return mon.unit();  // if there is no unit, remove this line\n    \
    \    assert (0 <= l and l < r and r <= (int)table[0].size());\n        int k =\
    \ 31 - __builtin_clz(r - l);  // log2\n        return mon.mult(table[k][l], table[k][r\
    \ - (1ll << k)]);\n    }\n};\n#line 2 \"number/gcd.hpp\"\n#include <algorithm>\n\
    \n/**\n * @note if arguments are negative, the result may be negative\n */\ntemplate\
    \ <typename T>\nT gcd(T a, T b) {\n    while (a) {\n        b %= a;\n        std::swap(a,\
    \ b);\n    }\n    return b;\n}\n\ntemplate <typename T>\nT lcm(T a, T b) {\n \
    \   return a / gcd(a, b) * b;\n}\n#line 3 \"monoids/gcd.hpp\"\n\n/**\n * @note\
    \ a semilattice\n */\ntemplate <class Integer>\nstruct gcd_monoid {\n    typedef\
    \ Integer value_type;\n    Integer unit() const { return 0; }\n    Integer mult(Integer\
    \ a, Integer b) const { return gcd(a, b); }\n};\n#line 7 \"data_structure/sparse_table.yukicoder-1036.test.cpp\"\
    \n\nlong long solve(int n, const std::vector<long long> & a) {\n    sparse_table<gcd_monoid<long\
    \ long> > table(ALL(a));\n    int r = 0;\n    long long ans = 0;\n    REP (l,\
    \ n) {\n        while (r < n and table.range_get(l, r) != 1) {\n            ++\
    \ r;\n        }\n        if (r == n and table.range_get(l, r) != 1) {\n      \
    \      break;\n        }\n        ans += n - r + 1;\n    }\n    return ans;\n\
    }\n\nint main() {\n    int n; scanf(\"%d\", &n);\n    std::vector<long long> a(n);\n\
    \    REP (i, n) {\n        scanf(\"%lld\", &a[i]);\n    }\n    printf(\"%lld\\\
    n\", solve(n, a));\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1036\"\n#include <cstdio>\n\
    #include <vector>\n#include \"utils/macros.hpp\"\n#include \"data_structure/sparse_table.hpp\"\
    \n#include \"monoids/gcd.hpp\"\n\nlong long solve(int n, const std::vector<long\
    \ long> & a) {\n    sparse_table<gcd_monoid<long long> > table(ALL(a));\n    int\
    \ r = 0;\n    long long ans = 0;\n    REP (l, n) {\n        while (r < n and table.range_get(l,\
    \ r) != 1) {\n            ++ r;\n        }\n        if (r == n and table.range_get(l,\
    \ r) != 1) {\n            break;\n        }\n        ans += n - r + 1;\n    }\n\
    \    return ans;\n}\n\nint main() {\n    int n; scanf(\"%d\", &n);\n    std::vector<long\
    \ long> a(n);\n    REP (i, n) {\n        scanf(\"%lld\", &a[i]);\n    }\n    printf(\"\
    %lld\\n\", solve(n, a));\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - data_structure/sparse_table.hpp
  - monoids/gcd.hpp
  - number/gcd.hpp
  isVerificationFile: true
  path: data_structure/sparse_table.yukicoder-1036.test.cpp
  requiredBy: []
  timestamp: '2020-04-24 23:33:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/sparse_table.yukicoder-1036.test.cpp
layout: document
redirect_from:
- /verify/data_structure/sparse_table.yukicoder-1036.test.cpp
- /verify/data_structure/sparse_table.yukicoder-1036.test.cpp.html
title: data_structure/sparse_table.yukicoder-1036.test.cpp
---
