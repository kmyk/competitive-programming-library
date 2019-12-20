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


# :warning: get the diameter of a tree / 木の直径 <small>(graph/diameter.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/diameter.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59+09:00


* see: <a href="http://techtipshoge.blogspot.jp/2016/09/blog-post.html">http://techtipshoge.blogspot.jp/2016/09/blog-post.html</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief get the diameter of a tree / 木の直径
 */

/**
 * @sa http://techtipshoge.blogspot.jp/2016/09/blog-post.html
 */
pair<int, int> get_eccentricity(int k, vector<vector<int> > const & tree) {
    pair<int, int> result = { -1, -1 };  // (depth, vertex)
    function<void (int, int, int)> dfs = [&](int i, int parent, int depth) {
        chmax(result, make_pair(depth, i));
        for (int j : tree[i]) if (j != parent) {
            dfs(j, i, depth + 1);
        }
    };
    dfs(k, -1, 0);
    return result;
}
int get_diameter(vector<vector<int> > const & tree) {
    return get_eccentricity(get_eccentricity(0, tree).second, tree).first;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/diameter.inc.cpp"
/**
 * @brief get the diameter of a tree / 木の直径
 */

/**
 * @sa http://techtipshoge.blogspot.jp/2016/09/blog-post.html
 */
pair<int, int> get_eccentricity(int k, vector<vector<int> > const & tree) {
    pair<int, int> result = { -1, -1 };  // (depth, vertex)
    function<void (int, int, int)> dfs = [&](int i, int parent, int depth) {
        chmax(result, make_pair(depth, i));
        for (int j : tree[i]) if (j != parent) {
            dfs(j, i, depth + 1);
        }
    };
    dfs(k, -1, 0);
    return result;
}
int get_diameter(vector<vector<int> > const & tree) {
    return get_eccentricity(get_eccentricity(0, tree).second, tree).first;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

