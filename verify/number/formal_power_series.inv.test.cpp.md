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


[Back to top page](../../index.html)

* see: [https://judge.yosupo.jp/problem/inv_of_formal_power_series](https://judge.yosupo.jp/problem/inv_of_formal_power_series)


## Dependencies
* :heavy_check_mark: [number/formal_power_series.hpp](../../library/number/formal_power_series.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)


## Code
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

[Back to top page](../../index.html)

