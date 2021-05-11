---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
    title: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
    title: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_beats.DSL_2_F.test.cpp
    title: data_structure/segment_tree_beats.DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_beats.DSL_2_G.test.cpp
    title: data_structure/segment_tree_beats.DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_beats.DSL_2_H.test.cpp
    title: data_structure/segment_tree_beats.DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_beats.DSL_2_I.test.cpp
    title: data_structure/segment_tree_beats.DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_beats.yosupo.test.cpp
    title: data_structure/segment_tree_beats.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.range_kth_smallest.test.cpp
    title: data_structure/wavelet_matrix.range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: hack/fastio.yosupo.test.cpp
    title: hack/fastio.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/number_theoretic_transformation.yosupo.test.cpp
    title: modulus/number_theoretic_transformation.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp
    title: modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp
    title: modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: string/longest_common_prefix.yosupo.test.cpp
    title: string/longest_common_prefix.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.yosupo.test.cpp
    title: string/suffix_array.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: utils/two_satisfiability.yosupo.test.cpp
    title: utils/two_satisfiability.yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"hack/fastio.hpp\"\n#include <cstdint>\n#include <cstdio>\n\
    #include <string>\n#include <type_traits>\n\ntemplate <class Char, std::enable_if_t<std::is_same_v<Char,\
    \ char>, int> = 0>\ninline Char in() { return getchar_unlocked(); }\ntemplate\
    \ <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> =\
    \ 0>\ninline std::string in() {\n    char c; do { c = getchar_unlocked(); } while\
    \ (isspace(c));\n    std::string s;\n    do { s.push_back(c); } while (not isspace(c\
    \ = getchar_unlocked()));\n    return s;\n}\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>\
    \ and not std::is_same_v<Integer, char>, int> = 0>\ninline Integer in() {\n  \
    \  char c; do { c = getchar_unlocked(); } while (isspace(c));\n    if (std::is_signed<Integer>::value\
    \ and c == '-') return -in<Integer>();\n    Integer n = 0;\n    do { n = n * 10\
    \ + c - '0'; } while (not isspace(c = getchar_unlocked()));\n    return n;\n}\n\
    \ntemplate <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\n\
    inline void out(char c) { putchar_unlocked(c); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline void out(const std::string & s) { for (char\
    \ c : s) putchar_unlocked(c); }\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>,\
    \ int> = 0>\ninline void out(Integer n) {\n    char s[20];\n    int i = 0;\n \
    \   if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *=\
    \ -1; }\n    do { s[i ++] = n % 10; n /= 10; } while (n);\n    while (i) putchar_unlocked(s[--\
    \ i] + '0');\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <cstdio>\n#include <string>\n\
    #include <type_traits>\n\ntemplate <class Char, std::enable_if_t<std::is_same_v<Char,\
    \ char>, int> = 0>\ninline Char in() { return getchar_unlocked(); }\ntemplate\
    \ <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> =\
    \ 0>\ninline std::string in() {\n    char c; do { c = getchar_unlocked(); } while\
    \ (isspace(c));\n    std::string s;\n    do { s.push_back(c); } while (not isspace(c\
    \ = getchar_unlocked()));\n    return s;\n}\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>\
    \ and not std::is_same_v<Integer, char>, int> = 0>\ninline Integer in() {\n  \
    \  char c; do { c = getchar_unlocked(); } while (isspace(c));\n    if (std::is_signed<Integer>::value\
    \ and c == '-') return -in<Integer>();\n    Integer n = 0;\n    do { n = n * 10\
    \ + c - '0'; } while (not isspace(c = getchar_unlocked()));\n    return n;\n}\n\
    \ntemplate <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\n\
    inline void out(char c) { putchar_unlocked(c); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline void out(const std::string & s) { for (char\
    \ c : s) putchar_unlocked(c); }\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>,\
    \ int> = 0>\ninline void out(Integer n) {\n    char s[20];\n    int i = 0;\n \
    \   if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *=\
    \ -1; }\n    do { s[i ++] = n % 10; n /= 10; } while (n);\n    while (i) putchar_unlocked(s[--\
    \ i] + '0');\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: hack/fastio.hpp
  requiredBy: []
  timestamp: '2020-06-13 00:00:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - string/longest_common_prefix.yosupo.test.cpp
  - string/suffix_array.yosupo.test.cpp
  - utils/two_satisfiability.yosupo.test.cpp
  - hack/fastio.yosupo.test.cpp
  - data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - data_structure/segment_tree_beats.DSL_2_F.test.cpp
  - data_structure/segment_tree_beats.DSL_2_I.test.cpp
  - data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - data_structure/wavelet_matrix.range_kth_smallest.test.cpp
  - data_structure/segment_tree_beats.yosupo.test.cpp
  - data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  - data_structure/segment_tree_beats.DSL_2_H.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
  - data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - data_structure/segment_tree_beats.DSL_2_G.test.cpp
  - modulus/number_theoretic_transformation.yosupo.test.cpp
  - modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp
  - modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp
documentation_of: hack/fastio.hpp
layout: document
redirect_from:
- /library/hack/fastio.hpp
- /library/hack/fastio.hpp.html
title: hack/fastio.hpp
---
