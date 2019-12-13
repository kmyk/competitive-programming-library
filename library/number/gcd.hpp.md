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


# :warning: number/gcd.hpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/gcd.hpp">View this file on GitHub</a>
    - Last commit date: 2019-06-04 14:45:23 +0900




## Required By
* :warning: <a href="../data_structure/sparse_table.hpp.html">sparse table on a semilattice</a>
* :warning: <a href="../graph/lowest_common_ancestor.hpp.html">lowest common ancestor with \pm 1 RMQ and sparse table</a>


## Verified With
* :warning: <a href="../../verify/data_structure/sparse_table.unit.test.cpp.html">data_structure/sparse_table.unit.test.cpp</a>
* :warning: <a href="../../verify/graph/lowest_common_ancestor.aoj.test.cpp.html">graph/lowest_common_ancestor.aoj.test.cpp</a>
* :warning: <a href="../../verify/number/gcd.test.cpp.html">number/gcd.test.cpp</a>


## Code
{% raw %}
```cpp
#pragma once
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

