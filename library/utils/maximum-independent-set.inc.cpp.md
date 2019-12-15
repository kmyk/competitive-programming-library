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


# :warning: utils/maximum-independent-set.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/maximum-independent-set.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-12-15 22:37:03 +0900


* see: <a href="https://www.slideshare.net/wata_orz/ss-12131479">https://www.slideshare.net/wata_orz/ss-12131479</a>


## Code

{% raw %}
```cpp
/**
 * @see https://www.slideshare.net/wata_orz/ss-12131479
 * @note O(1.466^n n)
 * @param g is an adjacency matrix
 */
int maximum_independent_set(vector<vector<bool> > const & g) {
    int n = g.size();
    function<int (int, vector<bool> const &)> go = [&](int i, vector<bool> used) {
        while (i < n and used[i]) ++ i;
        if (i == n) return 0;
        int degree = 0;
        repeat_from (j, i + 1, n) {
            degree += (not used[j] and g[i][j]);
        }
        int result = 0;
        used[i] = true;
        if (degree >= 2) {
            setmax(result, go(i + 1, used));  // don't use i
        }
        repeat_from (j, i + 1, n) {
            used[j] = (used[j] or g[i][j]);
        }
        setmax(result, 1 + go(i + 1, used));  // use i
        return result;
    };
    return go(0, vector<bool>(n));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

