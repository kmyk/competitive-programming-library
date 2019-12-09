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


# :heavy_check_mark: lowest common ancestor with \pm 1 RMQ and sparse table
* category: graph


[Back to top page](../../index.html)

* see: [https://www.slideshare.net/yumainoue965/lca-and-rmq](https://www.slideshare.net/yumainoue965/lca-and-rmq)


## Dependencies
* :heavy_check_mark: [sparse table on a semilattice](../data_structure/sparse_table.hpp.html)


## Verified
* :heavy_check_mark: [graph/lowest_common_ancestor.aoj.test.cpp](../../verify/graph/lowest_common_ancestor.aoj.test.cpp.html)


## Code
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>
#include "data_structure/sparse_table.hpp"

/**
 * @brief lowest common ancestor with \pm 1 RMQ and sparse table
 * @see https://www.slideshare.net/yumainoue965/lca-and-rmq
 * @note verified http://www.utpc.jp/2011/problems/travel.html
 */
struct lowest_common_ancestor {
    sparse_table<indexed_min_semilattice> table;
    std::vector<int> index;
    lowest_common_ancestor() = default;
    /**
     * @note O(N)
     * @param g is an adjacent list of a tree
     * @note you can easily modify this to accept forests
     */
    lowest_common_ancestor(int root, std::vector<std::vector<int> > const & g) {
        std::vector<std::pair<int, int> > tour;
        index.assign(g.size(), -1);
        dfs(root, -1, 0, g, tour);
        table = sparse_table<indexed_min_semilattice>(tour);
    }
private:
    /**
     * @note to avoid stack overflow
     */
    void dfs(int x, int parent, int depth, std::vector<std::vector<int> > const & g, std::vector<std::pair<int, int> > & tour) {
        index[x] = tour.size();
        tour.emplace_back(depth, x);
        for (int y : g[x]) if (y != parent) {
            dfs(y, x, depth + 1, g, tour);
            tour.emplace_back(depth, x);
        }
    }
public:
    /**
     * @note O(1)
     */
    int operator () (int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        x = index[x];
        y = index[y];
        if (x > y) std::swap(x, y);
        return table.range_concat(x, y + 1).second;
    }
    int get_depth(int x) const {
        assert (0 <= x and x < index.size());
        return table.range_concat(index[x], index[x] + 1).first;
    }
    int get_dist(int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        int z = (*this)(x, y);
        return get_depth(x) + get_depth(y) - 2 * get_depth(z);
    }
};

```
{% endraw %}

[Back to top page](../../index.html)

