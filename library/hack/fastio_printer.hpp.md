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


# :heavy_check_mark: hack/fastio_printer.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d78b6f30225cdc811adfe8d4e7c9fd34">hack</a>
* <a href="{{ site.github.repository_url }}/blob/master/hack/fastio_printer.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 16:58:19+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/hack/fastio_scanner_and_printer.yosupo.test.cpp.html">hack/fastio_scanner_and_printer.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <type_traits>
#include <unistd.h>

class printer {
    static constexpr int N = 131072;
    static constexpr int K = 64;
    char buf[N];
    int i = 0;
    inline void flush() {
        write(STDOUT_FILENO, buf, i);
        i = 0;
    }
public:
    printer() = default;
    printer(const printer &) = delete;
    printer & operator = (const printer &) = delete;
    ~printer() {
        flush();
    }
    template <class Char, std::enable_if_t<std::is_same<Char, char>::value, int> = 0>
    inline void put(char c) {
        if (i == N) flush();
        buf[i ++] = c;
    }
    template <class String, std::enable_if_t<std::is_same<String, std::string>::value, int> = 0>
    void put(const std::string & s) {
        for (int l = 0; l < (int)s.length(); ) {
            if (i == N) flush();
            int r = std::min<int>(s.length(), l + (N - i));
            memcpy(buf + i, s.data() + l, r - l);
            i += r - l;
            l = r;
        }
    }
    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    void put(Integer x) {
        if (N - i < K) flush();
        if (std::is_signed<Integer>::value and x < 0) {
            x *= -1;
            buf[i ++] = '-';
        }
        if (x == 0) {
            buf[i ++] = '0';
            return;
        }
        char s[K];
        int j = 0;
        while (x) {
            s[j ++] = x % 10 + '0';
            x /= 10;
        }
        while (j) {
            buf[i ++] = s[-- j];
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "hack/fastio_printer.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <type_traits>
#include <unistd.h>

class printer {
    static constexpr int N = 131072;
    static constexpr int K = 64;
    char buf[N];
    int i = 0;
    inline void flush() {
        write(STDOUT_FILENO, buf, i);
        i = 0;
    }
public:
    printer() = default;
    printer(const printer &) = delete;
    printer & operator = (const printer &) = delete;
    ~printer() {
        flush();
    }
    template <class Char, std::enable_if_t<std::is_same<Char, char>::value, int> = 0>
    inline void put(char c) {
        if (i == N) flush();
        buf[i ++] = c;
    }
    template <class String, std::enable_if_t<std::is_same<String, std::string>::value, int> = 0>
    void put(const std::string & s) {
        for (int l = 0; l < (int)s.length(); ) {
            if (i == N) flush();
            int r = std::min<int>(s.length(), l + (N - i));
            memcpy(buf + i, s.data() + l, r - l);
            i += r - l;
            l = r;
        }
    }
    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    void put(Integer x) {
        if (N - i < K) flush();
        if (std::is_signed<Integer>::value and x < 0) {
            x *= -1;
            buf[i ++] = '-';
        }
        if (x == 0) {
            buf[i ++] = '0';
            return;
        }
        char s[K];
        int j = 0;
        while (x) {
            s[j ++] = x % 10 + '0';
            x /= 10;
        }
        while (j) {
            buf[i ++] = s[-- j];
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

