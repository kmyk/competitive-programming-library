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


# :heavy_check_mark: Dynamic Connectivity (offline, commutative monoids) <small>(data_structure/dynamic_connectivity_offline.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/dynamic_connectivity_offline.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-08 04:11:51+09:00




## Operations

単純無向グラフ $G = (V, E)$ であって頂点 $x \in V$ に可換 monoid $M = (M, +, 0)$ による重み $a_x \in M$ が付いたものに対し、次のクエリが offline で全体で $O(Q \log Q)$ で処理可能:

-   $\mathtt{link}(x, y)$: 頂点 $x, y$ 間に辺 $\lbrace x, y \rbrace$ を追加する。
-   $\mathtt{cut}(x, y)$: 頂点 $x, y$ 間から辺 $\lbrace x, y \rbrace$ を削除する。
-   $\mathtt{point\unicode{95}set}(x, b)$: 頂点 $x$ の重みを $a_x \gets b$ と更新する。
-   $\mathtt{point\unicode{95}mult}(x, b)$: 頂点 $x$ の重みを $a_x \gets a_x + b$ と更新する。
-   $\mathtt{component\unicode{95}get}(x)$: 頂点 $x$ と同じ連結成分 $C \subseteq V$ に所属する頂点の重みの総和 $\sum _ {x \in C} a_x$ を計算する。

ただし offline であるので、計算結果は最後に $\mathtt{run}()$ を呼ぶことで取得する。


## Depends on

