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


# :warning: modulus/mint.unit.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/mint.unit.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-13 18:43:42+09:00




## Depends on

* :heavy_check_mark: <a href="mint.hpp.html">modulus/mint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "modulus/mint.hpp"

#include <cassert>
using namespace std;

int main() {
    constexpr int MOD = 1000000007;

    // ctor
    assert (mint<MOD>(-2).value == MOD - 2);
    assert (mint<MOD>(1000ll * MOD + 3).value == 3);

    // pow
    assert (mint<MOD>(2).pow(3) == 8);
    assert (mint<MOD>(2).pow(MOD - 1) == 1);
    assert (mint<MOD>(7).pow(MOD - 2) * 7 == 1);
    assert (mint<MOD>(42).pow(MOD - 1) == 1);

    // inv
    assert (mint<256>(1).inv() * 1 == 1);
    assert (mint<256>(3).inv() * 3 == 1);
    assert (mint<256>(5).inv() * 5 == 1);
    assert (mint<256>(7).inv() * 7 == 1);
    assert (mint<256>(13).inv() * 13 == 1);
    assert (mint<MOD>(1).inv() * 1 == 1);
    assert (mint<MOD>(2).inv() * 2 == 1);
    assert (mint<MOD>(3).inv() * 3 == 1);
    assert (mint<MOD>(4).inv() * 4 == 1);
    assert (mint<MOD>(42).inv() * 42 == 1);
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
#line 2 "modulus/mint.unit.random-test.cpp"

#include <cassert>
using namespace std;

int main() {
    constexpr int MOD = 1000000007;

    // ctor
    assert (mint<MOD>(-2).value == MOD - 2);
    assert (mint<MOD>(1000ll * MOD + 3).value == 3);

    // pow
    assert (mint<MOD>(2).pow(3) == 8);
    assert (mint<MOD>(2).pow(MOD - 1) == 1);
    assert (mint<MOD>(7).pow(MOD - 2) * 7 == 1);
    assert (mint<MOD>(42).pow(MOD - 1) == 1);

    // inv
    assert (mint<256>(1).inv() * 1 == 1);
    assert (mint<256>(3).inv() * 3 == 1);
    assert (mint<256>(5).inv() * 5 == 1);
    assert (mint<256>(7).inv() * 7 == 1);
    assert (mint<256>(13).inv() * 13 == 1);
    assert (mint<MOD>(1).inv() * 1 == 1);
    assert (mint<MOD>(2).inv() * 2 == 1);
    assert (mint<MOD>(3).inv() * 3 == 1);
    assert (mint<MOD>(4).inv() * 4 == 1);
    assert (mint<MOD>(42).inv() * 42 == 1);
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

