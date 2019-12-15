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


# :warning: number/lagrange_interpolation.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/lagrange_interpolation.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-13 18:43:42 +0900




## Depends on

* :warning: <a href="lagrange_interpolation.hpp.html">Lagrange interpolation <small>(number/lagrange_interpolation.hpp)</small></a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

{% raw %}
```cpp
#include "number/lagrange_interpolation.hpp"

#include <cassert>
#include <random>
#include <set>
#include <tuple>
#include <utility>
#include <iostream>
using namespace std;

long double apply(std::vector<long double> & f, long double x) {
    long double y = 0;
    REP_R (i, f.size()) {
        y = y * x + f[i];
    }
    return y;
}

int main() {
    default_random_engine gen;
    REP (iteration, 20) {
        // generate
        vector<pair<long double, long double> > points;
        set<int> used;
        REP (i, iteration) {
            int z_i = uniform_int_distribution<int>(- 100, 100)(gen);
            if (used.count(z_i)) continue;
            used.insert(z_i);
            long double x_i = z_i / 10.0L;
            long double y_i = uniform_int_distribution<int>(- 100, 100)(gen) / 10.0L;
            points.emplace_back(x_i, y_i);
        }

        // run
        auto f = lagrange_interpolate(points);

        // check
        constexpr long double eps = 1e-4;
        assert (f.size() == points.size());
        for (auto point : points) {
            long double x, y; tie(x, y) = point;
            assert (abs(apply(f, x) - y) < eps);
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

