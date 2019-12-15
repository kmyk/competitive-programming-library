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


# :heavy_check_mark: a binary search / 二分探索 <small>(utils/binary_search.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/binary_search.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900




## Required by

* :warning: <a href="binary_search.unit.random-test.cpp.html">utils/binary_search.unit.random-test.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/utils/binary_search.aoj.test.cpp.html">utils/binary_search.aoj.test.cpp</a>


## Code

{% raw %}
```cpp
#pragma once
#include <cassert>
#include <cstdint>

/**
 * @brief a binary search / 二分探索
 * @param[in] p  a monotone predicate defined on $[l, r)$
 * @return $\min \lbrace x \in [l, r) \mid p(x) \rbrace$, or r if it doesn't exist
 */
template <typename UnaryPredicate>
int64_t binsearch(int64_t l, int64_t r, UnaryPredicate p) {
    assert (l <= r);
    -- l;
    while (r - l > 1) {
        int64_t m = l + (r - l) / 2;
        (p(m) ? r : l) = m;
    }
    return r;
}

/**
 * @return $\max \lbrace x \in (l, r] \mid p(x) \rbrace$, or l if it doesn't exist
 */
template <typename UnaryPredicate>
int64_t binsearch_max(int64_t l, int64_t r, UnaryPredicate p) {
    assert (l <= r);
    ++ r;
    while (r - l > 1) {
        int64_t m = l + (r - l) / 2;
        (p(m) ? l : r) = m;
    }
    return l;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

