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


# :heavy_check_mark: number/matrix_template.yukicoder-1073.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/matrix_template.yukicoder-1073.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-05 23:45:06+09:00


* see: <a href="https://yukicoder.me/problems/no/1073">https://yukicoder.me/problems/no/1073</a>


## Depends on

* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/number/matrix_template.hpp.html">number/matrix_template.hpp</a>
* :question: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1073"
#include "number/matrix_template.hpp"
#include "modulus/mint.hpp"
#include <iostream>
using namespace std;


constexpr int MOD = 1000000007;
mint<MOD> solve(int64_t n) {
    matrix<mint<MOD>, 6, 6> f = {{
        {{ 0, 0, 0, 0, 0, mint<MOD>(6).inv() }},
        {{ 1, 0, 0, 0, 0, mint<MOD>(6).inv() }},
        {{ 0, 1, 0, 0, 0, mint<MOD>(6).inv() }},
        {{ 0, 0, 1, 0, 0, mint<MOD>(6).inv() }},
        {{ 0, 0, 0, 1, 0, mint<MOD>(6).inv() }},
        {{ 0, 0, 0, 0, 1, mint<MOD>(6).inv() }},
    }};
    array<mint<MOD>, 6> x = {{
        0,
        0,
        0,
        0,
        0,
        1,
    }};
    return (powmat(f, n) * x)[5];
}

int main() {
    int64_t n; cin >> n;
    auto ans = solve(n);
    cout << ans << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "number/matrix_template.yukicoder-1073.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1073"
#line 2 "number/matrix_template.hpp"
#include <array>
#include <cstdint>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 5 "number/matrix_template.hpp"

template <typename T, size_t H, size_t W>
using matrix = std::array<std::array<T, W>, H>;

template <typename T, size_t A, size_t B, size_t C>
matrix<T, A, C> operator * (matrix<T, A, B> const & a, matrix<T, B, C> const & b) {
    matrix<T, A, C> c = {};
    REP (y, A) REP (z, B) REP (x, C) c[y][x] += a[y][z] * b[z][x];
    return c;
}
template <typename T, size_t H, size_t W>
std::array<T, H> operator * (matrix<T, H, W> const & a, std::array<T, W> const & b) {
    std::array<T, H> c = {};
    REP (y, H) REP (z, W) c[y] += a[y][z] * b[z];
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T, H, W> operator + (matrix<T, H, W> const & a, matrix<T, H, W> const & b) {
    matrix<T, H, W> c;
    REP (y, H) REP (x, W) c[y][x] = a[y][x] + b[y][x];
    return c;
}

template <typename T, size_t N>
std::array<T, N> operator + (std::array<T, N> const & a, std::array<T, N> const & b) {
    std::array<T, N> c;
    REP (i, N) c[i] = a[i] + b[i];
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T, H, W> zero_matrix() {
    return {};
}

template <typename T, size_t N>
matrix<T, N, N> unit_matrix() {
    matrix<T, N, N> a = {};
    REP (i, N) a[i][i] = 1;
    return a;
}

template <typename T, size_t N>
matrix<T, N, N> powmat(matrix<T, N, N> x, int64_t k) {
    matrix<T, N, N> y = unit_matrix<T, N>();
    for (; k; k >>= 1) {
        if (k & 1) y = y * x;
        x = x * x;
    }
    return y;
}
#line 2 "modulus/mint.hpp"
#include <algorithm>
#include <cassert>
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
#line 5 "number/matrix_template.yukicoder-1073.test.cpp"
using namespace std;


constexpr int MOD = 1000000007;
mint<MOD> solve(int64_t n) {
    matrix<mint<MOD>, 6, 6> f = {{
        {{ 0, 0, 0, 0, 0, mint<MOD>(6).inv() }},
        {{ 1, 0, 0, 0, 0, mint<MOD>(6).inv() }},
        {{ 0, 1, 0, 0, 0, mint<MOD>(6).inv() }},
        {{ 0, 0, 1, 0, 0, mint<MOD>(6).inv() }},
        {{ 0, 0, 0, 1, 0, mint<MOD>(6).inv() }},
        {{ 0, 0, 0, 0, 1, mint<MOD>(6).inv() }},
    }};
    array<mint<MOD>, 6> x = {{
        0,
        0,
        0,
        0,
        0,
        1,
    }};
    return (powmat(f, n) * x)[5];
}

int main() {
    int64_t n; cin >> n;
    auto ans = solve(n);
    cout << ans << endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

