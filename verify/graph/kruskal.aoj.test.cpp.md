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


# :heavy_check_mark: graph/kruskal.aoj.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/graph/kruskal.aoj.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-27 03:24:33+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/union_find_tree.hpp.html">a disjoint set structure <small>(data_structure/union_find_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/graph/kruskal.hpp.html">compute a minimum spanning forest with Kruskal's method <small>(graph/kruskal.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A"
#include "graph/kruskal.hpp"

#include "utils/macros.hpp"
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // input
    int n; scanf("%d", &n);
    vector<tuple<int, int, long long> > edges;
    REP (x, n) {
        REP (y, n) {
            long long a; scanf("%lld", &a);
            if (a != -1) {
                edges.emplace_back(x, y, a);
            }
        }
    }

    // solve
    vector<int> mst = compute_minimum_spanning_tree(n, edges);
    long long answer = 0;
    for (int i : mst) {
        answer += get<2>(edges[i]);
    }

    // output
    printf("%lld\n", answer);
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/kruskal.aoj.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A"
#line 2 "data_structure/union_find_tree.hpp"
#include <vector>

/**
 * @brief a disjoint set structure
 * @note union-by-size + path-compression
 */
struct union_find_tree {
    std::vector<int> data;
    union_find_tree() = default;
    explicit union_find_tree(std::size_t n) : data(n, -1) {}
    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }
    int tree_size(int i) { return - data[find_root(i)]; }
    int unite_trees(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (tree_size(i) < tree_size(j)) std::swap(i, j);
            data[i] += data[j];
            data[j] = i;
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
};
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 4 "graph/kruskal.hpp"
#include <algorithm>
#include <numeric>
#include <tuple>
#include <vector>

/**
 * @brief compute a minimum spanning forest with Kruskal's method
 * @note $O(E \log E)$
 * @return a list of indices of edges
 */
template <typename T>
std::vector<int> compute_minimum_spanning_tree(int n, std::vector<std::tuple<int, int, T> > edges) {
    std::vector<int> order(edges.size());
    std::iota(ALL(order), 0);
    std::sort(ALL(order), [&](int i, int j) {
        return std::make_pair(std::get<2>(edges[i]), i) < std::make_pair(std::get<2>(edges[j]), j);
    });
    std::vector<int> tree;
    union_find_tree uft(n);
    for (int i : order) {
        int x = std::get<0>(edges[i]);
        int y = std::get<1>(edges[i]);
        if (not uft.is_same(x, y)) {
            uft.unite_trees(x, y);
            tree.push_back(i);
        }
    }
    return tree;
}
#line 3 "graph/kruskal.aoj.test.cpp"

#line 5 "graph/kruskal.aoj.test.cpp"
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // input
    int n; scanf("%d", &n);
    vector<tuple<int, int, long long> > edges;
    REP (x, n) {
        REP (y, n) {
            long long a; scanf("%lld", &a);
            if (a != -1) {
                edges.emplace_back(x, y, a);
            }
        }
    }

    // solve
    vector<int> mst = compute_minimum_spanning_tree(n, edges);
    long long answer = 0;
    for (int i : mst) {
        answer += get<2>(edges[i]);
    }

    // output
    printf("%lld\n", answer);
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

