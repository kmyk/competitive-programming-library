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


# :heavy_check_mark: data_structure/fully_indexable_dictionary.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [a fully indexable dictionary](../../library/data_structure/fully_indexable_dictionary.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)


## Code
{% raw %}
```cpp
#include "data_structure/fully_indexable_dictionary.hpp"

#include <cassert>
#include <random>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

template <class RandomEngine>
void unittest(int n, RandomEngine & gen) {
    vector<bool> data(n);
    REP (i, n) {
        data[i] = bernoulli_distribution(0.5)(gen);
    }
    auto rank = [&](bool value, int l, int r) {
        return count(data.begin() + l, data.begin() + r, value);
    };
    auto select = [&](bool value, int k, int l) {
        int i = l;
        while (i < data.size() and data[i] != value) ++ i;
        while (i < data.size() and k --) {
            ++ i;
            while (i < data.size() and data[i] != value) ++ i;
        }
        return i;
    };
    fully_indexable_dictionary fid(data);
    for (int iteration = 1000; iteration --; ) {
        bool value = bernoulli_distribution(0.5)(gen);
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        int k = uniform_int_distribution<int>(0, (r - l) * 2 / 3)(gen);
        assert (fid.rank(value, l, r) == rank(value, l, r));
        assert (fid.select(value, k, l) == select(value, k, l));
        assert (fid.access(l) == data[l]);
    }
}

int main() {
    random_device device;
    default_random_engine gen(device());
    unittest(1, gen);
    unittest(126, gen);
    unittest(127, gen);
    unittest(128, gen);
    unittest(129, gen);
    unittest(10000, gen);
    return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

