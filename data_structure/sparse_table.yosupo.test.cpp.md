---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table (idempotent monoid)
  - icon: ':heavy_check_mark:'
    path: monoids/min.hpp
    title: monoids/min.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"data_structure/sparse_table.yosupo.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"data_structure/sparse_table.hpp\"\
    \n#include <cassert>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define\
    \ REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for\
    \ (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n)\
    \ - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 5 \"\
    data_structure/sparse_table.hpp\"\n\n/**\n * @brief Sparse Table (idempotent monoid)\n\
    \ * @note the unit is required just for convenience\n * @note $O(N \\log N)$ space\n\
    \ */\ntemplate <class IdempotentMonoid>\nstruct sparse_table {\n    typedef typename\
    \ IdempotentMonoid::value_type value_type;\n    std::vector<std::vector<value_type>\
    \ > table;\n    IdempotentMonoid mon;\n    sparse_table() = default;\n\n    /**\n\
    \     * @note $O(N \\log N)$ time\n     */\n    template <class InputIterator>\n\
    \    sparse_table(InputIterator first, InputIterator last, const IdempotentMonoid\
    \ & mon_ = IdempotentMonoid())\n            : mon(mon_) {\n        table.emplace_back(first,\
    \ last);\n        int n = table[0].size();\n        int log_n = 32 - __builtin_clz(n);\n\
    \        table.resize(log_n, std::vector<value_type>(n));\n        REP (k, log_n\
    \ - 1) {\n            REP (i, n) {\n                table[k + 1][i] = i + (1ll\
    \ << k) < n ?\n                    mon.mult(table[k][i], table[k][i + (1ll <<\
    \ k)]) :\n                    table[k][i];\n            }\n        }\n    }\n\n\
    \    /**\n     * @note $O(1)$\n     */\n    value_type range_get(int l, int r)\
    \ const {\n        if (l == r) return mon.unit();  // if there is no unit, remove\
    \ this line\n        assert (0 <= l and l < r and r <= (int)table[0].size());\n\
    \        int k = 31 - __builtin_clz(r - l);  // log2\n        return mon.mult(table[k][l],\
    \ table[k][r - (1ll << k)]);\n    }\n};\n#line 3 \"data_structure/sparse_table.yosupo.test.cpp\"\
    \n\n#line 2 \"monoids/min.hpp\"\n#include <algorithm>\n#include <limits>\n\ntemplate\
    \ <class T>\nstruct min_monoid {\n    typedef T value_type;\n    value_type unit()\
    \ const { return std::numeric_limits<T>::max(); }\n    value_type mult(value_type\
    \ a, value_type b) const { return std::min(a, b); }\n};\n#line 6 \"data_structure/sparse_table.yosupo.test.cpp\"\
    \n#include <cstdio>\n#line 8 \"data_structure/sparse_table.yosupo.test.cpp\"\n\
    using namespace std;\n\nint main() {\n    // input a sequence\n    int n, q; scanf(\"\
    %d%d\", &n, &q);\n    vector<int> a(n);\n    REP (i, n) {\n        scanf(\"%d\"\
    , &a[i]);\n    }\n\n    // construct the sparse table\n    sparse_table<min_monoid<int>\
    \ > st(ALL(a));\n\n    // answer to queries\n    while (q --) {\n        int l,\
    \ r; scanf(\"%d%d\", &l, &r);\n        int answer = st.range_get(l, r);\n    \
    \    printf(\"%d\\n\", answer);\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    data_structure/sparse_table.hpp\"\n\n#include \"utils/macros.hpp\"\n#include \"\
    monoids/min.hpp\"\n#include <cstdio>\n#include <vector>\nusing namespace std;\n\
    \nint main() {\n    // input a sequence\n    int n, q; scanf(\"%d%d\", &n, &q);\n\
    \    vector<int> a(n);\n    REP (i, n) {\n        scanf(\"%d\", &a[i]);\n    }\n\
    \n    // construct the sparse table\n    sparse_table<min_monoid<int> > st(ALL(a));\n\
    \n    // answer to queries\n    while (q --) {\n        int l, r; scanf(\"%d%d\"\
    , &l, &r);\n        int answer = st.range_get(l, r);\n        printf(\"%d\\n\"\
    , answer);\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/sparse_table.hpp
  - utils/macros.hpp
  - monoids/min.hpp
  isVerificationFile: true
  path: data_structure/sparse_table.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-03-04 19:51:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/sparse_table.yosupo.test.cpp
layout: document
redirect_from:
- /verify/data_structure/sparse_table.yosupo.test.cpp
- /verify/data_structure/sparse_table.yosupo.test.cpp.html
title: data_structure/sparse_table.yosupo.test.cpp
---
