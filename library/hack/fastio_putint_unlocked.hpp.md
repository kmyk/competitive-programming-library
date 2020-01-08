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


# :warning: hack/fastio_putint_unlocked.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d78b6f30225cdc811adfe8d4e7c9fd34">hack</a>
* <a href="{{ site.github.repository_url }}/blob/master/hack/fastio_putint_unlocked.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include <cstdio>

inline void putint_unlocked(int64_t n) {
    char s[20];
    int i = 0;
    if (n < 0) { putchar_unlocked('-'); n *= -1; }
    do { s[i ++] = n % 10; n /= 10; } while (n);
    while (i) putchar_unlocked(s[-- i] + '0');
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "hack/fastio_putint_unlocked.hpp"
#include <cstdint>
#include <cstdio>

inline void putint_unlocked(int64_t n) {
    char s[20];
    int i = 0;
    if (n < 0) { putchar_unlocked('-'); n *= -1; }
    do { s[i ++] = n % 10; n /= 10; } while (n);
    while (i) putchar_unlocked(s[-- i] + '0');
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

