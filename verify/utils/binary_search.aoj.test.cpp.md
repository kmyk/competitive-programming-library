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
    - Last commit date: 2019-11-09 09:23:07 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B</a>


## Depends On
* :heavy_check_mark: <a href="../../library/utils/binary_search.hpp.html">a flexible binary search</a>
* :warning: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code
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

<a href="../../index.html">Back to top page</a>

