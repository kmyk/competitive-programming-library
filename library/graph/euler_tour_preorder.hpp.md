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


# :heavy_check_mark: Euler Tour (preorder) <small>(graph/euler_tour_preorder.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/euler_tour_preorder.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-26 19:51:56+09:00




## Required by

* :heavy_check_mark: <a href="../data_structure/euler_tour_subtree_query.hpp.html">Euler Tour (subtree queries, with commutative monoids) <small>(data_structure/euler_tour_subtree_query.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp.html">data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <functional>
#include <vector>

/**
 * @brief Euler Tour (preorder)
 * @arg g must be a rooted tree, directed or undirected
 */
void do_euler_tour_preorder(std::vector<std::vector<int> > const & g, int root, std::vector<int> & tour, std::vector<int> & left, std::vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.assign(n, -1);
    right.assign(n, -1);
    std::function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
    };
    go(root, -1);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/euler_tour_preorder.hpp"
#include <functional>
#include <vector>

/**
 * @brief Euler Tour (preorder)
 * @arg g must be a rooted tree, directed or undirected
 */
void do_euler_tour_preorder(std::vector<std::vector<int> > const & g, int root, std::vector<int> & tour, std::vector<int> & left, std::vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.assign(n, -1);
    right.assign(n, -1);
    std::function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
    };
    go(root, -1);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

