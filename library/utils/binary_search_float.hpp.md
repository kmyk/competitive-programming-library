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


# :warning: a binary search on floating point numbers / 二分探索 (浮動小数点数) <small>(utils/binary_search_float.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/binary_search_float.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-23 03:04:39+09:00




## Depends on

* :question: <a href="macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include "utils/macros.hpp"

/**
 * @brief a binary search on floating point numbers / 二分探索 (浮動小数点数)
 */
template <int Iteration = 64, typename UnaryPredicate>
double binsearch_float(double l, double r, UnaryPredicate p) {
    assert (l <= r);
    REP (i, Iteration) {
        double m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/binary_search_float.hpp"
#include <cassert>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 4 "utils/binary_search_float.hpp"

/**
 * @brief a binary search on floating point numbers / 二分探索 (浮動小数点数)
 */
template <int Iteration = 64, typename UnaryPredicate>
double binsearch_float(double l, double r, UnaryPredicate p) {
    assert (l <= r);
    REP (i, Iteration) {
        double m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

