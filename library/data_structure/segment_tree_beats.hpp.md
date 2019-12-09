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


# :warning: a segment tree beats
* category: data_structure


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

/**
 * @brief a segment tree beats
 */
class segment_tree_beats {
    typedef struct {
        int64_t first;
        int64_t second;
        int cnt;
        int64_t sum;
    } value_type;

    int n;
    std::vector<value_type> a;

public:
    segment_tree_beats() = default;
    segment_tree_beats(int n_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1, (value_type) { INT64_MAX, INT64_MIN, -1, 0 });
        REP (i, 2 * n - 1) {
            a[i].cnt = n >> (32 - __builtin_clz(i + 1) - 1);
        }
    }

    void range_chmin(int l, int r, int64_t value) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        range_chmin(0, 0, n, l, r, value);
    }
    void range_chmin(int i, int il, int ir, int l, int r, int64_t g) {
        if (ir <= l or r <= il or break_condition(i, g)) {
            // break
        } else if (l <= il and ir <= r and tag_condition(i, g)) {
            tag(i, g);
        } else {
            pushdown(i);
            range_chmin(2 * i + 1, il, (il + ir) / 2, l, r, g);
            range_chmin(2 * i + 2, (il + ir) / 2, ir, l, r, g);
            update(i);
        }
    }

    int64_t range_sum(int l, int r) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        return range_sum(0, 0, n, l, r);
    }
    int64_t range_sum(int i, int il, int ir, int l, int r) {
        if (ir <= l or r <= il) {
            return 0;
        } else if (l <= il and ir <= r) {
            return a[i].sum;
        } else {
            pushdown(i);
            int64_t sum_l = range_sum(2 * i + 1, il, (il + ir) / 2, l, r);
            int64_t sum_r = range_sum(2 * i + 2, (il + ir) / 2, ir, l, r);
            return sum_l + sum_r;
        }
    }

private:
    bool break_condition(int i, int64_t g) {
         return a[i].first <= g;
    }
    bool tag_condition(int i, int64_t g) {
         return a[i].second < g and g < a[i].first;
    }
    void tag(int i, int64_t g) {
        if (a[i].first != INT64_MAX) {
            a[i].sum -= a[i].first * a[i].cnt;
        }
        a[i].sum += g * a[i].cnt;
        a[i].first = g;
    }
    void pushdown(int i) {
        if (a[i].first < a[2 * i + 1].first) {
            tag(2 * i + 1, a[i].first);
        }
        if (a[i].first < a[2 * i + 2].first) {
            tag(2 * i + 2, a[i].first);
        }
    }
    void update(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        vector<int64_t> b { a[l].first, a[l].second, a[r].first, a[r].second };
        std::sort(b.rbegin(), b.rend());
        b.erase(std::unique(ALL(b)), b.end());
        a[i].first = b[0];
        a[i].second = b[1];
        a[i].cnt = (b[0] == a[l].first ? a[l].cnt : 0) + (b[0] == a[r].first ? a[r].cnt : 0);
        a[i].sum = a[l].sum + a[r].sum;
    }
};

```
{% endraw %}

[Back to top page](../../index.html)

