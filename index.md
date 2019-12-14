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
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# C++ Competitive Programming Library

[![Actions Status]({{ site.github.repository_url }}/workflows/verify/badge.svg)]({{ site.github.repository_url }}/actions) <a href="{{ site.github.repository_url }}"><img src="https://img.shields.io/github/last-commit/{{ site.github.owner_name }}/{{ site.github.repository_name }}" /></a>

## Library Files
<div id="5058f1af8388633f609cadb75a75dc9d"></div>
### .
* :warning: <a href="library/template.cpp.html">template.cpp</a>


<div id="c8f6850ec2ec3fb32f203c1f4e3c2fd2"></div>
### data_structure
* :warning: <a href="library/data_structure/binary-indexed-tree.inc.cpp.html">data_structure/binary-indexed-tree.inc.cpp</a>
* :warning: <a href="library/data_structure/convex-hull-trick-with-monotonicity.inc.cpp.html">data_structure/convex-hull-trick-with-monotonicity.inc.cpp</a>
* :warning: <a href="library/data_structure/convex_hull_trick.hpp.html">data_structure/convex_hull_trick.hpp</a>
* :warning: <a href="library/data_structure/convex_hull_trick.random-test.cpp.html">data_structure/convex_hull_trick.random-test.cpp</a>
* :warning: <a href="library/data_structure/double-ended-priority-queue.inc.cpp.html">a double-ended priority queue</a>
* :heavy_check_mark: <a href="library/data_structure/dual_segment_tree.hpp.html">a dual segment tree</a>
* :warning: <a href="library/data_structure/dual_segment_tree.unit.random-test.cpp.html">data_structure/dual_segment_tree.unit.random-test.cpp</a>
* :warning: <a href="library/data_structure/dynamic-segment-tree.inc.cpp.html">data_structure/dynamic-segment-tree.inc.cpp</a>
* :warning: <a href="library/data_structure/fully_indexable_dictionary.hpp.html">a fully indexable dictionary</a>
* :warning: <a href="library/data_structure/fully_indexable_dictionary.random-test.cpp.html">data_structure/fully_indexable_dictionary.random-test.cpp</a>
* :warning: <a href="library/data_structure/lazy-propagation-red-black-tree.inc.cpp.html">data_structure/lazy-propagation-red-black-tree.inc.cpp</a>
* :heavy_check_mark: <a href="library/data_structure/lazy_propagation_segment_tree.hpp.html">a lazy propagation segment tree</a>
* :warning: <a href="library/data_structure/lazy_propagation_segment_tree.unit.random-test.cpp.html">data_structure/lazy_propagation_segment_tree.unit.random-test.cpp</a>
* :warning: <a href="library/data_structure/li_chao_tree.hpp.html">data_structure/li_chao_tree.hpp</a>
* :warning: <a href="library/data_structure/li_chao_tree.random-test.cpp.html">data_structure/li_chao_tree.random-test.cpp</a>
* :warning: <a href="library/data_structure/linear-weighted-sum.inc.cpp.html">data_structure/linear-weighted-sum.inc.cpp</a>
* :heavy_check_mark: <a href="library/data_structure/link_cut_tree.hpp.html">an extended structure of union-find tree</a>
* :warning: <a href="library/data_structure/link_cut_tree.spaceships.random-test.cpp.html">data_structure/link_cut_tree.spaceships.random-test.cpp</a>
* :warning: <a href="library/data_structure/persistent-array.inc.cpp.html">data_structure/persistent-array.inc.cpp</a>
* :warning: <a href="library/data_structure/persistent-randomized-binary-search-tree.inc.cpp.html">data_structure/persistent-randomized-binary-search-tree.inc.cpp</a>
* :warning: <a href="library/data_structure/range-union-find-tree.inc.cpp.html">data_structure/range-union-find-tree.inc.cpp</a>
* :warning: <a href="library/data_structure/red-black-tree.inc.cpp.html">data_structure/red-black-tree.inc.cpp</a>
* :warning: <a href="library/data_structure/segment-tree-2d.inc.cpp.html">data_structure/segment-tree-2d.inc.cpp</a>
* :heavy_check_mark: <a href="library/data_structure/segment_tree.hpp.html">a segment tree</a>
* :warning: <a href="library/data_structure/segment_tree_beats.hpp.html">a segment tree beats</a>
* :warning: <a href="library/data_structure/skew-heap.inc.cpp.html">data_structure/skew-heap.inc.cpp</a>
* :warning: <a href="library/data_structure/sliding-window.inc.cpp.html">the sliding window minimum algorithm</a>
* :warning: <a href="library/data_structure/sliding_window_aggregation.hpp.html">get sum of elements in the queue</a>
* :warning: <a href="library/data_structure/sliding_window_aggregation.random-test.cpp.html">data_structure/sliding_window_aggregation.random-test.cpp</a>
* :heavy_check_mark: <a href="library/data_structure/sparse_table.hpp.html">sparse table on a semilattice</a>
* :warning: <a href="library/data_structure/sparse_table.unit.random-test.cpp.html">data_structure/sparse_table.unit.random-test.cpp</a>
* :warning: <a href="library/data_structure/treap.inc.cpp.html">data_structure/treap.inc.cpp</a>
* :warning: <a href="library/data_structure/trie-tree.inc.cpp.html">data_structure/trie-tree.inc.cpp</a>
* :heavy_check_mark: <a href="library/data_structure/union_find_tree.hpp.html">a disjoint set structure</a>
* :heavy_check_mark: <a href="library/data_structure/union_find_tree_with_monoid.hpp.html">a disjoint set structure with monoid</a>
* :warning: <a href="library/data_structure/wavelet_matrix.hpp.html">a wavelet matrix</a>
* :warning: <a href="library/data_structure/wavelet_matrix.random-test.cpp.html">data_structure/wavelet_matrix.random-test.cpp</a>


