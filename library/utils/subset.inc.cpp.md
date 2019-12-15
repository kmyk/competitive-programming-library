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


# :warning: utils/subset.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/subset.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-12-16 00:01:28 +0900


* see: <a href="https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/">https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/</a>


## Code

{% raw %}
```cpp
/**
 * @sa https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/
 */

// for a set z, list y \subseteq z, ascending order
for (int y = 0; ; y = (y - z) & z) {
    ...
    if (y == z) break;
}

// for a set z, list y \subseteq z, descending order
for (int y = z; ; y = (y - 1) & z) {
    ...
    if (y == 0) break;
}

// for a set x and an ordinal n, list y s.t. x \subseteq y \subseteq n
or (int y = x; y < (1 << n); y = (y + 1) | x) {
    ...
}

// for an ordinal n and integer k, list x \subseteq n s.t. \|x\| = k
for (int x = (1 << k) - 1; x < (1 << n); ) {
    ...
    int t = x | (x - 1);
    x = (t + 1) | (((~ t & - ~ t) - 1) >> (__builtin_ctz(x) + 1));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

