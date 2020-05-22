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


# :warning: old/factoradic.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/factoradic.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-23 00:47:48+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class RandomAccessIterator>
uint64_t encode_factoradic(RandomAccessIterator first, RandomAccessIterator last) { // O(N^2)
    static vector<int> fact(1, 1);
    while (fact.size() < n) {
        fact.push_back(fact.size() * fact.back());
    }
    int n = last - first;
    uint64_t y = 0;
    REP (i, n) {
        int xi = *(first + i);
        int rank = count_if(first, first + i, [&](int xj) { return xi < xj; });
        y += rank * fact[i];
    }
    return y;
}
vector<int> decode_factoradic(uint64_t y, int n) { // O(N^2)
    static vector<int> fact(1, 1);
    while (fact.size() < n) {
        fact.push_back(fact.size() * fact.back());
    }
    vector<int> xs(n);
    vector<int> zs(n); iota(zs.begin(), zs.end(), 0);
    REP_R (i, n) {
        auto it = zs.begin() + (i - y / fact[i]);
        xs[i] = *it;
        zs.erase(it);
        y %= fact[i];
    }
    return xs;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/factoradic.inc.cpp"
template <class RandomAccessIterator>
uint64_t encode_factoradic(RandomAccessIterator first, RandomAccessIterator last) { // O(N^2)
    static vector<int> fact(1, 1);
    while (fact.size() < n) {
        fact.push_back(fact.size() * fact.back());
    }
    int n = last - first;
    uint64_t y = 0;
    REP (i, n) {
        int xi = *(first + i);
        int rank = count_if(first, first + i, [&](int xj) { return xi < xj; });
        y += rank * fact[i];
    }
    return y;
}
vector<int> decode_factoradic(uint64_t y, int n) { // O(N^2)
    static vector<int> fact(1, 1);
    while (fact.size() < n) {
        fact.push_back(fact.size() * fact.back());
    }
    vector<int> xs(n);
    vector<int> zs(n); iota(zs.begin(), zs.end(), 0);
    REP_R (i, n) {
        auto it = zs.begin() + (i - y / fact[i]);
        xs[i] = *it;
        zs.erase(it);
        y %= fact[i];
    }
    return xs;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

