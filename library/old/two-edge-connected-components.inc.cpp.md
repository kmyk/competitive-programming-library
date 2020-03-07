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


# VerificationStatus.DEFAULT 2-edge-connected components decomposition / 2-辺連結成分分解 <small>(old/two-edge-connected-components.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/two-edge-connected-components.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 2-edge-connected components decomposition / 2-辺連結成分分解
 * @param g an adjacent list of the simple undirected graph
 * @note O(V + E)
 */
pair<int, vector<int> > decompose_to_two_edge_connected_components(vector<vector<int> > const & g) {
    int n = g.size();
    vector<int> imos(n); { // imos[i] == 0  iff  the edge i -> parent is a bridge
        vector<char> used(n); // 0: unused ; 1: exists on stack ; 2: removed from stack
        function<void (int, int)> go = [&](int i, int parent) {
            used[i] = 1;
            for (int j : g[i]) if (j != parent) {
                if (used[j] == 0) {
                    go(j, i);
                    imos[i] += imos[j];
                } else if (used[j] == 1) {
                    imos[i] += 1;
                    imos[j] -= 1;
                }
            }
            used[i] = 2;
        };
        REP (i, n) if (used[i] == 0) {
            go(i, -1);
        }
    }
    int size = 0;
    vector<int> component_of(n, -1); {
        function<void (int)> go = [&](int i) {
            for (int j : g[i]) if (component_of[j] == -1) {
                component_of[j] = imos[j] == 0 ? size ++ : component_of[i];
                go(j);
            }
        };
        REP (i, n) if (component_of[i] == -1) {
            component_of[i] = size ++;
            go(i);
        }
    }
    return { size, move(component_of) };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/two-edge-connected-components.inc.cpp"
/**
 * @brief 2-edge-connected components decomposition / 2-辺連結成分分解
 * @param g an adjacent list of the simple undirected graph
 * @note O(V + E)
 */
pair<int, vector<int> > decompose_to_two_edge_connected_components(vector<vector<int> > const & g) {
    int n = g.size();
    vector<int> imos(n); { // imos[i] == 0  iff  the edge i -> parent is a bridge
        vector<char> used(n); // 0: unused ; 1: exists on stack ; 2: removed from stack
        function<void (int, int)> go = [&](int i, int parent) {
            used[i] = 1;
            for (int j : g[i]) if (j != parent) {
                if (used[j] == 0) {
                    go(j, i);
                    imos[i] += imos[j];
                } else if (used[j] == 1) {
                    imos[i] += 1;
                    imos[j] -= 1;
                }
            }
            used[i] = 2;
        };
        REP (i, n) if (used[i] == 0) {
            go(i, -1);
        }
    }
    int size = 0;
    vector<int> component_of(n, -1); {
        function<void (int)> go = [&](int i) {
            for (int j : g[i]) if (component_of[j] == -1) {
                component_of[j] = imos[j] == 0 ? size ++ : component_of[i];
                go(j);
            }
        };
        REP (i, n) if (component_of[i] == -1) {
            component_of[i] = size ++;
            go(i);
        }
    }
    return { size, move(component_of) };
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

