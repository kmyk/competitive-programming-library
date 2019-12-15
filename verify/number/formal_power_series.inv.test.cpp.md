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


# :heavy_check_mark: number/formal_power_series.inv.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/number/formal_power_series.inv.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-08 21:29:58 +0900


* see: <a href="https://judge.yosupo.jp/problem/inv_of_formal_power_series">https://judge.yosupo.jp/problem/inv_of_formal_power_series</a>


## Depends on

* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="../../library/number/formal_power_series.hpp.html">number/formal_power_series.hpp</a>
* :heavy_check_mark: <a href="../../library/number/number_theoretic_transformation.hpp.html">a specialized version of Garner's algorithm <small>(number/number_theoretic_transformation.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

{% raw %}
```cpp
#include "number/formal_power_series.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <cstdio>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

constexpr int MOD = 998244353;
int main() {
    // input
    int n; scanf("%d", &n);
    vector<mint<MOD> > a(n);
    REP (i, n) {
        scanf("%d", &a[i].value);
    }

    // solve
    vector<mint<MOD> > b = formal_power_series<mint<MOD> >(a).inv(n).data();
    b.resize(n);

    // output
    REP (i, n) {
        printf("%d ", b[i].value);
    }
    printf("\n");
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

