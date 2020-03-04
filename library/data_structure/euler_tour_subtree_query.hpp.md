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


# :heavy_check_mark: Euler Tour (subtree queries, with commutative monoids) <small>(data_structure/euler_tour_subtree_query.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/euler_tour_subtree_query.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 20:34:24+09:00




## Operations

根付き木 $T$ であってそれぞれの頂点 $x$ に可換 monoid 重み $a_x \in M$ が乗ったものがあるとする。頂点数を $N$ として均し $O(\log N)$ で次が処理できる。

-   $\mathtt{vertex\unicode{95}set}(x, b)$: 頂点 $x$ の重みを $a_x \gets b$ と更新する。
-   $\mathtt{vertex\unicode{95}get}(x)$: 頂点 $x$ の重み $a_x$ を計算する。
-   $\mathtt{subtree\unicode{95}get}(x, y)$: 頂点 $x$ を根とする部分木に属する頂点の重みの総和 $$\sum _ {y ~\text{is a descendent of}~ x} a_y$$ を計算する。


## Depends on

* :heavy_check_mark: <a href="segment_tree.hpp.html">Segment Tree / セグメント木 (monoids, 完全二分木) <small>(data_structure/segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../graph/euler_tour_preorder.hpp.html">Euler Tour (preorder) <small>(graph/euler_tour_preorder.hpp)</small></a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp.html">data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <vector>
#include "utils/macros.hpp"
#include "graph/euler_tour_preorder.hpp"
#include "data_structure/segment_tree.hpp"

/**
 * @brief Euler Tour (subtree queries, with commutative monoids)
 * @docs data_structure/euler_tour_subtree_query.md
 */
template <class CommutativeMonoid>
class euler_tour_subtree_query {
    typedef typename CommutativeMonoid::value_type value_type;
    segment_tree<CommutativeMonoid> data;
    std::vector<int> left, right;

public:
    euler_tour_subtree_query(const std::vector<std::vector<int> > & g, int root, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : data(g.size(), mon_) {
        std::vector<int> tour;
        do_euler_tour_preorder(g, root, tour, left, right);
    }
    template <class InputIterator>
    euler_tour_subtree_query(const std::vector<std::vector<int> > & g, int root, InputIterator first, InputIterator last, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : data(std::distance(first, last), mon_) {
        assert ((int)g.size() == std::distance(first, last));
        std::vector<int> tour;
        do_euler_tour_preorder(g, root, tour, left, right);
        REP (x, g.size()) {
            data.unsafe_point_set(left[x], *(first ++));
        }
        data.unsafe_rebuild();
    }

    void vertex_set(int x, value_type a) {
        assert (0 <= x and x < (int)left.size());
        return data.point_set(left[x], a);
    }
    value_type vertex_get(int x) {
        assert (0 <= x and x < (int)left.size());
        return data.point_get(left[x]);
    }
    value_type subtree_get(int x) {
        assert (0 <= x and x < (int)left.size());
        return data.range_get(left[x], right[x]);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/euler_tour_subtree_query.hpp"
#include <cassert>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 2 "graph/euler_tour_preorder.hpp"
#include <functional>
#include <vector>

/**
 * @brief Euler Tour (preorder)
 * @arg g must be a rooted tree, directed or undirected
 */
void do_euler_tour_preorder(std::vector<std::vector<int> > const & g, int root, std::vector<int> & tour, std::vector<int> & left, std::vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.assign(n, -1);
    right.assign(n, -1);
    std::function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
    };
    go(root, -1);
}
#line 2 "data_structure/segment_tree.hpp"
#include <algorithm>
#include <cassert>
#include <vector>
#line 6 "data_structure/segment_tree.hpp"

/**
 * @brief Segment Tree / セグメント木 (monoids, 完全二分木)
 * @docs data_structure/segment_tree.md
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
    value_type range_get(int l, int r) {  // 0-based, [l, r)
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
#line 7 "data_structure/euler_tour_subtree_query.hpp"

/**
 * @brief Euler Tour (subtree queries, with commutative monoids)
 * @docs data_structure/euler_tour_subtree_query.md
 */
template <class CommutativeMonoid>
class euler_tour_subtree_query {
    typedef typename CommutativeMonoid::value_type value_type;
    segment_tree<CommutativeMonoid> data;
    std::vector<int> left, right;

public:
    euler_tour_subtree_query(const std::vector<std::vector<int> > & g, int root, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : data(g.size(), mon_) {
        std::vector<int> tour;
        do_euler_tour_preorder(g, root, tour, left, right);
    }
    template <class InputIterator>
    euler_tour_subtree_query(const std::vector<std::vector<int> > & g, int root, InputIterator first, InputIterator last, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : data(std::distance(first, last), mon_) {
        assert ((int)g.size() == std::distance(first, last));
        std::vector<int> tour;
        do_euler_tour_preorder(g, root, tour, left, right);
        REP (x, g.size()) {
            data.unsafe_point_set(left[x], *(first ++));
        }
        data.unsafe_rebuild();
    }

    void vertex_set(int x, value_type a) {
        assert (0 <= x and x < (int)left.size());
        return data.point_set(left[x], a);
    }
    value_type vertex_get(int x) {
        assert (0 <= x and x < (int)left.size());
        return data.point_get(left[x]);
    }
    value_type subtree_get(int x) {
        assert (0 <= x and x < (int)left.size());
        return data.range_get(left[x], right[x]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

