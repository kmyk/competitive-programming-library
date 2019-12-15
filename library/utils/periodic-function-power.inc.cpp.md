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


# :warning: utils/periodic-function-power.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/periodic-function-power.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-12-25 19:08:00 +0900




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class F, class T>
T periodic_function_power(F f, ll k, T x) {
    assert (k >= 1);
    if (k == 1) return x;
    vector<T> history;
    unordered_map<T, int> lookup;
    history.push_back(x);
    lookup[x] = 0;
    for (int i = 1; ; ++ i) {
        T y = f(x);
        if (i == k) return y;
        if (lookup.count(y)) break;
        history.push_back(y);
        lookup[y] = lookup[x] + 1;
        x = y;
    }
    T y = f(x);
    int base = lookup[y];
    int cycle = lookup[x] + 1 - lookup[y];
    return history[(k - base) % cycle + base];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/periodic-function-power.inc.cpp"
template <class F, class T>
T periodic_function_power(F f, ll k, T x) {
    assert (k >= 1);
    if (k == 1) return x;
    vector<T> history;
    unordered_map<T, int> lookup;
    history.push_back(x);
    lookup[x] = 0;
    for (int i = 1; ; ++ i) {
        T y = f(x);
        if (i == k) return y;
        if (lookup.count(y)) break;
        history.push_back(y);
        lookup[y] = lookup[x] + 1;
        x = y;
    }
    T y = f(x);
    int base = lookup[y];
    int cycle = lookup[x] + 1 - lookup[y];
    return history[(k - base) % cycle + base];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

