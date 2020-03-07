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


# VerificationStatus.VERIFIED monoids/dual.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/dual.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-19 00:15:23+09:00


* see: <a href="http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual">http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.vertex_set_path_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html">data_structure/segment_tree.point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sliding_window_aggregation.yosupo.test.cpp.html">data_structure/sliding_window_aggregation.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @see http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual
 */
template <class Monoid>
struct dual_monoid {
    typedef typename Monoid::value_type value_type;
    Monoid base;
    value_type unit() const { return base.unit(); }
    value_type mult(const value_type & a, const value_type & b) const { return base.mult(b, a); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/dual.hpp"

/**
 * @see http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual
 */
template <class Monoid>
struct dual_monoid {
    typedef typename Monoid::value_type value_type;
    Monoid base;
    value_type unit() const { return base.unit(); }
    value_type mult(const value_type & a, const value_type & b) const { return base.mult(b, a); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

