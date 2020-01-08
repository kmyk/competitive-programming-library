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


# :warning: monoids/chmin_chmax_add_min_max_action.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/chmin_chmax_add_min_max_action.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 14:04:37+09:00




## Depends on

* :warning: <a href="chmin_chmax_add.hpp.html">monoids/chmin_chmax_add.hpp</a>
* :warning: <a href="min_max.hpp.html">monoids/min_max.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include "monoids/chmin_chmax_add.hpp"
#include "monoids/min_max.hpp"

template <class T>
struct chmin_chmax_add_min_max_action {
    typedef typename chmin_chmax_add_monoid<T>::value_type F;
    typedef typename min_max_monoid<T>::value_type X;
    X operator () (F f, X x) const {
        if (x.first == std::numeric_limits<T>::max()) {
            assert (x.second == std::numeric_limits<T>::lowest());
            return x;
        }
        T a = std::min(f.chmin, std::max(f.chmax, f.add + x.first));
        T b = std::min(f.chmin, std::max(f.chmax, f.add + x.second));
        return std::make_pair(a, b);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/chmin_chmax_add_min_max_action.hpp"
#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#line 2 "monoids/chmin_chmax_add.hpp"
#include <algorithm>
#include <numeric>
#include <utility>

/**
 * @note represents the monoid $M = (\lbrace \lambda x. \min(a, \max(b, c + x)) \mid a, b, c \rbrace, \circ, \mathrm{id})$
 */
template <class T>
struct chmin_chmax_add_monoid {
    static constexpr MAX = std::numeric_limits<T>::max();
    static constexpr MIN = std::numeric_limits<T>::lowest();
    struct value_type {
        long long chmin;
        long long chmax;
        long long add;
    };
    value_type unit() const {
        return (value_type) { MAX, MIN, 0 };
    }
    value_type mult(value_type a, value_type b) const {
        value_type c = b;
        // add
        if (c.chmin != MAX) {
            c.chmin += a.add;
        }
        if (c.chmax != MIN) {
            c.chmax += a.add;
        }
        c.add += a.add;
        // chmax
        c.chmin = std::max(a.chmax, c.chmin);
        c.chmax = std::max(a.chmax, c.chmax);
        // chmin
        c.chmin = std::min(a.chmin, c.chmin);
        return c;
    }
    static value_type chmin(T value) {
        return (value_type) { value, MIN, 0 };
    }
    static value_type chmin(T value) {
        return (value_type) { MAX, value, 0 };
    }
    static value_type chmin(T value) {
        return (value_type) { MAX, MIN, value };
    }
};
#line 2 "monoids/min_max.hpp"
#include <algorithm>
#include <numeric>
#include <utility>

template <class T>
struct min_max_monoid {
    typedef std::pair<T, T> value_type;
    value_type unit() const {
        return std::make_pair(std::numeric_limits<T>::max(), std::numeric_limits<T>::lowest());
    }
    value_type mult(value_type a, value_type b) const {
        return std::make_pair(std::min(a.min, b.min), std::max(a.max, b.max));
    }
};
#line 8 "monoids/chmin_chmax_add_min_max_action.hpp"

template <class T>
struct chmin_chmax_add_min_max_action {
    typedef typename chmin_chmax_add_monoid<T>::value_type F;
    typedef typename min_max_monoid<T>::value_type X;
    X operator () (F f, X x) const {
        if (x.first == std::numeric_limits<T>::max()) {
            assert (x.second == std::numeric_limits<T>::lowest());
            return x;
        }
        T a = std::min(f.chmin, std::max(f.chmax, f.add + x.first));
        T b = std::min(f.chmin, std::max(f.chmax, f.add + x.second));
        return std::make_pair(a, b);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

