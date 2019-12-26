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


# :warning: the baby-step giant-step <small>(modulus/modsqrt_modlog.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/modsqrt_modlog.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-26 23:56:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @param m must be a positive integer
 * @note O(log y)
 */
ll modpow(ll x, ll y, int m) {
    assert (0 <= x and x < m);
    assert (0 <= y);
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % m;
        x = x * x % m;
    }
    return z;
}

/**
 * @param p must be a prime
 * @note O(log p)
 */
ll modinv(ll x, int p) {
    assert (x % p != 0);
    return modpow(x, p - 2, p);
}

/**
 * @note x and m must be relatively prime
 * @note O(log m)
 */
ll modinv(ll x, int m) {
    assert (1 <= x and x < m);
    ll y, d; tie(y, ignore, d) = extgcd(x, m);
    if (d != 1) return 0;  // no inverse
    if (y < 0) y += m;
    assert (x * y % m == 1);
    return (y % m + m) % m;
}

/**
 * @brief the baby-step giant-step
 * @description find the smallest x >= 0 s.t. g^x = y mod m
 * @note O(sqrt(m))
 * @note meet-in-the-middle; let x = a sqrt(m) + b
 */
ll modlog(ll g, ll y, int m) {
    if (y == 0) return -1;
    ll sqrt_m = sqrt(m);  // as a real

    // baby-step
    unordered_map<ll, int> baby;
    ll gb = 1;
    REP (b, sqrt_m + 3) {
        baby[gb] = b;
        gb = gb * g % m;
    }

    // giant-step
    ll g_sqrt_m_inv = modinv(modpow(g, sqrt_m, m), m);
    ll giant = y;
    REP (a, sqrt_m + 3) {
        if (baby.count(giant)) {
            int b = baby[giant];
            ll x = a * sqrt_m + b;
            assert (modpow(g, x % m, m) == y);
            return x % m;
        }
        giant = giant * g_sqrt_m_inv % m;
    }
    return -1;
}

struct prepared_modlog {
    static constexpr double RATE = 0.7;
    const ll g;
    const int p;
    int sqrt_p;
    unordered_map<ll, int> baby;
    ll g_sqrt_p_inv;

    prepared_modlog(ll g_, int p_)
            : g(g_), p(p_) {
        sqrt_p = pow(p, RATE);  // as a real
        g_sqrt_p_inv = modinv(modpow(g, sqrt_p, p), p);

        // baby-step
        ll gb = 1;
        REP (b, sqrt_p + 3) {
            baby[gb] = b;
            gb = gb * g % p;
        }
    }

    ll operator () (ll y) const {
        // giant-step
        ll giant = y;
        REP (a, sqrt_p + 3) {
            auto it = baby.find(giant);
            if (it != baby.end()) {
                int b = it->second;
                ll x = a * sqrt_p + b;
                return x % p;
            }
            giant = giant * g_sqrt_p_inv % p;
        }
        return -1;
    }
};

int legendre_symbol(int a, int p) {
    return powmod(a, (p - 1) / 2, p); // Euler's criterion
}
int modsqrt(int a, int p) {
    a %= p;
    if (a == 0) return 0;
    if (p == 2) return a;
    assert (p >= 3);
    if (legendre_symbol(a, p) != +1) return -1;
    int b = 1;
    while (legendre_symbol(b, p) == 1) {
        b += 1;
    }
    int e = 0;
    int m = p - 1;
    while (m % 2 == 0) {
        m /= 2;
        e += 1;
    }
    ll x = powmod(a, (m - 1) / 2, p);
    ll y = a * x % p * x % p;
    x = x * a % p;
    ll z = powmod(b, m, p);
    while (y != 1) {
        int j = 0;
        for (ll t = y; t != 1; t = t * t % p) ++ j;
        if (e <= j) return -1;
        z = powmod(z, 1ll << (e - j - 1), p);
        x = x * z % p;
        z = z * z % p;
        y = y * z % p;
        e = j;
    }
    assert (x * x % p == a);
    return x;
}

unittest {
    for (int p : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 1009, 1000000007 }) {
        repeat (a, min(p - 1, 42)) {
            if (legendre_symbol(a, p) == 1) {
                ll x = modsqrt(a, p);
                assert (x * x % p == a);
            }
        }
    }
}

// https://yukicoder.me/problems/no/551
vector<int> solve_modeqn(int a, int b, int c, int p) { // ax^2 + bx + c = 0 mod p
    int d = (b *(ll) b - 4ll * a * c) % p;
    if (d < 0) d += p;
    int w = modsqrt(d, p);
    if (w == -1) return vector<int>();
    vector<int> xs;
    xs.push_back((- b + w) *(ll) modinv(2 * a % p, p) % p);
    xs.push_back((- b - w) *(ll) modinv(2 * a % p, p) % p);
    if (xs[0] < 0) xs[0] += p;
    if (xs[1] < 0) xs[1] += p;
    whole(sort, xs);
    xs.erase(whole(unique, xs), xs.end());
    return xs;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "modulus/modsqrt_modlog.inc.cpp"
/**
 * @param m must be a positive integer
 * @note O(log y)
 */
ll modpow(ll x, ll y, int m) {
    assert (0 <= x and x < m);
    assert (0 <= y);
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % m;
        x = x * x % m;
    }
    return z;
}

