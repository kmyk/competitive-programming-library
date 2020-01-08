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


# :warning: old/iterate.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/iterate.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// http://yukicoder.me/submissions/142657
struct sequence {
    vector<int> data;
    int offset, cycle;
};
sequence iterate(int a, function<int (int)> f) {
    sequence xs;
    map<int, int> used;
    while (not used.count(a)) {
        used[a] = xs.data.size();
        xs.data.push_back(a);
        a = f(a);
    }
    xs.offset  = used[a];
    xs.cycle = xs.data.size() - xs.offset;
    return xs;
}
int at(sequence const & xs, int i) {
    return xs.data[i < xs.offset ? i : (i - xs.offset) % xs.cycle + xs.offset];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/iterate.inc.cpp"
// http://yukicoder.me/submissions/142657
struct sequence {
    vector<int> data;
    int offset, cycle;
};
sequence iterate(int a, function<int (int)> f) {
    sequence xs;
    map<int, int> used;
    while (not used.count(a)) {
        used[a] = xs.data.size();
        xs.data.push_back(a);
        a = f(a);
    }
    xs.offset  = used[a];
    xs.cycle = xs.data.size() - xs.offset;
    return xs;
}
int at(sequence const & xs, int i) {
    return xs.data[i < xs.offset ? i : (i - xs.offset) % xs.cycle + xs.offset];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

