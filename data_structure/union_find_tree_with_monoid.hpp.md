---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: utils/dsu_on_tree.aoj.test.cpp
    title: utils/dsu_on_tree.aoj.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: a disjoint set structure with monoid
    links: []
  bundledCode: "#line 2 \"data_structure/union_find_tree_with_monoid.hpp\"\n#include\
    \ <vector>\n\n/**\n * @brief a disjoint set structure with monoid\n * @note union-by-size\
    \ + path-compression\n */\ntemplate <class Monoid>\nstruct union_find_tree_with_monoid\
    \ {\n    typedef typename Monoid::value_type value_type;\n    const Monoid mon;\n\
    \    std::vector<int> data;\n    std::vector<value_type> value;\n\n    union_find_tree_with_monoid()\
    \ = default;\n    union_find_tree_with_monoid(std::size_t n, Monoid const & mon_\
    \ = Monoid()) : mon(mon_), data(n, -1), value(n, mon.unit()) {}\n    bool is_root(int\
    \ i) { return data[i] < 0; }\n    int find_root(int i) { return is_root(i) ? i\
    \ : (data[i] = find_root(data[i])); }\n    int tree_size(int i) { return - data[find_root(i)];\
    \ }\n    int unite_trees(int i, int j) {\n        i = find_root(i); j = find_root(j);\n\
    \        if (i != j) {\n            if (tree_size(i) < tree_size(j)) std::swap(i,\
    \ j);\n            data[i] += data[j];\n            data[j] = i;\n           \
    \ value[i] = mon.mult(value[i], value[j]);\n        }\n        return i;\n   \
    \ }\n    bool is_same(int i, int j) { return find_root(i) == find_root(j); }\n\
    \    value_type get_value(int i) { return value[find_root(i)]; }\n    void set_value(int\
    \ i, value_type z) { value[find_root(i)] = z; }\n};\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief a disjoint set structure\
    \ with monoid\n * @note union-by-size + path-compression\n */\ntemplate <class\
    \ Monoid>\nstruct union_find_tree_with_monoid {\n    typedef typename Monoid::value_type\
    \ value_type;\n    const Monoid mon;\n    std::vector<int> data;\n    std::vector<value_type>\
    \ value;\n\n    union_find_tree_with_monoid() = default;\n    union_find_tree_with_monoid(std::size_t\
    \ n, Monoid const & mon_ = Monoid()) : mon(mon_), data(n, -1), value(n, mon.unit())\
    \ {}\n    bool is_root(int i) { return data[i] < 0; }\n    int find_root(int i)\
    \ { return is_root(i) ? i : (data[i] = find_root(data[i])); }\n    int tree_size(int\
    \ i) { return - data[find_root(i)]; }\n    int unite_trees(int i, int j) {\n \
    \       i = find_root(i); j = find_root(j);\n        if (i != j) {\n         \
    \   if (tree_size(i) < tree_size(j)) std::swap(i, j);\n            data[i] +=\
    \ data[j];\n            data[j] = i;\n            value[i] = mon.mult(value[i],\
    \ value[j]);\n        }\n        return i;\n    }\n    bool is_same(int i, int\
    \ j) { return find_root(i) == find_root(j); }\n    value_type get_value(int i)\
    \ { return value[find_root(i)]; }\n    void set_value(int i, value_type z) { value[find_root(i)]\
    \ = z; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find_tree_with_monoid.hpp
  requiredBy: []
  timestamp: '2019-12-14 05:03:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - utils/dsu_on_tree.aoj.test.cpp
documentation_of: data_structure/union_find_tree_with_monoid.hpp
layout: document
redirect_from:
- /library/data_structure/union_find_tree_with_monoid.hpp
- /library/data_structure/union_find_tree_with_monoid.hpp.html
title: a disjoint set structure with monoid
---
