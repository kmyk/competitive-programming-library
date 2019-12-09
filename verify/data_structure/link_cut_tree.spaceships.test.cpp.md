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


# :heavy_check_mark: data_structure/link_cut_tree.spaceships.test.cpp


[Back to top page](../../index.html)

* see: [https://atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships](https://atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships)


## Dependencies
* :heavy_check_mark: [an extended structure of union-find tree](../../library/data_structure/link_cut_tree.hpp.html)


## Code
{% raw %}
```cpp
// #define PROBLEM "https://atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships"
#include <cassert>
#include "data_structure/link_cut_tree.hpp"

/*
int main() {
    int n, q; cin >> n >> q;
    link_cut_tree g(n);
    while (q --) {
        int t, a; cin >> t >> a; -- a;
        if (t == 1) {
            int b; cin >> b; -- b;
            g.link(a, b);
        } else if (t == 2) {
            g.cut(a);
        } else if (t == 3) {
            int b; cin >> b; -- b;
            int c = g.get_lowest_common_ancestor(a, b);
            cout << (c == -1 ? -1 : c + 1) << endl;
        } else {
            assert (false);
        }
    }
    return 0;
}
*/

void sample1() {
    link_cut_tree g(6);
    g.link(1, 3);
    assert (g.get_lowest_common_ancestor(1, 5) == -1);
    g.link(3, 2);
    g.link(5, 3);
    assert (g.get_lowest_common_ancestor(1, 5) == 3);
}

void sample2() {
    link_cut_tree g(8);
    g.link(0, 1);
    g.link(5, 4);
    g.link(6, 7);
    assert (g.get_lowest_common_ancestor(4, 5) == 4);
    g.link(4, 3);
    g.link(7, 0);
    assert (g.get_lowest_common_ancestor(6, 1) == 1);
    assert (g.get_lowest_common_ancestor(2, 7) == -1);
    assert (g.get_lowest_common_ancestor(0, 7) == 0);
    g.link(2, 1);
    g.link(3, 0);
    assert (g.get_lowest_common_ancestor(7, 4) == 0);
    assert (g.get_lowest_common_ancestor(3, 2) == 1);
    g.cut(3);
    assert (g.get_lowest_common_ancestor(5, 7) == -1);
    g.link(1, 4);
    assert (g.get_lowest_common_ancestor(5, 7) == 4);
    g.cut(7);
    assert (g.get_lowest_common_ancestor(0, 3) == 3);
    assert (g.get_lowest_common_ancestor(5, 7) == -1);
    assert (g.get_lowest_common_ancestor(5, 2) == 4);
    g.cut(2);
    assert (g.get_lowest_common_ancestor(0, 1) == 1);
    g.link(3, 2);
    assert (g.get_lowest_common_ancestor(1, 5) == 4);
    g.link(7, 2);
    assert (g.get_lowest_common_ancestor(0, 6) == 2);
    assert (g.get_lowest_common_ancestor(0, 5) == 4);
    assert (g.get_lowest_common_ancestor(4, 3) == 3);
    g.cut(1);
    g.cut(4);
    g.link(2, 5);
    g.link(1, 6);
    assert (g.get_lowest_common_ancestor(0, 3) == 2);
    assert (g.get_lowest_common_ancestor(0, 4) == 4);
    assert (g.get_lowest_common_ancestor(5, 6) == 5);
}

int main() {
    sample1();
    sample2();
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

