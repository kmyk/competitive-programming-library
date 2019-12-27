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


# :heavy_check_mark: a dual segment tree / 双対セグメント木 <small>(data_structure/dual_segment_tree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/dual_segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/dual_segment_tree.range_update_query.test.cpp.html">data_structure/dual_segment_tree.range_update_query.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

/**
 * @brief a dual segment tree / 双対セグメント木
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/dual_segment_tree.hpp"
#include <algorithm>
#include <cassert>
#include <vector>

/**
 * @brief a dual segment tree / 双対セグメント木
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

