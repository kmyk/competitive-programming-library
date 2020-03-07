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


# VerificationStatus.VERIFIED modulus/modsqrt.yosupo.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/modsqrt.yosupo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-31 00:22:07+09:00


* see: <a href="https://judge.yosupo.jp/problem/sqrt_mod">https://judge.yosupo.jp/problem/sqrt_mod</a>


## Depends on

* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modsqrt.hpp.html">find the sqrt $b$ of $a$ modulo $p$ <small>(modulus/modsqrt.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "modulus/modsqrt.hpp"
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int y, p; scanf("%d%d", &y, &p);
        int x = modsqrt(y, p);
        printf("%d\n", x);
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "modulus/modsqrt.yosupo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#line 2 "modulus/modsqrt.hpp"
#include <cassert>
#include <cstdint>
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
#line 5 "modulus/modsqrt.hpp"

/**
 * @brief find the sqrt $b$ of $a$ modulo $p$
 * @param p must be a prime
 * @note i.e. $b^2 \equiv a \pmod{p}$
 * @note -1 if not found
 */
int modsqrt(int a, int p) {
    auto legendre_symbol = [&](int a) {
        return modpow(a, (p - 1) / 2, p);  // Euler's criterion
    };
    a %= p;
    if (a == 0) return 0;
    if (p == 2) return a;
    assert (p >= 3);
    if (legendre_symbol(a) != +1) return -1;
    int b = 1;
    while (legendre_symbol(b) == 1) {
        b += 1;
    }
    int e = 0;
    int m = p - 1;
    while (m % 2 == 0) {
        m /= 2;
        e += 1;
    }
    int64_t x = modpow(a, (m - 1) / 2, p);
    int64_t y = a * x % p * x % p;
    x = x * a % p;
    int64_t z = modpow(b, m, p);
    while (y != 1) {
        int j = 0;
        for (int64_t t = y; t != 1; t = t * t % p) ++ j;
        if (e <= j) return -1;
        z = modpow(z, 1ll << (e - j - 1), p);
        x = x * z % p;
        z = z * z % p;
        y = y * z % p;
        e = j;
    }
    assert (x * x % p == a);
    return x;
}
#line 4 "modulus/modsqrt.yosupo.test.cpp"
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int y, p; scanf("%d%d", &y, &p);
        int x = modsqrt(y, p);
        printf("%d\n", x);
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

