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


# :warning: data_structure/linear-weighted-sum.inc.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/linear-weighted-sum.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-09 01:50:43 +0900




## Code
{% raw %}
```cpp
/**
 * @description a structure to compute sum_{i \in [l, r)} (i - l) a_i
 * @note a_l is ignored since i - l = 0
 */
class linear_weighted_sum {
    vector<ll> b;
    vector<ll> c;
public:
    linear_weighted_sum() = default;
    linear_weighted_sum(vector<ll> const & a) {
        int n = a.size();
        b.resize(n + 1);
        c.resize(n + 1);
        REP (i, n) {
            b[i + 1] = b[i] + a[i];
            c[i + 1] = c[i] + i * a[i];
        }
    }
    ll range_sum(int l, int r) const {
        assert (max(0, l) <= r and r <= b.size() - 1);
        int l1 = max(0, l);
        return (c[r] - c[l1]) - l * (b[r] - b[l1]);
    }
    ll inversed_range_sum(int l, int r) const {
        assert (0 <= l and l <= min((int)b.size() - 1, r));
        int r1 = min((int)b.size() - 1, r);
        return r * (b[r1] - b[l]) - (c[r1] - c[l]);
    }
};

/**
 * @description a monoid to compute sum_{i \in [l, r)} (i - l) a_i
 */
struct linear_weighted_plus_monoid {
    typedef struct {
        int l, r;
        ll sum, weighted_sum;
    } value_type;
    static value_type make(int i, ll value) {
        value_type a;
        a.l = i;
        a.r = i + 1;
        a.sum = value;
        a.weighted_sum = 0;
        return a;
    }
    value_type unit() const {
        return make(-1, 0);
    }
    value_type append(value_type a, value_type b) const {
        if (a.l == -1) return b;
        if (b.l == -1) return a;
        assert (a.r == b.l);
        value_type c;
        c.l = a.l;
        c.r = b.r;
        c.sum = a.sum + b.sum;
        c.weighted_sum = a.weighted_sum + b.weighted_sum + (a.r - a.l) * b.sum;
        return c;
    }
};

unittest {
    default_random_engine gen;
    REP (iteration, 10) {
        int size = uniform_int_distribution<int>(3, 100)(gen);
        vector<ll> ary(size);
        segment_tree<linear_weighted_plus_monoid> segtree(size);
        REP (i, size) {
            int a = uniform_int_distribution<int>(-100, 100)(gen);
            ary[i] = a;
            segtree.point_set(i, linear_weighted_plus_monoid::make(i, a));
        }
        linear_weighted_sum lws(ary);
        REP (iteration, 100) {
            int l = uniform_int_distribution<int>(0, size - 1)(gen);
            int r = uniform_int_distribution<int>(l + 1, size)(gen);
            ll acc_l = 0;
            ll acc_r = 0;
            REP3 (m, l, r) {
                acc_l += (m - l) * ary[m];
                acc_r += (r - m) * ary[m];
            }
            auto m = segtree.range_concat(l, r);
            assert (acc_l == m.weighted_sum);
            assert (acc_r == m.sum * (m.r - m.l) - m.weighted_sum);
            assert (acc_l == lws.range_sum(l, r));
            assert (acc_r == lws.inversed_range_sum(l, r));
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

