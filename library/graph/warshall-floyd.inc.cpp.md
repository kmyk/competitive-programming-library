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


# :warning: graph/warshall-floyd.inc.cpp
* category: graph


[Back to top page](../../index.html)

* Warshall-Floyd algorithm
* Warshall-Floyd algorithm for connectivity


## Code
```cpp
/**
 * @brief Warshall-Floyd algorithm
 * @note O(n^3)
 * @param g is a digraph
 */
vector<vector<ll> > warshall_floyd(vector<vector<pair<int, ll> > > const & g) {
    int n = g.size();
    vector<vector<ll> > dist(n, vector<ll>(n, LLONG_MAX));
    REP (i, n) {
        dist[i][i] = 0;
        for (auto edge : g[i]) {
            int j; ll cost; tie(j, cost) = edge;
            dist[i][j] = cost;
        }
    }
    REP (k, n) {
        REP (i, n) if (dist[i][k] != LLONG_MAX) {
            REP (j, n) if (dist[k][j] != LLONG_MAX) {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

/**
 * @brief Warshall-Floyd algorithm for connectivity
 */
vector<vector<bool> > warshall_floyd(vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<bool> > conn(n, vector<bool>(n));
    REP (i, n) {
        conn[i][i] = true;
        for (int j : g[i]) {
            conn[i][j] = true;
        }
    }
    REP (k, n) REP (i, n) REP (j, n) {
        if (conn[i][k] and conn[k][j]) {
            conn[i][j] = true;
        }
    }
    return conn;
}

```

[Back to top page](../../index.html)

