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


# :heavy_check_mark: modulus/modinv.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/modinv.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-16 07:51:56+09:00




## Required by

* :heavy_check_mark: <a href="bell_number.hpp.html">the Bell number (前処理 $O(NK)$ + $O(1)$) <small>(modulus/bell_number.hpp)</small></a>
* :heavy_check_mark: <a href="choose.hpp.html">combination / 組合せ ${} _ n C _ r$ (前処理 $O(n)$ + $O(1)$) <small>(modulus/choose.hpp)</small></a>
* :warning: <a href="choose_simple.hpp.html">combination / 組合せ ${} _ n C _ r$ (愚直 $O(r)$) <small>(modulus/choose_simple.hpp)</small></a>
* :heavy_check_mark: <a href="factorial.hpp.html">modulus/factorial.hpp</a>
* :heavy_check_mark: <a href="formal_power_series.hpp.html">formal power series / 形式的羃級数環 $\mathbb{Z}/n\mathbb{Z}\lbrack\lbrack x\rbrack\rbrack$ <small>(modulus/formal_power_series.hpp)</small></a>
* :warning: <a href="garner.hpp.html">Garner's algorithm <small>(modulus/garner.hpp)</small></a>
* :heavy_check_mark: <a href="mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="modlog.hpp.html">discrete log / 離散対数 (the baby-step giant-step, $O(\sqrt{m})$) <small>(modulus/modlog.hpp)</small></a>
* :heavy_check_mark: <a href="multichoose.hpp.html">重複組合せ ${} _ n H _ r = {} _ {n + r - 1} C _ r$ (前処理 $O(n)$ + $O(1)$) <small>(modulus/multichoose.hpp)</small></a>
* :warning: <a href="multichoose_simple.hpp.html">重複組合せ ${} _ n H _ r = {} _ {n + r - 1} C _ r$ (愚直 $O(r)$) <small>(modulus/multichoose_simple.hpp)</small></a>
* :heavy_check_mark: <a href="number_theoretic_transformation.hpp.html">Number Theoretic Transformation (NTT) for Proth primes <small>(modulus/number_theoretic_transformation.hpp)</small></a>
* :heavy_check_mark: <a href="number_theoretic_transformation_with_garner.hpp.html">multiprecation on $\mathbb{Z}/n\mathbb{Z}\[x\]$ <small>(modulus/number_theoretic_transformation_with_garner.hpp)</small></a>
* :heavy_check_mark: <a href="partition_number.hpp.html">the partition number (前処理 $O(NK)$ + $O(1)$) <small>(modulus/partition_number.hpp)</small></a>
* :heavy_check_mark: <a href="permute.hpp.html">permutation / 順列 ${} _ n P _ r$ (前処理 $O(n)$ + $O(1)$) <small>(modulus/permute.hpp)</small></a>
* :heavy_check_mark: <a href="stirling_number_of_the_second_kind_convolution.hpp.html">the Stirling number of the second kind (for given $N$, compute $S(N, \ast)$ in $O(N \log N)$) <small>(modulus/stirling_number_of_the_second_kind_convolution.hpp)</small></a>
* :heavy_check_mark: <a href="stirling_number_of_the_second_kind_direct.hpp.html">the Stirling number of the second kind ($O(K \log N)$) <small>(modulus/stirling_number_of_the_second_kind_direct.hpp)</small></a>
* :heavy_check_mark: <a href="stirling_number_of_the_second_kind_table.hpp.html">the Stirling number of the second kind (前処理 $O(NK)$ + $O(1)$) <small>(modulus/stirling_number_of_the_second_kind_table.hpp)</small></a>
* :heavy_check_mark: <a href="twelvefold_way.hpp.html">twelvefold way / 写像12相 <small>(modulus/twelvefold_way.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp.html">data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.vertex_set_path_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html">data_structure/segment_tree.point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sliding_window_aggregation.yosupo.test.cpp.html">data_structure/sliding_window_aggregation.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/tree_decomposition.aoj_2405.test.cpp.html">graph/tree_decomposition.aoj_2405.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/choose.yukicoder-1035.test.cpp.html">modulus/choose.yukicoder-1035.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.exp.test.cpp.html">modulus/formal_power_series.exp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.inv.test.cpp.html">modulus/formal_power_series.inv.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.log.test.cpp.html">modulus/formal_power_series.log.test.cpp</a>
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
* :heavy_check_mark: <a href="../../verify/number/matrix_template.yukicoder-1073.test.cpp.html">number/matrix_template.yukicoder-1073.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>

inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    if (value == 0) return -1;
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    if (not (value * x + MOD * y == b and b == 1)) return -1;
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

inline int32_t modinv(int32_t x, int32_t MOD) {
    int32_t y = modinv_nocheck(x, MOD);
    assert (y != -1);
    return y;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modulus/modinv.hpp"
#include <algorithm>
#include <cassert>
#include <cstdint>

inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    if (value == 0) return -1;
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    if (not (value * x + MOD * y == b and b == 1)) return -1;
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

inline int32_t modinv(int32_t x, int32_t MOD) {
    int32_t y = modinv_nocheck(x, MOD);
    assert (y != -1);
    return y;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

