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


# :warning: utils/dsu_on_tree.hpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/dsu_on_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-13 04:55:53 +0900


* see: <a href="https://codeforces.com/blog/entry/44351">https://codeforces.com/blog/entry/44351</a>


## Depends On
* :heavy_check_mark: <a href="../graph/subtree.hpp.html">graph/subtree.hpp</a>
* :heavy_check_mark: <a href="macros.hpp.html">utils/macros.hpp</a>


## Code
{% raw %}
```cpp
#pragma once
#include <functional>
#include <stack>
#include <vector>
#include "graph/subtree.hpp"
#include "utils/macros.hpp"

/**
 * @arg g is a tree
 * @arg root
 * @arg add is a function object which takes a index of a vertex
 * @arg sub is a function object which takes a index of a vertex
 * @arg callback is a function object which takes a index of a vertex
 * @note for each x, add(x) and sub(x) are called O(log n) times
 * @note O(n log n) if add, sub, and callback are O(1)
 * @see https://codeforces.com/blog/entry/44351
 */
template <class Add, class Sub, class Callback>
void dsu_on_tree(const std::vector<std::vector<int> > & g, int root, Add & add, Sub & sub, Callback & callback) {
    auto info = prepare_subtree_info(g, root);
    auto subtree_apply = [&](int x, auto & f) {
        std::stack<int> stk;
        stk.push(x);
        while (not stk.empty()) {
            int y = stk.top();
            stk.pop();
            f(y);
            for (int z : g[y]) if (z != info[y].parent) {
                stk.push(z);
            }
        }
    };
    std::function<void (int, bool)> go = [&](int x, bool keep) {
        // leaf
        if (info[x].size == 1) {
            add(x);
            callback(x);
            if (not keep) {
                sub(x);
            }
            return;
        }
        // choose the heavy child
        int z = *max_element(ALL(g[x]), [&](int y1, int y2) {
            int size1 = (y1 == info[x].parent ? -1 : info[y1].size);
            int size2 = (y2 == info[x].parent ? -1 : info[y2].size);
            return size1 < size2;
        });
        // go light
        for (int y : g[x]) if (y != info[x].parent) {
            if (y != z) {
                go(y, false);
            }
        }
        // go heavy
        go(z, true);
        for (int y : g[x]) if (y != info[x].parent) {
            if (y != z) {
                subtree_apply(y, add);
            }
        }
        add(x);
        callback(x);
        if (not keep) {
            subtree_apply(x, sub);
        }
    };
    go(root, false);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

