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


# :heavy_check_mark: utils/dsu_on_tree.aoj.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/dsu_on_tree.aoj.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/union_find_tree_with_monoid.hpp.html">a disjoint set structure with monoid <small>(data_structure/union_find_tree_with_monoid.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/graph/subtree.hpp.html">subtree info / それぞれの部分木の size とか height とかをまとめて求めておいてくれるやつ <small>(graph/subtree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/hack/stack_pivot.hpp.html">hack/stack_pivot.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/plus.hpp.html">monoids/plus.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/dsu_on_tree.hpp.html">DSU on tree (sack) <small>(utils/dsu_on_tree.hpp)</small></a>
* :question: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995"
#include "utils/dsu_on_tree.hpp"
#include "data_structure/union_find_tree_with_monoid.hpp"
#include "monoids/plus.hpp"
#include "hack/stack_pivot.hpp"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "utils/macros.hpp"
using namespace std;

vector<int> solve(int n, int k, const vector<vector<int> > & g, const vector<int> & c, const vector<int> & d) {
    union_find_tree_with_monoid<plus_monoid<int> > uft(k);
    unordered_set<int> used;
    int value = 0;
    auto func = [&](int e) {
        return min(uft.tree_size(e), uft.get_value(e));
    };

    auto add = [&](int i) {
        int c_i = uft.find_root(c[i]);
        int d_i = uft.find_root(d[i]);
        if (c_i == d_i) {
            value -= func(c_i);
            uft.set_value(c_i, uft.get_value(c_i) + 1);
            value += func(c_i);
        } else {
            value -= func(c_i);
            value -= func(d_i);
            uft.unite_trees(c_i, d_i);
            if (not uft.is_root(c_i)) {
                swap(c_i, d_i);
            }
            uft.set_value(c_i, uft.get_value(c_i) + 1);
            value += func(c_i);
        }
        used.insert(c_i);
        used.insert(d_i);
    };
    auto reset = [&](int i) {
        if (used.empty()) return;
        for (int e : used) {
            uft.data[e] = -1;
            uft.value[e] = 0;
        }
        used.clear();
        value = 0;
    };

    vector<int> answer(n, -1);
    auto callback = [&](int i) {
        answer[i] = value;
    };

    constexpr int root = 0;
    dsu_on_tree(g, root, add, reset, callback);
    return answer;
}

int moin() {
    // input
    int n, k; cin >> n >> k;
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int u, v; cin >> u >> v;
        -- u;
        -- v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> c(n);
    vector<int> d(n);
    REP (i, n) {
        cin >> c[i] >> d[i];
        -- c[i];
        -- d[i];
    }

    // solve
    auto answer = solve(n, k, g, c, d);

    // output
    REP (i, n) {
        cout << answer[i] << endl;
    }
    return 0;
}

STACK_PIVOT_MAIN(moin)

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/dsu_on_tree.aoj.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995"
#line 2 "utils/dsu_on_tree.hpp"
#include <functional>
#include <stack>
#include <vector>
#line 2 "graph/subtree.hpp"
#include <algorithm>
#line 4 "graph/subtree.hpp"

struct subtree_info_t {
    int parent;  // in the entire tree
    int depth;  // in the entire tree
    int size;  // of the subtree
    int height;  // of the subtree
};

/**
 * @brief subtree info / それぞれの部分木の size とか height とかをまとめて求めておいてくれるやつ
 * @arg g must be a tree
 * @note O(n) time
 * @note O(n) space on heap
 */
std::vector<subtree_info_t> prepare_subtree_info(std::vector<std::vector<int> > const & g, int root) {
    int n = g.size();
    std::vector<subtree_info_t> info(n, (subtree_info_t) { -1, -1, -1, -1 });
    std::vector<int> topological(n);
    topological[0] = root;
    info[root].parent = root;
    info[root].depth = 0;
    int r = 1;
    for (int l = 0; l < r; ++ l) {
        int i = topological[l];
        for (int j : g[i]) if (j != info[i].parent) {
            topological[r ++] = j;
            info[j].parent = i;
            info[j].depth = info[i].depth + 1;
        }
    }
    while ((-- r) >= 0) {
        int i = topological[r];
        info[i].size = 1;
        info[i].height = 0;
        for (int j : g[i]) if (j != info[i].parent) {
            info[i].size += info[j].size;
            info[i].height = std::max(info[i].height, info[j].height + 1);
        }
    }
    info[root].parent = -1;
    return info;
}
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 7 "utils/dsu_on_tree.hpp"

/**
 * @brief DSU on tree (sack)
 * @arg g is a tree
 * @arg root
 * @arg add is a function object which takes a index of a vertex
 * @arg sub is a function object which takes a index of a vertex
 * @arg callback is a function object which takes a index of a vertex
 * @note for each x, add(x) and sub(x) are called O(log n) times
 * @note O(n log n) if add, sub, and callback are O(1)
 * @see https://codeforces.com/blog/entry/44351
 * @note sub(x) can be implemented as reset(), because sub(x) is called until it becomes empty after sub(x) is called once
 */
