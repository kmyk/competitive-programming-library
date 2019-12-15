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


# :warning: twelvefold way / 写像12相 <small>(modulus/twelvefold-way.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#06efba23b1f3a9b846a25c6b49f30348">modulus</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulus/twelvefold-way.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900


* labeled-N labeled-K any-f
* labeled-N labeled-K injective-f
* labeled-N labeled-K surjective-f
* unlabeled-N labeled-K any-f
* unlabeled-N labeled-K injective-f
* unlabeled-N labeled-K surjective-f
* labeled-N unlabeled-K any-f
* labeled-N unlabeled-K injective-f
* labeled-N unlabeled-K surjective-f
* unlabeled-N unlabeled-K injective-f
* see: <a href="https://en.wikipedia.org/wiki/Twelvefold_way">https://en.wikipedia.org/wiki/Twelvefold_way</a>
* see: <a href="https://mathtrain.jp/twelveway">https://mathtrain.jp/twelveway</a>


## Code

{% raw %}
```cpp
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
    return stirling_number_of_the_second_kind<MOD>(n, k) * fact(k);
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
    return binary_bell_number(n, k);
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
    return stirling_number_of_the_second_kind<MOD>(n, k);
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

