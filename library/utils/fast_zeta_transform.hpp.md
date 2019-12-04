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


# :warning: utils/fast_zeta_transform.hpp
* category: utils


[Back to top page](../../index.html)

* upward fast zeta transform on primes


## Dependencies
* :heavy_check_mark: [number/primes.hpp](../number/primes.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](macros.hpp.html)


## Code
```cpp
#pragma once
#include <cassert>
#include <vector>
#include "number/primes.hpp"
#include "utils/macros.hpp"

/**
 * @brief upward fast zeta transform on primes
 * @note $O(n \log n)$ (or, $O(n \log \log n)$ ???)
 * @return $b_i = \sum _ {i \mid j} a_j$
 * @note $a_0, b_0$ means the greatest element
 */
template <class CommutativeSemiring>
std::vector<typename CommutativeSemiring::value_type> upward_fast_zeta_transform_on_primes(std::vector<typename CommutativeSemiring::value_type> a, const prepared_primes & primes, const CommutativeSemiring & mon = CommutativeSemiring()) {
    assert (a.size() <= primes.size);
    if (a.empty()) return a;
    for (int64_t p : primes.primes) {
        REP3R (x, 1, (a.size() - 1) / p + 1) {
            a[x] = mon.mult(a[x], a[p * x]);
        }
    }
    REP3 (x, 1, a.size()) {
        a[x] = mon.mult(a[x], a[0]);
    }
    return a;
}

```

[Back to top page](../../index.html)

