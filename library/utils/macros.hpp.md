---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :question: utils/macros.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/macros.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00




## Required by

* :heavy_check_mark: <a href="../data_structure/dynamic_connectivity_offline.hpp.html">Dynamic Connectivity (offline, commutative monoids) <small>(data_structure/dynamic_connectivity_offline.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/euler_tour_subtree_query.hpp.html">Euler Tour (subtree queries, with commutative monoids) <small>(data_structure/euler_tour_subtree_query.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/fully_indexable_dictionary.hpp.html">Fully Indexable Dictionary / 完備辞書 <small>(data_structure/fully_indexable_dictionary.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/lazy_propagation_segment_tree.hpp.html">Lazy Propagation Segment Tree / 遅延伝播セグメント木 (monoids, 完全二分木) <small>(data_structure/lazy_propagation_segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/li_chao_tree.hpp.html">Li-Chao tree <small>(data_structure/li_chao_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/link_cut_tree.hpp.html">Link-Cut tree (monoids without commutativity, vertex set + path get) <small>(data_structure/link_cut_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/reporting_segment_tree.hpp.html">Dual Segment Tree / 双対セグメント木 (列挙クエリ, 完全二分木) <small>(data_structure/reporting_segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/segment_tree.hpp.html">Segment Tree / セグメント木 (monoids, 完全二分木) <small>(data_structure/segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/segment_tree_beats.hpp.html">Segment Tree Beats (range {chmin, chmax, add, update} + range {min, max, sum}, 完全二分木) <small>(data_structure/segment_tree_beats.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/sliding_window_aggregation.hpp.html">Sliding Window Aggregation / 含まれる要素の総和が $O(1)$ で取れる queue (可換とは限らない monoid が乗る) <small>(data_structure/sliding_window_aggregation.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/sparse_table.hpp.html">Sparse Table (idempotent monoid) <small>(data_structure/sparse_table.hpp)</small></a>
* :heavy_check_mark: <a href="../data_structure/wavelet_matrix.hpp.html">Wavelet Matrix <small>(data_structure/wavelet_matrix.hpp)</small></a>
* :heavy_check_mark: <a href="../graph/bellman_ford.hpp.html">Bellman-Ford algorithm <small>(graph/bellman_ford.hpp)</small></a>
* :heavy_check_mark: <a href="../graph/kruskal.hpp.html">minimum spanning tree / 最小全域木 (Kruskal's method) <small>(graph/kruskal.hpp)</small></a>
* :heavy_check_mark: <a href="../graph/lowest_common_ancestor.hpp.html">lowest common ancestor / 最小共通祖先 (前処理 $O(N)$ + $O(1)$, $\pm 1$ RMQ and sparse table) <small>(graph/lowest_common_ancestor.hpp)</small></a>
* :heavy_check_mark: <a href="../graph/quotient_graph.hpp.html">graph/quotient_graph.hpp</a>
* :warning: <a href="../graph/shortest_path_faster_algorithm.hpp.html">Shortest Path Faster Algorithm <small>(graph/shortest_path_faster_algorithm.hpp)</small></a>
* :heavy_check_mark: <a href="../graph/strongly_connected_components.hpp.html">strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解 <small>(graph/strongly_connected_components.hpp)</small></a>
* :heavy_check_mark: <a href="../graph/topological_sort.hpp.html">topological sort <small>(graph/topological_sort.hpp)</small></a>
* :heavy_check_mark: <a href="../graph/transpose_graph.hpp.html">graph/transpose_graph.hpp</a>
* :heavy_check_mark: <a href="../graph/tree_decomposition.hpp.html">木分解 (木幅 $t \le 2$) <small>(graph/tree_decomposition.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/bell_number.hpp.html">the Bell number (前処理 $O(NK)$ + $O(1)$) <small>(modulus/bell_number.hpp)</small></a>
* :warning: <a href="../modulus/choose_simple.hpp.html">combination / 組合せ ${} _ n C _ r$ (愚直 $O(r)$) <small>(modulus/choose_simple.hpp)</small></a>
* :question: <a href="../modulus/formal_power_series.hpp.html">formal power series / 形式的羃級数環 $\mathbb{Z}/n\mathbb{Z}\lbrack\lbrack x\rbrack\rbrack$ <small>(modulus/formal_power_series.hpp)</small></a>
* :warning: <a href="../modulus/garner.hpp.html">Garner's algorithm <small>(modulus/garner.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/modlog.hpp.html">discrete log / 離散対数 (the baby-step giant-step, $O(\sqrt{m})$) <small>(modulus/modlog.hpp)</small></a>
* :warning: <a href="../modulus/multichoose_simple.hpp.html">重複組合せ ${} _ n H _ r = {} _ {n + r - 1} C _ r$ (愚直 $O(r)$) <small>(modulus/multichoose_simple.hpp)</small></a>
* :question: <a href="../modulus/number_theoretic_transformation.hpp.html">Number Theoretic Transformation (NTT) for Proth primes <small>(modulus/number_theoretic_transformation.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/number_theoretic_transformation_with_garner.hpp.html">multiprecation on $\mathbb{Z}/n\mathbb{Z}\[x\]$ <small>(modulus/number_theoretic_transformation_with_garner.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/partition_number.hpp.html">the partition number (前処理 $O(NK)$ + $O(1)$) <small>(modulus/partition_number.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/stirling_number_of_the_second_kind_convolution.hpp.html">the Stirling number of the second kind (for given $N$, compute $S(N, \ast)$ in $O(N \log N)$) <small>(modulus/stirling_number_of_the_second_kind_convolution.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/stirling_number_of_the_second_kind_direct.hpp.html">the Stirling number of the second kind ($O(K \log N)$) <small>(modulus/stirling_number_of_the_second_kind_direct.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/stirling_number_of_the_second_kind_table.hpp.html">the Stirling number of the second kind (前処理 $O(NK)$ + $O(1)$) <small>(modulus/stirling_number_of_the_second_kind_table.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/twelvefold_way.hpp.html">twelvefold way / 写像12相 <small>(modulus/twelvefold_way.hpp)</small></a>
* :warning: <a href="../monoids/matrix_template.hpp.html">monoids/matrix_template.hpp</a>
* :warning: <a href="../number/fast_fourier_transformation.hpp.html">the convolution <small>(number/fast_fourier_transformation.hpp)</small></a>
* :warning: <a href="../number/lagrange_interpolation.hpp.html">Lagrange interpolation <small>(number/lagrange_interpolation.hpp)</small></a>
* :warning: <a href="../number/matrix_template.hpp.html">number/matrix_template.hpp</a>
* :heavy_check_mark: <a href="../number/primes.hpp.html">number/primes.hpp</a>
* :heavy_check_mark: <a href="../string/longest_common_prefix.hpp.html">Longest Common Prefix / 最長共通接頭辞 (接尾辞配列, 前処理 $O(N (\log N)^2)$ + $O(1)$) <small>(string/longest_common_prefix.hpp)</small></a>
* :heavy_check_mark: <a href="../string/suffix_array.hpp.html">Suffix Array / 接尾辞配列 ($O(N (\log N)^2)$, Manber & Myers) <small>(string/suffix_array.hpp)</small></a>
* :heavy_check_mark: <a href="coordinate_compression.hpp.html">utils/coordinate_compression.hpp</a>
* :heavy_check_mark: <a href="dsu_on_tree.hpp.html">DSU on tree (sack) <small>(utils/dsu_on_tree.hpp)</small></a>
* :warning: <a href="fast_zeta_transform.hpp.html">upward fast zeta transform on primes <small>(utils/fast_zeta_transform.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/convex_hull_trick.line_add_get_min.test.cpp.html">data_structure/convex_hull_trick.line_add_get_min.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp.html">data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp.html">data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp.html">data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/li_chao_tree.segment_add_get_min.test.cpp.html">data_structure/li_chao_tree.segment_add_get_min.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp.html">data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.marked_ancestor.test.cpp.html">data_structure/link_cut_tree.marked_ancestor.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.vertex_add_path_sum.test.cpp.html">data_structure/link_cut_tree.vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.vertex_set_path_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_add_range_sum.test.cpp.html">data_structure/segment_tree.point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html">data_structure/segment_tree.point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.range_sum_query.test.cpp.html">data_structure/segment_tree.range_sum_query.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.DSL_2_F.test.cpp.html">data_structure/segment_tree_beats.DSL_2_F.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.DSL_2_G.test.cpp.html">data_structure/segment_tree_beats.DSL_2_G.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.DSL_2_H.test.cpp.html">data_structure/segment_tree_beats.DSL_2_H.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.DSL_2_I.test.cpp.html">data_structure/segment_tree_beats.DSL_2_I.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.yosupo.test.cpp.html">data_structure/segment_tree_beats.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sliding_window_aggregation.yosupo.test.cpp.html">data_structure/sliding_window_aggregation.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sparse_table.yosupo.test.cpp.html">data_structure/sparse_table.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sparse_table.yukicoder-1036.test.cpp.html">data_structure/sparse_table.yukicoder-1036.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/wavelet_matrix.aoj2674.test.cpp.html">data_structure/wavelet_matrix.aoj2674.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/wavelet_matrix.range_kth_smallest.test.cpp.html">data_structure/wavelet_matrix.range_kth_smallest.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/wavelet_matrix.rectangle_sum.test.cpp.html">data_structure/wavelet_matrix.rectangle_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/bellman_ford.test.cpp.html">graph/bellman_ford.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/kruskal.aoj.test.cpp.html">graph/kruskal.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/lowest_common_ancestor.aoj.test.cpp.html">graph/lowest_common_ancestor.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/lowest_common_ancestor.yosupo.test.cpp.html">graph/lowest_common_ancestor.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/strongly_connected_components.yosupo.test.cpp.html">graph/strongly_connected_components.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/tree_decomposition.aoj_2405.test.cpp.html">graph/tree_decomposition.aoj_2405.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/choose.yukicoder-1035.test.cpp.html">modulus/choose.yukicoder-1035.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.exp.test.cpp.html">modulus/formal_power_series.exp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.inv.test.cpp.html">modulus/formal_power_series.inv.test.cpp</a>
* :x: <a href="../../verify/modulus/formal_power_series.log.test.cpp.html">modulus/formal_power_series.log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/modlog.yosupo.test.cpp.html">modulus/modlog.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/number_theoretic_transformation.yosupo.test.cpp.html">modulus/number_theoretic_transformation.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp.html">modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp.html">modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_1.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_1.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_10.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_10.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_11.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_11.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_2.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_2.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_3.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_3.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_4.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_4.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_5.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_5.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_6.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_6.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_7.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_7.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_8.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_8.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_9.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_9.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/primes.aoj.test.cpp.html">number/primes.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/old/rollback-square-decomposition.yukicoder-1031.test.cpp.html">old/rollback-square-decomposition.yukicoder-1031.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/string/longest_common_prefix.yosupo.test.cpp.html">string/longest_common_prefix.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/string/suffix_array.yosupo.test.cpp.html">string/suffix_array.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/utils/binary_search.aoj.test.cpp.html">utils/binary_search.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/utils/dsu_on_tree.aoj.test.cpp.html">utils/dsu_on_tree.aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

