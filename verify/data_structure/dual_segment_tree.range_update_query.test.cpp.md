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


# :heavy_check_mark: data_structure/dual_segment_tree.range_update_query.test.cpp


[Back to top page](../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D)


## Dependencies
* :heavy_check_mark: [data_structure/dual_segment_tree.hpp](../../library/data_structure/dual_segment_tree.hpp.html)
* :heavy_check_mark: [utils/monoids.hpp](../../library/utils/monoids.hpp.html)


## Code
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

[Back to top page](../../index.html)

