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


# :heavy_check_mark: graph/yen_algorithm.yukicoder-1069.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/yen_algorithm.yukicoder-1069.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-30 03:02:40+09:00


* see: <a href="https://yukicoder.me/problems/no/1069">https://yukicoder.me/problems/no/1069</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/yen_algorithm.hpp.html">K shortest simple paths (Yen's algorithm + Dijkstra, $O(K V (E + V) \log V)$) <small>(graph/yen_algorithm.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1069"
#define ERROR 1e-4
#include <bits/stdc++.h>
#include "utils/macros.hpp"
#include "graph/yen_algorithm.hpp"
using namespace std;

int main() {
    // input
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
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
    auto path = yen_algorithm_with_dijkstra(g, start, goal, k);
    vector<double> cost(k, -1);
    map<pair<int, int>, double> lookup;
    REP (i, n) {
        for (auto [j, cost] : g[i]) {
            lookup[make_pair(i, j)] = cost;
        }
    }
    REP (i, path.size()) {
        cost[i] = 0;
        REP (j, (int)path[i].size() - 1) {
            cost[i] += lookup[make_pair(path[i][j], path[i][j + 1])];
        }
    }

    // output
    REP (i, k) {
        printf("%.12lf\n", cost[i]);
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/yen_algorithm.yukicoder-1069.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1069"
#define ERROR 1e-4
#include <bits/stdc++.h>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 9 "graph/yen_algorithm.hpp"

/**
 * @brief K shortest simple paths (Yen's algorithm + Dijkstra, $O(K V (E + V) \log V)$)
 * @param g is an adjacent list of a simple undirected graph
 * @return simple paths. If there are only less than K paths, return all paths in sorted order.
 */
template <class T>
std::vector<std::vector<int> > yen_algorithm_with_dijkstra(const std::vector<std::vector<std::pair<int, T> > > & g, int start, int goal, int k) {
    using namespace std;
    using reversed_priority_queue = priority_queue<pair<T, int> , vector<pair<T, int> >, greater<pair<T, int> > >;

    // trivial cases
    if (k == 0) return vector<vector<int> >();
    if (start == goal) {
        return vector<vector<int> >(1, vector<int>(1, start));
    }
    assert (k >= 1);

    // prepare
    int n = g.size();
    auto dijkstra = [&](int start, const set<int> & removed_vertices, const set<pair<int, int> > & removed_edges) -> pair<T, vector<int> > {
        // dijkstra
        vector<pair<T, int> > dist(n, make_pair(numeric_limits<T>::max(), -1));
        reversed_priority_queue que;
        dist[start] = make_pair(0, -1);
        que.emplace(0, start);
        while (not que.empty()) {
            auto [dist_x, x] = que.top();
            que.pop();
            if (dist[x].first < dist_x) continue;
            for (auto [y, cost] : g[x]) if (not removed_vertices.count(y) and not removed_edges.count(make_pair(x, y))) {
                if (dist_x + cost < dist[y].first) {
                    dist[y] = make_pair(dist_x + cost, x);
                    que.emplace(dist_x + cost, y);
                }
            }
        }

        // reconstruct the path
        if (start != goal and dist[goal].second == -1) {
            // failure
            return make_pair(dist[goal].first, vector<int>());
        }
        vector<int> path;
        for (int x = goal; x != -1; x = dist[x].second) {
            path.push_back(x);
        }
        reverse(ALL(path));
        return make_pair(dist[goal].first, path);
    };
    map<pair<int, int>, double> lookup;
    REP (i, n) {
        for (auto [j, cost] : g[i]) {
            lookup[make_pair(i, j)] = cost;
        }
    }

    // run Yen's algorithm
    vector<vector<int> > result;
    set<pair<T, vector<int> > > que;
    result.push_back(dijkstra(start, set<int>(), set<pair<int, int> >()).second);
    while ((int)result.size() < k) {
        auto & root = result.back();

        T root_cost = 0;
        set<int> removed_vertices;
        vector<int> prefix(result.size());
        iota(ALL(prefix), 0);
        REP (i, (int)root.size() - 1) {
            // remove edges used in other shortest paths from the graph
            set<pair<int, int> > removed_edges;
            vector<int> next_prefix;
            for (int j : prefix) {
                if (i + 1 < result[j].size() and result[j][i] == root[i]) {
                    int x = result[j][i];
                    int y = result[j][i + 1];
                    removed_edges.emplace(x, y);
                    removed_edges.emplace(y, x);
                    next_prefix.push_back(j);
                }
            }
            prefix.swap(next_prefix);

            // make the new path
            auto [spur_cost, spur] = dijkstra(root[i], removed_vertices, removed_edges);
            if (not spur.empty()) {
                vector<int> path(i + spur.size());
                copy(root.begin(), root.begin() + i, path.begin());
                copy(ALL(spur), path.begin() + i);
                que.emplace(root_cost + spur_cost, path);
                if (que.size() > k - (int)result.size()) {
                    que.erase(prev(que.end()));
                }
            }

            // remove vertices in root from the graph
            removed_vertices.insert(root[i]);
            root_cost += lookup[make_pair(root[i], root[i + 1])];
        }

        // found i-th smallest path
        if (que.empty()) {
            return result;
        }
        result.push_back(que.begin()->second);
        que.erase(que.begin());
    }
    return result;
}
#line 6 "graph/yen_algorithm.yukicoder-1069.test.cpp"
using namespace std;

int main() {
    // input
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
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
    auto path = yen_algorithm_with_dijkstra(g, start, goal, k);
    vector<double> cost(k, -1);
    map<pair<int, int>, double> lookup;
    REP (i, n) {
        for (auto [j, cost] : g[i]) {
            lookup[make_pair(i, j)] = cost;
        }
    }
    REP (i, path.size()) {
        cost[i] = 0;
        REP (j, (int)path[i].size() - 1) {
            cost[i] += lookup[make_pair(path[i][j], path[i][j + 1])];
        }
    }

    // output
    REP (i, k) {
        printf("%.12lf\n", cost[i]);
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

