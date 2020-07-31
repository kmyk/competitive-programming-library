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


# :heavy_check_mark: number/primes.yukicoder-1140.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/primes.yukicoder-1140.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-01 00:51:48+09:00


* see: <a href="https://yukicoder.me/problems/no/1140">https://yukicoder.me/problems/no/1140</a>


## Depends on

* :heavy_check_mark: <a href="../../library/number/primes.hpp.html">number/primes.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1140"
#include <cstdio>
#include "utils/macros.hpp"
#include "number/primes.hpp"

prepared_primes primes(1e6 + 100);

int solve(long long a, int p) {
    if (not primes.is_prime(p)) return -1;
    if (a % p == 0) return 0;
    return 1;
}

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        long long a; int p; scanf("%lld%d", &a, &p);
        auto ans = solve(a, p);
        printf("%d\n", ans);
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "number/primes.yukicoder-1140.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1140"
#include <cstdio>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 2 "number/primes.hpp"
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <map>
#include <vector>
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

    /**
     * @note O(1) if n < size; O(sqrt n) if size <= n < size^2
     */
    bool is_prime(int64_t n) {
        assert (1 <= n and n < (int64_t)size * size);
        if (n < size) {
            return sieve[n] == n;
        }
        for (int p : primes) {
            if (n < (int64_t)p * p) {
                break;
            }
            if (n % p == 0) {
                return false;
            }
        }
        return true;
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
#line 5 "number/primes.yukicoder-1140.test.cpp"

prepared_primes primes(1e6 + 100);

int solve(long long a, int p) {
    if (not primes.is_prime(p)) return -1;
    if (a % p == 0) return 0;
    return 1;
}

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        long long a; int p; scanf("%lld%d", &a, &p);
        auto ans = solve(a, p);
        printf("%d\n", ans);
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

