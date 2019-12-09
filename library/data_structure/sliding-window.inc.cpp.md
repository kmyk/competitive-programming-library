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


# :warning: the sliding window minimum algorithm
* category: data_structure


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
/**
 * @brief the sliding window minimum algorithm
 * @note to get maximums, use greater<T>
 * @note verified http://poj.org/problem?id=2823
 * @note verified http://cf16-tournament-round3-open.contest.atcoder.jp/tasks/asaporo_d
 */
template <typename T, class Compare = less<T> >
class sliding_window {
    deque<pair<int, T> > data;
    Compare compare;
public:
    sliding_window(Compare const & a_compare = Compare())
        : compare(a_compare) {}
    T front() {  // O(1), minimum
        return data.front().second;
    }
    void push_back(int i, T a) {  // O(1) amortized.
        while (not data.empty() and compare(a, data.back().second)) {
            data.pop_back();
        }
        data.emplace_back(i, a);
    }
    void pop_front(int i) {
        if (data.front().first == i) {
            data.pop_front();
        }
    }
    void push_front(int i, T a) {
        if (data.empty() or not compare(data.front().second, a)) {
            data.emplace_front(i, a);
        }
    }
};

```
{% endraw %}

[Back to top page](../../index.html)

