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


# :heavy_check_mark: modulus/twelvefold_way.balls_and_boxes_1.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/twelvefold_way.balls_and_boxes_1.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 12:57:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/modulus/bell_number.hpp.html">the Bell number (前処理 $O(NK)$ + $O(1)$) <small>(modulus/bell_number.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/choose.hpp.html">combination / 組合せ ${} _ n C _ r$ (前処理 $O(n)$ + $O(1)$) <small>(modulus/choose.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/factorial.hpp.html">modulus/factorial.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/multichoose.hpp.html">重複組合せ ${} _ n H _ r = {} _ {n + r - 1} C _ r$ (前処理 $O(n)$ + $O(1)$) <small>(modulus/multichoose.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/permute.hpp.html">permutation / 順列 ${} _ n P _ r$ (前処理 $O(n)$ + $O(1)$) <small>(modulus/permute.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/stirling_number_of_the_second_kind_direct.hpp.html">the Stirling number of the second kind ($O(K \log N)$) <small>(modulus/stirling_number_of_the_second_kind_direct.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/stirling_number_of_the_second_kind_table.hpp.html">the Stirling number of the second kind (前処理 $O(NK)$ + $O(1)$) <small>(modulus/stirling_number_of_the_second_kind_table.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/twelvefold_way.hpp.html">twelvefold way / 写像12相 <small>(modulus/twelvefold_way.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"
#include <iostream>
#include "modulus/twelvefold_way.hpp"
using namespace std;

constexpr int MOD = 1e9 + 7;
int main() {
    int n, k; cin >> n >> k;
    cout << twelvefold_lla<MOD>(n, k) << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "modulus/twelvefold_way.balls_and_boxes_1.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"
#include <iostream>
#line 2 "modulus/mint.hpp"
#include <algorithm>
#include <cassert>
#line 3 "modulus/modpow.hpp"

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}
#line 4 "modulus/modinv.hpp"

inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    if (value == 0) return -1;
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    if (not (value * x + MOD * y == b and b == 1)) return -1;
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

inline int32_t modinv(int32_t x, int32_t MOD) {
    int32_t y = modinv_nocheck(x, MOD);
    assert (y != -1);
    return y;
}
#line 7 "modulus/mint.hpp"


/**
 * @brief quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$
 */
template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline constexpr mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline constexpr mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline constexpr mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline constexpr mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline constexpr mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline constexpr mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline constexpr mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline constexpr mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline constexpr mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline constexpr mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline constexpr bool operator == (mint<MOD> other) const { return value == other.value; }
    inline constexpr bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }
#line 2 "modulus/factorial.hpp"
#include <vector>
#line 4 "modulus/factorial.hpp"

template <int32_t MOD>
mint<MOD> fact(int n) {
    static std::vector<mint<MOD> > memo(1, 1);
    while (n >= memo.size()) {
        memo.push_back(memo.back() * mint<MOD>(memo.size()));
    }
    return memo[n];
}
template <int32_t MOD>
mint<MOD> inv_fact(int n) {
    static std::vector<mint<MOD> > memo;
    if (memo.size() <= n) {
        int l = memo.size();
        int r = n * 1.3 + 100;
        memo.resize(r);
        memo[r - 1] = fact<MOD>(r - 1).inv();
        for (int i = r - 2; i >= l; -- i) {
            memo[i] = memo[i + 1] * (i + 1);
        }
    }
    return memo[n];
}
#line 5 "modulus/choose.hpp"

/**
 * @brief combination / 組合せ ${} _ n C _ r$ (前処理 $O(n)$ + $O(1)$)
 */
template <int32_t MOD>
mint<MOD> choose(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) * inv_fact<MOD>(n - r) * inv_fact<MOD>(r);
}
#line 5 "modulus/permute.hpp"

/**
 * @brief permutation / 順列 ${} _ n P _ r$ (前処理 $O(n)$ + $O(1)$)
 */
template <int32_t MOD>
mint<MOD> permute(int n, int r) {
    assert (0 <= r and r <= n);
    return fact<MOD>(n) * inv_fact<MOD>(n - r);
}
#line 5 "modulus/multichoose.hpp"

/**
 * @brief 重複組合せ ${} _ n H _ r = {} _ {n + r - 1} C _ r$ (前処理 $O(n)$ + $O(1)$)
 */
template <int32_t MOD>
mint<MOD> multichoose(int n, int r) {
    assert (0 <= n and 0 <= r);
    if (n == 0 and r == 0) return 1;
    return choose<MOD>(n + r - 1, r);
}
#line 4 "modulus/stirling_number_of_the_second_kind_direct.hpp"
#include <map>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 9 "modulus/stirling_number_of_the_second_kind_direct.hpp"

/**
 * @brief the Stirling number of the second kind ($O(K \log N)$)
 */
template <int MOD>
mint<MOD> stirling_number_of_the_second_kind_direct(int n, int k) {
    assert (0 <= n and 0 <= k);
    mint<MOD> acc = 0;
    REP (i, k + 1) {
        int parity = ((k - i) % 2 == 0 ? +1 : -1);
        acc += choose<MOD>(k, i) * mint<MOD>(i).pow(n) * parity;
    }
    return acc * inv_fact<MOD>(k);
}
#line 6 "modulus/stirling_number_of_the_second_kind_table.hpp"

/**
 * @brief the Stirling number of the second kind (前処理 $O(NK)$ + $O(1)$)
 * @description the number of ways of partitioning a set of n elements into k nonempty sets
 * @see http://mathworld.wolfram.com/StirlingNumberoftheSecondKind.html
 * @see http://oeis.org/A008277
 * @see https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0
 */
