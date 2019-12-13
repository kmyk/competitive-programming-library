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


# :warning: modulus/factorial.unit.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/modulus/factorial.unit.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-09 09:23:07 +0900




## Depends On
* :warning: <a href="../../library/modulus/factorial.hpp.html">modulus/factorial.hpp</a>
* :warning: <a href="../../library/modulus/mint.hpp.html">modulus/mint.hpp</a>


## Code
{% raw %}
```cpp
#include "modulus/factorial.hpp"

#include <cassert>
using namespace std;

int main() {
    constexpr int32_t MOD = 1e9 + 7;
    assert (fact<MOD>(0) == 1);
    assert (fact<MOD>(1) == 1);
    assert (fact<MOD>(2) == 2);
    assert (fact<MOD>(3) == 6);
    assert (fact<MOD>(4) == 24);
    assert (fact<MOD>(5) == 120);
    assert (fact<MOD>(6) == 720);
    assert (fact<MOD>(7) == 5040);
    assert (fact<MOD>(8) == 40320);
    assert (fact<MOD>(9) == 362880);
    assert (fact<MOD>(10) == 3628800);
    assert (fact<MOD>(11) == 39916800);
    assert (fact<MOD>(12) == 479001600);
    assert (fact<MOD>(13) == 227020758);
    assert (fact<MOD>(14) == 178290591);
    assert (fact<MOD>(15) == 674358851);
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

