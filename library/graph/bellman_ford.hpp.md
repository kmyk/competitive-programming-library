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


# :heavy_check_mark: Bellman-Ford algorithm
* category: graph


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [utils/macros.hpp](../utils/macros.hpp.html)


## Verified
* :heavy_check_mark: [graph/bellman_ford.test.cpp](../../verify/graph/bellman_ford.test.cpp.html)
* :heavy_check_mark: [graph/shortest_path_faster_algorithm.unit.test.cpp](../../verify/graph/shortest_path_faster_algorithm.unit.test.cpp.html)


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

[Back to top page](../../index.html)

