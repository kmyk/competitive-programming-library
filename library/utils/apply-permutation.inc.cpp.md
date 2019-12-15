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


# :warning: utils/apply-permutation.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/apply-permutation.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-01-05 16:41:32 +0900




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @note O(N) time, O(N) space
 */
template <typename T>
vector<T> apply_permutation(vector<int> const & sigma, vector<T> const & xs) {
    int n = sigma.size();
    vector<T> ys(n);
    REP (i, n) ys[i] = xs[sigma[i]];
    return ys;
}

unittest {
    vector<char> xs { 'a', 'b', 'c', 'd', 'e' };
    vector<int> sigma { 4, 3, 2, 0, 1 };
    vector<char> ys { 'e', 'd', 'c', 'a', 'b' };
    assert (ys == apply_permutation(sigma, xs));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/apply-permutation.inc.cpp"
/**
 * @note O(N) time, O(N) space
 */
template <typename T>
vector<T> apply_permutation(vector<int> const & sigma, vector<T> const & xs) {
    int n = sigma.size();
    vector<T> ys(n);
    REP (i, n) ys[i] = xs[sigma[i]];
    return ys;
}

unittest {
    vector<char> xs { 'a', 'b', 'c', 'd', 'e' };
    vector<int> sigma { 4, 3, 2, 0, 1 };

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

