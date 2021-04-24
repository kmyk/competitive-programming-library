---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"data_structure/binary_indexed_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include <cstdio>\n\
    #include <tuple>\n#include <vector>\n#line 2 \"data_structure/binary_indexed_tree.hpp\"\
    \n#include <cassert>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int\
    \ i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i)\
    \ < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 5 \"data_structure/binary_indexed_tree.hpp\"\
    \n\n/**\n * @brief Binary Indexed Tree\n */\ntemplate <typename CommutativeMonoid>\n\
    struct binary_indexed_tree {\n    typedef typename CommutativeMonoid::value_type\
    \ value_type;\n    CommutativeMonoid mon;\n    std::vector<value_type> data;\n\
    \    binary_indexed_tree(int n, CommutativeMonoid const & mon_ = CommutativeMonoid())\n\
    \            : mon(mon_),\n              data(n, mon.unit()) {\n    }\n    template\
    \ <class InputIterator>\n    binary_indexed_tree(InputIterator first, InputIterator\
    \ last, CommutativeMonoid const & mon_ = CommutativeMonoid())\n            : mon(mon_),\n\
    \              data(first, last) {\n        REP3 (j, 1, data.size() + 1) {\n \
    \           int k = j + (j & -j);\n            if (k - 1 < static_cast<int>(data.size()))\
    \ {\n                data[k - 1] = mon.mult(data[k - 1], data[j - 1]);\n     \
    \       }\n        }\n    }\n    /**\n     * @note $a_i \\gets a_i + z$\n    \
    \ * @note $O(\\log N)$\n     */\n    void point_mult(int i, value_type z) {\n\
    \        assert (0 <= i and i < static_cast<int>(data.size()));\n        for (int\
    \ j = i + 1; j <= static_cast<int>(data.size()); j += j & -j) {\n            data[j\
    \ - 1] = mon.mult(data[j - 1], z);\n        }\n    }\n    /**\n     * @note $\\\
    sum _ {i \\lt r} a_i$\n     * @note $O(\\log N)$\n     */\n    value_type initial_range_get(int\
    \ r) {\n        assert (0 <= r and r <= static_cast<int>(data.size()));\n    \
    \    value_type acc = mon.unit();\n        for (int i = r; 0 < i; i -= i & -i)\
    \ {\n            acc = mon.mult(data[i - 1], acc);\n        }\n        return\
    \ acc;\n    }\n};\n#line 2 \"monoids/plus.hpp\"\n\ntemplate <class T>\nstruct\
    \ plus_monoid {\n    typedef T value_type;\n    value_type unit() const { return\
    \ value_type(); }\n    value_type mult(value_type a, value_type b) const { return\
    \ a + b; }\n};\n#line 8 \"data_structure/binary_indexed_tree.test.cpp\"\nusing\
    \ namespace std;\n\nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n   \
    \ vector<long long> a(n);\n    REP (i, n) {\n        scanf(\"%lld\", &a[i]);\n\
    \    }\n    binary_indexed_tree<plus_monoid<long long> > bit(ALL(a));\n    while\
    \ (q --) {\n        int t, x, y; scanf(\"%d%d%d\", &t, &x, &y);\n        if (t\
    \ == 0) {\n            bit.point_mult(x, y);\n        } else if (t == 1) {\n \
    \           long long answer = bit.initial_range_get(y) - bit.initial_range_get(x);\n\
    \            printf(\"%lld\\n\", answer);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <cstdio>\n#include <tuple>\n#include <vector>\n#include \"data_structure/binary_indexed_tree.hpp\"\
    \n#include \"monoids/plus.hpp\"\n#include \"utils/macros.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n    vector<long\
    \ long> a(n);\n    REP (i, n) {\n        scanf(\"%lld\", &a[i]);\n    }\n    binary_indexed_tree<plus_monoid<long\
    \ long> > bit(ALL(a));\n    while (q --) {\n        int t, x, y; scanf(\"%d%d%d\"\
    , &t, &x, &y);\n        if (t == 0) {\n            bit.point_mult(x, y);\n   \
    \     } else if (t == 1) {\n            long long answer = bit.initial_range_get(y)\
    \ - bit.initial_range_get(x);\n            printf(\"%lld\\n\", answer);\n    \
    \    }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/binary_indexed_tree.hpp
  - utils/macros.hpp
  - monoids/plus.hpp
  isVerificationFile: true
  path: data_structure/binary_indexed_tree.test.cpp
  requiredBy: []
  timestamp: '2021-04-24 11:47:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/binary_indexed_tree.test.cpp
layout: document
redirect_from:
- /verify/data_structure/binary_indexed_tree.test.cpp
- /verify/data_structure/binary_indexed_tree.test.cpp.html
title: data_structure/binary_indexed_tree.test.cpp
---
