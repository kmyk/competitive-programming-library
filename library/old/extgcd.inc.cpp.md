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


# VerificationStatus.DEFAULT extended gcd <small>(old/extgcd.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/extgcd.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00


* see: <a href="https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466">https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief extended gcd
 * @description for given a and b, find x, y and gcd(a, b) such that ax + by = 1
 * @note O(log n)
 * @see https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466
 */
tuple<ll, ll, ll> extgcd(ll a, ll b) {
    ll x = 0, y = 1;
    for (ll u = 1, v = 0; a; ) {
        ll q = b / a;
        x -= q * u; swap(x, u);
        y -= q * v; swap(y, v);
        b -= q * a; swap(b, a);
    }
    return make_tuple(x, y, b);
}
unittest {
    random_device device;
    default_random_engine gen(device());
    REP (iteration, 1000) {
        ll a = uniform_int_distribution<ll>(1, 10000)(gen);
        ll b = uniform_int_distribution<ll>(1, 10000)(gen);
        ll x, y, d; tie(x, y, d) = extgcd(a, b);
        assert (a * x + b * y == d);
        assert (d == __gcd(a, b));
    }
}

/**
 * @note recursive version (slow)
 */
pair<int, int> extgcd_recursive(int a, int b) {
    if (b == 0) return { 1, 0 };
    int na, nb; tie(na, nb) = extgcd(b, a % b);
    return { nb, na - a/b * nb };
}

/**
 * @note x and m must be relatively prime
 * @note O(log m)
 */
ll modinv(ll x, int m) {
    assert (1 <= x and x < m);
    ll y, d; tie(y, ignore, d) = extgcd(x, m);
    if (d != 1) return 0;  // no inverse
    assert (x * y % m == 1);
    return (y % m + m) % m;
}

/**
 * @brief chinese remainder theorem
 * @note the unit element is (0, 1)
 */
pair<ll, ll> crt(pair<ll, ll> eqn1, pair<ll, ll> eqn2) {
    ll x1, m1; tie(x1, m1) = eqn1;
    ll x2, m2; tie(x2, m2) = eqn2;
    ll x = x1 + m1 * (x2 - x1) * modinv(m1 % m2, m2);
    ll m = m1 * m2;
    return { (x % m + m) % m, m };
}

ll multmod(ll a, ll b, ll m) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    ll c = 0;
    REP (i, 63) {
        if (b & (1ll << i)) {
            c += a;
            if (c > m) c -= m;
        }
        a *= 2;
        if (a > m) a -= m;
    }
    return c;
}

pair<ll, ll> crt(pair<ll, ll> eqn1, pair<ll, ll> eqn2) {
    ll x1, m1; tie(x1, m1) = eqn1;
    ll x2, m2; tie(x2, m2) = eqn2;
    if (m1 == 0 or m2 == 0) return make_pair(0ll, 0ll);
    assert (1 <= m1 and 1 <= m2);
    ll m1_inv, d; tie(m1_inv, ignore, d) = extgcd(m1, m2);
    if ((x1 - x2) % d) return make_pair(0ll, 0ll);
    ll m = m1 * m2 / d;
    // ll x = x1 + (m1 / d) * (x2 - x1) % m * (m1_inv % m) % m;
    ll x = x1 + multmod(multmod(m1 / d, x2 - x1, m), m1_inv, m);
    return make_pair((x % m + m) % m, m);
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/extgcd.inc.cpp"
/**
 * @brief extended gcd
 * @description for given a and b, find x, y and gcd(a, b) such that ax + by = 1
 * @note O(log n)
 * @see https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466
 */
tuple<ll, ll, ll> extgcd(ll a, ll b) {
    ll x = 0, y = 1;
    for (ll u = 1, v = 0; a; ) {
        ll q = b / a;
        x -= q * u; swap(x, u);
        y -= q * v; swap(y, v);
        b -= q * a; swap(b, a);
    }
    return make_tuple(x, y, b);
}
unittest {
    random_device device;
    default_random_engine gen(device());
    REP (iteration, 1000) {
        ll a = uniform_int_distribution<ll>(1, 10000)(gen);
        ll b = uniform_int_distribution<ll>(1, 10000)(gen);
        ll x, y, d; tie(x, y, d) = extgcd(a, b);
        assert (a * x + b * y == d);
        assert (d == __gcd(a, b));
    }
}

/**
 * @note recursive version (slow)
 */
pair<int, int> extgcd_recursive(int a, int b) {
    if (b == 0) return { 1, 0 };
    int na, nb; tie(na, nb) = extgcd(b, a % b);
    return { nb, na - a/b * nb };
}

/**
 * @note x and m must be relatively prime
 * @note O(log m)
 */
ll modinv(ll x, int m) {
    assert (1 <= x and x < m);
    ll y, d; tie(y, ignore, d) = extgcd(x, m);
    if (d != 1) return 0;  // no inverse
    assert (x * y % m == 1);
    return (y % m + m) % m;
}

/**
 * @brief chinese remainder theorem
 * @note the unit element is (0, 1)
 */
pair<ll, ll> crt(pair<ll, ll> eqn1, pair<ll, ll> eqn2) {
    ll x1, m1; tie(x1, m1) = eqn1;
    ll x2, m2; tie(x2, m2) = eqn2;
    ll x = x1 + m1 * (x2 - x1) * modinv(m1 % m2, m2);
    ll m = m1 * m2;
    return { (x % m + m) % m, m };
}

ll multmod(ll a, ll b, ll m) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    ll c = 0;
    REP (i, 63) {
        if (b & (1ll << i)) {
            c += a;
            if (c > m) c -= m;
        }
        a *= 2;
        if (a > m) a -= m;
    }
    return c;
}

pair<ll, ll> crt(pair<ll, ll> eqn1, pair<ll, ll> eqn2) {
    ll x1, m1; tie(x1, m1) = eqn1;
    ll x2, m2; tie(x2, m2) = eqn2;
    if (m1 == 0 or m2 == 0) return make_pair(0ll, 0ll);
    assert (1 <= m1 and 1 <= m2);
    ll m1_inv, d; tie(m1_inv, ignore, d) = extgcd(m1, m2);
    if ((x1 - x2) % d) return make_pair(0ll, 0ll);
    ll m = m1 * m2 / d;
    // ll x = x1 + (m1 / d) * (x2 - x1) % m * (m1_inv % m) % m;
    ll x = x1 + multmod(multmod(m1 / d, x2 - x1, m), m1_inv, m);
    return make_pair((x % m + m) % m, m);
}


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

