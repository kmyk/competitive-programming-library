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


# :warning: get centroids of a graph / 重心分解 <small>(graph/centroid-decomposition.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/centroid-decomposition.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900




## Code

{% raw %}
```cpp
/**
 * @brief get centroids of a graph / 重心分解
 * @note O(n) time
 * @note O(n) space on heap
 * @return the size is 1 or 2
 */
vector<int> get_centroids(vector<vector<int> > const & g, int root, set<int> const & forbidden) {
    map<int, int> available; {
        function<void (int, int)> go = [&](int i, int parent) {
            available.emplace(i, available.size());
            for (auto j : g[i]) if (j != parent and not forbidden.count(j)) {
                go(j, i);
            }
        };
        go(root, -1);
    }
    int n = available.size();
    vector<int> result;
    vector<int> size(n, -1);
    function<void (int, int)> go = [&](int x, int parent) {
        bool is_centroid = true;
        int i = available[x];
        size[i] = 1;
        for (auto y : g[x]) if (y != parent and available.count(y)) {
            int j = available[y];
            go(y, x);
            size[i] += size[j];
            if (size[j] > n / 2) is_centroid = false;
        }
        if (n - size[i] > n / 2) is_centroid = false;
        if (is_centroid) result.push_back(x);
    };
    go(root, -1);
    return result;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

