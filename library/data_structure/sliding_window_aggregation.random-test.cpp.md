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


# :warning: data_structure/sliding_window_aggregation.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/sliding_window_aggregation.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00




## Depends on

* :warning: <a href="sliding_window_aggregation.hpp.html">get sum of elements in the queue <small>(data_structure/sliding_window_aggregation.hpp)</small></a>
* :heavy_check_mark: <a href="../modulus/mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "data_structure/sliding_window_aggregation.hpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <deque>
#include <random>
#include <vector>
#include "utils/macros.hpp"
#include "modulus/mint.hpp"
using namespace std;

constexpr int MOD = 1e9 + 7;
struct linear_function_monoid {
    typedef pair<mint<MOD>, mint<MOD> > value_type;
    value_type unit() const { return make_pair(1, 0); }
    value_type append(value_type f, value_type g) const { return make_pair(f.first * g.first, f.first * g.second + f.second); }
};

int main() {
    random_device device;
    default_random_engine gen(device());
    REP (iteration, 10000) {
        deque<typename linear_function_monoid::value_type> deq;
        sliding_window_aggregation<linear_function_monoid> swag;
        REP (i, 1000) {
            if (not deq.empty() and bernoulli_distribution()(gen) < 0.3) {
                deq.pop_front();
                swag.pop();
            } else {
                mint<MOD> a = uniform_int_distribution<int>(0, MOD - 1)(gen);
                mint<MOD> b = uniform_int_distribution<int>(0, MOD - 1)(gen);
                deq.emplace_back(a, b);
                swag.push(make_pair(a, b));
            }
            assert (accumulate(ALL(deq), linear_function_monoid().unit(), [&](typename linear_function_monoid::value_type f, typename linear_function_monoid::value_type g) {
                return linear_function_monoid().append(f, g);
            }) == swag.accumulate());
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
        back = mon.append(back, x);
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
                data[i] = mon.append(data[i], data[i + 1]);
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
        return front ? mon.append(data.front(), back) : back;
    }
    bool empty() const {
        return data.empty();
    }
    std::size_t size() const {
        return data.size();
    }
};
#line 2 "data_structure/sliding_window_aggregation.random-test.cpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <deque>
#include <random>
#include <vector>
#line 2 "modulus/mint.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>

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
#line 11 "data_structure/sliding_window_aggregation.random-test.cpp"
using namespace std;

constexpr int MOD = 1e9 + 7;
struct linear_function_monoid {
    typedef pair<mint<MOD>, mint<MOD> > value_type;
    value_type unit() const { return make_pair(1, 0); }
    value_type append(value_type f, value_type g) const { return make_pair(f.first * g.first, f.first * g.second + f.second); }
};

int main() {
    random_device device;
    default_random_engine gen(device());
    REP (iteration, 10000) {
        deque<typename linear_function_monoid::value_type> deq;
        sliding_window_aggregation<linear_function_monoid> swag;
        REP (i, 1000) {
            if (not deq.empty() and bernoulli_distribution()(gen) < 0.3) {
                deq.pop_front();
                swag.pop();
            } else {
                mint<MOD> a = uniform_int_distribution<int>(0, MOD - 1)(gen);
                mint<MOD> b = uniform_int_distribution<int>(0, MOD - 1)(gen);
                deq.emplace_back(a, b);
                swag.push(make_pair(a, b));
            }
            assert (accumulate(ALL(deq), linear_function_monoid().unit(), [&](typename linear_function_monoid::value_type f, typename linear_function_monoid::value_type g) {
                return linear_function_monoid().append(f, g);
            }) == swag.accumulate());
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