* :heavy_check_mark: <a href="reporting_segment_tree.hpp.html">Dual Segment Tree / 双対セグメント木 (列挙クエリ, 完全二分木) <small>(data_structure/reporting_segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="union_find_tree_foldable_undoable.hpp.html">Union-Find Tree (foldable with commutative monoids, undoable) <small>(data_structure/union_find_tree_foldable_undoable.hpp)</small></a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp.html">data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <optional>
#include <tuple>
#include <vector>
#include "data_structure/union_find_tree_foldable_undoable.hpp"
#include "data_structure/reporting_segment_tree.hpp"
#include "utils/macros.hpp"

/**
 * @brief Dynamic Connectivity (offline, commutative monoids)
 * @docs data_structure/dynamic_connectivity_offline.md
 */
template <class CommutativeMonoid>
class dynamic_connectivity_offline {
    typedef typename CommutativeMonoid::value_type value_type;
    enum query_tag {
        LINK,
        ADD,
    };
    struct query_type {
        query_tag tag;
        int l, r;
        int a;
        int64_t b;
    };

    const CommutativeMonoid mon;
    int size;
    int time;
    std::vector<query_type> set_queries;
    std::vector<std::pair<int, int> > get_queries;
    std::map<std::pair<int, int>, int> current_edges;
    std::vector<std::vector<std::pair<int, value_type> > > current_values;

    void flush_time() {
        if (not get_queries.empty() and get_queries.back().first == time) {
            ++ time;
        }
    }

public:
    /**
     * @arg size is the number of vertices
     */
    dynamic_connectivity_offline(int size_, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_) {
        size = size_;
        time = 0;
        current_values.resize(size);
    }
    void link(int x, int y) {
        flush_time();
        auto edge = std::minmax({ x, y });
        assert (not current_edges.count(edge));
        current_edges[edge] = time;
    }
    void cut(int x, int y) {
        flush_time();
        auto edge = std::minmax({ x, y });
        assert (current_edges.count(edge));
        set_queries.emplace_back((query_type) {
            LINK,
            current_edges[edge],
            time,
            edge.first,
            edge.second,
        });
        current_edges.erase(edge);
    }
    void point_set(int x, value_type value) {
        flush_time();
        while (not current_values[x].empty()) {
            auto [l, value_] = current_values[x].back();
            current_values[x].pop_back();
            set_queries.emplace_back((query_type) {
                ADD,
                l,
                time,
                x,
                value_,
            });
        }
        current_values[x].emplace_back(time, value);
    }
    void point_mult(int x, value_type value) {
        flush_time();
        current_values[x].emplace_back(time, value);
    }
    void component_get(int x) {
        get_queries.emplace_back(time, x);
    }

    /**
     * @note $O(Q \log Q)$
     */
    std::vector<value_type> run() {
        std::vector<value_type> results;
        auto it = get_queries.begin();

        // close half-open queries
        int current_size = set_queries.size();
        for (auto [edge, l] : current_edges) {
            set_queries.emplace_back((query_type) {
                LINK,
                l,
                time + 1,
                edge.first,
                edge.second,
            });
        }
        REP (x, size) {
            for (auto [l, value] : current_values[x]) {
                set_queries.emplace_back((query_type) {
                    ADD,
                    l,
                    time + 1,
                    x,
                    value,
                });
            }
        }

        // prepare undoable union-find tree
        union_find_tree_foldable_undoable<CommutativeMonoid> uft(size, mon);
        auto add = [&](int i) {
            auto & q = set_queries[i];
            if (q.tag == LINK) {
                uft.unite_trees(q.a, q.b);
            } else if (q.tag == ADD) {
                uft.tree_set(q.a, mon.mult(uft.tree_get(q.a), q.b));
            } else {
                assert (false);
            }
        };
        auto remove = [&](int i) {
            uft.undo();
        };
        auto report = [&](int t) {
            for (; it != get_queries.end() and it->first == t; ++ it) {
                int x = it->second;
                results.push_back(uft.tree_get(x));
            }
        };

        // use segment trees on time-axis for queries
        reporting_segment_tree<int> segtree(time + 1);
        REP (i, set_queries.size()) {
            auto & q = set_queries[i];
            segtree.add_segment(q.l, q.r, i);
        }
        segtree.traverse_segments(add, remove, report);

        // re-open closed queries
        set_queries.resize(current_size);

        assert (it == get_queries.end());
        return results;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/dynamic_connectivity_offline.hpp"
#include <algorithm>
#include <cassert>
#include <map>
#include <optional>
#include <tuple>
#include <vector>
#line 4 "data_structure/union_find_tree_foldable_undoable.hpp"
#include <utility>
#line 6 "data_structure/union_find_tree_foldable_undoable.hpp"

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
#line 4 "data_structure/reporting_segment_tree.hpp"
#include <functional>
#include <type_traits>
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
#line 11 "data_structure/dynamic_connectivity_offline.hpp"

/**
 * @brief Dynamic Connectivity (offline, commutative monoids)
 * @docs data_structure/dynamic_connectivity_offline.md
 */
template <class CommutativeMonoid>
class dynamic_connectivity_offline {
    typedef typename CommutativeMonoid::value_type value_type;
    enum query_tag {
        LINK,
        ADD,
    };
    struct query_type {
        query_tag tag;
        int l, r;
        int a;
        int64_t b;
    };

    const CommutativeMonoid mon;
    int size;
    int time;
    std::vector<query_type> set_queries;
    std::vector<std::pair<int, int> > get_queries;
    std::map<std::pair<int, int>, int> current_edges;
    std::vector<std::vector<std::pair<int, value_type> > > current_values;

    void flush_time() {
        if (not get_queries.empty() and get_queries.back().first == time) {
            ++ time;
        }
    }

public:
    /**
     * @arg size is the number of vertices
     */
    dynamic_connectivity_offline(int size_, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_) {
        size = size_;
        time = 0;
        current_values.resize(size);
    }
    void link(int x, int y) {
        flush_time();
        auto edge = std::minmax({ x, y });
        assert (not current_edges.count(edge));
        current_edges[edge] = time;
    }
    void cut(int x, int y) {
        flush_time();
        auto edge = std::minmax({ x, y });
        assert (current_edges.count(edge));
        set_queries.emplace_back((query_type) {
            LINK,
            current_edges[edge],
            time,
            edge.first,
            edge.second,
        });
        current_edges.erase(edge);
    }
    void point_set(int x, value_type value) {
        flush_time();
        while (not current_values[x].empty()) {
            auto [l, value_] = current_values[x].back();
            current_values[x].pop_back();
            set_queries.emplace_back((query_type) {
                ADD,
                l,
                time,
                x,
                value_,
            });
        }
        current_values[x].emplace_back(time, value);
    }
    void point_mult(int x, value_type value) {
        flush_time();
        current_values[x].emplace_back(time, value);
    }
    void component_get(int x) {
        get_queries.emplace_back(time, x);
    }

    /**
     * @note $O(Q \log Q)$
     */
    std::vector<value_type> run() {
        std::vector<value_type> results;
        auto it = get_queries.begin();

        // close half-open queries
        int current_size = set_queries.size();
        for (auto [edge, l] : current_edges) {
            set_queries.emplace_back((query_type) {
                LINK,
                l,
                time + 1,
                edge.first,
                edge.second,
            });
        }
        REP (x, size) {
            for (auto [l, value] : current_values[x]) {
                set_queries.emplace_back((query_type) {
                    ADD,
                    l,
                    time + 1,
                    x,
                    value,
                });
            }
        }

        // prepare undoable union-find tree
        union_find_tree_foldable_undoable<CommutativeMonoid> uft(size, mon);
        auto add = [&](int i) {
            auto & q = set_queries[i];
            if (q.tag == LINK) {
                uft.unite_trees(q.a, q.b);
            } else if (q.tag == ADD) {
                uft.tree_set(q.a, mon.mult(uft.tree_get(q.a), q.b));
            } else {
                assert (false);
            }
        };
        auto remove = [&](int i) {
            uft.undo();
        };
        auto report = [&](int t) {
            for (; it != get_queries.end() and it->first == t; ++ it) {
                int x = it->second;
                results.push_back(uft.tree_get(x));
            }
        };

        // use segment trees on time-axis for queries
        reporting_segment_tree<int> segtree(time + 1);
        REP (i, set_queries.size()) {
            auto & q = set_queries[i];
            segtree.add_segment(q.l, q.r, i);
        }
        segtree.traverse_segments(add, remove, report);

        // re-open closed queries
        set_queries.resize(current_size);

        assert (it == get_queries.end());
        return results;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