<div id="ed7daeb157cd9b31e53896ad3c771a26"></div>
### geometry
* :warning: <a href="library/geometry/a.inc.cpp.html">Andrew's Monotone Chain</a>
* :warning: <a href="library/geometry/convex-hull.inc.cpp.html">geometry/convex-hull.inc.cpp</a>
* :warning: <a href="library/geometry/point-int.inc.cpp.html">geometry/point-int.inc.cpp</a>


<div id="f8b0b924ebd7046dbfa85a856e4682c8"></div>
### graph
* :heavy_check_mark: <a href="library/graph/bellman_ford.hpp.html">Bellman-Ford algorithm</a>
* :warning: <a href="library/graph/bipartite-graph.inc.cpp.html">graph/bipartite-graph.inc.cpp</a>
* :warning: <a href="library/graph/breadth-first-search.inc.cpp.html">compute the distances from root</a>
* :warning: <a href="library/graph/catapillar_graph.hpp.html">get a central path of a catapillar graph</a>
* :warning: <a href="library/graph/centroid-decomposition.inc.cpp.html">graph/centroid-decomposition.inc.cpp</a>
* :warning: <a href="library/graph/diameter.inc.cpp.html">graph/diameter.inc.cpp</a>
* :warning: <a href="library/graph/dijkstra.inc.cpp.html">graph/dijkstra.inc.cpp</a>
* :warning: <a href="library/graph/dinic.inc.cpp.html">Dinic</a>
* :warning: <a href="library/graph/dominator-tree.inc.cpp.html">graph/dominator-tree.inc.cpp</a>
* :warning: <a href="library/graph/euler-tour.inc.cpp.html">euler tour</a>
* :warning: <a href="library/graph/ford-fulkerson.inc.cpp.html">graph/ford-fulkerson.inc.cpp</a>
* :warning: <a href="library/graph/heavy_light_decomposition.inc.cpp.html">heavy light decomposition</a>
* :warning: <a href="library/graph/lowest-common-ancestor-doubling.inc.cpp.html">lowest common ancestor with doubling</a>
* :heavy_check_mark: <a href="library/graph/lowest_common_ancestor.hpp.html">lowest common ancestor with \pm 1 RMQ and sparse table</a>
* :warning: <a href="library/graph/minimum-cost-flow.inc.cpp.html">minimum-cost flow with primal-dual method</a>
* :warning: <a href="library/graph/minimum-spanning-tree.inc.cpp.html">graph/minimum-spanning-tree.inc.cpp</a>
* :warning: <a href="library/graph/namori-graph.inc.cpp.html">graph/namori-graph.inc.cpp</a>
* :warning: <a href="library/graph/shortest_path_faster_algorithm.hpp.html">Shortest Path Faster Algorithm</a>
* :warning: <a href="library/graph/shortest_path_faster_algorithm.random-test.cpp.html">graph/shortest_path_faster_algorithm.random-test.cpp</a>
* :warning: <a href="library/graph/shortest_path_faster_algorithm.unit.random-test.cpp.html">graph/shortest_path_faster_algorithm.unit.random-test.cpp</a>
* :warning: <a href="library/graph/strongly_connected_components.cpp.html">strongly connected components decomposition, Kosaraju's algorithm</a>
* :heavy_check_mark: <a href="library/graph/subtree.hpp.html">graph/subtree.hpp</a>
* :warning: <a href="library/graph/subtree.unit.random-test.cpp.html">graph/subtree.unit.random-test.cpp</a>
* :warning: <a href="library/graph/topological-sort.inc.cpp.html">graph/topological-sort.inc.cpp</a>
* :warning: <a href="library/graph/tree-dp.inc.cpp.html">fold a rooted tree (木DP)</a>
* :warning: <a href="library/graph/two-edge-connected-components.inc.cpp.html">2-edge-connected components decomposition</a>
* :warning: <a href="library/graph/two-node-connected-components.inc.cpp.html">2-node-connected components decomposition</a>
* :warning: <a href="library/graph/utils.inc.cpp.html">reverse a digraph</a>
* :warning: <a href="library/graph/warshall-floyd.inc.cpp.html">Warshall-Floyd algorithm</a>


