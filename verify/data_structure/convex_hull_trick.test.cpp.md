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


# :heavy_check_mark: data_structure/convex_hull_trick.test.cpp
<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/convex_hull_trick.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-09 09:23:07 +0900




## Depends On
* :heavy_check_mark: <a href="../../library/data_structure/convex_hull_trick.hpp.html">data_structure/convex_hull_trick.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code
{% raw %}
```cpp
#include "data_structure/convex_hull_trick.hpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <random>
#include <vector>
#include "utils/macros.hpp"
using namespace std;


int main() {
    random_device device;
    default_random_engine gen(device());
    REP (iteration, 1000) {
        vector<pair<int, int> > lines;
        convex_hull_trick cht;
        REP (i, 100) {
            int a = uniform_int_distribution<int>(- 30, 30)(gen);
            int b = uniform_int_distribution<int>(- 30, 30)(gen);
            lines.emplace_back(a, b);
            cht.add_line(a, b);
        }
        REP (i, 10) {
            int x = uniform_int_distribution<int>(- 100, 100)(gen);
            int y = INT_MAX;
            for (auto line : lines) {
                int a, b; tie(a, b) = line;
                y = min(y, a * x + b);
            }
            assert (cht.get_min(x) == y);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

