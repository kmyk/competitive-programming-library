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


# :warning: data_structure/dual_segment_tree.unit.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/dual_segment_tree.unit.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-29 09:20:33 +0900




## Depends On
* :warning: <a href="../../library/data_structure/dual_segment_tree.hpp.html">a dual segment tree</a>
* :warning: <a href="../../library/utils/monoids.hpp.html">utils/monoids.hpp</a>


## Code
{% raw %}
```cpp
#include "data_structure/dual_segment_tree.hpp"
#include "utils/monoids.hpp"

#include <cassert>
using namespace std;

int main() {
    dual_segment_tree<min_monoid<int> > segtree(12);
    segtree.range_apply(2, 7, 50);
    segtree.range_apply(5, 9, 30);
    segtree.range_apply(1, 11, 80);
    assert (segtree.point_get( 0) == min_monoid<int>().unit());
    assert (segtree.point_get( 1) ==  80);
    assert (segtree.point_get( 2) ==  50);
    assert (segtree.point_get( 3) ==  50);
    assert (segtree.point_get( 4) ==  50);
    assert (segtree.point_get( 5) ==  30);
    assert (segtree.point_get( 6) ==  30);
    assert (segtree.point_get( 7) ==  30);
    assert (segtree.point_get( 8) ==  30);
    assert (segtree.point_get( 9) ==  80);
    assert (segtree.point_get(10) ==  80);
    assert (segtree.point_get(11) == min_monoid<int>().unit());
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

