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


# :x: monoids/plus_min_action.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/plus_min_action.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 19:16:13+09:00




## Depends on

* :x: <a href="min.hpp.html">monoids/min.hpp</a>
* :heavy_check_mark: <a href="plus.hpp.html">monoids/plus.hpp</a>


## Verified with

* :x: <a href="../../verify/data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "monoids/plus.hpp"
#include "monoids/min.hpp"

template <class T>
struct plus_min_action {
    typename min_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename min_monoid<T>::value_type x) const {
        return (x == min_monoid<T>().unit() ? x : f + x);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/plus.hpp"

template <class T>
struct plus_monoid {
    typedef T value_type;
    value_type unit() const { return value_type(); }
    value_type mult(value_type a, value_type b) const { return a + b; }
};
#line 2 "monoids/min.hpp"
#include <algorithm>
#include <limits>

template <class T>
struct min_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::max(); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};
#line 4 "monoids/plus_min_action.hpp"

template <class T>
struct plus_min_action {
    typename min_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename min_monoid<T>::value_type x) const {
        return (x == min_monoid<T>().unit() ? x : f + x);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

