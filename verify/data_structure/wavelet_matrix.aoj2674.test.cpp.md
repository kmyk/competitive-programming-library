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


# :heavy_check_mark: data_structure/wavelet_matrix.aoj2674.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/wavelet_matrix.aoj2674.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-16 04:00:06 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/fully_indexable_dictionary.hpp.html">a fully indexable dictionary <small>(data_structure/fully_indexable_dictionary.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/data_structure/wavelet_matrix.hpp.html">a wavelet matrix <small>(data_structure/wavelet_matrix.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"
#include "data_structure/wavelet_matrix.hpp"
#include "utils/macros.hpp"
#include <cstdio>
#include <numeric>
using namespace std;

int main() {
    constexpr int BITS = 30;
    constexpr int MIN_X = -1e8;
    constexpr int MAX_X = 1e8;

    // read a sequence
    int d; scanf("%d", &d);
    vector<int> x(d);
    REP (i, d) {
        scanf("%d", &x[i]);
        x[i] -= MIN_X;
    }

    // construct a wavelet matrix
    wavelet_matrix<BITS> wm(x);

    // answer to queries
    int q; scanf("%d", &q);
    while (q --) {
        int l, r, e; scanf("%d%d%d", &l, &r, &e);
        -- l;
        int a = min(x[l], x[r - 1]);
        int b = max(x[l], x[r - 1]);
        int cnt = 0;
        cnt += wm.range_frequency(l, r, 0, max(0, a - e));
        cnt += wm.range_frequency(l, r, min(MAX_X - MIN_X + 1, b + e + 1), MAX_X - MIN_X + 1);
        printf("%d\n", cnt);
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

