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


# :heavy_check_mark: strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解 <small>(graph/strongly_connected_components.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/strongly_connected_components.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-30 23:14:29+09:00




## Depends on

* :heavy_check_mark: <a href="transpose_graph.hpp.html">graph/transpose_graph.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Required by

* :heavy_check_mark: <a href="../utils/two_satisfiability.hpp.html">2-SAT ($O(N)$) <small>(utils/two_satisfiability.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/graph/strongly_connected_components.yosupo.test.cpp.html">graph/strongly_connected_components.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/utils/two_satisfiability.yosupo.test.cpp.html">utils/two_satisfiability.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <functional>
#include <utility>
#include <vector>
#include "graph/transpose_graph.hpp"
#include "utils/macros.hpp"

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/strongly_connected_components.hpp"
#include <functional>
#include <utility>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

