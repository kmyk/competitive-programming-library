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


# :heavy_check_mark: utils/binary_search.unit.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [a flexible binary search](../../library/utils/binary_search.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)


## Code
{% raw %}
```cpp
#include "utils/binary_search.hpp"

#include <cassert>
#include <initializer_list>
#include "utils/macros.hpp"

int main() {
    // binsearch()
    for (int l : { 0, 1, 2, 3 }) {
        for (int r : { 8, 9, 10, 11 }) {
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return true;   }) == l);
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return false;  }) == r);
            REP3 (i, l, r + 1) {
                assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return n >= i; }) == i);
            }
        }
    }

    // binsearch_max
    for (int l : { 0, 1, 2, 3 }) {
        for (int r : { 8, 9, 10, 11 }) {
            assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return false; }) == l);
            assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return true;  }) == r);
            REP3 (i, l, r + 1) {
                assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return n <= i; }) == i);
            }
        }
    }
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

