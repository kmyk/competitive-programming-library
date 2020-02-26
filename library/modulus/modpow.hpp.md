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


# :heavy_check_mark: modulus/modpow.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/modpow.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-26 23:56:34+09:00




## Required by

* :heavy_check_mark: <a href="bell_number.hpp.html">the Bell number <small>(modulus/bell_number.hpp)</small></a>
* :heavy_check_mark: <a href="choose.hpp.html">combination / 組合せ ${} _ n C _ r$ (前処理 $O(n)$ + $O(1)$) <small>(modulus/choose.hpp)</small></a>
* :warning: <a href="choose_simple.hpp.html">combination / 組合せ ${} _ n C _ r$ (愚直 $O(r)$) <small>(modulus/choose_simple.hpp)</small></a>
* :heavy_check_mark: <a href="factorial.hpp.html">modulus/factorial.hpp</a>
* :heavy_check_mark: <a href="formal_power_series.hpp.html">formal power series / 形式的羃級数環 $\mathbb{Z}/n\mathbb{Z}\lbrack\lbrack x\rbrack\rbrack$ <small>(modulus/formal_power_series.hpp)</small></a>
* :warning: <a href="garner.hpp.html">Garner's algorithm <small>(modulus/garner.hpp)</small></a>
* :heavy_check_mark: <a href="mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="modlog.hpp.html">discrete log / 離散対数 (the baby-step giant-step, $O(\sqrt{m})$) <small>(modulus/modlog.hpp)</small></a>
* :heavy_check_mark: <a href="modsqrt.hpp.html">find the sqrt $b$ of $a$ modulo $p$ <small>(modulus/modsqrt.hpp)</small></a>
* :heavy_check_mark: <a href="multichoose.hpp.html">重複組合せ ${} _ n H _ r = {} _ {n + r - 1} C _ r$ (前処理 $O(n)$ + $O(1)$) <small>(modulus/multichoose.hpp)</small></a>
* :heavy_check_mark: <a href="number_theoretic_transformation.hpp.html">Number Theoretic Transformation (NTT) for Proth primes <small>(modulus/number_theoretic_transformation.hpp)</small></a>
* :heavy_check_mark: <a href="number_theoretic_transformation_with_garner.hpp.html">multiprecation on $\mathbb{Z}/n\mathbb{Z}\[x\]$ <small>(modulus/number_theoretic_transformation_with_garner.hpp)</small></a>
* :heavy_check_mark: <a href="permute.hpp.html">permutation / 順列 ${} _ n P _ r$ (前処理 $O(n)$ + $O(1)$) <small>(modulus/permute.hpp)</small></a>
* :heavy_check_mark: <a href="stirling_number_of_the_second_kind.hpp.html">the Stirling number of the second kind <small>(modulus/stirling_number_of_the_second_kind.hpp)</small></a>
* :heavy_check_mark: <a href="twelvefold_way.hpp.html">twelvefold way / 写像12相 <small>(modulus/twelvefold_way.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.vertex_set_path_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html">data_structure/segment_tree.point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sliding_window_aggregation.yosupo.test.cpp.html">data_structure/sliding_window_aggregation.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/tree_decomposition.aoj_2405.test.cpp.html">graph/tree_decomposition.aoj_2405.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.exp.test.cpp.html">modulus/formal_power_series.exp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.inv.test.cpp.html">modulus/formal_power_series.inv.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/formal_power_series.log.test.cpp.html">modulus/formal_power_series.log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/modlog.yosupo.test.cpp.html">modulus/modlog.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/modsqrt.yosupo.test.cpp.html">modulus/modsqrt.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/number_theoretic_transformation.yosupo.test.cpp.html">modulus/number_theoretic_transformation.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp.html">modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_1.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_1.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_11.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_11.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_2.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_2.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_3.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_3.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_4.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_4.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_5.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_5.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_6.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_6.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_7.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_7.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_8.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_8.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/twelvefold_way.balls_and_boxes_9.test.cpp.html">modulus/twelvefold_way.balls_and_boxes_9.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modulus/modpow.hpp"
#include <cassert>

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
