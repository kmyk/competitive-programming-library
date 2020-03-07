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


# :heavy_check_mark: data_structure/sliding_window_aggregation.yosupo.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/sliding_window_aggregation.yosupo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-22 23:03:03+09:00


* see: <a href="https://judge.yosupo.jp/problem/queue_operate_all_composite">https://judge.yosupo.jp/problem/queue_operate_all_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/sliding_window_aggregation.hpp.html">Sliding Window Aggregation / 含まれる要素の総和が $O(1)$ で取れる queue (可換とは限らない monoid が乗る) <small>(data_structure/sliding_window_aggregation.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/dual.hpp.html">monoids/dual.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/linear_function.hpp.html">monoids/linear_function.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "data_structure/sliding_window_aggregation.hpp"
#include "monoids/linear_function.hpp"
#include "monoids/dual.hpp"
#include "modulus/mint.hpp"
#include <cstdio>
#include <tuple>
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int q; scanf("%d", &q);
    sliding_window_aggregation<dual_monoid<linear_function_monoid<mint<MOD> > > > swag;
    while (q --) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int a, b; scanf("%d%d", &a, &b);
            swag.push(make_pair(a, b));
        } else if (t == 1) {
            swag.pop();
        } else if (t == 2) {
            int x; scanf("%d", &x);
            mint<MOD> a, b; tie(a, b) = swag.accumulate();
            printf("%d\n", (a * x + b).value);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/sliding_window_aggregation.yosupo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#line 2 "data_structure/sliding_window_aggregation.hpp"
#include <cassert>
#include <cstddef>
#include <deque>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 6 "data_structure/sliding_window_aggregation.hpp"

/**
 * @brief Sliding Window Aggregation / 含まれる要素の総和が $O(1)$ で取れる queue (可換とは限らない monoid が乗る)
 */
template <class Monoid>
struct sliding_window_aggregation {
    typedef typename Monoid::value_type value_type;
    Monoid mon;
    std::deque<value_type> data;
    int front;
    value_type back;
    sliding_window_aggregation(const Monoid & mon_ = Monoid()) : mon(mon_) {
        front = 0;
        back = mon.unit();
    }
    /**
     * @note O(1)
     */
    void push(value_type x) {
        data.push_back(x);
        back = mon.mult(back, x);
    }
    /**
     * @note amortized O(1)
     */
    void pop() {
        assert (not data.empty());
        data.pop_front();
        if (front) {
            -- front;
        } else {
            REP_R (i, (int)data.size() - 1) {
                data[i] = mon.mult(data[i], data[i + 1]);
            }
            front = data.size();
            back = mon.unit();
        }
    }
    /**
     * @brief get sum of elements in the queue
     * @note O(1)
     */
    value_type accumulate() const {
        return front ? mon.mult(data.front(), back) : back;
    }
    bool empty() const {
        return data.empty();
    }
    std::size_t size() const {
        return data.size();
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
#line 4 "modulus/mint.hpp"
#include <iostream>
#line 3 "modulus/modpow.hpp"

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
#line 6 "data_structure/sliding_window_aggregation.yosupo.test.cpp"
#include <cstdio>
#include <tuple>
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int q; scanf("%d", &q);
    sliding_window_aggregation<dual_monoid<linear_function_monoid<mint<MOD> > > > swag;
    while (q --) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int a, b; scanf("%d%d", &a, &b);
            swag.push(make_pair(a, b));
        } else if (t == 1) {
            swag.pop();
        } else if (t == 2) {
            int x; scanf("%d", &x);
            mint<MOD> a, b; tie(a, b) = swag.accumulate();
            printf("%d\n", (a * x + b).value);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

