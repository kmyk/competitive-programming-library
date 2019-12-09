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


# :warning: graph/diameter.inc.cpp
* category: graph


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
/**
 * @sa http://techtipshoge.blogspot.jp/2016/09/blog-post.html
 */
pair<int, int> get_eccentricity(int k, vector<vector<int> > const & tree) {
    pair<int, int> result = { -1, -1 };  // (depth, vertex)
    function<void (int, int, int)> dfs = [&](int i, int parent, int depth) {
        chmax(result, make_pair(depth, i));
        for (int j : tree[i]) if (j != parent) {
            dfs(j, i, depth + 1);
        }
    };
    dfs(k, -1, 0);
    return result;
}
int get_diameter(vector<vector<int> > const & tree) {
    return get_eccentricity(get_eccentricity(0, tree).second, tree).first;
}

vector<int> get_centers(vector<vector<int> > const & tree) {
    int n = tree.size();
    vector<bool> used(n);
    vector<int> cur, prv;
    REP (i, n) {
        if (tree[i].size() <= 1) {
            cur.push_back(i);
            used[i] = true;
        }
    }
    while (not cur.empty()) {
        cur.swap(prv);
        cur.clear();
        for (int i : prv) {
            for (int j : tree[i]) if (not used[j]) {
                cur.push_back(j);
                used[j] = true;
            }
        }
    }
    return prv;
}

```
{% endraw %}

[Back to top page](../../index.html)

