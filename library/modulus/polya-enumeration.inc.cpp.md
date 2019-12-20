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


# :warning: modulus/polya-enumeration.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/polya-enumeration.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-12-07 05:10:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @note using Polya enumeration theorem
 * @note factorization + O(d(n)^2 + sqrt n)
 */
template <int MOD>
mint<MOD> count_cycle_coloring(int n, int k) {
    auto primes = list_primes(sqrt(n) + 3);
    map<ll, int> factors = prime_factorize(n, primes);
    vector<ll> divs = list_divisors(n, primes);
    mint<MOD> cnt = 0;
    for (ll div : divs) {
        ll e = div;  // Euler's phi of div
        for (auto it : factors) {
            int p = it.first;
            if (div % p == 0) {
                e = e / p * (p - 1);
            }
        }
        cnt += mint<MOD>(k).pow(n / div) * e;
    }
    return cnt / n;
}

unittest {
    constexpr int MOD = 1e9 + 7;
    assert (count_cycle_coloring<MOD>(2, 10).value == 55);
    assert (count_cycle_coloring<MOD>(4, 10).value == 2530);
    assert (count_cycle_coloring<MOD>(4, 2).value == 6);
    assert (count_cycle_coloring<MOD>(1000000000, 1000000000).value == 898487047);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "modulus/polya-enumeration.inc.cpp"
/**
 * @note using Polya enumeration theorem
 * @note factorization + O(d(n)^2 + sqrt n)
 */
template <int MOD>
mint<MOD> count_cycle_coloring(int n, int k) {
    auto primes = list_primes(sqrt(n) + 3);
    map<ll, int> factors = prime_factorize(n, primes);
    vector<ll> divs = list_divisors(n, primes);
    mint<MOD> cnt = 0;
    for (ll div : divs) {
        ll e = div;  // Euler's phi of div
        for (auto it : factors) {
            int p = it.first;
            if (div % p == 0) {
                e = e / p * (p - 1);
            }
        }
        cnt += mint<MOD>(k).pow(n / div) * e;
    }
    return cnt / n;
}

unittest {
    constexpr int MOD = 1e9 + 7;
    assert (count_cycle_coloring<MOD>(2, 10).value == 55);
    assert (count_cycle_coloring<MOD>(4, 10).value == 2530);
    assert (count_cycle_coloring<MOD>(4, 2).value == 6);
    assert (count_cycle_coloring<MOD>(1000000000, 1000000000).value == 898487047);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

