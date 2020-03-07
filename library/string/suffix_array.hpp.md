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


# VerificationStatus.VERIFIED Suffix Array / 接尾辞配列 ($O(N (\log N)^2)$, Manber & Myers) <small>(string/suffix_array.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/suffix_array.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 13:12:45+09:00




## Depends on

* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Required by

* :heavy_check_mark: <a href="longest_common_prefix.hpp.html">Longest Common Prefix / 最長共通接頭辞 (接尾辞配列, 前処理 $O(N (\log N)^2)$ + $O(1)$) <small>(string/longest_common_prefix.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/string/longest_common_prefix.yosupo.test.cpp.html">string/longest_common_prefix.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/string/suffix_array.yosupo.test.cpp.html">string/suffix_array.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include "utils/macros.hpp"

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/suffix_array.hpp"
#include <algorithm>
#include <string>
#include <vector>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

