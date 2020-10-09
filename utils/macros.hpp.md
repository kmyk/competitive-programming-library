---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_connectivity_offline.hpp
    title: Dynamic Connectivity (offline, commutative monoids)
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.hpp
    title: Euler Tour (subtree queries, with commutative monoids)
  - icon: ':heavy_check_mark:'
    path: data_structure/fully_indexable_dictionary.hpp
    title: "Fully Indexable Dictionary / \u5B8C\u5099\u8F9E\u66F8"
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.hpp
    title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: data_structure/li_chao_tree.hpp
    title: Li-Chao tree
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.hpp
    title: Link-Cut tree (monoids without commutativity, vertex set + path get)
  - icon: ':heavy_check_mark:'
    path: data_structure/reporting_segment_tree.hpp
    title: "Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5217\
      \u6319\u30AF\u30A8\u30EA, \u5B8C\u5168\u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
      \u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_beats.hpp
    title: "Segment Tree Beats (range {chmin, chmax, add, update} + range {min, max,\
      \ sum}, \u5B8C\u5168\u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: data_structure/sliding_window_aggregation.hpp
    title: "Sliding Window Aggregation / \u542B\u307E\u308C\u308B\u8981\u7D20\u306E\
      \u7DCF\u548C\u304C $O(1)$ \u3067\u53D6\u308C\u308B queue (\u53EF\u63DB\u3068\
      \u306F\u9650\u3089\u306A\u3044 monoid \u304C\u4E57\u308B)"
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table (idempotent monoid)
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: Wavelet Matrix
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: Bellman-Ford algorithm
  - icon: ':heavy_check_mark:'
    path: graph/cartesian_tree.hpp
    title: Cartesian tree ($O(n)$)
  - icon: ':warning:'
    path: graph/connected_components.hpp
    title: graph/connected_components.hpp
  - icon: ':warning:'
    path: graph/euler_graph.hpp
    title: "Eulerian cycle (\u7121\u5411, \u5FA9\u5143)"
  - icon: ':heavy_check_mark:'
    path: graph/format.hpp
    title: graph/format.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "minimum spanning tree / \u6700\u5C0F\u5168\u57DF\u6728 (Kruskal's method)"
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.hpp
    title: "lowest common ancestor / \u6700\u5C0F\u5171\u901A\u7956\u5148 (\u524D\u51E6\
      \u7406 $O(N)$ + $O(1)$, $\\pm 1$ RMQ and sparse table)"
  - icon: ':heavy_check_mark:'
    path: graph/quotient_graph.hpp
    title: graph/quotient_graph.hpp
  - icon: ':warning:'
    path: graph/shortest_path_faster_algorithm.hpp
    title: Shortest Path Faster Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "strongly connected components decomposition, Kosaraju's algorithm / \u5F37\
      \u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/topological_sort.hpp
    title: topological sort
  - icon: ':heavy_check_mark:'
    path: graph/transpose_graph.hpp
    title: graph/transpose_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_decomposition.hpp
    title: "\u6728\u5206\u89E3 (\u6728\u5E45 $t \\le 2$)"
  - icon: ':heavy_check_mark:'
    path: modulus/bell_number.hpp
    title: "the Bell number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':warning:'
    path: modulus/choose_simple.hpp
    title: "combination / \u7D44\u5408\u305B ${} _ n C _ r$ (\u611A\u76F4 $O(r)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/formal_power_series.hpp
    title: "formal power series / \u5F62\u5F0F\u7684\u7F83\u7D1A\u6570\u74B0 $\\mathbb{Z}/n\\\
      mathbb{Z}\\lbrack\\lbrack x\\rbrack\\rbrack$"
  - icon: ':warning:'
    path: modulus/garner.hpp
    title: Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: modulus/modlog.hpp
    title: "discrete log / \u96E2\u6563\u5BFE\u6570 (the baby-step giant-step, $O(\\\
      sqrt{m})$)"
  - icon: ':warning:'
    path: modulus/multichoose_simple.hpp
    title: "\u91CD\u8907\u7D44\u5408\u305B ${} _ n H _ r = {} _ {n + r - 1} C _ r$\
      \ (\u611A\u76F4 $O(r)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/number_theoretic_transformation.hpp
    title: Number Theoretic Transformation (NTT) for Proth primes
  - icon: ':heavy_check_mark:'
    path: modulus/number_theoretic_transformation_with_garner.hpp
    title: multiprecation on $\mathbb{Z}/n\mathbb{Z}[x]$
  - icon: ':heavy_check_mark:'
    path: modulus/partition_number.hpp
    title: "the partition number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/stirling_number_of_the_second_kind_convolution.hpp
    title: the Stirling number of the second kind (for given $N$, compute $S(N, \ast)$
      in $O(N \log N)$)
  - icon: ':heavy_check_mark:'
    path: modulus/stirling_number_of_the_second_kind_direct.hpp
    title: the Stirling number of the second kind ($O(K \log N)$)
  - icon: ':heavy_check_mark:'
    path: modulus/stirling_number_of_the_second_kind_table.hpp
    title: "the Stirling number of the second kind (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.hpp
    title: "twelvefold way / \u5199\u50CF12\u76F8"
  - icon: ':warning:'
    path: monoids/matrix_template.hpp
    title: monoids/matrix_template.hpp
  - icon: ':heavy_check_mark:'
    path: number/fast_fourier_transformation.hpp
    title: FFT convolution
  - icon: ':warning:'
    path: number/karatsuba.hpp
    title: Karatsuba method ($O(n^{\log_2 3})$)
  - icon: ':warning:'
    path: number/lagrange_interpolation.hpp
    title: Lagrange interpolation
  - icon: ':heavy_check_mark:'
    path: number/matrix_template.hpp
    title: number/matrix_template.hpp
  - icon: ':heavy_check_mark:'
    path: number/primes.hpp
    title: number/primes.hpp
  - icon: ':heavy_check_mark:'
    path: string/longest_common_prefix.hpp
    title: "Longest Common Prefix / \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E (\u63A5\
      \u5C3E\u8F9E\u914D\u5217, \u524D\u51E6\u7406 $O(N (\\log N)^2)$ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: "Suffix Array / \u63A5\u5C3E\u8F9E\u914D\u5217 ($O(N (\\log N)^2)$, Manber\
      \ & Myers)"
  - icon: ':warning:'
    path: utils/binary_search_float.hpp
    title: "a binary search on floating point numbers / \u4E8C\u5206\u63A2\u7D22 (\u6D6E\
      \u52D5\u5C0F\u6570\u70B9\u6570)"
  - icon: ':heavy_check_mark:'
    path: utils/coordinate_compression.hpp
    title: utils/coordinate_compression.hpp
  - icon: ':heavy_check_mark:'
    path: utils/dsu_on_tree.hpp
    title: DSU on tree (sack)
  - icon: ':warning:'
    path: utils/fast_zeta_transform.hpp
    title: upward fast zeta transform on primes
  - icon: ':heavy_check_mark:'
    path: utils/left_to_right_maxima.hpp
    title: "Length of Left-to-right Maxima (\u524D\u51E6\u7406 $O(n \\log n)$ + $O(1)$)"
  - icon: ':heavy_check_mark:'
    path: utils/two_satisfiability.hpp
    title: 2-SAT ($O(N)$)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/convex_hull_trick.line_add_get_min.test.cpp
    title: data_structure/convex_hull_trick.line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
    title: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
    title: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
    title: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/li_chao_tree.segment_add_get_min.test.cpp
    title: data_structure/li_chao_tree.segment_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.marked_ancestor.test.cpp
    title: data_structure/link_cut_tree.marked_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
    title: data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
    title: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.point_add_range_sum.test.cpp
    title: data_structure/segment_tree.point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.point_set_range_composite.test.cpp
    title: data_structure/segment_tree.point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.range_sum_query.test.cpp
    title: data_structure/segment_tree.range_sum_query.test.cpp
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
    path: data_structure/sliding_window_aggregation.yosupo.test.cpp
    title: data_structure/sliding_window_aggregation.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.yosupo.test.cpp
    title: data_structure/sparse_table.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.yukicoder-1036.test.cpp
    title: data_structure/sparse_table.yukicoder-1036.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.aoj2674.test.cpp
    title: data_structure/wavelet_matrix.aoj2674.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.range_kth_smallest.test.cpp
    title: data_structure/wavelet_matrix.range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.rectangle_sum.test.cpp
    title: data_structure/wavelet_matrix.rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.test.cpp
    title: graph/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/cartesian_tree.yosupo.test.cpp
    title: graph/cartesian_tree.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/cartesian_tree.yukicoder-1031.test.cpp
    title: graph/cartesian_tree.yukicoder-1031.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.yukicoder-1065.test.cpp
    title: graph/dijkstra.yukicoder-1065.test.cpp
  - icon: ':x:'
    path: graph/functional_graph.yuki1254.test.cpp
    title: graph/functional_graph.yuki1254.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.aoj.test.cpp
    title: graph/kruskal.aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.aoj.test.cpp
    title: graph/lowest_common_ancestor.aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.yosupo.test.cpp
    title: graph/lowest_common_ancestor.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.yosupo.test.cpp
    title: graph/strongly_connected_components.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_decomposition.aoj_2405.test.cpp
    title: graph/tree_decomposition.aoj_2405.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/yen_algorithm.yukicoder-1069.test.cpp
    title: graph/yen_algorithm.yukicoder-1069.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: modulus/modlog.yosupo.test.cpp
    title: modulus/modlog.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/modlog.yuki1255.test.cpp
    title: modulus/modlog.yuki1255.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_10.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_10.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_11.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_11.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_2.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_3.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_5.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_5.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_6.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_6.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_7.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_7.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_8.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_8.test.cpp
  - icon: ':heavy_check_mark:'
    path: modulus/twelvefold_way.balls_and_boxes_9.test.cpp
    title: modulus/twelvefold_way.balls_and_boxes_9.test.cpp
  - icon: ':heavy_check_mark:'
    path: number/fast_fourier_transformation.yukicoder-856.test.cpp
    title: number/fast_fourier_transformation.yukicoder-856.test.cpp
  - icon: ':heavy_check_mark:'
    path: number/matrix_template.yukicoder-1073.test.cpp
    title: number/matrix_template.yukicoder-1073.test.cpp
  - icon: ':heavy_check_mark:'
    path: number/primes.aoj.test.cpp
    title: number/primes.aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: number/primes.yukicoder-1140.test.cpp
    title: number/primes.yukicoder-1140.test.cpp
  - icon: ':heavy_check_mark:'
    path: old/rollback-square-decomposition.yukicoder-1031.test.cpp
    title: old/rollback-square-decomposition.yukicoder-1031.test.cpp
  - icon: ':heavy_check_mark:'
    path: string/longest_common_prefix.yosupo.test.cpp
    title: string/longest_common_prefix.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.yosupo.test.cpp
    title: string/suffix_array.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: utils/binary_search.aoj.test.cpp
    title: utils/binary_search.aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: utils/dsu_on_tree.aoj.test.cpp
    title: utils/dsu_on_tree.aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: utils/two_satisfiability.yosupo.test.cpp
    title: utils/two_satisfiability.yosupo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "utils/macros.hpp"

    #define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))

    #define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))

    #define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))

    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

    #define ALL(x) std::begin(x), std::end(x)

    '
  code: '#pragma once

    #define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))

    #define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))

    #define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))

    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

    #define ALL(x) std::begin(x), std::end(x)

    '
  dependsOn: []
  isVerificationFile: false
  path: utils/macros.hpp
  requiredBy:
  - string/longest_common_prefix.hpp
  - string/suffix_array.hpp
  - number/matrix_template.hpp
  - number/fast_fourier_transformation.hpp
  - number/karatsuba.hpp
  - number/primes.hpp
  - number/lagrange_interpolation.hpp
  - graph/format.hpp
  - graph/kruskal.hpp
  - graph/quotient_graph.hpp
  - graph/lowest_common_ancestor.hpp
  - graph/connected_components.hpp
  - graph/transpose_graph.hpp
  - graph/cartesian_tree.hpp
  - graph/shortest_path_faster_algorithm.hpp
  - graph/euler_graph.hpp
  - graph/topological_sort.hpp
  - graph/bellman_ford.hpp
  - graph/tree_decomposition.hpp
  - graph/strongly_connected_components.hpp
  - modulus/partition_number.hpp
  - modulus/stirling_number_of_the_second_kind_convolution.hpp
  - modulus/bell_number.hpp
  - modulus/number_theoretic_transformation_with_garner.hpp
  - modulus/stirling_number_of_the_second_kind_direct.hpp
  - modulus/twelvefold_way.hpp
  - modulus/number_theoretic_transformation.hpp
  - modulus/modlog.hpp
  - modulus/choose_simple.hpp
  - modulus/stirling_number_of_the_second_kind_table.hpp
  - modulus/multichoose_simple.hpp
  - modulus/formal_power_series.hpp
  - modulus/garner.hpp
  - monoids/matrix_template.hpp
  - utils/left_to_right_maxima.hpp
  - utils/two_satisfiability.hpp
  - utils/binary_search_float.hpp
  - utils/fast_zeta_transform.hpp
  - utils/coordinate_compression.hpp
  - utils/dsu_on_tree.hpp
  - data_structure/fully_indexable_dictionary.hpp
  - data_structure/sliding_window_aggregation.hpp
  - data_structure/reporting_segment_tree.hpp
  - data_structure/euler_tour_subtree_query.hpp
  - data_structure/li_chao_tree.hpp
  - data_structure/sparse_table.hpp
  - data_structure/link_cut_tree.hpp
  - data_structure/segment_tree.hpp
  - data_structure/dynamic_connectivity_offline.hpp
  - data_structure/wavelet_matrix.hpp
  - data_structure/segment_tree_beats.hpp
  - data_structure/lazy_propagation_segment_tree.hpp
  timestamp: '2019-12-20 06:12:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - string/suffix_array.yosupo.test.cpp
  - string/longest_common_prefix.yosupo.test.cpp
  - number/primes.yukicoder-1140.test.cpp
  - number/matrix_template.yukicoder-1073.test.cpp
  - number/primes.aoj.test.cpp
  - number/fast_fourier_transformation.yukicoder-856.test.cpp
  - graph/lowest_common_ancestor.yosupo.test.cpp
  - graph/cartesian_tree.yosupo.test.cpp
  - graph/strongly_connected_components.yosupo.test.cpp
  - graph/bellman_ford.test.cpp
  - graph/tree_decomposition.aoj_2405.test.cpp
  - graph/functional_graph.yuki1254.test.cpp
  - graph/lowest_common_ancestor.aoj.test.cpp
  - graph/kruskal.aoj.test.cpp
  - graph/dijkstra.yukicoder-1065.test.cpp
  - graph/cartesian_tree.yukicoder-1031.test.cpp
  - graph/yen_algorithm.yukicoder-1069.test.cpp
  - modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_8.test.cpp
  - modulus/modlog.yosupo.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_11.test.cpp
  - modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp
  - modulus/formal_power_series.exp.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_6.test.cpp
  - modulus/formal_power_series.log.test.cpp
  - modulus/modlog.yuki1255.test.cpp
  - modulus/formal_power_series.yukicoder-1145.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_7.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_4.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_3.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_10.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_2.test.cpp
  - modulus/choose.yukicoder-1035.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_5.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_1.test.cpp
  - modulus/number_theoretic_transformation.yosupo.test.cpp
  - modulus/twelvefold_way.balls_and_boxes_9.test.cpp
  - modulus/formal_power_series.inv.test.cpp
  - utils/dsu_on_tree.aoj.test.cpp
  - utils/two_satisfiability.yosupo.test.cpp
  - utils/binary_search.aoj.test.cpp
  - old/rollback-square-decomposition.yukicoder-1031.test.cpp
  - data_structure/sliding_window_aggregation.yosupo.test.cpp
  - data_structure/segment_tree_beats.DSL_2_I.test.cpp
  - data_structure/segment_tree_beats.DSL_2_F.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  - data_structure/li_chao_tree.segment_add_get_min.test.cpp
  - data_structure/link_cut_tree.vertex_set_path_composite.test.cpp
  - data_structure/wavelet_matrix.aoj2674.test.cpp
  - data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
  - data_structure/wavelet_matrix.rectangle_sum.test.cpp
  - data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  - data_structure/link_cut_tree.vertex_add_path_sum.test.cpp
  - data_structure/wavelet_matrix.range_kth_smallest.test.cpp
  - data_structure/segment_tree_beats.DSL_2_H.test.cpp
  - data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp
  - data_structure/sparse_table.yosupo.test.cpp
  - data_structure/sparse_table.yukicoder-1036.test.cpp
  - data_structure/convex_hull_trick.line_add_get_min.test.cpp
  - data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp
  - data_structure/segment_tree.point_set_range_composite.test.cpp
  - data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
  - data_structure/segment_tree_beats.DSL_2_G.test.cpp
  - data_structure/segment_tree_beats.yosupo.test.cpp
  - data_structure/segment_tree.range_sum_query.test.cpp
  - data_structure/link_cut_tree.marked_ancestor.test.cpp
  - data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
  - data_structure/segment_tree.point_add_range_sum.test.cpp
documentation_of: utils/macros.hpp
layout: document
redirect_from:
- /library/utils/macros.hpp
- /library/utils/macros.hpp.html
title: utils/macros.hpp
---
