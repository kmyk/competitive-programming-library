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


# :warning: Karatsuba method ($O(n^{\log_2 3})$) <small>(number/karatsuba.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/karatsuba.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 20:59:07+09:00




## Depends on

* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief Karatsuba method ($O(n^{\log_2 3})$)
 */
template <class CommutativeRing>
std::vector<CommutativeRing> karatsuba_convolution(const std::vector<CommutativeRing> & x, const std::vector<CommutativeRing> & y) {
    int n = x.size();
    int m = y.size();
    if ((int64_t)n * m <= 100) {
        std::vector<CommutativeRing> z(n + m - 1);
        REP (i, n) REP (j, m) {
            z[i + j] += x[i] * y[j];
        }
        return z;
    }
    int half = (std::max(n, m) + 1) / 2;

    std::vector<CommutativeRing> x0(x.begin(), x.begin() + std::min(n, half));
    std::vector<CommutativeRing> y0(y.begin(), y.begin() + std::min(m, half));
    std::vector<CommutativeRing> z0 = karatsuba_convolution(x0, y0);

    std::vector<CommutativeRing> x1(x.begin() + std::min(n, half), x.end());
    std::vector<CommutativeRing> y1(y.begin() + std::min(m, half), y.end());
    std::vector<CommutativeRing> z2 = karatsuba_convolution(x1, y1);

    assert (x1.size() <= x0.size());
    std::vector<CommutativeRing> dx = x0;
    REP (i, x1.size()) dx[i] -= x1[i];
    assert (y1.size() <= y0.size());
    std::vector<CommutativeRing> dy = y0;
    REP (i, y1.size()) dy[i] -= y1[i];
    std::vector<CommutativeRing> dz = karatsuba_convolution(dx, dy);

    std::vector<CommutativeRing> z(n + m - 1);
    REP (i, z0.size()) {
        z[i] += z0[i];
        if (half + i < (int)z.size()) z[half + i] += z0[i];
    }
    REP (i, dz.size()) {
        if (half + i < (int)z.size()) z[half + i] -= dz[i];
    }
    REP (i, z2.size()) {
        z[half + i] += z2[i];
        if (2 * half + i < (int)z.size()) z[2 * half + i] += z2[i];
    }
    return z;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "number/karatsuba.hpp"
#include <cassert>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 5 "number/karatsuba.hpp"

/**
 * @brief Karatsuba method ($O(n^{\log_2 3})$)
 */
template <class CommutativeRing>
std::vector<CommutativeRing> karatsuba_convolution(const std::vector<CommutativeRing> & x, const std::vector<CommutativeRing> & y) {
    int n = x.size();
    int m = y.size();
    if ((int64_t)n * m <= 100) {
        std::vector<CommutativeRing> z(n + m - 1);
        REP (i, n) REP (j, m) {
            z[i + j] += x[i] * y[j];
        }
        return z;
    }
    int half = (std::max(n, m) + 1) / 2;

    std::vector<CommutativeRing> x0(x.begin(), x.begin() + std::min(n, half));
    std::vector<CommutativeRing> y0(y.begin(), y.begin() + std::min(m, half));
    std::vector<CommutativeRing> z0 = karatsuba_convolution(x0, y0);

    std::vector<CommutativeRing> x1(x.begin() + std::min(n, half), x.end());
    std::vector<CommutativeRing> y1(y.begin() + std::min(m, half), y.end());
    std::vector<CommutativeRing> z2 = karatsuba_convolution(x1, y1);

    assert (x1.size() <= x0.size());
    std::vector<CommutativeRing> dx = x0;
    REP (i, x1.size()) dx[i] -= x1[i];
    assert (y1.size() <= y0.size());
    std::vector<CommutativeRing> dy = y0;
    REP (i, y1.size()) dy[i] -= y1[i];
    std::vector<CommutativeRing> dz = karatsuba_convolution(dx, dy);

    std::vector<CommutativeRing> z(n + m - 1);
    REP (i, z0.size()) {
        z[i] += z0[i];
        if (half + i < (int)z.size()) z[half + i] += z0[i];
    }
    REP (i, dz.size()) {
        if (half + i < (int)z.size()) z[half + i] -= dz[i];
    }
    REP (i, z2.size()) {
        z[half + i] += z2[i];
        if (2 * half + i < (int)z.size()) z[2 * half + i] += z2[i];
    }
    return z;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

