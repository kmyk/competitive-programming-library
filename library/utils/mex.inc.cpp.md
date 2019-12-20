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


# :warning: minimum excluded value <small>(utils/mex.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/mex.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-06-02 16:57:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief minimum excluded value
 * @link https://en.wikipedia.org/wiki/Mex_(mathematics)
 * @link https://kimiyuki.net/blog/2015/12/19/srm-676-med/
 */
template <typename C>
int mex(C const & xs) {
    int y = 0;
    for (int x : xs) { // xs must be sorted (duplication is permitted)
        if (y <  x) break;
        if (y == x) ++ y;
    }
    return y;
}

/**
 * @link https://kimiyuki.net/blog/2015/12/02/cf-603-c/
 */
int mex(int a, int b) {
    for (int i = 0; ; ++ i) {
        if (i != a and i != b) {
            return i;
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/mex.inc.cpp"
/**
 * @brief minimum excluded value
 * @link https://en.wikipedia.org/wiki/Mex_(mathematics)
 * @link https://kimiyuki.net/blog/2015/12/19/srm-676-med/
 */
template <typename C>
int mex(C const & xs) {
    int y = 0;
    for (int x : xs) { // xs must be sorted (duplication is permitted)
        if (y <  x) break;
        if (y == x) ++ y;
    }
    return y;
}

/**
 * @link https://kimiyuki.net/blog/2015/12/02/cf-603-c/
 */
int mex(int a, int b) {
    for (int i = 0; ; ++ i) {

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

