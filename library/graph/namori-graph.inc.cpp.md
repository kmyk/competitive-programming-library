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


# :warning: graph/namori-graph.inc.cpp
* category: graph


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
/**
 * @param g a simple connected undirected graph with |E| = |V|
 */
deque<int> get_namori_cycle(vector<vector<int> > const & g) {
    int n = g.size();
    { int m = 0; REP (i, n) m += g[i].size(); assert (m == 2 * n); }  // assume the namori-ty
    deque<int> stk;
    vector<bool> used(n);
    function<void (int, int)> go = [&](int i, int parent) {
        if (used[i]) throw i;
        stk.push_back(i);
        used[i] = true;
        for (int j : g[i]) if (j != parent) {
            go(j, i);
        }
        assert (stk.back() == i);
        stk.pop_back();
        used[i] = false;
    };
    try {
        go(0, -1);
        assert (false);  // fails if the graph is not simple
    } catch (int i) {
        while (stk.front() != i) {
            stk.pop_front();
        }
    }
    return stk;
}
unittest {
    vector<vector<int> > g(10);
    auto add_edge = [&](int i, int j) {
        g[i].push_back(j);
        g[j].push_back(i);
    };
    add_edge(0, 5);
    add_edge(1, 7);
    add_edge(2, 7);
    add_edge(3, 8);
    add_edge(4, 5);
    add_edge(5, 9);
    add_edge(6, 7);
    add_edge(7, 8);
    add_edge(8, 9);
    add_edge(3, 1);
    assert (get_namori_cycle(g) == deque<int>({ 8, 3, 1, 7 }));
}
unittest {
    vector<vector<int> > g(10);
    auto add_edge = [&](int i, int j) {
        g[i].push_back(j);
        g[j].push_back(i);
    };
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 4);
    add_edge(3, 5);
    add_edge(4, 6);
    add_edge(6, 2);
    add_edge(6, 7);
    add_edge(7, 8);
    add_edge(8, 9);
    assert (get_namori_cycle(g) == deque<int>({ 2, 4, 6 }));
}

```
{% endraw %}

[Back to top page](../../index.html)

