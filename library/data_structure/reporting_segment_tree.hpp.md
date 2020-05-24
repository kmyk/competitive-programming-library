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


# :heavy_check_mark: Dual Segment Tree / 双対セグメント木 (列挙クエリ, 完全二分木) <small>(data_structure/reporting_segment_tree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/reporting_segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-08 03:44:30+09:00




## Depends on

* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Required by

* :heavy_check_mark: <a href="dynamic_connectivity_offline.hpp.html">Dynamic Connectivity (offline, commutative monoids) <small>(data_structure/dynamic_connectivity_offline.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp.html">data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <type_traits>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief Dual Segment Tree / 双対セグメント木 (列挙クエリ, 完全二分木)
 * @note This tree is very similar to the Bentley's original segment tree.
 */
template <class Key>
struct reporting_segment_tree {
    int size;
    std::vector<std::vector<Key> > data;
    reporting_segment_tree() = default;
    explicit reporting_segment_tree(int size_) {
        size = 1; while (size < size_) size *= 2;
        data.resize(2 * size - 1);
    }

    /**
     * @arg key must be unique
     * @note $O(\log n)$
     */
    void add_segment(int l, int r, const Key & key) {
        assert (0 <= l and l <= r and r <= size);
        for (l += size, r += size; l < r; l /= 2, r /= 2) {  // 1-based
            if (l % 2 == 1) data[(l ++) - 1].push_back(key);
            if (r % 2 == 1) data[(-- r) - 1].push_back(key);
        }
    }

    /**
     * @note $O(\log n + k)$
     */
    template <class Callback>
    void list_segments(int i, Callback & callback) {
        static_assert (std::is_invocable_r<void, Callback, const Key &>::value, "");
        assert (0 <= i and i < size);
        for (i += size; i > 0; i /= 2) {  // 1-based
            for (const auto & key : data[i - 1]) {
                callback(key);
            }
        }
    }

    /**
     * @note $O(n + k)$
     * @arg remove can be implemented as undo
     * @arg report is called with all indices in increasing order
     */
    template <class Add, class Remove, class Report>
    void traverse_segments(Add & add, Remove & remove, Report & report) {
        static_assert (std::is_invocable_r<void, Add, const Key &>::value, "");
        static_assert (std::is_invocable_r<void, Remove, const Key &>::value, "");
        static_assert (std::is_invocable_r<void, Report, int>::value, "");
        std::function<void (int, int, int)> dfs = [&](int i, int l, int r) {
            for (const auto & key : data[i]) {
                add(key);
            }
            if (i >= size - 1) {
                report(i - size + 1);
            } else {
                dfs(2 * i + 1, l, (l + r) / 2);
                dfs(2 * i + 2, (l + r) / 2, r);
            }
            for (auto it = data[i].rbegin(); it != data[i].rend(); ++ it) {
                remove(*it);
            }
        };
        dfs(0, 0, size);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/reporting_segment_tree.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <type_traits>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 8 "data_structure/reporting_segment_tree.hpp"

/**
 * @brief Dual Segment Tree / 双対セグメント木 (列挙クエリ, 完全二分木)
 * @note This tree is very similar to the Bentley's original segment tree.
 */
template <class Key>
struct reporting_segment_tree {
    int size;
    std::vector<std::vector<Key> > data;
    reporting_segment_tree() = default;
    explicit reporting_segment_tree(int size_) {
        size = 1; while (size < size_) size *= 2;
        data.resize(2 * size - 1);
    }

    /**
     * @arg key must be unique
     * @note $O(\log n)$
     */
    void add_segment(int l, int r, const Key & key) {
        assert (0 <= l and l <= r and r <= size);
        for (l += size, r += size; l < r; l /= 2, r /= 2) {  // 1-based
            if (l % 2 == 1) data[(l ++) - 1].push_back(key);
            if (r % 2 == 1) data[(-- r) - 1].push_back(key);
        }
    }

    /**
     * @note $O(\log n + k)$
     */
    template <class Callback>
    void list_segments(int i, Callback & callback) {
        static_assert (std::is_invocable_r<void, Callback, const Key &>::value, "");
        assert (0 <= i and i < size);
        for (i += size; i > 0; i /= 2) {  // 1-based
            for (const auto & key : data[i - 1]) {
                callback(key);
            }
        }
    }

    /**
     * @note $O(n + k)$
     * @arg remove can be implemented as undo
     * @arg report is called with all indices in increasing order
     */
    template <class Add, class Remove, class Report>
    void traverse_segments(Add & add, Remove & remove, Report & report) {
        static_assert (std::is_invocable_r<void, Add, const Key &>::value, "");
        static_assert (std::is_invocable_r<void, Remove, const Key &>::value, "");
        static_assert (std::is_invocable_r<void, Report, int>::value, "");
        std::function<void (int, int, int)> dfs = [&](int i, int l, int r) {
            for (const auto & key : data[i]) {
                add(key);
            }
            if (i >= size - 1) {
                report(i - size + 1);
            } else {
                dfs(2 * i + 1, l, (l + r) / 2);
                dfs(2 * i + 2, (l + r) / 2, r);
            }
            for (auto it = data[i].rbegin(); it != data[i].rend(); ++ it) {
                remove(*it);
            }
        };
        dfs(0, 0, size);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

