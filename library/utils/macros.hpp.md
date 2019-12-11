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


# :heavy_check_mark: utils/macros.hpp
<a href="../../index.html">Back to top page</a>

* category: utils
* <a href="{{ site.github.repository_url }}/blob/master/utils/macros.hpp">View this file on GitHub</a>
    - Last commit date: 2019-06-03 23:38:29 +0900




## Required By
* :heavy_check_mark: <a href="../data_structure/fully_indexable_dictionary.hpp.html">a fully indexable dictionary</a>
* :heavy_check_mark: <a href="../data_structure/lazy_propagation_segment_tree.hpp.html">a lazy propagation segment tree</a>
* :heavy_check_mark: <a href="../data_structure/li_chao_tree.hpp.html">data_structure/li_chao_tree.hpp</a>
* :heavy_check_mark: <a href="../data_structure/link_cut_tree.hpp.html">an extended structure of union-find tree</a>
* :heavy_check_mark: <a href="../data_structure/sliding_window_aggregation.hpp.html">get sum of elements in the queue</a>
* :heavy_check_mark: <a href="../data_structure/sparse_table.hpp.html">sparse table on a semilattice</a>
* :heavy_check_mark: <a href="../data_structure/wavelet_matrix.hpp.html">a wavelet matrix</a>
* :heavy_check_mark: <a href="../graph/bellman_ford.hpp.html">Bellman-Ford algorithm</a>
* :heavy_check_mark: <a href="../graph/lowest_common_ancestor.hpp.html">lowest common ancestor with \pm 1 RMQ and sparse table</a>
* :heavy_check_mark: <a href="../graph/shortest_path_faster_algorithm.hpp.html">Shortest Path Faster Algorithm</a>
* :warning: <a href="../modulus/choose.hpp.html">modulus/choose.hpp</a>
* :heavy_check_mark: <a href="../number/fast_fourier_transformation.hpp.html">the convolution</a>
* :heavy_check_mark: <a href="../number/formal_power_series.hpp.html">number/formal_power_series.hpp</a>
* :heavy_check_mark: <a href="../number/lagrange_interpolation.hpp.html">Lagrange interpolation</a>
* :heavy_check_mark: <a href="../number/number_theoretic_transformation.hpp.html">a specialized version of Garner's algorithm</a>
* :heavy_check_mark: <a href="../number/primes.hpp.html">number/primes.hpp</a>
* :warning: <a href="dsu_on_tree.hpp.html">utils/dsu_on_tree.hpp</a>
* :warning: <a href="fast_zeta_transform.hpp.html">upward fast zeta transform on primes</a>


## Verified With
* :heavy_check_mark: <a href="../../verify/data_structure/convex_hull_trick.test.cpp.html">data_structure/convex_hull_trick.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/fully_indexable_dictionary.test.cpp.html">data_structure/fully_indexable_dictionary.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_segment_tree.unit.test.cpp.html">data_structure/lazy_propagation_segment_tree.unit.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/li_chao_tree.test.cpp.html">data_structure/li_chao_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.marked_ancestor.test.cpp.html">data_structure/link_cut_tree.marked_ancestor.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.spaceships.test.cpp.html">data_structure/link_cut_tree.spaceships.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html">data_structure/segment_tree.point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sliding_window_aggregation.test.cpp.html">data_structure/sliding_window_aggregation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sparse_table.unit.test.cpp.html">data_structure/sparse_table.unit.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/wavelet_matrix.test.cpp.html">data_structure/wavelet_matrix.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/bellman_ford.test.cpp.html">graph/bellman_ford.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/lowest_common_ancestor.aoj.test.cpp.html">graph/lowest_common_ancestor.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/shortest_path_faster_algorithm.test.cpp.html">graph/shortest_path_faster_algorithm.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/shortest_path_faster_algorithm.unit.test.cpp.html">graph/shortest_path_faster_algorithm.unit.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/fast_fourier_transformation.unit.test.cpp.html">number/fast_fourier_transformation.unit.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/formal_power_series.exp.test.cpp.html">number/formal_power_series.exp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/formal_power_series.inv.test.cpp.html">number/formal_power_series.inv.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/formal_power_series.log.test.cpp.html">number/formal_power_series.log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/lagrange_interpolation.test.cpp.html">number/lagrange_interpolation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/number_theoretic_transformation.998244353.test.cpp.html">number/number_theoretic_transformation.998244353.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/primes.aoj.test.cpp.html">number/primes.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/utils/binary_search.aoj.test.cpp.html">utils/binary_search.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/utils/binary_search.unit.test.cpp.html">utils/binary_search.unit.test.cpp</a>


## Code
{% raw %}
```cpp
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

