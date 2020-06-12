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


# :heavy_check_mark: data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-23 00:48:03+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/lazy_propagation_segment_tree.hpp.html">Lazy Propagation Segment Tree / 遅延伝播セグメント木 (monoids, 完全二分木) <small>(data_structure/lazy_propagation_segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/linear_function.hpp.html">monoids/linear_function.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/linear_function_plus_count_action.hpp.html">monoids/linear_function_plus_count_action.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/plus_count.hpp.html">monoids/plus_count.hpp</a>
* :question: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "data_structure/lazy_propagation_segment_tree.hpp"
#include "monoids/plus_count.hpp"
#include "monoids/linear_function.hpp"
#include "monoids/linear_function_plus_count_action.hpp"
#include "modulus/mint.hpp"
#include "utils/macros.hpp"
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

constexpr int MOD = 998244353;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    vector<pair<mint<MOD>, int> > a(n);
    REP (i, n) {
        int a_i; scanf("%d", &a_i);
        a[i].first = a_i;
        a[i].second = 1;
    }
    lazy_propagation_segment_tree<plus_count_monoid<mint<MOD> >, linear_function_monoid<mint<MOD> >, linear_function_plus_count_action<mint<MOD> > > segtree(ALL(a));
    while (q --) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int l, r, b, c; scanf("%d%d%d%d", &l, &r, &b, &c);
            pair<mint<MOD>, mint<MOD> > f(b, c);
            segtree.range_apply(l, r, f);
        } else if (t == 1) {
            int l, r; scanf("%d%d", &l, &r);
            mint<MOD> answer = segtree.range_get(l, r).first;
            printf("%d\n", answer.value);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
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
#line 2 "monoids/plus_count.hpp"
#include <utility>

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
#line 3 "monoids/linear_function.hpp"

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
#line 4 "monoids/linear_function_plus_count_action.hpp"

/**
 * @note lazy_propagation_segment_tree<plus_count_monoid<T>, linear_function_monoid<T>, linear_function_plus_count_action<T> >
 */
template <class T>
struct linear_function_plus_count_action {
    typename plus_count_monoid<T>::value_type operator () (typename linear_function_monoid<T>::value_type f, typename plus_count_monoid<T>::value_type x) const {
        return std::make_pair(f.first * x.first + f.second * x.second, x.second);
    }
};
#line 4 "modulus/mint.hpp"
#include <iostream>
#line 3 "modulus/modpow.hpp"

inline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);
    return y;
}
#line 4 "modulus/modinv.hpp"

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


/**
 * @brief quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$
 */
template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline bool operator == (mint<MOD> other) const { return value == other.value; }
    inline bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }
#line 8 "data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp"
#include <cstdio>
#line 11 "data_structure/lazy_propagation_segment_tree.range_affine_range_sum.test.cpp"
using namespace std;

constexpr int MOD = 998244353;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    vector<pair<mint<MOD>, int> > a(n);
    REP (i, n) {
        int a_i; scanf("%d", &a_i);
        a[i].first = a_i;
        a[i].second = 1;
    }
    lazy_propagation_segment_tree<plus_count_monoid<mint<MOD> >, linear_function_monoid<mint<MOD> >, linear_function_plus_count_action<mint<MOD> > > segtree(ALL(a));
    while (q --) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int l, r, b, c; scanf("%d%d%d%d", &l, &r, &b, &c);
            pair<mint<MOD>, mint<MOD> > f(b, c);
            segtree.range_apply(l, r, f);
        } else if (t == 1) {
            int l, r; scanf("%d%d", &l, &r);
            mint<MOD> answer = segtree.range_get(l, r).first;
            printf("%d\n", answer.value);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

