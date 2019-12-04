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


# :warning: data_structure/sparse_table.hpp
* category: data_structure


[Back to top page](../../index.html)

* sparse table on a semilattice


## Dependencies
* :heavy_check_mark: [number/gcd.hpp](../number/gcd.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../utils/macros.hpp.html)


## Required
* :heavy_check_mark: [graph/lowest_common_ancestor.hpp](../graph/lowest_common_ancestor.hpp.html)


## Verified
* :heavy_check_mark: [data_structure/sparse_table.unit.test.cpp](../../verify/data_structure/sparse_table.unit.test.cpp.html)


## Code
```cpp
#pragma once
#include <cassert>
#include <vector>
#include "utils/macros.hpp"

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
#include "number/gcd.hpp"

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

```

[Back to top page](../../index.html)

