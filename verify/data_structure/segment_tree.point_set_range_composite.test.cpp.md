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


# :heavy_check_mark: data_structure/segment_tree.point_set_range_composite.test.cpp


[Back to top page](../../index.html)

* see: [https://judge.yosupo.jp/problem/point_set_range_composite](https://judge.yosupo.jp/problem/point_set_range_composite)


## Dependencies
* :heavy_check_mark: [data_structure/segment_tree.hpp](../../library/data_structure/segment_tree.hpp.html)
* :heavy_check_mark: [modulus/mint.hpp](../../library/modulus/mint.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)
* :heavy_check_mark: [utils/monoids.hpp](../../library/utils/monoids.hpp.html)


## Code
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

[Back to top page](../../index.html)

