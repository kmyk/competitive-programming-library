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


# :warning: Eulerian cycle (無向, 復元) <small>(graph/euler_graph.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/euler_graph.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-06 18:18:58+09:00




## Depends on

* :question: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <tuple>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

/**
 * @param g must be an undirected graph. Loops and multiple edges are acceptable.
 * @param root specifies the component to find an Eulerian cycle
 * @return indices of edges. It's empty if g is not a Eulerian graph.
 */
std::vector<int> find_eulerian_cycle_with_root(int n, const std::vector<std::pair<int, int> > & edges, int root) {
    int m = edges.size();
    std::vector<std::vector<int> > g(n);
    std::vector<int> degree(n);
    REP (i, m) {
        int x, y; std::tie(x, y) = edges[i];
        g[x].push_back(i);
        g[y].push_back(i);
        ++ degree[x];
        ++ degree[y];  // This is required even if x == y
    }

    std::vector<int> order;
    std::vector<bool> used(m);
    auto go = [&](auto && go, int x) -> bool {
        if (degree[x] % 2 != 0) {
            return false;
        }
        while (not g[x].empty()) {
            int i = g[x].back();
            g[x].pop_back();
            if (not used[i]) {
                used[i] = true;
                int y = x ^ edges[i].first ^ edges[i].second;
                if (not go(go, y)) {
                    return false;
                }
                order.push_back(i);
            }
        }
        return true;
    };
    if (not go(go, root)) {
        return std::vector<int>();  // not a Eulerian graph
    }
    return order;
}

/**
 * @brief Eulerian cycle (無向, 復元)
 * @param g must be an undirected and connected graph.
 * @return indices of edges. It's empty if g is not a Eulerian graph.
 */
std::vector<int> find_eulerian_cycle(int n, const std::vector<std::pair<int, int> > & edges) {
    auto order = find_eulerian_cycle_with_root(n, edges, 0);
    if (order.size() != edges.size()) {
        return std::vector<int>();
    }
    return order;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/euler_graph.hpp"
#include <algorithm>
#include <tuple>
#include <utility>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 7 "graph/euler_graph.hpp"

/**
 * @param g must be an undirected graph. Loops and multiple edges are acceptable.
 * @param root specifies the component to find an Eulerian cycle
 * @return indices of edges. It's empty if g is not a Eulerian graph.
 */
std::vector<int> find_eulerian_cycle_with_root(int n, const std::vector<std::pair<int, int> > & edges, int root) {
    int m = edges.size();
    std::vector<std::vector<int> > g(n);
    std::vector<int> degree(n);
    REP (i, m) {
        int x, y; std::tie(x, y) = edges[i];
        g[x].push_back(i);
        g[y].push_back(i);
        ++ degree[x];
        ++ degree[y];  // This is required even if x == y
    }

    std::vector<int> order;
    std::vector<bool> used(m);
    auto go = [&](auto && go, int x) -> bool {
        if (degree[x] % 2 != 0) {
            return false;
        }
        while (not g[x].empty()) {
            int i = g[x].back();
            g[x].pop_back();
            if (not used[i]) {
                used[i] = true;
                int y = x ^ edges[i].first ^ edges[i].second;
                if (not go(go, y)) {
                    return false;
                }
                order.push_back(i);
            }
        }
        return true;
    };
    if (not go(go, root)) {
        return std::vector<int>();  // not a Eulerian graph
    }
    return order;
}

/**
 * @brief Eulerian cycle (無向, 復元)
 * @param g must be an undirected and connected graph.
 * @return indices of edges. It's empty if g is not a Eulerian graph.
 */
std::vector<int> find_eulerian_cycle(int n, const std::vector<std::pair<int, int> > & edges) {
    auto order = find_eulerian_cycle_with_root(n, edges, 0);
    if (order.size() != edges.size()) {
        return std::vector<int>();
    }
    return order;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