template <class Add, class Sub, class Callback>
void dsu_on_tree(const std::vector<std::vector<int> > & g, int root, Add & add, Sub & sub, Callback & callback) {
    auto info = prepare_subtree_info(g, root);
    auto subtree_apply = [&](int x, auto & f) {
        std::stack<int> stk;
        stk.push(x);
        while (not stk.empty()) {
            int y = stk.top();
            stk.pop();
            f(y);
            for (int z : g[y]) if (z != info[y].parent) {
                stk.push(z);
            }
        }
    };
    std::function<void (int, bool)> go = [&](int x, bool keep) {
        // leaf
        if (info[x].size == 1) {
            add(x);
            callback(x);
            if (not keep) {
                sub(x);
            }
            return;
        }
        // choose the heavy child
        int z = *max_element(ALL(g[x]), [&](int y1, int y2) {
            int size1 = (y1 == info[x].parent ? -1 : info[y1].size);
            int size2 = (y2 == info[x].parent ? -1 : info[y2].size);
            return size1 < size2;
        });
        // go light
        for (int y : g[x]) if (y != info[x].parent) {
            if (y != z) {
                go(y, false);
            }
        }
        // go heavy
        go(z, true);
        for (int y : g[x]) if (y != info[x].parent) {
            if (y != z) {
                subtree_apply(y, add);
            }
        }
        add(x);
        callback(x);
        if (not keep) {
            subtree_apply(x, sub);
        }
    };
    go(root, false);
}
#line 3 "data_structure/union_find_tree_with_monoid.hpp"

/**
 * @brief a disjoint set structure with monoid
 * @note union-by-size + path-compression
 */
template <class Monoid>
struct union_find_tree_with_monoid {
    typedef typename Monoid::value_type value_type;
    const Monoid mon;
    std::vector<int> data;
    std::vector<value_type> value;

    union_find_tree_with_monoid() = default;
    union_find_tree_with_monoid(std::size_t n, Monoid const & mon_ = Monoid()) : mon(mon_), data(n, -1), value(n, mon.unit()) {}
    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }
    int tree_size(int i) { return - data[find_root(i)]; }
    int unite_trees(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (tree_size(i) < tree_size(j)) std::swap(i, j);
            data[i] += data[j];
            data[j] = i;
            value[i] = mon.mult(value[i], value[j]);
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
    value_type get_value(int i) { return value[find_root(i)]; }
    void set_value(int i, value_type z) { value[find_root(i)] = z; }
};
#line 2 "monoids/plus.hpp"

template <class T>
struct plus_monoid {
    typedef T value_type;
    value_type unit() const { return value_type(); }
    value_type mult(value_type a, value_type b) const { return a + b; }
};
#line 2 "hack/stack_pivot.hpp"
#include <cstdlib>

/**
 * @note This is a workaround for WSL. We cannot use ulimit -s unlimited on the environment.
 * @note To use such techniques, you should take care of the alignment of rsp. If not, you'll get SIGSEGV around XMM registers.
 */

#define BEGIN_STACK_PIVOT(STACK_SIZE) \
    static volatile char *old_stack; \
    asm volatile("mov %%rsp, %0" : "=r" (old_stack) ); \
    char *new_stack = ((char *)malloc(STACK_SIZE) + (STACK_SIZE) - 0x10); \
    asm volatile("mov %0, %%rsp" : : "r" (new_stack) );

#define END_STACK_PIVOT() \
    asm volatile("mov %0, %%rsp" : : "r" (old_stack) );

#define STACK_PIVOT_MAIN(moin) \
    int main() { \
        BEGIN_STACK_PIVOT(1 << 28) \
        static int returncode = moin(); \
        END_STACK_PIVOT() \
        return returncode; \
    }
#line 6 "utils/dsu_on_tree.aoj.test.cpp"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#line 11 "utils/dsu_on_tree.aoj.test.cpp"
using namespace std;

vector<int> solve(int n, int k, const vector<vector<int> > & g, const vector<int> & c, const vector<int> & d) {
    union_find_tree_with_monoid<plus_monoid<int> > uft(k);
    unordered_set<int> used;
    int value = 0;
    auto func = [&](int e) {
        return min(uft.tree_size(e), uft.get_value(e));
    };

    auto add = [&](int i) {
        int c_i = uft.find_root(c[i]);
        int d_i = uft.find_root(d[i]);
        if (c_i == d_i) {
            value -= func(c_i);
            uft.set_value(c_i, uft.get_value(c_i) + 1);
            value += func(c_i);
        } else {
            value -= func(c_i);
            value -= func(d_i);
            uft.unite_trees(c_i, d_i);
            if (not uft.is_root(c_i)) {
                swap(c_i, d_i);
            }
            uft.set_value(c_i, uft.get_value(c_i) + 1);
            value += func(c_i);
        }
        used.insert(c_i);
        used.insert(d_i);
    };
    auto reset = [&](int i) {
        if (used.empty()) return;
        for (int e : used) {
            uft.data[e] = -1;
            uft.value[e] = 0;
        }
        used.clear();
        value = 0;
    };

    vector<int> answer(n, -1);
    auto callback = [&](int i) {
        answer[i] = value;
    };

    constexpr int root = 0;
    dsu_on_tree(g, root, add, reset, callback);
    return answer;
}

int moin() {
    // input
    int n, k; cin >> n >> k;
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int u, v; cin >> u >> v;
        -- u;
        -- v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> c(n);
    vector<int> d(n);
    REP (i, n) {
        cin >> c[i] >> d[i];
        -- c[i];
        -- d[i];
    }

    // solve
    auto answer = solve(n, k, g, c, d);

    // output
    REP (i, n) {
        cout << answer[i] << endl;
    }
    return 0;
}

STACK_PIVOT_MAIN(moin)

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

