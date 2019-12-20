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


# :warning: the extended Mo's algorithm <small>(utils/rollback-square-decomposition.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/rollback-square-decomposition.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-04-12 06:30:36+09:00


* see: <a href="http://snuke.hatenablog.com/entry/2016/07/01/000000">http://snuke.hatenablog.com/entry/2016/07/01/000000</a>
* see: <a href="http://codeforces.com/blog/entry/7383?#comment-161520">http://codeforces.com/blog/entry/7383?#comment-161520</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief the extended Mo's algorithm
 * @arg stupid is called O(Q) times, each length is O(\sqrt{N})
 * @arg mo si the following:
 *     struct rollback_mo_interface {
 *         void reset(int l);  // called O(N) times
 *         void extend_left( int l, int r);  // called O(Q) times, the sum of length is O(N \sqrt {N})
 *         void extend_right(int l, int r);  // called O(Q) times, the sum of length is O(Q \sqrt {N})
 *         void snapshot();  // called O(Q) times
 *         void rollback();  // called O(Q) times
 *         void query();     // called O(Q) times
 *     };
 * @see http://snuke.hatenablog.com/entry/2016/07/01/000000
 * @see http://codeforces.com/blog/entry/7383?#comment-161520
 */
template <class Func, class RollbackMoInterface>
void rollback_square_decomposition(int n, vector<pair<int, int> > const & range, RollbackMoInterface & mo, Func stupid) {
    int bucket_size = sqrt(n);
    int bucket_count = (n + bucket_size - 1) / bucket_size;
    vector<vector<int> > bucket(bucket_count);
    REP (i, int(range.size())) {
        int l, r; tie(l, r) = range[i];
        if (r - l <= bucket_size) {
            stupid(l, r);
        } else {
            bucket[l / bucket_size].push_back(i);
        }
    }
    REP (b, bucket_count) {
        sort(ALL(bucket[b]), [&](int i, int j) { return range[i].second < range[j].second; });
        int l = (b + 1) * bucket_size;
        mo.reset(l);
        int r = l;
        for (int i : bucket[b]) {
            int l_i, r_i; tie(l_i, r_i) = range[i];
            mo.extend_right(r, r_i);
            mo.snapshot();
            mo.extend_left(l_i, l);
            mo.query();
            mo.rollback();
            r = r_i;
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/rollback-square-decomposition.inc.cpp"
/**
 * @brief the extended Mo's algorithm
 * @arg stupid is called O(Q) times, each length is O(\sqrt{N})
 * @arg mo si the following:
 *     struct rollback_mo_interface {
 *         void reset(int l);  // called O(N) times
 *         void extend_left( int l, int r);  // called O(Q) times, the sum of length is O(N \sqrt {N})
 *         void extend_right(int l, int r);  // called O(Q) times, the sum of length is O(Q \sqrt {N})
 *         void snapshot();  // called O(Q) times
 *         void rollback();  // called O(Q) times
 *         void query();     // called O(Q) times
 *     };
 * @see http://snuke.hatenablog.com/entry/2016/07/01/000000
 * @see http://codeforces.com/blog/entry/7383?#comment-161520
 */
template <class Func, class RollbackMoInterface>
void rollback_square_decomposition(int n, vector<pair<int, int> > const & range, RollbackMoInterface & mo, Func stupid) {
    int bucket_size = sqrt(n);
    int bucket_count = (n + bucket_size - 1) / bucket_size;
    vector<vector<int> > bucket(bucket_count);
    REP (i, int(range.size())) {
        int l, r; tie(l, r) = range[i];
        if (r - l <= bucket_size) {
            stupid(l, r);
        } else {
            bucket[l / bucket_size].push_back(i);
        }
    }
    REP (b, bucket_count) {
        sort(ALL(bucket[b]), [&](int i, int j) { return range[i].second < range[j].second; });
        int l = (b + 1) * bucket_size;
        mo.reset(l);
        int r = l;
        for (int i : bucket[b]) {
            int l_i, r_i; tie(l_i, r_i) = range[i];
            mo.extend_right(r, r_i);
            mo.snapshot();
            mo.extend_left(l_i, l);
            mo.query();
            mo.rollback();
            r = r_i;
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

