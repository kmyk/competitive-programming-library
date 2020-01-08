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


# :warning: the doubling technique <small>(old/doubling.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/doubling.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief the doubling technique
 */
struct doubling_table {
    vector<vector<int> > table;
    doubling_table() = default;
    /**
     * @note O(N log K)
     */
    doubling_table(vector<int> const & next, int size = -1) {
        int n = next.size();
        {
            auto it = minmax_element(ALL(next));
            assert (0 <= *(it.first) and *(it.second) <= n);
        }
        if (size == -1) {
            size = max<int>(1, ceil(log2(n)));
        }
        table.resize(size);
        table[0] = next;
        REP (k, size - 1) {
            table[k + 1].resize(n, n);
            REP (i, n) if (table[k][i] != n) {
                table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }
    /**
     * @note O(log K)
     */
    int get(int i, int count) {
        assert (count < (1 << table.size()));
        int n = table[0].size();
        if (i == n) return n;
        assert (0 <= i and i < n);
        REP_R (k, table.size()) if (count & (1 << k)) {
            i = table[k][i];
            if (i == n) return n;
        }
        return i;
    }
};

unittest {
    vector<int> step { 1, 3, 3, 4, 5, 6, 8, 8, 9, 10 };
    doubling_table steps(step);
    assert (steps.get(6, 2) == step[step[6]]);
    assert (steps.get(3, 5) == step[step[step[step[step[3]]]]]);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/doubling.inc.cpp"
/**
 * @brief the doubling technique
 */
struct doubling_table {
    vector<vector<int> > table;
    doubling_table() = default;
    /**
     * @note O(N log K)
     */
    doubling_table(vector<int> const & next, int size = -1) {
        int n = next.size();
        {
            auto it = minmax_element(ALL(next));
            assert (0 <= *(it.first) and *(it.second) <= n);
        }
        if (size == -1) {
            size = max<int>(1, ceil(log2(n)));
        }
        table.resize(size);
        table[0] = next;
        REP (k, size - 1) {
            table[k + 1].resize(n, n);
            REP (i, n) if (table[k][i] != n) {
                table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }
    /**
     * @note O(log K)
     */
    int get(int i, int count) {
        assert (count < (1 << table.size()));
        int n = table[0].size();
        if (i == n) return n;
        assert (0 <= i and i < n);
        REP_R (k, table.size()) if (count & (1 << k)) {
            i = table[k][i];
            if (i == n) return n;
        }
        return i;
    }
};

unittest {
    vector<int> step { 1, 3, 3, 4, 5, 6, 8, 8, 9, 10 };
    doubling_table steps(step);
    assert (steps.get(6, 2) == step[step[6]]);
    assert (steps.get(3, 5) == step[step[step[step[step[3]]]]]);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

