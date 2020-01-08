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


# :heavy_check_mark: data_structure/segment_tree.point_set_range_composite.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree.point_set_range_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 19:38:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/segment_tree.hpp.html">a segment tree / セグメント木 <small>(data_structure/segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/dual.hpp.html">monoids/dual.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/linear_function.hpp.html">monoids/linear_function.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "data_structure/segment_tree.hpp"
#include "monoids/linear_function.hpp"
#include "monoids/dual.hpp"
#include "modulus/mint.hpp"
#include "utils/macros.hpp"
#include <cstdint>
#include <tuple>
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int n, q; scanf("%d%d", &n, &q);
    segment_tree<dual_monoid<linear_function_monoid<mint<MOD> > > > segtree(n);
    REP (i, n) {
        int a, b; scanf("%d%d", &a, &b);
        segtree.point_set(i, make_pair(a, b));
    }
    while (q --) {
        int f, x, y, z; scanf("%d%d%d%d", &f, &x, &y, &z);
        if (f == 0) {
            segtree.point_set(x, make_pair(y, z));
        } else if (f == 1) {
            mint<MOD> a, b; tie(a, b) = segtree.range_get(x, y);
            printf("%d\n", (a * z + b).value);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/segment_tree.point_set_range_composite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
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
#line 2 "monoids/linear_function.hpp"
#include <utility>

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
#line 2 "monoids/dual.hpp"

/**
 * @see http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual
 */
template <class Monoid>
struct dual_monoid {
    typedef typename Monoid::value_type value_type;
    Monoid base;
    value_type unit() const { return base.unit(); }
    value_type mult(const value_type & a, const value_type & b) const { return base.mult(b, a); }
};
#line 2 "modulus/mint.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#line 2 "modulus/modpow.hpp"
#include <cassert>

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}
#line 2 "modulus/modinv.hpp"
#include <algorithm>
#include <cassert>

inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    if (value == 0) return -1;
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    if (not (value * x + MOD * y == b and b == 1)) return -1;
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

inline int32_t modinv(int32_t x, int32_t MOD) {
    int32_t y = modinv_nocheck(x, MOD);
    assert (y != -1);
    return y;
}
#line 7 "modulus/mint.hpp"


template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline constexpr mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline constexpr mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline constexpr mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline constexpr mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline constexpr mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline constexpr mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline constexpr mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline constexpr mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline constexpr mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline constexpr mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline constexpr bool operator == (mint<MOD> other) const { return value == other.value; }
    inline constexpr bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }
#line 7 "data_structure/segment_tree.point_set_range_composite.test.cpp"
#include <cstdint>
#include <tuple>
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int n, q; scanf("%d%d", &n, &q);
    segment_tree<dual_monoid<linear_function_monoid<mint<MOD> > > > segtree(n);
    REP (i, n) {
        int a, b; scanf("%d%d", &a, &b);
        segtree.point_set(i, make_pair(a, b));
    }
    while (q --) {
        int f, x, y, z; scanf("%d%d%d%d", &f, &x, &y, &z);
        if (f == 0) {
            segtree.point_set(x, make_pair(y, z));
        } else if (f == 1) {
            mint<MOD> a, b; tie(a, b) = segtree.range_get(x, y);
            printf("%d\n", (a * z + b).value);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

