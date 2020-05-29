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


# :heavy_check_mark: graph/dijkstra.yukicoder-1065.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.yukicoder-1065.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 23:50:33+09:00


* see: <a href="https://yukicoder.me/problems/no/1065">https://yukicoder.me/problems/no/1065</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/dijkstra.hpp.html">Dijkstra ($O((E + V) \log V)$) <small>(graph/dijkstra.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1065"
#define ERROR 1e-4
#include <bits/stdc++.h>
#include "utils/macros.hpp"
#include "graph/dijkstra.hpp"
using namespace std;


int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    int start, goal; scanf("%d%d", &start, &goal);
    -- start;
    -- goal;
    vector<long long> x(n), y(n);
    REP (i, n) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    vector<vector<pair<int, double> > > g(n);
    REP (i, m) {
        int p, q; cin >> p >> q;
        -- p;
        -- q;
        double cost = sqrt(pow(x[p] - x[q], 2) + pow(y[p] - y[q], 2));
        g[p].emplace_back(q, cost);
        g[q].emplace_back(p, cost);
    }

    // solve
    auto dist = dijkstra(g, start);

    // output
    printf("%.12lf\n", dist[goal]);
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dijkstra.yukicoder-1065.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1065"
#define ERROR 1e-4
#include <bits/stdc++.h>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 7 "graph/dijkstra.hpp"

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
#line 6 "graph/dijkstra.yukicoder-1065.test.cpp"
using namespace std;


int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    int start, goal; scanf("%d%d", &start, &goal);
    -- start;
    -- goal;
    vector<long long> x(n), y(n);
    REP (i, n) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    vector<vector<pair<int, double> > > g(n);
    REP (i, m) {
        int p, q; cin >> p >> q;
        -- p;
        -- q;
        double cost = sqrt(pow(x[p] - x[q], 2) + pow(y[p] - y[q], 2));
        g[p].emplace_back(q, cost);
        g[q].emplace_back(p, cost);
    }

    // solve
    auto dist = dijkstra(g, start);

    // output
    printf("%.12lf\n", dist[goal]);
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