/**
 * @param p must be a prime
 * @note O(log p)
 */
ll modinv(ll x, int p) {
    assert (x % p != 0);
    return modpow(x, p - 2, p);
}

/**
 * @note x and m must be relatively prime
 * @note O(log m)
 */
ll modinv(ll x, int m) {
    assert (1 <= x and x < m);
    ll y, d; tie(y, ignore, d) = extgcd(x, m);
    if (d != 1) return 0;  // no inverse
    if (y < 0) y += m;
    assert (x * y % m == 1);
    return (y % m + m) % m;
}

/**
 * @brief the baby-step giant-step
 * @description find the smallest x >= 0 s.t. g^x = y mod m
 * @note O(sqrt(m))
 * @note meet-in-the-middle; let x = a sqrt(m) + b
 */
ll modlog(ll g, ll y, int m) {
    if (y == 0) return -1;
    ll sqrt_m = sqrt(m);  // as a real

    // baby-step
    unordered_map<ll, int> baby;
    ll gb = 1;
    REP (b, sqrt_m + 3) {
        baby[gb] = b;
        gb = gb * g % m;
    }

    // giant-step
    ll g_sqrt_m_inv = modinv(modpow(g, sqrt_m, m), m);
    ll giant = y;
    REP (a, sqrt_m + 3) {
        if (baby.count(giant)) {
            int b = baby[giant];
            ll x = a * sqrt_m + b;
            assert (modpow(g, x % m, m) == y);
            return x % m;
        }
        giant = giant * g_sqrt_m_inv % m;
    }
    return -1;
}

struct prepared_modlog {
    static constexpr double RATE = 0.7;
    const ll g;
    const int p;
    int sqrt_p;
    unordered_map<ll, int> baby;
    ll g_sqrt_p_inv;

    prepared_modlog(ll g_, int p_)
            : g(g_), p(p_) {
        sqrt_p = pow(p, RATE);  // as a real
        g_sqrt_p_inv = modinv(modpow(g, sqrt_p, p), p);

        // baby-step
        ll gb = 1;
        REP (b, sqrt_p + 3) {
            baby[gb] = b;
            gb = gb * g % p;
        }
    }

    ll operator () (ll y) const {
        // giant-step
        ll giant = y;
        REP (a, sqrt_p + 3) {
            auto it = baby.find(giant);
            if (it != baby.end()) {
                int b = it->second;
                ll x = a * sqrt_p + b;
                return x % p;
            }
            giant = giant * g_sqrt_p_inv % p;
        }
        return -1;
    }
};

int legendre_symbol(int a, int p) {
    return powmod(a, (p - 1) / 2, p); // Euler's criterion
}
int modsqrt(int a, int p) {
    a %= p;
    if (a == 0) return 0;
    if (p == 2) return a;
    assert (p >= 3);
    if (legendre_symbol(a, p) != +1) return -1;
    int b = 1;
    while (legendre_symbol(b, p) == 1) {
        b += 1;
    }
    int e = 0;
    int m = p - 1;
    while (m % 2 == 0) {
        m /= 2;
        e += 1;
    }
    ll x = powmod(a, (m - 1) / 2, p);
    ll y = a * x % p * x % p;
    x = x * a % p;
    ll z = powmod(b, m, p);
    while (y != 1) {
        int j = 0;
        for (ll t = y; t != 1; t = t * t % p) ++ j;
        if (e <= j) return -1;
        z = powmod(z, 1ll << (e - j - 1), p);
        x = x * z % p;
        z = z * z % p;
        y = y * z % p;
        e = j;
    }
    assert (x * x % p == a);
    return x;
}

unittest {
    for (int p : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 1009, 1000000007 }) {
        repeat (a, min(p - 1, 42)) {
            if (legendre_symbol(a, p) == 1) {
                ll x = modsqrt(a, p);
                assert (x * x % p == a);
            }
        }
    }
}

// https://yukicoder.me/problems/no/551
vector<int> solve_modeqn(int a, int b, int c, int p) { // ax^2 + bx + c = 0 mod p
    int d = (b *(ll) b - 4ll * a * c) % p;
    if (d < 0) d += p;
    int w = modsqrt(d, p);
    if (w == -1) return vector<int>();
    vector<int> xs;
    xs.push_back((- b + w) *(ll) modinv(2 * a % p, p) % p);
    xs.push_back((- b - w) *(ll) modinv(2 * a % p, p) % p);
    if (xs[0] < 0) xs[0] += p;
    if (xs[1] < 0) xs[1] += p;
    whole(sort, xs);
    xs.erase(whole(unique, xs), xs.end());
    return xs;
}


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

