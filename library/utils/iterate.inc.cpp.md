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


# :warning: utils/iterate.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/iterate.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-06-02 16:57:27+09:00




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
#line 1 "utils/iterate.inc.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

