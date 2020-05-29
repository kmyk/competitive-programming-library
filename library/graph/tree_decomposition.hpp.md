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


# :heavy_check_mark: 木分解 (木幅 $t \le 2$) <small>(graph/tree_decomposition.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/tree_decomposition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-21 10:52:58+09:00


* see: <a href="https://ei1333.hateblo.jp/entry/2020/02/12/150319">https://ei1333.hateblo.jp/entry/2020/02/12/150319</a>


## 説明

ある (根付きではなく) 頂点に集合重みの付いた木 $T = (I, F; X)$ が無向グラフ $G = (V, E)$ の a tree decomposition であるとは、次をすべて満たすことをいう。

1.  頂点 $i \in I$ の重みは $G$ の頂点の部分集合である $X_i \subseteq V$
1.  任意の辺 $(u, v) \in E$ に対し、ある $i \in I$ が存在し、$u \in X_i$ かつ $v \in X_i$ である
1.  任意の頂点 $v \in V$ に対し、頂点の集合 $\lbrace i \in I \mid v \in X_i \rbrace$ は $T$ 上で連結

a tree decomposition $T = (I, F; X)$ の幅とは、その頂点の要素数の最大値 $\max \lbrace \unicode{35} X \mid X \in I \rbrace$ のことをいう。
無向グラフの木幅とは、その tree decompositions の幅の最大値のことをいう。

木幅 $t = 2$ が分かっていれば、a tree decomposition は次を再帰的に行うことで構成できる。

1.  次数 $2$ 以下の頂点 $v$ を好きに選ぶ。
1.  頂点 $v$ および頂点 $v$ に接続する辺をすべて取り除き (もしあれば) $v$ に隣接していた頂点間に辺を付け加えてできるグラフ $G'$ を考える。
1.  $G'$ に対する a tree decomposition $T$ を求める。
1.  (2.) で取り除いた辺に含まれる頂点を重み $X_i$ とするような頂点 $i$ を $T$ に追加し、$v$ に隣接していた頂点すべてを重みとして含むような頂点の子とする。

頂点に集合重みの付いた根付き木 $T = (I, F; i, X)$ が nice であるとは、おおまかには次のようにして帰納的に定められる。

