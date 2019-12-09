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


# :heavy_check_mark: data_structure/sparse_table.unit.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [sparse table on a semilattice](../../library/data_structure/sparse_table.hpp.html)


## Code
{% raw %}
```cpp
#include "data_structure/sparse_table.hpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <random>
using namespace std;

int main() {
    random_device device;
    default_random_engine gen(device());

    int n = uniform_int_distribution<int>(1, 500)(gen);
    vector<int> data(n);
    REP (i, n) data[i] = uniform_int_distribution<int>(- 1000000, 1000000)(gen);
    sparse_table<max_semilattice> table(data);
    auto range_concat = [&](int l, int r) {
        int acc = INT_MIN;
        REP3 (i, l, r) {
            acc = max(acc, data[i]);
        }
        return acc;
    };

    REP (iteration, 500) {
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        assert (table.range_concat(l, r) == range_concat(l, r));
    }
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

