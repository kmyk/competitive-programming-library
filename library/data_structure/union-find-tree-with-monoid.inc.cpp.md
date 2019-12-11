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


# :warning: data_structure/union-find-tree-with-monoid.inc.cpp
<a href="../../index.html">Back to top page</a>

* category: data_structure
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/union-find-tree-with-monoid.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-09 01:50:43 +0900




## Code
{% raw %}
```cpp
// NOTE: not verified
template <class Monoid>
struct union_find_tree_with_data {
    typedef typename Monoid::value_type value_type;
    const Monoid mon;
    vector<int> data;
    vector<value_type> value;

    union_find_tree_with_data() = default;
    explicit union_find_tree(size_t n, Monoid const & mon_) : mon(mon_), data(n, -1), value(n, mon.unit()) {}
    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }
    int tree_size(int i) { return - data[find_root(i)]; }
    int unite_trees(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (tree_size(i) < tree_size(j)) swap(i, j);
            data[i] += data[j];
            data[j] = i;
            value[i] = mon.append(value[i], value[j]);
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
    value_type get_value(int i) { return value[find_root(i)]; }
    void set_value(int i, value_type z) { value[find_root(i)] = z; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

