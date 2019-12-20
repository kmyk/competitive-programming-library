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


# :warning: data_structure/li_chao_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/li_chao_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00




## Depends on

* :warning: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Required by

* :warning: <a href="li_chao_tree.random-test.cpp.html">data_structure/li_chao_tree.random-test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

/**
 * @note Li-Chao tree
 */
template <class T>
struct li_chao_tree {
    int k;
    std::vector<std::pair<T, T> > f;
    std::vector<T> x;
    std::vector<T> y;
    li_chao_tree() = default;
    li_chao_tree(const std::vector<T> & x_) : x(x_) {
        assert (std::is_sorted(ALL(x)));
        k = 0; while ((1 << k) < x.size()) ++ k;
        f.resize((1 << k) - 1, std::make_pair(0, std::numeric_limits<T>::max()));
        y.resize(x.size(), std::numeric_limits<T>::max());
    }
    T get_min(int i) {  // 0-based
        assert (0 <= i and i < x.size());
        T z = y[i];
        for (int j = (i + (1 << k)) / 2; j > 0; j /= 2) {  // 1-based
            z = std::min(z, f[j - 1].first * x[i] + f[j - 1].second);
        }
        return z;
    }
    void add_segment(int l, int r, T a, T b) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= x.size());
        add_segment(0, 0, 1 << k, l, r, a, b);
    }
    void add_segment(int i, int il, int ir, int l, int r, T a, T b) {
        if (l <= il and ir <= r) {  // 0-based
            if (i >= (1 << k) - 1) {
                int j = i - (1 << k) + 1;
                y[j] = std::min(y[j], a * x[j] + b);
            } else {
                T xl = x[il];
                T xr = x[ir - 1];  // [xl, xr]
                T yl1 = f[i].first * xl + f[i].second;
                T yr1 = f[i].first * xr + f[i].second;
                T yl2 = a * xl + b;
                T yr2 = a * xr + b;
                if (yl1 <= yl2 and yr1 <= yr2) {
                    // if forall x in [l, r]. f(x) <= g(x), then do nothing
                    // nop
                } else if (yl2 <= yl1 and yr2 <= yr1) {
                    // if forall x in [l, r]. g(x) <= f(x), then replace f with g
                    f[i] = std::make_pair(a, b);
                } else {
                    T xm = x[(il + ir) / 2];
                    T ym1 = f[i].first * xm + f[i].second;
                    T ym2 = a * xm + b;
                    if (yl1 <= yl2 and ym1 <= ym2) {
                        // if forall x in [l, m]. f(x) <= g(x), then do recursion for [m, r] with f
                        add_segment(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (yl2 <= yl1 and ym2 <= ym1) {
                        // if forall x in [l, m]. g(x) <= f(x), then replace f with g and do recursion for [m, r] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (ym1 <= ym2 and yr1 <= yr2) {
                        // if forall x in [m, r]. f(x) <= g(x), then do recursion for [l, m] with f
                        add_segment(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else if (ym2 <= ym1 and yr2 <= yr1) {
                        // if forall x in [m, r]. g(x) <= f(x), then replace f with g and do recursion for [l, m] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else {
                        assert (false);
                    }
                }
            }
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            add_segment(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
            add_segment(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/li_chao_tree.hpp"
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 7 "data_structure/li_chao_tree.hpp"

/**
 * @note Li-Chao tree
 */
template <class T>
struct li_chao_tree {
    int k;
    std::vector<std::pair<T, T> > f;
    std::vector<T> x;
    std::vector<T> y;
    li_chao_tree() = default;
    li_chao_tree(const std::vector<T> & x_) : x(x_) {
        assert (std::is_sorted(ALL(x)));
        k = 0; while ((1 << k) < x.size()) ++ k;
        f.resize((1 << k) - 1, std::make_pair(0, std::numeric_limits<T>::max()));
        y.resize(x.size(), std::numeric_limits<T>::max());
    }
    T get_min(int i) {  // 0-based
        assert (0 <= i and i < x.size());
        T z = y[i];
        for (int j = (i + (1 << k)) / 2; j > 0; j /= 2) {  // 1-based
            z = std::min(z, f[j - 1].first * x[i] + f[j - 1].second);
        }
        return z;
    }
    void add_segment(int l, int r, T a, T b) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= x.size());
        add_segment(0, 0, 1 << k, l, r, a, b);
    }
    void add_segment(int i, int il, int ir, int l, int r, T a, T b) {
        if (l <= il and ir <= r) {  // 0-based
            if (i >= (1 << k) - 1) {
                int j = i - (1 << k) + 1;
                y[j] = std::min(y[j], a * x[j] + b);
            } else {
                T xl = x[il];
                T xr = x[ir - 1];  // [xl, xr]
                T yl1 = f[i].first * xl + f[i].second;
                T yr1 = f[i].first * xr + f[i].second;
                T yl2 = a * xl + b;
                T yr2 = a * xr + b;
                if (yl1 <= yl2 and yr1 <= yr2) {
                    // if forall x in [l, r]. f(x) <= g(x), then do nothing
                    // nop
                } else if (yl2 <= yl1 and yr2 <= yr1) {
                    // if forall x in [l, r]. g(x) <= f(x), then replace f with g
                    f[i] = std::make_pair(a, b);
                } else {
                    T xm = x[(il + ir) / 2];
                    T ym1 = f[i].first * xm + f[i].second;
                    T ym2 = a * xm + b;
                    if (yl1 <= yl2 and ym1 <= ym2) {
                        // if forall x in [l, m]. f(x) <= g(x), then do recursion for [m, r] with f
                        add_segment(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (yl2 <= yl1 and ym2 <= ym1) {
                        // if forall x in [l, m]. g(x) <= f(x), then replace f with g and do recursion for [m, r] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (ym1 <= ym2 and yr1 <= yr2) {
                        // if forall x in [m, r]. f(x) <= g(x), then do recursion for [l, m] with f
                        add_segment(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else if (ym2 <= ym1 and yr2 <= yr1) {
                        // if forall x in [m, r]. g(x) <= f(x), then replace f with g and do recursion for [l, m] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else {
                        assert (false);
                    }
                }
            }
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            add_segment(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
            add_segment(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

