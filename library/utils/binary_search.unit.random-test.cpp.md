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


# :warning: utils/binary_search.unit.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/binary_search.unit.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24 +0900




## Depends on

* :heavy_check_mark: <a href="binary_search.hpp.html">a binary search / 二分探索 <small>(utils/binary_search.hpp)</small></a>
* :heavy_check_mark: <a href="macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "utils/binary_search.hpp"

#include <cassert>
#include <initializer_list>
#include "utils/macros.hpp"

int main() {
    // binsearch()
    for (int l : { 0, 1, 2, 3 }) {
        for (int r : { 8, 9, 10, 11 }) {
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return true;   }) == l);
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return false;  }) == r);
            REP3 (i, l, r + 1) {
                assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return n >= i; }) == i);
            }
        }
    }

    // binsearch_max
    for (int l : { 0, 1, 2, 3 }) {
        for (int r : { 8, 9, 10, 11 }) {
            assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return false; }) == l);
            assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return true;  }) == r);
            REP3 (i, l, r + 1) {
                assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return n <= i; }) == i);
            }
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/binary_search.hpp"
#include <cassert>
#include <cstdint>

/**
 * @brief a binary search / 二分探索
 * @param[in] p  a monotone predicate defined on $[l, r)$
 * @return $\min \lbrace x \in [l, r) \mid p(x) \rbrace$, or r if it doesn't exist
 */
template <typename UnaryPredicate>
int64_t binsearch(int64_t l, int64_t r, UnaryPredicate p) {
    assert (l <= r);
    -- l;
    while (r - l > 1) {
        int64_t m = l + (r - l) / 2;
        (p(m) ? r : l) = m;
    }
    return r;
}

/**
 * @return $\max \lbrace x \in (l, r] \mid p(x) \rbrace$, or l if it doesn't exist
 */
template <typename UnaryPredicate>
int64_t binsearch_max(int64_t l, int64_t r, UnaryPredicate p) {
    assert (l <= r);
    ++ r;
    while (r - l > 1) {
        int64_t m = l + (r - l) / 2;
        (p(m) ? l : r) = m;
    }
    return l;
}
#line 2 "utils/binary_search.unit.random-test.cpp"

#include <cassert>
#include <initializer_list>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 6 "utils/binary_search.unit.random-test.cpp"

int main() {
    // binsearch()
    for (int l : { 0, 1, 2, 3 }) {
        for (int r : { 8, 9, 10, 11 }) {
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return true;   }) == l);
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return false;  }) == r);
            REP3 (i, l, r + 1) {
                assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return n >= i; }) == i);
            }
        }
    }

    // binsearch_max
    for (int l : { 0, 1, 2, 3 }) {
        for (int r : { 8, 9, 10, 11 }) {
            assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return false; }) == l);
            assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return true;  }) == r);
            REP3 (i, l, r + 1) {
                assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return n <= i; }) == i);
            }
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

