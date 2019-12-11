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


# :heavy_check_mark: graph/subtree.hpp
<a href="../../index.html">Back to top page</a>

* category: graph
* <a href="{{ site.github.repository_url }}/blob/master/graph/subtree.hpp">View this file on GitHub</a>
    - Last commit date: 2019-11-29 09:19:37 +0900




## Required By
* :warning: <a href="../utils/dsu_on_tree.hpp.html">utils/dsu_on_tree.hpp</a>


## Verified With
* :heavy_check_mark: <a href="../../verify/graph/subtree.unit.test.cpp.html">graph/subtree.unit.test.cpp</a>


## Code
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <vector>

struct subtree_info_t {
    int parent;  // in the entire tree
    int depth;  // in the entire tree
    int size;  // of the subtree
    int height;  // of the subtree
};

/**
 * @arg g must be a tree
 * @note O(n) time
 * @note O(n) space on heap
 */
std::vector<subtree_info_t> prepare_subtree_info(std::vector<std::vector<int> > const & g, int root) {
    int n = g.size();
    std::vector<subtree_info_t> info(n, (subtree_info_t) { -1, -1, -1, -1 });
    std::vector<int> topological(n);
    topological[0] = root;
    info[root].parent = root;
    info[root].depth = 0;
    int r = 1;
    for (int l = 0; l < r; ++ l) {
        int i = topological[l];
        for (int j : g[i]) if (j != info[i].parent) {
            topological[r ++] = j;
            info[j].parent = i;
            info[j].depth = info[i].depth + 1;
        }
    }
    while ((-- r) >= 0) {
        int i = topological[r];
        info[i].size = 1;
        info[i].height = 0;
        for (int j : g[i]) if (j != info[i].parent) {
            info[i].size += info[j].size;
            info[i].height = std::max(info[i].height, info[j].height + 1);
        }
    }
    info[root].parent = -1;
    return info;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

