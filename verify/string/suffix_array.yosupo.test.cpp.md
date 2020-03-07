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


# :heavy_check_mark: string/suffix_array.yosupo.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/string/suffix_array.yosupo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 19:51:45+09:00


* see: <a href="https://judge.yosupo.jp/problem/suffixarray">https://judge.yosupo.jp/problem/suffixarray</a>


## Depends on

* :heavy_check_mark: <a href="../../library/hack/fastio.hpp.html">hack/fastio.hpp</a>
* :heavy_check_mark: <a href="../../library/string/suffix_array.hpp.html">Suffix Array / 接尾辞配列 ($O(N (\log N)^2)$, Manber & Myers) <small>(string/suffix_array.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <cassert>
#include <string>
#include <vector>
#include "string/suffix_array.hpp"
#include "hack/fastio.hpp"
using namespace std;

int main() {
    // input
    string s = in<string>();
    int n = s.length();

    // solve
    vector<int> sa, rank;
    compute_suffix_array(s, sa, rank);
    assert ((int)sa.size() == n + 1);
    assert (sa[0] == n);

    // output
    REP (i, n) {
        out<int>(sa[i + 1]);
        out<char>(i < n - 1 ? ' ' : '\n');
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/suffix_array.yosupo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <cassert>
#include <string>
#include <vector>
#line 2 "string/suffix_array.hpp"
#include <algorithm>
#line 5 "string/suffix_array.hpp"
#include <utility>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 7 "string/suffix_array.hpp"

/**
 * @brief Suffix Array / 接尾辞配列 ($O(N (\log N)^2)$, Manber & Myers)
 * @arg sa[i] is the index of i-th smallest substring of s, s[sa[i], N)
 * @arg rank[i] is the rank of substring s[i, N)
 * @note 蟻本より
 */
void compute_suffix_array(std::string const & s, std::vector<int> & sa, std::vector<int> & rank) {
    int n = s.length();
    sa.resize(n + 1);
    rank.resize(n + 1);
    REP (i, n + 1) {
        sa[i] = i;
        rank[i] = i < n ? s[i] : -1;
    }
    auto rankf = [&](int i) {
        return i <= n ? rank[i] : -1;
    };
    std::vector<int> nxt(n + 1);
    for (int k = 1; k <= n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            return std::make_pair(rank[i], rankf(i + k)) < std::make_pair(rank[j], rankf(j + k));
        };
        std::sort(sa.begin(), sa.end(), cmp);
        nxt[sa[0]] = 0;
        REP3 (i, 1, n + 1) {
            nxt[sa[i]] = nxt[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        rank.swap(nxt);
    }
}
#line 2 "hack/fastio.hpp"
#include <cstdint>
#include <cstdio>
#line 5 "hack/fastio.hpp"
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
#line 7 "string/suffix_array.yosupo.test.cpp"
using namespace std;

int main() {
    // input
    string s = in<string>();
    int n = s.length();

    // solve
    vector<int> sa, rank;
    compute_suffix_array(s, sa, rank);
    assert ((int)sa.size() == n + 1);
    assert (sa[0] == n);

    // output
    REP (i, n) {
        out<int>(sa[i + 1]);
        out<char>(i < n - 1 ? ' ' : '\n');
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

