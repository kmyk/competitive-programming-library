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


# :warning: a double-ended priority queue <small>(data_structure/double-ended-priority-queue.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/double-ended-priority-queue.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-03 23:08:10+09:00


* see: <a href="https://topcoder.g.hatena.ne.jp/spaghetti_source/20121006#c1349522933">https://topcoder.g.hatena.ne.jp/spaghetti_source/20121006#c1349522933</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief a double-ended priority queue
 * @note the feature is the same to std::multiset, but this is 7x faster for 10^7 operations
 * @note interval heap is more faster
 * @sa https://topcoder.g.hatena.ne.jp/spaghetti_source/20121006#c1349522933
 */
template <class T>
class four_priority_queues {
    priority_queue<T> max_heap, max_deleted;
    priority_queue<T, vector<T>, greater<T> > min_heap, min_deleted;
private:
    template <class Queue>
    void flush(Queue & heap, Queue & deleted) {
        while (not deleted.empty()) {
            assert (not heap.empty());
            if (deleted.top() != heap.top()) break;
            deleted.pop();
            heap.pop();
        }
    }
public:
    void push(T a) {
        max_heap.push(a);
        min_heap.push(a);
    }
    T get_min() {
        flush(min_heap, min_deleted);
        return min_heap.top();
    }
    T get_max() {
        flush(max_heap, max_deleted);
        return max_heap.top();
    }
    void pop_min() {
        max_deleted.push(get_min());
        min_heap.pop();
    }
    void pop_max() {
        min_deleted.push(get_max());
        max_heap.pop();
    }
    bool empty() {
        flush(min_heap, min_deleted);  // NOTE: you can replace this with max_*
        return min_heap.empty();
    }
};

unittest {
    default_random_engine gen;
    REP (iteration, 10) {
        four_priority_queues<int> depq;
        multiset<int> mlt;
        REP (iteration, 100000) {
            if (mlt.empty() or bernoulli_distribution(0.8)(gen)) {
                int a = uniform_int_distribution<int>()(gen);
                mlt.insert(a);
                depq.push(a);
            } else {
                if (bernoulli_distribution(0.5)(gen)) {
                    int a = *mlt.begin();
                    int b = depq.get_min();
                    assert (a == b);
                    mlt.erase(mlt.begin());
                    depq.pop_min();
                } else {
                    int a = *prev(mlt.end());
                    int b = depq.get_max();
                    assert (a == b);
                    mlt.erase(prev(mlt.end()));
                    depq.pop_max();
                }
            }
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/double-ended-priority-queue.inc.cpp"
/**
 * @brief a double-ended priority queue
 * @note the feature is the same to std::multiset, but this is 7x faster for 10^7 operations
 * @note interval heap is more faster
 * @sa https://topcoder.g.hatena.ne.jp/spaghetti_source/20121006#c1349522933
 */
template <class T>
class four_priority_queues {
    priority_queue<T> max_heap, max_deleted;
    priority_queue<T, vector<T>, greater<T> > min_heap, min_deleted;
private:
    template <class Queue>
    void flush(Queue & heap, Queue & deleted) {
        while (not deleted.empty()) {
            assert (not heap.empty());
            if (deleted.top() != heap.top()) break;
            deleted.pop();
            heap.pop();
        }
    }
public:
    void push(T a) {
        max_heap.push(a);
        min_heap.push(a);
    }
    T get_min() {
        flush(min_heap, min_deleted);
        return min_heap.top();
    }
    T get_max() {
        flush(max_heap, max_deleted);
        return max_heap.top();
    }
    void pop_min() {
        max_deleted.push(get_min());
        min_heap.pop();
    }
    void pop_max() {
        min_deleted.push(get_max());
        max_heap.pop();
    }
    bool empty() {
        flush(min_heap, min_deleted);  // NOTE: you can replace this with max_*
        return min_heap.empty();
    }
};

unittest {
    default_random_engine gen;
    REP (iteration, 10) {
        four_priority_queues<int> depq;
        multiset<int> mlt;
        REP (iteration, 100000) {
            if (mlt.empty() or bernoulli_distribution(0.8)(gen)) {
                int a = uniform_int_distribution<int>()(gen);
                mlt.insert(a);
                depq.push(a);
            } else {
                if (bernoulli_distribution(0.5)(gen)) {
                    int a = *mlt.begin();
                    int b = depq.get_min();
                    assert (a == b);
                    mlt.erase(mlt.begin());
                    depq.pop_min();
                } else {
                    int a = *prev(mlt.end());
                    int b = depq.get_max();
                    assert (a == b);
                    mlt.erase(prev(mlt.end()));

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

