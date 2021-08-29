---
data:
  libraryCategories:
  - name: data_structure
    pages:
    - icon: ':heavy_check_mark:'
      path: data_structure/binary_indexed_tree.hpp
      title: Binary Indexed Tree
    - icon: ':heavy_check_mark:'
      path: data_structure/convex_hull_trick.hpp
      title: "Convex Hull Trick (\u975E\u5358\u8ABF, online)"
    - icon: ':heavy_check_mark:'
      path: data_structure/dual_segment_tree.hpp
      title: "Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
        \ (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)"
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
      path: data_structure/lazy_propagation_red_black_tree.hpp
      title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\
        \u30E1\u30F3\u30C8\u6728 (monoids, \u8D64\u9ED2\u6728)"
    - icon: ':heavy_check_mark:'
      path: data_structure/lazy_propagation_segment_tree.hpp
      title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\
        \u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)"
    - icon: ':heavy_check_mark:'
      path: data_structure/li_chao_tree.hpp
      title: Li-Chao tree
    - icon: ':heavy_check_mark:'
      path: data_structure/link_cut_tree.hpp
      title: Link-Cut tree (monoids without commutativity, vertex set + path get)
    - icon: ':heavy_check_mark:'
      path: data_structure/reporting_segment_tree.hpp
      title: "Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
        \ (\u5217\u6319\u30AF\u30A8\u30EA, \u5B8C\u5168\u4E8C\u5206\u6728)"
    - icon: ':heavy_check_mark:'
      path: data_structure/segment_tree.hpp
      title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\
        \u5168\u4E8C\u5206\u6728)"
    - icon: ':heavy_check_mark:'
      path: data_structure/segment_tree_beats.hpp
      title: "Segment Tree Beats (range {chmin, chmax, add, update} + range {min,\
        \ max, sum}, \u5B8C\u5168\u4E8C\u5206\u6728)"
    - icon: ':heavy_check_mark:'
      path: data_structure/sliding_window_aggregation.hpp
      title: "Sliding Window Aggregation / \u542B\u307E\u308C\u308B\u8981\u7D20\u306E\
        \u7DCF\u548C\u304C $O(1)$ \u3067\u53D6\u308C\u308B queue (\u53EF\u63DB\u3068\
        \u306F\u9650\u3089\u306A\u3044 monoid \u304C\u4E57\u308B)"
    - icon: ':heavy_check_mark:'
      path: data_structure/sparse_table.hpp
      title: Sparse Table (idempotent monoid)
    - icon: ':heavy_check_mark:'
      path: data_structure/union_find_tree.hpp
      title: Union-Find Tree
    - icon: ':heavy_check_mark:'
      path: data_structure/union_find_tree_foldable_undoable.hpp
      title: Union-Find Tree (foldable with commutative monoids, undoable)
    - icon: ':heavy_check_mark:'
      path: data_structure/union_find_tree_with_monoid.hpp
      title: a disjoint set structure with monoid
    - icon: ':heavy_check_mark:'
      path: data_structure/wavelet_matrix.hpp
      title: Wavelet Matrix
  - name: graph
    pages:
    - icon: ':heavy_check_mark:'
      path: graph/bellman_ford.hpp
      title: Bellman-Ford algorithm
    - icon: ':heavy_check_mark:'
      path: graph/cartesian_tree.hpp
      title: Cartesian tree ($O(n)$)
    - icon: ':warning:'
      path: graph/catapillar_graph.hpp
      title: get a central path of a catapillar graph
    - icon: ':warning:'
      path: graph/connected_components.hpp
      title: graph/connected_components.hpp
    - icon: ':warning:'
      path: graph/diameter_of_tree.hpp
      title: "get the diameter of a tree / \u6728\u306E\u76F4\u5F84"
    - icon: ':heavy_check_mark:'
      path: graph/dijkstra.hpp
      title: Dijkstra ($O((E + V) \log V)$)
    - icon: ':warning:'
      path: graph/dinic.hpp
      title: "maximum flow / \u6700\u5927\u6D41 (Dinic)"
    - icon: ':warning:'
      path: graph/euler_graph.hpp
      title: "Eulerian cycle (\u7121\u5411, \u5FA9\u5143)"
    - icon: ':heavy_check_mark:'
      path: graph/euler_tour_preorder.hpp
      title: Euler Tour (preorder)
    - icon: ':heavy_check_mark:'
      path: graph/format.hpp
      title: graph/format.hpp
    - icon: ':heavy_check_mark:'
      path: graph/functional_graph.hpp
      title: "Namori cycle / \u306A\u3082\u308A\u9589\u8DEF"
    - icon: ':warning:'
      path: graph/is_connected_graph.hpp
      title: graph/is_connected_graph.hpp
    - icon: ':warning:'
      path: graph/is_simple_graph.hpp
      title: graph/is_simple_graph.hpp
    - icon: ':heavy_check_mark:'
      path: graph/kruskal.hpp
      title: "minimum spanning tree / \u6700\u5C0F\u5168\u57DF\u6728 (Kruskal's method)"
    - icon: ':heavy_check_mark:'
      path: graph/lowest_common_ancestor.hpp
      title: "lowest common ancestor / \u6700\u5C0F\u5171\u901A\u7956\u5148 (\u524D\
        \u51E6\u7406 $O(N)$ + $O(1)$, $\\pm 1$ RMQ and sparse table)"
    - icon: ':warning:'
      path: graph/matrix_tree_theorem.hpp
      title: "\u5168\u57DF\u6728\u306E\u500B\u6570\u3092\u6570\u3048\u308B (\u884C\
        \u5217\u6728\u5B9A\u7406)"
    - icon: ':warning:'
      path: graph/minimum-cost-flow.hpp
      title: "minimum cost flow / \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual)"
    - icon: ':heavy_check_mark:'
      path: graph/quotient_graph.hpp
      title: graph/quotient_graph.hpp
    - icon: ':warning:'
      path: graph/shortest_path_faster_algorithm.hpp
      title: Shortest Path Faster Algorithm
    - icon: ':heavy_check_mark:'
      path: graph/strongly_connected_components.hpp
      title: "strongly connected components decomposition, Kosaraju's algorithm /\
        \ \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    - icon: ':heavy_check_mark:'
      path: graph/subtree.hpp
      title: "subtree info / \u305D\u308C\u305E\u308C\u306E\u90E8\u5206\u6728\u306E\
        \ size \u3068\u304B height \u3068\u304B\u3092\u307E\u3068\u3081\u3066\u6C42\
        \u3081\u3066\u304A\u3044\u3066\u304F\u308C\u308B\u3084\u3064"
    - icon: ':heavy_check_mark:'
      path: graph/topological_sort.hpp
      title: topological sort
    - icon: ':heavy_check_mark:'
      path: graph/transpose_graph.hpp
      title: graph/transpose_graph.hpp
    - icon: ':heavy_check_mark:'
      path: graph/tree_decomposition.hpp
      title: "\u6728\u5206\u89E3 (\u6728\u5E45 $t \\le 2$)"
    - icon: ':warning:'
      path: graph/virtual_trees.hpp
      title: "\u865A\u6A39 / virtual trees"
    - icon: ':heavy_check_mark:'
      path: graph/yen_algorithm.hpp
      title: K shortest simple paths (Yen's algorithm + Dijkstra, $O(K V (E + V) \log
        V)$)
  - name: hack
    pages:
    - icon: ':heavy_check_mark:'
      path: hack/fastio.hpp
      title: hack/fastio.hpp
    - icon: ':heavy_check_mark:'
      path: hack/fastio_printer.hpp
      title: hack/fastio_printer.hpp
    - icon: ':heavy_check_mark:'
      path: hack/fastio_scanner.hpp
      title: hack/fastio_scanner.hpp
    - icon: ':heavy_check_mark:'
      path: hack/stack_pivot.hpp
      title: hack/stack_pivot.hpp
  - name: modulus
    pages:
    - icon: ':heavy_check_mark:'
      path: modulus/bell_number.hpp
      title: "the Bell number (\u524D\u51E6\u7406 $O(NK)$ + $O(1)$)"
    - icon: ':heavy_check_mark:'
      path: modulus/choose.hpp
      title: "combination / \u7D44\u5408\u305B ${} _ n C _ r$ (\u524D\u51E6\u7406\
        \ $O(n)$ + $O(1)$)"
    - icon: ':heavy_check_mark:'
      path: modulus/choose_simple.hpp
      title: "combination / \u7D44\u5408\u305B ${} _ n C _ r$ (\u611A\u76F4 $O(r)$)"
    - icon: ':heavy_check_mark:'
      path: modulus/factorial.hpp
      title: modulus/factorial.hpp
    - icon: ':heavy_check_mark:'
      path: modulus/formal_power_series.hpp
      title: "formal power series / \u5F62\u5F0F\u7684\u7F83\u7D1A\u6570\u74B0 $\\\
        mathbb{Z}/n\\mathbb{Z}\\lbrack\\lbrack x\\rbrack\\rbrack$"
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
    - icon: ':question:'
      path: modulus/modinv.hpp
      title: modulus/modinv.hpp
    - icon: ':heavy_check_mark:'
      path: modulus/modlog.hpp
      title: "discrete log / \u96E2\u6563\u5BFE\u6570 (the baby-step giant-step, $O(\\\
        sqrt{m})$)"
    - icon: ':question:'
      path: modulus/modpow.hpp
      title: modulus/modpow.hpp
    - icon: ':heavy_check_mark:'
      path: modulus/modsqrt.hpp
      title: find the sqrt $b$ of $a$ modulo $p$
    - icon: ':heavy_check_mark:'
      path: modulus/multichoose.hpp
      title: "\u91CD\u8907\u7D44\u5408\u305B ${} _ n H _ r = {} _ {n + r - 1} C _\
        \ r$ (\u524D\u51E6\u7406 $O(n)$ + $O(1)$)"
    - icon: ':heavy_check_mark:'
      path: modulus/multichoose_simple.hpp
      title: "\u91CD\u8907\u7D44\u5408\u305B ${} _ n H _ r = {} _ {n + r - 1} C _\
        \ r$ (\u611A\u76F4 $O(r)$)"
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
      path: modulus/permute.hpp
      title: "permutation / \u9806\u5217 ${} _ n P _ r$ (\u524D\u51E6\u7406 $O(n)$\
        \ + $O(1)$)"
    - icon: ':heavy_check_mark:'
      path: modulus/stirling_number_of_the_second_kind_convolution.hpp
      title: the Stirling number of the second kind (for given $N$, compute $S(N,
        \ast)$ in $O(N \log N)$)
    - icon: ':heavy_check_mark:'
      path: modulus/stirling_number_of_the_second_kind_direct.hpp
      title: the Stirling number of the second kind ($O(K \log N)$)
    - icon: ':heavy_check_mark:'
      path: modulus/stirling_number_of_the_second_kind_table.hpp
      title: "the Stirling number of the second kind (\u524D\u51E6\u7406 $O(NK)$ +\
        \ $O(1)$)"
    - icon: ':heavy_check_mark:'
      path: modulus/twelvefold_way.hpp
      title: "twelvefold way / \u5199\u50CF12\u76F8"
  - name: monoids
    pages:
    - icon: ':warning:'
      path: monoids/chmin_chmax_add.hpp
      title: monoids/chmin_chmax_add.hpp
    - icon: ':warning:'
      path: monoids/chmin_chmax_add_min_max_action.hpp
      title: monoids/chmin_chmax_add_min_max_action.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/dual.hpp
      title: monoids/dual.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/gcd.hpp
      title: monoids/gcd.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/left.hpp
      title: monoids/left.hpp
    - icon: ':warning:'
      path: monoids/left_action.hpp
      title: monoids/left_action.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/linear_function.hpp
      title: monoids/linear_function.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/linear_function_plus_count_action.hpp
      title: monoids/linear_function_plus_count_action.hpp
    - icon: ':warning:'
      path: monoids/matrix_template.hpp
      title: monoids/matrix_template.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/max.hpp
      title: monoids/max.hpp
    - icon: ':warning:'
      path: monoids/max_index.hpp
      title: monoids/max_index.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/min.hpp
      title: monoids/min.hpp
    - icon: ':warning:'
      path: monoids/min_count.hpp
      title: monoids/min_count.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/min_index.hpp
      title: monoids/min_index.hpp
    - icon: ':warning:'
      path: monoids/min_max.hpp
      title: monoids/min_max.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/plus.hpp
      title: monoids/plus.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/plus_count.hpp
      title: monoids/plus_count.hpp
    - icon: ':warning:'
      path: monoids/plus_max_action.hpp
      title: monoids/plus_max_action.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/plus_min_action.hpp
      title: monoids/plus_min_action.hpp
    - icon: ':warning:'
      path: monoids/plus_min_count_action.hpp
      title: monoids/plus_min_count_action.hpp
    - icon: ':warning:'
      path: monoids/product.hpp
      title: monoids/product.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/reversible.hpp
      title: monoids/reversible.hpp
    - icon: ':heavy_check_mark:'
      path: monoids/trivial.hpp
      title: monoids/trivial.hpp
    - icon: ':warning:'
      path: monoids/trivial_action.hpp
      title: monoids/trivial_action.hpp
  - name: number
    pages:
    - icon: ':heavy_check_mark:'
      path: number/fast_fourier_transformation.hpp
      title: FFT convolution
    - icon: ':heavy_check_mark:'
      path: number/gcd.hpp
      title: number/gcd.hpp
    - icon: ':warning:'
      path: number/inversion_number.hpp
      title: number/inversion_number.hpp
    - icon: ':warning:'
      path: number/karatsuba.hpp
      title: Karatsuba method ($O(n^{\log_2 3})$)
    - icon: ':warning:'
      path: number/lagrange_interpolation.hpp
      title: Lagrange interpolation
    - icon: ':heavy_check_mark:'
      path: number/matrix.hpp
      title: number/matrix.hpp
    - icon: ':heavy_check_mark:'
      path: number/matrix_template.hpp
      title: number/matrix_template.hpp
    - icon: ':warning:'
      path: number/miller-rabin.hpp
      title: miller-rabin primality test
    - icon: ':heavy_check_mark:'
      path: number/primes.hpp
      title: number/primes.hpp
    - icon: ':heavy_check_mark:'
      path: number/primes_extra.hpp
      title: number/primes_extra.hpp
  - name: old
    pages:
    - icon: ':warning:'
      path: old/a.inc.cpp
      title: Andrew's Monotone Chain
    - icon: ':warning:'
      path: old/aho-corasick.inc.cpp
      title: old/aho-corasick.inc.cpp
    - icon: ':warning:'
      path: old/bernoulli-number.inc.cpp
      title: the Bernoulli number
    - icon: ':warning:'
      path: old/bipartite-graph.inc.cpp
      title: old/bipartite-graph.inc.cpp
    - icon: ':warning:'
      path: old/boyer-moore.inc.cpp
      title: old/boyer-moore.inc.cpp
    - icon: ':warning:'
      path: old/breadth-first-search.inc.cpp
      title: compute the distances from root
    - icon: ':warning:'
      path: old/centers.inc.cpp
      title: "get centers of a tree / \u6728\u306E\u4E2D\u5FC3"
    - icon: ':warning:'
      path: old/centroid-decomposition.inc.cpp
      title: "get centroids of a graph / \u91CD\u5FC3\u5206\u89E3"
    - icon: ':warning:'
      path: old/comparable-view.inc.cpp
      title: compare substrings of a string with O(1) using suffix arrays
    - icon: ':warning:'
      path: old/convex-hull-trick-with-monotonicity.inc.cpp
      title: old/convex-hull-trick-with-monotonicity.inc.cpp
    - icon: ':warning:'
      path: old/convex-hull.inc.cpp
      title: old/convex-hull.inc.cpp
    - icon: ':warning:'
      path: old/cumulative-sum.inc.cpp
      title: cumulative sum
    - icon: ':warning:'
      path: old/dice.inc.cpp
      title: old/dice.inc.cpp
    - icon: ':warning:'
      path: old/digit-dp.inc.cpp
      title: old/digit-dp.inc.cpp
    - icon: ':warning:'
      path: old/dijkstra.inc.cpp
      title: old/dijkstra.inc.cpp
    - icon: ':warning:'
      path: old/distributed-code-jam.inc.cpp
      title: old/distributed-code-jam.inc.cpp
    - icon: ':warning:'
      path: old/dlopen.inc.cpp
      title: old/dlopen.inc.cpp
    - icon: ':warning:'
      path: old/dominator-tree.inc.cpp
      title: old/dominator-tree.inc.cpp
    - icon: ':warning:'
      path: old/double-ended-priority-queue.inc.cpp
      title: a double-ended priority queue
    - icon: ':warning:'
      path: old/doubling.inc.cpp
      title: the doubling technique
    - icon: ':warning:'
      path: old/dynamic-segment-tree.inc.cpp
      title: old/dynamic-segment-tree.inc.cpp
    - icon: ':warning:'
      path: old/euler-tour.inc.cpp
      title: euler tour
    - icon: ':warning:'
      path: old/extgcd.inc.cpp
      title: extended gcd
    - icon: ':warning:'
      path: old/factoradic.inc.cpp
      title: old/factoradic.inc.cpp
    - icon: ':warning:'
      path: old/factorial-embed.inc.cpp
      title: a program to make the table
    - icon: ':warning:'
      path: old/fast-mobius-transformation.inc.cpp
      title: (upward) fast zeta transformation
    - icon: ':warning:'
      path: old/ford-fulkerson.inc.cpp
      title: old/ford-fulkerson.inc.cpp
    - icon: ':warning:'
      path: old/graphviz.inc.cpp
      title: old/graphviz.inc.cpp
    - icon: ':warning:'
      path: old/heavy_light_decomposition.inc.cpp
      title: "heavy light decomposition / \u91CD\u8EFD\u5206\u89E3"
    - icon: ':warning:'
      path: old/iterate.inc.cpp
      title: old/iterate.inc.cpp
    - icon: ':warning:'
      path: old/knapsack-problem-branch-and-bound.inc.cpp
      title: old/knapsack-problem-branch-and-bound.inc.cpp
    - icon: ':warning:'
      path: old/knuth-morris-pratt.inc.cpp
      title: Morris-Pratt algorithm
    - icon: ':warning:'
      path: old/linear-weighted-sum.inc.cpp
      title: old/linear-weighted-sum.inc.cpp
    - icon: ':warning:'
      path: old/longest-increasing-subsequence.inc.cpp
      title: old/longest-increasing-subsequence.inc.cpp
    - icon: ':warning:'
      path: old/marathon.inc.cpp
      title: old/marathon.inc.cpp
    - icon: ':warning:'
      path: old/matrix.inc.cpp
      title: old/matrix.inc.cpp
    - icon: ':warning:'
      path: old/maximum-independent-set.inc.cpp
      title: old/maximum-independent-set.inc.cpp
    - icon: ':warning:'
      path: old/midpoint.inc.cpp
      title: a structure to make a midpoint for given two points
    - icon: ':warning:'
      path: old/palindrome.inc.cpp
      title: old/palindrome.inc.cpp
    - icon: ':warning:'
      path: old/periodic-function-power.inc.cpp
      title: old/periodic-function-power.inc.cpp
    - icon: ':warning:'
      path: old/persistent-array.inc.cpp
      title: "persistent array / \u6C38\u7D9A\u914D\u5217"
    - icon: ':warning:'
      path: old/persistent-randomized-binary-search-tree.inc.cpp
      title: old/persistent-randomized-binary-search-tree.inc.cpp
    - icon: ':warning:'
      path: old/point-int.inc.cpp
      title: old/point-int.inc.cpp
    - icon: ':warning:'
      path: old/polya-enumeration.inc.cpp
      title: old/polya-enumeration.inc.cpp
    - icon: ':warning:'
      path: old/popen2.inc.cpp
      title: old/popen2.inc.cpp
    - icon: ':warning:'
      path: old/primes-small.inc.cpp
      title: enumerate primes in [2, n) with O(n log log n)
    - icon: ':warning:'
      path: old/range-union-find-tree.inc.cpp
      title: old/range-union-find-tree.inc.cpp
    - icon: ':warning:'
      path: old/rational.inc.cpp
      title: old/rational.inc.cpp
    - icon: ':warning:'
      path: old/red-black-tree.inc.cpp
      title: old/red-black-tree.inc.cpp
    - icon: ':heavy_check_mark:'
      path: old/rollback-square-decomposition.inc.cpp
      title: the extended Mo's algorithm
    - icon: ':warning:'
      path: old/rolling-hash.inc.cpp
      title: a rolling hash
    - icon: ':warning:'
      path: old/segment-tree-2d.inc.cpp
      title: old/segment-tree-2d.inc.cpp
    - icon: ':warning:'
      path: old/simplex.inc.cpp
      title: old/simplex.inc.cpp
    - icon: ':warning:'
      path: old/skew-heap.inc.cpp
      title: old/skew-heap.inc.cpp
    - icon: ':warning:'
      path: old/sliding-window.inc.cpp
      title: the sliding window minimum algorithm
    - icon: ':warning:'
      path: old/string-skip-list.inc.cpp
      title: old/string-skip-list.inc.cpp
    - icon: ':warning:'
      path: old/subset.inc.cpp
      title: old/subset.inc.cpp
    - icon: ':warning:'
      path: old/suffix-array.inc.cpp
      title: old/suffix-array.inc.cpp
    - icon: ':warning:'
      path: old/ternary-search.inc.cpp
      title: old/ternary-search.inc.cpp
    - icon: ':warning:'
      path: old/treap.inc.cpp
      title: old/treap.inc.cpp
    - icon: ':warning:'
      path: old/tree-dp.inc.cpp
      title: "fold a rooted tree / \u6728DP"
    - icon: ':warning:'
      path: old/trie-tree.inc.cpp
      title: old/trie-tree.inc.cpp
    - icon: ':warning:'
      path: old/two-edge-connected-components.inc.cpp
      title: "2-edge-connected components decomposition / 2-\u8FBA\u9023\u7D50\u6210\
        \u5206\u5206\u89E3"
    - icon: ':warning:'
      path: old/two-node-connected-components.inc.cpp
      title: "2-node-connected components decomposition / 2-\u9802\u70B9\u9023\u7D50\
        \u6210\u5206\u5206\u89E3"
    - icon: ':warning:'
      path: old/warshall-floyd.inc.cpp
      title: Warshall-Floyd algorithm
    - icon: ':warning:'
      path: old/xorshift.inc.cpp
      title: old/xorshift.inc.cpp
  - name: python
    pages:
    - icon: ':warning:'
      path: python/binary_search.py
      title: python/binary_search.py
    - icon: ':warning:'
      path: python/chinese_remainder_theorem.py
      title: python/chinese_remainder_theorem.py
    - icon: ':warning:'
      path: python/choose.py
      title: python/choose.py
    - icon: ':warning:'
      path: python/extgcd.py
      title: python/extgcd.py
    - icon: ':warning:'
      path: python/matrix-modinv.py
      title: python/matrix-modinv.py
    - icon: ':warning:'
      path: python/miller_rabin.py
      title: python/miller_rabin.py
    - icon: ':warning:'
      path: python/rational-gcd.py
      title: python/rational-gcd.py
  - name: string
    pages:
    - icon: ':heavy_check_mark:'
      path: string/longest_common_prefix.hpp
      title: "Longest Common Prefix / \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E (\u63A5\
        \u5C3E\u8F9E\u914D\u5217, \u524D\u51E6\u7406 $O(N (\\log N)^2)$ + $O(1)$)"
    - icon: ':heavy_check_mark:'
      path: string/suffix_array.hpp
      title: "Suffix Array / \u63A5\u5C3E\u8F9E\u914D\u5217 ($O(N (\\log N)^2)$, Manber\
        \ & Myers)"
  - name: .
    pages:
    - icon: ':warning:'
      path: template.cpp
      title: template.cpp
  - name: utils
    pages:
    - icon: ':heavy_check_mark:'
      path: utils/binary_search.hpp
      title: "a binary search / \u4E8C\u5206\u63A2\u7D22"
    - icon: ':warning:'
      path: utils/binary_search_float.hpp
      title: "a binary search on floating point numbers / \u4E8C\u5206\u63A2\u7D22\
        \ (\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570)"
    - icon: ':heavy_check_mark:'
      path: utils/binary_search_max.hpp
      title: utils/binary_search_max.hpp
    - icon: ':heavy_check_mark:'
      path: utils/coordinate_compression.hpp
      title: utils/coordinate_compression.hpp
    - icon: ':heavy_check_mark:'
      path: utils/dsu_on_tree.hpp
      title: DSU on tree (sack)
    - icon: ':warning:'
      path: utils/fast_zeta_transform.hpp
      title: upward fast zeta transform on primes
    - icon: ':warning:'
      path: utils/interval_map.hpp
      title: map from disjoint intervals
    - icon: ':warning:'
      path: utils/interval_set.hpp
      title: set of disjoint intervals
    - icon: ':heavy_check_mark:'
      path: utils/left_to_right_maxima.hpp
      title: "Length of Left-to-right Maxima (\u524D\u51E6\u7406 $O(n \\log n)$ +\
        \ $O(1)$)"
    - icon: ':question:'
      path: utils/macros.hpp
      title: utils/macros.hpp
    - icon: ':warning:'
      path: utils/mex.hpp
      title: Minimum Excluded Value ($O(n)$ for a given sorted container)
    - icon: ':warning:'
      path: utils/mex_calculator.hpp
      title: utils/mex_calculator.hpp
    - icon: ':heavy_check_mark:'
      path: utils/mo_algorithm.hpp
      title: utils/mo_algorithm.hpp
    - icon: ':warning:'
      path: utils/next_combination.hpp
      title: utils/next_combination.hpp
    - icon: ':heavy_check_mark:'
      path: utils/two_satisfiability.hpp
      title: 2-SAT ($O(N)$)
  verificationCategories:
  - name: data_structure
    pages:
    - icon: ':heavy_check_mark:'
      path: data_structure/binary_indexed_tree.test.cpp
      title: data_structure/binary_indexed_tree.test.cpp
    - icon: ':heavy_check_mark:'
      path: data_structure/convex_hull_trick.line_add_get_min.test.cpp
      title: data_structure/convex_hull_trick.line_add_get_min.test.cpp
    - icon: ':heavy_check_mark:'
      path: data_structure/dual_segment_tree.range_update_query.test.cpp
      title: data_structure/dual_segment_tree.range_update_query.test.cpp
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
      path: data_structure/union_find_tree.aoj.test.cpp
      title: data_structure/union_find_tree.aoj.test.cpp
    - icon: ':heavy_check_mark:'
      path: data_structure/union_find_tree.yosupo.test.cpp
      title: data_structure/union_find_tree.yosupo.test.cpp
    - icon: ':heavy_check_mark:'
      path: data_structure/wavelet_matrix.aoj2674.test.cpp
      title: data_structure/wavelet_matrix.aoj2674.test.cpp
    - icon: ':heavy_check_mark:'
      path: data_structure/wavelet_matrix.range_kth_smallest.test.cpp
      title: data_structure/wavelet_matrix.range_kth_smallest.test.cpp
    - icon: ':heavy_check_mark:'
      path: data_structure/wavelet_matrix.rectangle_sum.test.cpp
      title: data_structure/wavelet_matrix.rectangle_sum.test.cpp
  - name: graph
    pages:
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
    - icon: ':heavy_check_mark:'
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
  - name: hack
    pages:
    - icon: ':heavy_check_mark:'
      path: hack/fastio.yosupo.test.cpp
      title: hack/fastio.yosupo.test.cpp
    - icon: ':heavy_check_mark:'
      path: hack/fastio_scanner_and_printer.yosupo.test.cpp
      title: hack/fastio_scanner_and_printer.yosupo.test.cpp
  - name: modulus
    pages:
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
  - name: number
    pages:
    - icon: ':heavy_check_mark:'
      path: number/fast_fourier_transformation.yukicoder-856.test.cpp
      title: number/fast_fourier_transformation.yukicoder-856.test.cpp
    - icon: ':heavy_check_mark:'
      path: number/matrix.yukicoder-1073.test.cpp
      title: number/matrix.yukicoder-1073.test.cpp
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
      path: number/primes_extra.yukicoder-1659.test.cpp
      title: number/primes_extra.yukicoder-1659.test.cpp
  - name: old
    pages:
    - icon: ':heavy_check_mark:'
      path: old/rollback-square-decomposition.yukicoder-1031.test.cpp
      title: old/rollback-square-decomposition.yukicoder-1031.test.cpp
  - name: string
    pages:
    - icon: ':heavy_check_mark:'
      path: string/longest_common_prefix.yosupo.test.cpp
      title: string/longest_common_prefix.yosupo.test.cpp
    - icon: ':heavy_check_mark:'
      path: string/suffix_array.yosupo.test.cpp
      title: string/suffix_array.yosupo.test.cpp
  - name: utils
    pages:
    - icon: ':heavy_check_mark:'
      path: utils/binary_search.aoj.test.cpp
      title: utils/binary_search.aoj.test.cpp
    - icon: ':heavy_check_mark:'
      path: utils/dsu_on_tree.aoj.test.cpp
      title: utils/dsu_on_tree.aoj.test.cpp
    - icon: ':heavy_check_mark:'
      path: utils/mo_algorithm.yuki1270.test.cpp
      title: utils/mo_algorithm.yuki1270.test.cpp
    - icon: ':heavy_check_mark:'
      path: utils/two_satisfiability.yosupo.test.cpp
      title: utils/two_satisfiability.yosupo.test.cpp
layout: toppage
---
