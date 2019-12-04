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


# :warning: modulus/stirling-number-of-the-second-kind.inc.cpp
* category: modulus


[Back to top page](../../index.html)

* the Stirling number of the second kind
* see: [http://mathworld.wolfram.com/StirlingNumberoftheSecondKind.html](http://mathworld.wolfram.com/StirlingNumberoftheSecondKind.html)
* see: [http://oeis.org/A008277](http://oeis.org/A008277)
* see: [https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0](https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0)


## Code
```cpp
/**
 * @brief the Stirling number of the second kind
 * @description the number of ways of partitioning a set of n elements into k nonempty sets
 * @see http://mathworld.wolfram.com/StirlingNumberoftheSecondKind.html
 * @see http://oeis.org/A008277
 * @see https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0
 * @note O(NK), memoized
 */
template <int MOD>
mint<MOD> stirling_number_of_the_second_kind(int n, int k) {
    assert (0 <= n and 0 <= k);
    if (n  < k) return 0;
    if (n == k) return 1;
    if (k == 0) return 0;
    static vector<vector<mint<MOD> > > memo;
    if (memo.size() <= n) {
        int l = memo.size();
        memo.resize(n + 1);
        REP3 (i, l, n + 1) memo[i].resize(i);
    }
    if (memo[n][k]) return memo[n][k];
    return memo[n][k] =
        stirling_number_of_the_second_kind<MOD>(n - 1, k - 1) +
        stirling_number_of_the_second_kind<MOD>(n - 1, k) * k;
}

/**
 * @note O(K \log N)
 */
template <int MOD>
mint<MOD> stirling_number_of_the_second_kind(int n, int k) {
    assert (0 <= n and 0 <= k);
    mint<MOD> acc = 0;
    REP3 (i, 1, k + 1) {
        int parity = ((k - i) % 2 == 0 ? +1 : -1);
        acc += choose<MOD>(k, i) * mint<MOD>(i).pow(n) * parity;
    }
    return acc * fact_inv<MOD>(k);
}

```

[Back to top page](../../index.html)

