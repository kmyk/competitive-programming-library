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


# :warning: utils/coordinate-compression.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/coordinate-compression.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-01-05 16:41:32 +0900




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
map<T, int> coordinate_compression_map(vector<T> const & xs) {
    int n = xs.size();
    vector<int> ys(n);
    iota(ALL(ys), 0);
    sort(ALL(ys), [&](int i, int j) { return xs[i] < xs[j]; });
    map<T, int> f;
    for (int i : ys) {
        if (not f.count(xs[i])) { // make unique
            int j = f.size();
            f[xs[i]] = j; // f[xs[i]] has a side effect, increasing the f.size()
        }
    }
    return f;
}

template <typename T>
vector<int> apply_compression(map<T, int> const & f, vector<T> const & xs) {
    int n = xs.size();
    vector<int> ys(n);
    REP (i, n) ys[i] = f.at(xs[i]);
    return ys;
}

unittest {
    vector<int> xs { 5, 3, 1, 8, 1, -2, 8 };
    auto compress = coordinate_compression_map(xs);
    vector<int> ys { 3, 2, 1, 4, 1,  0, 4 };
    assert (ys == apply_compression(compress, xs));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/coordinate-compression.inc.cpp"
template <typename T>
map<T, int> coordinate_compression_map(vector<T> const & xs) {
    int n = xs.size();
    vector<int> ys(n);
    iota(ALL(ys), 0);
    sort(ALL(ys), [&](int i, int j) { return xs[i] < xs[j]; });
    map<T, int> f;
    for (int i : ys) {
        if (not f.count(xs[i])) { // make unique
            int j = f.size();
            f[xs[i]] = j; // f[xs[i]] has a side effect, increasing the f.size()
        }
    }
    return f;
}

template <typename T>
vector<int> apply_compression(map<T, int> const & f, vector<T> const & xs) {
    int n = xs.size();
    vector<int> ys(n);
    REP (i, n) ys[i] = f.at(xs[i]);
    return ys;
}

unittest {
    vector<int> xs { 5, 3, 1, 8, 1, -2, 8 };
    auto compress = coordinate_compression_map(xs);
    vector<int> ys { 3, 2, 1, 4, 1,  0, 4 };
    assert (ys == apply_compression(compress, xs));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

