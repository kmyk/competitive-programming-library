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


# VerificationStatus.VERIFIED Union-Find Tree (foldable with commutative monoids, undoable) <small>(data_structure/union_find_tree_foldable_undoable.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/union_find_tree_foldable_undoable.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-08 03:44:30+09:00




## Required by

* :heavy_check_mark: <a href="dynamic_connectivity_offline.hpp.html">Dynamic Connectivity (offline, commutative monoids) <small>(data_structure/dynamic_connectivity_offline.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp.html">data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <tuple>
#include <utility>
#include <vector>

/**
 * @brief Union-Find Tree (foldable with commutative monoids, undoable)
 * @note $O(\log N)$
 * @note union-by-size (without path-compression)
 */
template <class CommutativeMonoid>
class union_find_tree_foldable_undoable {
    typedef typename CommutativeMonoid::value_type value_type;
    const CommutativeMonoid mon;
    std::vector<int> data;
    std::vector<value_type> value;
    std::vector<std::tuple<int, int, value_type> > history;

public:
    union_find_tree_foldable_undoable() = default;
    union_find_tree_foldable_undoable(std::size_t size, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_), data(size, -1), value(size, mon.unit()) {
    }
    template <class InputIterator>
    union_find_tree_foldable_undoable(InputIterator first, InputIterator last, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_), data(std::distance(first, last), -1), value(first, last) {
    }

    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { while (not is_root(i)) i = data[i]; return i; }
    int get_size(int i) { return - data[find_root(i)]; }
    void unite_trees(int i, int j) {
        i = find_root(i);
        j = find_root(j);
        if (get_size(i) < get_size(j)) std::swap(i, j);
        history.emplace_back(-1, 0, mon.unit());
        if (i != j) {
            history.emplace_back(i, data[i], value[i]);
            history.emplace_back(j, data[j], value[j]);
            data[i] += data[j];
            data[j] = i;
            value[i] = mon.mult(value[i], value[j]);
        }
    }
    bool is_connected(int i, int j) { return find_root(i) == find_root(j); }

    void tree_set(int i, value_type x) {
        i = find_root(i);
        history.emplace_back(-1, 0, mon.unit());
        history.emplace_back(i, data[i], value[i]);
        value[i] = x;
    }
    value_type tree_get(int i) {
        return value[find_root(i)];
    }
    /**
     * @note for unite_trees() and tree_set()
     */
    void undo() {
        while (true) {
            assert (not history.empty());
            auto [i, data_i, value_i] = history.back();
            history.pop_back();
            if (i == -1) break;
            value[i] = value_i;
            data[i] = data_i;
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/union_find_tree_foldable_undoable.hpp"
#include <cassert>
#include <tuple>
#include <utility>
#include <vector>

/**
 * @brief Union-Find Tree (foldable with commutative monoids, undoable)
 * @note $O(\log N)$
 * @note union-by-size (without path-compression)
 */
template <class CommutativeMonoid>
class union_find_tree_foldable_undoable {
    typedef typename CommutativeMonoid::value_type value_type;
    const CommutativeMonoid mon;
    std::vector<int> data;
    std::vector<value_type> value;
    std::vector<std::tuple<int, int, value_type> > history;

public:
    union_find_tree_foldable_undoable() = default;
    union_find_tree_foldable_undoable(std::size_t size, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_), data(size, -1), value(size, mon.unit()) {
    }
    template <class InputIterator>
    union_find_tree_foldable_undoable(InputIterator first, InputIterator last, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_), data(std::distance(first, last), -1), value(first, last) {
    }

    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { while (not is_root(i)) i = data[i]; return i; }
    int get_size(int i) { return - data[find_root(i)]; }
    void unite_trees(int i, int j) {
        i = find_root(i);
        j = find_root(j);
        if (get_size(i) < get_size(j)) std::swap(i, j);
        history.emplace_back(-1, 0, mon.unit());
        if (i != j) {
            history.emplace_back(i, data[i], value[i]);
            history.emplace_back(j, data[j], value[j]);
            data[i] += data[j];
            data[j] = i;
            value[i] = mon.mult(value[i], value[j]);
        }
    }
    bool is_connected(int i, int j) { return find_root(i) == find_root(j); }

    void tree_set(int i, value_type x) {
        i = find_root(i);
        history.emplace_back(-1, 0, mon.unit());
        history.emplace_back(i, data[i], value[i]);
        value[i] = x;
    }
    value_type tree_get(int i) {
        return value[find_root(i)];
    }
    /**
     * @note for unite_trees() and tree_set()
     */
    void undo() {
        while (true) {
            assert (not history.empty());
            auto [i, data_i, value_i] = history.back();
            history.pop_back();
            if (i == -1) break;
            value[i] = value_i;
            data[i] = data_i;
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

