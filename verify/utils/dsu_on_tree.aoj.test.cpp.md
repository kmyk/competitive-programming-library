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

* <a href="{{ site.github.repository_url }}/blob/master/utils/dsu_on_tree.aoj.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995</a>


## Depends On
* :heavy_check_mark: <a href="../../library/data_structure/union_find_tree_with_monoid.hpp.html">a disjoint set structure with monoid</a>
* :heavy_check_mark: <a href="../../library/graph/subtree.hpp.html">subtree info / それぞれの部分木の size とか height とかをまとめて求めておいてくれるやつ</a>
* :heavy_check_mark: <a href="../../library/utils/dsu_on_tree.hpp.html">DSU on tree (sack)</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/monoids.hpp.html">utils/monoids.hpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995"
#include "utils/dsu_on_tree.hpp"
#include "data_structure/union_find_tree_with_monoid.hpp"
#include "utils/monoids.hpp"

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

int main() {
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

