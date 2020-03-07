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


# VerificationStatus.VERIFIED discrete log / 離散対数 (the baby-step giant-step, $O(\sqrt{m})$) <small>(modulus/modlog.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/modlog.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-22 23:03:03+09:00




## Depends on

* :heavy_check_mark: <a href="modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/modulus/modlog.yosupo.test.cpp.html">modulus/modlog.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <unordered_map>
#include "modulus/modinv.hpp"
#include "modulus/modpow.hpp"
#include "utils/macros.hpp"
#include <iostream>

/**
 * @brief discrete log / 離散対数 (the baby-step giant-step, $O(\sqrt{m})$)
 * @description find the smallest $x \ge 0$ s.t. $g^x \equiv y \pmod{m}$
 * @param m is a positive integer
 * @note -1 if not found
 */
inline int modlog(int g, int y, int m) {
    assert (0 <= g and g < m);
    assert (0 <= y and y < m);
    if (m == 1) return 0;
    if (y == 1) return 0;
    if (g == 0 and y == 0) return 1;

    // meet-in-the-middle; let x = a \sqrt{m} + b
    int sqrt_m = sqrt(m) + 100;  // + 100 is required to bruteforce g^b for b < 100; this avoids problems with g != 0 and y = 0
    assert (sqrt_m >= 0);

    // baby-step: list (y, gy, g^2 y, ...) = (g^x, g^{x + 1}, g^{x + 2}, ...)
    std::unordered_map<int, int> table;
    int baby = 1;
    REP (b, sqrt_m) {
        if (baby == y) return b;
        table[(int64_t)baby * y % m] = b;
        baby = (int64_t)baby * g % m;
    }

    // giant-step: list (g^{sqrt(m)}, g^{2 sqrt(m)}, g^{3 sqrt(m)}, ...)
    int giant = 1;
    REP3 (a, 1, sqrt_m + 3) {
        giant = (int64_t)giant * baby % m;
        auto it = table.find(giant);
        if (it != table.end()) {
            int b = it->second;
            int x = (int64_t)a * sqrt_m - b;
            assert (x >= 0);
            return (modpow(g, x, m) == y ? x : -1);
        }
    }
    return -1;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modulus/modlog.hpp"
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <unordered_map>
#line 3 "modulus/modinv.hpp"
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
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 10 "modulus/modlog.hpp"
#include <iostream>

/**
 * @brief discrete log / 離散対数 (the baby-step giant-step, $O(\sqrt{m})$)
 * @description find the smallest $x \ge 0$ s.t. $g^x \equiv y \pmod{m}$
 * @param m is a positive integer
 * @note -1 if not found
 */
inline int modlog(int g, int y, int m) {
    assert (0 <= g and g < m);
    assert (0 <= y and y < m);
    if (m == 1) return 0;
    if (y == 1) return 0;
    if (g == 0 and y == 0) return 1;

    // meet-in-the-middle; let x = a \sqrt{m} + b
    int sqrt_m = sqrt(m) + 100;  // + 100 is required to bruteforce g^b for b < 100; this avoids problems with g != 0 and y = 0
    assert (sqrt_m >= 0);

    // baby-step: list (y, gy, g^2 y, ...) = (g^x, g^{x + 1}, g^{x + 2}, ...)
    std::unordered_map<int, int> table;
    int baby = 1;
    REP (b, sqrt_m) {
        if (baby == y) return b;
        table[(int64_t)baby * y % m] = b;
        baby = (int64_t)baby * g % m;
    }

    // giant-step: list (g^{sqrt(m)}, g^{2 sqrt(m)}, g^{3 sqrt(m)}, ...)
    int giant = 1;
    REP3 (a, 1, sqrt_m + 3) {
        giant = (int64_t)giant * baby % m;
        auto it = table.find(giant);
        if (it != table.end()) {
            int b = it->second;
            int x = (int64_t)a * sqrt_m - b;
            assert (x >= 0);
            return (modpow(g, x, m) == y ? x : -1);
        }
    }
    return -1;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

