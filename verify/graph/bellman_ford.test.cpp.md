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


# :heavy_check_mark: graph/bellman_ford.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/graph/bellman_ford.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/bellman_ford.hpp.html">Bellman-Ford algorithm <small>(graph/bellman_ford.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#ifdef USE_SPFA
#include "graph/shortest_path_faster_algorithm.hpp"
auto BELLMAN_FORD = shortest_path_faster_algorithm;
#else
#include "graph/bellman_ford.hpp"
auto BELLMAN_FORD = bellman_ford_shortest_path;
#endif

#include <algorithm>
#include <iostream>
#include "utils/macros.hpp"
using namespace std;

int main() {
    // input
    int v, e, root; cin >> v >> e >> root;
    vector<vector<pair<int, int64_t> > > g(v);
    REP (j, e) {
        int s, t, dist; cin >> s >> t >> dist;
        g[s].emplace_back(t, dist);
    }

    // solve
    auto dist = BELLMAN_FORD(root, g);

    // output
    if (count(ALL(dist), LLONG_MIN)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        REP (i, v) {
            if (dist[i] == LLONG_MAX) {
                cout << "INF" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 328, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 153, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.bundle.BundleError: graph/bellman_ford.test.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

