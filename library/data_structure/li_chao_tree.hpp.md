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


# :heavy_check_mark: Li-Chao tree <small>(data_structure/li_chao_tree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/li_chao_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 19:38:32+09:00


## 概要

定義域を区間に制限された一次関数の集合 $F = \emptyset \subseteq \lbrace \lambda x \in \lbrack l, r). ax + b \mid a, b, l, r \in \mathbb{Z} \rbrace$ に対し、次が処理可能:

-   線分追加: 与えられた $f = \lambda x \lbrack l, r). ax + b$ に対し $F \gets F \cup \lbrace f \rbrace$ と均し $O(\log N)$ で更新する
-   最小値取得: 与えられた $x$ に対し $$\min _ {f \in F \wdge f : \lbrack l, r) \wedge i \in \lbrack l, r)} f(x)$$ を $O(\log N)$ で計算する


## Depends on

* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/li_chao_tree.segment_add_get_min.test.cpp.html">data_structure/li_chao_tree.segment_add_get_min.test.cpp</a>


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
 * @brief Li-Chao tree
 * @docs data_structure/li_chao_tree.md
 */
struct li_chao_tree {
    int k;
    std::vector<std::pair<int64_t, int64_t> > f;
    std::vector<int64_t> x;
    std::vector<int64_t> y;
    li_chao_tree() = default;
    li_chao_tree(const std::vector<int64_t> & x_) : x(x_) {
        assert (std::is_sorted(ALL(x)));
        k = 0; while ((1 << k) < x.size()) ++ k;
        f.resize((1 << k) - 1, std::make_pair(0, std::numeric_limits<int64_t>::max()));
        y.resize(x.size(), std::numeric_limits<int64_t>::max());
    }
    /**
     * @note i is a point on the original space
     */
    int64_t get_min(int64_t i) {
        i = std::lower_bound(ALL(x), i) - x.begin();
        return get_min_compressed(i);
    }
    int64_t get_min_compressed(int i) {  // 0-based
        assert (0 <= i and i < x.size());
        int64_t z = y[i];
        for (int j = (i + (1 << k)) / 2; j > 0; j /= 2) {  // 1-based
            z = std::min(z, f[j - 1].first * x[i] + f[j - 1].second);
        }
        return z;
    }
    /**
     * @note [l, r) is an interval on the original space
     */
    void add_segment(int64_t l, int64_t r, int64_t a, int64_t b) {
        l = std::lower_bound(ALL(x), l) - x.begin();
        r = std::lower_bound(ALL(x), r) - x.begin();
        add_segment_compressed(l, r, a, b);
    }
    void add_segment_compressed(int64_t l, int64_t r, int64_t a, int64_t b) {
        assert (0 <= l and l <= r and r <= x.size());
        add_segment_compressed(0, 0, 1 << k, l, r, a, b);
    }
    void add_segment_compressed(int i, int il, int ir, int l, int r, int64_t a, int64_t b) {
        if (l <= il and ir <= r) {  // 0-based
            if (i >= (1 << k) - 1) {
                int j = i - (1 << k) + 1;
                y[j] = std::min(y[j], a * x[j] + b);
            } else {
                int64_t xl = x[il];
                int64_t xr = x[ir - 1];  // [xl, xr]
                int64_t yl1 = f[i].first * xl + f[i].second;
                int64_t yr1 = f[i].first * xr + f[i].second;
                int64_t yl2 = a * xl + b;
                int64_t yr2 = a * xr + b;
                if (yl1 <= yl2 and yr1 <= yr2) {
                    // if forall x in [l, r]. f(x) <= g(x), then do nothing
                    // nop
                } else if (yl2 <= yl1 and yr2 <= yr1) {
                    // if forall x in [l, r]. g(x) <= f(x), then replace f with g
                    f[i] = std::make_pair(a, b);
                } else {
                    int64_t xm = x[(il + ir) / 2];
                    int64_t ym1 = f[i].first * xm + f[i].second;
                    int64_t ym2 = a * xm + b;
                    if (yl1 <= yl2 and ym1 <= ym2) {
                        // if forall x in [l, m]. f(x) <= g(x), then do recursion for [m, r] with f
                        add_segment_compressed(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (yl2 <= yl1 and ym2 <= ym1) {
                        // if forall x in [l, m]. g(x) <= f(x), then replace f with g and do recursion for [m, r] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment_compressed(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (ym1 <= ym2 and yr1 <= yr2) {
                        // if forall x in [m, r]. f(x) <= g(x), then do recursion for [l, m] with f
                        add_segment_compressed(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else if (ym2 <= ym1 and yr2 <= yr1) {
                        // if forall x in [m, r]. g(x) <= f(x), then replace f with g and do recursion for [l, m] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment_compressed(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else {
                        assert (false);
                    }
                }
            }
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            add_segment_compressed(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
            add_segment_compressed(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
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
 * @brief Li-Chao tree
 * @docs data_structure/li_chao_tree.md
 */
struct li_chao_tree {
    int k;
    std::vector<std::pair<int64_t, int64_t> > f;
    std::vector<int64_t> x;
    std::vector<int64_t> y;
    li_chao_tree() = default;
    li_chao_tree(const std::vector<int64_t> & x_) : x(x_) {
        assert (std::is_sorted(ALL(x)));
        k = 0; while ((1 << k) < x.size()) ++ k;
        f.resize((1 << k) - 1, std::make_pair(0, std::numeric_limits<int64_t>::max()));
        y.resize(x.size(), std::numeric_limits<int64_t>::max());
    }
    /**
     * @note i is a point on the original space
     */
    int64_t get_min(int64_t i) {
        i = std::lower_bound(ALL(x), i) - x.begin();
        return get_min_compressed(i);
    }
    int64_t get_min_compressed(int i) {  // 0-based
        assert (0 <= i and i < x.size());
        int64_t z = y[i];
        for (int j = (i + (1 << k)) / 2; j > 0; j /= 2) {  // 1-based
            z = std::min(z, f[j - 1].first * x[i] + f[j - 1].second);
        }
        return z;
    }
    /**
     * @note [l, r) is an interval on the original space
     */
    void add_segment(int64_t l, int64_t r, int64_t a, int64_t b) {
        l = std::lower_bound(ALL(x), l) - x.begin();
        r = std::lower_bound(ALL(x), r) - x.begin();
        add_segment_compressed(l, r, a, b);
    }
    void add_segment_compressed(int64_t l, int64_t r, int64_t a, int64_t b) {
        assert (0 <= l and l <= r and r <= x.size());
        add_segment_compressed(0, 0, 1 << k, l, r, a, b);
    }
    void add_segment_compressed(int i, int il, int ir, int l, int r, int64_t a, int64_t b) {
        if (l <= il and ir <= r) {  // 0-based
            if (i >= (1 << k) - 1) {
                int j = i - (1 << k) + 1;
                y[j] = std::min(y[j], a * x[j] + b);
            } else {
                int64_t xl = x[il];
                int64_t xr = x[ir - 1];  // [xl, xr]
                int64_t yl1 = f[i].first * xl + f[i].second;
                int64_t yr1 = f[i].first * xr + f[i].second;
                int64_t yl2 = a * xl + b;
                int64_t yr2 = a * xr + b;
                if (yl1 <= yl2 and yr1 <= yr2) {
                    // if forall x in [l, r]. f(x) <= g(x), then do nothing
                    // nop
                } else if (yl2 <= yl1 and yr2 <= yr1) {
                    // if forall x in [l, r]. g(x) <= f(x), then replace f with g
                    f[i] = std::make_pair(a, b);
                } else {
                    int64_t xm = x[(il + ir) / 2];
                    int64_t ym1 = f[i].first * xm + f[i].second;
                    int64_t ym2 = a * xm + b;
                    if (yl1 <= yl2 and ym1 <= ym2) {
                        // if forall x in [l, m]. f(x) <= g(x), then do recursion for [m, r] with f
                        add_segment_compressed(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (yl2 <= yl1 and ym2 <= ym1) {
                        // if forall x in [l, m]. g(x) <= f(x), then replace f with g and do recursion for [m, r] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment_compressed(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (ym1 <= ym2 and yr1 <= yr2) {
                        // if forall x in [m, r]. f(x) <= g(x), then do recursion for [l, m] with f
                        add_segment_compressed(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else if (ym2 <= ym1 and yr2 <= yr1) {
                        // if forall x in [m, r]. g(x) <= f(x), then replace f with g and do recursion for [l, m] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment_compressed(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else {
                        assert (false);
                    }
                }
            }
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            add_segment_compressed(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
            add_segment_compressed(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

