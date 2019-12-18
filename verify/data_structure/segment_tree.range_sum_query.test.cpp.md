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


# :heavy_check_mark: data_structure/segment_tree.range_sum_query.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree.range_sum_query.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-19 02:03:14 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/segment_tree.hpp.html">a segment tree / セグメント木 <small>(data_structure/segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/monoids.hpp.html">utils/monoids.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include "data_structure/segment_tree.hpp"
#include "utils/monoids.hpp"

#include <iostream>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    segment_tree<plus_monoid<int> > segtree(n);
    while (q --) {
        int com, x, y; cin >> com >> x >> y;
        -- x;
        if (com == 0) {
            segtree.point_set(x, segtree.range_concat(x, x + 1) + y);
        } else if (com == 1) {
            cout << segtree.range_concat(x, y) << endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/segment_tree.range_sum_query.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#line 2 "data_structure/segment_tree.hpp"
#include <algorithm>
#include <cassert>
#include <vector>
#line 1 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)
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

    /**
     * @brief a fast & semigroup-friendly version constructor
     * @note $O(n)$
     */
    segment_tree(const std::vector<value_type> & a_, const Monoid & mon_ = Monoid()) : mon(mon_) {
        n = 1; while (n < a_.size()) n *= 2;
        a.resize(2 * n - 1, mon.unit());
        std::copy(ALL(a_), a.begin() + (n - 1));
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
#line 2 "utils/monoids.hpp"
#include <climits>
#include <cstdint>
#include <limits>
#include <utility>

template <class T>
struct plus_monoid {
    typedef T value_type;
    value_type unit() const { return value_type(); }
    value_type mult(value_type a, value_type b) const { return a + b; }
};

template <class T>
struct max_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::lowest(); }
    value_type mult(value_type a, value_type b) const { return std::max(a, b); }
};

template <class T>
struct min_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::max(); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};

template <class T>
struct left_monoid {
    // typedef std::optional<T> value_type;
    typedef std::pair<bool, T> value_type;
    value_type unit() const { return std::make_pair(false, T()); }
    value_type mult(value_type a, value_type b) const { return a.first ? a : b; }
};

/**
 * @note lazy_propagation_segment_tree<left_monoid<typename Monoid::value_type>, Monoid, left_action<Monoid> > is the same to dual_segment_tree<Monoid>
 */
template <class Monoid>
struct left_action {
    typename left_monoid<typename Monoid::value_type>::value_type operator () (typename Monoid::value_type f, typename left_monoid<typename Monoid::value_type>::value_type x) const {
        return x.first ? std::make_pair(true, Monoid().mult(f, x.second)) : x;
    }
};

template <class CommutativeRing>
struct linear_function_monoid {
    typedef std::pair<CommutativeRing, CommutativeRing> value_type;
    linear_function_monoid() = default;
    value_type unit() const {
        return std::make_pair(1, 0);
    }
    value_type mult(value_type g, value_type f) const {
        CommutativeRing fst = g.first * f.first;
        CommutativeRing snd = g.second + g.first * f.second;
        return std::make_pair(fst, snd);
    }
};

struct trivial_monoid {
    typedef struct {} value_type;
    value_type unit() const { return (value_type) {}; }
    value_type unit(value_type a, value_type b) const { return (value_type) {}; }
};

/**
 * @note lazy_propagation_segment_tree<Monoid, trivial_monoid, trivial_action<typename Monoid::value_type> > is the same to segment_tree<Monoid>
 */
template <class T>
struct trivial_action {
    T operator () (typename trivial_monoid::value_type f, T x) const { return x; }
};

/**
 * @note lazy_propagation_segment_tree<max_monoid<T>, plus_monoid<T>, plus_max_action<T> > is a starry sky tree
 */
template <class T>
struct plus_max_action {
    typename max_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename max_monoid<T>::value_type x) const {
        return (x == max_monoid<T>().unit() ? x : f + x);
    }
};

template <class T>
struct plus_min_action {
    typename min_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename min_monoid<T>::value_type x) const {
        return (x == min_monoid<T>().unit() ? x : f + x);
    }
};

template <class T>
struct plus_count_monoid {
    typedef std::pair<T, int> value_type;
    value_type unit() const {
        return std::make_pair(T(), 0);
    }
    value_type mult(value_type a, value_type b) const {
        return std::make_pair(a.first + b.first, a.second + b.second);
    }
    static value_type make(T a) {
        return std::make_pair(a, 1);
    }
};

/**
 * @note lazy_propagation_segment_tree<plus_count_monoid<T>, linear_function_monoid<T>, linear_function_plus_count_action<T> >
 */
template <class T>
struct linear_function_plus_count_action {
    typename plus_count_monoid<T>::value_type operator () (typename linear_function_monoid<T>::value_type f, typename plus_count_monoid<T>::value_type x) const {
        return std::make_pair(f.first * x.first + f.second * x.second, x.second);
    }
};

template <class T>
struct min_count_monoid {
    typedef std::pair<T, int> value_type;
    value_type unit() const {
        return std::make_pair(std::numeric_limits<T>::max(), 0);
    }
    value_type mult(value_type a, value_type b) const {
        if (a.first < b.first) return a;
        if (a.first > b.first) return b;
        return std::make_pair(a.first, a.second + b.second);
    }
    static value_type make(T a) {
        return std::make_pair(a, 1);
    }
};

/**
 * @note lazy_propagation_segment_tree<min_count_monoid<T>, plus_monoid<T>, plus_min_count_action<T> > can count a number of zeros (or, non-zero numbers) in the array
 */
template <class T>
struct plus_min_count_action {
    typename min_count_monoid<T>::value_type operator () (typename plus_monoid<T>::value_type f, typename min_count_monoid<T>::value_type x) const {
        if (x.first == min_count_monoid<T>().unit().first) return x;
        return std::make_pair(f + x.first, x.second);
    }
};
#line 4 "data_structure/segment_tree.range_sum_query.test.cpp"

#include <iostream>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    segment_tree<plus_monoid<int> > segtree(n);
    while (q --) {
        int com, x, y; cin >> com >> x >> y;
        -- x;
        if (com == 0) {
            segtree.point_set(x, segtree.range_concat(x, x + 1) + y);
        } else if (com == 1) {
            cout << segtree.range_concat(x, y) << endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

