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


# :warning: utils/twosat.inc.cpp
* category: utils


[Back to top page](../../index.html)



## Code
```cpp

vector<bool> twosat(int n, vector<pair<int, int> > const & cnf) {
    // make digraph
    vector<vector<int> > g(2*n);
    auto i = [&](int x) { assert (x != 0 and abs(x) <= n); return x > 0 ? x-1 : n-x-1; };
    for (auto it : cnf) {
        int x, y; tie(x, y) = it; // x or y
        g[i(- x)].push_back(i(y)); // not x implies y
        g[i(- y)].push_back(i(x)); // not y implies x
    }
    // do SCC
    vector<int> component = strongly_connected_components::decompose(g).second;
    vector<bool> valuation(n);
    repeat_from (x,1,n+1) {
        if (component[i(x)] == component[i(- x)]) { // x iff not x
            return vector<bool>(); // unsat
        }
        valuation[x-1] = component[i(x)] > component[i(- x)]; // use components which indices are large
    }
    return valuation;
}

```

[Back to top page](../../index.html)
