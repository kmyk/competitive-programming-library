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


# :heavy_check_mark: number/gcd.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [number/gcd.hpp](../../library/number/gcd.hpp.html)


## Code
{% raw %}
```cpp
#include "number/gcd.hpp"

#include <cassert>

int main() {
    assert (gcd(0, 0) == 0);
    assert (gcd(42, 0) == 42);
    assert (gcd(0, 42) == 42);
    assert (gcd(3, -12) == 3);
    assert (gcd(-3, 12) == -3);
    assert (gcd(7, -12) == -1);
    assert (gcd(-7, 12) == 1);
    assert (gcd(-9, -12) == -3);
    assert (gcd(-1, -1) == -1);
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

