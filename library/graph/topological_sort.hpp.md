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


# :heavy_check_mark: topological sort <small>(graph/topological_sort.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/topological_sort.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-22 23:03:03+09:00




## Depends on

* :question: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/graph/strongly_connected_components.yosupo.test.cpp.html">graph/strongly_connected_components.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <functional>
#include <vector>
#include "utils/macros.hpp"

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/topological_sort.hpp"
#include <algorithm>
#include <functional>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

