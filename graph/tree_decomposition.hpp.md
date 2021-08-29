---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/tree_decomposition.aoj_2405.test.cpp
    title: graph/tree_decomposition.aoj_2405.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: graph/tree_decomposition.md
    document_title: "\u6728\u5206\u89E3 (\u6728\u5E45 $t \\le 2$)"
    links:
    - https://ei1333.hateblo.jp/entry/2020/02/12/150319
  bundledCode: "#line 2 \"graph/tree_decomposition.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cstdio>\n#include <cstdint>\n#include <functional>\n#include\
    \ <set>\n#include <stack>\n#include <tuple>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n)\
    \ for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i =\
    \ (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1;\
    \ (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >=\
    \ (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 14 \"graph/tree_decomposition.hpp\"\
    \n\n/**\n * @brief \u6728\u5206\u89E3 (\u6728\u5E45 $t \\le 2$)\n * @docs graph/tree_decomposition.md\n\
    \ * @note $O(N)$ ?\n * @see https://ei1333.hateblo.jp/entry/2020/02/12/150319\n\
    \ * @arg g is a simple connected graph $G = (V, E)$ whose treewidth $t \\le 2$\n\
    \ * @return a decomposed tree $T = (I, F)$ as a triple of (the root, the list\
    \ of children $c : I \\to \\mathcal{P} \\to I$, what vertices are contained $X\
    \ : I \\to \\mathcal{P}(V)$)\n */\ninline std::pair<std::vector<int>, std::vector<std::vector<int>\
    \ > > get_tree_decomposition(const std::vector<std::vector<int> > & g) {\n   \
    \ int n = g.size();\n\n    // prepare the info about g\n    std::vector<int> used(n,\
    \ -1);\n    std::vector<int> degree(n);\n    std::unordered_set<int64_t> edges;\n\
    \    auto pack = [&](int x, int y) {\n        if (x > y) std::swap(x, y);\n  \
    \      return ((int64_t)x << 32) | y;\n    };\n    REP (x, n) {\n        degree[x]\
    \ = g[x].size();\n        for (int y : g[x]) if (x < y) {\n            edges.insert(pack(x,\
    \ y));\n        }\n    }\n\n    // prepare the info about t\n    std::vector<int>\
    \ parent;\n    std::vector<int> antecedent;\n    std::function<int (int)> find_root\
    \ = [&](int a) {\n        // union-find tree with only path-compression\n    \
    \    return (antecedent[a] == -1 ? a : antecedent[a] = find_root(antecedent[a]));\n\
    \    };\n    std::vector<std::vector<int> > bags;\n\n    // construct the tree\
    \ with a stack\n    std::stack<int> stk;\n    REP (x, n) {\n        if (g[x].size()\
    \ <= 2) {\n            stk.push(x);\n        }\n    }\n    while (not stk.empty())\
    \ {\n        int x = stk.top();\n        stk.pop();\n        if (degree[x] ==\
    \ 0) continue;\n        used[x] = bags.size();\n        parent.push_back(-1);\n\
    \        antecedent.push_back(-1);\n        bags.emplace_back();\n        auto\
    \ & bag = bags.back();\n\n        // make the new bag\n        bag.push_back(x);\n\
    \        for (int y : g[x]) {\n            if (used[y] == -1) {\n            \
    \    // add a vertex y into the new bag\n                bag.push_back(y);\n\n\
    \            } else if (used[y] >= 0) {\n                // connect a bag used[y]\
    \ as a child\n                int root = find_root(used[y]);\n               \
    \ if (root == used[x]) {\n                    // nop\n\n                } else\
    \ if (bags[used[y]].size() == 2) {\n                    // the sub-bag is removing\
    \ a vertex\n                    if (parent[root] == -1) {\n                  \
    \      parent[root] = antecedent[root] = used[x];\n                    }\n   \
    \                 assert (bags[used[y]][1] == x);\n                    bag.push_back(y);\n\
    \n                } else if (bags[used[y]].size() == 3) {\n                  \
    \  // the sub-bag is removing an edge\n                    if (parent[root] ==\
    \ -1) {\n                        parent[root] = antecedent[root] = used[x];\n\
    \                    }\n                    assert (bags[root][1] == x or bags[root][2]\
    \ == x);\n                    bag.push_back(bags[root][1] ^ bags[root][2] ^ x);\n\
    \                    used[bags[root][0]] = used[x];\n                } else {\n\
    \                    assert (false);\n                }\n\n            } else\
    \ {\n                // nop\n            }\n        }\n        std::sort(bag.begin()\
    \ + 1, bag.end());\n        bag.erase(std::unique(bag.begin() + 1, bag.end()),\
    \ bag.end());\n        assert (bag.size() == degree[x] + 1);\n\n        // remove\
    \ and add edges\n        auto decr = [&](int y) {\n            -- degree[y];\n\
    \            if (degree[y] == 2) {\n                stk.push(y);\n           \
    \ }\n        };\n        if (degree[x] == 1) {\n            decr(bag[1]);\n  \
    \      } if (degree[x] == 2) {\n            if (not edges.insert(pack(bag[1],\
    \ bag[2])).second) {\n                decr(bag[1]);\n                decr(bag[2]);\n\
    \            }\n        }\n        degree[x] = 0;\n    }\n\n    if (std::count(ALL(degree),\
    \ 0) != n) return std::make_pair(std::vector<int>(), std::vector<std::vector<int>\
    \ >());\n    assert (std::count(ALL(parent), -1) == 1);\n    return std::make_pair(parent,\
    \ bags);\n}\n\nenum nice_tree_decomposition_tag {\n    LEAF,\n    INTRODUCE,\n\
    \    FORGET,\n    JOIN,\n};\n\n/**\n * @note $O(t N)$\n */\ninline std::vector<std::tuple<nice_tree_decomposition_tag,\
    \ int, int> > get_nice_tree_decomposition(const std::vector<int> & parent, const\
    \ std::vector<std::vector<int> > & bags) {\n    assert (not parent.empty());\n\
    \    assert (parent.back() == -1);  // assume that vertices are topologically\
    \ sorted and reversed\n    int n = parent.size();\n    std::vector<std::vector<int>\
    \ > children(n);\n    std::vector<int> node(n, -1);\n    std::vector<std::tuple<nice_tree_decomposition_tag,\
    \ int, int> > nice;\n    REP (a, n) {\n        assert (not bags[a].empty());\n\
    \        if (children[a].empty()) {\n            for (int x : bags[a]) {\n   \
    \             if (x == bags[a].front()) {\n                    nice.emplace_back(LEAF,\
    \ x, -1);\n                } else {\n                    nice.emplace_back(INTRODUCE,\
    \ x, nice.size() - 1);\n                }\n            }\n            node[a]\
    \ = nice.size() - 1;\n        } else {\n            for (int b : children[a])\
    \ {\n                for (int y : bags[b]) {\n                    if (not count(ALL(bags[a]),\
    \ y)) {\n                        nice.emplace_back(FORGET, y, node[b]);\n    \
    \                    node[b] = nice.size() - 1;\n                    }\n     \
    \           }\n                for (int x : bags[a]) {\n                    if\
    \ (not count(ALL(bags[b]), x)) {\n                        nice.emplace_back(INTRODUCE,\
    \ x, node[b]);\n                        node[b] = nice.size() - 1;\n         \
    \           }\n                }\n                if (b == children[a].front())\
    \ {\n                    std::swap(node[a], node[b]);\n                } else\
    \ {\n                    nice.emplace_back(JOIN, node[a], node[b]);\n        \
    \            node[a] = nice.size() - 1;\n                }\n            }\n  \
    \      }\n        if (parent[a] != -1) {\n            children[parent[a]].push_back(a);\n\
    \        }\n    };\n    for (int x : bags.back()) {\n        nice.emplace_back(FORGET,\
    \ x, node.back());\n        node.back() = nice.size() - 1;\n    }\n    return\
    \ nice;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cstdio>\n\
    #include <cstdint>\n#include <functional>\n#include <set>\n#include <stack>\n\
    #include <tuple>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    #include \"../utils/macros.hpp\"\n\n/**\n * @brief \u6728\u5206\u89E3 (\u6728\u5E45\
    \ $t \\le 2$)\n * @docs graph/tree_decomposition.md\n * @note $O(N)$ ?\n * @see\
    \ https://ei1333.hateblo.jp/entry/2020/02/12/150319\n * @arg g is a simple connected\
    \ graph $G = (V, E)$ whose treewidth $t \\le 2$\n * @return a decomposed tree\
    \ $T = (I, F)$ as a triple of (the root, the list of children $c : I \\to \\mathcal{P}\
    \ \\to I$, what vertices are contained $X : I \\to \\mathcal{P}(V)$)\n */\ninline\
    \ std::pair<std::vector<int>, std::vector<std::vector<int> > > get_tree_decomposition(const\
    \ std::vector<std::vector<int> > & g) {\n    int n = g.size();\n\n    // prepare\
    \ the info about g\n    std::vector<int> used(n, -1);\n    std::vector<int> degree(n);\n\
    \    std::unordered_set<int64_t> edges;\n    auto pack = [&](int x, int y) {\n\
    \        if (x > y) std::swap(x, y);\n        return ((int64_t)x << 32) | y;\n\
    \    };\n    REP (x, n) {\n        degree[x] = g[x].size();\n        for (int\
    \ y : g[x]) if (x < y) {\n            edges.insert(pack(x, y));\n        }\n \
    \   }\n\n    // prepare the info about t\n    std::vector<int> parent;\n    std::vector<int>\
    \ antecedent;\n    std::function<int (int)> find_root = [&](int a) {\n       \
    \ // union-find tree with only path-compression\n        return (antecedent[a]\
    \ == -1 ? a : antecedent[a] = find_root(antecedent[a]));\n    };\n    std::vector<std::vector<int>\
    \ > bags;\n\n    // construct the tree with a stack\n    std::stack<int> stk;\n\
    \    REP (x, n) {\n        if (g[x].size() <= 2) {\n            stk.push(x);\n\
    \        }\n    }\n    while (not stk.empty()) {\n        int x = stk.top();\n\
    \        stk.pop();\n        if (degree[x] == 0) continue;\n        used[x] =\
    \ bags.size();\n        parent.push_back(-1);\n        antecedent.push_back(-1);\n\
    \        bags.emplace_back();\n        auto & bag = bags.back();\n\n        //\
    \ make the new bag\n        bag.push_back(x);\n        for (int y : g[x]) {\n\
    \            if (used[y] == -1) {\n                // add a vertex y into the\
    \ new bag\n                bag.push_back(y);\n\n            } else if (used[y]\
    \ >= 0) {\n                // connect a bag used[y] as a child\n             \
    \   int root = find_root(used[y]);\n                if (root == used[x]) {\n \
    \                   // nop\n\n                } else if (bags[used[y]].size()\
    \ == 2) {\n                    // the sub-bag is removing a vertex\n         \
    \           if (parent[root] == -1) {\n                        parent[root] =\
    \ antecedent[root] = used[x];\n                    }\n                    assert\
    \ (bags[used[y]][1] == x);\n                    bag.push_back(y);\n\n        \
    \        } else if (bags[used[y]].size() == 3) {\n                    // the sub-bag\
    \ is removing an edge\n                    if (parent[root] == -1) {\n       \
    \                 parent[root] = antecedent[root] = used[x];\n               \
    \     }\n                    assert (bags[root][1] == x or bags[root][2] == x);\n\
    \                    bag.push_back(bags[root][1] ^ bags[root][2] ^ x);\n     \
    \               used[bags[root][0]] = used[x];\n                } else {\n   \
    \                 assert (false);\n                }\n\n            } else {\n\
    \                // nop\n            }\n        }\n        std::sort(bag.begin()\
    \ + 1, bag.end());\n        bag.erase(std::unique(bag.begin() + 1, bag.end()),\
    \ bag.end());\n        assert (bag.size() == degree[x] + 1);\n\n        // remove\
    \ and add edges\n        auto decr = [&](int y) {\n            -- degree[y];\n\
    \            if (degree[y] == 2) {\n                stk.push(y);\n           \
    \ }\n        };\n        if (degree[x] == 1) {\n            decr(bag[1]);\n  \
    \      } if (degree[x] == 2) {\n            if (not edges.insert(pack(bag[1],\
    \ bag[2])).second) {\n                decr(bag[1]);\n                decr(bag[2]);\n\
    \            }\n        }\n        degree[x] = 0;\n    }\n\n    if (std::count(ALL(degree),\
    \ 0) != n) return std::make_pair(std::vector<int>(), std::vector<std::vector<int>\
    \ >());\n    assert (std::count(ALL(parent), -1) == 1);\n    return std::make_pair(parent,\
    \ bags);\n}\n\nenum nice_tree_decomposition_tag {\n    LEAF,\n    INTRODUCE,\n\
    \    FORGET,\n    JOIN,\n};\n\n/**\n * @note $O(t N)$\n */\ninline std::vector<std::tuple<nice_tree_decomposition_tag,\
    \ int, int> > get_nice_tree_decomposition(const std::vector<int> & parent, const\
    \ std::vector<std::vector<int> > & bags) {\n    assert (not parent.empty());\n\
    \    assert (parent.back() == -1);  // assume that vertices are topologically\
    \ sorted and reversed\n    int n = parent.size();\n    std::vector<std::vector<int>\
    \ > children(n);\n    std::vector<int> node(n, -1);\n    std::vector<std::tuple<nice_tree_decomposition_tag,\
    \ int, int> > nice;\n    REP (a, n) {\n        assert (not bags[a].empty());\n\
    \        if (children[a].empty()) {\n            for (int x : bags[a]) {\n   \
    \             if (x == bags[a].front()) {\n                    nice.emplace_back(LEAF,\
    \ x, -1);\n                } else {\n                    nice.emplace_back(INTRODUCE,\
    \ x, nice.size() - 1);\n                }\n            }\n            node[a]\
    \ = nice.size() - 1;\n        } else {\n            for (int b : children[a])\
    \ {\n                for (int y : bags[b]) {\n                    if (not count(ALL(bags[a]),\
    \ y)) {\n                        nice.emplace_back(FORGET, y, node[b]);\n    \
    \                    node[b] = nice.size() - 1;\n                    }\n     \
    \           }\n                for (int x : bags[a]) {\n                    if\
    \ (not count(ALL(bags[b]), x)) {\n                        nice.emplace_back(INTRODUCE,\
    \ x, node[b]);\n                        node[b] = nice.size() - 1;\n         \
    \           }\n                }\n                if (b == children[a].front())\
    \ {\n                    std::swap(node[a], node[b]);\n                } else\
    \ {\n                    nice.emplace_back(JOIN, node[a], node[b]);\n        \
    \            node[a] = nice.size() - 1;\n                }\n            }\n  \
    \      }\n        if (parent[a] != -1) {\n            children[parent[a]].push_back(a);\n\
    \        }\n    };\n    for (int x : bags.back()) {\n        nice.emplace_back(FORGET,\
    \ x, node.back());\n        node.back() = nice.size() - 1;\n    }\n    return\
    \ nice;\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: graph/tree_decomposition.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/tree_decomposition.aoj_2405.test.cpp
documentation_of: graph/tree_decomposition.hpp
layout: document
redirect_from:
- /library/graph/tree_decomposition.hpp
- /library/graph/tree_decomposition.hpp.html
title: "\u6728\u5206\u89E3 (\u6728\u5E45 $t \\le 2$)"
---
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
