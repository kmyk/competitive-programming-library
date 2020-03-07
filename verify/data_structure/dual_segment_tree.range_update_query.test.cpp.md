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


# :heavy_check_mark: data_structure/dual_segment_tree.range_update_query.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/dual_segment_tree.range_update_query.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 20:34:24+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/dual_segment_tree.hpp.html">Dual Segment Tree / 双対セグメント木 (monoids, 完全二分木) <small>(data_structure/dual_segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/monoids/left.hpp.html">monoids/left.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "data_structure/dual_segment_tree.hpp"
#include "monoids/left.hpp"

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

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/dual_segment_tree.range_update_query.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#line 2 "data_structure/dual_segment_tree.hpp"
#include <algorithm>
#include <cassert>
#include <vector>

/**
 * @brief Dual Segment Tree / 双対セグメント木 (monoids, 完全二分木)
 * @docs data_structure/dual_segment_tree.md
 * @tparam Monoid (commutativity is not required)
 */
template <class Monoid>
struct dual_segment_tree {
    typedef typename Monoid::value_type value_type;
    const Monoid mon;
    int n;
    std::vector<value_type> f;
    dual_segment_tree() = default;
    dual_segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {
        n = 1; while (n < n_) n *= 2;
        f.resize(2 * n - 1, mon.unit());
    }
    value_type point_get(int i) {  // 0-based
        assert (0 <= i and i < n);
        value_type acc = mon.unit();
        for (i += n; i > 0; i /= 2) {  // 1-based
            acc = mon.mult(f[i - 1], acc);
        }
        return acc;
    }
    void range_apply(int l, int r, value_type g) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        range_apply(0, 0, n, l, r, g);
    }
    void range_apply(int i, int il, int ir, int l, int r, value_type g) {
        if (l <= il and ir <= r) {  // 0-based
            f[i] = mon.mult(g, f[i]);
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);
            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);
            f[i] = mon.unit();
            range_apply(2 * i + 1, il, (il + ir) / 2, l, r, g);
            range_apply(2 * i + 2, (il + ir) / 2, ir, l, r, g);
        }
    }
};
#line 2 "monoids/left.hpp"
#include <utility>

template <class T>
struct left_monoid {
    // typedef std::optional<T> value_type;
    typedef std::pair<bool, T> value_type;
    value_type unit() const { return std::make_pair(false, T()); }
    value_type mult(value_type a, value_type b) const { return a.first ? a : b; }
};
#line 4 "data_structure/dual_segment_tree.range_update_query.test.cpp"

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

