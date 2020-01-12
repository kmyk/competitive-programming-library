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


# :warning: Garner's algorithm <small>(modulus/garner.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/garner.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-12 17:06:03+09:00




## Depends on

* :heavy_check_mark: <a href="mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <cstdint>
#include <tuple>
#include <utility>
#include <vector>
#include "modulus/mint.hpp"
#include "utils/macros.hpp"

/**
 * @brief Garner's algorithm
 * @arg eqns is equations like x = a_i (mod m_i)
 * @return the minimal solution of given equations
 */
int32_t garner_algorithm(std::vector<std::pair<int32_t, int32_t> > eqns, int32_t MOD) {
    eqns.emplace_back(0, MOD);
    std::vector<int64_t> k(eqns.size(), 1);
    std::vector<int64_t> c(eqns.size(), 0);
    REP (i, eqns.size() - 1) {
        int32_t a_i, m_i; std::tie(a_i, m_i) = eqns[i];

        int32_t x = (a_i - c[i]) * modinv(k[i], m_i) % m_i;
        if (x < 0) x += m_i;
        assert (a_i == (k[i] * x + c[i]) % m_i);

        REP3 (j, i + 1, eqns.size()) {
            int32_t a_j, m_j; std::tie(a_j, m_j) = eqns[j];
            (c[j] += k[j] * x) %= m_j;
            (k[j] *= m_i) %= m_j;
        }
    }
    return c.back();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modulus/garner.hpp"
#include <cassert>
#include <cstdint>
#include <tuple>
#include <utility>
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
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 9 "modulus/garner.hpp"

/**
 * @brief Garner's algorithm
 * @arg eqns is equations like x = a_i (mod m_i)
 * @return the minimal solution of given equations
 */
int32_t garner_algorithm(std::vector<std::pair<int32_t, int32_t> > eqns, int32_t MOD) {
    eqns.emplace_back(0, MOD);
    std::vector<int64_t> k(eqns.size(), 1);
    std::vector<int64_t> c(eqns.size(), 0);
    REP (i, eqns.size() - 1) {
        int32_t a_i, m_i; std::tie(a_i, m_i) = eqns[i];

        int32_t x = (a_i - c[i]) * modinv(k[i], m_i) % m_i;
        if (x < 0) x += m_i;
        assert (a_i == (k[i] * x + c[i]) % m_i);

        REP3 (j, i + 1, eqns.size()) {
            int32_t a_j, m_j; std::tie(a_j, m_j) = eqns[j];
            (c[j] += k[j] * x) %= m_j;
            (k[j] *= m_i) %= m_j;
        }
    }
    return c.back();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

