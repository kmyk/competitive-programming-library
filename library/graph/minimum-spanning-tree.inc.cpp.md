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


# :warning: graph/minimum-spanning-tree.inc.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/minimum-spanning-tree.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-21 20:34:40 +0900




## Code
{% raw %}
```cpp
template <typename T> struct weighted_edge { int u, v; T w; };
template <typename T> bool operator < (weighted_edge<T> const & a, weighted_edge<T> const & b) { return make_tuple(a.w, a.u, a.v) < make_tuple(b.w, b.u, b.v); }
template <typename T>
vector<vector<weighted_edge<T> > > minimum_spanning_tree(int n, vector<weighted_edge<T> > edges) { // Kruskal's method, O(E \log E)
    vector<vector<weighted_edge<T> > > tree(n);
    union_find_tree uft(n);
    sort(ALL(edges));
    for (auto e : edges) {
        if (not uft.is_same(e.u, e.v)) {
            uft.unite_trees(e.u, e.v);
            tree[e.u].push_back( (weighted_edge<T>) { e.u, e.v, e.w } );
            tree[e.v].push_back( (weighted_edge<T>) { e.v, e.u, e.w } );
        }
    }
    return tree;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

