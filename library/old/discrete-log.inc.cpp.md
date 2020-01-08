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


# :warning: old/discrete-log.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/discrete-log.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
uint32_t powmod(uint32_t g, uint32_t x, uint32_t p) {
    uint32_t y = 1;
    for (; x; x >>= 1) {
        if (x & 1) y = (uint64_t)y * g % p;
        g = (uint64_t)g * g % p;
    }
    return y;
}

uint32_t modinv(uint32_t g, uint32_t p) {
    return powmod(g, p - 2, p);  // p must be a prime
}

/**
 * @description find the smallest x >= 0 s.t. g^x = y mod p
 * @note O(sqrt(p))
 * @note meet-in-the-middle; let x = a sqrt(p) + b
 */
uint32_t baby_step_giant_step(uint32_t g, uint32_t y, uint32_t p) {
    uint32_t sqrt_p = sqrt(p);

    unordered_map<uint32_t, int> baby;
    uint32_t gb = 1;
    REP (b, sqrt_p + 3) {
        baby[gb] = b;
        gb = (uint64_t)gb * g % p;
    }

    uint32_t g_sqrt_p_inv = modinv(powmod(g, sqrt_p, p), p);
    uint32_t giant = y;
    REP (a, sqrt_p + 3) {
        if (baby.count(giant)) {
            int b = baby[giant];
            uint32_t x = a * sqrt_p + b;
            return x % p;
        }
        giant = (uint64_t)giant * g_sqrt_p_inv % p;
    }
    return -1;
}

unittest {
    assert (baby_step_giant_step( 3, powmod( 3,  0,  17),  17) ==  0);
    assert (baby_step_giant_step( 3, powmod( 3, 12,  17),  17) == 12);
    assert (baby_step_giant_step(12, powmod(12, 17, 101), 101) == 17);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/discrete-log.inc.cpp"
uint32_t powmod(uint32_t g, uint32_t x, uint32_t p) {
    uint32_t y = 1;
    for (; x; x >>= 1) {
        if (x & 1) y = (uint64_t)y * g % p;
        g = (uint64_t)g * g % p;
    }
    return y;
}

uint32_t modinv(uint32_t g, uint32_t p) {
    return powmod(g, p - 2, p);  // p must be a prime
}

/**
 * @description find the smallest x >= 0 s.t. g^x = y mod p
 * @note O(sqrt(p))
 * @note meet-in-the-middle; let x = a sqrt(p) + b
 */
uint32_t baby_step_giant_step(uint32_t g, uint32_t y, uint32_t p) {
    uint32_t sqrt_p = sqrt(p);

    unordered_map<uint32_t, int> baby;
    uint32_t gb = 1;
    REP (b, sqrt_p + 3) {
        baby[gb] = b;
        gb = (uint64_t)gb * g % p;
    }

    uint32_t g_sqrt_p_inv = modinv(powmod(g, sqrt_p, p), p);
    uint32_t giant = y;
    REP (a, sqrt_p + 3) {
        if (baby.count(giant)) {
            int b = baby[giant];
            uint32_t x = a * sqrt_p + b;
            return x % p;
        }
        giant = (uint64_t)giant * g_sqrt_p_inv % p;
    }
    return -1;
}

unittest {
    assert (baby_step_giant_step( 3, powmod( 3,  0,  17),  17) ==  0);
    assert (baby_step_giant_step( 3, powmod( 3, 12,  17),  17) == 12);
    assert (baby_step_giant_step(12, powmod(12, 17, 101), 101) == 17);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

