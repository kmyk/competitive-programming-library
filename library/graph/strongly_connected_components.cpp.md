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


# :warning: strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解 <small>(graph/strongly_connected_components.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/strongly_connected_components.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 04:15:59 +0900


* memory optimized version


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<vector<int> > opposite_graph(vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<int> > h(n);
    REP (i, n) for (int j : g[i]) h[j].push_back(i);
    return h;
}
/**
 * @brief strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解
 * @return the pair (the number k of components, the function from vertices of g to components)
 * @note O(V + E)
 */
pair<int, vector<int> > decompose_to_strongly_connected_components(vector<vector<int> > const & g, vector<vector<int> > const & g_rev) {
    int n = g.size();
    vector<int> acc(n); {
        vector<bool> used(n);
        function<void (int)> dfs = [&](int i) {
            used[i] = true;
            for (int j : g[i]) if (not used[j]) dfs(j);
            acc.push_back(i);
        };
        REP (i,n) if (not used[i]) dfs(i);
        reverse(ALL(acc));
    }
    int size = 0;
    vector<int> component_of(n); {
        vector<bool> used(n);
        function<void (int)> rdfs = [&](int i) {
            used[i] = true;
            component_of[i] = size;
            for (int j : g_rev[i]) if (not used[j]) rdfs(j);
        };
        for (int i : acc) if (not used[i]) {
            rdfs(i);
            ++ size;
        }
    }
    return { size, move(component_of) };
}

/**
 * @return a tree in many cases
 */
vector<vector<int> > decomposed_graph(int size, vector<int> const & component_of, vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<int> > h(size);
    REP (i, n) for (int j : g[i]) {
        if (component_of[i] != component_of[j]) {
            h[component_of[i]].push_back(component_of[j]);
        }
    }
    REP (k, size) {
        sort(ALL(h[k]));
        h[k].erase(unique(ALL(h[k])), h[k].end());
    }
    return h;
}

/**
 * @brief memory optimized version
 * @note 速度差はほぼない stack overflowしたとき用
 */
pair<int, vector<int> > decompose_to_strongly_connected_components(vector<vector<int> > const & g, vector<vector<int> > const & g_rev) {
    int n = g.size();
    vector<int> acc(n); {
        auto it = acc.rbegin();
        vector<bool> used(n);
        stack<pair<int, int> > stk;
        REP (k, n) if (not used[k]) {
            stk.emplace(k, 0);
            used[k] = true;
            while (not stk.empty()) { // dfs
                int i = stk.top().first;
                int & e = stk.top().second;
                while (e < g[i].size()) {
                    int j = g[i][e];
                    ++ e;
                    if (not used[j]) {
                        stk.emplace(j, 0);
                        used[j] = true;
                        break;
                    }
                }
                if (stk.top().first == i) {
                    *(it ++) = i;
                    stk.pop();
                }
            }
        }
    }
    int size = 0;
    vector<int> component_of(n); {
        vector<bool> used(n);
        stack<int> stk;
        for (int k : acc) if (not used[k]) {
            stk.push(k);
            used[k] = true;
            while (not stk.empty()) { // dfs
                int i = stk.top(); stk.pop();
                component_of[i] = size;
                for (int j : g_rev[i]) if (not used[j]) {
                    stk.push(j);
                    used[j] = true;
                }
            }
            ++ size;
        }
    }
    return { size, move(component_of) };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/strongly_connected_components.cpp"
vector<vector<int> > opposite_graph(vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<int> > h(n);
    REP (i, n) for (int j : g[i]) h[j].push_back(i);
    return h;
}
/**
 * @brief strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解
 * @return the pair (the number k of components, the function from vertices of g to components)
 * @note O(V + E)
 */
pair<int, vector<int> > decompose_to_strongly_connected_components(vector<vector<int> > const & g, vector<vector<int> > const & g_rev) {
    int n = g.size();
    vector<int> acc(n); {
        vector<bool> used(n);
        function<void (int)> dfs = [&](int i) {
            used[i] = true;
            for (int j : g[i]) if (not used[j]) dfs(j);
            acc.push_back(i);
        };
        REP (i,n) if (not used[i]) dfs(i);
        reverse(ALL(acc));
    }
    int size = 0;
    vector<int> component_of(n); {
        vector<bool> used(n);
        function<void (int)> rdfs = [&](int i) {
            used[i] = true;
            component_of[i] = size;
            for (int j : g_rev[i]) if (not used[j]) rdfs(j);
        };
        for (int i : acc) if (not used[i]) {
            rdfs(i);
            ++ size;
        }
    }
    return { size, move(component_of) };
}

/**
 * @return a tree in many cases
 */
vector<vector<int> > decomposed_graph(int size, vector<int> const & component_of, vector<vector<int> > const & g) {
    int n = g.size();
    vector<vector<int> > h(size);
    REP (i, n) for (int j : g[i]) {
        if (component_of[i] != component_of[j]) {
            h[component_of[i]].push_back(component_of[j]);
        }
    }
    REP (k, size) {
        sort(ALL(h[k]));
        h[k].erase(unique(ALL(h[k])), h[k].end());
    }
    return h;
}

/**
 * @brief memory optimized version
 * @note 速度差はほぼない stack overflowしたとき用
 */
pair<int, vector<int> > decompose_to_strongly_connected_components(vector<vector<int> > const & g, vector<vector<int> > const & g_rev) {
    int n = g.size();
    vector<int> acc(n); {
        auto it = acc.rbegin();
        vector<bool> used(n);
        stack<pair<int, int> > stk;
        REP (k, n) if (not used[k]) {
            stk.emplace(k, 0);
            used[k] = true;
            while (not stk.empty()) { // dfs
                int i = stk.top().first;
                int & e = stk.top().second;
                while (e < g[i].size()) {
                    int j = g[i][e];
                    ++ e;
                    if (not used[j]) {
                        stk.emplace(j, 0);
                        used[j] = true;
                        break;
                    }
                }
                if (stk.top().first == i) {
                    *(it ++) = i;
                    stk.pop();
                }
            }
        }
    }
    int size = 0;
    vector<int> component_of(n); {
        vector<bool> used(n);
        stack<int> stk;
        for (int k : acc) if (not used[k]) {
            stk.push(k);
            used[k] = true;
            while (not stk.empty()) { // dfs
                int i = stk.top(); stk.pop();
                component_of[i] = size;
                for (int j : g_rev[i]) if (not used[j]) {
                    stk.push(j);
                    used[j] = true;
                }
            }
            ++ size;
        }
    }
    return { size, move(component_of) };
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

