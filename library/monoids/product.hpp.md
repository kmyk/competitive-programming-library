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


# :warning: monoids/product.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/product.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 19:38:00+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

template <class Monoid1, class Monoid2>
struct productt_monoid {
    typedef std::pair<typename Monoid1::value_type, typename Monoid2::value_type> value_type;
    Monoid1 mon1;
    Monoid2 mon2;
    value_type unit() const {
        return std::make_pair(mon1.unit(), mon2.unit());
    }
    value_type mult(value_type a, value_type b) const {
        return std::make_pair(mon1.mult(a.first, b.first), mon2.mult(a.second, b.second));
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/product.hpp"
#include <utility>

template <class Monoid1, class Monoid2>
struct productt_monoid {
    typedef std::pair<typename Monoid1::value_type, typename Monoid2::value_type> value_type;
    Monoid1 mon1;
    Monoid2 mon2;
    value_type unit() const {
        return std::make_pair(mon1.unit(), mon2.unit());
    }
    value_type mult(value_type a, value_type b) const {
        return std::make_pair(mon1.mult(a.first, b.first), mon2.mult(a.second, b.second));
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

