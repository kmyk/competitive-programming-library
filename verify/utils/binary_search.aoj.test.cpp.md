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


# :heavy_check_mark: utils/binary_search.aoj.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/utils/binary_search.aoj.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/utils/binary_search.hpp.html">a binary search / 二分探索 <small>(utils/binary_search.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B"
#include "utils/binary_search.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> s(n);
    REP (i, n) {
        cin >> s[i];
    }

    int q; cin >> q;
    int64_t cnt = 0;
    while (q --) {
        int t_i; cin >> t_i;
        int l = binsearch(0, n, [&](int i) {
            return s[i] >= t_i;
        });
        cnt += (l < n and s[l] == t_i);

        int r = binsearch_max(0, n, [&](int i) {
            return s[i] <= t_i;
        });
        assert ((l < n and s[l] == t_i) == (l <= r));
    }

    cout << cnt << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/binary_search.aoj.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B"
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
#line 3 "utils/binary_search.aoj.test.cpp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 9 "utils/binary_search.aoj.test.cpp"
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> s(n);
    REP (i, n) {
        cin >> s[i];
    }

    int q; cin >> q;
    int64_t cnt = 0;
    while (q --) {
        int t_i; cin >> t_i;
        int l = binsearch(0, n, [&](int i) {
            return s[i] >= t_i;
        });
        cnt += (l < n and s[l] == t_i);

        int r = binsearch_max(0, n, [&](int i) {
            return s[i] <= t_i;
        });
        assert ((l < n and s[l] == t_i) == (l <= r));
    }

    cout << cnt << endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

