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


# :heavy_check_mark: old/rollback-square-decomposition.yukicoder-1031.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/rollback-square-decomposition.yukicoder-1031.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-17 23:46:14+09:00


* see: <a href="https://yukicoder.me/problems/no/1031">https://yukicoder.me/problems/no/1031</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/segment_tree.hpp.html">Segment Tree / セグメント木 (monoids, 完全二分木) <small>(data_structure/segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/data_structure/sparse_table.hpp.html">Sparse Table (idempotent monoid) <small>(data_structure/sparse_table.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/monoids/max.hpp.html">monoids/max.hpp</a>
* :heavy_check_mark: <a href="../../library/old/rollback-square-decomposition.inc.cpp.html">the extended Mo's algorithm <small>(old/rollback-square-decomposition.inc.cpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1031"
#include "utils/macros.hpp"
#include "data_structure/sparse_table.hpp"
#include "data_structure/segment_tree.hpp"
#include "monoids/max.hpp"
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <optional>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#include "old/rollback-square-decomposition.inc.cpp"

template <class T>
struct rollbackable_deque {
    deque<T> data;
    vector<pair<char, optional<T> > > history;
    rollbackable_deque() = default;
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
    T operator [] (size_t i) const { return data[i]; }
    const T & front() const { return data.front(); }
    const T & back() const { return data.back(); }
    void push_front(T value) {
        history.emplace_back('f', optional<T>());
        data.push_front(value);
    }
    void pop_front() {
        history.emplace_back('F', data.front());
        data.pop_front();
    }
    void push_back(T value) {
        history.emplace_back('b', optional<T>());
        data.push_back(value);
    }
    void pop_back() {
        history.emplace_back('B', data.back());
        data.pop_back();
    }
    void snapshot() {
        history.emplace_back('$', optional<T>());
    }
    void rollback() {
        while (history.back().first != '$') {
            char op = history.back().first;
            optional<T> value = history.back().second;
            history.pop_back();
            if (op == 'f') {
                data.pop_front();
            } else if (op == 'F') {
                data.push_front(*value);
            } else if (op == 'b') {
                data.pop_back();
            } else if (op == 'B') {
                data.push_back(*value);
            }
        }
        history.pop_back();
    }
};

struct rollback_mo_inc {
    const vector<int> & p;
    int64_t & ans;
    int l, r;
    vector<pair<int, int> > history;
    rollbackable_deque<int> deq;
    rollback_mo_inc(const vector<int> & p_, int64_t & ans_) : p(p_), ans(ans_) {
        reset(0);
    }
    void reset(int l_) {
        l = l_;
        r = l_;
        history.clear();
        deq = rollbackable_deque<int>();
    }
    void extend_left(int nl, int r) {
        for (; nl < l; -- l) {
            if (deq.empty() or p[l - 1] < deq.front()) {
                deq.push_front(p[l - 1]);
            }
        }
    }
    void extend_right(int l, int nr) {
        for (; r < nr; ++ r) {
            while (not deq.empty() and p[r] < deq.back()) {
                deq.pop_back();
            }
            deq.push_back(p[r]);
        }
    }
    void snapshot() {
        deq.snapshot();
        history.emplace_back(l, r);
    }
    void rollback() {
        deq.rollback();
        tie(l, r) = history.back();
        history.pop_back();
    }
    void query() {
        ans += deq.size();
    }
};

int64_t solve1(int n, const vector<int> & p) {
    vector<pair<int, int> > query_inc;
    vector<int> lookup(n);
    REP (i, n) {
        lookup[p[i]] = i;
    }
    sparse_table<max_monoid<int> > table(ALL(p));
    function<void (int, int)> go = [&](int l, int r) {
        if (r - l < 2) return;
        int m = lookup[table.range_get(l, r)];
        query_inc.emplace_back(l, m);
        go(l, m);
        go(m + 1, r);
    };
    go(0, n);

    int64_t ans = 0;
    rollback_mo_inc interface_inc(p, ans);
    rollback_square_decomposition(n, query_inc, interface_inc, [&](int l, int r) {
        int last = INT_MAX;
        REP3R (i, l, r) {
            if (p[i] < last) {
                last = p[i];
                ++ ans;
            }
        }
    });
    return ans;
}

int64_t solve(int n, vector<int> p) {
    int64_t ans = solve1(n, p);
    reverse(ALL(p));
    return ans + solve1(n, p);
}

// generated by online-judge-template-generator v4.1.0 (https://github.com/kmyk/online-judge-template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    constexpr char endl = '\n';
    int N;
    cin >> N;
    vector<int> p(N);
    REP (i, N) {
        cin >> p[i];
        -- p[i];
    }
    auto ans = solve(N, p);
    cout << ans << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/rollback-square-decomposition.yukicoder-1031.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1031"
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 2 "data_structure/sparse_table.hpp"
#include <cassert>
#include <vector>
#line 5 "data_structure/sparse_table.hpp"

