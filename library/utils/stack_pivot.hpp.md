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


# :heavy_check_mark: utils/stack_pivot.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/stack_pivot.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 14:14:37+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/graph/lowest_common_ancestor.yosupo.test.cpp.html">graph/lowest_common_ancestor.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/utils/dsu_on_tree.aoj.test.cpp.html">utils/dsu_on_tree.aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdlib>

/**
 * @note This is a workaround for WSL. We cannot use ulimit -s unlimited on the environment.
 * @note To use such techniques, you should take care of the alignment of rsp. If not, you'll get SIGSEGV around XMM registers.
 */

#define BEGIN_STACK_PIVOT(STACK_SIZE) \
    static volatile char *old_stack; \
    asm volatile("mov %%rsp, %0" : "=r" (old_stack) ); \
    char *new_stack = ((char *)malloc(STACK_SIZE) + (STACK_SIZE) - 0x10); \
    asm volatile("mov %0, %%rsp" : : "r" (new_stack) );

#define END_STACK_PIVOT() \
    asm volatile("mov %0, %%rsp" : : "r" (old_stack) );

#define STACK_PIVOT_MAIN(moin) \
    int main() { \
        BEGIN_STACK_PIVOT(1 << 28) \
        static int returncode = moin(); \
        END_STACK_PIVOT() \
        return returncode; \
    }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/stack_pivot.hpp"
#include <cstdlib>

/**
 * @note This is a workaround for WSL. We cannot use ulimit -s unlimited on the environment.
 * @note To use such techniques, you should take care of the alignment of rsp. If not, you'll get SIGSEGV around XMM registers.
 */

#define BEGIN_STACK_PIVOT(STACK_SIZE) \
    static volatile char *old_stack; \
    asm volatile("mov %%rsp, %0" : "=r" (old_stack) ); \
    char *new_stack = ((char *)malloc(STACK_SIZE) + (STACK_SIZE) - 0x10); \
    asm volatile("mov %0, %%rsp" : : "r" (new_stack) );

#define END_STACK_PIVOT() \
    asm volatile("mov %0, %%rsp" : : "r" (old_stack) );

#define STACK_PIVOT_MAIN(moin) \
    int main() { \
        BEGIN_STACK_PIVOT(1 << 28) \
        static int returncode = moin(); \
        END_STACK_PIVOT() \
        return returncode; \
    }

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

