---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: binary indexed tree
    links: []
  bundledCode: "#line 2 \"data_structure/binary_indexed_tree.hpp\"\n#include <vector>\n\
    \n/**\n * @brief binary indexed tree\n */\ntemplate <typename Monoid>\nstruct\
    \ binary_indexed_tree {\n    typedef typename Monoid::value_type value_type;\n\
    \    std::vector<value_type> data;\n    Monoid mon;\n    binary_indexed_tree(size_t\
    \ n, Monoid const & a_mon = Monoid())\n            : mon(a_mon) {\n        data.resize(n,\
    \ mon.unit());\n    }\n    /**\n     * @note a_i \\gets z\n     */\n    void point_mult(size_t\
    \ i, value_type z) {\n        for (size_t j = i + 1; j <= data.size(); j += j\
    \ & -j) {\n            data[j - 1] = mon.mult(data[j - 1], z);\n        }\n  \
    \  }\n    /**\n     * @note \\sum _ {j \\lt i} a_j\n     */\n    value_type initial_range_get(size_t\
    \ i) {\n        value_type acc = mon.unit();\n        for (size_t j = i; 0 < j;\
    \ j -= j & -j) acc = mon.mult(data[j - 1], acc);\n        return acc;\n    }\n\
    };\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief binary indexed tree\n */\n\
    template <typename Monoid>\nstruct binary_indexed_tree {\n    typedef typename\
    \ Monoid::value_type value_type;\n    std::vector<value_type> data;\n    Monoid\
    \ mon;\n    binary_indexed_tree(size_t n, Monoid const & a_mon = Monoid())\n \
    \           : mon(a_mon) {\n        data.resize(n, mon.unit());\n    }\n    /**\n\
    \     * @note a_i \\gets z\n     */\n    void point_mult(size_t i, value_type\
    \ z) {\n        for (size_t j = i + 1; j <= data.size(); j += j & -j) {\n    \
    \        data[j - 1] = mon.mult(data[j - 1], z);\n        }\n    }\n    /**\n\
    \     * @note \\sum _ {j \\lt i} a_j\n     */\n    value_type initial_range_get(size_t\
    \ i) {\n        value_type acc = mon.unit();\n        for (size_t j = i; 0 < j;\
    \ j -= j & -j) acc = mon.mult(data[j - 1], acc);\n        return acc;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2021-04-24 02:07:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/data_structure/binary_indexed_tree.hpp
- /library/data_structure/binary_indexed_tree.hpp.html
title: binary indexed tree
---
