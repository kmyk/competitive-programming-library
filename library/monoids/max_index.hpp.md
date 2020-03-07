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


# VerificationStatus.DEFAULT monoids/max_index.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/max_index.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-11 22:02:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <climits>
#include <limits>
#include <utility>

/**
 * @note a semilattice
 */
template <class T>
struct max_index_monoid {
    typedef std::pair<T, int> value_type;
    value_type unit() const { return std::make_pair(std::numeric_limits<T>::lowest(), INT_MIN); }
    value_type mult(value_type a, value_type b) const { return std::max(a, b); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/max_index.hpp"
#include <algorithm>
#include <climits>
#include <limits>
#include <utility>

/**
 * @note a semilattice
 */
template <class T>
struct max_index_monoid {
    typedef std::pair<T, int> value_type;
    value_type unit() const { return std::make_pair(std::numeric_limits<T>::lowest(), INT_MIN); }
    value_type mult(value_type a, value_type b) const { return std::max(a, b); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