template <int MOD>
mint<MOD> stirling_number_of_the_second_kind_table(int n, int k) {
    assert (0 <= n and 0 <= k);
    if (n  < k) return 0;
    if (n == k) return 1;
    if (k == 0) return 0;
    static std::vector<std::vector<mint<MOD> > > memo;
    if (memo.size() <= n) {
        int l = memo.size();
        memo.resize(n + 1);
        REP3 (i, l, n + 1) {
            memo[i].resize(i);
        }
    }
    if (memo[n][k]) return memo[n][k];
    return memo[n][k] =
        stirling_number_of_the_second_kind_table<MOD>(n - 1, k - 1) +
        stirling_number_of_the_second_kind_table<MOD>(n - 1, k) * k;
}
#line 5 "modulus/bell_number.hpp"

/**
 * @brief the Bell number (前処理 $O(NK)$ + $O(1)$)
 * @description the number of ways a set of n elements can be partitioned into nonempty subsets
 * @see http://mathworld.wolfram.com/BellNumber.html
 * @see https://oeis.org/A110
 * @see https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0
 */
template <int PRIME>
mint<PRIME> bell_number(int n, int k) {
    static std::vector<std::vector<mint<PRIME> > > memo;
    if (memo.size() <= n) {
        memo.resize(n + 1);
    }
    if (memo[n].empty()) {
        memo[n].push_back(0);
    }
    while (memo[n].size() <= k) {
        int i = memo[n].size();
        memo[n].push_back(memo[n].back() + stirling_number_of_the_second_kind_table<PRIME>(n, i));
    }
    return memo[n][k];
}

template <int PRIME>
mint<PRIME> unary_bell_number(int n) {
    return bell_number<PRIME>(n, n);
}
#line 8 "modulus/twelvefold_way.hpp"

/**
 * @brief twelvefold way / 写像12相
 * @sa https://en.wikipedia.org/wiki/Twelvefold_way
 * @sa https://mathtrain.jp/twelveway
 * @note the numbers of mapprings f putting N balls into K boxes
 */


/**
 * @brief labeled-N labeled-K any-f
 * @note the number of f for all f : N \to K
 * @note O(log K)
 */
template <int MOD>
mint<MOD> twelvefold_lla(int n, int k) {
    return mint<MOD>(k).pow(n);
}

/**
 * @brief labeled-N labeled-K injective-f
 * @note the number of f for injective f : N \rightarrowtail K
 * @note O(1) with precomputation O(N + K)
 */
template <int MOD>
mint<MOD> twelvefold_lli(int n, int k) {
    if (n > k) return 0;
    return permute<MOD>(k, n);
}

/**
 * @brief labeled-N labeled-K surjective-f
 * @note the number of f for surjective f : N \twoheadrightarrow K
 * @note O(NK) or O(N \log K)
 */
template <int MOD>
mint<MOD> twelvefold_lls(int n, int k) {
    return stirling_number_of_the_second_kind_direct<MOD>(n, k) * fact<MOD>(k);
}


/**
 * @brief unlabeled-N labeled-K any-f
 * @note the number of f \circ S_N for any f : N \to K
 * @note O(1) with precomputation O(N + K)
 */
template <int MOD>
mint<MOD> twelvefold_ula(int n, int k) {
    return choose<MOD>(n + k - 1, n);
}

/**
 * @brief unlabeled-N labeled-K injective-f
 * @note the number of f \circ S_N for injective f : N \rightarrowtail K
 * @note O(1) with precomputation O(K)
 */
template <int MOD>
mint<MOD> twelvefold_uli(int n, int k) {
    if (n > k) return 0;
    return choose<MOD>(k, n);
}

/**
 * @brief unlabeled-N labeled-K surjective-f
 * @note the number of f \circ S_N for surjective f : N \twoheadrightarrow K
 * @note O(1) with precomputation O(N)
 */
template <int MOD>
mint<MOD> twelvefold_uls(int n, int k) {
    if (n < k) return 0;
    return choose<MOD>(n - 1, n - k);
}


/**
 * @brief labeled-N unlabeled-K any-f
 * @note the number of S_K \circ f for all f : N \to K
 */
template <int MOD>
mint<MOD> twelvefold_lua(int n, int k) {
    return bell_number<MOD>(n, k);
}

/**
 * @brief labeled-N unlabeled-K injective-f
 * @note the number of S_K \circ f for injective f : N \rightarrowtail K
 * @note O(1)
 */
template <int MOD>
mint<MOD> twelvefold_lui(int n, int k) {
    if (n > k) return 0;
    return 1;
}

/**
 * @brief labeled-N unlabeled-K surjective-f
 * @note the number of S_K \circ f for surjective f : N \twoheadrightarrow K
 * @note O(NK) or O(N \log K)
 */
template <int MOD>
mint<MOD> twelvefold_lus(int n, int k) {
    return stirling_number_of_the_second_kind_direct<MOD>(n, k);
}


/**
 * @brief unlabeled-N unlabeled-K injective-f
 * @note the number of S_K \circ f \circ S_N for injective f : N \rightarrowtail K
 * @note O(1)
 */
template <int MOD>
mint<MOD> twelvefold_uui(int n, int k) {
    if (n > k) return 0;
    return 1;
}
#line 4 "modulus/twelvefold_way.balls_and_boxes_1.test.cpp"
using namespace std;

constexpr int MOD = 1e9 + 7;
int main() {
    int n, k; cin >> n >> k;
    cout << twelvefold_lla<MOD>(n, k) << endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

