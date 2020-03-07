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


# :heavy_check_mark: data_structure/sparse_table.yosupo.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/sparse_table.yosupo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 19:51:45+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/sparse_table.hpp.html">Sparse Table (idempotent monoid) <small>(data_structure/sparse_table.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/monoids/min.hpp.html">monoids/min.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "data_structure/sparse_table.hpp"

#include "utils/macros.hpp"
#include "monoids/min.hpp"
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // input a sequence
    int n, q; scanf("%d%d", &n, &q);
    vector<int> a(n);
    REP (i, n) {
        scanf("%d", &a[i]);
    }

    // construct the sparse table
    sparse_table<min_monoid<int> > st(ALL(a));

    // answer to queries
    while (q --) {
        int l, r; scanf("%d%d", &l, &r);
        int answer = st.range_get(l, r);
        printf("%d\n", answer);
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/sparse_table.yosupo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
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
#line 3 "data_structure/sparse_table.yosupo.test.cpp"

#line 2 "monoids/min.hpp"
#include <algorithm>
#include <limits>

template <class T>
struct min_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::max(); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};
#line 6 "data_structure/sparse_table.yosupo.test.cpp"
#include <cstdio>
#line 8 "data_structure/sparse_table.yosupo.test.cpp"
using namespace std;

int main() {
    // input a sequence
    int n, q; scanf("%d%d", &n, &q);
    vector<int> a(n);
    REP (i, n) {
        scanf("%d", &a[i]);
    }

    // construct the sparse table
    sparse_table<min_monoid<int> > st(ALL(a));

    // answer to queries
    while (q --) {
        int l, r; scanf("%d%d", &l, &r);
        int answer = st.range_get(l, r);
        printf("%d\n", answer);
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

