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


# :heavy_check_mark: graph/cartesian_tree.yukicoder-1031.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/cartesian_tree.yukicoder-1031.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-21 05:29:34+09:00


* see: <a href="https://yukicoder.me/problems/no/1031">https://yukicoder.me/problems/no/1031</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/sparse_table.hpp.html">Sparse Table (idempotent monoid) <small>(data_structure/sparse_table.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/graph/cartesian_tree.hpp.html">Cartesian tree ($O(n)$) <small>(graph/cartesian_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/graph/format.hpp.html">graph/format.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/min.hpp.html">monoids/min.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/left-to-right-maxima.hpp.html">Length of Left-to-right Maxima (前処理 $O(n \log n)$ + $O(1)$) <small>(utils/left-to-right-maxima.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1031"
#include "utils/macros.hpp"
#include "graph/cartesian_tree.hpp"
#include "graph/format.hpp"
#include "utils/left-to-right-maxima.hpp"
#include <cstdio>
#include <functional>
#include <utility>
#include <vector>

#include <iostream>
using namespace std;

int64_t solve1(int n, const vector<int> & p) {
    // prepare a data structure for the sequence
    auto f = left_to_right_maxima::construct<int>(ALL(p));

    // construct the Cartesian tree
    vector<int> parent = construct_cartesian_tree(p);
    vector<vector<int> > children; int root; tie(children, root) = children_from_parent(parent);

    // fold the Cartesian tree
    int64_t ans = 0;
    auto go = [&](auto && go, int l, int m, int r) -> void {
        if (l == r) {
            return;
        }
        ans += f(m + 1, r);
        for (int x : children[m]) {
            if (x < m) {
                go(go, l, x, m);
            } else {
                go(go, m + 1, x, r);
            }
        }
    };
    go(go, 0, root, n);
    return ans;
}

int64_t solve(int n, vector<int> p) {
    int64_t ans = solve1(n, p);
    reverse(ALL(p));
    return ans + solve1(n, p);
}

int main() {
    int n; scanf("%d", &n);
    vector<int> p(n);
    REP (i, n) {
        scanf("%d", &p[i]);
    }
    long long ans = solve(n, p);
    printf("%lld\n", ans);
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/cartesian_tree.yukicoder-1031.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1031"
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 2 "graph/cartesian_tree.hpp"
#include <functional>
#include <vector>
#line 5 "graph/cartesian_tree.hpp"

/**
 * @brief Cartesian tree ($O(n)$)
 * @note the smallest value is the root
 * @note if a is not distinct, the way for tie-break is undefined
 * @return the binary tree as the list of parents
 */
template <class T, class Comparator = std::less<int> >
std::vector<int> construct_cartesian_tree(const std::vector<T> & a, const Comparator & cmp = Comparator()) {
    int n = a.size();
    std::vector<int> parent(n, -1);
    REP3 (i, 1, n) {
        int p = i - 1;  // parent of i
        int l = -1;  // left child of i
        while (p != -1 and cmp(a[i], a[p])) {
            int pp = parent[p];  // parent of parent of i
            if (l != -1) {
                parent[l] = p;
            }
            parent[p] = i;
            l = p;
            p = pp;
        }
        parent[i] = p;
    }
    return parent;
}
#line 2 "graph/format.hpp"
#include <cassert>
#include <utility>
#line 6 "graph/format.hpp"

std::pair<std::vector<std::vector<int> >, int> children_from_parent(const std::vector<int> & parent) {
    int n = parent.size();
    std::vector<std::vector<int> > children(n);
    int root = -1;
    REP (x, n) {
        if (parent[x] == -1) {
            assert (root == -1);
            root = x;
        } else {
            children[parent[x]].push_back(x);
        }
    }
    assert (root != -1);
    return std::make_pair(children, root);
}

std::vector<std::vector<int> > adjacent_list_from_children(const std::vector<std::vector<int> > & children) {
    int n = children.size();
    std::vector<std::vector<int> > g(n);
    REP (x, n) {
        for (int y : children[x]) {
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    return g;
}
#line 2 "utils/left-to-right-maxima.hpp"
#include <stack>
#include <tuple>
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
#line 2 "monoids/min.hpp"
#include <algorithm>
#include <limits>

template <class T>
struct min_monoid {
    typedef T value_type;
    value_type unit() const { return std::numeric_limits<T>::max(); }
    value_type mult(value_type a, value_type b) const { return std::min(a, b); }
};
#line 9 "utils/left-to-right-maxima.hpp"

/**
 * @brief Length of Left-to-right Maxima (前処理 $O(n \log n)$ + $O(1)$)
 * @description computes the lengths of the left-to-right maxima for the given interval
 * @note the left-to-right maxima for a sequence $a$ means the subsubsequence of the elements $a_i$ which satisfy $\forall j \lt i. a_j \lt a_i$.
 */
class left_to_right_maxima {
    std::vector<int> depth;
    sparse_table<min_monoid<int> > table;

public:
    left_to_right_maxima() = default;

    int operator () (int l, int r) const {
        assert (0 <= l and l <= r and r <= (int)depth.size());
        if (l == r) return 0;
        return depth[l] - table.range_get(l, r) + 1;
    }

private:
    left_to_right_maxima(const std::vector<int> & depth_)
            : depth(depth_), table(ALL(depth_)) {
    }

public:
    /**
     * @note this is just a constructor, but is needed to specify template arguments.
     */
    template <class T, class Comparator = std::less<T>, class RandomAccessIterator>
    static left_to_right_maxima construct(RandomAccessIterator first, RandomAccessIterator last, const Comparator & cmp = Comparator()) {
        int n = std::distance(first, last);

        // make a forest
        std::vector<int> parent(n, -1);
        std::stack<int> stk;
        REP (i, n) {
            while (not stk.empty() and cmp(*(first + stk.top()), *(first + i))) {
                parent[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        // calculate depths
        std::vector<int> depth(n);
        REP_R (i, n) {
            if (parent[i] != -1) {
                depth[i] = depth[parent[i]] + 1;
            }
        }

        return left_to_right_maxima(depth);
    }
};
#line 6 "graph/cartesian_tree.yukicoder-1031.test.cpp"
#include <cstdio>
#line 10 "graph/cartesian_tree.yukicoder-1031.test.cpp"

#include <iostream>
using namespace std;

int64_t solve1(int n, const vector<int> & p) {
    // prepare a data structure for the sequence
    auto f = left_to_right_maxima::construct<int>(ALL(p));

    // construct the Cartesian tree
    vector<int> parent = construct_cartesian_tree(p);
    vector<vector<int> > children; int root; tie(children, root) = children_from_parent(parent);

    // fold the Cartesian tree
    int64_t ans = 0;
    auto go = [&](auto && go, int l, int m, int r) -> void {
        if (l == r) {
            return;
        }
        ans += f(m + 1, r);
        for (int x : children[m]) {
            if (x < m) {
                go(go, l, x, m);
            } else {
                go(go, m + 1, x, r);
            }
        }
    };
    go(go, 0, root, n);
    return ans;
}

int64_t solve(int n, vector<int> p) {
    int64_t ans = solve1(n, p);
    reverse(ALL(p));
    return ans + solve1(n, p);
}

int main() {
    int n; scanf("%d", &n);
    vector<int> p(n);
    REP (i, n) {
        scanf("%d", &p[i]);
    }
    long long ans = solve(n, p);
    printf("%lld\n", ans);
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

