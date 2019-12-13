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


# :warning: data_structure/dual_segment_tree.range_update_query.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/dual_segment_tree.range_update_query.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-29 09:20:33 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D</a>


## Depends On
* :warning: <a href="../../library/data_structure/dual_segment_tree.hpp.html">a dual segment tree</a>
* :warning: <a href="../../library/utils/monoids.hpp.html">utils/monoids.hpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "data_structure/dual_segment_tree.hpp"
#include "utils/monoids.hpp"

#include <iostream>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    dual_segment_tree<left_monoid<uint32_t> > segtree(n);
    segtree.range_apply(0, n, make_pair(true, (1u << 31) - 1));
    while (q --) {
        int com; cin >> com;
        if (com == 0) {
            int l, r; uint32_t x; cin >> l >> r >> x;
            ++ r;
            segtree.range_apply(l, r, make_pair(true, x));
        } else if (com == 1) {
            int i; cin >> i;
            cout << segtree.point_get(i).second << endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

