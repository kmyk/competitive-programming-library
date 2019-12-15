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


# :warning: graph/shortest_path_faster_algorithm.unit.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/shortest_path_faster_algorithm.unit.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-13 18:43:42 +0900




## Depends on

* :heavy_check_mark: <a href="bellman_ford.hpp.html">Bellman-Ford algorithm <small>(graph/bellman_ford.hpp)</small></a>
* :warning: <a href="shortest_path_faster_algorithm.hpp.html">Shortest Path Faster Algorithm <small>(graph/shortest_path_faster_algorithm.hpp)</small></a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


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

<a href="../../index.html">Back to top page</a>

