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


# :warning: data_structure/union_find_tree.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/union_find_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-07 22:48:24 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A</a>


## Depends On
* :warning: <a href="../../library/data_structure/union_find_tree.hpp.html">a disjoint set structure</a>


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

<a href="../../index.html">Back to top page</a>

