---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number/inversion_number.hpp\"\n#include <cstdint>\n#include\
    \ <vector>\n#line 2 \"data_structure/binary_indexed_tree.hpp\"\n#include <cassert>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 5 \"data_structure/binary_indexed_tree.hpp\"\n\n/**\n * @brief\
    \ Binary Indexed Tree\n */\ntemplate <typename CommutativeMonoid>\nstruct binary_indexed_tree\
    \ {\n    typedef typename CommutativeMonoid::value_type value_type;\n    CommutativeMonoid\
    \ mon;\n    std::vector<value_type> data;\n    binary_indexed_tree(int n, CommutativeMonoid\
    \ const & mon_ = CommutativeMonoid())\n            : mon(mon_),\n            \
    \  data(n, mon.unit()) {\n    }\n    template <class InputIterator>\n    binary_indexed_tree(InputIterator\
    \ first, InputIterator last, CommutativeMonoid const & mon_ = CommutativeMonoid())\n\
    \            : mon(mon_),\n              data(first, last) {\n        REP3 (j,\
    \ 1, data.size() + 1) {\n            int k = j + (j & -j);\n            if (k\
    \ - 1 < static_cast<int>(data.size())) {\n                data[k - 1] = mon.mult(data[k\
    \ - 1], data[j - 1]);\n            }\n        }\n    }\n    /**\n     * @note\
    \ $a_i \\gets a_i + z$\n     * @note $O(\\log N)$\n     */\n    void point_mult(int\
    \ i, value_type z) {\n        assert (0 <= i and i < static_cast<int>(data.size()));\n\
    \        for (int j = i + 1; j <= static_cast<int>(data.size()); j += j & -j)\
    \ {\n            data[j - 1] = mon.mult(data[j - 1], z);\n        }\n    }\n \
    \   /**\n     * @note $\\sum _ {i \\lt r} a_i$\n     * @note $O(\\log N)$\n  \
    \   */\n    value_type initial_range_get(int r) {\n        assert (0 <= r and\
    \ r <= static_cast<int>(data.size()));\n        value_type acc = mon.unit();\n\
    \        for (int i = r; 0 < i; i -= i & -i) {\n            acc = mon.mult(data[i\
    \ - 1], acc);\n        }\n        return acc;\n    }\n};\n#line 2 \"monoids/plus.hpp\"\
    \n\ntemplate <class T>\nstruct plus_monoid {\n    typedef T value_type;\n    value_type\
    \ unit() const { return value_type(); }\n    value_type mult(value_type a, value_type\
    \ b) const { return a + b; }\n};\n#line 7 \"number/inversion_number.hpp\"\n\n\
    int64_t inversion_number(const std::vector<int> &a) {\n    int n = a.size();\n\
    \    binary_indexed_tree<plus_monoid<int64_t>> bit(n + 1);\n    int64_t cnt =\
    \ 0;\n    REP (i, n) {\n        cnt += i - bit.initial_range_get(a[i] + 1);\n\
    \        bit.point_mult(a[i], 1);\n    }\n    return cnt;\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n#include \"../data_structure/binary_indexed_tree.hpp\"\
    \n#include \"../utils/macros.hpp\"\n#include \"../monoids/plus.hpp\"\n\nint64_t\
    \ inversion_number(const std::vector<int> &a) {\n    int n = a.size();\n    binary_indexed_tree<plus_monoid<int64_t>>\
    \ bit(n + 1);\n    int64_t cnt = 0;\n    REP (i, n) {\n        cnt += i - bit.initial_range_get(a[i]\
    \ + 1);\n        bit.point_mult(a[i], 1);\n    }\n    return cnt;\n}\n"
  dependsOn:
  - data_structure/binary_indexed_tree.hpp
  - utils/macros.hpp
  - monoids/plus.hpp
  isVerificationFile: false
  path: number/inversion_number.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number/inversion_number.hpp
layout: document
redirect_from:
- /library/number/inversion_number.hpp
- /library/number/inversion_number.hpp.html
title: number/inversion_number.hpp
---
