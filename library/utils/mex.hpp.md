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


# :warning: Minimum Excluded Value ($O(n)$ for a given sorted container) <small>(utils/mex.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/mex.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-27 01:00:36+09:00


* see: <a href="https://en.wikipedia.org/wiki/Mex_(mathematics)">https://en.wikipedia.org/wiki/Mex_(mathematics)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>

/**
 * @brief Minimum Excluded Value ($O(n)$ for a given sorted container)
 * @sa https://en.wikipedia.org/wiki/Mex_(mathematics)
 * @note xs must be weakly increasing
 */
template <typename InputIterator>
int mex(InputIterator first, InputIterator last) {
    int last_x = 0;  // only for debug
    int y = 0;
    for (; first != last; ++ first) {
        int x = *first;
        assert (last_x <= x);
        last_x = x;
        if (y < x) break;
        if (y == x) ++ y;
    }
    return y;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/mex.hpp"
#include <cassert>

/**
 * @brief Minimum Excluded Value ($O(n)$ for a given sorted container)
 * @sa https://en.wikipedia.org/wiki/Mex_(mathematics)
 * @note xs must be weakly increasing
 */
template <typename InputIterator>
int mex(InputIterator first, InputIterator last) {
    int last_x = 0;  // only for debug
    int y = 0;
    for (; first != last; ++ first) {
        int x = *first;
        assert (last_x <= x);
        last_x = x;
        if (y < x) break;
        if (y == x) ++ y;
    }
    return y;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

