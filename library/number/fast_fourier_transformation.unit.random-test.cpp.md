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


# :warning: number/fast_fourier_transformation.unit.random-test.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/fast_fourier_transformation.unit.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-13 18:43:42 +0900




## Depends On
* :warning: <a href="fast_fourier_transformation.hpp.html">the convolution</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code
{% raw %}
```cpp
#include "number/fast_fourier_transformation.hpp"

#include <cassert>
#include <random>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

#include <iostream>
int main() {
    vector<int> f { 1, 2, 3 };
    vector<int> g { 10, 20, 30 };
    vector<int> h = convolution(f, g);
    assert (h[0] == 1 * 10);
    assert (h[1] == 1 * 20 + 2 * 10);
    assert (h[2] == 1 * 30 + 2 * 20 + 3 * 10);
    assert (h[3] ==          2 * 30 + 3 * 20);
    assert (h[4] ==                   3 * 30);

    default_random_engine gen;
    REP (iteration, 1000) {
        int n = uniform_int_distribution<int>(1, iteration + 1)(gen);
        int m = uniform_int_distribution<int>(1, iteration + 1)(gen);
        vector<int64_t> f(n);
        REP (i, n) {
            f[i] = uniform_int_distribution<int64_t>(- 1000000, 1000000)(gen);
        }
        vector<int64_t> g(m);
        REP (j, m) {
            g[j] = uniform_int_distribution<int64_t>(- 1000000, 1000000)(gen);
        }
        vector<int64_t> h(n + m - 1);
        REP (i, n) REP (j, m) {
            h[i + j] += f[i] * g[j];
        }
        assert (h == convolution(f, g));
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

