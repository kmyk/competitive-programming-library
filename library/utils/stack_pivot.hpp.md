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


# :warning: utils/stack_pivot.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/stack_pivot.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 10:10:20+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdlib>

/**
 * @note use as int main() { STACK_PIVOT main_(); exit(EXIT_SUCCESS); }
 */
#define STACK_PIVOT \
    size_t stack_size = 1 << 26; \
    char *malloced = (char *)malloc(stack_size); \
    char *addr = malloced + stack_size - sizeof(int); \
    __asm__("mov %0, %%rsp;" : "=g" (addr) );

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/stack_pivot.hpp"
#include <cstdlib>

/**
 * @note use as int main() { STACK_PIVOT main_(); exit(EXIT_SUCCESS); }
 */
#define STACK_PIVOT \
    size_t stack_size = 1 << 26; \
    char *malloced = (char *)malloc(stack_size); \
    char *addr = malloced + stack_size - sizeof(int); \
    __asm__("mov %0, %%rsp;" : "=g" (addr) );

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

