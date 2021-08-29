---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: modulus/bell_number.hpp
    title: "the Bell number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':question:'
    path: modulus/choose.hpp
    title: "combination / \u7D44\u5408\u305B ${} _ n C _ r$ (\u524D\u51E6\u7406 $O(n)$\
      \ + $O(1)$)"
  - icon: ':x:'
    path: modulus/choose_simple.hpp
    title: "combination / \u7D44\u5408\u305B ${} _ n C _ r$ (\u611A\u76F4 $O(r)$)"
  - icon: ':question:'
    path: modulus/factorial.hpp
    title: modulus/factorial.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/formal_power_series.hpp
    title: "formal power series / \u5F62\u5F0F\u7684\u7F83\u7D1A\u6570\u74B0 $\\mathbb{Z}/n\\\
      mathbb{Z}\\lbrack\\lbrack x\\rbrack\\rbrack$"
  - icon: ':warning:'
    path: modulus/garner.hpp
    title: Garner's algorithm
  - icon: ':question:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':x:'
    path: modulus/mint_with_zero.hpp
    title: "$\\mathbb{Z}$ \u306E\u4E57\u9664\u7B97\u3092 $\\mathbb{Z}/n\\mathbb{Z}$\
      \ \u306E\u4E0A\u3067\u3084\u308B\u30C7\u30FC\u30BF\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: modulus/modlog.hpp
    title: "discrete log / \u96E2\u6563\u5BFE\u6570 (the baby-step giant-step, $O(\\\
      sqrt{m})$)"
  - icon: ':heavy_check_mark:'
    path: modulus/modsqrt.hpp
    title: find the sqrt $b$ of $a$ modulo $p$
  - icon: ':question:'
    path: modulus/multichoose.hpp
    title: "\u91CD\u8907\u7D44\u5408\u305B ${} _ n H _ r = {} _ {n + r - 1} C _ r$\
      \ (\u524D\u51E6\u7406 $O(n)$ + $O(1)$)"
  - icon: ':x:'
    path: modulus/multichoose_simple.hpp
    title: "\u91CD\u8907\u7D44\u5408\u305B ${} _ n H _ r = {} _ {n + r - 1} C _ r$\
      \ (\u611A\u76F4 $O(r)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/number_theoretic_transformation.hpp
    title: Number Theoretic Transformation (NTT) for Proth primes
  - icon: ':heavy_check_mark:'
    path: modulus/number_theoretic_transformation_with_garner.hpp
    title: multiprecation on $\mathbb{Z}/n\mathbb{Z}[x]$
  - icon: ':question:'
    path: modulus/partition_number.hpp
    title: "the partition number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':question:'
    path: modulus/permute.hpp
    title: "permutation / \u9806\u5217 ${} _ n P _ r$ (\u524D\u51E6\u7406 $O(n)$ +\
      \ $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/stirling_number_of_the_second_kind_convolution.hpp
    title: the Stirling number of the second kind (for given $N$, compute $S(N, \ast)$
      in $O(N \log N)$)
  - icon: ':question:'
    path: modulus/stirling_number_of_the_second_kind_direct.hpp
    title: the Stirling number of the second kind ($O(K \log N)$)
  - icon: ':question:'
    path: modulus/stirling_number_of_the_second_kind_table.hpp
    title: "the Stirling number of the second kind (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':question:'
    path: modulus/twelvefold_way.hpp
    title: "twelvefold way / \u5199\u50CF12\u76F8"
  - icon: ':warning:'
    path: number/miller-rabin.hpp
    title: miller-rabin primality test
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.point_set_range_composite.test.cpp
    title: data_structure/segment_tree.point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sliding_window_aggregation.yosupo.test.cpp
    title: data_structure/sliding_window_aggregation.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_decomposition.aoj_2405.test.cpp
    title: graph/tree_decomposition.aoj_2405.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/choose.yukicoder-1035.test.cpp
    title: modulus/choose.yukicoder-1035.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/formal_power_series.exp.test.cpp
    title: modulus/formal_power_series.exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/formal_power_series.inv.test.cpp
    title: modulus/formal_power_series.inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/formal_power_series.log.test.cpp
    title: modulus/formal_power_series.log.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/formal_power_series.yukicoder-1145.test.cpp
    title: modulus/formal_power_series.yukicoder-1145.test.cpp
  - icon: ':x:'
    path: modulus/mint_with_zero.test.cpp
    title: modulus/mint_with_zero.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/modlog.yosupo.test.cpp
    title: modulus/modlog.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/modlog.yuki1255.test.cpp
    title: modulus/modlog.yuki1255.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/modsqrt.yosupo.test.cpp
    title: modulus/modsqrt.yosupo.test.cpp
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
    path: modulus/twelvefold_way.balls_and_boxes_1.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_1.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_10.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_10.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_11.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_11.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_2.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_2.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_3.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_3.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_5.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_5.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_6.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_6.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_7.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_7.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_8.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_8.test.cpp
  - icon: ':x:'
    path: modulus/twelvefold_way.balls_and_boxes_9.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_9.test.cpp
  - icon: ':x:'
    path: number/fast_fourier_transformation.yukicoder-856.test.cpp
    title: number/fast_fourier_transformation.yukicoder-856.test.cpp
  - icon: ':x:'
    path: number/matrix.yukicoder-1073.test.cpp
    title: number/matrix.yukicoder-1073.test.cpp
  - icon: ':x:'
    path: number/matrix_template.yukicoder-1073.test.cpp
    title: number/matrix_template.yukicoder-1073.test.cpp
  - icon: ':x:'
    path: number/primes_extra.yukicoder-1659.test.cpp
    title: number/primes_extra.yukicoder-1659.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulus/modpow.hpp\"\n#include <cassert>\n#include <cstdint>\n\
    \ninline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {\n    assert\
    \ (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n    uint_fast64_t y = 1;\n    for\
    \ (; k; k >>= 1) {\n        if (k & 1) (y *= x) %= MOD;\n        (x *= x) %= MOD;\n\
    \    }\n    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);\n    return y;\n\
    }\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n\ninline int32_t modpow(uint_fast64_t\
    \ x, uint64_t k, int32_t MOD) {\n    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n\
    \    uint_fast64_t y = 1;\n    for (; k; k >>= 1) {\n        if (k & 1) (y *=\
    \ x) %= MOD;\n        (x *= x) %= MOD;\n    }\n    assert (/* 0 <= y and */ y\
    \ < (uint_fast64_t)MOD);\n    return y;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: modulus/modpow.hpp
  requiredBy:
  - modulus/permute.hpp
  - modulus/bell_number.hpp
  - modulus/garner.hpp
  - modulus/partition_number.hpp
  - modulus/twelvefold_way.hpp
  - modulus/stirling_number_of_the_second_kind_table.hpp
  - modulus/multichoose.hpp
  - modulus/number_theoretic_transformation.hpp
  - modulus/formal_power_series.hpp
  - modulus/stirling_number_of_the_second_kind_direct.hpp
  - modulus/choose.hpp
  - modulus/factorial.hpp
  - modulus/choose_simple.hpp
  - modulus/modsqrt.hpp
  - modulus/mint.hpp
  - modulus/mint_with_zero.hpp
  - modulus/multichoose_simple.hpp
  - modulus/number_theoretic_transformation_with_garner.hpp
  - modulus/stirling_number_of_the_second_kind_convolution.hpp
  - modulus/modlog.hpp
  - number/miller-rabin.hpp
  timestamp: '2020-06-16 07:51:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - modulus/modlog.yosupo.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_3.test.cpp
  - modulus/modsqrt.yosupo.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_2.test.cpp
  - modulus/choose.yukicoder-1035.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_11.test.cpp
  - modulus/formal_power_series.inv.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_7.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_10.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_4.test.cpp
  - modulus/formal_power_series.exp.test.cpp
  - modulus/formal_power_series.yukicoder-1145.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_1.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_8.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_6.test.cpp
  - modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp
  - modulus/mint_with_zero.test.cpp
  - modulus/number_theoretic_transformation.yosupo.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_9.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_5.test.cpp
  - modulus/formal_power_series.log.test.cpp
  - modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp
  - modulus/modlog.yuki1255.test.cpp
  - graph/tree_decomposition.aoj_2405.test.cpp
  - number/matrix_template.yukicoder-1073.test.cpp
  - number/fast_fourier_transformation.yukicoder-856.test.cpp
  - number/primes_extra.yukicoder-1659.test.cpp
  - number/matrix.yukicoder-1073.test.cpp
  - data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  - data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - data_structure/sliding_window_aggregation.yosupo.test.cpp
  - data_structure/segment_tree.point_set_range_composite.test.cpp
  - data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
documentation_of: modulus/modpow.hpp
layout: document
redirect_from:
- /library/modulus/modpow.hpp
- /library/modulus/modpow.hpp.html
title: modulus/modpow.hpp
---
