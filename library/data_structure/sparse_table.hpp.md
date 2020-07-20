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


# :heavy_check_mark: Sparse Table (idempotent monoid) <small>(data_structure/sparse_table.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/sparse_table.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 19:51:45+09:00




## Depends on

* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Required by

* :heavy_check_mark: <a href="../graph/lowest_common_ancestor.hpp.html">lowest common ancestor / 最小共通祖先 (前処理 $O(N)$ + $O(1)$, $\pm 1$ RMQ and sparse table) <small>(graph/lowest_common_ancestor.hpp)</small></a>
* :heavy_check_mark: <a href="../string/longest_common_prefix.hpp.html">Longest Common Prefix / 最長共通接頭辞 (接尾辞配列, 前処理 $O(N (\log N)^2)$ + $O(1)$) <small>(string/longest_common_prefix.hpp)</small></a>
* :heavy_check_mark: <a href="../utils/left-to-right-maxima.hpp.html">Length of Left-to-right Maxima (前処理 $O(n \log n)$ + $O(1)$) <small>(utils/left-to-right-maxima.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/sparse_table.yosupo.test.cpp.html">data_structure/sparse_table.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/sparse_table.yukicoder-1036.test.cpp.html">data_structure/sparse_table.yukicoder-1036.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/cartesian_tree.yukicoder-1031.test.cpp.html">graph/cartesian_tree.yukicoder-1031.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/lowest_common_ancestor.aoj.test.cpp.html">graph/lowest_common_ancestor.aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/lowest_common_ancestor.yosupo.test.cpp.html">graph/lowest_common_ancestor.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/old/rollback-square-decomposition.yukicoder-1031.test.cpp.html">old/rollback-square-decomposition.yukicoder-1031.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/string/longest_common_prefix.yosupo.test.cpp.html">string/longest_common_prefix.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief Sparse Table (idempotent monoid)
 * @note the unit is required just for convenience
 * @note $O(N \log N)$ space
 */
template <class IdempotentMonoid>
struct sparse_table {
    typedef typename IdempotentMonoid::value_type value_type;
    std::vector<std::vector<value_type> > table;
    IdempotentMonoid mon;
    sparse_table() = default;

    /**
     * @note $O(N \log N)$ time
     */
    template <class InputIterator>
    sparse_table(InputIterator first, InputIterator last, const IdempotentMonoid & mon_ = IdempotentMonoid())
            : mon(mon_) {
        table.emplace_back(first, last);
        int n = table[0].size();
        int log_n = 32 - __builtin_clz(n);
        table.resize(log_n, std::vector<value_type>(n));
        REP (k, log_n - 1) {
            REP (i, n) {
                table[k + 1][i] = i + (1ll << k) < n ?
                    mon.mult(table[k][i], table[k][i + (1ll << k)]) :
                    table[k][i];
            }
        }
    }

    /**
     * @note $O(1)$
     */
    value_type range_get(int l, int r) const {
        if (l == r) return mon.unit();  // if there is no unit, remove this line
        assert (0 <= l and l < r and r <= (int)table[0].size());
        int k = 31 - __builtin_clz(r - l);  // log2
        return mon.mult(table[k][l], table[k][r - (1ll << k)]);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
 * @brief Sparse Table (idempotent monoid)
 * @note the unit is required just for convenience
 * @note $O(N \log N)$ space
 */
template <class IdempotentMonoid>
struct sparse_table {
    typedef typename IdempotentMonoid::value_type value_type;
    std::vector<std::vector<value_type> > table;
    IdempotentMonoid mon;
    sparse_table() = default;

    /**
     * @note $O(N \log N)$ time
     */
    template <class InputIterator>
    sparse_table(InputIterator first, InputIterator last, const IdempotentMonoid & mon_ = IdempotentMonoid())
            : mon(mon_) {
        table.emplace_back(first, last);
        int n = table[0].size();
        int log_n = 32 - __builtin_clz(n);
        table.resize(log_n, std::vector<value_type>(n));
        REP (k, log_n - 1) {
            REP (i, n) {
                table[k + 1][i] = i + (1ll << k) < n ?
                    mon.mult(table[k][i], table[k][i + (1ll << k)]) :
                    table[k][i];
            }
        }
    }

    /**
     * @note $O(1)$
     */
    value_type range_get(int l, int r) const {
        if (l == r) return mon.unit();  // if there is no unit, remove this line
        assert (0 <= l and l < r and r <= (int)table[0].size());
        int k = 31 - __builtin_clz(r - l);  // log2
        return mon.mult(table[k][l], table[k][r - (1ll << k)]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

