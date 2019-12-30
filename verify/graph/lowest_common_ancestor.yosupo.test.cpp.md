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


# :heavy_check_mark: graph/lowest_common_ancestor.yosupo.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/graph/lowest_common_ancestor.yosupo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-30 22:14:44+09:00


* see: <a href="https://judge.yosupo.jp/problem/lca">https://judge.yosupo.jp/problem/lca</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/sparse_table.hpp.html">a sparse table on a semilattice <small>(data_structure/sparse_table.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/graph/lowest_common_ancestor.hpp.html">lowest common ancestor with $\pm$ 1 RMQ and sparse table <small>(graph/lowest_common_ancestor.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/monoids/min_index.hpp.html">monoids/min_index.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/stack_pivot.hpp.html">utils/stack_pivot.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "graph/lowest_common_ancestor.hpp"

#include "utils/macros.hpp"
#include "utils/stack_pivot.hpp"
#include <cstdio>
#include <vector>
using namespace std;

int moin() {
    // read a tree
    int n, q; scanf("%d%d", &n, &q);
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int p; scanf("%d", &p);
        g[i + 1].push_back(p);
        g[p].push_back(i + 1);
    }

    // construct the LCA
    constexpr int root = 0;
    lowest_common_ancestor lca(root, g);

    // answer to queries
    while (q --) {
        int u, v; scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}

STACK_PIVOT_MAIN(moin)

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/lowest_common_ancestor.yosupo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#line 2 "graph/lowest_common_ancestor.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>
#line 2 "data_structure/sparse_table.hpp"
#include <cassert>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 5 "data_structure/sparse_table.hpp"

/**
 * @brief a sparse table on a semilattice
 * @note a semilattice is a commutative idempotent semigroup
 * @note for convenience, it requires the unit
 * @note $O(N \log N)$ space
 */
template <class Semilattice>
struct sparse_table {
    typedef typename Semilattice::value_type value_type;
    std::vector<std::vector<value_type> > table;
    Semilattice lat;
    sparse_table() = default;

    /**
     * @note $O(N \log N)$ time
     */
    sparse_table(std::vector<value_type> const & data, Semilattice const & lat_ = Semilattice())
            : lat(lat_) {
        int n = data.size();
        int log_n = 32 - __builtin_clz(n);
        table.resize(log_n, std::vector<value_type>(n));
        table[0] = data;
        REP (k, log_n - 1) {
            REP (i, n) {
                table[k + 1][i] = i + (1ll << k) < n ?
                    lat.mult(table[k][i], table[k][i + (1ll << k)]) :
                    table[k][i];
            }
        }
    }

    /**
     * @note $O(1)$
     */
    value_type range_concat(int l, int r) const {
        if (l == r) return lat.unit();  // if there is no unit, remove this line
        assert (0 <= l and l < r and r <= table[0].size());
        int k = 31 - __builtin_clz(r - l);  // log2
        return lat.mult(table[k][l], table[k][r - (1ll << k)]);
    }
};
#line 2 "monoids/min_index.hpp"
#include <algorithm>
#include <climits>
#include <limits>
#include <utility>

/**
 * @note a semilattice
 */
template <class T>
struct min_index_monoid {
    typedef std::pair<T, int> value_type;
    value_type unit() const { return std::make_pair(std::numeric_limits<T>::max(), INT_MAX); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};
#line 9 "graph/lowest_common_ancestor.hpp"

/**
 * @brief lowest common ancestor with $\pm$ 1 RMQ and sparse table
 * @see https://www.slideshare.net/yumainoue965/lca-and-rmq
 * @note verified http://www.utpc.jp/2011/problems/travel.html
 */
struct lowest_common_ancestor {
    sparse_table<min_index_monoid<int> > table;
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
        table = sparse_table<min_index_monoid<int> >(tour);
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
#line 3 "graph/lowest_common_ancestor.yosupo.test.cpp"

#line 2 "utils/stack_pivot.hpp"
#include <cstdlib>

/**
 * @note This is a workaround for WSL. We cannot use ulimit -s unlimited on the environment.
 * @note To use such techniques, you should take care of the alignment of rsp. If not, you'll get SIGSEGV around XMM registers.
 */

#define BEGIN_STACK_PIVOT(STACK_SIZE) \
    static volatile char *old_stack; \
    asm volatile("mov %%rsp, %0" : "=r" (old_stack) ); \
    char *new_stack = ((char *)malloc(STACK_SIZE) + (STACK_SIZE) - 0x10); \
    asm volatile("mov %0, %%rsp" : : "r" (new_stack) );

#define END_STACK_PIVOT() \
    asm volatile("mov %0, %%rsp" : : "r" (old_stack) );

#define STACK_PIVOT_MAIN(moin) \
    int main() { \
        BEGIN_STACK_PIVOT(1 << 28) \
        static int returncode = moin(); \
        END_STACK_PIVOT() \
        return returncode; \
    }
#line 6 "graph/lowest_common_ancestor.yosupo.test.cpp"
#include <cstdio>
#include <vector>
using namespace std;

int moin() {
    // read a tree
    int n, q; scanf("%d%d", &n, &q);
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int p; scanf("%d", &p);
        g[i + 1].push_back(p);
        g[p].push_back(i + 1);
    }

    // construct the LCA
    constexpr int root = 0;
    lowest_common_ancestor lca(root, g);

    // answer to queries
    while (q --) {
        int u, v; scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}

STACK_PIVOT_MAIN(moin)

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