1.  (leaf): 頂点数 $1$ でその唯一の頂点 $i$ の重みの要素数 $\unicode{35} X_i$ が $1$ な根付き木は nice である
1.  (introduce): nice な根付き木の根 $i$ の上に $X _ {i'} = X_i \cup \lbrace y \rbrace$ な新しい根を付け加えてできる根付き木は nice である
1.  (forget): nice な根付き木の根 $i$ の上に $X _ {i'} = X_i \setminus \lbrace y \rbrace$ な新しい根を付け加えてできる根付き木は nice である
1.  (join): nice なふたつの根付き木であって根 $i_1, i_2$ の重みが等しいものの上に $X _ i = X _ {i_1} = X _ {i_2}$ な新しい根を付け加えてできる根付き木は nice である

a tree decomposition であってそれを根付き木として見たとき nice であるものを a nice tree decomposition という。
a nice tree decomposition があるとその構成に沿って動的計画法ができ、その計算量は幅 $t$ に対し $O(2^t V)$ や $O(2^t t^2 V)$ などになる。


## Depends on

* :question: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/graph/tree_decomposition.aoj_2405.test.cpp.html">graph/tree_decomposition.aoj_2405.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdint>
#include <functional>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief 木分解 (木幅 $t \le 2$)
 * @docs graph/tree_decomposition.md
 * @note $O(N)$ ?
 * @see https://ei1333.hateblo.jp/entry/2020/02/12/150319
 * @arg g is a simple connected graph $G = (V, E)$ whose treewidth $t \le 2$
 * @return a decomposed tree $T = (I, F)$ as a triple of (the root, the list of children $c : I \to \mathcal{P} \to I$, what vertices are contained $X : I \to \mathcal{P}(V)$)
 */
inline std::pair<std::vector<int>, std::vector<std::vector<int> > > get_tree_decomposition(const std::vector<std::vector<int> > & g) {
    int n = g.size();

    // prepare the info about g
    std::vector<int> used(n, -1);
    std::vector<int> degree(n);
    std::unordered_set<int64_t> edges;
    auto pack = [&](int x, int y) {
        if (x > y) std::swap(x, y);
        return ((int64_t)x << 32) | y;
    };
    REP (x, n) {
        degree[x] = g[x].size();
        for (int y : g[x]) if (x < y) {
            edges.insert(pack(x, y));
        }
    }

    // prepare the info about t
    std::vector<int> parent;
    std::vector<int> antecedent;
    std::function<int (int)> find_root = [&](int a) {
        // union-find tree with only path-compression
        return (antecedent[a] == -1 ? a : antecedent[a] = find_root(antecedent[a]));
    };
    std::vector<std::vector<int> > bags;

    // construct the tree with a stack
    std::stack<int> stk;
    REP (x, n) {
        if (g[x].size() <= 2) {
            stk.push(x);
        }
    }
    while (not stk.empty()) {
        int x = stk.top();
        stk.pop();
        if (degree[x] == 0) continue;
        used[x] = bags.size();
        parent.push_back(-1);
        antecedent.push_back(-1);
        bags.emplace_back();
        auto & bag = bags.back();

        // make the new bag
        bag.push_back(x);
        for (int y : g[x]) {
            if (used[y] == -1) {
                // add a vertex y into the new bag
                bag.push_back(y);

            } else if (used[y] >= 0) {
                // connect a bag used[y] as a child
                int root = find_root(used[y]);
                if (root == used[x]) {
                    // nop

                } else if (bags[used[y]].size() == 2) {
                    // the sub-bag is removing a vertex
                    if (parent[root] == -1) {
                        parent[root] = antecedent[root] = used[x];
                    }
                    assert (bags[used[y]][1] == x);
                    bag.push_back(y);

                } else if (bags[used[y]].size() == 3) {
                    // the sub-bag is removing an edge
                    if (parent[root] == -1) {
                        parent[root] = antecedent[root] = used[x];
                    }
                    assert (bags[root][1] == x or bags[root][2] == x);
                    bag.push_back(bags[root][1] ^ bags[root][2] ^ x);
                    used[bags[root][0]] = used[x];
                } else {
                    assert (false);
                }

            } else {
                // nop
            }
        }
        std::sort(bag.begin() + 1, bag.end());
        bag.erase(std::unique(bag.begin() + 1, bag.end()), bag.end());
        assert (bag.size() == degree[x] + 1);

        // remove and add edges
        auto decr = [&](int y) {
            -- degree[y];
            if (degree[y] == 2) {
                stk.push(y);
            }
        };
        if (degree[x] == 1) {
            decr(bag[1]);
        } if (degree[x] == 2) {
            if (not edges.insert(pack(bag[1], bag[2])).second) {
                decr(bag[1]);
                decr(bag[2]);
            }
        }
        degree[x] = 0;
    }

    if (std::count(ALL(degree), 0) != n) return std::make_pair(std::vector<int>(), std::vector<std::vector<int> >());
    assert (std::count(ALL(parent), -1) == 1);
    return std::make_pair(parent, bags);
}

enum nice_tree_decomposition_tag {
    LEAF,
    INTRODUCE,
    FORGET,
    JOIN,
};

/**
 * @note $O(t N)$
 */
inline std::vector<std::tuple<nice_tree_decomposition_tag, int, int> > get_nice_tree_decomposition(const std::vector<int> & parent, const std::vector<std::vector<int> > & bags) {
    assert (not parent.empty());
    assert (parent.back() == -1);  // assume that vertices are topologically sorted and reversed
    int n = parent.size();
    std::vector<std::vector<int> > children(n);
    std::vector<int> node(n, -1);
    std::vector<std::tuple<nice_tree_decomposition_tag, int, int> > nice;
    REP (a, n) {
        assert (not bags[a].empty());
        if (children[a].empty()) {
            for (int x : bags[a]) {
                if (x == bags[a].front()) {
                    nice.emplace_back(LEAF, x, -1);
                } else {
                    nice.emplace_back(INTRODUCE, x, nice.size() - 1);
                }
            }
            node[a] = nice.size() - 1;
        } else {
            for (int b : children[a]) {
                for (int y : bags[b]) {
                    if (not count(ALL(bags[a]), y)) {
                        nice.emplace_back(FORGET, y, node[b]);
                        node[b] = nice.size() - 1;
                    }
                }
                for (int x : bags[a]) {
                    if (not count(ALL(bags[b]), x)) {
                        nice.emplace_back(INTRODUCE, x, node[b]);
                        node[b] = nice.size() - 1;
                    }
                }
                if (b == children[a].front()) {
                    std::swap(node[a], node[b]);
                } else {
                    nice.emplace_back(JOIN, node[a], node[b]);
                    node[a] = nice.size() - 1;
                }
            }
        }
        if (parent[a] != -1) {
            children[parent[a]].push_back(a);
        }
    };
    for (int x : bags.back()) {
        nice.emplace_back(FORGET, x, node.back());
        node.back() = nice.size() - 1;
    }
    return nice;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/tree_decomposition.hpp"
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdint>
#include <functional>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 14 "graph/tree_decomposition.hpp"

/**
 * @brief 木分解 (木幅 $t \le 2$)
 * @docs graph/tree_decomposition.md
 * @note $O(N)$ ?
 * @see https://ei1333.hateblo.jp/entry/2020/02/12/150319
 * @arg g is a simple connected graph $G = (V, E)$ whose treewidth $t \le 2$
 * @return a decomposed tree $T = (I, F)$ as a triple of (the root, the list of children $c : I \to \mathcal{P} \to I$, what vertices are contained $X : I \to \mathcal{P}(V)$)
 */
inline std::pair<std::vector<int>, std::vector<std::vector<int> > > get_tree_decomposition(const std::vector<std::vector<int> > & g) {
    int n = g.size();

    // prepare the info about g
    std::vector<int> used(n, -1);
    std::vector<int> degree(n);
    std::unordered_set<int64_t> edges;
    auto pack = [&](int x, int y) {
        if (x > y) std::swap(x, y);
        return ((int64_t)x << 32) | y;
    };
    REP (x, n) {
        degree[x] = g[x].size();
        for (int y : g[x]) if (x < y) {
            edges.insert(pack(x, y));
        }
    }

    // prepare the info about t
    std::vector<int> parent;
    std::vector<int> antecedent;
    std::function<int (int)> find_root = [&](int a) {
        // union-find tree with only path-compression
        return (antecedent[a] == -1 ? a : antecedent[a] = find_root(antecedent[a]));
    };
    std::vector<std::vector<int> > bags;

    // construct the tree with a stack
    std::stack<int> stk;
    REP (x, n) {
        if (g[x].size() <= 2) {
            stk.push(x);
        }
    }
    while (not stk.empty()) {
        int x = stk.top();
        stk.pop();
        if (degree[x] == 0) continue;
        used[x] = bags.size();
        parent.push_back(-1);
        antecedent.push_back(-1);
        bags.emplace_back();
        auto & bag = bags.back();

        // make the new bag
        bag.push_back(x);
        for (int y : g[x]) {
            if (used[y] == -1) {
                // add a vertex y into the new bag
                bag.push_back(y);

            } else if (used[y] >= 0) {
                // connect a bag used[y] as a child
                int root = find_root(used[y]);
                if (root == used[x]) {
                    // nop

                } else if (bags[used[y]].size() == 2) {
                    // the sub-bag is removing a vertex
                    if (parent[root] == -1) {
                        parent[root] = antecedent[root] = used[x];
                    }
                    assert (bags[used[y]][1] == x);
                    bag.push_back(y);

                } else if (bags[used[y]].size() == 3) {
                    // the sub-bag is removing an edge
                    if (parent[root] == -1) {
                        parent[root] = antecedent[root] = used[x];
                    }
                    assert (bags[root][1] == x or bags[root][2] == x);
                    bag.push_back(bags[root][1] ^ bags[root][2] ^ x);
                    used[bags[root][0]] = used[x];
                } else {
                    assert (false);
                }

            } else {
                // nop
            }
        }
        std::sort(bag.begin() + 1, bag.end());
        bag.erase(std::unique(bag.begin() + 1, bag.end()), bag.end());
        assert (bag.size() == degree[x] + 1);

        // remove and add edges
        auto decr = [&](int y) {
            -- degree[y];
            if (degree[y] == 2) {
                stk.push(y);
            }
        };
        if (degree[x] == 1) {
            decr(bag[1]);
        } if (degree[x] == 2) {
            if (not edges.insert(pack(bag[1], bag[2])).second) {
                decr(bag[1]);
                decr(bag[2]);
            }
        }
        degree[x] = 0;
    }

    if (std::count(ALL(degree), 0) != n) return std::make_pair(std::vector<int>(), std::vector<std::vector<int> >());
    assert (std::count(ALL(parent), -1) == 1);
    return std::make_pair(parent, bags);
}

enum nice_tree_decomposition_tag {
    LEAF,
    INTRODUCE,
    FORGET,
    JOIN,
};

/**
 * @note $O(t N)$
 */
inline std::vector<std::tuple<nice_tree_decomposition_tag, int, int> > get_nice_tree_decomposition(const std::vector<int> & parent, const std::vector<std::vector<int> > & bags) {
    assert (not parent.empty());
    assert (parent.back() == -1);  // assume that vertices are topologically sorted and reversed
    int n = parent.size();
    std::vector<std::vector<int> > children(n);
    std::vector<int> node(n, -1);
    std::vector<std::tuple<nice_tree_decomposition_tag, int, int> > nice;
    REP (a, n) {
        assert (not bags[a].empty());
        if (children[a].empty()) {
            for (int x : bags[a]) {
                if (x == bags[a].front()) {
                    nice.emplace_back(LEAF, x, -1);
                } else {
                    nice.emplace_back(INTRODUCE, x, nice.size() - 1);
                }
            }
            node[a] = nice.size() - 1;
        } else {
            for (int b : children[a]) {
                for (int y : bags[b]) {
                    if (not count(ALL(bags[a]), y)) {
                        nice.emplace_back(FORGET, y, node[b]);
                        node[b] = nice.size() - 1;
                    }
                }
                for (int x : bags[a]) {
                    if (not count(ALL(bags[b]), x)) {
                        nice.emplace_back(INTRODUCE, x, node[b]);
                        node[b] = nice.size() - 1;
                    }
                }
                if (b == children[a].front()) {
                    std::swap(node[a], node[b]);
                } else {
                    nice.emplace_back(JOIN, node[a], node[b]);
                    node[a] = nice.size() - 1;
                }
            }
        }
        if (parent[a] != -1) {
            children[parent[a]].push_back(a);
        }
    };
    for (int x : bags.back()) {
        nice.emplace_back(FORGET, x, node.back());
        node.back() = nice.size() - 1;
    }
    return nice;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

