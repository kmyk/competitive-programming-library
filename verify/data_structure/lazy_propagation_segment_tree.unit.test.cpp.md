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


# :heavy_check_mark: data_structure/lazy_propagation_segment_tree.unit.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [a lazy propagation segment tree](../../library/data_structure/lazy_propagation_segment_tree.hpp.html)
* :heavy_check_mark: [modulus/mint.hpp](../../library/modulus/mint.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)
* :heavy_check_mark: [utils/monoids.hpp](../../library/utils/monoids.hpp.html)


## Code
{% raw %}
```cpp
#include "data_structure/lazy_propagation_segment_tree.hpp"
#include "utils/monoids.hpp"

#include <cassert>
#include <vector>
#include "modulus/mint.hpp"
#include "utils/macros.hpp"
using namespace std;

int main() {
    {
        int n = 9;
        lazy_propagation_segment_tree<min_monoid<int>, plus_monoid<int>, plus_min_action<int> > segtree(n);
        segtree.point_set(2, 2);
        segtree.point_set(3, 3);
        segtree.point_set(4, 4);
        segtree.point_set(6, 6);
        assert (segtree.range_concat(2, 3) == 2);
        assert (segtree.range_concat(5, 8) == 6);
        segtree.range_apply(1, 4, 9);
        assert (segtree.range_concat(3, 6) == 4);
        assert (segtree.range_concat(0, 3) == 11);
    }

    {
        constexpr int MOD = 1e9 + 7;
        constexpr int n = 13;
        vector<mint<MOD> > ary(n);
        lazy_propagation_segment_tree<plus_count_monoid<mint<MOD> >, linear_function_monoid<mint<MOD> >, linear_function_plus_count_action<mint<MOD> > > segtree(n);
        segtree.range_set(0, n, make_pair(0, 1));
        auto check = [&]() {
            REP (l, n) {
                mint<MOD> acc = 0;
                REP3 (r, l + 1, n + 1) {
                    acc += ary[r - 1];
                    assert (segtree.range_concat(l, r).first == acc);
                }
            }
        };
        auto apply = [&](int l, int r, mint<MOD> a, mint<MOD> b) {
            REP3 (i, l, r) {
                ary[i] = a * ary[i] + b;
            }
            segtree.range_apply(l, r, make_pair(a, b));
            check();
        };
        apply(1, 4, 1, 1);
        apply(3, 7, 2, 3);
        apply(2, 9, 5, 4);
        apply(0, 5, 7, 6);
    }
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

