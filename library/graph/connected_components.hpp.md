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


# :warning: graph/connected_components.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/connected_components.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-05 02:57:09+09:00




## Depends on

* :question: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <stack>
#include <vector>
#include "utils/macros.hpp"

/**
 * @param g is an undirected graph
 */
int count_connected_components(const std::vector<std::vector<int> > & g) {
    int n = g.size();
    int cnt = 0;
    std::vector<bool> used(n);
    std::stack<int> stk;
    REP (z, n) if (not used[z]) {
        ++ cnt;
        used[z] = true;
        stk.push(z);
        while (not stk.empty()) {
            int x = stk.top();
            stk.pop();
            for (int y : g[x]) if (not used[y]) {
                used[y] = true;
                stk.push(y);
            }
        }
    }
    return cnt;
}

/**
 * @param g is an undirected graph
 */
bool is_connected_graph(const std::vector<std::vector<int> > & g) {
    return count_connected_components(g) == 1;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/connected_components.hpp"
#include <stack>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 5 "graph/connected_components.hpp"

/**
 * @param g is an undirected graph
 */
int count_connected_components(const std::vector<std::vector<int> > & g) {
    int n = g.size();
    int cnt = 0;
    std::vector<bool> used(n);
    std::stack<int> stk;
    REP (z, n) if (not used[z]) {
        ++ cnt;
        used[z] = true;
        stk.push(z);
        while (not stk.empty()) {
            int x = stk.top();
            stk.pop();
            for (int y : g[x]) if (not used[y]) {
                used[y] = true;
                stk.push(y);
            }
        }
    }
    return cnt;
}

/**
 * @param g is an undirected graph
 */
bool is_connected_graph(const std::vector<std::vector<int> > & g) {
    return count_connected_components(g) == 1;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

