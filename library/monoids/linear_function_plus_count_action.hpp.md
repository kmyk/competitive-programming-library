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


# :heavy_check_mark: monoids/linear_function_plus_count_action.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/linear_function_plus_count_action.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 19:16:13+09:00




## Depends on

* :heavy_check_mark: <a href="linear_function.hpp.html">monoids/linear_function.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp.html">data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>
#include "monoids/linear_function.hpp"

/**
 * @note lazy_propagation_segment_tree<plus_count_monoid<T>, linear_function_monoid<T>, linear_function_plus_count_action<T> >
 */
template <class T>
struct linear_function_plus_count_action {
    typename plus_count_monoid<T>::value_type operator () (typename linear_function_monoid<T>::value_type f, typename plus_count_monoid<T>::value_type x) const {
        return std::make_pair(f.first * x.first + f.second * x.second, x.second);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/linear_function_plus_count_action.hpp"
#include <utility>
#line 2 "monoids/linear_function.hpp"
#include <utility>

template <class CommutativeRing>
struct linear_function_monoid {
    typedef std::pair<CommutativeRing, CommutativeRing> value_type;
    linear_function_monoid() = default;
    value_type unit() const {
        return std::make_pair(1, 0);
    }
    value_type mult(value_type g, value_type f) const {
        CommutativeRing fst = g.first * f.first;
        CommutativeRing snd = g.second + g.first * f.second;
        return std::make_pair(fst, snd);
    }
};
#line 4 "monoids/linear_function_plus_count_action.hpp"

/**
 * @note lazy_propagation_segment_tree<plus_count_monoid<T>, linear_function_monoid<T>, linear_function_plus_count_action<T> >
 */
template <class T>
struct linear_function_plus_count_action {
    typename plus_count_monoid<T>::value_type operator () (typename linear_function_monoid<T>::value_type f, typename plus_count_monoid<T>::value_type x) const {
        return std::make_pair(f.first * x.first + f.second * x.second, x.second);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

