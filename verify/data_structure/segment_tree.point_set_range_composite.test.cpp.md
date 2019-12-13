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


# :warning: data_structure/segment_tree.point_set_range_composite.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree.point_set_range_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-29 09:41:35 +0900


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends On
* :warning: <a href="../../library/data_structure/segment_tree.hpp.html">a segment tree</a>
* :warning: <a href="../../library/modulus/mint.hpp.html">modulus/mint.hpp</a>
* :warning: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>
* :warning: <a href="../../library/utils/monoids.hpp.html">utils/monoids.hpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "data_structure/segment_tree.hpp"
#include "utils/monoids.hpp"
#include "modulus/mint.hpp"
#include "utils/macros.hpp"
#include <cstdint>
#include <tuple>
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int n, q; scanf("%d%d", &n, &q);
    segment_tree<linear_function_monoid<mint<MOD> > > segtree(n);
    REP (i, n) {
        int a, b; scanf("%d%d", &a, &b);
        segtree.point_set(n - i - 1, make_pair(a, b));
    }
    while (q --) {
        int f, x, y, z; scanf("%d%d%d%d", &f, &x, &y, &z);
        if (f == 0) {
            segtree.point_set(n - x - 1, make_pair(y, z));
        } else if (f == 1) {
            mint<MOD> a, b; tie(a, b) = segtree.range_concat(n - y, n - x);
            printf("%d\n", (a * z + b).value);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

