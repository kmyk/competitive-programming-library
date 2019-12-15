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


# :warning: get a central path of a catapillar graph <small>(graph/catapillar_graph.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/catapillar_graph.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-15 03:57:55 +0900


* see: <a href="https://en.wikipedia.org/wiki/Caterpillar_tree">https://en.wikipedia.org/wiki/Caterpillar_tree</a>


## Code

{% raw %}
```cpp
/**
 * @brief get a central path of a catapillar graph
 * @arg g is a tree
 * @return a central path; i.e. a longest path
 * @note $O(n)$
 * @note an empty vector if g is not a catapillar
 * @see https://en.wikipedia.org/wiki/Caterpillar_tree
 * @note example problem: https://atcoder.jp/contests/arc095/tasks/arc095_d
 * @note ![](https://upload.wikimedia.org/wikipedia/commons/b/b7/Caterpillar_tree.svg)
 */
vector<int> get_catapillar_central_path(const vector<vector<int> > & g) {
    int n = g.size();

    // construct the tree with non-leaf vertices
    int m = 0;
    vector<vector<int> > h(n);
    REP (i, n) if (g[i].size() != 1) {
        ++ m;
        for (int j : g[i]) if (g[j].size() != 1) {
            h[i].push_back(j);
        }
    }

    // the tree must be a path graph
    REP (i, n) {
        if (h[i].size() >= 3) {
            return vector<int>();
        }
    }

    // reconstruct the path
    if (m == 0) {
        if (n == 1) {
            return vector<int>({ 0 });
        } else if (n == 2) {
            return vector<int>({ 0, 1 });
        } else {
            assert (false);
        }

    } else {
        assert (n >= 3);
        vector<int> path;
        int i = 0;
        while (g[i].size() == 1 or h[i].size() == 2) {
            ++ i;
        }
        for (int j : g[i]) if (g[i].size() == 1) {
            path.push_back(j);
            break;
        }
        int parent = path.back();
        while (true) {
            path.push_back(i);
            bool found = false;
            for (int j : h[i]) if (j != parent) {
                parent = i;
                i = j;
                found = true;
                break;
            }
            if (not found) {
                break;
            }
        }
        for (int j : g[i]) if (g[i].size() == 1 and j != parent) {
            path.push_back(j);
            break;
        }
        return path;
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

