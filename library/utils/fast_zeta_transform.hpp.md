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


# :warning: upward fast zeta transform on primes <small>(utils/fast_zeta_transform.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/fast_zeta_transform.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00




## Depends on

* :heavy_check_mark: <a href="../number/primes.hpp.html">number/primes.hpp</a>
* :warning: <a href="macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
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
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/fast_zeta_transform.hpp"
#include <cassert>
#include <vector>
#line 2 "number/primes.hpp"
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <map>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 8 "number/primes.hpp"

/**
 * @note O(\sqrt{n})
 */
struct prepared_primes {
    int size;
    std::vector<int> sieve;
    std::vector<int> primes;

    prepared_primes(int size_)
        : size(size_) {

        sieve.resize(size);
        REP3 (p, 2, size) if (sieve[p] == 0) {
            primes.push_back(p);
            for (int k = p; k < size; k += p) {
                if (sieve[k] == 0) {
                    sieve[k] = p;
                }
            }
        }
    }

    std::vector<int64_t> list_prime_factors(int64_t n) {
        assert (1 <= n and n < (int64_t)size * size);
        std::vector<int64_t> result;

        // trial division for large part
        for (int p : primes) {
            if (n < size or n < (int64_t)p * p) {
                break;
            }
            while (n % p == 0) {
                n /= p;
                result.push_back(p);
            }
        }

        // small part
        if (n == 1) {
            // nop
        } else if (n < size) {
            while (n != 1) {
                result.push_back(sieve[n]);
                n /= sieve[n];
            }
        } else {
            result.push_back(n);
        }

        assert (std::is_sorted(ALL(result)));
        return result;
    }

    bool is_prime(int64_t n) {
        return list_prime_factors(n).size() == 1;
    }

    std::vector<int64_t> list_all_factors(int64_t n) {
        auto p = list_prime_factors(n);
        std::vector<int64_t> d;
        d.push_back(1);
        for (int l = 0; l < p.size(); ) {
            int r = l + 1;
            while (r < p.size() and p[r] == p[l]) ++ r;
            int n = d.size();
            REP (k1, r - l) {
                REP (k2, n) {
                    d.push_back(d[d.size() - n] * p[l]);
                }
            }
            l = r;
        }
        return d;
    }

    std::map<int64_t, int> list_prime_factors_as_map(int64_t n) {
        std::map<int64_t, int> cnt;
        for (int64_t p : list_prime_factors(n)) {
            ++ cnt[p];
        }
        return cnt;
    }

    int64_t euler_totient(int64_t n) {
        int64_t phi = 1;
        int64_t last = -1;
        for (int64_t p : list_prime_factors(n)) {
            if (last != p) {
                last = p;
                phi *= p - 1;
            } else {
                phi *= p;
            }
        }
        return phi;
    }
};
#line 6 "utils/fast_zeta_transform.hpp"

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
{% endraw %}

<a href="../../index.html">Back to top page</a>

