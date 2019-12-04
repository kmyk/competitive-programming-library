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


# :heavy_check_mark: data_structure/link_cut_tree.marked_ancestor.test.cpp


[Back to top page](../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2170&lang=jp](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2170&lang=jp)


## Dependencies
* :heavy_check_mark: [data_structure/link_cut_tree.hpp](../../library/data_structure/link_cut_tree.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)


## Code
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

[Back to top page](../../index.html)

