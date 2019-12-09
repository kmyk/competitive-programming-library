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


# :heavy_check_mark: graph/subtree.unit.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [graph/subtree.hpp](../../library/graph/subtree.hpp.html)


## Code
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

[Back to top page](../../index.html)

