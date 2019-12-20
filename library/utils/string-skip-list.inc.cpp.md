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


# :warning: utils/string-skip-list.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/string-skip-list.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-11-11 00:29:39+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename Iterator>
vector<array<int, 26> > get_next_index(Iterator first, Iterator last) {
    int n = distance(first, last);
    vector<array<int, 26> > x(n + 1);
    fill(whole(x[n]), n);
    repeat_reverse (i, n) {
        x[i] = x[i + 1];
        x[i][*(first + i) - 'a'] = i;
    }
    return x;  // x_{i, c} = \min \{ j \ge i \mid s_j = c \}
}
unittest {
    string s = "aabcab";
    auto x = get_next_index(s.begin(), s.end());
    assert (x[0][0] == 0);  // () [a]abcab
    assert (x[0][1] == 2);  // () aa[b]cab
    assert (x[0][2] == 3);  // () aab[c]ab
    assert (x[4][0] == 4);  // (aabc) [a]b
    assert (x[4][1] == 5);  // (aabc) a[b]
    assert (x[4][2] == 6);  // (aabc) ab[]
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/string-skip-list.inc.cpp"
template <typename Iterator>
vector<array<int, 26> > get_next_index(Iterator first, Iterator last) {
    int n = distance(first, last);
    vector<array<int, 26> > x(n + 1);
    fill(whole(x[n]), n);
    repeat_reverse (i, n) {
        x[i] = x[i + 1];
        x[i][*(first + i) - 'a'] = i;
    }
    return x;  // x_{i, c} = \min \{ j \ge i \mid s_j = c \}
}
unittest {
    string s = "aabcab";
    auto x = get_next_index(s.begin(), s.end());
    assert (x[0][0] == 0);  // () [a]abcab
    assert (x[0][1] == 2);  // () aa[b]cab
    assert (x[0][2] == 3);  // () aab[c]ab
    assert (x[4][0] == 4);  // (aabc) [a]b
    assert (x[4][1] == 5);  // (aabc) a[b]
    assert (x[4][2] == 6);  // (aabc) ab[]
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

