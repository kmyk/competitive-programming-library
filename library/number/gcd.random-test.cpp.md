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


# :warning: number/gcd.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/gcd.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-13 18:43:42 +0900




## Depends on

* :heavy_check_mark: <a href="gcd.hpp.html">number/gcd.hpp</a>


## Code

<a id="unbundled"></a>
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
#line 2 "number/gcd.random-test.cpp"

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

<a href="../../index.html">Back to top page</a>

