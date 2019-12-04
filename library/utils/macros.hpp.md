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


# :warning: utils/macros.hpp
* category: utils


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [data_structure/fully_indexable_dictionary.hpp](../data_structure/fully_indexable_dictionary.hpp.html)
* :heavy_check_mark: [data_structure/lazy_propagation_segment_tree.hpp](../data_structure/lazy_propagation_segment_tree.hpp.html)
* :heavy_check_mark: [data_structure/li_chao_tree.hpp](../data_structure/li_chao_tree.hpp.html)
* :heavy_check_mark: [data_structure/link_cut_tree.hpp](../data_structure/link_cut_tree.hpp.html)
* :heavy_check_mark: [data_structure/sliding_window_aggregation.hpp](../data_structure/sliding_window_aggregation.hpp.html)
* :heavy_check_mark: [data_structure/sparse_table.hpp](../data_structure/sparse_table.hpp.html)
* :heavy_check_mark: [data_structure/wavelet_matrix.hpp](../data_structure/wavelet_matrix.hpp.html)
* :heavy_check_mark: [graph/bellman_ford.hpp](../graph/bellman_ford.hpp.html)
* :heavy_check_mark: [graph/shortest_path_faster_algorithm.hpp](../graph/shortest_path_faster_algorithm.hpp.html)
* :warning: [modulus/choose.hpp](../modulus/choose.hpp.html)
* :heavy_check_mark: [number/fast_fourier_transformation.hpp](../number/fast_fourier_transformation.hpp.html)
* :heavy_check_mark: [number/formal_power_series.hpp](../number/formal_power_series.hpp.html)
* :heavy_check_mark: [number/lagrange_interpolation.hpp](../number/lagrange_interpolation.hpp.html)
* :heavy_check_mark: [number/number_theoretic_transformation.hpp](../number/number_theoretic_transformation.hpp.html)
* :heavy_check_mark: [number/primes.hpp](../number/primes.hpp.html)
* :warning: [utils/dsu_on_tree.hpp](dsu_on_tree.hpp.html)
* :warning: [utils/fast_zeta_transform.hpp](fast_zeta_transform.hpp.html)


## Verified
* :heavy_check_mark: [data_structure/convex_hull_trick.test.cpp](../../verify/data_structure/convex_hull_trick.test.cpp.html)
* :heavy_check_mark: [data_structure/fully_indexable_dictionary.test.cpp](../../verify/data_structure/fully_indexable_dictionary.test.cpp.html)
* :heavy_check_mark: [data_structure/lazy_propagation_segment_tree.unit.test.cpp](../../verify/data_structure/lazy_propagation_segment_tree.unit.test.cpp.html)
* :heavy_check_mark: [data_structure/li_chao_tree.test.cpp](../../verify/data_structure/li_chao_tree.test.cpp.html)
* :heavy_check_mark: [data_structure/link_cut_tree.marked_ancestor.test.cpp](../../verify/data_structure/link_cut_tree.marked_ancestor.test.cpp.html)
* :heavy_check_mark: [data_structure/segment_tree.point_set_range_composite.test.cpp](../../verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html)
* :heavy_check_mark: [data_structure/sliding_window_aggregation.test.cpp](../../verify/data_structure/sliding_window_aggregation.test.cpp.html)
* :heavy_check_mark: [data_structure/wavelet_matrix.test.cpp](../../verify/data_structure/wavelet_matrix.test.cpp.html)
* :heavy_check_mark: [graph/bellman_ford.test.cpp](../../verify/graph/bellman_ford.test.cpp.html)
* :heavy_check_mark: [graph/shortest_path_faster_algorithm.unit.test.cpp](../../verify/graph/shortest_path_faster_algorithm.unit.test.cpp.html)
* :heavy_check_mark: [number/fast_fourier_transformation.unit.test.cpp](../../verify/number/fast_fourier_transformation.unit.test.cpp.html)
* :heavy_check_mark: [number/formal_power_series.exp.test.cpp](../../verify/number/formal_power_series.exp.test.cpp.html)
* :heavy_check_mark: [number/formal_power_series.inv.test.cpp](../../verify/number/formal_power_series.inv.test.cpp.html)
* :heavy_check_mark: [number/formal_power_series.log.test.cpp](../../verify/number/formal_power_series.log.test.cpp.html)
* :heavy_check_mark: [number/number_theoretic_transformation.998244353.test.cpp](../../verify/number/number_theoretic_transformation.998244353.test.cpp.html)
* :heavy_check_mark: [utils/binary_search.aoj.test.cpp](../../verify/utils/binary_search.aoj.test.cpp.html)
* :heavy_check_mark: [utils/binary_search.unit.test.cpp](../../verify/utils/binary_search.unit.test.cpp.html)


## Code
```cpp
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)

```

[Back to top page](../../index.html)

