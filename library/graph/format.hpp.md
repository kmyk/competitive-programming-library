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


# :heavy_check_mark: graph/format.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/format.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-15 05:21:39+09:00




## Depends on

* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/graph/cartesian_tree.yukicoder-1031.test.cpp.html">graph/cartesian_tree.yukicoder-1031.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

std::pair<std::vector<std::vector<int> >, int> children_from_parent(const std::vector<int> & parent) {
    int n = parent.size();
    std::vector<std::vector<int> > children(n);
    int root = -1;
    REP (x, n) {
        if (parent[x] == -1) {
            assert (root == -1);
            root = x;
        } else {
            children[parent[x]].push_back(x);
        }
    }
    assert (root != -1);
    return std::make_pair(children, root);
}

std::vector<std::vector<int> > adjacent_list_from_children(const std::vector<std::vector<int> > & children) {
    int n = children.size();
    std::vector<std::vector<int> > g(n);
    REP (x, n) {
        for (int y : children[x]) {
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    return g;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/format.hpp"
#include <cassert>
#include <utility>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 6 "graph/format.hpp"

std::pair<std::vector<std::vector<int> >, int> children_from_parent(const std::vector<int> & parent) {
    int n = parent.size();
    std::vector<std::vector<int> > children(n);
    int root = -1;
    REP (x, n) {
        if (parent[x] == -1) {
            assert (root == -1);
            root = x;
        } else {
            children[parent[x]].push_back(x);
        }
    }
    assert (root != -1);
    return std::make_pair(children, root);
}

std::vector<std::vector<int> > adjacent_list_from_children(const std::vector<std::vector<int> > & children) {
    int n = children.size();
    std::vector<std::vector<int> > g(n);
    REP (x, n) {
        for (int y : children[x]) {
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    return g;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

