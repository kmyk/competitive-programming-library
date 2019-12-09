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


# :heavy_check_mark: modulus/mint.unit.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [modulus/mint.hpp](../../library/modulus/mint.hpp.html)


## Code
{% raw %}
```cpp
#include "modulus/mint.hpp"

#include <cassert>
using namespace std;

int main() {
    constexpr int MOD = 1000000007;

    // ctor
    assert (mint<MOD>(-2).value == MOD - 2);
    assert (mint<MOD>(1000ll * MOD + 3).value == 3);

    // pow
    assert (mint<MOD>(2).pow(3) == 8);
    assert (mint<MOD>(2).pow(MOD - 1) == 1);
    assert (mint<MOD>(7).pow(MOD - 2) * 7 == 1);
    assert (mint<MOD>(42).pow(MOD - 1) == 1);

    // inv
    assert (mint<256>(1).inv() * 1 == 1);
    assert (mint<256>(3).inv() * 3 == 1);
    assert (mint<256>(5).inv() * 5 == 1);
    assert (mint<256>(7).inv() * 7 == 1);
    assert (mint<256>(13).inv() * 13 == 1);
    assert (mint<MOD>(1).inv() * 1 == 1);
    assert (mint<MOD>(2).inv() * 2 == 1);
    assert (mint<MOD>(3).inv() * 3 == 1);
    assert (mint<MOD>(4).inv() * 4 == 1);
    assert (mint<MOD>(42).inv() * 42 == 1);
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

