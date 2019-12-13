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


# :warning: modulus/choose.hpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/choose.hpp">View this file on GitHub</a>
    - Last commit date: 2019-11-09 09:23:07 +0900




## Depends On
* :warning: <a href="factorial.hpp.html">modulus/factorial.hpp</a>
* :heavy_check_mark: <a href="mint.hpp.html">modulus/mint.hpp</a>
* :warning: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code
{% raw %}
```cpp
#pragma once
#include <cassert>
#include "modulus/mint.hpp"
#include "modulus/factorial.hpp"
#include "utils/macros.hpp"

/**
 * @note O(n log n) at first time, otherwise O(1)
 */
template <int32_t MOD>
mint<MOD> choose(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) * inv_fact<MOD>(n - r) * inv_fact<MOD>(r);
}
template <int32_t MOD>
mint<MOD> permute(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) * inv_fact<MOD>(n - r);
}
template <int32_t MOD>
mint<MOD> multichoose(int n, int r) {
    assert (0 <= n and 0 <= r);
    if (n == 0 and r == 0) return 1;
    return choose<MOD>(n + r - 1, r);
}

/**
 * @note O(r)
 */
template <int32_t MOD>
mint<MOD> simple_choose(int64_t n, int32_t r) {
    assert (0 <= r and r <= n);
    mint<MOD> num = 1;
    mint<MOD> den = 1;
    REP (i, r) {
        num *= n - i;
        den *= i + 1;
    }
    return num / den;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

