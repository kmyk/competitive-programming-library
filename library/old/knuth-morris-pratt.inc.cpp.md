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


# :warning: Morris-Pratt algorithm <small>(old/knuth-morris-pratt.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/knuth-morris-pratt.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Morris-Pratt algorithm
 * @description compute the list of the lengthes of the longest borders
 * @note O(N)
 */
template <class Iterator>
vector<int> morris_pratt(Iterator first, Iterator last) {
    int length = distance(first, last);
    vector<int> border(length + 1);
    border[0] = -1;
    int j = -1;
    REP (i, length) {
        while (j >= 0 and pattern[i] != pattern[j]) {
            j = border[j];
        }
        ++ j;
        border[i + 1] = j;
    }
    return border;
}

/*
vector<int> kmp_build_fail(string const & pattern) { // O(m)
    int m = pattern.size();
    vector<int> fali(m+1);
    fail[0] = -1;
    int j = -1;
    repeat (i,m) {
        while (j >= 0 and pattern[i] != pattern[j]) j = fail[j];
        fail[i+1] = ++ j;
    }
    return fail;
}
int kmp_match(string const & target, string const & pattern, vector<int> const & fail) { // O(n+m)
    int n = target.length();
    int m = pattern.length();
    int result = 0;
    for (int i = 0, k = 0; i < n; ++ i) {
        while (k >= 0 and pattern[k] != target[i]) k = fail[k];
        if (++ k >= m) {
            ++ result; // match at t[i-m+1 .. i]
            k = fail[k];
        }
    }
    return result;
}
int kmp_match(string const & target, string const & pattern) {
    return kmp_match(target, pattern, kmp_build_fail(pattern));
}
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/knuth-morris-pratt.inc.cpp"
/**
 * @brief Morris-Pratt algorithm
 * @description compute the list of the lengthes of the longest borders
 * @note O(N)
 */
template <class Iterator>
vector<int> morris_pratt(Iterator first, Iterator last) {
    int length = distance(first, last);
    vector<int> border(length + 1);
    border[0] = -1;
    int j = -1;
    REP (i, length) {
        while (j >= 0 and pattern[i] != pattern[j]) {
            j = border[j];
        }
        ++ j;
        border[i + 1] = j;
    }
    return border;
}

/*
vector<int> kmp_build_fail(string const & pattern) { // O(m)
    int m = pattern.size();
    vector<int> fali(m+1);
    fail[0] = -1;
    int j = -1;
    repeat (i,m) {
        while (j >= 0 and pattern[i] != pattern[j]) j = fail[j];
        fail[i+1] = ++ j;
    }
    return fail;
}
int kmp_match(string const & target, string const & pattern, vector<int> const & fail) { // O(n+m)
    int n = target.length();
    int m = pattern.length();
    int result = 0;
    for (int i = 0, k = 0; i < n; ++ i) {
        while (k >= 0 and pattern[k] != target[i]) k = fail[k];
        if (++ k >= m) {
            ++ result; // match at t[i-m+1 .. i]
            k = fail[k];
        }
    }
    return result;
}
int kmp_match(string const & target, string const & pattern) {
    return kmp_match(target, pattern, kmp_build_fail(pattern));
}
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

