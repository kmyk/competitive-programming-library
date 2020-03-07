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


# VerificationStatus.VERIFIED hack/fastio.yosupo.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d78b6f30225cdc811adfe8d4e7c9fd34">hack</a>
* <a href="{{ site.github.repository_url }}/blob/master/hack/fastio.yosupo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 16:22:43+09:00


* see: <a href="https://judge.yosupo.jp/problem/many_aplusb">https://judge.yosupo.jp/problem/many_aplusb</a>


## Depends on

* :heavy_check_mark: <a href="../../library/hack/fastio.hpp.html">hack/fastio.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "hack/fastio.hpp"

int main() {
    int t = in<int>();
    while (t --) {
        uint64_t a = in<uint64_t>();
        uint64_t b = in<uint64_t>();
        out<uint64_t>(a + b);
        out<char>('\n');
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "hack/fastio.yosupo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#line 2 "hack/fastio.hpp"
#include <cstdint>
#include <cstdio>
#include <string>
#include <type_traits>

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline Char in() { return getchar_unlocked(); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline std::string in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    std::string s;
    do { s.push_back(c); } while (not isspace(c = getchar_unlocked()));
    return s;
}
template <class Integer, std::enable_if_t<std::is_integral_v<Integer>, int> = 0>
inline Integer in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    if (std::is_signed<Integer>::value and c == '-') return -in<Integer>();
    Integer n = 0;
    do { n = n * 10 + c - '0'; } while (not isspace(c = getchar_unlocked()));
    return n;
}

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline void out(char c) { putchar_unlocked(c); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline void out(const std::string & s) { for (char c : s) putchar_unlocked(c); }
template <class Integer, std::enable_if_t<std::is_integral_v<Integer>, int> = 0>
inline void out(Integer n) {
    char s[20];
    int i = 0;
    if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *= -1; }
    do { s[i ++] = n % 10; n /= 10; } while (n);
    while (i) putchar_unlocked(s[-- i] + '0');
}
#line 3 "hack/fastio.yosupo.test.cpp"

int main() {
    int t = in<int>();
    while (t --) {
        uint64_t a = in<uint64_t>();
        uint64_t b = in<uint64_t>();
        out<uint64_t>(a + b);
        out<char>('\n');
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