<div id="06efba23b1f3a9b846a25c6b49f30348"></div>
### modulus
* :warning: <a href="library/modulus/998244353.inc.cpp.html">modulus/998244353.inc.cpp</a>
* :warning: <a href="library/modulus/bell-number.inc.cpp.html">the Bell number</a>
* :warning: <a href="library/modulus/bernoulli-number.inc.cpp.html">0^k + 1^k + 2^k + ... + (n - 1)^k</a>
* :warning: <a href="library/modulus/choose.hpp.html">modulus/choose.hpp</a>
* :warning: <a href="library/modulus/discrete-log.inc.cpp.html">modulus/discrete-log.inc.cpp</a>
* :warning: <a href="library/modulus/factorial-embed.inc.cpp.html">a program to make the table</a>
* :warning: <a href="library/modulus/factorial.hpp.html">modulus/factorial.hpp</a>
* :warning: <a href="library/modulus/factorial.unit.random-test.cpp.html">modulus/factorial.unit.random-test.cpp</a>
* :warning: <a href="library/modulus/fib.inc.cpp.html">modulus/fib.inc.cpp</a>
* :heavy_check_mark: <a href="library/modulus/mint.hpp.html">modulus/mint.hpp</a>
* :warning: <a href="library/modulus/mint.unit.random-test.cpp.html">modulus/mint.unit.random-test.cpp</a>
* :warning: <a href="library/modulus/modops.inc.cpp.html">modulus/modops.inc.cpp</a>
* :warning: <a href="library/modulus/polya-enumeration.inc.cpp.html">modulus/polya-enumeration.inc.cpp</a>
* :warning: <a href="library/modulus/powmod.inc.cpp.html">the baby-step giant-step</a>
* :warning: <a href="library/modulus/stirling-number-of-the-second-kind.inc.cpp.html">the Stirling number of the second kind</a>
* :warning: <a href="library/modulus/twelvefold-way.inc.cpp.html">labeled-N labeled-K any-f</a>


