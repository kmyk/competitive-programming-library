---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
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
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728 (\u5217\u6319\u30AF\u30A8\u30EA, \u5B8C\u5168\u4E8C\u5206\u6728)"
    links: []
  bundledCode: "#line 2 \"data_structure/reporting_segment_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <type_traits>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 8 \"data_structure/reporting_segment_tree.hpp\"\n\n/**\n\
    \ * @brief Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \ (\u5217\u6319\u30AF\u30A8\u30EA, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @note This\
    \ tree is very similar to the Bentley's original segment tree.\n */\ntemplate\
    \ <class Key>\nstruct reporting_segment_tree {\n    int size;\n    std::vector<std::vector<Key>\
    \ > data;\n    reporting_segment_tree() = default;\n    explicit reporting_segment_tree(int\
    \ size_) {\n        size = 1; while (size < size_) size *= 2;\n        data.resize(2\
    \ * size - 1);\n    }\n\n    /**\n     * @arg key must be unique\n     * @note\
    \ $O(\\log n)$\n     */\n    void add_segment(int l, int r, const Key & key) {\n\
    \        assert (0 <= l and l <= r and r <= size);\n        for (l += size, r\
    \ += size; l < r; l /= 2, r /= 2) {  // 1-based\n            if (l % 2 == 1) data[(l\
    \ ++) - 1].push_back(key);\n            if (r % 2 == 1) data[(-- r) - 1].push_back(key);\n\
    \        }\n    }\n\n    /**\n     * @note $O(\\log n + k)$\n     */\n    template\
    \ <class Callback>\n    void list_segments(int i, Callback & callback) {\n   \
    \     static_assert (std::is_invocable_r<void, Callback, const Key &>::value,\
    \ \"\");\n        assert (0 <= i and i < size);\n        for (i += size; i > 0;\
    \ i /= 2) {  // 1-based\n            for (const auto & key : data[i - 1]) {\n\
    \                callback(key);\n            }\n        }\n    }\n\n    /**\n\
    \     * @note $O(n + k)$\n     * @arg remove can be implemented as undo\n    \
    \ * @arg report is called with all indices in increasing order\n     */\n    template\
    \ <class Add, class Remove, class Report>\n    void traverse_segments(Add & add,\
    \ Remove & remove, Report & report) {\n        static_assert (std::is_invocable_r<void,\
    \ Add, const Key &>::value, \"\");\n        static_assert (std::is_invocable_r<void,\
    \ Remove, const Key &>::value, \"\");\n        static_assert (std::is_invocable_r<void,\
    \ Report, int>::value, \"\");\n        std::function<void (int, int, int)> dfs\
    \ = [&](int i, int l, int r) {\n            for (const auto & key : data[i]) {\n\
    \                add(key);\n            }\n            if (i >= size - 1) {\n\
    \                report(i - size + 1);\n            } else {\n               \
    \ dfs(2 * i + 1, l, (l + r) / 2);\n                dfs(2 * i + 2, (l + r) / 2,\
    \ r);\n            }\n            for (auto it = data[i].rbegin(); it != data[i].rend();\
    \ ++ it) {\n                remove(*it);\n            }\n        };\n        dfs(0,\
    \ 0, size);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <type_traits>\n#include <vector>\n#include \"utils/macros.hpp\"\n\n/**\n\
    \ * @brief Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \ (\u5217\u6319\u30AF\u30A8\u30EA, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @note This\
    \ tree is very similar to the Bentley's original segment tree.\n */\ntemplate\
    \ <class Key>\nstruct reporting_segment_tree {\n    int size;\n    std::vector<std::vector<Key>\
    \ > data;\n    reporting_segment_tree() = default;\n    explicit reporting_segment_tree(int\
    \ size_) {\n        size = 1; while (size < size_) size *= 2;\n        data.resize(2\
    \ * size - 1);\n    }\n\n    /**\n     * @arg key must be unique\n     * @note\
    \ $O(\\log n)$\n     */\n    void add_segment(int l, int r, const Key & key) {\n\
    \        assert (0 <= l and l <= r and r <= size);\n        for (l += size, r\
    \ += size; l < r; l /= 2, r /= 2) {  // 1-based\n            if (l % 2 == 1) data[(l\
    \ ++) - 1].push_back(key);\n            if (r % 2 == 1) data[(-- r) - 1].push_back(key);\n\
    \        }\n    }\n\n    /**\n     * @note $O(\\log n + k)$\n     */\n    template\
    \ <class Callback>\n    void list_segments(int i, Callback & callback) {\n   \
    \     static_assert (std::is_invocable_r<void, Callback, const Key &>::value,\
    \ \"\");\n        assert (0 <= i and i < size);\n        for (i += size; i > 0;\
    \ i /= 2) {  // 1-based\n            for (const auto & key : data[i - 1]) {\n\
    \                callback(key);\n            }\n        }\n    }\n\n    /**\n\
    \     * @note $O(n + k)$\n     * @arg remove can be implemented as undo\n    \
    \ * @arg report is called with all indices in increasing order\n     */\n    template\
    \ <class Add, class Remove, class Report>\n    void traverse_segments(Add & add,\
    \ Remove & remove, Report & report) {\n        static_assert (std::is_invocable_r<void,\
    \ Add, const Key &>::value, \"\");\n        static_assert (std::is_invocable_r<void,\
    \ Remove, const Key &>::value, \"\");\n        static_assert (std::is_invocable_r<void,\
    \ Report, int>::value, \"\");\n        std::function<void (int, int, int)> dfs\
    \ = [&](int i, int l, int r) {\n            for (const auto & key : data[i]) {\n\
    \                add(key);\n            }\n            if (i >= size - 1) {\n\
    \                report(i - size + 1);\n            } else {\n               \
    \ dfs(2 * i + 1, l, (l + r) / 2);\n                dfs(2 * i + 2, (l + r) / 2,\
    \ r);\n            }\n            for (auto it = data[i].rbegin(); it != data[i].rend();\
    \ ++ it) {\n                remove(*it);\n            }\n        };\n        dfs(0,\
    \ 0, size);\n    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: data_structure/reporting_segment_tree.hpp
  requiredBy:
  - data_structure/dynamic_connectivity_offline.hpp
  timestamp: '2020-03-08 03:44:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: data_structure/reporting_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/reporting_segment_tree.hpp
- /library/data_structure/reporting_segment_tree.hpp.html
title: "Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5217\
  \u6319\u30AF\u30A8\u30EA, \u5B8C\u5168\u4E8C\u5206\u6728)"
---