/**
 * @brief Sparse Table (idempotent monoid)
 * @note the unit is required just for convenience
 * @note $O(N \log N)$ space
 */
template <class IdempotentMonoid>
struct sparse_table {
    typedef typename IdempotentMonoid::value_type value_type;
    std::vector<std::vector<value_type> > table;
    IdempotentMonoid mon;
    sparse_table() = default;

    /**
     * @note $O(N \log N)$ time
     */
    template <class InputIterator>
    sparse_table(InputIterator first, InputIterator last, const IdempotentMonoid & mon_ = IdempotentMonoid())
            : mon(mon_) {
        table.emplace_back(first, last);
        int n = table[0].size();
        int log_n = 32 - __builtin_clz(n);
        table.resize(log_n, std::vector<value_type>(n));
        REP (k, log_n - 1) {
            REP (i, n) {
                table[k + 1][i] = i + (1ll << k) < n ?
                    mon.mult(table[k][i], table[k][i + (1ll << k)]) :
                    table[k][i];
            }
        }
    }

    /**
     * @note $O(1)$
     */
    value_type range_get(int l, int r) const {
        if (l == r) return mon.unit();  // if there is no unit, remove this line
        assert (0 <= l and l < r and r <= (int)table[0].size());
        int k = 31 - __builtin_clz(r - l);  // log2
        return mon.mult(table[k][l], table[k][r - (1ll << k)]);
    }
};
#line 2 "data_structure/segment_tree.hpp"
#include <algorithm>
#line 6 "data_structure/segment_tree.hpp"

/**
 * @brief Segment Tree / セグメント木 (monoids, 完全二分木)
 * @docs data_structure/segment_tree.md
 * @tparam Monoid (commutativity is not required)
 */
template <class Monoid>
struct segment_tree {
    typedef typename Monoid::value_type value_type;
    const Monoid mon;
    int n;
    std::vector<value_type> a;
    segment_tree() = default;
    segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1, mon.unit());
    }
    void point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
        for (i = (i + n) / 2; i > 0; i /= 2) {  // 1-based
            a[i - 1] = mon.mult(a[2 * i - 1], a[2 * i]);
        }
    }
    value_type range_get(int l, int r) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        value_type lacc = mon.unit(), racc = mon.unit();
        for (l += n, r += n; l < r; l /= 2, r /= 2) {  // 1-based loop, 2x faster than recursion
            if (l % 2 == 1) lacc = mon.mult(lacc, a[(l ++) - 1]);
            if (r % 2 == 1) racc = mon.mult(a[(-- r) - 1], racc);
        }
        return mon.mult(lacc, racc);
    }

    value_type point_get(int i) {  // 0-based
        assert (0 <= i and i < n);
        return a[i + n - 1];
    }

    /**
     * @brief a fast & semigroup-friendly version constructor
     * @note $O(n)$
     */
    template <class InputIterator>
    segment_tree(InputIterator first, InputIterator last, const Monoid & mon_ = Monoid()) : mon(mon_) {
        int size = std::distance(first, last);
        n = 1; while (n < size) n *= 2;
        a.resize(2 * n - 1, mon.unit());
        std::copy(first, last, a.begin() + (n - 1));
        unsafe_rebuild();
    }
    /**
     * @brief update a leaf node without updating ancestors
     * @note $O(1)$
     */
    void unsafe_point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
    }
    /**
     * @brief re-build non-leaf nodes from leaf nodes
     * @note $O(n)$
     */
    void unsafe_rebuild() {
        REP_R (i, n - 1) {
            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }
};
#line 3 "monoids/max.hpp"
#include <limits>

template <class T>
struct max_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::lowest(); }
    value_type mult(value_type a, value_type b) const { return std::max(a, b); }
};
#line 6 "old/rollback-square-decomposition.yukicoder-1031.test.cpp"
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <optional>
#include <tuple>
#include <utility>
#line 15 "old/rollback-square-decomposition.yukicoder-1031.test.cpp"
using namespace std;
#line 1 "old/rollback-square-decomposition.inc.cpp"
/**
 * @brief the extended Mo's algorithm
 * @arg stupid is called O(Q) times, each length is O(\sqrt{N})
 * @arg mo si the following:
 *     struct rollback_mo_interface {
 *         void reset(int l);  // called O(N) times
 *         void extend_left( int l, int r);  // called O(Q) times, the sum of length is O(N \sqrt {N})
 *         void extend_right(int l, int r);  // called O(Q) times, the sum of length is O(Q \sqrt {N})
 *         void snapshot();  // called O(Q) times
 *         void rollback();  // called O(Q) times
 *         void query();     // called O(Q) times
 *     };
 * @see http://snuke.hatenablog.com/entry/2016/07/01/000000
 * @see http://codeforces.com/blog/entry/7383?#comment-161520
 */
