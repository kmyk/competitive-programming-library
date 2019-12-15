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


# :heavy_check_mark: number/primes.aoj.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/number/primes.aoj.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-09 09:39:14 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../library/number/primes.hpp.html">number/primes.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "number/primes.hpp"
#include <cassert>
#include <iostream>

int main() {
    int n; std::cin >> n;
    prepared_primes primes(1e6 + 3);
    int cnt = 0;
    REP (i, n) {
        int a; std::cin >> a;
        cnt += primes.is_prime(a);
    }
    std::cout << cnt << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

