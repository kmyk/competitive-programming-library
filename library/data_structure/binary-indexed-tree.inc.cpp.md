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


# :warning: data_structure/binary-indexed-tree.inc.cpp
* category: data_structure


[Back to top page](../../index.html)



## Code
```cpp
template <typename Monoid>
struct binary_indexed_tree {  // on monoid
    typedef typename Monoid::value_type value_type;
    vector<value_type> data;
    Monoid mon;
    binary_indexed_tree(size_t n, Monoid const & a_mon = Monoid()) : mon(a_mon) {
        data.resize(n, mon.unit());
    }
    void point_append(size_t i, value_type z) {  // data[i] += z
        for (size_t j = i + 1; j <= data.size(); j += j & -j) data[j - 1] = mon.append(data[j - 1], z);
    }
    value_type initial_range_concat(size_t i) {  // sum [0, i)
        value_type acc = mon.unit();
        for (size_t j = i; 0 < j; j -= j & -j) acc = mon.append(data[j - 1], acc);
        return acc;
    }
};
struct plus_monoid {
    typedef int value_type;
    int unit() const { return 0; }
    int append(int a, int b) const { return a + b; }
};

unittest {
    binary_indexed_tree<plus_monoid> bit(8);
    bit.point_append(3, 4);
    bit.point_append(4, 3);
    bit.point_append(7, 1);
    assert (bit.initial_range_concat(3) == 0);
    assert (bit.initial_range_concat(5) == 7);
    assert (bit.initial_range_concat(8) == 8);
    bit.point_append(4, 2);
    assert (bit.initial_range_concat(3) == 0);
    assert (bit.initial_range_concat(5) == 9);
    assert (bit.initial_range_concat(8) == 10);
}

```

[Back to top page](../../index.html)

