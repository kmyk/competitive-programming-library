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


# :warning: 2-node-connected components decomposition / 2-頂点連結成分分解 <small>(graph/two-node-connected-components.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/two-node-connected-components.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900




## Code

{% raw %}
```cpp
/**
 * @brief 2-node-connected components decomposition / 2-頂点連結成分分解
 * @param g an adjacent list of the simple undirected graph
 * @note O(V + E)
 * @return list of (list of edges in the component)
 */
vector<vector<pair<int, int> > > decompose_to_two_node_connected_components(vector<vector<int> > const & g) {
    int n = g.size();
    vector<int> ord(n, -1);
    vector<int> low(n, -1);
    vector<bool> used(n);
    vector<vector<pair<int, int> > > components;
    stack<pair<int, int> > stk;
    int k = 0;
    function<void (int, int)> go = [&](int i, int parent) {
        used[i] = true;
        ord[i] = k ++;
        low[i] = ord[i];
        for (auto j : g[i]) if (j != parent) {
            if (ord[j] < ord[i]) {
                stk.emplace(minmax({ i, j }));
            }
            if (used[j]) {
                chmin(low[i], ord[j]);
            } else {
                go(j, i);
                chmin(low[i], low[j]);
                if (low[j] >= ord[i]) {
                    components.emplace_back();
                    while (true) {
                        pair<int, int> e = stk.top();
                        components.back().push_back(e);
                        stk.pop();
                        if (e == minmax({ i, j })) {
                            break;
                        }
                    }
                }
            }
        }
    };
    REP (i, n) if (not used[i]) {
        go(i, -1);
    }
    return components;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

