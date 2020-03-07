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


# VerificationStatus.VERIFIED string/longest_common_prefix.yosupo.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/longest_common_prefix.yosupo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 19:51:45+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/sparse_table.hpp.html">Sparse Table (idempotent monoid) <small>(data_structure/sparse_table.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/hack/fastio.hpp.html">hack/fastio.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/min.hpp.html">monoids/min.hpp</a>
* :heavy_check_mark: <a href="../../library/string/longest_common_prefix.hpp.html">Longest Common Prefix / 最長共通接頭辞 (接尾辞配列, 前処理 $O(N (\log N)^2)$ + $O(1)$) <small>(string/longest_common_prefix.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/string/suffix_array.hpp.html">Suffix Array / 接尾辞配列 ($O(N (\log N)^2)$, Manber & Myers) <small>(string/suffix_array.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "string/longest_common_prefix.hpp"
#include "hack/fastio.hpp"

int main() {
    std::string s = in<std::string>();
    int n = s.length();
    longest_common_prefix lcp(s);
    REP (i, n) {
        out<int>(lcp.get(0, i));
        out<char>(i < n - 1 ? ' ' : '\n');
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/longest_common_prefix.yosupo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#line 2 "string/longest_common_prefix.hpp"
#include <algorithm>
#include <string>
#include <vector>
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
#line 2 "data_structure/sparse_table.hpp"
#include <cassert>
#line 5 "data_structure/sparse_table.hpp"

/**
 * @brief Sparse Table (idempotent monoid)
 * @note the unit is required just for convenience
 * @note $O(N \log N)$ space
 */
template <class IdempotentMonoid>
struct sparse_table {
    typedef typename IdempotentMonoid::value_type value_type;
    std::vector<std::vector<value_type> > table;
    IdempotentMonoid mon;
    sparse_table() = default;

    /**
     * @note $O(N \log N)$ time
     */
    template <class InputIterator>
    sparse_table(InputIterator first, InputIterator last, const IdempotentMonoid & mon_ = IdempotentMonoid())
            : mon(mon_) {
        table.emplace_back(first, last);
        int n = table[0].size();
        int log_n = 32 - __builtin_clz(n);
        table.resize(log_n, std::vector<value_type>(n));
        REP (k, log_n - 1) {
            REP (i, n) {
                table[k + 1][i] = i + (1ll << k) < n ?
                    mon.mult(table[k][i], table[k][i + (1ll << k)]) :
                    table[k][i];
            }
        }
    }

    /**
     * @note $O(1)$
     */
    value_type range_get(int l, int r) const {
        if (l == r) return mon.unit();  // if there is no unit, remove this line
        assert (0 <= l and l < r and r <= (int)table[0].size());
        int k = 31 - __builtin_clz(r - l);  // log2
        return mon.mult(table[k][l], table[k][r - (1ll << k)]);
    }
};
#line 3 "monoids/min.hpp"
#include <limits>

template <class T>
struct min_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::max(); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};
#line 8 "string/longest_common_prefix.hpp"

/**
 * @brief Longest Common Prefix / 最長共通接頭辞 (接尾辞配列, 前処理 $O(N (\log N)^2)$ + $O(1)$)
 */
class longest_common_prefix {
    std::vector<int> rank;
    sparse_table<min_monoid<int> > table;

    void initialize(const std::string & s, const std::vector<int> & sa) {
        int n = s.length();
        std::vector<int> lcp(n, -1);  // lcp[i] is the length of the common prefix between i-th and (i+1)-th substring of s
        int h = 0;
        lcp[0] = 0;
        REP (i, n) {
            int j = sa[rank[i] - 1];
            if (h > 0) -- h;
            while (j + h < n and i + h < n and s[j + h] == s[i + h]) ++ h;
            lcp[rank[i] - 1] = h;
        }
        table = sparse_table<min_monoid<int> >(ALL(lcp));
    }

public:
    longest_common_prefix(const std::string & s) {
        std::vector<int> sa;
        compute_suffix_array(s, sa, rank);
        initialize(s, sa);
    }
    longest_common_prefix(const std::string & s, const std::vector<int> & sa, const std::vector<int> & rank_)
            : rank(rank_) {
        initialize(s, sa);
    }

    int get(int i, int j) const {
        int l = rank[i];
        int r = rank[j];
        if (l > r) std::swap(l, r);
        int n = rank.size() - 1;
        return std::min(n, table.range_get(l, r));
    }
};
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
#line 4 "string/longest_common_prefix.yosupo.test.cpp"

int main() {
    std::string s = in<std::string>();
    int n = s.length();
    longest_common_prefix lcp(s);
    REP (i, n) {
        out<int>(lcp.get(0, i));
        out<char>(i < n - 1 ? ' ' : '\n');
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

