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


# :warning: utils/dlopen.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/dlopen.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-06-28 15:20:11 +0900




## Code

{% raw %}
```cpp
extern "C" {
#if defined(_WIN32)
void *__libc_dlopen_mode(const char *, int);
void *__libc_dlsym(void *, const char *);
#else
void* __stdcall LoadLibraryA(const char *);
void* __stdcall GetProcAddress(void *, const char *);
#endif
}
struct dynamic_library {
    void *handle;
    dynamic_library() : handle(nullptr) {}
    dynamic_library(string const & path) { handle = nullptr; try_open(path); }
    void try_open(string const & path) {
        if (not handle) {
#if defined(_WIN32)
            handle = LoadLibraryA(path.c_str());
#else
            int rtld_now = 2;
            handle = __libc_dlopen_mode(path.c_str(), rtld_now);
#endif
        }
    }
    void *operator () (string const & symbol) {
#if defined(_WIN32)
        return GetProcAddress(handle, symbol.c_str());
#else
        return __libc_dlsym(handle, symbol.c_str());
#endif
    }
};

dynamic_library libpthread = dynamic_library()
    .try_open("/lib/x86_64-linux-gnu/libpthread.so.0") // atcoder
    .try_open("/usr/lib64/libpthread.so.0"); // yukicoder
extern "C" {
int pthread_create (pthread_t *__restrict __newthread,
        const pthread_attr_t *__restrict __attr,
        void *(*__start_routine) (void *),
        void *__restrict __arg) {
    typedef decltype(pthread_create) (*type);
    static type ptr = (type)(libpthread("pthread_create"));
    return ptr(__newthread, __attr, __start_routine, __arg);
}
void pthread_exit (void *__retval) {
    typedef decltype(pthread_exit) (*type);
    static type ptr = (type)(libpthread("pthread_exit"));
    ptr(__retval);
}
int pthread_join (pthread_t __th, void **__thread_return) {
    typedef decltype(pthread_join) (*type);
    static type ptr = (type)(libpthread("pthread_join"));
    return ptr(__th, __thread_return);
}
int pthread_detach (pthread_t __th) {
    typedef decltype(pthread_detach) (*type);
    static type ptr = (type)(libpthread("pthread_detach"));
    return ptr(__th);
}
}

#include <gmp.h>
#define EXPAND_MACRO_TO_STR_2(a) #a
#define EXPAND_MACRO_TO_STR(a) EXPAND_MACRO_TO_STR_2(a)
dynamic_library libgmp = dynamic_library()
    .try_open("/usr/lib/x86_64-linux-gnu/libgmp.so.10") // atcoder
    .try_open("/usr/lib64/libgmp.so.10") // yukicoder
    .try_open("mpir.dll");
#define D(name) const auto my_##name = (decltype(::name) *)libgmp(EXPAND_MACRO_TO_STR(name))
D(mpz_init_set_str)
D(mpz_probab_prime_p)
#undef D

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

