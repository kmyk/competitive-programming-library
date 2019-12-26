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


# :warning: get sum of elements in the queue <small>(data_structure/sliding_window_aggregation.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/sliding_window_aggregation.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00




## Depends on

* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Required by

* :warning: <a href="sliding_window_aggregation.random-test.cpp.html">data_structure/sliding_window_aggregation.random-test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <cstddef>
#include <deque>
#include "utils/macros.hpp"

template <class Monoid>
struct sliding_window_aggregation {
    typedef typename Monoid::value_type value_type;
    Monoid mon;
    std::deque<value_type> data;
    int front;
    value_type back;
    sliding_window_aggregation(const Monoid & mon_ = Monoid()) : mon(mon_) {
        front = 0;
        back = mon.unit();
    }
    /**
     * @note O(1)
     */
    void push(value_type x) {
        data.push_back(x);
        back = mon.append(back, x);
    }
    /**
     * @note amortized O(1)
     */
    void pop() {
        assert (not data.empty());
        data.pop_front();
        if (front) {
            -- front;
        } else {
            REP_R (i, (int)data.size() - 1) {
                data[i] = mon.append(data[i], data[i + 1]);
            }
            front = data.size();
            back = mon.unit();
        }
    }
    /**
     * @brief get sum of elements in the queue
     * @note O(1)
     */
    value_type accumulate() const {
        return front ? mon.append(data.front(), back) : back;
    }
    bool empty() const {
        return data.empty();
    }
    std::size_t size() const {
        return data.size();
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/sliding_window_aggregation.hpp"
#include <cassert>
#include <cstddef>
#include <deque>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 6 "data_structure/sliding_window_aggregation.hpp"

template <class Monoid>
struct sliding_window_aggregation {
    typedef typename Monoid::value_type value_type;
    Monoid mon;
    std::deque<value_type> data;
    int front;
    value_type back;
    sliding_window_aggregation(const Monoid & mon_ = Monoid()) : mon(mon_) {
        front = 0;
        back = mon.unit();
    }
    /**
     * @note O(1)
     */
    void push(value_type x) {
        data.push_back(x);
        back = mon.append(back, x);
    }
    /**
     * @note amortized O(1)
     */
    void pop() {
        assert (not data.empty());
        data.pop_front();
        if (front) {
            -- front;
        } else {
            REP_R (i, (int)data.size() - 1) {
                data[i] = mon.append(data[i], data[i + 1]);
            }
            front = data.size();
            back = mon.unit();
        }
    }
    /**
     * @brief get sum of elements in the queue
     * @note O(1)
     */
    value_type accumulate() const {
        return front ? mon.append(data.front(), back) : back;
    }
    bool empty() const {
        return data.empty();
    }
    std::size_t size() const {
        return data.size();
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

