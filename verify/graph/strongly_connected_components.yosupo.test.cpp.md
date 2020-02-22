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


# :heavy_check_mark: graph/strongly_connected_components.yosupo.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/graph/strongly_connected_components.yosupo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-22 23:03:03+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/quotient_graph.hpp.html">graph/quotient_graph.hpp</a>
* :heavy_check_mark: <a href="../../library/graph/strongly_connected_components.hpp.html">strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解 <small>(graph/strongly_connected_components.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/graph/topological_sort.hpp.html">topological sort <small>(graph/topological_sort.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/graph/transpose_graph.hpp.html">graph/transpose_graph.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "graph/strongly_connected_components.hpp"
#include "graph/quotient_graph.hpp"
#include "graph/topological_sort.hpp"
#include "utils/macros.hpp"
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int> > g(n);
    REP (i, m) {
        int a, b; scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }

    // solve
    int size; vector<int> component_of; tie(size, component_of) = decompose_to_strongly_connected_components(g);
    vector<vector<int> > component(size);
    REP (i, n) {
        component[component_of[i]].push_back(i);
    }
    vector<vector<int> > h = make_quotient_graph(g, size, component_of);
    vector<int> order = topological_sort(h);
    assert (order.size() == size);

    // output
    printf("%d\n", size);
    for (int a : order) {
        printf("%d", (int)component[a].size());
        for (int i : component[a]) {
            printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/strongly_connected_components.yosupo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#line 2 "graph/strongly_connected_components.hpp"
#include <functional>
#include <utility>
#include <vector>
#line 2 "graph/transpose_graph.hpp"
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 4 "graph/transpose_graph.hpp"

/**
 * @param g is an adjacent list of a digraph
 * @note $O(V + E)$
 * @see https://en.wikipedia.org/wiki/Transpose_graph
 */
std::vector<std::vector<int> > make_transpose_graph(std::vector<std::vector<int> > const & g) {
    int n = g.size();
    std::vector<std::vector<int> > h(n);
    REP (i, n) {
        for (int j : g[i]) {
            h[j].push_back(i);
        }
    }
    return h;
}
#line 7 "graph/strongly_connected_components.hpp"

/**
 * @brief strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解
 * @return the pair (the number k of components, the function from vertices of g to components)
 * @param g is an adjacent list of a digraph
 * @param g_rev is the transpose graph of g
 * @note $O(V + E)$
 */
std::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const std::vector<std::vector<int> > & g, const std::vector<std::vector<int> > & g_rev) {
    int n = g.size();
    std::vector<int> acc(n); {
        std::vector<bool> used(n);
        std::function<void (int)> dfs = [&](int i) {
            used[i] = true;
            for (int j : g[i]) if (not used[j]) dfs(j);
            acc.push_back(i);
        };
        REP (i,n) if (not used[i]) dfs(i);
        reverse(ALL(acc));
    }
    int size = 0;
    std::vector<int> component_of(n); {
        std::vector<bool> used(n);
        std::function<void (int)> rdfs = [&](int i) {
            used[i] = true;
            component_of[i] = size;
            for (int j : g_rev[i]) if (not used[j]) rdfs(j);
        };
        for (int i : acc) if (not used[i]) {
            rdfs(i);
            ++ size;
        }
    }
    return { size, move(component_of) };
}

std::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const std::vector<std::vector<int> > & g) {
    return decompose_to_strongly_connected_components(g, make_transpose_graph(g));
}
#line 2 "graph/quotient_graph.hpp"
#include <vector>
#line 5 "graph/quotient_graph.hpp"

/**
 * @param g is an adjacent list of a digraph
 * @param size is the size of equivalence classes
 * @param component_of is the map from original vertices to equivalence classes
 * @note $O(V + E)$
 * @see https://en.wikipedia.org/wiki/Quotient_graph
 */
std::vector<std::vector<int> > make_quotient_graph(const std::vector<std::vector<int> > & g, int size, const std::vector<int> & component_of) {
    int n = g.size();
    std::vector<std::vector<int> > h(size);
    REP (i, n) for (int j : g[i]) {
        if (component_of[i] != component_of[j]) {
            h[component_of[i]].push_back(component_of[j]);
        }
    }
    REP (k, size) {
        std::sort(ALL(h[k]));
        h[k].erase(std::unique(ALL(h[k])), h[k].end());
    }
    return h;
}
#line 2 "graph/topological_sort.hpp"
#include <algorithm>
#include <functional>
#include <vector>
#line 6 "graph/topological_sort.hpp"

/**
 * @brief topological sort
 * @return a list of vertices which sorted topologically
 * @note the empty list is returned if cycles exist
 * @note $O(V + E)$
 */
std::vector<int> topological_sort(const std::vector<std::vector<int> > & g) {
    int n = g.size();
    std::vector<int> order;
    std::vector<char> used(n);
    std::function<bool (int)> go = [&](int i) {
        used[i] = 1;  // in stack
        for (int j : g[i]) {
            if (used[j] == 1) return true;
            if (not used[j]) {
                if (go(j)) return true;
            }
        }
        used[i] = 2;  // completely used
        order.push_back(i);
        return false;
    };
    REP (i, n) if (not used[i]) {
        if (go(i)) return std::vector<int>();
    }
    std::reverse(ALL(order));
    return order;
}
#line 6 "graph/strongly_connected_components.yosupo.test.cpp"
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int> > g(n);
    REP (i, m) {
        int a, b; scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }

    // solve
    int size; vector<int> component_of; tie(size, component_of) = decompose_to_strongly_connected_components(g);
    vector<vector<int> > component(size);
    REP (i, n) {
        component[component_of[i]].push_back(i);
    }
    vector<vector<int> > h = make_quotient_graph(g, size, component_of);
    vector<int> order = topological_sort(h);
    assert (order.size() == size);

    // output
    printf("%d\n", size);
    for (int a : order) {
        printf("%d", (int)component[a].size());
        for (int i : component[a]) {
            printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

