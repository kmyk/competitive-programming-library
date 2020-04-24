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


# :heavy_check_mark: monoids/gcd.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/gcd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 23:33:38+09:00




## Depends on

* :heavy_check_mark: <a href="../number/gcd.hpp.html">number/gcd.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/sparse_table.yukicoder-1036.test.cpp.html">data_structure/sparse_table.yukicoder-1036.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "number/gcd.hpp"

/**
 * @note a semilattice
 */
template <class Integer>
struct gcd_monoid {
    typedef Integer value_type;
    Integer unit() const { return 0; }
    Integer mult(Integer a, Integer b) const { return gcd(a, b); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "number/gcd.hpp"
#include <algorithm>

/**
 * @note if arguments are negative, the result may be negative
 */
template <typename T>
T gcd(T a, T b) {
    while (a) {
        b %= a;
        std::swap(a, b);
    }
    return b;
}

template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
#line 3 "monoids/gcd.hpp"

/**
 * @note a semilattice
 */
template <class Integer>
struct gcd_monoid {
    typedef Integer value_type;
    Integer unit() const { return 0; }
    Integer mult(Integer a, Integer b) const { return gcd(a, b); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

