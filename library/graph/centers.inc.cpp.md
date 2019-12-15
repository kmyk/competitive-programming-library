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


# :warning: get centers of a tree / 木の中心 <small>(graph/centers.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/centers.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief get centers of a tree / 木の中心
 */
vector<int> get_centers(vector<vector<int> > const & tree) {
    int n = tree.size();
    vector<bool> used(n);
    vector<int> cur, prv;
    REP (i, n) {
        if (tree[i].size() <= 1) {
            cur.push_back(i);
            used[i] = true;
        }
    }
    while (not cur.empty()) {
        cur.swap(prv);
        cur.clear();
        for (int i : prv) {
            for (int j : tree[i]) if (not used[j]) {
                cur.push_back(j);
                used[j] = true;
            }
        }
    }
    return prv;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/centers.inc.cpp"
/**
 * @brief get centers of a tree / 木の中心
 */
vector<int> get_centers(vector<vector<int> > const & tree) {
    int n = tree.size();
    vector<bool> used(n);
    vector<int> cur, prv;
    REP (i, n) {
        if (tree[i].size() <= 1) {
            cur.push_back(i);
            used[i] = true;
        }
    }
    while (not cur.empty()) {
        cur.swap(prv);
        cur.clear();
        for (int i : prv) {
            for (int j : tree[i]) if (not used[j]) {
                cur.push_back(j);
                used[j] = true;
            }
        }

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

