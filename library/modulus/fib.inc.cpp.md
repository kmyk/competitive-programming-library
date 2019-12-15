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


# :warning: modulus/fib.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/fib.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-12-30 16:00:47 +0900




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
const int mod = 1e9+7;
ll fib(ll n) {
    static unordered_map<ll,int> memo;
    if (memo.count(n)) return memo[n];
    if (n == 0 or n== 1) return memo[n] = 1;
    ll a = n/2, b = (n+1)/2;
    return memo[n] = (fib(a)*(ll)fib(b) + fib(a-1)*(ll)fib(b-1)) % mod;
}

// use matrix operator *
// 2x faster then fib(n/2)*...
const ll mod = 1e9+7;
ll fib(ll n) {
    vector<vector<ll> > f(2, vector<ll>(2));
    vector<vector<ll> > e(2, vector<ll>(2));
    f[0][0] = f[1][1] = 1;
    e[0][0] = e[0][1] = e[1][0] = 1;
    for (ll i = 1; i <= n; i <<= 1) {
        if (n & i) f = f * e;
        e = e * e;
    }
    return f[0][0];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "modulus/fib.inc.cpp"
const int mod = 1e9+7;
ll fib(ll n) {
    static unordered_map<ll,int> memo;
    if (memo.count(n)) return memo[n];
    if (n == 0 or n== 1) return memo[n] = 1;
    ll a = n/2, b = (n+1)/2;
    return memo[n] = (fib(a)*(ll)fib(b) + fib(a-1)*(ll)fib(b-1)) % mod;
}

// use matrix operator *
// 2x faster then fib(n/2)*...
const ll mod = 1e9+7;
ll fib(ll n) {
    vector<vector<ll> > f(2, vector<ll>(2));
    vector<vector<ll> > e(2, vector<ll>(2));
    f[0][0] = f[1][1] = 1;
    e[0][0] = e[0][1] = e[1][0] = 1;
    for (ll i = 1; i <= n; i <<= 1) {
        if (n & i) f = f * e;
        e = e * e;
    }
    return f[0][0];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

