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


# :heavy_check_mark: data_structure/li_chao_tree.segment_add_get_min.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/li_chao_tree.segment_add_get_min.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 14:39:34+09:00


* see: <a href="https://judge.yosupo.jp/problem/segment_add_get_min">https://judge.yosupo.jp/problem/segment_add_get_min</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/li_chao_tree.hpp.html">Li-Chao tree <small>(data_structure/li_chao_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "data_structure/li_chao_tree.hpp"
#include "utils/macros.hpp"
#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    // input
    int n, q; scanf("%d%d", &n, &q);
    vector<int64_t> xs;
    vector<tuple<int64_t, int64_t, int64_t, int64_t> > segments;
    REP (i, n) {
        int64_t l, r, a, b; scanf("%lld%lld%lld%lld", &l, &r, &a, &b);
        xs.push_back(l);
        xs.push_back(r);
        segments.emplace_back(l, r, a, b);
    }
    vector<tuple<int, int64_t, int64_t, int64_t, int64_t, int64_t> > queries;
    REP (j, q) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int64_t l, r, a, b; scanf("%lld%lld%lld%lld", &l, &r, &a, &b);
            xs.push_back(l);
            xs.push_back(r);
            queries.emplace_back(t, l, r, a, b, -1);
        } else if (t == 1) {
            int64_t p; scanf("%lld", &p);
            xs.push_back(p);
            queries.emplace_back(t, -1, -1, -1, -1, p);
        } else {
            assert (false);
        }
    }

    // construct
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    li_chao_tree lichao(xs);

    // output
    for (auto [l, r, a, b] : segments) {
        lichao.add_segment(l, r, a, b);
    }
    for (auto [t, l, r, a, b, p] : queries) {
        if (t == 0) {
            lichao.add_segment(l, r, a, b);
        } else if (t == 1) {
            int64_t q = lichao.get_min(p);
            if (q == INT64_MAX) {
                printf("INFINITY\n");
            } else {
                printf("%lld\n", q);
            }
        } else {
            assert (false);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/li_chao_tree.segment_add_get_min.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
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
#line 4 "data_structure/li_chao_tree.segment_add_get_min.test.cpp"
#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    // input
    int n, q; scanf("%d%d", &n, &q);
    vector<int64_t> xs;
    vector<tuple<int64_t, int64_t, int64_t, int64_t> > segments;
    REP (i, n) {
        int64_t l, r, a, b; scanf("%lld%lld%lld%lld", &l, &r, &a, &b);
        xs.push_back(l);
        xs.push_back(r);
        segments.emplace_back(l, r, a, b);
    }
    vector<tuple<int, int64_t, int64_t, int64_t, int64_t, int64_t> > queries;
    REP (j, q) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int64_t l, r, a, b; scanf("%lld%lld%lld%lld", &l, &r, &a, &b);
            xs.push_back(l);
            xs.push_back(r);
            queries.emplace_back(t, l, r, a, b, -1);
        } else if (t == 1) {
            int64_t p; scanf("%lld", &p);
            xs.push_back(p);
            queries.emplace_back(t, -1, -1, -1, -1, p);
        } else {
            assert (false);
        }
    }

    // construct
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    li_chao_tree lichao(xs);

    // output
    for (auto [l, r, a, b] : segments) {
        lichao.add_segment(l, r, a, b);
    }
    for (auto [t, l, r, a, b, p] : queries) {
        if (t == 0) {
            lichao.add_segment(l, r, a, b);
        } else if (t == 1) {
            int64_t q = lichao.get_min(p);
            if (q == INT64_MAX) {
                printf("INFINITY\n");
            } else {
                printf("%lld\n", q);
            }
        } else {
            assert (false);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

