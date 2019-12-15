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


# :warning: graph/subtree.unit.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/subtree.unit.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900




## Depends on

* :heavy_check_mark: <a href="subtree.hpp.html">subtree info / それぞれの部分木の size とか height とかをまとめて求めておいてくれるやつ <small>(graph/subtree.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "graph/subtree.hpp"
#include <cassert>
using namespace std;

int main() {
    vector<vector<int> > g(9);
    const int root = 0;
    g[0].push_back(1);
    g[0].push_back(2);
    ;   g[2].push_back(4);
    ;   g[2].push_back(5);
    ;   g[2].push_back(6);
    ;   ;   g[6].push_back(8);
    g[0].push_back(3);
    ;   g[3].push_back(7);
    auto info = prepare_subtree_info(g, root);
    assert (info[root].parent == -1);
    assert (info[root].depth == 0);
    assert (info[root].size == g.size());
    assert (info[root].height == 3);
    assert (info[1].parent == 0);
    assert (info[1].depth == 1);
    assert (info[1].size == 1);
    assert (info[1].height == 0);
    assert (info[6].parent == 2);
    assert (info[6].depth == 2);
    assert (info[6].size == 2);
    assert (info[6].height == 1);
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/subtree.hpp"
#include <algorithm>
#include <vector>

struct subtree_info_t {
    int parent;  // in the entire tree
    int depth;  // in the entire tree
    int size;  // of the subtree
    int height;  // of the subtree
};

/**
 * @brief subtree info / それぞれの部分木の size とか height とかをまとめて求めておいてくれるやつ
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
#line 2 "graph/subtree.unit.random-test.cpp"
#include <cassert>
using namespace std;

int main() {
    vector<vector<int> > g(9);
    const int root = 0;
    g[0].push_back(1);
    g[0].push_back(2);
    ;   g[2].push_back(4);
    ;   g[2].push_back(5);
    ;   g[2].push_back(6);
    ;   ;   g[6].push_back(8);
    g[0].push_back(3);
    ;   g[3].push_back(7);
    auto info = prepare_subtree_info(g, root);
    assert (info[root].parent == -1);
    assert (info[root].depth == 0);
    assert (info[root].size == g.size());
    assert (info[root].height == 3);
    assert (info[1].parent == 0);
    assert (info[1].depth == 1);
    assert (info[1].size == 1);
    assert (info[1].height == 0);
    assert (info[6].parent == 2);
    assert (info[6].depth == 2);
    assert (info[6].size == 2);
    assert (info[6].height == 1);
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

