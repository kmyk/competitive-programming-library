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


# :warning: compute the distances from root <small>(graph/breadth-first-search.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/breadth-first-search.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-01-13 05:37:22+09:00


* 0-1 BFS


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief compute the distances from root
 * @note O(n)
 * @arg g is a digraph
 * @note loops and double edges are allowed
 */
vector<int> breadth_first_search(int root, vector<vector<int> > const & g) {
    int n = g.size();
    vector<int> dist(n, INT_MAX);
    queue<int> que;
    dist[root] = 0;
    que.push(root);
    while (not que.empty()) {
        int i = que.front(); que.pop();
        for (int j : g[i]) if (dist[j] == INT_MAX) {
            dist[j] = dist[i] + 1;
            que.push(j);
        }
    }
    return dist;
}

/**
 * @brief 0-1 BFS
 * @arg g is a weighted digraph whose weights are 0 or 1
 * @note loops and double edges are allowed
 */
vector<int> zero_one_breadth_first_search(int root, vector<vector<pair<int, bool> > > const & g) {
    int n = g.size();
    vector<int> dist(n, INT_MAX);
    deque<pair<int, int> > que;
    dist[root] = 0;
    que.emplace_back(root, dist[root]);
    while (not que.empty()) {
        int i, dist_i; tie(i, dist_i) = que.front(); que.pop_front();
        if (dist[i] < dist_i) continue;
        for (auto edge : g[i]) {
            int j; bool cost; tie(j, cost) = edge;
            if (dist[i] + cost < dist[j]) {
                dist[j] = dist[i] + cost;
                if (cost) {
                    que.emplace_back(j, dist[j]);
                } else {
                    que.emplace_front(j, dist[j]);
                }
            }
        }
    }
    return dist;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/breadth-first-search.inc.cpp"
/**
 * @brief compute the distances from root
 * @note O(n)
 * @arg g is a digraph
 * @note loops and double edges are allowed
 */
vector<int> breadth_first_search(int root, vector<vector<int> > const & g) {
    int n = g.size();
    vector<int> dist(n, INT_MAX);
    queue<int> que;
    dist[root] = 0;
    que.push(root);
    while (not que.empty()) {
        int i = que.front(); que.pop();
        for (int j : g[i]) if (dist[j] == INT_MAX) {
            dist[j] = dist[i] + 1;
            que.push(j);
        }
    }
    return dist;
}

/**
 * @brief 0-1 BFS
 * @arg g is a weighted digraph whose weights are 0 or 1
 * @note loops and double edges are allowed
 */
vector<int> zero_one_breadth_first_search(int root, vector<vector<pair<int, bool> > > const & g) {
    int n = g.size();
    vector<int> dist(n, INT_MAX);
    deque<pair<int, int> > que;
    dist[root] = 0;
    que.emplace_back(root, dist[root]);
    while (not que.empty()) {
        int i, dist_i; tie(i, dist_i) = que.front(); que.pop_front();
        if (dist[i] < dist_i) continue;
        for (auto edge : g[i]) {
            int j; bool cost; tie(j, cost) = edge;
            if (dist[i] + cost < dist[j]) {
                dist[j] = dist[i] + cost;
                if (cost) {
                    que.emplace_back(j, dist[j]);
                } else {
                    que.emplace_front(j, dist[j]);
                }
            }
        }
    }
    return dist;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

