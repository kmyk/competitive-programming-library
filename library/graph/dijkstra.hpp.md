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


# :heavy_check_mark: Dijkstra ($O((E + V) \log V)$) <small>(graph/dijkstra.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 23:50:33+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/graph/dijkstra.yukicoder-1065.test.cpp.html">graph/dijkstra.yukicoder-1065.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

/**
 * @brief Dijkstra ($O((E + V) \log V)$)
 */
template <class T = int64_t>
std::vector<T> dijkstra(std::vector<std::vector<std::pair<int, T> > > const & g, int root) {
    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());
    std::priority_queue<std::pair<T, int> > que;
    dist[root] = 0;
    que.emplace(- dist[root], root);
    while (not que.empty()) {
        T dist_x; int x; std::tie(dist_x, x) = que.top(); que.pop();
        if (dist[x] < - dist_x) continue;
        for (auto it : g[x]) {
            int y; T cost; std::tie(y, cost) = it;
            if (- dist_x + cost < dist[y]) {
                dist[y] = - dist_x + cost;
                que.emplace(dist_x - cost, y);
            }
        }
    }
    return dist;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/dijkstra.hpp"
#include <cstdint>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

/**
 * @brief Dijkstra ($O((E + V) \log V)$)
 */
template <class T = int64_t>
std::vector<T> dijkstra(std::vector<std::vector<std::pair<int, T> > > const & g, int root) {
    std::vector<T> dist(g.size(), std::numeric_limits<T>::max());
    std::priority_queue<std::pair<T, int> > que;
    dist[root] = 0;
    que.emplace(- dist[root], root);
    while (not que.empty()) {
        T dist_x; int x; std::tie(dist_x, x) = que.top(); que.pop();
        if (dist[x] < - dist_x) continue;
        for (auto it : g[x]) {
            int y; T cost; std::tie(y, cost) = it;
            if (- dist_x + cost < dist[y]) {
                dist[y] = - dist_x + cost;
                que.emplace(dist_x - cost, y);
            }
        }
    }
    return dist;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

