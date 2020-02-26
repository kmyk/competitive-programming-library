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


# :warning: hack/fastio_scanner.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d78b6f30225cdc811adfe8d4e7c9fd34">hack</a>
* <a href="{{ site.github.repository_url }}/blob/master/hack/fastio_scanner.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <type_traits>
#include <unistd.h>

class scanner {
    static constexpr int N = 65536;
    static constexpr int K = 64;
    char buf[K + N];
    int l = 0;
    int r = 0;
    void flush() {
        if (K < r - l) return;
        memmove(buf + K - (r - l), buf + l, r - l);
        l = K - (r - l);
        r = K + read(STDIN_FILENO, buf + K, N);
        assert (l < r);
    }
    void prepare() {
        flush();
        while (isspace(buf[l])) {
            ++ l;
            flush();
        }
    }
public:
    scanner() = default;
    scanner(const scanner &) = delete;
    scanner & operator = (const scanner &) = delete;
    template <class Char, std::enable_if_t<std::is_same<Char, char>::value, int> = 0>
    inline char get() {
        prepare();
        return buf[l ++];
    }
    template <class String, std::enable_if_t<std::is_same<String, std::string>::value, int> = 0>
    std::string get() {
        prepare();
        std::string s;
        do {
            s.push_back(buf[l ++]);
            if (r == l) flush();
        } while (not isspace(buf[l]));
        return s;
    }
    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    Integer get() {
        prepare();
        bool is_negative = false;
        if (std::is_signed<Integer>::value and buf[l] == '-') {
            is_negative = true;
            ++ l;
        }
        Integer x = 0;
        while (l < r and isdigit(buf[l])) {
            x *= 10;
            x += buf[l] - '0';
            ++ l;
        }
        if (std::is_signed<Integer>::value and is_negative) {
            x *= -1;
        }
        return x;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "hack/fastio_scanner.hpp"
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <type_traits>
#include <unistd.h>

class scanner {
    static constexpr int N = 65536;
    static constexpr int K = 64;
    char buf[K + N];
    int l = 0;
    int r = 0;
    void flush() {
        if (K < r - l) return;
        memmove(buf + K - (r - l), buf + l, r - l);
        l = K - (r - l);
        r = K + read(STDIN_FILENO, buf + K, N);
        assert (l < r);
    }
    void prepare() {
        flush();
        while (isspace(buf[l])) {
            ++ l;
            flush();
        }
    }
public:
    scanner() = default;
    scanner(const scanner &) = delete;
    scanner & operator = (const scanner &) = delete;
    template <class Char, std::enable_if_t<std::is_same<Char, char>::value, int> = 0>
    inline char get() {
        prepare();
        return buf[l ++];
    }
    template <class String, std::enable_if_t<std::is_same<String, std::string>::value, int> = 0>
    std::string get() {
        prepare();
        std::string s;
        do {
            s.push_back(buf[l ++]);
            if (r == l) flush();
        } while (not isspace(buf[l]));
        return s;
    }
    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    Integer get() {
        prepare();
        bool is_negative = false;
        if (std::is_signed<Integer>::value and buf[l] == '-') {
            is_negative = true;
            ++ l;
        }
        Integer x = 0;
        while (l < r and isdigit(buf[l])) {
            x *= 10;
            x += buf[l] - '0';
            ++ l;
        }
        if (std::is_signed<Integer>::value and is_negative) {
            x *= -1;
        }
        return x;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
