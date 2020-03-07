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


# :warning: euler tour <small>(old/euler-tour.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/euler-tour.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00


* see: <a href="https://yukicoder.me/problems/no/899">https://yukicoder.me/problems/no/899</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief euler tour
 * @arg g must be a tree, directed or undirected
 * @note for constraints, see the unittest
 */
void do_euler_tour(vector<vector<int> > const & g, int root, vector<int> & tour, vector<int> & left, vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.resize(n);
    right.resize(n);
    function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
        tour.push_back(x);
    };
    go(root, -1);
}
unittest {
    default_random_engine gen;
    int n = 100;
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int j = uniform_int_distribution<int>(i + 1, n - 1)(gen);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    vector<int> tour, left, right; do_euler_tour(g, 0, tour, left, right);
    assert (tour.size() == 2 * n);
    REP (i, n) {
        assert (tour[ left[i]] == i);
        assert (tour[right[i]] == i);
    }
}

/**
 * @brief euler tour, push vertices only visiting
 * @arg g must be a tree, directed or undirected
 */
void do_left_euler_tour(vector<vector<int> > const & g, int root, vector<int> & tour, vector<int> & left, vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.resize(n);
    right.resize(n);
    function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
    };
    go(root, -1);
}
unittest {
    default_random_engine gen;
    int n = 100;
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int j = uniform_int_distribution<int>(i + 1, n - 1)(gen);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    vector<int> tour, left, right; do_left_euler_tour(g, 0, tour, left, right);
    assert (tour.size() == n);
    REP (i, n) {
        assert (tour[left[i]] == i);
    }
}

/**
 * @brief something like euler tour but do BFS
 * @arg g must be a tree, directed or undirected
 * @note for constraints, see the unittest
 * @arg parent is initialized
 * @arg left and
 * @arg right are the ranges of descendants of k-th level
 * @note O(N * DEPTH)
 * @sa https://yukicoder.me/problems/no/899
 */
template <int DEPTH>
void do_bfs_euler_tour(vector<vector<int> > const & g, int root, vector<int> & tour, vector<int> & parent, vector<array<int, DEPTH> > & left, vector<array<int, DEPTH> > & right) {
    int n = g.size();
    tour.clear();
    parent.assign(n, -1);
    left.resize(n);
    right.resize(n);
    queue<int> que;
    que.push(root);
    while (not que.empty()) {
        int x = que.front();
        que.pop();
        int i = tour.size();
        // initialize current
        tour.push_back(x);
        fill(ALL(left[x]), n);
        fill(ALL(right[x]), n);
        // update parent
        int y = x;
        REP (d, DEPTH) {
            y = parent[y];
            if (y == -1) break;
            left[y][d] = min(left[y][d], i);
            right[y][d] = i + 1;
        }
        // go children
        for (int y : g[x]) if (y != parent[x]) {
            parent[y] = x;
            que.push(y);
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/euler-tour.inc.cpp"
/**
 * @brief euler tour
 * @arg g must be a tree, directed or undirected
 * @note for constraints, see the unittest
 */
void do_euler_tour(vector<vector<int> > const & g, int root, vector<int> & tour, vector<int> & left, vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.resize(n);
    right.resize(n);
    function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
        tour.push_back(x);
    };
    go(root, -1);
}
unittest {
    default_random_engine gen;
    int n = 100;
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int j = uniform_int_distribution<int>(i + 1, n - 1)(gen);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    vector<int> tour, left, right; do_euler_tour(g, 0, tour, left, right);
    assert (tour.size() == 2 * n);
    REP (i, n) {
        assert (tour[ left[i]] == i);
        assert (tour[right[i]] == i);
    }
}

/**
 * @brief euler tour, push vertices only visiting
 * @arg g must be a tree, directed or undirected
 */
void do_left_euler_tour(vector<vector<int> > const & g, int root, vector<int> & tour, vector<int> & left, vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.resize(n);
    right.resize(n);
    function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
    };
    go(root, -1);
}
unittest {
    default_random_engine gen;
    int n = 100;
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int j = uniform_int_distribution<int>(i + 1, n - 1)(gen);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    vector<int> tour, left, right; do_left_euler_tour(g, 0, tour, left, right);
    assert (tour.size() == n);
    REP (i, n) {
        assert (tour[left[i]] == i);
    }
}

/**
 * @brief something like euler tour but do BFS
 * @arg g must be a tree, directed or undirected
 * @note for constraints, see the unittest
 * @arg parent is initialized
 * @arg left and
 * @arg right are the ranges of descendants of k-th level
 * @note O(N * DEPTH)
 * @sa https://yukicoder.me/problems/no/899
 */
template <int DEPTH>
void do_bfs_euler_tour(vector<vector<int> > const & g, int root, vector<int> & tour, vector<int> & parent, vector<array<int, DEPTH> > & left, vector<array<int, DEPTH> > & right) {
    int n = g.size();
    tour.clear();
    parent.assign(n, -1);
    left.resize(n);
    right.resize(n);
    queue<int> que;
    que.push(root);
    while (not que.empty()) {
        int x = que.front();
        que.pop();
        int i = tour.size();
        // initialize current
        tour.push_back(x);
        fill(ALL(left[x]), n);
        fill(ALL(right[x]), n);
        // update parent
        int y = x;
        REP (d, DEPTH) {
            y = parent[y];
            if (y == -1) break;
            left[y][d] = min(left[y][d], i);
            right[y][d] = i + 1;
        }
        // go children
        for (int y : g[x]) if (y != parent[x]) {
            parent[y] = x;
            que.push(y);
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

