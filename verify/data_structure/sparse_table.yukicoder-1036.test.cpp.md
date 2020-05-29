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


# :heavy_check_mark: data_structure/sparse_table.yukicoder-1036.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/sparse_table.yukicoder-1036.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 23:33:38+09:00


* see: <a href="https://yukicoder.me/problems/no/1036">https://yukicoder.me/problems/no/1036</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/sparse_table.hpp.html">Sparse Table (idempotent monoid) <small>(data_structure/sparse_table.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/monoids/gcd.hpp.html">monoids/gcd.hpp</a>
* :heavy_check_mark: <a href="../../library/number/gcd.hpp.html">number/gcd.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include <cstdio>
#include <vector>
#include "utils/macros.hpp"
#include "data_structure/sparse_table.hpp"
#include "monoids/gcd.hpp"

long long solve(int n, const std::vector<long long> & a) {
    sparse_table<gcd_monoid<long long> > table(ALL(a));
    int r = 0;
    long long ans = 0;
    REP (l, n) {
        while (r < n and table.range_get(l, r) != 1) {
            ++ r;
        }
        if (r == n and table.range_get(l, r) != 1) {
            break;
        }
        ans += n - r + 1;
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    std::vector<long long> a(n);
    REP (i, n) {
        scanf("%lld", &a[i]);
    }
    printf("%lld\n", solve(n, a));
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/sparse_table.yukicoder-1036.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include <cstdio>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 2 "data_structure/sparse_table.hpp"
#include <cassert>
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
#line 3 "monoids/gcd.hpp"

/**
 * @note a semilattice
 */
template <class Integer>
struct gcd_monoid {
    typedef Integer value_type;
    Integer unit() const { return 0; }
    Integer mult(Integer a, Integer b) const { return gcd(a, b); }
};
#line 7 "data_structure/sparse_table.yukicoder-1036.test.cpp"

long long solve(int n, const std::vector<long long> & a) {
    sparse_table<gcd_monoid<long long> > table(ALL(a));
    int r = 0;
    long long ans = 0;
    REP (l, n) {
        while (r < n and table.range_get(l, r) != 1) {
            ++ r;
        }
        if (r == n and table.range_get(l, r) != 1) {
            break;
        }
        ans += n - r + 1;
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    std::vector<long long> a(n);
    REP (i, n) {
        scanf("%lld", &a[i]);
    }
    printf("%lld\n", solve(n, a));
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

