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


# :heavy_check_mark: graph/shortest_path_faster_algorithm.unit.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [Bellman-Ford algorithm](../../library/graph/bellman_ford.hpp.html)
* :heavy_check_mark: [Shortest Path Faster Algorithm](../../library/graph/shortest_path_faster_algorithm.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)


## Code
{% raw %}
```cpp
#include "graph/bellman_ford.hpp"
#include "graph/shortest_path_faster_algorithm.hpp"

#include <cassert>
#include <random>
#include <vector>
#include <iostream>
#include "utils/macros.hpp"
using namespace std;

int main() {
    default_random_engine gen;
    auto generate_digraph = [&](int n, int m) {
        vector<vector<pair<int, int64_t> > > g(n);
        REP (e, m) {
            int x = uniform_int_distribution<int>(0, n - 1)(gen);
            int y = uniform_int_distribution<int>(0, n - 1)(gen);
            int64_t cost = uniform_int_distribution<int64_t>(- 1000000, 10000000)(gen);
            g[x].emplace_back(y, cost);
        }
        return g;
    };

    // compare with Bellman Ford
    REP (iteration, 200) {
        int n = iteration + 1;
        int m = uniform_int_distribution<int>(0, 10 * n)(gen);
        auto g = generate_digraph(n, m);
        int root = uniform_int_distribution<int>(0, n - 1)(gen);
        assert (bellman_ford_shortest_path(root, g) == shortest_path_faster_algorithm(root, g));
    }

    // run against big graph
    int n = 10000;
    int m = 100000;
    auto g = generate_digraph(n, m);
    int root = uniform_int_distribution<int>(0, n - 1)(gen);
    volatile auto dist = shortest_path_faster_algorithm(root, g);
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

