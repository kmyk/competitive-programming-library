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


# :warning: data_structure/range-union-find-tree.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/range-union-find-tree.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-03 23:08:10 +0900




## Code

{% raw %}
```cpp
/**
 * @note 計算量は確かに落ちるのだけどこれを使って速くなるケースは元々全部連結してて自明な気がする
 * @note thank to https://beta.atcoder.jp/contests/yahoo-procon2018-final/submissions/2126707
 */
struct range_union_find_tree {
    vector<union_find_tree> data;
    range_union_find_tree() = default;
    explicit range_union_find_tree(size_t n) {
        int log_n = 32 - __builtin_clz(n);
        data.resize(log_n, union_find_tree(n));
    }
    /**
     * @description unite (l1 + k)-th tree and (l2 + k)-th tree for each k in [0, len)
     * @note O(1)
     */
    void range_unite_trees(int l1, int l2, int len) {
        int n = data.front().data.size();
        assert (0 <= l1 and l1 + len <= n);
        assert (0 <= l2 and l2 + len <= n);
        assert (len >= 1);
        int k = 31 - __builtin_clz(len);  // log2
        data[k].unite_trees(l1, l2);
        data[k].unite_trees(l1 + len - (1 << k), l2 + len - (1 << k));
    }
    /**
     * @description collapse range-queries and get result
     * @note O(N \log N)
     */
    union_find_tree const & update() {
        int n = data.front().data.size();
        int log_n = data.size();
        REP_R (k, log_n - 1) {
            REP (i, n - (1 << k)) {
                int root = data[k + 1].find_root(i);
                data[k].unite_trees(i, root);
                data[k].unite_trees(i + (1 << k), root + (1 << k));
            }
        }
        return data[0];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

