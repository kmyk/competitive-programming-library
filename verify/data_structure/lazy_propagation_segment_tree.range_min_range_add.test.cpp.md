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


# :heavy_check_mark: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp


[Back to top page](../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H)


## Dependencies
* :heavy_check_mark: [data_structure/lazy_propagation_segment_tree.hpp](../../library/data_structure/lazy_propagation_segment_tree.hpp.html)
* :heavy_check_mark: [utils/monoids.hpp](../../library/utils/monoids.hpp.html)


## Code
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "data_structure/lazy_propagation_segment_tree.hpp"
#include "utils/monoids.hpp"

#include <iostream>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    lazy_propagation_segment_tree<min_monoid<int>, plus_monoid<int>, plus_min_action<int> > segtree(n);
    segtree.range_set(0, n, 0);
    while (q --) {
        int com, l, r; cin >> com >> l >> r;
        ++ r;
        if (com == 0) {
            int x; cin >> x;
            segtree.range_apply(l, r, x);
        } else if (com == 1) {
            cout << segtree.range_concat(l, r) << endl;
        }
    }
    return 0;
}

```

[Back to top page](../../index.html)

