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


# :heavy_check_mark: graph/quotient_graph.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/quotient_graph.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-30 23:14:29+09:00


* see: <a href="https://en.wikipedia.org/wiki/Quotient_graph">https://en.wikipedia.org/wiki/Quotient_graph</a>


## Depends on

* :heavy_check_mark: <a href="transpose_graph.hpp.html">graph/transpose_graph.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/graph/strongly_connected_components.yosupo.test.cpp.html">graph/strongly_connected_components.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "graph/transpose_graph.hpp"
#include "utils/macros.hpp"

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/quotient_graph.hpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