<div id="b1bc248a7ff2b2e95569f56de68615df"></div>
### number
* :warning: <a href="library/number/choose.inc.cpp.html">number/choose.inc.cpp</a>
* :warning: <a href="library/number/extgcd.inc.cpp.html">extended gcd</a>
* :warning: <a href="library/number/factoradic.inc.cpp.html">number/factoradic.inc.cpp</a>
* :warning: <a href="library/number/fast-mobius-transformation.inc.cpp.html">(upward) fast zeta transformation</a>
* :warning: <a href="library/number/fast_fourier_transformation.hpp.html">the convolution</a>
* :warning: <a href="library/number/fast_fourier_transformation.unit.random-test.cpp.html">number/fast_fourier_transformation.unit.random-test.cpp</a>
* :heavy_check_mark: <a href="library/number/formal_power_series.hpp.html">number/formal_power_series.hpp</a>
* :heavy_check_mark: <a href="library/number/gcd.hpp.html">number/gcd.hpp</a>
* :warning: <a href="library/number/gcd.random-test.cpp.html">number/gcd.random-test.cpp</a>
* :warning: <a href="library/number/lagrange_interpolation.hpp.html">Lagrange interpolation</a>
* :warning: <a href="library/number/lagrange_interpolation.random-test.cpp.html">number/lagrange_interpolation.random-test.cpp</a>
* :warning: <a href="library/number/matrix.inc.cpp.html">number/matrix.inc.cpp</a>
* :warning: <a href="library/number/matrix.template.inc.cpp.html">number/matrix.template.inc.cpp</a>
* :warning: <a href="library/number/miller-rabin.inc.cpp.html">number/miller-rabin.inc.cpp</a>
* :heavy_check_mark: <a href="library/number/number_theoretic_transformation.hpp.html">a specialized version of Garner's algorithm</a>
* :warning: <a href="library/number/primes-small.inc.cpp.html">enumerate primes in \[2, n) with O(n log log n)</a>
* :heavy_check_mark: <a href="library/number/primes.hpp.html">number/primes.hpp</a>
* :warning: <a href="library/number/rational.inc.cpp.html">number/rational.inc.cpp</a>


<div id="b45cffe084dd3d20d928bee85e7b0f21"></div>
### string
* :warning: <a href="library/string/aho-corasick.inc.cpp.html">string/aho-corasick.inc.cpp</a>
* :warning: <a href="library/string/boyer-moore.inc.cpp.html">string/boyer-moore.inc.cpp</a>
* :warning: <a href="library/string/comparable-view.inc.cpp.html">compare substrings of a string with O(1) using suffix arrays</a>
* :warning: <a href="library/string/knuth-morris-pratt.inc.cpp.html">Morris-Pratt algorithm</a>
* :warning: <a href="library/string/palindrome.inc.cpp.html">string/palindrome.inc.cpp</a>
* :warning: <a href="library/string/prefix.inc.cpp.html">string/prefix.inc.cpp</a>
* :warning: <a href="library/string/rolling-hash.inc.cpp.html">a rolling hash</a>
* :warning: <a href="library/string/suffix-array.inc.cpp.html">suffix array</a>