template <class Func, class RollbackMoInterface>
void rollback_square_decomposition(int n, vector<pair<int, int> > const & range, RollbackMoInterface & mo, Func stupid) {
    int bucket_size = sqrt(n);
    int bucket_count = (n + bucket_size - 1) / bucket_size;
    vector<vector<int> > bucket(bucket_count);
    REP (i, int(range.size())) {
        int l, r; tie(l, r) = range[i];
        if (r - l <= bucket_size) {
            stupid(l, r);
        } else {
            bucket[l / bucket_size].push_back(i);
        }
    }
    REP (b, bucket_count) {
        sort(ALL(bucket[b]), [&](int i, int j) { return range[i].second < range[j].second; });
        int l = (b + 1) * bucket_size;
        mo.reset(l);
        int r = l;
        for (int i : bucket[b]) {
            int l_i, r_i; tie(l_i, r_i) = range[i];
            mo.extend_right(r, r_i);
            mo.snapshot();
            mo.extend_left(l_i, l);
            mo.query();
            mo.rollback();
            r = r_i;
        }
    }
}
#line 17 "old/rollback-square-decomposition.yukicoder-1031.test.cpp"

template <class T>
struct rollbackable_deque {
    deque<T> data;
    vector<pair<char, optional<T> > > history;
    rollbackable_deque() = default;
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
    T operator [] (size_t i) const { return data[i]; }
    const T & front() const { return data.front(); }
    const T & back() const { return data.back(); }
    void push_front(T value) {
        history.emplace_back('f', optional<T>());
        data.push_front(value);
    }
    void pop_front() {
        history.emplace_back('F', data.front());
        data.pop_front();
    }
    void push_back(T value) {
        history.emplace_back('b', optional<T>());
        data.push_back(value);
    }
    void pop_back() {
        history.emplace_back('B', data.back());
        data.pop_back();
    }
    void snapshot() {
        history.emplace_back('$', optional<T>());
    }
    void rollback() {
        while (history.back().first != '$') {
            char op = history.back().first;
            optional<T> value = history.back().second;
            history.pop_back();
            if (op == 'f') {
                data.pop_front();
            } else if (op == 'F') {
                data.push_front(*value);
            } else if (op == 'b') {
                data.pop_back();
            } else if (op == 'B') {
                data.push_back(*value);
            }
        }
        history.pop_back();
    }
};

struct rollback_mo_inc {
    const vector<int> & p;
    int64_t & ans;
    int l, r;
    vector<pair<int, int> > history;
    rollbackable_deque<int> deq;
    rollback_mo_inc(const vector<int> & p_, int64_t & ans_) : p(p_), ans(ans_) {
        reset(0);
    }
    void reset(int l_) {
        l = l_;
        r = l_;
        history.clear();
        deq = rollbackable_deque<int>();
    }
    void extend_left(int nl, int r) {
        for (; nl < l; -- l) {
            if (deq.empty() or p[l - 1] < deq.front()) {
                deq.push_front(p[l - 1]);
            }
        }
    }
    void extend_right(int l, int nr) {
        for (; r < nr; ++ r) {
            while (not deq.empty() and p[r] < deq.back()) {
                deq.pop_back();
            }
            deq.push_back(p[r]);
        }
    }
    void snapshot() {
        deq.snapshot();
        history.emplace_back(l, r);
    }
    void rollback() {
        deq.rollback();
        tie(l, r) = history.back();
        history.pop_back();
    }
    void query() {
        ans += deq.size();
    }
};

int64_t solve1(int n, const vector<int> & p) {
    vector<pair<int, int> > query_inc;
    vector<int> lookup(n);
    REP (i, n) {
        lookup[p[i]] = i;
    }
    sparse_table<max_monoid<int> > table(ALL(p));
    function<void (int, int)> go = [&](int l, int r) {
        if (r - l < 2) return;
        int m = lookup[table.range_get(l, r)];
        query_inc.emplace_back(l, m);
        go(l, m);
        go(m + 1, r);
    };
    go(0, n);

    int64_t ans = 0;
    rollback_mo_inc interface_inc(p, ans);
    rollback_square_decomposition(n, query_inc, interface_inc, [&](int l, int r) {
        int last = INT_MAX;
        REP3R (i, l, r) {
            if (p[i] < last) {
                last = p[i];
                ++ ans;
            }
        }
    });
    return ans;
}

int64_t solve(int n, vector<int> p) {
    int64_t ans = solve1(n, p);
    reverse(ALL(p));
    return ans + solve1(n, p);
}

// generated by online-judge-template-generator v4.1.0 (https://github.com/kmyk/online-judge-template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    constexpr char endl = '\n';
    int N;
    cin >> N;
    vector<int> p(N);
    REP (i, N) {
        cin >> p[i];
        -- p[i];
    }
    auto ans = solve(N, p);
    cout << ans << endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

