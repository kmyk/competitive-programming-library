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


# :warning: number/factoradic.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b1bc248a7ff2b2e95569f56de68615df">number</a>
* <a href="{{ site.github.repository_url }}/blob/master/number/factoradic.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-06-02 16:57:27 +0900




## Code

{% raw %}
```cpp
int fact(int n) { return n ? n * fact(n-1) : 1; } // O(N)
template <class RandomAccessIterator>
uint64_t encode_factoradic(RandomAccessIterator first, RandomAccessIterator last) { // O(N^2)
    int n = last - first;
    uint64_t y = 0;
    repeat (i,n) {
        int xi = *(first + i);
        int rank = count_if(first, first + i, [&](int xj) { return xi < xj; });
        y += rank * fact(i);
    }
    return y;
}
vector<int> decode_factoradic(uint64_t y, int n) { // O(N^2)
    vector<int> xs(n);
    vector<int> zs(n); iota(zs.begin(), zs.end(), 0);
    repeat_reverse (i,n) {
        auto it = zs.begin() + (i - y / fact(i));
        xs[i] = *it;
        zs.erase(it);
        y %= fact(i);
    }
    return xs;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

