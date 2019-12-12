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


# :warning: data_structure/convex-hull-trick-with-monotonicity.inc.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/convex-hull-trick-with-monotonicity.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-03 23:08:10 +0900




## Code
{% raw %}
```cpp
class convex_hull_trick_with_monotonicity {
    typedef pair<ll, ll> line_t;
    deque<line_t> lines;
    ll inc_x, dec_x;  // only for assertions
public:
    convex_hull_trick_with_monotonicity() {
        inc_x = LLONG_MIN;
        dec_x = LLONG_MAX;
    }
    void add_line_increasing(ll a, ll b) {
        assert (lines.empty() or lines.back().first <= a);  // weakly monotonically increasing
        while (lines.size() >= 2 and not is_required(lines[lines.size() - 2], lines.back(), { a, b })) {
            lines.pop_back();
        }
        lines.emplace_back(a, b);
    }
    void add_line_decreasing(ll a, ll b) {
        assert (lines.empty() or a <= lines.front().first);  // weakly monotonically decreasing
        while (lines.size() >= 2 and not is_required({ a, b }, lines.front(), lines[1])) {
            lines.pop_front();
        }
        lines.emplace_front(a, b);
    }
    ll get_max_increasing(ll x) {
        assert (inc_x <= x);  // weakly monotonically increasing
        inc_x = x;
        assert (not lines.empty());
        while (lines.size() >= 2 and get_value(0, x) <= get_value(1, x)) {
            lines.pop_front();
        }
        return get_value(0, x);
    }
    ll get_max_decreasing(ll x) {
        assert (x <= dec_x);  // weakly monotonically decreasing
        dec_x = x;
        assert (not lines.empty());
        while (lines.size() >= 2 and get_value(-2, x) >= get_value(-1, x)) {
            lines.pop_back();
        }
        return get_value(-1, x);
    }
private:
    bool is_required(line_t f1, line_t f2, line_t f3) const {
        return (f3.first - f1.first) * (f1.second - f2.second) < (f2.first - f1.first) * (f1.second - f3.second);
    }
    ll get_value(int i, ll x) const {
        if (i < 0) i += lines.size();
        ll a, b; tie(a, b) = lines[i];
        return a * x + b;
    }
};

struct inverted_convex_hull_trick_with_monotonicity {
    convex_hull_trick_with_monotonicity data;
    void add_line_increasing(ll a, ll b) { data.add_line_decreasing(- a, - b); }
    void add_line_decreasing(ll a, ll b) { data.add_line_increasing(- a, - b); }
    ll get_max_increasing(ll x) { return - data.get_max_increasing(x); }
    ll get_max_decreasing(ll x) { return - data.get_max_decreasing(x); }
};

unittest() {
    default_random_engine gen;
    REP (iteration, 10000) {
        bool inc_f = bernoulli_distribution(0.5)(gen);
        bool inc_x = bernoulli_distribution(0.5)(gen);
        vector<pair<int, int> > lines;
        REP (i, 30) {
            int a = uniform_int_distribution<int>(- 30, 30)(gen);
            int b = uniform_int_distribution<int>(- 30, 30)(gen);
            lines.emplace_back(a, b);
        }
        sort(ALL(lines));
        if (inc_f) {
            // nop
        } else {
            reverse(ALL(lines));
        }
        convex_hull_trick_with_monotonicity cht;
        int x = uniform_int_distribution<int>(- 100, 100)(gen);
        REP (i, lines.size()) {
            int y = INT_MIN;
            REP (j, i + 1) {
                int a, b; tie(a, b) = lines[j];
                chmax(y, a * x + b);
            }
            int a, b; tie(a, b) = lines[i];
            if (inc_f) {
                cht.add_line_increasing(a, b);
            } else {
                cht.add_line_decreasing(a, b);
            }
            if (inc_x) {
                assert (cht.get_max_increasing(x) == y);
                x += uniform_int_distribution<int>(0, 5)(gen);
            } else {
                assert (cht.get_max_decreasing(x) == y);
                x -= uniform_int_distribution<int>(0, 5)(gen);
            }
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

