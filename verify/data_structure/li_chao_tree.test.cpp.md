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


# :heavy_check_mark: data_structure/li_chao_tree.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/li_chao_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-24 17:27:27 +0900




## Depends On
* :heavy_check_mark: <a href="../../library/data_structure/li_chao_tree.hpp.html">data_structure/li_chao_tree.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code
{% raw %}
```cpp
#include "data_structure/li_chao_tree.hpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <random>
#include <vector>
#include "utils/macros.hpp"
using namespace std;


int main() {
    random_device device;
    default_random_engine gen(device());
    REP (subtest, 1000) {
        int n = uniform_int_distribution<int>(1, 200)(gen);
        vector<int> x(n);
        REP (i, n) {
            x[i] = uniform_int_distribution<int>(- 1000, 1000)(gen);
        }
        sort(ALL(x));
        vector<int> y(n, INT_MAX);
        li_chao_tree<int> lichao(x);
        REP (add_query, 100) {
            int l = uniform_int_distribution<int>(- 1000, 1000)(gen);
            int r = uniform_int_distribution<int>(- 1000, 1000)(gen);
            if (l > r) swap(l, r);
            int a = uniform_int_distribution<int>(- 300, 300)(gen);
            int b = uniform_int_distribution<int>(- 300, 300)(gen);
            REP (i, n) {
                if (l <= x[i] and x[i] < r) {
                    y[i] = min(y[i], a * x[i] + b);
                }
            }
            int il = lower_bound(ALL(x), l) - x.begin();
            int ir = lower_bound(ALL(x), r) - x.begin();
            lichao.add_segment(il, ir, a, b);
            REP (min_query, 10) {
                int i = uniform_int_distribution<int>(0, n - 1)(gen);
                assert (lichao.get_min(i) == y[i]);
            }
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

