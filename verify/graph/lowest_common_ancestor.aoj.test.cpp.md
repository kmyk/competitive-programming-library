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


# :heavy_check_mark: graph/lowest_common_ancestor.aoj.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/graph/lowest_common_ancestor.aoj.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-24 17:26:39 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C</a>


## Depends On
* :heavy_check_mark: <a href="../../library/data_structure/sparse_table.hpp.html">sparse table on a semilattice</a>
* :heavy_check_mark: <a href="../../library/graph/lowest_common_ancestor.hpp.html">lowest common ancestor with \pm 1 RMQ and sparse table</a>
* :heavy_check_mark: <a href="../../library/number/gcd.hpp.html">number/gcd.hpp</a>
* :warning: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "graph/lowest_common_ancestor.hpp"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    // read a tree
    int n; cin >> n;
    vector<vector<int> > g(n);
    REP (i, n) {
        int k; cin >> k;
        REP (j, k) {
            int c; cin >> c;
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }

    // construct the LCA
    constexpr int root = 0;
    lowest_common_ancestor lca(root, g);

    // answer to queries
    int q; cin >> q;
    while (q --) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

