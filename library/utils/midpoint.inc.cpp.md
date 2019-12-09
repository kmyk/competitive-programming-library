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


# :warning: for given a and c, make b s.t. a < b < c
* category: utils


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
class midpoint {
    vector<bool> data;
    midpoint(vector<bool> const & data_) : data(data_) {}
public:
    midpoint() : data({ false, true }) {}
    static midpoint min() { return midpoint(vector<bool>()); }
    static midpoint max() { return midpoint(vector<bool>(1, true)); }
    /**
     * @brief for given a and c, make b s.t. a < b < c
     */
    midpoint between(midpoint const & other) const {
        auto const & a = this->data;
        auto const & b = other.data;
        vector<bool> c(::max(a.size(), b.size()) + 1);
        bool is_carried = false;
        REP_R (i, ::max(a.size(), b.size())) {
            bool a_i = (i < a.size() and a[i]);
            bool b_i = (i < b.size() and b[i]);
            c[i + 1]   = a_i ^ b_i ^ is_carried;
            is_carried = a_i + b_i + is_carried >= 2;
        }
        c[0] = is_carried;
        while (not c.empty() and not c.back()) {
            c.pop_back();
        }
        return midpoint(c);
    }
    bool operator < (midpoint const & other) const {
        return this->data < other.data;
    }
};

```
{% endraw %}

[Back to top page](../../index.html)

