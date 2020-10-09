---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_connectivity_offline.hpp
    title: Dynamic Connectivity (offline, commutative monoids)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
    title: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union-Find Tree (foldable with commutative monoids, undoable)
    links: []
  bundledCode: "#line 2 \"data_structure/union_find_tree_foldable_undoable.hpp\"\n\
    #include <cassert>\n#include <tuple>\n#include <utility>\n#include <vector>\n\n\
    /**\n * @brief Union-Find Tree (foldable with commutative monoids, undoable)\n\
    \ * @note $O(\\log N)$\n * @note union-by-size (without path-compression)\n */\n\
    template <class CommutativeMonoid>\nclass union_find_tree_foldable_undoable {\n\
    \    typedef typename CommutativeMonoid::value_type value_type;\n    const CommutativeMonoid\
    \ mon;\n    std::vector<int> data;\n    std::vector<value_type> value;\n    std::vector<std::tuple<int,\
    \ int, value_type> > history;\n\npublic:\n    union_find_tree_foldable_undoable()\
    \ = default;\n    union_find_tree_foldable_undoable(std::size_t size, const CommutativeMonoid\
    \ & mon_ = CommutativeMonoid())\n            : mon(mon_), data(size, -1), value(size,\
    \ mon.unit()) {\n    }\n    template <class InputIterator>\n    union_find_tree_foldable_undoable(InputIterator\
    \ first, InputIterator last, const CommutativeMonoid & mon_ = CommutativeMonoid())\n\
    \            : mon(mon_), data(std::distance(first, last), -1), value(first, last)\
    \ {\n    }\n\n    bool is_root(int i) { return data[i] < 0; }\n    int find_root(int\
    \ i) { while (not is_root(i)) i = data[i]; return i; }\n    int get_size(int i)\
    \ { return - data[find_root(i)]; }\n    void unite_trees(int i, int j) {\n   \
    \     i = find_root(i);\n        j = find_root(j);\n        if (get_size(i) <\
    \ get_size(j)) std::swap(i, j);\n        history.emplace_back(-1, 0, mon.unit());\n\
    \        if (i != j) {\n            history.emplace_back(i, data[i], value[i]);\n\
    \            history.emplace_back(j, data[j], value[j]);\n            data[i]\
    \ += data[j];\n            data[j] = i;\n            value[i] = mon.mult(value[i],\
    \ value[j]);\n        }\n    }\n    bool is_connected(int i, int j) { return find_root(i)\
    \ == find_root(j); }\n\n    void tree_set(int i, value_type x) {\n        i =\
    \ find_root(i);\n        history.emplace_back(-1, 0, mon.unit());\n        history.emplace_back(i,\
    \ data[i], value[i]);\n        value[i] = x;\n    }\n    value_type tree_get(int\
    \ i) {\n        return value[find_root(i)];\n    }\n    /**\n     * @note for\
    \ unite_trees() and tree_set()\n     */\n    void undo() {\n        while (true)\
    \ {\n            assert (not history.empty());\n            auto [i, data_i, value_i]\
    \ = history.back();\n            history.pop_back();\n            if (i == -1)\
    \ break;\n            value[i] = value_i;\n            data[i] = data_i;\n   \
    \     }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief Union-Find Tree (foldable with commutative\
    \ monoids, undoable)\n * @note $O(\\log N)$\n * @note union-by-size (without path-compression)\n\
    \ */\ntemplate <class CommutativeMonoid>\nclass union_find_tree_foldable_undoable\
    \ {\n    typedef typename CommutativeMonoid::value_type value_type;\n    const\
    \ CommutativeMonoid mon;\n    std::vector<int> data;\n    std::vector<value_type>\
    \ value;\n    std::vector<std::tuple<int, int, value_type> > history;\n\npublic:\n\
    \    union_find_tree_foldable_undoable() = default;\n    union_find_tree_foldable_undoable(std::size_t\
    \ size, const CommutativeMonoid & mon_ = CommutativeMonoid())\n            : mon(mon_),\
    \ data(size, -1), value(size, mon.unit()) {\n    }\n    template <class InputIterator>\n\
    \    union_find_tree_foldable_undoable(InputIterator first, InputIterator last,\
    \ const CommutativeMonoid & mon_ = CommutativeMonoid())\n            : mon(mon_),\
    \ data(std::distance(first, last), -1), value(first, last) {\n    }\n\n    bool\
    \ is_root(int i) { return data[i] < 0; }\n    int find_root(int i) { while (not\
    \ is_root(i)) i = data[i]; return i; }\n    int get_size(int i) { return - data[find_root(i)];\
    \ }\n    void unite_trees(int i, int j) {\n        i = find_root(i);\n       \
    \ j = find_root(j);\n        if (get_size(i) < get_size(j)) std::swap(i, j);\n\
    \        history.emplace_back(-1, 0, mon.unit());\n        if (i != j) {\n   \
    \         history.emplace_back(i, data[i], value[i]);\n            history.emplace_back(j,\
    \ data[j], value[j]);\n            data[i] += data[j];\n            data[j] =\
    \ i;\n            value[i] = mon.mult(value[i], value[j]);\n        }\n    }\n\
    \    bool is_connected(int i, int j) { return find_root(i) == find_root(j); }\n\
    \n    void tree_set(int i, value_type x) {\n        i = find_root(i);\n      \
    \  history.emplace_back(-1, 0, mon.unit());\n        history.emplace_back(i, data[i],\
    \ value[i]);\n        value[i] = x;\n    }\n    value_type tree_get(int i) {\n\
    \        return value[find_root(i)];\n    }\n    /**\n     * @note for unite_trees()\
    \ and tree_set()\n     */\n    void undo() {\n        while (true) {\n       \
    \     assert (not history.empty());\n            auto [i, data_i, value_i] = history.back();\n\
    \            history.pop_back();\n            if (i == -1) break;\n          \
    \  value[i] = value_i;\n            data[i] = data_i;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find_tree_foldable_undoable.hpp
  requiredBy:
  - data_structure/dynamic_connectivity_offline.hpp
  timestamp: '2020-03-08 03:44:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: data_structure/union_find_tree_foldable_undoable.hpp
layout: document
redirect_from:
- /library/data_structure/union_find_tree_foldable_undoable.hpp
- /library/data_structure/union_find_tree_foldable_undoable.hpp.html
title: Union-Find Tree (foldable with commutative monoids, undoable)
---
