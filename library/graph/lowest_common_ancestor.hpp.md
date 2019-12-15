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


# :heavy_check_mark: lowest common ancestor with $\pm$ 1 RMQ and sparse table <small>(graph/lowest_common_ancestor.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/lowest_common_ancestor.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 03:56:03 +0900


* see: <a href="https://www.slideshare.net/yumainoue965/lca-and-rmq">https://www.slideshare.net/yumainoue965/lca-and-rmq</a>


## Depends on

* :heavy_check_mark: <a href="../data_structure/sparse_table.hpp.html">sparse table on a semilattice <small>(data_structure/sparse_table.hpp)</small></a>
* :heavy_check_mark: <a href="../number/gcd.hpp.html">number/gcd.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/graph/lowest_common_ancestor.aoj.test.cpp.html">graph/lowest_common_ancestor.aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>
#include "data_structure/sparse_table.hpp"

/**
 * @brief lowest common ancestor with $\pm$ 1 RMQ and sparse table
 * @see https://www.slideshare.net/yumainoue965/lca-and-rmq
 * @note verified http://www.utpc.jp/2011/problems/travel.html
 */
struct lowest_common_ancestor {
    sparse_table<indexed_min_semilattice> table;
    std::vector<int> index;
    lowest_common_ancestor() = default;
    /**
     * @note $O(N)$
     * @param g is an adjacent list of a tree
     * @note you can easily modify this to accept forests
     */
    lowest_common_ancestor(int root, std::vector<std::vector<int> > const & g) {
        std::vector<std::pair<int, int> > tour;
        index.assign(g.size(), -1);
        dfs(root, -1, 0, g, tour);
        table = sparse_table<indexed_min_semilattice>(tour);
    }
private:
    /**
     * @note to avoid stack overflow
     */
    void dfs(int x, int parent, int depth, std::vector<std::vector<int> > const & g, std::vector<std::pair<int, int> > & tour) {
        index[x] = tour.size();
        tour.emplace_back(depth, x);
        for (int y : g[x]) if (y != parent) {
            dfs(y, x, depth + 1, g, tour);
            tour.emplace_back(depth, x);
        }
    }
public:
    /**
     * @note $O(1)$
     */
    int operator () (int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        x = index[x];
        y = index[y];
        if (x > y) std::swap(x, y);
        return table.range_concat(x, y + 1).second;
    }
    int get_depth(int x) const {
        assert (0 <= x and x < index.size());
        return table.range_concat(index[x], index[x] + 1).first;
    }
    int get_dist(int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        int z = (*this)(x, y);
        return get_depth(x) + get_depth(y) - 2 * get_depth(z);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/lowest_common_ancestor.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>
#line 2 "data_structure/sparse_table.hpp"
#include <cassert>
#include <vector>
#line 1 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)
#line 5 "data_structure/sparse_table.hpp"

/**
 * @brief sparse table on a semilattice
 * @note a semilattice is a commutative idempotent semigroup
 * @note for convenience, it requires the unit
 * @note O(N log N) space
 */
template <class Semilattice>
struct sparse_table {
    typedef typename Semilattice::value_type value_type;
    std::vector<std::vector<value_type> > table;
    Semilattice lat;
    sparse_table() = default;
    /**
     * @note O(N \log N) time
     */
    sparse_table(std::vector<value_type> const & data, Semilattice const & a_lat = Semilattice())
            : lat(a_lat) {
        int n = data.size();
        int log_n = 32 - __builtin_clz(n);
        table.resize(log_n, std::vector<value_type>(n));
        table[0] = data;
        REP (k, log_n - 1) {
            REP (i, n) {
                table[k + 1][i] = i + (1ll << k) < n ?
                    lat.append(table[k][i], table[k][i + (1ll << k)]) :
                    table[k][i];
            }
        }
    }
    /**
     * @note O(1)
     */
    value_type range_concat(int l, int r) const {
        if (l == r) return lat.unit();  // if there is no unit, remove this line
        assert (0 <= l and l < r and r <= table[0].size());
        int k = 31 - __builtin_clz(r - l);  // log2
        return lat.append(table[k][l], table[k][r - (1ll << k)]);
    }
};


#include <algorithm>
#include <climits>
#line 2 "number/gcd.hpp"
#include <algorithm>

/**
 * @note if arguments are negative, the result may be negative
 */
template <typename T>
T gcd(T a, T b) {
    while (a) {
        b %= a;
        std::swap(a, b);
    }
    return b;
}

template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
#line 50 "data_structure/sparse_table.hpp"

struct max_semilattice {
    typedef int value_type;
    int unit() const { return INT_MIN; }
    int append(int a, int b) const { return std::max(a, b); }
};
struct min_semilattice {
    typedef int value_type;
    int unit() const { return INT_MAX; }
    int append(int a, int b) const { return std::min(a, b); }
};
struct gcd_semilattice {
    typedef int value_type;
    int unit() const { return 0; }
    int append(int a, int b) const { return gcd(a, b); }
};

struct indexed_min_semilattice {
    typedef std::pair<int, int> value_type;
    value_type unit() const { return { INT_MAX, INT_MAX }; }
    value_type append(value_type a, value_type b) const { return std::min(a, b); }
};
#line 8 "graph/lowest_common_ancestor.hpp"

/**
 * @brief lowest common ancestor with $\pm$ 1 RMQ and sparse table
 * @see https://www.slideshare.net/yumainoue965/lca-and-rmq
 * @note verified http://www.utpc.jp/2011/problems/travel.html
 */
struct lowest_common_ancestor {
    sparse_table<indexed_min_semilattice> table;
    std::vector<int> index;
    lowest_common_ancestor() = default;
    /**
     * @note $O(N)$
     * @param g is an adjacent list of a tree
     * @note you can easily modify this to accept forests
     */
    lowest_common_ancestor(int root, std::vector<std::vector<int> > const & g) {
        std::vector<std::pair<int, int> > tour;
        index.assign(g.size(), -1);
        dfs(root, -1, 0, g, tour);
        table = sparse_table<indexed_min_semilattice>(tour);
    }
private:
    /**
     * @note to avoid stack overflow
     */
    void dfs(int x, int parent, int depth, std::vector<std::vector<int> > const & g, std::vector<std::pair<int, int> > & tour) {
        index[x] = tour.size();
        tour.emplace_back(depth, x);
        for (int y : g[x]) if (y != parent) {
            dfs(y, x, depth + 1, g, tour);
            tour.emplace_back(depth, x);
        }
    }
public:
    /**
     * @note $O(1)$
     */
    int operator () (int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        x = index[x];
        y = index[y];
        if (x > y) std::swap(x, y);
        return table.range_concat(x, y + 1).second;
    }
    int get_depth(int x) const {
        assert (0 <= x and x < index.size());
        return table.range_concat(index[x], index[x] + 1).first;
    }
    int get_dist(int x, int y) const {
        assert (0 <= x and x < index.size());
        assert (0 <= y and y < index.size());
        int z = (*this)(x, y);
        return get_depth(x) + get_depth(y) - 2 * get_depth(z);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