<div id="2b3583e6e17721c54496bd04e57a0c15"></div>
### utils
* :warning: <a href="library/utils/apply-permutation.inc.cpp.html">utils/apply-permutation.inc.cpp</a>
* :heavy_check_mark: <a href="library/utils/binary_search.hpp.html">a flexible binary search</a>
* :warning: <a href="library/utils/binary_search.unit.random-test.cpp.html">utils/binary_search.unit.random-test.cpp</a>
* :warning: <a href="library/utils/coordinate-compression.inc.cpp.html">utils/coordinate-compression.inc.cpp</a>
* :warning: <a href="library/utils/cumulative-sum.inc.cpp.html">cumulative sum</a>
* :warning: <a href="library/utils/dice.inc.cpp.html">utils/dice.inc.cpp</a>
* :warning: <a href="library/utils/digit-dp.inc.cpp.html">utils/digit-dp.inc.cpp</a>
* :warning: <a href="library/utils/distributed-code-jam.inc.cpp.html">utils/distributed-code-jam.inc.cpp</a>
* :warning: <a href="library/utils/dlopen.inc.cpp.html">utils/dlopen.inc.cpp</a>
* :warning: <a href="library/utils/doubling.inc.cpp.html">the doubling technique</a>
* :heavy_check_mark: <a href="library/utils/dsu_on_tree.hpp.html">utils/dsu_on_tree.hpp</a>
* :warning: <a href="library/utils/fast_zeta_transform.hpp.html">upward fast zeta transform on primes</a>
* :warning: <a href="library/utils/fib.inc.cpp.html">utils/fib.inc.cpp</a>
* :warning: <a href="library/utils/graphviz.inc.cpp.html">utils/graphviz.inc.cpp</a>
* :warning: <a href="library/utils/inversion-number.inc.cpp.html">utils/inversion-number.inc.cpp</a>
* :warning: <a href="library/utils/iterate.inc.cpp.html">utils/iterate.inc.cpp</a>
* :warning: <a href="library/utils/knapsack-problem-branch-and-bound.inc.cpp.html">utils/knapsack-problem-branch-and-bound.inc.cpp</a>
* :warning: <a href="library/utils/longest-increasing-subsequence.inc.cpp.html">utils/longest-increasing-subsequence.inc.cpp</a>
* :heavy_check_mark: <a href="library/utils/macros.hpp.html">utils/macros.hpp</a>
* :warning: <a href="library/utils/marathon.inc.cpp.html">utils/marathon.inc.cpp</a>
* :warning: <a href="library/utils/maximum-independent-set.inc.cpp.html">utils/maximum-independent-set.inc.cpp</a>
* :warning: <a href="library/utils/mex.inc.cpp.html">minimum excluded value</a>
* :warning: <a href="library/utils/midpoint.inc.cpp.html">for given a and c, make b s.t. a < b < c</a>
* :heavy_check_mark: <a href="library/utils/monoids.hpp.html">utils/monoids.hpp</a>
* :warning: <a href="library/utils/periodic-function-power.inc.cpp.html">utils/periodic-function-power.inc.cpp</a>
* :warning: <a href="library/utils/popen2.inc.cpp.html">utils/popen2.inc.cpp</a>
* :warning: <a href="library/utils/rollback-square-decomposition.inc.cpp.html">the extended Mo's algorithm</a>
* :warning: <a href="library/utils/simplex.inc.cpp.html">utils/simplex.inc.cpp</a>
* :warning: <a href="library/utils/string-skip-list.inc.cpp.html">utils/string-skip-list.inc.cpp</a>
* :warning: <a href="library/utils/subset.inc.cpp.html">utils/subset.inc.cpp</a>
* :warning: <a href="library/utils/ternary-search.inc.cpp.html">utils/ternary-search.inc.cpp</a>
* :warning: <a href="library/utils/twosat.inc.cpp.html">utils/twosat.inc.cpp</a>
* :warning: <a href="library/utils/xorshift.inc.cpp.html">utils/xorshift.inc.cpp</a>


## Verify Files
* :heavy_check_mark: <a href="verify/data_structure/dual_segment_tree.range_update_query.test.cpp.html">data_structure/dual_segment_tree.range_update_query.test.cpp</a>
* :heavy_check_mark: <a href="verify/data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp</a>
* :heavy_check_mark: <a href="verify/data_structure/link_cut_tree.marked_ancestor.test.cpp.html">data_structure/link_cut_tree.marked_ancestor.test.cpp</a>
* :heavy_check_mark: <a href="verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html">data_structure/segment_tree.point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="verify/data_structure/segment_tree.range_sum_query.test.cpp.html">data_structure/segment_tree.range_sum_query.test.cpp</a>
* :heavy_check_mark: <a href="verify/data_structure/union_find_tree.test.cpp.html">data_structure/union_find_tree.test.cpp</a>
* :heavy_check_mark: <a href="verify/graph/bellman_ford.test.cpp.html">graph/bellman_ford.test.cpp</a>
* :heavy_check_mark: <a href="verify/graph/lowest_common_ancestor.aoj.test.cpp.html">graph/lowest_common_ancestor.aoj.test.cpp</a>
* :heavy_check_mark: <a href="verify/number/formal_power_series.exp.test.cpp.html">number/formal_power_series.exp.test.cpp</a>
* :heavy_check_mark: <a href="verify/number/formal_power_series.inv.test.cpp.html">number/formal_power_series.inv.test.cpp</a>
* :heavy_check_mark: <a href="verify/number/formal_power_series.log.test.cpp.html">number/formal_power_series.log.test.cpp</a>
* :heavy_check_mark: <a href="verify/number/number_theoretic_transformation.998244353.test.cpp.html">number/number_theoretic_transformation.998244353.test.cpp</a>
* :heavy_check_mark: <a href="verify/number/primes.aoj.test.cpp.html">number/primes.aoj.test.cpp</a>
* :heavy_check_mark: <a href="verify/utils/binary_search.aoj.test.cpp.html">utils/binary_search.aoj.test.cpp</a>
* :heavy_check_mark: <a href="verify/utils/dsu_on_tree.aoj.test.cpp.html">utils/dsu_on_tree.aoj.test.cpp</a>


