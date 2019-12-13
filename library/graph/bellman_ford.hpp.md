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


# :warning: Bellman-Ford algorithm
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bellman_ford.hpp">View this file on GitHub</a>
    - Last commit date: 2019-08-12 19:57:24 +0900




## Depends On
* :warning: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Required By
* :warning: <a href="shortest_path_faster_algorithm.unit.random-test.cpp.html">graph/shortest_path_faster_algorithm.unit.random-test.cpp</a>


## Verified With
* :warning: <a href="../../verify/graph/bellman_ford.test.cpp.html">graph/bellman_ford.test.cpp</a>


## Code
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <climits>
#include <cstdint>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief Bellman-Ford algorithm
 * @note O(V E)
 * @arg g is a digraph with possibly negative cost edges
 * @note INT64_MIN for negative loops
 * @note INT64_MAX for unreachable nodes
 */
std::vector<int64_t> bellman_ford_shortest_path(int root, std::vector<std::vector<std::pair<int, int64_t> > > const & g) {
    assert (not g.empty());
    int n = g.size();
    std::vector<int64_t> dist(n, INT64_MAX);

    // update n - 1 times
    dist[root] = 0;
    REP (iteration, n - 1) {
        REP (i, n) if (dist[i] != INT64_MAX) {
            for (auto edge : g[i]) {
                int j; int64_t cost; std::tie(j, cost) = edge;
                dist[j] = std::min(dist[j], dist[i] + cost);
            }
        }
    }

    // propagate effects of negative cycles
    std::stack<int> stk;
    REP (i, n) if (dist[i] != INT64_MAX) {
        stk.push(i);
    }
    while (not stk.empty()) {
        int i = stk.top();
        stk.pop();
        for (auto edge : g[i]) {
            int j; int64_t cost; std::tie(j, cost) = edge;
            if (dist[j] != INT64_MIN) {
                if (dist[i] == INT64_MIN or dist[i] + cost < dist[j]) {
                    dist[j] = INT64_MIN;
                    stk.push(j);
                }
            }
        }
    }

    return dist;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

