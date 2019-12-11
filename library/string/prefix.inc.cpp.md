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


# :warning: string/prefix.inc.cpp
<a href="../../index.html">Back to top page</a>

* category: string
* <a href="{{ site.github.repository_url }}/blob/master/string/prefix.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-12-07 05:27:34 +0900




## Code
{% raw %}
```cpp
bool is_suffix(string const & a, string const & b) {
    if (a.length() > b.length()) return false;
    return b.compare(b.length() - a.length(), a.length(), a) == 0;
}

unittest {
    assert (is_suffix("er", "atcoder"));
    assert (is_suffix("coder", "atcoder"));
    assert (not is_suffix("at", "atcoder"));
    assert (not is_suffix("error", "atcoder"));
    assert (not is_suffix("redoctatcoder", "atcoder"));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

