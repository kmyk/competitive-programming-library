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


# :heavy_check_mark: a segment tree / セグメント木 <small>(data_structure/segment_tree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-30 22:32:43+09:00


* a fast & semigroup-friendly version constructor
* update a leaf node without updating ancestors
* re-build non-leaf nodes from leaf nodes


## Depends on

* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_add_range_sum.test.cpp.html">data_structure/segment_tree.point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.point_set_range_composite.test.cpp.html">data_structure/segment_tree.point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree.range_sum_query.test.cpp.html">data_structure/segment_tree.range_sum_query.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief a segment tree / セグメント木
 * @tparam Monoid (commutativity is not required)
 */
template <class Monoid>
struct segment_tree {
    typedef typename Monoid::value_type value_type;
    const Monoid mon;
    int n;
    std::vector<value_type> a;
    segment_tree() = default;
    segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1, mon.unit());
    }
    void point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
        for (i = (i + n) / 2; i > 0; i /= 2) {  // 1-based
            a[i - 1] = mon.mult(a[2 * i - 1], a[2 * i]);
        }
    }
    value_type range_concat(int l, int r) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        value_type lacc = mon.unit(), racc = mon.unit();
        for (l += n, r += n; l < r; l /= 2, r /= 2) {  // 1-based loop, 2x faster than recursion
            if (l % 2 == 1) lacc = mon.mult(lacc, a[(l ++) - 1]);
            if (r % 2 == 1) racc = mon.mult(a[(-- r) - 1], racc);
        }
        return mon.mult(lacc, racc);
    }

    value_type point_get(int i) {  // 0-based
        assert (0 <= i and i < n);
        return a[i + n - 1];
    }

    /**
     * @brief a fast & semigroup-friendly version constructor
     * @note $O(n)$
     */
    template <class InputIterator>
    segment_tree(InputIterator first, InputIterator last, const Monoid & mon_ = Monoid()) : mon(mon_) {
        int size = std::distance(first, last);
        n = 1; while (n < size) n *= 2;
        a.resize(2 * n - 1, mon.unit());
        std::copy(first, last, a.begin() + (n - 1));
        unsafe_rebuild();
    }
    /**
     * @brief update a leaf node without updating ancestors
     * @note $O(1)$
     */
    void unsafe_point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
    }
    /**
     * @brief re-build non-leaf nodes from leaf nodes
     * @note $O(n)$
     */
    void unsafe_rebuild() {
        REP_R (i, n - 1) {
            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/segment_tree.hpp"
#include <algorithm>
#include <cassert>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 6 "data_structure/segment_tree.hpp"

/**
 * @brief a segment tree / セグメント木
 * @tparam Monoid (commutativity is not required)
 */
template <class Monoid>
struct segment_tree {
    typedef typename Monoid::value_type value_type;
    const Monoid mon;
    int n;
    std::vector<value_type> a;
    segment_tree() = default;
    segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1, mon.unit());
    }
    void point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
        for (i = (i + n) / 2; i > 0; i /= 2) {  // 1-based
            a[i - 1] = mon.mult(a[2 * i - 1], a[2 * i]);
        }
    }
    value_type range_concat(int l, int r) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        value_type lacc = mon.unit(), racc = mon.unit();
        for (l += n, r += n; l < r; l /= 2, r /= 2) {  // 1-based loop, 2x faster than recursion
            if (l % 2 == 1) lacc = mon.mult(lacc, a[(l ++) - 1]);
            if (r % 2 == 1) racc = mon.mult(a[(-- r) - 1], racc);
        }
        return mon.mult(lacc, racc);
    }

    value_type point_get(int i) {  // 0-based
        assert (0 <= i and i < n);
        return a[i + n - 1];
    }

    /**
     * @brief a fast & semigroup-friendly version constructor
     * @note $O(n)$
     */
    template <class InputIterator>
    segment_tree(InputIterator first, InputIterator last, const Monoid & mon_ = Monoid()) : mon(mon_) {
        int size = std::distance(first, last);
        n = 1; while (n < size) n *= 2;
        a.resize(2 * n - 1, mon.unit());
        std::copy(first, last, a.begin() + (n - 1));
        unsafe_rebuild();
    }
    /**
     * @brief update a leaf node without updating ancestors
     * @note $O(1)$
     */
    void unsafe_point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
    }
    /**
     * @brief re-build non-leaf nodes from leaf nodes
     * @note $O(n)$
     */
    void unsafe_rebuild() {
        REP_R (i, n - 1) {
            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

