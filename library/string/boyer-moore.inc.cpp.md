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


# :warning: string/boyer-moore.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/boyer-moore.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-06-02 16:57:27 +0900




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
array<int,26> bm_build_skip(string const & pattern) { // O(m)
    int m = pattern.length();
    array<int,26> skip = {};
    repeat (i,m) skip[pattern[i]-'a'] = m-i-1;
    return skip;
}
vector<int> bm_build_next(string const & pattern) { // O(m)
    int m = pattern.length();
    int g[m]; fill(g, g+m, m);
    vector<int> next(m);
    repeat (i,m) next[i] = 2*m-i-1;
    int j = m;
    for (int i = m-1; i >= 0; --i, --j) {
        g[i] = j;
        while (j < m and pattern[j] != pattern[i]) {
            next[j] = min(next[j], m-i-1);
            j = g[j];
        }
    }
    repeat (i,m) {
        next[i] = min(next[i], j+m-i);
        if (i >= j) j = g[j];
    }
    return next;
}
int bm_match(string const & target, string const & pattern, array<int,26> const & skip, vector<int> const & next) { // O(nm)
    int n = target.length();
    int m = pattern.length();
    int result = 0;
    for (int i = m-1; i < n; ) {
        int j = m-1;
        while (j >= 0 and target[i] == pattern[j]) { --i; --j; }
        if (j < 0) {
            ++ result; // match at text[i+1, ..., i+m]
            i += m + 1;
        } else {
            i += max(skip[target[i]-'a'], next[j]);
        }
    }
    return result;
}
int bm_match(string const & target, string const & pattern) { // Boyer-Moore
    return bm_match(target, pattern, bm_build_skip(pattern), bm_build_next(pattern));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/boyer-moore.inc.cpp"
array<int,26> bm_build_skip(string const & pattern) { // O(m)
    int m = pattern.length();
    array<int,26> skip = {};
    repeat (i,m) skip[pattern[i]-'a'] = m-i-1;
    return skip;
}
vector<int> bm_build_next(string const & pattern) { // O(m)
    int m = pattern.length();
    int g[m]; fill(g, g+m, m);
    vector<int> next(m);
    repeat (i,m) next[i] = 2*m-i-1;
    int j = m;
    for (int i = m-1; i >= 0; --i, --j) {
        g[i] = j;
        while (j < m and pattern[j] != pattern[i]) {
            next[j] = min(next[j], m-i-1);
            j = g[j];
        }
    }
    repeat (i,m) {
        next[i] = min(next[i], j+m-i);
        if (i >= j) j = g[j];
    }
    return next;
}
int bm_match(string const & target, string const & pattern, array<int,26> const & skip, vector<int> const & next) { // O(nm)
    int n = target.length();
    int m = pattern.length();
    int result = 0;
    for (int i = m-1; i < n; ) {
        int j = m-1;
        while (j >= 0 and target[i] == pattern[j]) { --i; --j; }
        if (j < 0) {
            ++ result; // match at text[i+1, ..., i+m]
            i += m + 1;
        } else {
            i += max(skip[target[i]-'a'], next[j]);
        }
    }
    return result;
}
int bm_match(string const & target, string const & pattern) { // Boyer-Moore
    return bm_match(target, pattern, bm_build_skip(pattern), bm_build_next(pattern));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

