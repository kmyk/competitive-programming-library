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


# VerificationStatus.DEFAULT monoids/plus_min_count_action.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/plus_min_count_action.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 19:16:13+09:00




## Depends on

* :warning: <a href="min_count.hpp.html">monoids/min_count.hpp</a>
* :heavy_check_mark: <a href="plus.hpp.html">monoids/plus.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>
#include "monoids/plus.hpp"
#include "monoids/min_count.hpp"

/**
 * @note lazy_propagation_segment_tree<min_count_monoid<T>, plus_monoid<T>, plus_min_count_action<T> > can count a number of zeros (or, non-zero numbers) in the array
 */
template <class T>
struct plus_min_count_action {
    typename min_count_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename min_count_monoid<T>::value_type x) const {
        if (x.first == min_count_monoid<T>().unit().first) return x;
        return std::make_pair(f + x.first, x.second);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/plus_min_count_action.hpp"
#include <utility>
#line 2 "monoids/plus.hpp"

template <class T>
struct plus_monoid {
    typedef T value_type;
    value_type unit() const { return value_type(); }
    value_type mult(value_type a, value_type b) const { return a + b; }
};
#line 2 "monoids/min_count.hpp"
#include <limits>
#line 4 "monoids/min_count.hpp"

template <class T>
struct min_count_monoid {
    typedef std::pair<T, int> value_type;
    value_type unit() const {
        return std::make_pair(std::numeric_limits<T>::max(), 0);
    }
    value_type mult(value_type a, value_type b) const {
        if (a.first < b.first) return a;
        if (a.first > b.first) return b;
        return std::make_pair(a.first, a.second + b.second);
    }
    static value_type make(T a) {
        return std::make_pair(a, 1);
    }
};
#line 5 "monoids/plus_min_count_action.hpp"

/**
 * @note lazy_propagation_segment_tree<min_count_monoid<T>, plus_monoid<T>, plus_min_count_action<T> > can count a number of zeros (or, non-zero numbers) in the array
 */
template <class T>
struct plus_min_count_action {
    typename min_count_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename min_count_monoid<T>::value_type x) const {
        if (x.first == min_count_monoid<T>().unit().first) return x;
        return std::make_pair(f + x.first, x.second);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

