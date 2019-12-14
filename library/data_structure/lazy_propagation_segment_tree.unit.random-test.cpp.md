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


# :warning: data_structure/lazy_propagation_segment_tree.unit.random-test.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/lazy_propagation_segment_tree.unit.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900




## Depends On
* :heavy_check_mark: <a href="lazy_propagation_segment_tree.hpp.html">a lazy propagation segment tree / 遅延伝播セグメント木</a>
* :heavy_check_mark: <a href="../modulus/mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>
* :heavy_check_mark: <a href="../utils/monoids.hpp.html">utils/monoids.hpp</a>


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

<a href="../../index.html">Back to top page</a>

