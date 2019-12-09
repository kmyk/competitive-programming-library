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


# :heavy_check_mark: graph/bellman_ford.test.cpp


[Back to top page](../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B)


## Dependencies
* :heavy_check_mark: [Bellman-Ford algorithm](../../library/graph/bellman_ford.hpp.html)
* :heavy_check_mark: [Shortest Path Faster Algorithm](../../library/graph/shortest_path_faster_algorithm.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)


## Required
* :heavy_check_mark: [graph/shortest_path_faster_algorithm.test.cpp](shortest_path_faster_algorithm.test.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#ifdef USE_SPFA
#include "graph/shortest_path_faster_algorithm.hpp"
auto BELLMAN_FORD = shortest_path_faster_algorithm;
#else
#include "graph/bellman_ford.hpp"
auto BELLMAN_FORD = bellman_ford_shortest_path;
#endif

#include <algorithm>
#include <iostream>
#include "utils/macros.hpp"
using namespace std;

int main() {
    // input
    int v, e, root; cin >> v >> e >> root;
    vector<vector<pair<int, int64_t> > > g(v);
    REP (j, e) {
        int s, t, dist; cin >> s >> t >> dist;
        g[s].emplace_back(t, dist);
    }

    // solve
    auto dist = BELLMAN_FORD(root, g);

    // output
    if (count(ALL(dist), LLONG_MIN)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        REP (i, v) {
            if (dist[i] == LLONG_MAX) {
                cout << "INF" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

