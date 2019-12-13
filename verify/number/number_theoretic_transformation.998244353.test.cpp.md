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


# :warning: number/number_theoretic_transformation.998244353.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/number/number_theoretic_transformation.998244353.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-08 21:29:58 +0900


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod">https://judge.yosupo.jp/problem/convolution_mod</a>


## Depends On
* :warning: <a href="../../library/modulus/mint.hpp.html">modulus/mint.hpp</a>
* :warning: <a href="../../library/number/number_theoretic_transformation.hpp.html">a specialized version of Garner's algorithm</a>
* :warning: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code
{% raw %}
```cpp
#include "number/number_theoretic_transformation.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <cstdio>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

constexpr int MOD = 998244353;
int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    vector<mint<MOD> > a(n);
    REP (i, n) {
        scanf("%d", &a[i].value);
    }
    vector<mint<MOD> > b(m);
    REP (j, m) {
        scanf("%d", &b[j].value);
    }

    // solve
    vector<mint<MOD> > c = ntt_convolution(a, b);

    // output
    REP (i, n + m - 1) {
        printf("%d ", c[i].value);
    }
    printf("\n");
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

