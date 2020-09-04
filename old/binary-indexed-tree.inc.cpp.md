---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"old/binary-indexed-tree.inc.cpp\"\ntemplate <typename Monoid>\n\
    struct binary_indexed_tree {  // on monoid\n    typedef typename Monoid::value_type\
    \ value_type;\n    vector<value_type> data;\n    Monoid mon;\n    binary_indexed_tree(size_t\
    \ n, Monoid const & a_mon = Monoid()) : mon(a_mon) {\n        data.resize(n, mon.unit());\n\
    \    }\n    void point_append(size_t i, value_type z) {  // data[i] += z\n   \
    \     for (size_t j = i + 1; j <= data.size(); j += j & -j) data[j - 1] = mon.append(data[j\
    \ - 1], z);\n    }\n    value_type initial_range_concat(size_t i) {  // sum [0,\
    \ i)\n        value_type acc = mon.unit();\n        for (size_t j = i; 0 < j;\
    \ j -= j & -j) acc = mon.append(data[j - 1], acc);\n        return acc;\n    }\n\
    };\nstruct plus_monoid {\n    typedef int value_type;\n    int unit() const {\
    \ return 0; }\n    int append(int a, int b) const { return a + b; }\n};\n\nunittest\
    \ {\n    binary_indexed_tree<plus_monoid> bit(8);\n    bit.point_append(3, 4);\n\
    \    bit.point_append(4, 3);\n    bit.point_append(7, 1);\n    assert (bit.initial_range_concat(3)\
    \ == 0);\n    assert (bit.initial_range_concat(5) == 7);\n    assert (bit.initial_range_concat(8)\
    \ == 8);\n    bit.point_append(4, 2);\n    assert (bit.initial_range_concat(3)\
    \ == 0);\n    assert (bit.initial_range_concat(5) == 9);\n    assert (bit.initial_range_concat(8)\
    \ == 10);\n}\n"
  code: "template <typename Monoid>\nstruct binary_indexed_tree {  // on monoid\n\
    \    typedef typename Monoid::value_type value_type;\n    vector<value_type> data;\n\
    \    Monoid mon;\n    binary_indexed_tree(size_t n, Monoid const & a_mon = Monoid())\
    \ : mon(a_mon) {\n        data.resize(n, mon.unit());\n    }\n    void point_append(size_t\
    \ i, value_type z) {  // data[i] += z\n        for (size_t j = i + 1; j <= data.size();\
    \ j += j & -j) data[j - 1] = mon.append(data[j - 1], z);\n    }\n    value_type\
    \ initial_range_concat(size_t i) {  // sum [0, i)\n        value_type acc = mon.unit();\n\
    \        for (size_t j = i; 0 < j; j -= j & -j) acc = mon.append(data[j - 1],\
    \ acc);\n        return acc;\n    }\n};\nstruct plus_monoid {\n    typedef int\
    \ value_type;\n    int unit() const { return 0; }\n    int append(int a, int b)\
    \ const { return a + b; }\n};\n\nunittest {\n    binary_indexed_tree<plus_monoid>\
    \ bit(8);\n    bit.point_append(3, 4);\n    bit.point_append(4, 3);\n    bit.point_append(7,\
    \ 1);\n    assert (bit.initial_range_concat(3) == 0);\n    assert (bit.initial_range_concat(5)\
    \ == 7);\n    assert (bit.initial_range_concat(8) == 8);\n    bit.point_append(4,\
    \ 2);\n    assert (bit.initial_range_concat(3) == 0);\n    assert (bit.initial_range_concat(5)\
    \ == 9);\n    assert (bit.initial_range_concat(8) == 10);\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/binary-indexed-tree.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/binary-indexed-tree.inc.cpp
layout: document
redirect_from:
- /library/old/binary-indexed-tree.inc.cpp
- /library/old/binary-indexed-tree.inc.cpp.html
title: old/binary-indexed-tree.inc.cpp
---
