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


# :heavy_check_mark: data_structure/wavelet_matrix.rectangle_sum.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/wavelet_matrix.rectangle_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-16 03:47:02 +0900


* see: <a href="https://judge.yosupo.jp/problem/rectangle_sum">https://judge.yosupo.jp/problem/rectangle_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/fully_indexable_dictionary.hpp.html">a fully indexable dictionary <small>(data_structure/fully_indexable_dictionary.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/data_structure/wavelet_matrix.hpp.html">a wavelet matrix <small>(data_structure/wavelet_matrix.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "data_structure/wavelet_matrix.hpp"
#include "utils/macros.hpp"
#include <cstdint>
#include <cstdio>
#include <numeric>
using namespace std;

int main() {
    // read points
    int n, q; scanf("%d%d", &n, &q);
    vector<int> x(n);
    vector<int> y(n);
    vector<long long> w(n);
    REP (i, n) {
        scanf("%d%d%lld", &x[i], &y[i], &w[i]);
    }

    // construct wavlet matrices
    constexpr int BITS = 30;
    vector<int> order(n);
    iota(ALL(order), 0);
    sort(ALL(order), [&](int i, int j) {
        return x[i] < x[j];
    });
    constexpr int WIDTH = 16;
    constexpr int HEIGHT = 8;
    array<vector<int>, HEIGHT> x1;
    array<vector<int>, HEIGHT> y1;
    for (int i : order) {
        long long w_i = w[i];
        for (int k = 0; w_i; ++ k) {
            assert (k < HEIGHT);
            REP (j, w_i % WIDTH) {
                x1[k].push_back(x[i]);
                y1[k].push_back(y[i]);
            }
            w_i /= WIDTH;
        }
    }
    array<wavelet_matrix<BITS>, HEIGHT> wm;
    REP (k, HEIGHT) {
        wm[k] = wavelet_matrix<BITS>(y1[k]);
    }

    // answer to queries
    REP (i, q) {
        int lx, ly, rx, ry; scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        long long answer = 0;
        REP_R (k, HEIGHT) {
            int l = lower_bound(ALL(x1[k]), lx) - x1[k].begin();
            int r = lower_bound(ALL(x1[k]), rx) - x1[k].begin();
            int a = ly;
            int b = ry;
            answer *= WIDTH;
            answer += wm[k].range_frequency(l, r, a, b);
        }
        printf("%lld\n", answer);
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

