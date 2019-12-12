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


# :warning: utils/graphviz.inc.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/graphviz.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2017-12-27 06:53:37 +0900




## Code
{% raw %}
```cpp
void graphviz(vector<vector<int> > const & g, bool is_digraph = false, string const & name = "graph") {
    ofstream ofs(name + ".dot");
    ofs << (is_digraph ? "di" : "") << "graph graph_name {" << endl;
    ofs << "    graph [ bgcolor = \"#00000000\" ]" << endl;
    ofs << "    node [ shape = circle, style = filled, fillcolor = \"#ffffffff\" ]" << endl;
    REP (i, g.size()) for (int j : g[i]) if (is_digraph or i <= j) ofs << "    " << i << (is_digraph ? " -> " : " -- ") << j << endl;
    ofs << "}" << endl;
    ofs.close();
    system(("dot -T png " + name + ".dot > " + name + ".png").c_str());
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

