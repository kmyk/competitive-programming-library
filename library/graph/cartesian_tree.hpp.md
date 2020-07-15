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


# :heavy_check_mark: Cartesian tree ($O(n)$) <small>(graph/cartesian_tree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/cartesian_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-16 00:31:29+09:00




## Depends on

* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/graph/cartesian_tree.yukicoder-1031.test.cpp.html">graph/cartesian_tree.yukicoder-1031.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <functional>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief Cartesian tree ($O(n)$)
 * @note the smallest value is the root
 * @note if a is not distinct, the way for tie-break is undefined
 * @return the binary tree as the list of parents
 */
template <class T, class Comparator = std::less<int> >
std::vector<int> construct_cartesian_tree(const std::vector<T> & a, const Comparator & cmp = Comparator()) {
    int n = a.size();
    std::vector<int> parent(n, -1);
    REP3 (i, 1, n) {
        int p = i - 1;  // parent of i
        int l = -1;  // left child of i
        while (p != -1 and cmp(a[i], a[p])) {
            int pp = parent[p];  // parent of parent of i
            if (l != -1) {
                parent[l] = p;
            }
            parent[p] = i;
            l = p;
            p = pp;
        }
        parent[i] = p;
    }
    return parent;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/cartesian_tree.hpp"
#include <functional>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 5 "graph/cartesian_tree.hpp"

/**
 * @brief Cartesian tree ($O(n)$)
 * @note the smallest value is the root
 * @note if a is not distinct, the way for tie-break is undefined
 * @return the binary tree as the list of parents
 */
template <class T, class Comparator = std::less<int> >
std::vector<int> construct_cartesian_tree(const std::vector<T> & a, const Comparator & cmp = Comparator()) {
    int n = a.size();
    std::vector<int> parent(n, -1);
    REP3 (i, 1, n) {
        int p = i - 1;  // parent of i
        int l = -1;  // left child of i
        while (p != -1 and cmp(a[i], a[p])) {
            int pp = parent[p];  // parent of parent of i
            if (l != -1) {
                parent[l] = p;
            }
            parent[p] = i;
            l = p;
            p = pp;
        }
        parent[i] = p;
    }
    return parent;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

