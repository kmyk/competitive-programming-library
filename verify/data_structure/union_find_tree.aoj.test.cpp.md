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


# VerificationStatus.VERIFIED data_structure/union_find_tree.aoj.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/union_find_tree.aoj.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-28 14:33:39+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/union_find_tree.hpp.html">Union-Find Tree <small>(data_structure/union_find_tree.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include "data_structure/union_find_tree.hpp"
#include <cstdio>

int main() {
    int n, q; scanf("%d%d", &n, &q);
    union_find_tree uft(n);
    while (q --) {
        int com, x, y; scanf("%d%d%d", &com, &x, &y);
        if (com == 0) {
            uft.unite_trees(x, y);
        } else if (com == 1) {
            bool answer = uft.is_same(x, y);
            printf("%d\n", (int)answer);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/union_find_tree.aoj.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#line 2 "data_structure/union_find_tree.hpp"
#include <vector>

/**
 * @brief Union-Find Tree
 * @docs data_structure/union_find_tree.md
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
#line 3 "data_structure/union_find_tree.aoj.test.cpp"
#include <cstdio>

int main() {
    int n, q; scanf("%d%d", &n, &q);
    union_find_tree uft(n);
    while (q --) {
        int com, x, y; scanf("%d%d%d", &com, &x, &y);
        if (com == 0) {
            uft.unite_trees(x, y);
        } else if (com == 1) {
            bool answer = uft.is_same(x, y);
            printf("%d\n", (int)answer);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

