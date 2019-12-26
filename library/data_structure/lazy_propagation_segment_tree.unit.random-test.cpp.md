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
    - Last commit date: 2019-12-26 23:56:34+09:00




## Depends on

* :heavy_check_mark: <a href="lazy_propagation_segment_tree.hpp.html">a lazy propagation segment tree / 遅延伝播セグメント木 <small>(data_structure/lazy_propagation_segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="../modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>
* :heavy_check_mark: <a href="../utils/monoids.hpp.html">utils/monoids.hpp</a>


## Code

<a id="unbundled"></a>
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

<a id="bundled"></a>
{% raw %}
```cpp
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
 * @brief a lazy propagation segment tree / 遅延伝播セグメント木
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
        n = 1; while (n <= n_) n *= 2;
        a.resize(2 * n - 1, mon_x.unit());
        f.resize(n - 1, mon_f.unit());
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
        return range_concat(i, i + 1);
    }
    value_type range_concat(int l, int r) {
        assert (0 <= l and l <= r and r <= n);
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
#line 3 "data_structure/lazy_propagation_segment_tree.unit.random-test.cpp"

#include <cassert>
#include <vector>
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

inline int32_t modinv(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    assert (value != 0);
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    assert (value * x + MOD * y == b and b == 1);
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
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
#line 8 "data_structure/lazy_propagation_segment_tree.unit.random-test.cpp"
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

