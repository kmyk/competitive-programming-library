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


# :heavy_check_mark: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 20:34:24+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/lazy_propagation_segment_tree.hpp.html">Lazy Propagation Segment Tree / 遅延伝播セグメント木 (monoids, 完全二分木) <small>(data_structure/lazy_propagation_segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/monoids/min.hpp.html">monoids/min.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/plus.hpp.html">monoids/plus.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/plus_min_action.hpp.html">monoids/plus_min_action.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "data_structure/lazy_propagation_segment_tree.hpp"
#include "monoids/min.hpp"
#include "monoids/plus.hpp"
#include "monoids/plus_min_action.hpp"
#include <cstdio>

int main() {
    int n, q; scanf("%d%d", &n, &q);
    lazy_propagation_segment_tree<min_monoid<int>, plus_monoid<int>, plus_min_action<int> > segtree(n);
    segtree.range_set(0, n, 0);
    while (q --) {
        int com, l, r; scanf("%d%d%d", &com, &l, &r);
        ++ r;
        if (com == 0) {
            int x; scanf("%d", &x);
            segtree.range_apply(l, r, x);
        } else if (com == 1) {
            printf("%d\n", segtree.range_get(l, r));
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#line 2 "data_structure/lazy_propagation_segment_tree.hpp"
#include <algorithm>
#include <cassert>
#include <type_traits>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 7 "data_structure/lazy_propagation_segment_tree.hpp"

/**
 * @brief Lazy Propagation Segment Tree / 遅延伝播セグメント木 (monoids, 完全二分木)
 * @docs data_structure/lazy_propagation_segment_tree.md
 * @tparam MonoidX is a monoid
 * @tparam MonoidF is a monoid
 * @tparam Action is a function phi : F * X -> X where the partial applied phi(f, -) : X -> X is a homomorphism on X
 */
template <class MonoidX, class MonoidF, class Action>
struct lazy_propagation_segment_tree {
    static_assert (std::is_invocable_r<typename MonoidX::value_type, Action, typename MonoidF::value_type, typename MonoidX::value_type>::value, "");
    typedef typename MonoidX::value_type value_type;
    typedef typename MonoidF::value_type operator_type;
    const MonoidX mon_x;
    const MonoidF mon_f;
    const Action act;
    int n;
    std::vector<value_type> a;
    std::vector<operator_type> f;

    lazy_propagation_segment_tree() = default;
    lazy_propagation_segment_tree(int n_, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_ = MonoidF(), const Action & act_ = Action())
            : mon_x(mon_x_), mon_f(mon_f_), act(act_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1, mon_x.unit());
        f.resize(n - 1, mon_f.unit());
    }
    template <class InputIterator>
    lazy_propagation_segment_tree(InputIterator first, InputIterator last, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_ = MonoidF(), const Action & act_ = Action())
            : mon_x(mon_x_), mon_f(mon_f_), act(act_) {
        int size = std::distance(first, last);
        n = 1; while (n < size) n *= 2;
        a.resize(2 * n - 1, mon_x.unit());
        f.resize(n - 1, mon_f.unit());
        std::copy(first, last, a.begin() + (n - 1));
        REP_R (i, n - 1) {
            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    void point_set(int i, value_type b) {
        range_set(i, i + 1, b);
    }
    /**
     * @note O(min(n, (r - l) log n))
     */
    void range_set(int l, int r, value_type b) {
        assert (0 <= l and l <= r and r <= n);
        range_set(0, 0, n, l, r, b);
    }
    void range_set(int i, int il, int ir, int l, int r, value_type b) {
        if (l <= il and ir <= r and ir - il == 1) {  // 0-based
            a[i] = b;
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);
            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);
            f[i] = mon_f.unit();
            range_set(2 * i + 1, il, (il + ir) / 2, l, r, b);
            range_set(2 * i + 2, (il + ir) / 2, ir, l, r, b);
            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    void point_apply(int i, operator_type g) {
        range_apply(i, i + 1, g);
    }
    void range_apply(int l, int r, operator_type g) {
        assert (0 <= l and l <= r and r <= n);
        range_apply(0, 0, n, l, r, g);
    }
    void range_apply(int i, int il, int ir, int l, int r, operator_type g) {
        if (l <= il and ir <= r) { // 0-based
            a[i] = act(g, a[i]);
            if (i < f.size()) f[i] = mon_f.mult(g, f[i]);
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);
            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);
            f[i] = mon_f.unit();  // unnecessary if the oprator monoid is commutative
            range_apply(2 * i + 1, il, (il + ir) / 2, l, r, g);
            range_apply(2 * i + 2, (il + ir) / 2, ir, l, r, g);
            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    value_type point_get(int i) {
        return range_get(i, i + 1);
    }
    value_type range_get(int l, int r) {
        assert (0 <= l and l <= r and r <= n);
	if (l == 0 and r == n) return a[0];
        value_type lacc = mon_x.unit(), racc = mon_x.unit();
        for (int l1 = (l += n), r1 = (r += n) - 1; l1 > 1; l /= 2, r /= 2, l1 /= 2, r1 /= 2) {  // 1-based loop, 2x faster than recursion
            if (l < r) {
                if (l % 2 == 1) lacc = mon_x.mult(lacc, a[(l ++) - 1]);
                if (r % 2 == 1) racc = mon_x.mult(a[(-- r) - 1], racc);
            }
            lacc = act(f[l1 / 2 - 1], lacc);
            racc = act(f[r1 / 2 - 1], racc);
        }
        return mon_x.mult(lacc, racc);
    }
};
#line 3 "monoids/min.hpp"
#include <limits>

template <class T>
struct min_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::max(); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};
#line 2 "monoids/plus.hpp"

template <class T>
struct plus_monoid {
    typedef T value_type;
    value_type unit() const { return value_type(); }
    value_type mult(value_type a, value_type b) const { return a + b; }
};
#line 4 "monoids/plus_min_action.hpp"

template <class T>
struct plus_min_action {
    typename min_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename min_monoid<T>::value_type x) const {
        return (x == min_monoid<T>().unit() ? x : f + x);
    }
};
#line 6 "data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp"
#include <cstdio>

int main() {
    int n, q; scanf("%d%d", &n, &q);
    lazy_propagation_segment_tree<min_monoid<int>, plus_monoid<int>, plus_min_action<int> > segtree(n);
    segtree.range_set(0, n, 0);
    while (q --) {
        int com, l, r; scanf("%d%d%d", &com, &l, &r);
        ++ r;
        if (com == 0) {
            int x; scanf("%d", &x);
            segtree.range_apply(l, r, x);
        } else if (com == 1) {
            printf("%d\n", segtree.range_get(l, r));
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

