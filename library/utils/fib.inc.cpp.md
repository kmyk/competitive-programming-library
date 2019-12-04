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


# :warning: utils/fib.inc.cpp
* category: utils


[Back to top page](../../index.html)



## Code
```cpp
int fib(ll n, int mod) {
    assert (3 * pow(mod, 2) < pow(2, 63));
    assert (n >= 0);
    if (n <= 1) return n;
    int a = 0;
    int b = 1;
    ll i = 1ll << (63 - __builtin_clzll(n) - 1);
    for (; i; i >>= 1) {
        int na = (a *(ll) a + b *(ll) b) % mod;
        int nb = (2ll * a + b) * b % mod;
        a = na;
        b = nb;
        if (n & i) {
            int c = a + b; if (c >= mod) c -= mod;
            a = b;
            b = c;
        }
    }
    return b;
}

```

[Back to top page](../../index.html)

