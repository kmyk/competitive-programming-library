---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.test.cpp
    title: data_structure/binary_indexed_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"data_structure/binary_indexed_tree.hpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i\
    \ = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) <\
    \ (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
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
    \ acc;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"utils/macros.hpp\"\
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
    \ acc;\n    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: data_structure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2021-04-24 11:47:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/binary_indexed_tree.test.cpp
documentation_of: data_structure/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/data_structure/binary_indexed_tree.hpp
- /library/data_structure/binary_indexed_tree.hpp.html
title: Binary Indexed Tree
---
