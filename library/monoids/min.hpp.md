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


# :heavy_check_mark: monoids/min.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/min.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 19:16:13+09:00




## Required by

* :heavy_check_mark: <a href="plus_min_action.hpp.html">monoids/plus_min_action.hpp</a>
* :heavy_check_mark: <a href="../string/longest_common_prefix.hpp.html">Longest Common Prefix / 最長共通接頭辞 (接尾辞配列, 前処理 $O(N (\log N)^2)$ + $O(1)$) <small>(string/longest_common_prefix.hpp)</small></a>
* :heavy_check_mark: <a href="../utils/greedily_increasing_subsequence.hpp.html">Length of Greedily Increasing Subsequences (前処理 $O(n \log n)$ + $O(1)$) <small>(utils/greedily_increasing_subsequence.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sparse_table.yosupo.test.cpp.html">data_structure/sparse_table.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/cartesian_tree.yukicoder-1031.test.cpp.html">graph/cartesian_tree.yukicoder-1031.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/string/longest_common_prefix.yosupo.test.cpp.html">string/longest_common_prefix.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <limits>

template <class T>
struct min_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::max(); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/min.hpp"
#include <algorithm>
#include <limits>

template <class T>
struct min_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::max(); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

