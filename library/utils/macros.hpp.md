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

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/macros.hpp">View this file on GitHub</a>
    - Last commit date: 2019-06-03 23:38:29 +0900




## Required by

* :warning: <a href="../data_structure/convex_hull_trick.random-test.cpp.html">data_structure/convex_hull_trick.random-test.cpp</a>
* :heavy_check_mark: <a href="../data_structure/fully_indexable_dictionary.hpp.html">a fully indexable dictionary <small>(data_structure/fully_indexable_dictionary.hpp)</small></a>
* :warning: <a href="../data_structure/fully_indexable_dictionary.random-test.cpp.html">data_structure/fully_indexable_dictionary.random-test.cpp</a>
* :heavy_check_mark: <a href="../data_structure/lazy_propagation_segment_tree.hpp.html">a lazy propagation segment tree / 遅延伝播セグメント木 <small>(data_structure/lazy_propagation_segment_tree.hpp)</small></a>
* :warning: <a href="../data_structure/lazy_propagation_segment_tree.unit.random-test.cpp.html">data_structure/lazy_propagation_segment_tree.unit.random-test.cpp</a>
* :warning: <a href="../data_structure/li_chao_tree.hpp.html">data_structure/li_chao_tree.hpp</a>
* :warning: <a href="../data_structure/li_chao_tree.random-test.cpp.html">data_structure/li_chao_tree.random-test.cpp</a>
* :heavy_check_mark: <a href="../data_structure/link_cut_tree.hpp.html">an extended structure of union-find tree <small>(data_structure/link_cut_tree.hpp)</small></a>
* :warning: <a href="../data_structure/link_cut_tree.spaceships.random-test.cpp.html">data_structure/link_cut_tree.spaceships.random-test.cpp</a>
* :warning: <a href="../data_structure/sliding_window_aggregation.hpp.html">get sum of elements in the queue <small>(data_structure/sliding_window_aggregation.hpp)</small></a>
* :warning: <a href="../data_structure/sliding_window_aggregation.random-test.cpp.html">data_structure/sliding_window_aggregation.random-test.cpp</a>
* :heavy_check_mark: <a href="../data_structure/sparse_table.hpp.html">sparse table on a semilattice <small>(data_structure/sparse_table.hpp)</small></a>
* :warning: <a href="../data_structure/sparse_table.unit.random-test.cpp.html">data_structure/sparse_table.unit.random-test.cpp</a>
* :heavy_check_mark: <a href="../data_structure/wavelet_matrix.hpp.html">a wavelet matrix <small>(data_structure/wavelet_matrix.hpp)</small></a>
* :warning: <a href="../data_structure/wavelet_matrix.random-test.cpp.html">data_structure/wavelet_matrix.random-test.cpp</a>
* :heavy_check_mark: <a href="../graph/bellman_ford.hpp.html">Bellman-Ford algorithm <small>(graph/bellman_ford.hpp)</small></a>
* :heavy_check_mark: <a href="../graph/lowest_common_ancestor.hpp.html">lowest common ancestor with $\pm$ 1 RMQ and sparse table <small>(graph/lowest_common_ancestor.hpp)</small></a>
* :warning: <a href="../graph/shortest_path_faster_algorithm.hpp.html">Shortest Path Faster Algorithm <small>(graph/shortest_path_faster_algorithm.hpp)</small></a>
* :warning: <a href="../graph/shortest_path_faster_algorithm.random-test.cpp.html">graph/shortest_path_faster_algorithm.random-test.cpp</a>
* :warning: <a href="../graph/shortest_path_faster_algorithm.unit.random-test.cpp.html">graph/shortest_path_faster_algorithm.unit.random-test.cpp</a>
* :warning: <a href="../modulus/choose.hpp.html">modulus/choose.hpp</a>
* :warning: <a href="../number/fast_fourier_transformation.hpp.html">the convolution <small>(number/fast_fourier_transformation.hpp)</small></a>
* :warning: <a href="../number/fast_fourier_transformation.unit.random-test.cpp.html">number/fast_fourier_transformation.unit.random-test.cpp</a>
* :heavy_check_mark: <a href="../number/formal_power_series.hpp.html">number/formal_power_series.hpp</a>
* :warning: <a href="../number/lagrange_interpolation.hpp.html">Lagrange interpolation <small>(number/lagrange_interpolation.hpp)</small></a>
* :warning: <a href="../number/lagrange_interpolation.random-test.cpp.html">number/lagrange_interpolation.random-test.cpp</a>
* :heavy_check_mark: <a href="../number/number_theoretic_transformation.hpp.html">a specialized version of Garner's algorithm <small>(number/number_theoretic_transformation.hpp)</small></a>
* :heavy_check_mark: <a href="../number/primes.hpp.html">number/primes.hpp</a>
* :warning: <a href="binary_search.unit.random-test.cpp.html">utils/binary_search.unit.random-test.cpp</a>
* :heavy_check_mark: <a href="dsu_on_tree.hpp.html">DSU on tree (sack) <small>(utils/dsu_on_tree.hpp)</small></a>
* :warning: <a href="fast_zeta_transform.hpp.html">upward fast zeta transform on primes <small>(utils/fast_zeta_transform.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.marked_ancestor.test.cpp.html">data_structure/link_cut_tree.marked_ancestor.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html">data_structure/segment_tree.point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/wavelet_matrix.aoj2674.test.cpp.html">data_structure/wavelet_matrix.aoj2674.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/wavelet_matrix.rectangle_sum.test.cpp.html">data_structure/wavelet_matrix.rectangle_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/bellman_ford.test.cpp.html">graph/bellman_ford.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/lowest_common_ancestor.aoj.test.cpp.html">graph/lowest_common_ancestor.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/formal_power_series.exp.test.cpp.html">number/formal_power_series.exp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/formal_power_series.inv.test.cpp.html">number/formal_power_series.inv.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/formal_power_series.log.test.cpp.html">number/formal_power_series.log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/number_theoretic_transformation.998244353.test.cpp.html">number/number_theoretic_transformation.998244353.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/number/primes.aoj.test.cpp.html">number/primes.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/utils/binary_search.aoj.test.cpp.html">utils/binary_search.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/utils/dsu_on_tree.aoj.test.cpp.html">utils/dsu_on_tree.aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

