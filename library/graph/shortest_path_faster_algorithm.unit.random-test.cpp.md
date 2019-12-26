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
    - Last commit date: 2019-12-20 06:12:24+09:00




## Depends on

* :heavy_check_mark: <a href="bellman_ford.hpp.html">Bellman-Ford algorithm <small>(graph/bellman_ford.hpp)</small></a>
* :warning: <a href="shortest_path_faster_algorithm.hpp.html">Shortest Path Faster Algorithm <small>(graph/shortest_path_faster_algorithm.hpp)</small></a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
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

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/bellman_ford.hpp"
#include <cassert>
#include <climits>
#include <cstdint>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 10 "graph/bellman_ford.hpp"

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
#line 2 "graph/shortest_path_faster_algorithm.hpp"
#include <cassert>
#include <climits>
#include <cstdint>
#include <deque>
#include <tuple>
#include <utility>
#include <vector>
#line 10 "graph/shortest_path_faster_algorithm.hpp"

/**
 * @brief Shortest Path Faster Algorithm
 * @note the interface is same to one of Bellman Ford
 */
std::vector<int64_t> shortest_path_faster_algorithm(int root, std::vector<std::vector<std::pair<int, int64_t> > > const & g) {
    assert (not g.empty());
    int n = g.size();
    std::vector<int64_t> dist(n, INT64_MAX);
    std::deque<int> cur, nxt;
    std::vector<bool> pushed(n);
    dist[root] = 0;
    nxt.push_back(root);
    pushed[root] = true;

    REP (iteration, 2 * n - 2) {
        cur.swap(nxt);
        while (not cur.empty()) {
            int x = cur.front();
            cur.pop_front();
            pushed[x] = false;
            for (const auto & edge : g[x]) {
                int y; int64_t cost; std::tie(y, cost) = edge;
                if ((dist[x] == INT64_MIN ? INT64_MIN : dist[x] + cost) < dist[y]) {
                    dist[y] = (iteration >= n - 1 ? INT64_MIN : dist[x] + cost);
                    if (not pushed[y]) {
                        if (not nxt.empty() and dist[y] < dist[nxt.front()]) {
                            // Small Label First
                            nxt.push_front(y);
                        } else {
                            nxt.push_back(y);
                        }
                        pushed[y] = true;
                    }
                }
            }
        }
        if (nxt.empty()) break;
    }

    return dist;
}
#line 3 "graph/shortest_path_faster_algorithm.unit.random-test.cpp"

#include <cassert>
#include <random>
#include <vector>
#include <iostream>
#line 9 "graph/shortest_path_faster_algorithm.unit.random-test.cpp"
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

