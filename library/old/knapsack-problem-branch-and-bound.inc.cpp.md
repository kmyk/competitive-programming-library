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


# :warning: old/knapsack-problem-branch-and-bound.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/knapsack-problem-branch-and-bound.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
ll knapsack_problem_branch_and_bound(int n, ll max_w, vector<ll> const & a_v, vector<ll> const & a_w) {
    vector<ll> v(n), w(n); {
        vector<int> xs(n);
        iota(ALL(xs), 0);
        sort(ALL(xs), [&](int i, int j) {
            return a_v[i] *(double) a_w[j] > a_v[j] *(double) a_w[i];
        });
        REP (i, n) {
            v[i] = a_v[xs[i]];
            w[i] = a_w[xs[i]];
        }
    }
    ll ans = 0;
    function<void (int, ll, ll)> go = [&](int i, ll cur_v, ll cur_w) {
        if (max_w < cur_w) return; // not executable
        if (i == n) {
            chmax(ans, cur_v);
            return; // terminate
        }
        ll lr_v = cur_v; // linear relaxation
        ll lr_w = cur_w;
        int j = i;
        for (; j < n and lr_w + w[j] <= max_w; ++ j) { // greedy
            lr_w += w[j];
            lr_v += v[j];
        }
        if (lr_w == max_w or j == n) {
            chmax(ans, lr_v);
            return; // accept greedy
        }
        double lr_ans = lr_v + v[j] * ((max_w - lr_w) /(double) w[j]);
        if (lr_ans <= ans) return; // bound
        go(i + 1, cur_v + v[i], cur_w + w[i]);
        go(i + 1, cur_v,        cur_w       );
    };
    go(0, 0, 0);
    return ans;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/knapsack-problem-branch-and-bound.inc.cpp"
ll knapsack_problem_branch_and_bound(int n, ll max_w, vector<ll> const & a_v, vector<ll> const & a_w) {
    vector<ll> v(n), w(n); {
        vector<int> xs(n);
        iota(ALL(xs), 0);
        sort(ALL(xs), [&](int i, int j) {
            return a_v[i] *(double) a_w[j] > a_v[j] *(double) a_w[i];
        });
        REP (i, n) {
            v[i] = a_v[xs[i]];
            w[i] = a_w[xs[i]];
        }
    }
    ll ans = 0;
    function<void (int, ll, ll)> go = [&](int i, ll cur_v, ll cur_w) {
        if (max_w < cur_w) return; // not executable
        if (i == n) {
            chmax(ans, cur_v);
            return; // terminate
        }
        ll lr_v = cur_v; // linear relaxation
        ll lr_w = cur_w;
        int j = i;
        for (; j < n and lr_w + w[j] <= max_w; ++ j) { // greedy
            lr_w += w[j];
            lr_v += v[j];
        }
        if (lr_w == max_w or j == n) {
            chmax(ans, lr_v);
            return; // accept greedy
        }
        double lr_ans = lr_v + v[j] * ((max_w - lr_w) /(double) w[j]);
        if (lr_ans <= ans) return; // bound
        go(i + 1, cur_v + v[i], cur_w + w[i]);
        go(i + 1, cur_v,        cur_w       );
    };
    go(0, 0, 0);
    return ans;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

