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


# :heavy_check_mark: data_structure/union_find_tree.test.cpp


[Back to top page](../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A)


## Dependencies
* :heavy_check_mark: [a disjoint set structure](../../library/data_structure/union_find_tree.hpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include "data_structure/union_find_tree.hpp"

#include <iostream>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    union_find_tree uft(n);
    while (q --) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) {
            uft.unite_trees(x, y);
        } else if (com == 1) {
            cout << uft.is_same(x, y) << endl;
        }
    }
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

