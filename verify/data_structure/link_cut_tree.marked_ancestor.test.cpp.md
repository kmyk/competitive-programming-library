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


# :warning: data_structure/link_cut_tree.marked_ancestor.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/link_cut_tree.marked_ancestor.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-07 22:48:24 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2170&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2170&lang=jp</a>


## Depends On
* :warning: <a href="../../library/data_structure/link_cut_tree.hpp.html">an extended structure of union-find tree</a>
* :warning: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2170&lang=jp"
#include <iostream>
#include "data_structure/link_cut_tree.hpp"
#include "utils/macros.hpp"
using namespace std;


int main() {
    while (true) {
        int n, q; cin >> n >> q;
        if (n == 0 and q == 0) break;

        link_cut_tree lct(n);
        REP3 (i, 1, n) {
            int parent; cin >> parent;
            -- parent;
            lct.link(i, parent);
        }

        long long sum = 0;
        while (q --) {
            char c; int v; cin >> c >> v;
            -- v;
            if (c == 'M') {
                lct.cut(v);
            } else if (c == 'Q') {
                sum += lct.get_root(v) + 1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

